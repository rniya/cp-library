---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2885.test.cpp
    title: test/aoj/2885.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/BipartiteGraph.md
    document_title: "2\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"graph/BipartiteGraph.hpp\"\
    \n\n/**\n * @brief 2\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A\n * @docs docs/graph/BipartiteGraph.md\n\
    \ */\nstruct BipartiteGraph {\n    vector<vector<int>> G;\n    vector<int> color,\
    \ root;\n    BipartiteGraph(int n) : G(n), color(n, -1), root(n, -1) {}\n    void\
    \ add_edge(int u, int v) {\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n    bool dfs(int v, int c, int r) {\n        color[v] = c;\n        root[v]\
    \ = r;\n        for (int u : G[v]) {\n            if (color[u] == c) return false;\n\
    \            if (color[u] < 0 && !dfs(u, c ^ 1, r)) return false;\n        }\n\
    \        return true;\n    }\n    bool build() {\n        for (int v = 0; v <\
    \ (int)G.size(); v++) {\n            if (color[v] < 0 && !dfs(v, 0, v)) {\n  \
    \              return false;\n            }\n        }\n        return true;\n\
    \    }\n    int operator[](int v) { return color[v]; }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief 2\u90E8\u30B0\u30E9\
    \u30D5\u5224\u5B9A\n * @docs docs/graph/BipartiteGraph.md\n */\nstruct BipartiteGraph\
    \ {\n    vector<vector<int>> G;\n    vector<int> color, root;\n    BipartiteGraph(int\
    \ n) : G(n), color(n, -1), root(n, -1) {}\n    void add_edge(int u, int v) {\n\
    \        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n    bool\
    \ dfs(int v, int c, int r) {\n        color[v] = c;\n        root[v] = r;\n  \
    \      for (int u : G[v]) {\n            if (color[u] == c) return false;\n  \
    \          if (color[u] < 0 && !dfs(u, c ^ 1, r)) return false;\n        }\n \
    \       return true;\n    }\n    bool build() {\n        for (int v = 0; v < (int)G.size();\
    \ v++) {\n            if (color[v] < 0 && !dfs(v, 0, v)) {\n                return\
    \ false;\n            }\n        }\n        return true;\n    }\n    int operator[](int\
    \ v) { return color[v]; }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/BipartiteGraph.hpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2885.test.cpp
documentation_of: graph/BipartiteGraph.hpp
layout: document
redirect_from:
- /library/graph/BipartiteGraph.hpp
- /library/graph/BipartiteGraph.hpp.html
title: "2\u90E8\u30B0\u30E9\u30D5\u5224\u5B9A"
---
## 概要

## 計算量