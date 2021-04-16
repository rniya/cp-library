---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/arc039_d.cpp
    title: test/atcoder/arc039_d.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/lca.test.cpp
    title: test/yosupo/lca.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/LowestCommonAncestor.md
    document_title: Lowest Common Ancestor
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"tree/LowestCommonAncestor.hpp\"\
    \n\n/**\n * @brief Lowest Common Ancestor\n * @docs docs/tree/LowestCommonAncestor.md\n\
    \ */\nstruct LowestCommonAncestor {\n    int n, h;\n    vector<vector<int>> G,\
    \ par;\n    vector<int> dep;\n    LowestCommonAncestor(int n) : n(n), G(n), dep(n)\
    \ {\n        h = 1;\n        while ((1 << h) <= n) h++;\n        par.assign(h,\
    \ vector<int>(n, -1));\n    }\n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n\
    \        G[v].emplace_back(u);\n    }\n    void dfs(int v, int p, int d) {\n \
    \       par[0][v] = p;\n        dep[v] = d;\n        for (int u : G[v]) {\n  \
    \          if (u != p) dfs(u, v, d + 1);\n        }\n    }\n    void build(int\
    \ r = 0) {\n        dfs(r, -1, 0);\n        for (int k = 0; k < h - 1; k++) {\n\
    \            for (int v = 0; v < n; v++) {\n                if (par[k][v] >= 0)\
    \ {\n                    par[k + 1][v] = par[k][par[k][v]];\n                }\n\
    \            }\n        }\n    }\n    int lca(int u, int v) {\n        if (dep[u]\
    \ > dep[v]) swap(u, v);\n        for (int k = 0; k < h; k++) {\n            if\
    \ ((dep[v] - dep[u]) & 1 << k) {\n                v = par[k][v];\n           \
    \ }\n        }\n        if (u == v) return u;\n        for (int k = h - 1; k >=\
    \ 0; --k) {\n            if (par[k][u] != par[k][v]) {\n                u = par[k][u];\n\
    \                v = par[k][v];\n            }\n        }\n        return par[0][u];\n\
    \    }\n    int distance(int u, int v) { return dep[u] + dep[v] - dep[lca(u, v)]\
    \ * 2; }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Lowest Common Ancestor\n\
    \ * @docs docs/tree/LowestCommonAncestor.md\n */\nstruct LowestCommonAncestor\
    \ {\n    int n, h;\n    vector<vector<int>> G, par;\n    vector<int> dep;\n  \
    \  LowestCommonAncestor(int n) : n(n), G(n), dep(n) {\n        h = 1;\n      \
    \  while ((1 << h) <= n) h++;\n        par.assign(h, vector<int>(n, -1));\n  \
    \  }\n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n     \
    \   G[v].emplace_back(u);\n    }\n    void dfs(int v, int p, int d) {\n      \
    \  par[0][v] = p;\n        dep[v] = d;\n        for (int u : G[v]) {\n       \
    \     if (u != p) dfs(u, v, d + 1);\n        }\n    }\n    void build(int r =\
    \ 0) {\n        dfs(r, -1, 0);\n        for (int k = 0; k < h - 1; k++) {\n  \
    \          for (int v = 0; v < n; v++) {\n                if (par[k][v] >= 0)\
    \ {\n                    par[k + 1][v] = par[k][par[k][v]];\n                }\n\
    \            }\n        }\n    }\n    int lca(int u, int v) {\n        if (dep[u]\
    \ > dep[v]) swap(u, v);\n        for (int k = 0; k < h; k++) {\n            if\
    \ ((dep[v] - dep[u]) & 1 << k) {\n                v = par[k][v];\n           \
    \ }\n        }\n        if (u == v) return u;\n        for (int k = h - 1; k >=\
    \ 0; --k) {\n            if (par[k][u] != par[k][v]) {\n                u = par[k][u];\n\
    \                v = par[k][v];\n            }\n        }\n        return par[0][u];\n\
    \    }\n    int distance(int u, int v) { return dep[u] + dep[v] - dep[lca(u, v)]\
    \ * 2; }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: tree/LowestCommonAncestor.hpp
  requiredBy:
  - test/atcoder/arc039_d.cpp
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/lca.test.cpp
  - test/aoj/GRL_5_C.test.cpp
documentation_of: tree/LowestCommonAncestor.hpp
layout: document
redirect_from:
- /library/tree/LowestCommonAncestor.hpp
- /library/tree/LowestCommonAncestor.hpp.html
title: Lowest Common Ancestor
---
## 概要

## 計算量