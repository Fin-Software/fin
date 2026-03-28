// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.

module direntries;
import std::sort, std::io::file, std::io::path, std::collections::list;

const PATH_MAX = 512;

struct Entry @private { String name; bool is_dir; }

struct DirEntry { String base; String name; bool is_dir; }

struct DirFrame @private { List{Entry} entries; String base; int id; }

struct DirEntries { Allocator alloc; List{DirFrame} stack; bool include_hidden; }

fn void? DirEntries.init(&de, String path, bool include_hidden, Allocator ally) {
	de.alloc = ally;
	(void)de.stack.init(ally, 0);
	de.include_hidden = include_hidden;
	de.push_dir(path.len ? path : ".")!;
}
fn DirEntry? DirEntries.next(&de) {
	while (de.stack.len()) {
		DirFrame* top = &de.stack.entries[de.stack.len() - 1];
		if (top.id >= top.entries.len()) {
			de.free_frame(top);
			de.stack.pop()!;
			continue;
		}
		Entry e = top.entries.entries[top.id++];
		DirEntry ret = { .base = top.base, .name = e.name, .is_dir = e.is_dir };
		if (e.is_dir) {
			@sfba(PATH_MAX, de.alloc; Allocator tmp)
				{ de.push_dir(join_a_path(tmp, top.base, e.name))!; };
		}
		return ret;
	}
	NO_MORE_ELEMENT~!;
}
fn void? DirEntries.traverse(&de, DirFrame* frame) {
	@sfba(PATH_MAX*2, de.alloc; Allocator tmp) {
		PathList list = path::ls(tmp, { frame.base, path::DEFAULT_ENV, tmp })!;
		foreach (&path : list) {
			String str = path.str_view();
			if (!de.include_hidden && str[0] == '.') continue;
			bool is_dir = file::is_dir(join_a_path(tmp, frame.base, str));
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
	isz len = base.len + 1 + name.len;
	char* buf = allocator::malloc(ally, len);
	mem::copy(buf, base.ptr, base.len);
	buf[base.len] = path::PREFERRED_SEPARATOR;
	mem::copy(buf + base.len + 1, name.ptr, name.len);
	return (String)buf[:len];
}
fn isz String.compare_to(s, String b) {
    isz len = min(s.len, b.len);
    for (isz i; i < len; i++) { int diff = s[i] - b[i]; if (diff != 0) return diff; }
    return (isz)s.len - (isz)b.len;
}
fn isz entry_cmp(Entry* a, Entry* b) @private => a.name.compare_to(b.name);

///////////////////////////////////////////////////////////////////////////////////////////////////

module main;
import direntries, std::io, std::thread, std::crypto::sha3, std::encoding::base64;

const HASH_LEN = 32;
struct ReaderArgs { BufChan ch; String wd; }
faultdef MISSING_WORKING_DIR_ARG, TOO_MANY_ARGS;
alias BufChan = channel::BufferedChannel{char[]};

fn int treeReader(void* arg) {
	@pool_init(mem, 1<<10) {

	BufChan ch = (BufChan)((ReaderArgs*)arg).ch;
	String wd = (String)((ReaderArgs*)arg).wd;
	DirEntries de @noinit;
	de.init(wd, true, mem)!!;
	defer de.deinit();
	
	while (try entry = de.next()) {
		String base = entry.base.len > wd.len ? entry.base[wd.len+1..] : "";
		isz off = base.len + (base.len ? 1 : 0);
		char[] path = allocator::malloc(mem, off+entry.name.len)[:off+entry.name.len];

		if (base.len) { mem::copy(path, base, base.len); path[base.len] = '/'; }
		mem::copy(path[off..], entry.name, entry.name.len);
		$if env::WIN32:
			foreach (i, c : path) if (c == '\\') path[i] = '/';
		$endif
		ch.push(path)!!;
		if (entry.is_dir) continue;

		File file;
		direntries::@sfba(direntries::PATH_MAX, mem; Allocator tmp)
			{ file = file::open(direntries::join_a_path(tmp, entry.base, entry.name), "r")!!; };
		defer (void)file.close();

		for (long size = file.size()!!, int n @noinit; size; size -= n) {
			n = (int)min(size, 64<<10);
			char[] slice = allocator::malloc(mem, n)[:n];
			io::read_all(&file, slice)!!;
			ch.push(slice)!!;
		}
	}
	ch.close();
	return 0;

	};
}

fn int sha3Hasher(void* arg) {
	BufChan ch = (BufChan)arg;
	Sha3{HASH_LEN*8} state;
	state.init();
	while (try buf = ch.pop()) {
		state.update(buf[..]);
		allocator::free(mem, buf);
	}
	char[HASH_LEN] digest @noinit;
	char[(HASH_LEN+2)/3*4 + 1] hash @noinit;
	state.final(digest[..]);
	base64::encode_buffer(&digest, &hash);
	hash[^1] = '\n';
	io::stdout().write(hash[..])!!;
	return 0;
}

fn int main(String[] args) {
	switch (args.len) {
		case 1: MISSING_WORKING_DIR_ARG~!!;
		case 2: break;
		default: TOO_MANY_ARGS~!!;
	}
	String wd = path::normalize(args[1])!!;

	BufChan ch;
	ch.init(mem, 16)!!;
	ReaderArgs ra = {ch, wd};

	Thread readert, hashert;
	readert.create(&treeReader, (void*)&ra)!!;
	hashert.create(&sha3Hasher, (void*)ch)!!;

	readert.join()!!;
	hashert.join()!!;
	ch.destroy()!!;
	return 0;
}
