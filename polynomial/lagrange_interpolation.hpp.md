---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/polynomial/lagrange_interpolation.md
    document_title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593"
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"polynomial/lagrange_interpolation.hpp\"\
    \n\n/**\n * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\n * @docs\
    \ docs/polynomial/lagrange_interpolation.md\n */\ntemplate <typename M> M lagrange_interpolation(vector<M>\
    \ x, vector<M> y, M T) {\n    int n = x.size() - 1;\n    M res = 0;\n    for (int\
    \ i = 0; i <= n; i++) {\n        M c = 1;\n        for (int j = 0; j <= n; j++)\
    \ {\n            if (i == j) continue;\n            (c *= T - x[j]) /= x[i] -\
    \ x[j];\n        }\n        res += c * y[i];\n    }\n    return res;\n}\n\ntemplate\
    \ <typename M> M lagrange_interpolation_arithmetic(vector<M>& y, M T) {\n    int\
    \ n = y.size() - 1;\n    if (T.value() <= n) return y[T.value()];\n    vector<M>\
    \ left(n + 1, 1), right(n + 1, 1), fac(n + 1, 1), finv(n + 1, 1);\n    for (int\
    \ i = 0; i < n; i++) left[i + 1] = left[i] * (T - i);\n    for (int i = n - 1;\
    \ i >= 0; --i) right[i] = right[i + 1] * (T - (i + 1));\n    for (int i = 1; i\
    \ <= n; i++) fac[i] = fac[i - 1] * i;\n    finv[n] = (M)1 / fac[n];\n    for (int\
    \ i = n; i > 0; --i) finv[i - 1] = finv[i] * i;\n    M res = 0;\n    for (int\
    \ i = 0; i <= n; i++) {\n        M add = y[i] * left[i] * right[i] * finv[i] *\
    \ finv[n - i];\n        if ((n - i) & 1)\n            res -= add;\n        else\n\
    \            res += add;\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief \u30E9\u30B0\u30E9\
    \u30F3\u30B8\u30E5\u88DC\u9593\n * @docs docs/polynomial/lagrange_interpolation.md\n\
    \ */\ntemplate <typename M> M lagrange_interpolation(vector<M> x, vector<M> y,\
    \ M T) {\n    int n = x.size() - 1;\n    M res = 0;\n    for (int i = 0; i <=\
    \ n; i++) {\n        M c = 1;\n        for (int j = 0; j <= n; j++) {\n      \
    \      if (i == j) continue;\n            (c *= T - x[j]) /= x[i] - x[j];\n  \
    \      }\n        res += c * y[i];\n    }\n    return res;\n}\n\ntemplate <typename\
    \ M> M lagrange_interpolation_arithmetic(vector<M>& y, M T) {\n    int n = y.size()\
    \ - 1;\n    if (T.value() <= n) return y[T.value()];\n    vector<M> left(n + 1,\
    \ 1), right(n + 1, 1), fac(n + 1, 1), finv(n + 1, 1);\n    for (int i = 0; i <\
    \ n; i++) left[i + 1] = left[i] * (T - i);\n    for (int i = n - 1; i >= 0; --i)\
    \ right[i] = right[i + 1] * (T - (i + 1));\n    for (int i = 1; i <= n; i++) fac[i]\
    \ = fac[i - 1] * i;\n    finv[n] = (M)1 / fac[n];\n    for (int i = n; i > 0;\
    \ --i) finv[i - 1] = finv[i] * i;\n    M res = 0;\n    for (int i = 0; i <= n;\
    \ i++) {\n        M add = y[i] * left[i] * right[i] * finv[i] * finv[n - i];\n\
    \        if ((n - i) & 1)\n            res -= add;\n        else\n           \
    \ res += add;\n    }\n    return res;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: polynomial/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2021-09-21 16:26:52+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/665.test.cpp
documentation_of: polynomial/lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/polynomial/lagrange_interpolation.hpp
- /library/polynomial/lagrange_interpolation.hpp.html
title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593"
---
## 概要

## 計算量