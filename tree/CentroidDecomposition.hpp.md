---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/frequency_table_of_tree_distance.test.cpp
    title: test/yosupo/frequency_table_of_tree_distance.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/tree/CentroidDecomposition.md
    document_title: Centroid Decomposition
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    const long long MOD = 1000000007;\n// const long long MOD=998244353;\nconst int\
    \ INF = 1e9;\nconst long long IINF = 1e18;\nconst int dx[4] = {1, 0, -1, 0}, dy[4]\
    \ = {0, 1, 0, -1};\nconst char dir[4] = {'D', 'R', 'U', 'L'};\n#define LOCAL\n\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"tree/CentroidDecomposition.hpp\"\
    \n\n/**\n * @brief Centroid Decomposition\n * @docs docs/tree/CentroidDecomposition.md\n\
    \ */\nclass CentroidDecomposition {\n    vector<vector<int>> G;\n    vector<int>\
    \ sub, centroid;\n    inline int dfs(int v, int p) {\n        sub[v] = 1;\n  \
    \      for (int u : G[v]) {\n            if (u == p || centroid[u]) continue;\n\
    \            sub[v] += dfs(u, v);\n        }\n        return sub[v];\n    }\n\
    \    inline int find(int v, int p, int mid) {\n        for (int u : G[v]) {\n\
    \            if (u == p || centroid[u]) continue;\n            if (sub[u] > mid)\
    \ return find(u, v, mid);\n        }\n        return v;\n    }\n\npublic:\n  \
    \  CentroidDecomposition(int n) : G(n), sub(n), centroid(n) {}\n    void add_edge(int\
    \ u, int v) {\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n    int build(int r) { return find(r, -1, dfs(r, -1) >> 1); }\n    void\
    \ disable(int v) { centroid[v] = true; }\n    void enable(int v) { centroid[v]\
    \ = false; }\n    int alive(int v) { return !centroid[v]; }\n    const vector<int>&\
    \ operator[](int v) const { return G[v]; }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Centroid Decomposition\n\
    \ * @docs docs/tree/CentroidDecomposition.md\n */\nclass CentroidDecomposition\
    \ {\n    vector<vector<int>> G;\n    vector<int> sub, centroid;\n    inline int\
    \ dfs(int v, int p) {\n        sub[v] = 1;\n        for (int u : G[v]) {\n   \
    \         if (u == p || centroid[u]) continue;\n            sub[v] += dfs(u, v);\n\
    \        }\n        return sub[v];\n    }\n    inline int find(int v, int p, int\
    \ mid) {\n        for (int u : G[v]) {\n            if (u == p || centroid[u])\
    \ continue;\n            if (sub[u] > mid) return find(u, v, mid);\n        }\n\
    \        return v;\n    }\n\npublic:\n    CentroidDecomposition(int n) : G(n),\
    \ sub(n), centroid(n) {}\n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n\
    \        G[v].emplace_back(u);\n    }\n    int build(int r) { return find(r, -1,\
    \ dfs(r, -1) >> 1); }\n    void disable(int v) { centroid[v] = true; }\n    void\
    \ enable(int v) { centroid[v] = false; }\n    int alive(int v) { return !centroid[v];\
    \ }\n    const vector<int>& operator[](int v) const { return G[v]; }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: tree/CentroidDecomposition.hpp
  requiredBy: []
  timestamp: '2021-01-19 15:22:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/frequency_table_of_tree_distance.test.cpp
documentation_of: tree/CentroidDecomposition.hpp
layout: document
redirect_from:
- /library/tree/CentroidDecomposition.hpp
- /library/tree/CentroidDecomposition.hpp.html
title: Centroid Decomposition
---
## 概要

## 計算量