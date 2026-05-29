// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Fin Authors. All rights reserved.

module direntries;
import std::sort, std::io::file, std::io::path, std::collections::list;

const PATH_MAX = 512;

struct Entry @private { Path name; bool is_dir; }

struct DirEntry { Path base; Path name; bool is_dir; }

struct DirFrame @private { List{Entry} entries; Path base; int id; }

struct DirEntries { Allocator alloc; List{DirFrame} stack; bool include_hidden; }

fn void? DirEntries.init(&de, Path path, bool include_hidden, Allocator ally) {
	de.alloc = ally;
	(void)de.stack.init(ally, 0);
	de.include_hidden = include_hidden;
	de.push_dir(path.len ? path : (Path)".")!;
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
				{ de.push_dir(join_paths(tmp, top.base, e.name))!; };
		}
		return ret;
	}
	NO_MORE_ELEMENT~!;
}
fn void? DirEntries.traverse(&de, DirFrame* frame) {
	@sfba(PATH_MAX*2, de.alloc; Allocator tmp) {
		PathList list = path::ls(tmp, frame.base)!;
		foreach (&path : list) { 
			if (!de.include_hidden && (char)path.[0] == '.') continue;
			bool is_dir = file::is_dir(join_paths(tmp, frame.base, (Path)*path));
			frame.entries.push({ .name = path.copy(de.alloc), .is_dir = is_dir });
		}
	};
	if (frame.entries.len() > 1) sort::quicksort(&frame.entries, &entry_cmp);
}
fn void? DirEntries.push_dir(&de, Path path) {
	DirFrame frame @noinit;
	frame.id = 0;
	frame.base = path.copy(de.alloc);
	frame.entries.init(de.alloc, 0);
	de.traverse(&frame)!;
	de.stack.push(frame);
}
fn void DirEntries.free_frame(&de, DirFrame* frame) {
	foreach (entry : frame.entries) alloc::free(de.alloc, entry.name);
	alloc::free(de.alloc, frame.base);
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
macro Path join_paths(Allocator ally, ...) {
	return (Path)string::join(ally, {...$vaarg}, {path::PREFERRED_SEPARATOR});
}
fn sz entry_cmp(Entry* a, Entry* b) @inline @private => a.name.compare_to(b.name);

////////////////////////////////////////////////////////////////////////////////////////////////////
module hash;
import direntries, std::io, std::thread, std::crypto::sha3, std::encoding::base64;

const HASH_LEN = 32;
struct ReaderArgs { BufChan* ch; Path wd; }
faultdef MISSING_WORKING_DIR_ARG, TOO_MANY_ARGS;
alias BufChan = BufferedChannel{char[]};

fn int treeReader(void* arg) {
	@pool_init(mem, 1<<10) {

	BufChan* ch = (BufChan*)((ReaderArgs*)arg).ch;
	Path wd = (Path)((ReaderArgs*)arg).wd;
	DirEntries de @noinit;
	de.init(wd, true, mem)!!;
	defer de.deinit();

	while (try entry = de.next()) {
		Path base = entry.base.len > wd.len ? entry.base[wd.len+1..] : (Path)"";
		Path hashed;
		if (base.len) {
			hashed = entry.is_dir ? direntries::join_paths(mem, base, entry.name, "")
				: direntries::join_paths(mem, base, entry.name);
		} else {
			hashed = entry.is_dir ? direntries::join_paths(mem, entry.name, "")
				: entry.name.copy(mem);
		}
		$if env::WIN32:
			foreach (i, c : hashed) if (c == '\\') hashed[i] = '/';
		$endif
		ch.push(hashed)!!; if (entry.is_dir) continue;
			
		File file;
		direntries::@sfba(direntries::PATH_MAX, mem; Allocator tmp)
			{ file = file::open(direntries::join_paths(tmp, entry.base, entry.name), "r")!!; };
		defer (void)file.close();

		for (sz size = file.size()!!, sz n @noinit; size; size -= n) {
			n = min(size, 64<<10);
			char[] slice = alloc::malloc(mem, n)[:n];
			io::read_all(&file, slice)!!;
			ch.push(slice)!!;
		}
	}
	ch.close();
	return 0;

	};
}

fn int sha3Hasher(void* arg) {
	BufChan* ch = (BufChan*)arg;
	Sha3{HASH_LEN*8} state;
	state.init();

	while (try buf = ch.pop()) { state.update(buf[..]); alloc::free(mem, buf); }
	char[HASH_LEN] digest @noinit;
	state.final(digest[..]);

	char[(HASH_LEN+2)/3*4 + 1] encoded = { [encoded.len-1] = '\n' };
	base64::encode_into(&encoded, &digest);
	io::stdout().write(encoded[..])!!;
	return 0;
}

fn int main(String[] args) {
	switch (args.len) {
		case 1: MISSING_WORKING_DIR_ARG~!!;
		case 2: break;
		default: TOO_MANY_ARGS~!!;
	}
	Path wd = (Path)path::normalize(args[1])!!;

	BufChan* ch = channel::create_buffered(mem, 16)!!;
	ReaderArgs ra = {ch, wd};

	Thread readert, hashert;
	readert.create(&treeReader, (void*)&ra)!!;
	hashert.create(&sha3Hasher, (void*)ch)!!;

	readert.join()!!;
	hashert.join()!!;
	ch.destroy();
	return 0;
}
