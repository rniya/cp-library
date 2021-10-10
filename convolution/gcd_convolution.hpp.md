---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/886.test.cpp
    title: test/yukicoder/886.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/convolution/gcd_convolution.md
    document_title: "$\\gcd$ convolution (\u6DFB\u5B57 $\\gcd$ \u7573\u307F\u8FBC\u307F\
      )"
    links: []
  bundledCode: "#line 2 \"convolution/gcd_convolution.hpp\"\n#include <cassert>\n\
    #include <vector>\n\nnamespace gcd_convolution {\n\n// f(k) <- \\sum_{k | i} f(i)\n\
    template <typename T> void divisor_transform(std::vector<T>& f) {\n    int n =\
    \ f.size();\n    std::vector<bool> sieve(n, true);\n    for (int p = 2; p < n;\
    \ p++) {\n        if (sieve[p]) {\n            for (int k = (n - 1) / p; k > 0;\
    \ k--) {\n                sieve[k * p] = false;\n                f[k] += f[k *\
    \ p];\n            }\n        }\n    }\n    for (int i = 1; i < n; i++) f[i] +=\
    \ f[0];\n}\n\n// inverse of divisor transform\ntemplate <typename T> void inverse_divisor_transform(std::vector<T>&\
    \ f) {\n    int n = f.size();\n    std::vector<bool> sieve(n, true);\n    for\
    \ (int i = 1; i < n; i++) f[i] -= f[0];\n    for (int p = 2; p < n; p++) {\n \
    \       if (sieve[p]) {\n            for (int k = 1 / p; k * p < n; k++) {\n \
    \               sieve[k * p] = false;\n                f[k] -= f[k * p];\n   \
    \         }\n        }\n    }\n}\n\ntemplate <typename T> std::vector<T> gcd_convolution(std::vector<T>\
    \ f, std::vector<T> g) {\n    assert(f.size() == g.size());\n    divisor_transform(f);\n\
    \    divisor_transform(g);\n    for (size_t i = 0; i < f.size(); i++) f[i] *=\
    \ g[i];\n    inverse_divisor_transform(f);\n    return f;\n}\n\n}  // namespace\
    \ gcd_convolution\n\n/**\n * @brief $\\gcd$ convolution (\u6DFB\u5B57 $\\gcd$\
    \ \u7573\u307F\u8FBC\u307F)\n * @docs docs/convolution/gcd_convolution.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\nnamespace gcd_convolution\
    \ {\n\n// f(k) <- \\sum_{k | i} f(i)\ntemplate <typename T> void divisor_transform(std::vector<T>&\
    \ f) {\n    int n = f.size();\n    std::vector<bool> sieve(n, true);\n    for\
    \ (int p = 2; p < n; p++) {\n        if (sieve[p]) {\n            for (int k =\
    \ (n - 1) / p; k > 0; k--) {\n                sieve[k * p] = false;\n        \
    \        f[k] += f[k * p];\n            }\n        }\n    }\n    for (int i =\
    \ 1; i < n; i++) f[i] += f[0];\n}\n\n// inverse of divisor transform\ntemplate\
    \ <typename T> void inverse_divisor_transform(std::vector<T>& f) {\n    int n\
    \ = f.size();\n    std::vector<bool> sieve(n, true);\n    for (int i = 1; i <\
    \ n; i++) f[i] -= f[0];\n    for (int p = 2; p < n; p++) {\n        if (sieve[p])\
    \ {\n            for (int k = 1 / p; k * p < n; k++) {\n                sieve[k\
    \ * p] = false;\n                f[k] -= f[k * p];\n            }\n        }\n\
    \    }\n}\n\ntemplate <typename T> std::vector<T> gcd_convolution(std::vector<T>\
    \ f, std::vector<T> g) {\n    assert(f.size() == g.size());\n    divisor_transform(f);\n\
    \    divisor_transform(g);\n    for (size_t i = 0; i < f.size(); i++) f[i] *=\
    \ g[i];\n    inverse_divisor_transform(f);\n    return f;\n}\n\n}  // namespace\
    \ gcd_convolution\n\n/**\n * @brief $\\gcd$ convolution (\u6DFB\u5B57 $\\gcd$\
    \ \u7573\u307F\u8FBC\u307F)\n * @docs docs/convolution/gcd_convolution.md\n */"
  dependsOn: []
  isVerificationFile: false
  path: convolution/gcd_convolution.hpp
  requiredBy: []
  timestamp: '2021-10-03 17:00:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/886.test.cpp
documentation_of: convolution/gcd_convolution.hpp
layout: document
redirect_from:
- /library/convolution/gcd_convolution.hpp
- /library/convolution/gcd_convolution.hpp.html
title: "$\\gcd$ convolution (\u6DFB\u5B57 $\\gcd$ \u7573\u307F\u8FBC\u307F)"
---
## 概要
数列を添字の $\gcd$ 演算に関して畳み込む.

| 関数                           | 効果                                                                                                         | 時間計算量          |
| ------------------------------ | ------------------------------------------------------------------------------------------------------------ | ------------------- |
| `divisor_transform(f)`         | $f(k) \leftarrow \sum_{k \| i} f(i)$ と変換する。                                                            | $O(n \log(\log n))$ |
| `inverse_divisor_transform(f)` | `divisor_transform` の逆変換を施す。                                                                         | $O(n \log(\log n))$ |
| `gcd_convolution(f, g)`        | 列 $f, g$ を $\gcd$ 演算に関して畳み込む. すなわち,  $h_k = \sum_{\gcd(i, j) = k} f_ig_j$ なる列 $h$ を返す. | $O(n \log(\log n))$ |

## 問題例
- [AtCoder Grand Contest 038 C - LCMs](https://atcoder.jp/contests/agc038/tasks/agc038_c)
- [COMPFEST 13 - Finals Online Mirror (Unrated, ICPC Rules, Teams Preferred) G. GCD Festival](https://codeforces.com/contest/1575/problem/G)

## Links
- [約数集合でのゼータ変換・メビウス変換的なやつと畳み込み - kazuma8128’s blog](https://kazuma8128.hatenablog.com/entry/2018/07/29/231819)
- [添え字 gcd での畳み込みで AGC038-C を解く - noshi91のメモ](https://noshi91.hatenablog.com/entry/2019/09/23/002445)
- [高速ゼータ変換の約数版 $O(N \log(\log(N)))$ - noshi91のメモ](https://noshi91.hatenablog.com/entry/2018/12/27/121649)
