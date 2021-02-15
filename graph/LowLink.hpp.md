---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_A.test.cpp
    title: test/aoj/GRL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_3_B.test.cpp
    title: test/aoj/GRL_3_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/LowLink.md
    document_title: "Low Link (\u6A4B/\u95A2\u7BC0\u70B9)"
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"graph/LowLink.hpp\"\n\n\
    /**\n * @brief Low Link (\u6A4B/\u95A2\u7BC0\u70B9)\n * @docs docs/graph/LowLink.md\n\
    \ */\nstruct LowLink {\n    int n, time;\n    vector<int> ord, low;\n    vector<vector<int>>\
    \ G;\n    vector<int> articulation;\n    vector<pair<int, int>> bridge;\n    LowLink(int\
    \ n) : n(n), time(0), ord(n, -1), low(n), G(n) {}\n    void add_edge(int u, int\
    \ v) {\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n\
    \    bool is_bridge(int u, int v) {\n        if (ord[u] > ord[v]) swap(u, v);\n\
    \        return ord[u] < low[v];\n    }\n    void dfs(int v, int p) {\n      \
    \  ord[v] = low[v] = time++;\n        bool is_articulation = false;\n        int\
    \ cnt = 0;\n        for (int u : G[v]) {\n            if (u == p) continue;\n\
    \            if (~ord[u]) {\n                low[v] = min(low[v], ord[u]);\n \
    \               continue;\n            }\n            cnt++;\n            dfs(u,\
    \ v);\n            low[v] = min(low[v], low[u]);\n            is_articulation\
    \ |= (~p && ord[v] <= low[u]);\n            if (is_bridge(v, u)) bridge.emplace_back(v,\
    \ u);\n        }\n        is_articulation |= (p < 0 && cnt > 1);\n        if (is_articulation)\
    \ articulation.emplace_back(v);\n    }\n    void build() {\n        for (int v\
    \ = 0; v < n; v++) {\n            if (ord[v] < 0) dfs(v, -1);\n        }\n   \
    \ }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Low Link (\u6A4B\
    /\u95A2\u7BC0\u70B9)\n * @docs docs/graph/LowLink.md\n */\nstruct LowLink {\n\
    \    int n, time;\n    vector<int> ord, low;\n    vector<vector<int>> G;\n   \
    \ vector<int> articulation;\n    vector<pair<int, int>> bridge;\n    LowLink(int\
    \ n) : n(n), time(0), ord(n, -1), low(n), G(n) {}\n    void add_edge(int u, int\
    \ v) {\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n\
    \    bool is_bridge(int u, int v) {\n        if (ord[u] > ord[v]) swap(u, v);\n\
    \        return ord[u] < low[v];\n    }\n    void dfs(int v, int p) {\n      \
    \  ord[v] = low[v] = time++;\n        bool is_articulation = false;\n        int\
    \ cnt = 0;\n        for (int u : G[v]) {\n            if (u == p) continue;\n\
    \            if (~ord[u]) {\n                low[v] = min(low[v], ord[u]);\n \
    \               continue;\n            }\n            cnt++;\n            dfs(u,\
    \ v);\n            low[v] = min(low[v], low[u]);\n            is_articulation\
    \ |= (~p && ord[v] <= low[u]);\n            if (is_bridge(v, u)) bridge.emplace_back(v,\
    \ u);\n        }\n        is_articulation |= (p < 0 && cnt > 1);\n        if (is_articulation)\
    \ articulation.emplace_back(v);\n    }\n    void build() {\n        for (int v\
    \ = 0; v < n; v++) {\n            if (ord[v] < 0) dfs(v, -1);\n        }\n   \
    \ }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/LowLink.hpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_3_A.test.cpp
  - test/aoj/GRL_3_B.test.cpp
documentation_of: graph/LowLink.hpp
layout: document
redirect_from:
- /library/graph/LowLink.hpp
- /library/graph/LowLink.hpp.html
title: "Low Link (\u6A4B/\u95A2\u7BC0\u70B9)"
---
## 概要

## 計算量