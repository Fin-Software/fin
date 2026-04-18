// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

#pragma once

#ifdef __cplusplus
extern "C" {
#endif

// AI; I don't use AI in production; this will be entirely rewritten; this is a shooby-whoop.

// Opaque handle representing a built driver compilation.
typedef struct fin_compilation_t fin_compilation_t;

// Build a compilation from argv (argc, argv). Returns nullptr on error.
// IMPORTANT: argv must NOT contain ObjC/ObjC++ flags you want stripped —
// do the filtering in Zig before calling this.
fin_compilation_t* fin_build_compilation(int argc, char** argv);

// Return how many jobs (commands) exist in the compilation.
// Note: some jobs may not be Command objects; shim counts only Commands
// that can be executed (the same things that ExecuteCompilation would run).
size_t fin_compilation_num_jobs(fin_compilation_t* c);

// Get a job's arguments as a single NUL-terminated string where arguments
// are joined with '\0' bytes (so Zig can split precisely). The returned
// pointer is heap-allocated and must be freed with fin_free_cstr.
char* fin_compilation_job_args_joined(fin_compilation_t* c, size_t job_index);

// Get a job's primary output path (if any). Returns nullptr if unknown.
// Returned pointer must be freed with fin_free_cstr.
char* fin_compilation_job_primary_output(fin_compilation_t* c, size_t job_index);

// Free a C string allocated by the shim.
void fin_free_cstr(char* s);

// Execute compilation but only run jobs selected by run_mask (bitset of length num_jobs).
// run_mask[i] == 0 -> skip job i; run_mask[i] != 0 -> run job i.
// Returns clang's exit code.
int fin_execute_compilation_with_mask(fin_compilation_t* c, const unsigned char* run_mask, size_t mask_len);

// Free the compilation handle and internal resources.
void fin_free_compilation(fin_compilation_t* c);

#ifdef __cplusplus
}
#endif
