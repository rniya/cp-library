---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/base.hpp\"\n#include <bits/stdc++.h>\n#ifdef LOCAL\n\
    #include <debug.hpp>\n#else\n#define debug(...) void(0)\n#endif\n\ntemplate <class\
    \ T> std::istream& operator>>(std::istream& is, std::vector<T>& v) {\n    for\
    \ (auto& e : v) {\n        is >> e;\n    }\n    return is;\n}\n\ntemplate <class\
    \ T> std::ostream& operator<<(std::ostream& os, const std::vector<T>& v) {\n \
    \   for (std::string_view sep = \"\"; const auto& e : v) {\n        os << std::exchange(sep,\
    \ \" \") << e;\n    }\n    return os;\n}\n\ntemplate <class T, class U = T> bool\
    \ chmin(T& x, U&& y) {\n    return y < x and (x = std::forward<U>(y), true);\n\
    }\n\ntemplate <class T, class U = T> bool chmax(T& x, U&& y) {\n    return x <\
    \ y and (x = std::forward<U>(y), true);\n}\n\ntemplate <class T> void mkuni(std::vector<T>&\
    \ v) {\n    std::ranges::sort(v);\n    auto result = std::ranges::unique(v);\n\
    \    v.erase(result.begin(), result.end());\n}\n\ntemplate <class T> int lwb(const\
    \ std::vector<T>& v, const T& x) {\n    return std::distance(v.begin(), std::ranges::lower_bound(v,\
    \ x));\n}\n#line 3 \"src/datastructure/RectangleSet.hpp\"\n\ntemplate <typename\
    \ T> struct RectangleSet {\n    constexpr T inf = numeric_limits<T>::max() / 2;\n\
    \    set<pair<T, T>> s;\n    multiset<T> val;\n    RectangleSet() {\n        s.emplace(-1,\
    \ inf);\n        s.emplace(0, 0);\n        val.emplace(0);\n    }\n\n    void\
    \ add(T x, T y) {\n        auto itr = s.lower_bound(make_pair(x, y));\n      \
    \  bool flag = false;\n        T nx = inf, ny = inf;\n        while (1) {\n  \
    \          itr = prev(itr);\n            if (y < itr->second) break;\n       \
    \     flag = true;\n            nx = min(nx, itr->first);\n            ny = min(ny,\
    \ itr->second);\n            val.erase(val.find(itr->first + itr->second));\n\
    \            itr = s.erase(itr);\n        }\n        if (flag) {\n           \
    \ s.emplace(nx, y);\n            val.emplace(nx + y);\n            s.emplace(x,\
    \ ny);\n            val.emplace(x + ny);\n        }\n    }\n    T query() { return\
    \ *val.begin(); }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate <typename T> struct RectangleSet\
    \ {\n    constexpr T inf = numeric_limits<T>::max() / 2;\n    set<pair<T, T>>\
    \ s;\n    multiset<T> val;\n    RectangleSet() {\n        s.emplace(-1, inf);\n\
    \        s.emplace(0, 0);\n        val.emplace(0);\n    }\n\n    void add(T x,\
    \ T y) {\n        auto itr = s.lower_bound(make_pair(x, y));\n        bool flag\
    \ = false;\n        T nx = inf, ny = inf;\n        while (1) {\n            itr\
    \ = prev(itr);\n            if (y < itr->second) break;\n            flag = true;\n\
    \            nx = min(nx, itr->first);\n            ny = min(ny, itr->second);\n\
    \            val.erase(val.find(itr->first + itr->second));\n            itr =\
    \ s.erase(itr);\n        }\n        if (flag) {\n            s.emplace(nx, y);\n\
    \            val.emplace(nx + y);\n            s.emplace(x, ny);\n           \
    \ val.emplace(x + ny);\n        }\n    }\n    T query() { return *val.begin();\
    \ }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/datastructure/RectangleSet.hpp
  requiredBy: []
  timestamp: '2024-05-12 03:06:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/RectangleSet.hpp
layout: document
title: Rectangle Set
---

## 概要
「$x \geqq a$ または $y \geqq b$」という条件が追加されていく際の $\min x + y$ を逐次計算する．

| メンバ関数  | 効果                                                     | 時間計算量       |
| ----------- | -------------------------------------------------------- | ---------------- |
| `add(a, b)` | 「$x \geqq a$ または $y \geqq b$」という条件を追加する． | 均し $O(\log n)$ |
| `query()`   | その時点での $\min x + y$ を返す．                       | $O(\log n)$      |

## 問題例
[Codeforces Round #230 (Div. 1) D. Three Arrays](https://codeforces.com/contest/392/problem/D)
