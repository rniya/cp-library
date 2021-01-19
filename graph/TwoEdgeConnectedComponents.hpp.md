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
    path: test/yosupo/two_edge_connected_components.test.cpp
    title: test/yosupo/two_edge_connected_components.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/StronglyConnectedComponents.md
    document_title: Two Edge Connected Components
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"graph/TwoEdgeConnectedComponents.hpp\"\
    \n\n/**\n * @brief Two Edge Connected Components\n * @docs docs/graph/StronglyConnectedComponents.md\n\
    \ */\nstruct TwoEdgeConnectedComponents {\n    int time, k;\n    vector<int> ord,\
    \ low, cmp;\n    vector<vector<int>> G, C, T;\n    vector<pair<int, int>> bridge;\n\
    \    TwoEdgeConnectedComponents(int n) : time(0), k(0), ord(n, -1), low(n), cmp(n,\
    \ -1), G(n) {}\n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n\
    \        G[v].emplace_back(u);\n    }\n    bool is_bridge(int u, int v) {\n  \
    \      if (ord[u] > ord[v]) swap(u, v);\n        return ord[u] < low[v];\n   \
    \ }\n    void dfs(int v, int p) {\n        ord[v] = low[v] = time++;\n       \
    \ int bic = 0;\n        for (int u : G[v]) {\n            if (u == p && !bic)\
    \ {\n                bic = 1;\n                continue;\n            }\n    \
    \        if (~ord[u]) {\n                low[v] = min(low[v], ord[u]);\n     \
    \           continue;\n            }\n            dfs(u, v);\n            low[v]\
    \ = min(low[v], low[u]);\n            if (is_bridge(v, u)) bridge.emplace_back(v,\
    \ u);\n        }\n    }\n    void fill_component(int v) {\n        C[cmp[v]].emplace_back(v);\n\
    \        for (int u : G[v]) {\n            if (~cmp[u] || is_bridge(u, v)) continue;\n\
    \            cmp[u] = cmp[v];\n            fill_component(u);\n        }\n   \
    \ }\n    void add_component(int v) {\n        if (~cmp[v]) return;\n        cmp[v]\
    \ = k++;\n        C.emplace_back();\n        fill_component(v);\n    }\n    int\
    \ build() {\n        int n = G.size();\n        for (int v = 0; v < n; v++) {\n\
    \            if (ord[v] < 0) dfs(v, -1);\n        }\n        for (int v = 0; v\
    \ < n; v++) add_component(v);\n        T.resize(k);\n        for (auto e : bridge)\
    \ {\n            int u = cmp[e.first], v = cmp[e.second];\n            T[u].emplace_back(v);\n\
    \            T[v].emplace_back(u);\n        }\n        return k;\n    }\n    int\
    \ operator[](int i) const { return cmp[i]; }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Two Edge Connected\
    \ Components\n * @docs docs/graph/StronglyConnectedComponents.md\n */\nstruct\
    \ TwoEdgeConnectedComponents {\n    int time, k;\n    vector<int> ord, low, cmp;\n\
    \    vector<vector<int>> G, C, T;\n    vector<pair<int, int>> bridge;\n    TwoEdgeConnectedComponents(int\
    \ n) : time(0), k(0), ord(n, -1), low(n), cmp(n, -1), G(n) {}\n    void add_edge(int\
    \ u, int v) {\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n    bool is_bridge(int u, int v) {\n        if (ord[u] > ord[v]) swap(u,\
    \ v);\n        return ord[u] < low[v];\n    }\n    void dfs(int v, int p) {\n\
    \        ord[v] = low[v] = time++;\n        int bic = 0;\n        for (int u :\
    \ G[v]) {\n            if (u == p && !bic) {\n                bic = 1;\n     \
    \           continue;\n            }\n            if (~ord[u]) {\n           \
    \     low[v] = min(low[v], ord[u]);\n                continue;\n            }\n\
    \            dfs(u, v);\n            low[v] = min(low[v], low[u]);\n         \
    \   if (is_bridge(v, u)) bridge.emplace_back(v, u);\n        }\n    }\n    void\
    \ fill_component(int v) {\n        C[cmp[v]].emplace_back(v);\n        for (int\
    \ u : G[v]) {\n            if (~cmp[u] || is_bridge(u, v)) continue;\n       \
    \     cmp[u] = cmp[v];\n            fill_component(u);\n        }\n    }\n   \
    \ void add_component(int v) {\n        if (~cmp[v]) return;\n        cmp[v] =\
    \ k++;\n        C.emplace_back();\n        fill_component(v);\n    }\n    int\
    \ build() {\n        int n = G.size();\n        for (int v = 0; v < n; v++) {\n\
    \            if (ord[v] < 0) dfs(v, -1);\n        }\n        for (int v = 0; v\
    \ < n; v++) add_component(v);\n        T.resize(k);\n        for (auto e : bridge)\
    \ {\n            int u = cmp[e.first], v = cmp[e.second];\n            T[u].emplace_back(v);\n\
    \            T[v].emplace_back(u);\n        }\n        return k;\n    }\n    int\
    \ operator[](int i) const { return cmp[i]; }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/TwoEdgeConnectedComponents.hpp
  requiredBy:
  - test/atcoder/arc039_d.cpp
  timestamp: '2021-01-19 15:36:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_edge_connected_components.test.cpp
documentation_of: graph/TwoEdgeConnectedComponents.hpp
layout: document
redirect_from:
- /library/graph/TwoEdgeConnectedComponents.hpp
- /library/graph/TwoEdgeConnectedComponents.hpp.html
title: Two Edge Connected Components
---
## 概要

## 計算量