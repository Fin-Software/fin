
#pragma once

#include "whixy.h"

inline u64 eval_lazy_u64_u64(lazy_1* call);

inline lazy_1 make_lazy_u64_u64(u64 (*func)(u64), u64 n);

int main(void);
