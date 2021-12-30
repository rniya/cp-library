---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"util/stack_extend.hpp\"\n#include <cstdlib>\n\n#define BEGIN_STACK_EXTEND(size)\
    \                                                                            \
    \     \\\n    void* stack_extend_memory_ = malloc(size);                     \
    \                                              \\\n    void* stack_extend_origin_memory_;\
    \                                                                           \\\
    \n    char* stack_extend_dummy_memory_ = (char*)alloca((1 + (int)(((long long)stack_extend_memory_)\
    \ & 127)) * 16); \\\n    *stack_extend_dummy_memory_ = 0;                    \
    \                                                         \\\n    asm volatile(\"\
    mov %%rsp, %%rbx\\nmov %%rax, %%rsp\"                                        \
    \                    \\\n                 : \"=b\"(stack_extend_origin_memory_)\
    \                                                             \\\n           \
    \      : \"a\"((char*)stack_extend_memory_ + (size)-1024));\n#define END_STACK_EXTEND\
    \                                                 \\\n    asm volatile(\"mov %%rax,\
    \ %%rsp\" ::\"a\"(stack_extend_origin_memory_)); \\\n    free(stack_extend_memory_);\n"
  code: "#pragma once\n#include <cstdlib>\n\n#define BEGIN_STACK_EXTEND(size)    \
    \                                                                            \
    \ \\\n    void* stack_extend_memory_ = malloc(size);                         \
    \                                          \\\n    void* stack_extend_origin_memory_;\
    \                                                                           \\\
    \n    char* stack_extend_dummy_memory_ = (char*)alloca((1 + (int)(((long long)stack_extend_memory_)\
    \ & 127)) * 16); \\\n    *stack_extend_dummy_memory_ = 0;                    \
    \                                                         \\\n    asm volatile(\"\
    mov %%rsp, %%rbx\\nmov %%rax, %%rsp\"                                        \
    \                    \\\n                 : \"=b\"(stack_extend_origin_memory_)\
    \                                                             \\\n           \
    \      : \"a\"((char*)stack_extend_memory_ + (size)-1024));\n#define END_STACK_EXTEND\
    \                                                 \\\n    asm volatile(\"mov %%rax,\
    \ %%rsp\" ::\"a\"(stack_extend_origin_memory_)); \\\n    free(stack_extend_memory_);\n"
  dependsOn: []
  isVerificationFile: false
  path: util/stack_extend.hpp
  requiredBy: []
  timestamp: '2021-12-30 22:27:29+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/stack_extend.hpp
layout: document
title: "\u30B9\u30BF\u30C3\u30AF\u62E1\u5F35\u30DE\u30AF\u30ED"
---

## 概要
ICPC 国内予選など手元実行が必要になる際に, 再帰に代表される重い処理はスタックオーバーフローを引き起こしやすい. それを回避するためにスタックを付け替えるマクロ. 具体的には以下のようにして用いる.

```c++
#include "stack_extend.hpp"

int main(){
    BEGIN_STACK_EXTEND(256 * 1024 *1024);   // 256 MB

    /**
     * メインの処理
     */

    END_STACK_EXTEND;
}
```

## Links
- [スタック拡張マクロ \| libalgo](https://tubo28.me/compprog/algorithm/extend-stack/)
