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
fn void? DirEntries.push_dir(&de, String path) {
    DirFrame frame @noinit;
    frame.id = 0;
    frame.base = path.copy(de.alloc);
    frame.entries.init(de.alloc, 0);
    de.traverse(&frame)!;
    de.stack.push(frame);
}
fn void DirEntries.free_frame(&de, DirFrame* frame) {
    foreach (entry : frame.entries) allocator::free(de.alloc, entry.name);
    allocator::free(de.alloc, frame.base);
}
fn void DirEntries.deinit(&de) {
    foreach (&frame : de.stack) de.free_frame(frame);
    de.stack.free();
}

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
import direntries, std::io, std::thread, std::encoding::base64;

struct ReaderArgs { BufChan ch; String wd }

fn int stdinReader(void* arg) {
	BufChan ch = (BufChan)((ReaderArgs*)arg).ch;
	String wd = (String)((ReaderArgs*)arg).wd;
	
    DirEntries de @noinit;
    de.init(wd, true, ally)!!;
    while (try entry = de.next()) {
        String base = entry.base[wd.len..];
        if (base.len) io::printf("%s%c", base[1..], direntries::SEPARATOR)!!;
        io::printfn("%s", entry.name)!!;
    }
	
    char[4096] stack_buf;

    while (true)
    {
        isz n = io::stdin.read(stack_buf[..])!;
        if (n == 0) break;

        // allocate exact-sized buffer
        char* buf = allocator::alloc(a, char, n)!;
        memcpy(buf, &stack_buf[0], n);

        ch.push(Chunk{ buf, (usz)n })!;
    }
    ch.close();
    return 0;
}

const HASH_LEN = 32;
extern fn void sha3_Init(void* state, uint bitSize);
extern fn void sha3_Update(void* state, void* bufIn, usz len);
extern fn void* sha3_Final(void* state) @cname("sha3_Finalize");

fn int sha3Hasher(void* arg) {
    char[224] state;
    sha3_Init(&state);
    BufChan ch = (BufChan)arg;
    while (true)
    {
        char[]? buf = ch.pop();
        if (catch excuse = buf) break;
        sha3_Update(&state, buf.ptr, buf.len);
        allocator::free(mem, buf);
    }
    char[HASH_LEN] digest;
    char[(HASH_LEN+2)/3*4] &hash;
    hash_final(&state, &digest);
    base64::encode_buffer(&digest, &hash);
    io::stdout.write(hash[..])!!;
    return 0;
}

const BUFFER_SIZE = 16 << 10;
alias BufChan = channel::BufferedChannel{char[]};
faultdef MISSING_WORKING_DIR_ARG, TOO_MANY_ARGS;

fn int main(String[] args) {
    switch (args.len) {
        case 1: MISSING_WORKING_DIR_ARG~!!;
        case 2: break;
        default: TOO_MANY_ARGS~!!;
    }
    String wd = path::normalize(args[1])!!;

    BufChan ch;
    ch.init(mem, 8)!!;
    ReaderArgs ra = {ch, wd};
    
    Thread readert, hashert;
    readert.create(&stdinReader, (void*)&ra)!!;
    hashert.create(&sha3Hasher, (void*)ch)!!;

    readert.join()!!;
    hashert.join()!!;
    chan.destroy()!!;
    return 0;
}
