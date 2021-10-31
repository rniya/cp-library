#pragma once
#include <cstdlib>

#define BEGIN_STACK_EXTEND(size)                                                                                 \
    void* stack_extend_memory_ = malloc(size);                                                                   \
    void* stack_extend_origin_memory_;                                                                           \
    char* stack_extend_dummy_memory_ = (char*)alloca((1 + (int)(((long long)stack_extend_memory_) & 127)) * 16); \
    *stack_extend_dummy_memory_ = 0;                                                                             \
    asm volatile("mov %%rsp, %%rbx\nmov %%rax, %%rsp"                                                            \
                 : "=b"(stack_extend_origin_memory_)                                                             \
                 : "a"((char*)stack_extend_memory_ + (size)-1024));
#define END_STACK_EXTEND                                                 \
    asm volatile("mov %%rax, %%rsp" ::"a"(stack_extend_origin_memory_)); \
    free(stack_extend_memory_);

/**
 * @brief スタック拡張マクロ
 * @docs docs/util/stack_extend.md
 */
