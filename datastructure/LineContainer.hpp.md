---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/datastructure/LineContainer.md
    document_title: Line Container (based on kactl)
    links:
    - https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h#L1
  bundledCode: "#line 2 \"datastructure/LineContainer.hpp\"\n#include <cassert>\n\
    #include <climits>\n#include <iterator>\n#include <set>\n\nstruct Line {\n   \
    \ mutable long long k, m, p;\n    bool operator<(const Line& o) const { return\
    \ k < o.k; }\n    bool operator<(long long x) const { return p < x; }\n};\n\n\
    template <bool isMin = true> struct LineContainer : std::multiset<Line, std::less<>>\
    \ {\n    // (for doubles, use inf = 1/.0, div(a,b) = a/b)\n    const long long\
    \ inf = LLONG_MAX / 2;\n    long long div(long long a, long long b) {  // floored\
    \ division\n        return a / b - ((a ^ b) < 0 && a % b);\n    }\n    bool isect(iterator\
    \ x, iterator y) {\n        if (y == end()) {\n            x->p = inf;\n     \
    \       return false;\n        }\n        if (x->k == y->k)\n            x->p\
    \ = x->m > y->m ? inf : -inf;\n        else\n            x->p = div(y->m - x->m,\
    \ x->k - y->k);\n        return x->p >= y->p;\n    }\n    void add(long long k,\
    \ long long m) {\n        if (isMin) k = -k, m = -m;\n        auto z = insert({k,\
    \ m, 0}), y = z++, x = y;\n        while (isect(y, z)) z = erase(z);\n       \
    \ if (x != begin() && isect(--x, y)) isect(x, y = erase(y));\n        while ((y\
    \ = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));\n    }\n    long long\
    \ query(long long x) {\n        assert(!empty());\n        auto l = *lower_bound(x);\n\
    \        long long s = 1;\n        if (isMin) s = -1;\n        return s * (l.k\
    \ * x + l.m);\n    }\n};\n\n/**\n * @brief Line Container (based on kactl)\n *\
    \ @docs docs/datastructure/LineContainer.md\n * @see https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h#L1\n\
    \ */\n"
  code: "#pragma once\n#include <cassert>\n#include <climits>\n#include <iterator>\n\
    #include <set>\n\nstruct Line {\n    mutable long long k, m, p;\n    bool operator<(const\
    \ Line& o) const { return k < o.k; }\n    bool operator<(long long x) const {\
    \ return p < x; }\n};\n\ntemplate <bool isMin = true> struct LineContainer : std::multiset<Line,\
    \ std::less<>> {\n    // (for doubles, use inf = 1/.0, div(a,b) = a/b)\n    const\
    \ long long inf = LLONG_MAX / 2;\n    long long div(long long a, long long b)\
    \ {  // floored division\n        return a / b - ((a ^ b) < 0 && a % b);\n   \
    \ }\n    bool isect(iterator x, iterator y) {\n        if (y == end()) {\n   \
    \         x->p = inf;\n            return false;\n        }\n        if (x->k\
    \ == y->k)\n            x->p = x->m > y->m ? inf : -inf;\n        else\n     \
    \       x->p = div(y->m - x->m, x->k - y->k);\n        return x->p >= y->p;\n\
    \    }\n    void add(long long k, long long m) {\n        if (isMin) k = -k, m\
    \ = -m;\n        auto z = insert({k, m, 0}), y = z++, x = y;\n        while (isect(y,\
    \ z)) z = erase(z);\n        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));\n\
    \        while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));\n\
    \    }\n    long long query(long long x) {\n        assert(!empty());\n      \
    \  auto l = *lower_bound(x);\n        long long s = 1;\n        if (isMin) s =\
    \ -1;\n        return s * (l.k * x + l.m);\n    }\n};\n\n/**\n * @brief Line Container\
    \ (based on kactl)\n * @docs docs/datastructure/LineContainer.md\n * @see https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h#L1\n\
    \ */"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/LineContainer.hpp
  requiredBy: []
  timestamp: '2021-09-22 20:47:22+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/LineContainer.hpp
layout: document
redirect_from:
- /library/datastructure/LineContainer.hpp
- /library/datastructure/LineContainer.hpp.html
title: Line Container (based on kactl)
---
## 概要
直線 $f(x) = ax + b$ の追加 (ただし, $a$ は単調増加もしくは単調減少) 及びある $x$ での最小値 (最大値) クエリを効率的に処理するデータ構造. Convex Hull Trick と異なり, 追加する直線の傾きの単調性は問わない.
実装は [kactl](https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h#L1) から.

| メンバ関数  | 効果                             | 時間計算量         |
| ----------- | -------------------------------- | ------------------ |
| `add(k, m)` | 直線 $f(x) = kx + m$ を追加する. | 全体 $O(n \log n)$ |
| `query(x)`  | $x$ における最小値を求める.      | クエリ $O(\log n)$ |

## 問題例
- [TOKI Regular Open Contest #22 F. MCD](https://tlx.toki.id/contests/troc-22/problems/F)