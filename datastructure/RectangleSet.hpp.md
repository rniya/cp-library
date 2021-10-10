---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/datastructure/RectangleSet.md
    document_title: Rectangle Set
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef\
    \ unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first <<\
    \ ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n   \
    \ for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const unordered_map<T, U>& m) {\n    os << '{';\n  \
    \  for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const multiset<T>& s) {\n    os << '{';\n    for (auto itr = s.begin();\
    \ itr != s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os <<\
    \ ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream&\
    \ operator<<(ostream& os, const unordered_set<T>& s) {\n    os << '{';\n    for\
    \ (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n        if (++itr\
    \ != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const deque<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&,\
    \ const T&) {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
    \ os, const T& t) {\n    if (i) os << ',';\n    os << get<i>(t);\n    print_tuple<i\
    \ + 1, T, Args...>(os, t);\n}\ntemplate <typename... Args> ostream& operator<<(ostream&\
    \ os, const tuple<Args...>& t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>,\
    \ Args...>(os, t);\n    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\\
    n'; }\ntemplate <class Head, class... Tail> void debug_out(Head&& head, Tail&&...\
    \ tail) {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n \
    \   debug_out(move(tail)...);\n}\n#ifdef LOCAL\n#define debug(...)           \
    \                                                        \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ cerr << #__VA_ARGS__ << \" :[\" << __LINE__ << \":\" << __FUNCTION__ << \"]\"\
    \ << '\\n'; \\\n    cerr << \" \";                                           \
    \                          \\\n    debug_out(__VA_ARGS__)\n#else\n#define debug(...)\
    \ 42\n#endif\n\ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y,\
    \ x % y) : x; }\ntemplate <typename T> T lcm(T x, T y) { return x / gcd(x, y)\
    \ * y; }\n\nint topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\nint topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n\
    int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long\
    \ long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\nint popcount(signed t)\
    \ { return __builtin_popcount(t); }\nint popcount(long long t) { return __builtin_popcountll(t);\
    \ }\nbool ispow2(int i) { return i && (i & -i) == i; }\n\ntemplate <class T> T\
    \ ceil(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? (x + y - 1) / y :\
    \ x / y);\n}\ntemplate <class T> T floor(T x, T y) {\n    assert(y >= 1);\n  \
    \  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <class T1, class T2>\
    \ inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2> inline\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"datastructure/RectangleSet.hpp\"\
    \n\n/**\n * @brief Rectangle Set\n * @docs docs/datastructure/RectangleSet.md\n\
    \ */\ntemplate <typename T> struct RectangleSet {\n    constexpr T inf = numeric_limits<T>::max()\
    \ / 2;\n    set<pair<T, T>> s;\n    multiset<T> val;\n    RectangleSet() {\n \
    \       s.emplace(-1, inf);\n        s.emplace(0, 0);\n        val.emplace(0);\n\
    \    }\n\n    void add(T x, T y) {\n        auto itr = s.lower_bound(make_pair(x,\
    \ y));\n        bool flag = false;\n        T nx = inf, ny = inf;\n        while\
    \ (1) {\n            itr = prev(itr);\n            if (y < itr->second) break;\n\
    \            flag = true;\n            nx = min(nx, itr->first);\n           \
    \ ny = min(ny, itr->second);\n            val.erase(val.find(itr->first + itr->second));\n\
    \            itr = s.erase(itr);\n        }\n        if (flag) {\n           \
    \ s.emplace(nx, y);\n            val.emplace(nx + y);\n            s.emplace(x,\
    \ ny);\n            val.emplace(x + ny);\n        }\n    }\n    T query() { return\
    \ *val.begin(); }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Rectangle Set\n\
    \ * @docs docs/datastructure/RectangleSet.md\n */\ntemplate <typename T> struct\
    \ RectangleSet {\n    constexpr T inf = numeric_limits<T>::max() / 2;\n    set<pair<T,\
    \ T>> s;\n    multiset<T> val;\n    RectangleSet() {\n        s.emplace(-1, inf);\n\
    \        s.emplace(0, 0);\n        val.emplace(0);\n    }\n\n    void add(T x,\
    \ T y) {\n        auto itr = s.lower_bound(make_pair(x, y));\n        bool flag\
    \ = false;\n        T nx = inf, ny = inf;\n        while (1) {\n            itr\
    \ = prev(itr);\n            if (y < itr->second) break;\n            flag = true;\n\
    \            nx = min(nx, itr->first);\n            ny = min(ny, itr->second);\n\
    \            val.erase(val.find(itr->first + itr->second));\n            itr =\
    \ s.erase(itr);\n        }\n        if (flag) {\n            s.emplace(nx, y);\n\
    \            val.emplace(nx + y);\n            s.emplace(x, ny);\n           \
    \ val.emplace(x + ny);\n        }\n    }\n    T query() { return *val.begin();\
    \ }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/RectangleSet.hpp
  requiredBy: []
  timestamp: '2021-07-19 14:45:19+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: datastructure/RectangleSet.hpp
layout: document
redirect_from:
- /library/datastructure/RectangleSet.hpp
- /library/datastructure/RectangleSet.hpp.html
title: Rectangle Set
---
## 概要
「$x \geqq a$または$y \geqq b$」という条件を追加して$\min x+y$を計算する.
- `add(a, b)` : 「$x \geqq a$または$y \geqq b$」という条件を追加する.
- `query()` : その時点での$\min x+y$を返す.

## 計算量
均し$O(n\log n)$

## 問題例
[Codeforces Round #230 (Div. 1) D. Three Arrays](https://codeforces.com/contest/392/problem/D)