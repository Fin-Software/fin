// SPDX-License-Identifier: Apache-2.0
// Copyright © 2025 The Whixy Authors. All rights reserved.
// Contributors responsible for this file:
// @p7r0x7 <mattrbonnette@pm.me>

#include "whixy.h"

static u64 counter() {
    static u64 static_ = 0; // destructured anon struct
    u64 t0 = static_;
    static_ += 1;
    return t0;
}

[[gnu::const]] static u64 fibonacci(u64 n) {
    if (n <= 1) return n;
    u64 prev = 0;
    u64 curr = 1;
    u64 i = 2;
    while (i <= n) {
        const u64 next = prev + curr;
        prev = curr;
        curr = next;
        i += 1;
    }
    return curr;
}
inline u64 eval_lazy_u64_u64(lazy_1* call) { return ((u64(*)(u64))call->func)((u64)(uintptr_t)call->arg0); }
inline lazy_1 make_lazy_u64_u64(u64 (*func)(u64), u64 n) {
    return (lazy_1){(void* (*)(void*))func, (void*)(uintptr_t)n};
}

// This would have a custom _start() spinning up runt and calling Main()
int main() {
    lazy_1 t0 = make_lazy_u64_u64(fibonacci, counter());
    return (int)(eval_lazy_u64_u64(&t0) & (1 << 8) - 1);
}
