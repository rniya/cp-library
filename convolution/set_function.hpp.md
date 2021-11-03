---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bitwise_and_convolution.test.cpp
    title: test/yosupo/bitwise_and_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bitwise_xor_convolution.test.cpp
    title: test/yosupo/bitwise_xor_convolution.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1240.test.cpp
    title: test/yukicoder/1240.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1289.test.cpp
    title: test/yukicoder/1289.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/convolution/set_function.md
    document_title: set function (FZT, FMT, FWHT)
    links: []
  bundledCode: "#line 2 \"convolution/set_function.hpp\"\n#include <cassert>\n#include\
    \ <vector>\n\nnamespace set_function {\n\n// subset sum : f(S) <- \\sum_{T \\\
    subseteq S} f(T)\ntemplate <typename T> void subset_zeta_transform(std::vector<T>&\
    \ f) {\n    int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i\
    \ = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if\
    \ ((j & i) == 0) {\n                f[j | i] += f[j];\n            }\n       \
    \ }\n    }\n}\n\n// inverse of subset sum\n// g = FZT(f) \\iff f = FMT(g)\ntemplate\
    \ <typename T> void subset_mobius_transform(std::vector<T>& f) {\n    int n =\
    \ f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i = 1; i < n; i <<=\
    \ 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j & i) == 0) {\n\
    \                f[j | i] -= f[j];\n            }\n        }\n    }\n}\n\n// superset\
    \ sum : f(S) <- \\sum_{T \\supseteq S} f(T)\ntemplate <typename T> void superset_zeta_transform(std::vector<T>&\
    \ f) {\n    int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i\
    \ = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if\
    \ ((j & i) == 0) {\n                f[j] += f[j | i];\n            }\n       \
    \ }\n    }\n}\n\n// inverse of superset sum\n// g = FZT(f) \\iff f = FMT(g)\n\
    template <typename T> void superset_mobius_transform(std::vector<T>& f) {\n  \
    \  int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i = 1; i <\
    \ n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j & i)\
    \ == 0) {\n                f[j] -= f[j | i];\n            }\n        }\n    }\n\
    }\n\ntemplate <typename T> void walsh_hadamard_transform(std::vector<T>& f, bool\
    \ inv = false) {\n    int n = f.size();\n    assert((n & (n - 1)) == 0);\n   \
    \ for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n \
    \           if ((j & i) == 0) {\n                T x = f[j], y = f[j | i];\n \
    \               f[j] = x + y, f[j | i] = x - y;\n            }\n        }\n  \
    \  }\n    if (inv) {\n        if (std::is_integral<T>::value) {\n            for\
    \ (auto& x : f) x /= n;\n        } else {\n            T inv_n = T(1) / f.size();\n\
    \            for (auto& x : f) x *= inv_n;\n        }\n    }\n}\n\ntemplate <typename\
    \ T> std::vector<T> and_convolution(std::vector<T> f, std::vector<T> g) {\n  \
    \  assert(f.size() == g.size());\n    superset_zeta_transform(f);\n    superset_zeta_transform(g);\n\
    \    for (size_t i = 0; i < f.size(); i++) f[i] *= g[i];\n    superset_mobius_transform(f);\n\
    \    return f;\n}\n\ntemplate <typename T> std::vector<T> or_convolution(std::vector<T>\
    \ f, std::vector<T> g) {\n    assert(f.size() == g.size());\n    subset_zeta_transform(f);\n\
    \    subset_zeta_transform(g);\n    for (size_t i = 0; i < f.size(); i++) f[i]\
    \ *= g[i];\n    subset_mobius_transform(f);\n    return f;\n}\n\ntemplate <typename\
    \ T> std::vector<T> xor_convolution(std::vector<T> f, std::vector<T> g) {\n  \
    \  assert(f.size() == g.size());\n    walsh_hadamard_transform(f);\n    walsh_hadamard_transform(g);\n\
    \    for (size_t i = 0; i < f.size(); i++) f[i] *= g[i];\n    walsh_hadamard_transform(f,\
    \ true);\n    return f;\n}\n\n}  // namespace set_function\n\n/**\n * @brief set\
    \ function (FZT, FMT, FWHT)\n * @docs docs/convolution/set_function.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\nnamespace set_function\
    \ {\n\n// subset sum : f(S) <- \\sum_{T \\subseteq S} f(T)\ntemplate <typename\
    \ T> void subset_zeta_transform(std::vector<T>& f) {\n    int n = f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    for (int i = 1; i < n; i <<= 1) {\n    \
    \    for (int j = 0; j < n; j++) {\n            if ((j & i) == 0) {\n        \
    \        f[j | i] += f[j];\n            }\n        }\n    }\n}\n\n// inverse of\
    \ subset sum\n// g = FZT(f) \\iff f = FMT(g)\ntemplate <typename T> void subset_mobius_transform(std::vector<T>&\
    \ f) {\n    int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i\
    \ = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if\
    \ ((j & i) == 0) {\n                f[j | i] -= f[j];\n            }\n       \
    \ }\n    }\n}\n\n// superset sum : f(S) <- \\sum_{T \\supseteq S} f(T)\ntemplate\
    \ <typename T> void superset_zeta_transform(std::vector<T>& f) {\n    int n =\
    \ f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i = 1; i < n; i <<=\
    \ 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j & i) == 0) {\n\
    \                f[j] += f[j | i];\n            }\n        }\n    }\n}\n\n// inverse\
    \ of superset sum\n// g = FZT(f) \\iff f = FMT(g)\ntemplate <typename T> void\
    \ superset_mobius_transform(std::vector<T>& f) {\n    int n = f.size();\n    assert((n\
    \ & (n - 1)) == 0);\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j\
    \ = 0; j < n; j++) {\n            if ((j & i) == 0) {\n                f[j] -=\
    \ f[j | i];\n            }\n        }\n    }\n}\n\ntemplate <typename T> void\
    \ walsh_hadamard_transform(std::vector<T>& f, bool inv = false) {\n    int n =\
    \ f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i = 1; i < n; i <<=\
    \ 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j & i) == 0) {\n\
    \                T x = f[j], y = f[j | i];\n                f[j] = x + y, f[j\
    \ | i] = x - y;\n            }\n        }\n    }\n    if (inv) {\n        if (std::is_integral<T>::value)\
    \ {\n            for (auto& x : f) x /= n;\n        } else {\n            T inv_n\
    \ = T(1) / f.size();\n            for (auto& x : f) x *= inv_n;\n        }\n \
    \   }\n}\n\ntemplate <typename T> std::vector<T> and_convolution(std::vector<T>\
    \ f, std::vector<T> g) {\n    assert(f.size() == g.size());\n    superset_zeta_transform(f);\n\
    \    superset_zeta_transform(g);\n    for (size_t i = 0; i < f.size(); i++) f[i]\
    \ *= g[i];\n    superset_mobius_transform(f);\n    return f;\n}\n\ntemplate <typename\
    \ T> std::vector<T> or_convolution(std::vector<T> f, std::vector<T> g) {\n   \
    \ assert(f.size() == g.size());\n    subset_zeta_transform(f);\n    subset_zeta_transform(g);\n\
    \    for (size_t i = 0; i < f.size(); i++) f[i] *= g[i];\n    subset_mobius_transform(f);\n\
    \    return f;\n}\n\ntemplate <typename T> std::vector<T> xor_convolution(std::vector<T>\
    \ f, std::vector<T> g) {\n    assert(f.size() == g.size());\n    walsh_hadamard_transform(f);\n\
    \    walsh_hadamard_transform(g);\n    for (size_t i = 0; i < f.size(); i++) f[i]\
    \ *= g[i];\n    walsh_hadamard_transform(f, true);\n    return f;\n}\n\n}  //\
    \ namespace set_function\n\n/**\n * @brief set function (FZT, FMT, FWHT)\n * @docs\
    \ docs/convolution/set_function.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: convolution/set_function.hpp
  requiredBy: []
  timestamp: '2021-10-03 17:00:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1240.test.cpp
  - test/yukicoder/1289.test.cpp
  - test/yosupo/bitwise_xor_convolution.test.cpp
  - test/yosupo/bitwise_and_convolution.test.cpp
documentation_of: convolution/set_function.hpp
layout: document
redirect_from:
- /library/convolution/set_function.hpp
- /library/convolution/set_function.hpp.html
title: set function (FZT, FMT, FWHT)
---
## 概要
高速ゼータ変換 (Fast Zeta Transform) , 高速メビウス変換 (Fast Mobius Transform) や 高速ウォルシュ-アダマール変換 (Fast Walsh-Hadamard Transform) といった集合に関する諸変換及びそれに関連して bitwise な演算上の畳み込みを扱うライブラリ.

以下に記す時間計算量においては扱う列 $f$ 及び $g$ の長さを $2^n$ としている.

| 関数                               | 効果                                                                                                                            | 時間計算量 |
| ---------------------------------- | ------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| `subset_zeta_transform(f)`         | $f(S) \leftarrow \sum_{T \subseteq S} f(T)$ と変換する.                                                                         | $O(n2^n)$  |
| `subset_mobius_transform(f)`       | `subset_zeta_transform` の逆変換を行う. すなわち, $f(S) \leftarrow \sum_{T \subseteq S} (-1)^{\|S\| - \|T\|}g(T)$ と変換する.   | $O(n2^n)$  |
| `superset_zeta_transform(f)`       | $f(S) \leftarrow \sum_{T \supseteq S} f(T)$ と変換する.                                                                         | $O(n2^n)$  |
| `superset_mobius_transform(f)`     | `superset_zeta_transform` の逆変換を行う. すなわち, $f(S) \leftarrow \sum_{T \subseteq S} (-1)^{\|S\| - \|T\|}g(T)$ と変換する. | $O(n2^n)$  |
| `walsh_hadamard_transform(f, inv)` | $f$ に対して Fast Walsh-Hadamard Transform を適用する. 引数 `inv` を `true` にすると逆変換となる.                               | $O(n2^n)$  |
| `and_convolution(f, g)`            | 列 $f, g$ を bitwise-and 演算に関して畳み込む. すなわち,  $h_k = \sum_{i \& j = k} f_ig_j$ なる列 $h$ を返す.                   | $O(n2^n)$  |
| `or_convolution(f, g)`             | 列 $f, g$ を bitwise-or 演算に関して畳み込む. すなわち,  $h_k = \sum_{i \cup j = k} f_ig_j$ なる列 $h$ を返す.                  | $O(n2^n)$  |
| `xor_convolution(f, g)`            | 列 $f, g$ を bitwise-xor 演算に関して畳み込む. すなわち,  $h_k = \sum_{i \oplus j = k} f_ig_j$ なる列 $h$ を返す.               | $O(n2^n)$  |

## 問題例
- [Codeforces Round #259 (Div. 1) D. Little Pony and Elements of Harmony](https://codeforces.com/contest/453/problem/D)
  - 3 種の畳み込みは適切な変換によって列を各点積で合成できるようにし, 最後にそれを逆変換するという仕組みになっている. よって, 例えば同じ列を $n$ 回合成するというような操作も一度変換した後に列の各要素を $n$ 乗するといった操作によって容易に扱える.
- [AtCoder Beginner Contest 212 H - Nim Counting](https://atcoder.jp/contests/abc212/tasks/abc212_h)
  - 上記に加えて, 変換後の空間での線形性も扱っている.
- [AtCoder Beginner Contest 215 H - Cabbage Master](https://atcoder.jp/contests/abc215/tasks/abc215_h)
- [AtCoder Beginner Contest 220 H - Security Camera](https://atcoder.jp/contests/abc220/tasks/abc220_h)
- [AtCoder Regular Contest 106 E - Medals](https://atcoder.jp/contests/arc106/tasks/arc106_e)

## Links
- [高速ゼータ変換について - Qiita](https://qiita.com/Euglenese/items/260f9ddf513f772d7e42)
- [高速ゼータ・メビウス変換 - Mister雑記](https://misteer.hatenablog.com/entry/zeta-moebius)
- [色々な畳み込み - kazuma8128’s blog](https://kazuma8128.hatenablog.com/entry/2018/05/31/144519)
