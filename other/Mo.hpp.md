---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/other/Mo.md
    document_title: Mo's Algorithm
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n      \
    \  os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
    }\ntemplate <typename T, typename U, typename V> ostream& operator<<(ostream&\
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
    \ i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" : \" \"\
    );\n    }\n    return os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate\
    \ <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {\n\
    \    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"other/Mo.hpp\"\n\n/**\n\
    \ * @brief Mo's Algorithm\n * @docs docs/other/Mo.md\n */\nstruct Mo {\n    int\
    \ sz;\n    vector<int> left, right;\n    Mo(int n) : sz((int)sqrt(n)) {}\n   \
    \ void insert(int l, int r) {\n        left.emplace_back(l);\n        right.emplace_back(r);\n\
    \    }\n    template <typename ADDL, typename ADDR, typename DELL, typename DELR,\
    \ typename REM>\n    void build(const ADDL& add_left,\n               const ADDR&\
    \ add_right,\n               const DELL& del_left,\n               const DELR&\
    \ del_right,\n               const REM& rem) {\n        int q = left.size();\n\
    \        vector<int> ord(q);\n        iota(ord.begin(), ord.end(), 0);\n     \
    \   sort(ord.begin(), ord.end(),\n             [&](int a, int b) { return (left[a]\
    \ / sz != left[b] / sz ? left[a] < left[b] : right[a] < right[b]); });\n     \
    \   int l = 0, r = 0;\n        for (int idx : ord) {\n            while (l > left[idx])\
    \ add_left(--l);\n            while (r < right[idx]) add_right(r++);\n       \
    \     while (l < left[idx]) del_left(l++);\n            while (r > right[idx])\
    \ del_right(--r);\n            rem(idx);\n        }\n    }\n    template <typename\
    \ ADD, typename DEL, typename REM> void build(const ADD& add, const DEL& del,\
    \ const REM& rem) {\n        build(add, add, del, del, rem);\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Mo's Algorithm\n\
    \ * @docs docs/other/Mo.md\n */\nstruct Mo {\n    int sz;\n    vector<int> left,\
    \ right;\n    Mo(int n) : sz((int)sqrt(n)) {}\n    void insert(int l, int r) {\n\
    \        left.emplace_back(l);\n        right.emplace_back(r);\n    }\n    template\
    \ <typename ADDL, typename ADDR, typename DELL, typename DELR, typename REM>\n\
    \    void build(const ADDL& add_left,\n               const ADDR& add_right,\n\
    \               const DELL& del_left,\n               const DELR& del_right,\n\
    \               const REM& rem) {\n        int q = left.size();\n        vector<int>\
    \ ord(q);\n        iota(ord.begin(), ord.end(), 0);\n        sort(ord.begin(),\
    \ ord.end(),\n             [&](int a, int b) { return (left[a] / sz != left[b]\
    \ / sz ? left[a] < left[b] : right[a] < right[b]); });\n        int l = 0, r =\
    \ 0;\n        for (int idx : ord) {\n            while (l > left[idx]) add_left(--l);\n\
    \            while (r < right[idx]) add_right(r++);\n            while (l < left[idx])\
    \ del_left(l++);\n            while (r > right[idx]) del_right(--r);\n       \
    \     rem(idx);\n        }\n    }\n    template <typename ADD, typename DEL, typename\
    \ REM> void build(const ADD& add, const DEL& del, const REM& rem) {\n        build(add,\
    \ add, del, del, rem);\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: other/Mo.hpp
  requiredBy: []
  timestamp: '2021-01-20 10:53:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static_range_inversions_query.test.cpp
  - test/yukicoder/1270.test.cpp
documentation_of: other/Mo.hpp
layout: document
redirect_from:
- /library/other/Mo.hpp
- /library/other/Mo.hpp.html
title: Mo's Algorithm
---
## 概要

## 計算量