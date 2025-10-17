// fin_clang_shim.cpp
#include "driver.h"

#include "clang/Basic/Diagnostic.h"
#include "clang/Basic/DiagnosticOptions.h"
#include "clang/Driver/Command.h"
#include "clang/Driver/Compilation.h"
#include "clang/Driver/Driver.h"
#include "clang/Driver/Job.h"
#include "clang/Frontend/TextDiagnosticPrinter.h"
#include "llvm/ADT/SmallVector.h"
#include "llvm/ADT/StringRef.h"
#include "llvm/Support/Host.h"
#include "llvm/Support/raw_ostream.h"

#include <cstdlib>
#include <cstring>
#include <memory>
#include <string>
#include <vector>

using namespace clang;
using namespace clang::driver;
using namespace llvm;

// AI; I don't use AI in production; this will be entirely rewritten; this is a shooby-whoop.

struct fin_compilation_t {
    std::unique_ptr<Compilation> compilation;
    // we keep a shallow snapshot (shared_ptr-like) of the initial job pointers
    // so indexes remain stable for callers even if we mutate the job list before execution.
    // We'll store the original Job* pointers in `original_jobs`.
    std::vector<const Job*> original_jobs;
};

static std::string join_argv_for_driver(int argc, char** argv) {
    // Not used externally; kept if needed
    std::string s;
    for (int i = 0; i < argc; ++i) {
        if (i) s.push_back(' ');
        s += argv[i];
    }
    return s;
}

fin_compilation_t* fin_build_compilation(int argc, char** argv) {
    IntrusiveRefCntPtr<DiagnosticOptions> diagOpts(new DiagnosticOptions());
    IntrusiveRefCntPtr<DiagnosticIDs> diagIDs(new DiagnosticIDs());
    TextDiagnosticPrinter* diagClient = new TextDiagnosticPrinter(llvm::errs(), &*diagOpts);
    DiagnosticsEngine diags(diagIDs, &*diagOpts, diagClient);

    std::string triple = llvm::sys::getDefaultTargetTriple();
    Driver driver(argv[0], triple, diags);

    SmallVector<const char*, 32> arr;
    for (int i = 0; i < argc; ++i) arr.push_back(argv[i]);

    std::unique_ptr<Compilation> comp(driver.BuildCompilation(arr));
    if (!comp) return nullptr;

    fin_compilation_t* wrapper = new fin_compilation_t();
    wrapper->compilation = std::move(comp);

    // capture stable pointers to the jobs we consider executable (Command jobs)
    const JobList& jl = wrapper->compilation->getJobs();
    for (auto& jptr: jl.getJobs()) {
        if (jptr && isa<Command>(*jptr)) {
            wrapper->original_jobs.push_back(jptr.get());
        } else {
            wrapper->original_jobs.push_back(nullptr); // keep index parity
        }
    }

    return wrapper;
}

size_t fin_compilation_num_jobs(fin_compilation_t* c) {
    if (!c) return 0;
    return c->original_jobs.size();
}

static char* copy_cstr_malloc(const char* s, size_t len) {
    char* out = (char*)std::malloc(len + 1);
    if (!out) return nullptr;
    std::memcpy(out, s, len);
    out[len] = '\0';
    return out;
}

char* fin_compilation_job_args_joined(fin_compilation_t* c, size_t job_index) {
    if (!c) return nullptr;
    if (job_index >= c->original_jobs.size()) return nullptr;
    const Job* j = c->original_jobs[job_index];
    if (!j || !isa<Command>(*j)) return nullptr;
    const Command* cmd = cast<Command>(j);

    // join args with embedded NULs so Zig can split exactly.
    // compute total length
    size_t total = 0;
    for (const auto& a: cmd->getArguments()) {
        total += a.size();
        total += 1; // separator NUL
    }
    std::string buf;
    buf.reserve(total);
    for (const auto& a: cmd->getArguments()) {
        buf.append(a.begin(), a.end());
        buf.push_back('\0');
    }
    return copy_cstr_malloc(
        buf.data(), buf.size()
    ); // note: buffer contains embedded NULs but we copy raw bytes and add trailing '\0'
}

char* fin_compilation_job_primary_output(fin_compilation_t* c, size_t job_index) {
    if (!c) return nullptr;
    if (job_index >= c->original_jobs.size()) return nullptr;
    const Job* j = c->original_jobs[job_index];
    if (!j || !isa<Command>(*j)) return nullptr;
    const Command* cmd = cast<Command>(j);

    // Try to use Command::getOutput() if available and non-empty.
    // getOutput() returns ArgStringList; if empty, return nullptr.
    const ArgStringList& outs = cmd->getOutput();
    if (!outs.empty()) {
        const char* s = outs[0];
        return copy_cstr_malloc(s, std::strlen(s));
    }
    return nullptr;
}

void fin_free_cstr(char* s) {
    if (!s) return;
    std::free(s);
}

int fin_execute_compilation_with_mask(fin_compilation_t* c, const unsigned char* run_mask, size_t mask_len) {
    if (!c) return 1;
    // Build a new JobList that omits jobs with run_mask == 0 where our original pointer was a Command.
    JobList filtered;
    JobList& orig = c->compilation->getJobs();

    // iterate through existing jobs in orig and decide whether to keep each.
    size_t idx = 0;
    for (auto& jp: orig.getJobs()) {
        bool keep = true;
        if (idx < mask_len) {
            const Job* orig_ptr = nullptr;
            if (idx < c->original_jobs.size()) orig_ptr = c->original_jobs[idx];
            if (orig_ptr && isa<Command>(*orig_ptr)) {
                // this slot corresponds to an executable Command (per our snapshot)
                if (run_mask[idx] == 0) keep = false;
            }
        }
        if (keep) {
            filtered.addJob(std::move(jp));
        } else {
            // drop it (skip execution)
        }
        ++idx;
    }

    // Replace jobs in compilation with filtered ones
    orig.clear();
    for (auto& fp: filtered.getJobs()) orig.addJob(std::move(fp));

    SmallVector<std::pair<int, const Command*>, 4> Failing;
    Driver* driver = nullptr;
    // We don't have original Driver here; but ExecuteCompilation is a free function on Driver instance.
    // However Compilation stores the underlying Driver? We can call driver via the Compilation's getJobs' toolchain
    // Simpler: call ExecuteCompilation on a temporary Driver created from argv[0] isn't available here.
    // Instead, we can call c->compilation->getActions? To avoid complexity, we will call the driver by constructing one locally
    // using the first job's executable name as argv0. This mirrors behavior from earlier examples.
    // But simplest approach: call the underlying Driver that produced the Compilation is not exposed;
    // however clang::driver::Compilation::ExecuteCompilation is a method on Driver, so we must re-create Driver.
    // For simplicity here we will call driver.ExecuteCompilation by reconstructing a Driver with the same triple and diag engine.
    // NOTE: This is a simplification; in production you should keep the original Driver object or re-run BuildCompilation.
    // For now, attempt to retrieve argv0 from compilation invocation:
    const ArgStringList& firstArgv = c->compilation->getInvocation().getArgs();
    const char* argv0 = nullptr;
    if (!firstArgv.empty()) argv0 = firstArgv[0];
    std::string triple = llvm::sys::getDefaultTargetTriple();

    // Recreate diagnostic engine for execution (simple).
    IntrusiveRefCntPtr<DiagnosticOptions> diagOpts(new DiagnosticOptions());
    IntrusiveRefCntPtr<DiagnosticIDs> diagIDs(new DiagnosticIDs());
    TextDiagnosticPrinter* diagClient = new TextDiagnosticPrinter(llvm::errs(), &*diagOpts);
    DiagnosticsEngine diags(diagIDs, &*diagOpts, diagClient);

    Driver exec_driver(argv0 ? argv0 : "clang", triple, diags);
    int rc = exec_driver.ExecuteCompilation(*c->compilation, Failing);

    return rc;
}

void fin_free_compilation(fin_compilation_t* c) {
    if (!c) return;
    c->compilation.reset();
    delete c;
}
