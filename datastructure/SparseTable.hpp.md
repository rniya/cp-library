---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/staticrmq.test.cpp
    title: test/yosupo/staticrmq.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/SparseTable.md
    document_title: Sparse table
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n \
    \       os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return\
    \ os;\n}\ntemplate <typename T, typename U, typename V> ostream& operator<<(ostream&\
    \ os, const tuple<T, U, V>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t)\
    \ << ',' << get<2>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U,\
    \ V, W>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t)\
    \ << ',' << get<3>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U> ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n\
    \    for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
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
    \" : \" \");\n    }\n    return os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\n\
    template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail)\
    \ {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
    }\n#ifdef LOCAL\n#define debug(...)                                          \
    \                         \\\n    cerr << \" \";                             \
    \                                        \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) 42\n#endif\n\ntemplate <typename\
    \ T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename\
    \ T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class\
    \ T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n   \
    \     return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2>\
    \ inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\n#line 3 \"datastructure/SparseTable.hpp\"\
    \n\n/**\n * @brief Sparse table\n * @docs docs/datastructure/SparseTable.md\n\
    \ */\ntemplate <typename T> struct SparseTable {\n    typedef function<T(T, T)>\
    \ F;\n    vector<vector<T>> dat;\n    vector<int> lookup;\n    const F f;\n  \
    \  SparseTable(F f) : f(f) {}\n    void build(const vector<T>& v) {\n        int\
    \ n = v.size(), h = 1;\n        while ((1 << h) <= n) h++;\n        dat.assign(h,\
    \ vector<T>(n));\n        lookup.assign(n + 1, 0);\n        for (int i = 2; i\
    \ <= n; i++) lookup[i] = lookup[i >> 1] + 1;\n        for (int j = 0; j < n; j++)\
    \ dat[0][j] = v[j];\n        for (int i = 1, mask = 1; i < h; i++, mask <<= 1)\
    \ {\n            for (int j = 0; j < n; j++) {\n                dat[i][j] = f(dat[i\
    \ - 1][j], dat[i - 1][min(j + mask, n - 1)]);\n            }\n        }\n    }\n\
    \    T query(int a, int b) {\n        int d = lookup[b - a];\n        return f(dat[d][a],\
    \ dat[d][b - (1 << d)]);\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Sparse table\n *\
    \ @docs docs/datastructure/SparseTable.md\n */\ntemplate <typename T> struct SparseTable\
    \ {\n    typedef function<T(T, T)> F;\n    vector<vector<T>> dat;\n    vector<int>\
    \ lookup;\n    const F f;\n    SparseTable(F f) : f(f) {}\n    void build(const\
    \ vector<T>& v) {\n        int n = v.size(), h = 1;\n        while ((1 << h) <=\
    \ n) h++;\n        dat.assign(h, vector<T>(n));\n        lookup.assign(n + 1,\
    \ 0);\n        for (int i = 2; i <= n; i++) lookup[i] = lookup[i >> 1] + 1;\n\
    \        for (int j = 0; j < n; j++) dat[0][j] = v[j];\n        for (int i = 1,\
    \ mask = 1; i < h; i++, mask <<= 1) {\n            for (int j = 0; j < n; j++)\
    \ {\n                dat[i][j] = f(dat[i - 1][j], dat[i - 1][min(j + mask, n -\
    \ 1)]);\n            }\n        }\n    }\n    T query(int a, int b) {\n      \
    \  int d = lookup[b - a];\n        return f(dat[d][a], dat[d][b - (1 << d)]);\n\
    \    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/SparseTable.hpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/staticrmq.test.cpp
documentation_of: datastructure/SparseTable.hpp
layout: document
redirect_from:
- /library/datastructure/SparseTable.hpp
- /library/datastructure/SparseTable.hpp.html
title: Sparse table
---
## 概要

## 計算量