---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: graph/TwoSatisfiability.hpp
    title: 2-SAT
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_C.test.cpp
    title: test/aoj/GRL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/scc.test.cpp
    title: test/yosupo/scc.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/StronglyConnectedComponents.md
    document_title: Strongly Connected Components
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"graph/StronglyConnectedComponents.hpp\"\
    \n\n/**\n * @brief Strongly Connected Components\n * @docs docs/graph/StronglyConnectedComponents.md\n\
    \ */\nstruct StronglyConnectedComponents {\n    vector<vector<int>> G, rG, C,\
    \ T;\n    vector<int> vs, cmp, used;\n    StronglyConnectedComponents(int n) :\
    \ G(n), rG(n), cmp(n), used(n) {}\n    void add_edge(int u, int v) {\n       \
    \ G[u].emplace_back(v);\n        rG[v].emplace_back(u);\n    }\n    void dfs(int\
    \ v) {\n        used[v] = 1;\n        for (int u : G[v])\n            if (!used[u])\
    \ dfs(u);\n        vs.emplace_back(v);\n    }\n    void rdfs(int v, int k) {\n\
    \        used[v] = 1;\n        cmp[v] = k;\n        C[k].emplace_back(v);\n  \
    \      for (int u : rG[v])\n            if (!used[u]) rdfs(u, k);\n    }\n   \
    \ int build() {\n        int n = G.size();\n        for (int i = 0; i < n; i++)\n\
    \            if (!used[i]) dfs(i);\n        fill(used.begin(), used.end(), 0);\n\
    \        int k = 0;\n        for (int i = n - 1; i >= 0; --i) {\n            if\
    \ (!used[vs[i]]) {\n                C.emplace_back(), T.emplace_back();\n    \
    \            rdfs(vs[i], k++);\n            }\n        }\n        for (int v =\
    \ 0; v < n; v++) {\n            for (int u : G[v]) {\n                if (cmp[v]\
    \ != cmp[u]) {\n                    T[cmp[v]].emplace_back(cmp[u]);\n        \
    \        }\n            }\n        }\n        for (int i = 0; i < k; i++) {\n\
    \            sort(T[i].begin(), T[i].end());\n            T[i].erase(unique(T[i].begin(),\
    \ T[i].end()), T[i].end());\n        }\n        return k;\n    }\n    int operator[](int\
    \ i) const { return cmp[i]; }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Strongly Connected\
    \ Components\n * @docs docs/graph/StronglyConnectedComponents.md\n */\nstruct\
    \ StronglyConnectedComponents {\n    vector<vector<int>> G, rG, C, T;\n    vector<int>\
    \ vs, cmp, used;\n    StronglyConnectedComponents(int n) : G(n), rG(n), cmp(n),\
    \ used(n) {}\n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n\
    \        rG[v].emplace_back(u);\n    }\n    void dfs(int v) {\n        used[v]\
    \ = 1;\n        for (int u : G[v])\n            if (!used[u]) dfs(u);\n      \
    \  vs.emplace_back(v);\n    }\n    void rdfs(int v, int k) {\n        used[v]\
    \ = 1;\n        cmp[v] = k;\n        C[k].emplace_back(v);\n        for (int u\
    \ : rG[v])\n            if (!used[u]) rdfs(u, k);\n    }\n    int build() {\n\
    \        int n = G.size();\n        for (int i = 0; i < n; i++)\n            if\
    \ (!used[i]) dfs(i);\n        fill(used.begin(), used.end(), 0);\n        int\
    \ k = 0;\n        for (int i = n - 1; i >= 0; --i) {\n            if (!used[vs[i]])\
    \ {\n                C.emplace_back(), T.emplace_back();\n                rdfs(vs[i],\
    \ k++);\n            }\n        }\n        for (int v = 0; v < n; v++) {\n   \
    \         for (int u : G[v]) {\n                if (cmp[v] != cmp[u]) {\n    \
    \                T[cmp[v]].emplace_back(cmp[u]);\n                }\n        \
    \    }\n        }\n        for (int i = 0; i < k; i++) {\n            sort(T[i].begin(),\
    \ T[i].end());\n            T[i].erase(unique(T[i].begin(), T[i].end()), T[i].end());\n\
    \        }\n        return k;\n    }\n    int operator[](int i) const { return\
    \ cmp[i]; }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/StronglyConnectedComponents.hpp
  requiredBy:
  - graph/TwoSatisfiability.hpp
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_sat.test.cpp
  - test/yosupo/scc.test.cpp
  - test/aoj/GRL_3_C.test.cpp
documentation_of: graph/StronglyConnectedComponents.hpp
layout: document
redirect_from:
- /library/graph/StronglyConnectedComponents.hpp
- /library/graph/StronglyConnectedComponents.hpp.html
title: Strongly Connected Components
---
## 概要

## 計算量