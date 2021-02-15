---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.test.cpp
    title: test/aoj/DSL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_D.test.cpp
    title: test/aoj/GRL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_subtree_sum.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/BinaryIndexedTree.md
    document_title: Binary Indexed Tree
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"datastructure/BinaryIndexedTree.hpp\"\
    \n\n/**\n * @brief Binary Indexed Tree\n * @docs docs/datastructure/BinaryIndexedTree.md\n\
    \ */\ntemplate <typename T> class BinaryIndexedTree {\n    T sum(int i) {\n  \
    \      T res = T();\n        for (; i > 0; i -= (i & -i)) res += dat[i];\n   \
    \     return res;\n    }\n\npublic:\n    int n;\n    vector<T> dat;\n    BinaryIndexedTree(int\
    \ n_) : n(n_ + 1), dat(n + 1, 0) {}\n    void add(int i, const T& x) {\n     \
    \   for (++i; i <= n; i += (i & -i)) dat[i] += x;\n    }\n    T query(int l, int\
    \ r) { return sum(r) - sum(l); }\n    int lower_bound(T x) const {\n        if\
    \ (x <= 0) return 0;\n        int pos = 0, k = 1;\n        while (k < n) k <<=\
    \ 1;\n        for (; k > 0; k >>= 1) {\n            if (pos + k <= n && dat[pos\
    \ + k] < x) {\n                x -= dat[pos + k];\n                pos += k;\n\
    \            }\n        }\n        return pos;\n    }\n    int upper_bound(T x)\
    \ const { return lower_bound(x + 1); }\n    T operator[](int i) { return query(i,\
    \ i + 1); }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Binary Indexed Tree\n\
    \ * @docs docs/datastructure/BinaryIndexedTree.md\n */\ntemplate <typename T>\
    \ class BinaryIndexedTree {\n    T sum(int i) {\n        T res = T();\n      \
    \  for (; i > 0; i -= (i & -i)) res += dat[i];\n        return res;\n    }\n\n\
    public:\n    int n;\n    vector<T> dat;\n    BinaryIndexedTree(int n_) : n(n_\
    \ + 1), dat(n + 1, 0) {}\n    void add(int i, const T& x) {\n        for (++i;\
    \ i <= n; i += (i & -i)) dat[i] += x;\n    }\n    T query(int l, int r) { return\
    \ sum(r) - sum(l); }\n    int lower_bound(T x) const {\n        if (x <= 0) return\
    \ 0;\n        int pos = 0, k = 1;\n        while (k < n) k <<= 1;\n        for\
    \ (; k > 0; k >>= 1) {\n            if (pos + k <= n && dat[pos + k] < x) {\n\
    \                x -= dat[pos + k];\n                pos += k;\n            }\n\
    \        }\n        return pos;\n    }\n    int upper_bound(T x) const { return\
    \ lower_bound(x + 1); }\n    T operator[](int i) { return query(i, i + 1); }\n\
    };"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/BinaryIndexedTree.hpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static_range_inversions_query.test.cpp
  - test/yosupo/vertex_add_subtree_sum.test.cpp
  - test/aoj/DSL_2_B.test.cpp
  - test/aoj/GRL_5_D.test.cpp
  - test/yukicoder/1270.test.cpp
documentation_of: datastructure/BinaryIndexedTree.hpp
layout: document
redirect_from:
- /library/datastructure/BinaryIndexedTree.hpp
- /library/datastructure/BinaryIndexedTree.hpp.html
title: Binary Indexed Tree
---
## 概要

## 計算量