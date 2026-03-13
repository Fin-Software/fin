// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.

module direntries;
import std::sort;
import std::io::file;
import std::io::path;
import std::collections::list;

const PATH_MAX = 512;
const SEPARATOR = path::PREFERRED_SEPARATOR;

struct Entry @private { String name; bool is_dir; }

struct DirEntry { String base; String name; bool is_dir; }

struct DirFrame @private { List{Entry} entries; String base; uint id; }

struct DirEntries { Allocator alloc; List{DirFrame} stack; bool include_hidden; }

fn void? DirEntries.init(&de, String path, bool include_hidden, Allocator ally) {
    de.alloc = ally;
    (void)de.stack.init(ally, 0);
    de.include_hidden = include_hidden;
    de.push_dir(path.len ? path : ".")!;
}
fn DirEntry? DirEntries.next(&de) {
    @sfba(PATH_MAX, de.alloc; Allocator ally) {
        while (de.stack.len()) {
            DirFrame* top = &de.stack.entries[de.stack.len() - 1];
            if (top.id < top.entries.len()) {
                Entry e = top.entries.entries[top.id];
                top.id++;

                DirEntry ret = { .base = top.base, .name = e.name, .is_dir = e.is_dir };
                if (e.is_dir) de.push_dir(join_a_path(ally, top.base, e.name))!;
                return ret;
            } else {
                de.free_frame(top);
                de.stack.pop()!;
                continue;
            }
        }
    };
    NO_MORE_ELEMENT~!;
}
fn void? DirEntries.push_dir(&de, String path) {
    DirFrame frame @noinit;
    frame.id = 0;
    frame.base = path.copy(de.alloc);
    frame.entries.init(de.alloc, 0);
    de.traverse(&frame)!;
    de.stack.push(frame);
}
fn void? DirEntries.traverse(&de, DirFrame* frame) {
	@sfba(1024, de.alloc; Allocator ally) {
		PathList list = path::ls(ally, { frame.base, path::DEFAULT_ENV, ally })!;
        foreach (&path : list) {
            String str = path.str_view();
            if (!de.include_hidden && str[0] == '.') continue;
            String full = join_a_path(ally, frame.base, str);
            bool is_dir = file::is_dir(full);
            allocator::free(ally, full);
            frame.entries.push({ .name = str.copy(de.alloc), .is_dir = is_dir });
        }
    };
    if (frame.entries.len() > 1) sort::quicksort(&frame.entries, &entry_cmp);
}
fn void DirEntries.free_frame(&de, DirFrame* frame) {
    foreach (entry : frame.entries) allocator::free(de.alloc, entry.name);
    allocator::free(de.alloc, frame.base);
}
fn void DirEntries.deinit(&de) {
    foreach (&frame : de.stack) de.free_frame(frame);
    de.stack.free();
}

//    Helper

macro void @sfba(usz $size, Allocator fb; @body(Allocator sfba)) {
    char[$size] buf;
    OnStackAllocator ally;
    ally.init(&buf, fb);
    defer ally.free();
    @body(&ally);
}
fn String join_a_path(Allocator ally, String base, String name) {
    usz len = base.len + 1 + name.len;
    char* buf = allocator::malloc(ally, len);
    mem::copy(buf, base.ptr, base.len);
    buf[base.len] = path::PREFERRED_SEPARATOR;
    mem::copy(buf + base.len + 1, name.ptr, name.len);
    return (String)buf[:len];
}
fn isz String.compare_to(s, String b) {
    usz min_len = min(s.len, b.len);
    for (usz i; i < min_len; i++) {
        int diff = s[i] - b[i];
        if (diff != 0) return (isz)diff;
    }
    return (isz)s.len - (isz)b.len;
}
fn isz entry_cmp(Entry* a, Entry* b) @private => a.name.compare_to(b.name);

///////////////////////////////////////////////////////////////////////////////////////////////////

module main;
import direntries, std::io, std::thread, std::encoding;

const BUFFER_SIZE = 16 << 10;

faultdef MISSING_WORKING_DIR_ARG, TOO_MANY_ARGS;

extern fn void sha3_Init(void* priv, uint bitSize);
extern fn void sha3_Update(void* priv, void* bufIn, usz len);
extern fn void* sha3_Finalize(void* priv);

fn int main(String[] args) {
    switch (args.len) {
        case 1: MISSING_WORKING_DIR_ARG~!!;
        case 2: break;
        default: TOO_MANY_ARGS~!!;
    }
    String wd = path::normalize(args[1])!!;

    direntries::@sfba(BUFFER_SIZE, mem; Allocator ally) {
        DirEntries de @noinit;
        de.init(wd, true, ally)!!;
        while (try entry = de.next()) {
            String base = entry.base[wd.len..];
            if (base.len) io::printf("%s%c", base[1..], direntries::SEPARATOR)!!;
            io::printfn("%s", entry.name)!!;
        }
    };
    return 0;
}

/*
//struct CharSlice { char* ptr; usz len; }
alias BufChan = channel::BufferedChannel{char[]};

fn int stdinReader(void* arg) {
    BufChan ch = (BufChan)arg;
/*
    Allocator a = allocator::heap();
    char[4096] stack_buf;

    while (true)
    {
        isz n = io::stdin.read(stack_buf[..])!;
        if (n == 0)
            break; // EOF

        // allocate exact-sized buffer
        char* buf = allocator::alloc(a, char, n)!;
        memcpy(buf, &stack_buf[0], n);

        ch.push(Chunk{ buf, (usz)n })!;
    }
    ch.close();
*/
    return 0;
}


fn int sha3Hasher(void* arg) {
    BufChan ch = (BufChan)arg;
/*
    HashCtx ctx;
    hash_init(&ctx);

    while (true)
    {
        Chunk c = ch.pop() catch
        {
            thread::CHANNEL_CLOSED => break,
        };

        hash_update(&ctx, c.data, c.len);
        allocator::free(allocator::heap(), c.data);
    }

    char digest[HASH_SIZE];
    hash_final(&ctx, digest);

    io::stdout.write(digest[..])!;
*/
    return 0;
}

fn int main() {
    BufChan chan;
    allocator::LibcAllocator malloc;
    chan.init(&malloc, 8)!!;

    Thread readert;
    Thread hashert;

    readert.create(&stdinReader, (void*)chan)!!;
    hashert.create(&sha3Hasher, (void*)chan)!!;

    readert.join()!!;
    hashert.join()!!;

    chan.destroy()!!;
    return 0;
}

// -----------------------------------------------------------------------------
// Hashing
// -----------------------------------------------------------------------------

const uint HASH_BUF_LEN = 16 * 1024;

fn void hash_entries(char[] out_hash, DirEntries* de) !{
    char[HASH_BUF_LEN] buf;
    SHA256 ctx;
    ctx.init();

    while (let entry = try de.next()) {
        String path_str;
        bool free_path = false;

        if (let base = entry.base) {
            path_str = join_path_manual(base, entry.name);
            free_path = true;

            if (fs::PATH_SEPARATOR != '/') {
                foreach(ref c : path_str) {
                    if (c == fs::PATH_SEPARATOR) c = '/';
                }
            }
        } else {
            path_str = entry.name;
        }

        ctx.update(path_str);

        if (entry.kind == fs::FileType.REGULAR) {
            // We need the OS path again.
            // If we normalized path_str above, we should ideally re-construct the OS path,
            // but for simple cases, forward slash often works on Windows too in C APIs.
            // To be safe, let's reconstruct if we have a base.
            String os_path = path_str;
            bool free_os_path = false;

            if (entry.base) {
                // Re-join with OS separator just for opening the file
                os_path = join_path_manual(entry.base !!, entry.name);
                free_os_path = true;
            }

            File file = try fs::File.open(os_path, "rb");
            defer file.close();

            while (true) {
                usz n = try file.read(buf);
                if (n == 0) break;
                ctx.update(buf[0..n]);
            }

            if (free_os_path) mem::free(os_path.ptr);
        }

        if (free_path) mem::free(path_str.ptr);
    }

    ctx.final(out_hash);
}

*/
