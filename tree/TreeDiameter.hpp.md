---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_A.test.cpp
    title: test/aoj/GRL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_B.test.cpp
    title: test/aoj/GRL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tree_diameter.test.cpp
    title: test/yosupo/tree_diameter.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/TreeDiameter.md
    document_title: Tree Diameter
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"tree/TreeDiameter.hpp\"\
    \n\n/**\n * @brief Tree Diameter\n * @docs docs/tree/TreeDiameter.md\n */\ntemplate\
    \ <typename T> struct TreeDiameter {\n    vector<T> dp, par;\n    vector<vector<pair<int,\
    \ T>>> G;\n    TreeDiameter(int n) : dp(n), par(n), G(n) {}\n    void add_edge(int\
    \ u, int v, T c) {\n        G[u].emplace_back(v, c);\n        G[v].emplace_back(u,\
    \ c);\n    }\n    void dfs(int v, int p, int& s) {\n        par[v] = p;\n    \
    \    if (p < 0) dp[v] = T(0);\n        if (dp[s] < dp[v]) s = v;\n        for\
    \ (auto e : G[v]) {\n            int u = e.first;\n            if (u == p) continue;\n\
    \            dp[u] = dp[v] + e.second;\n            dfs(u, v, s);\n        }\n\
    \    }\n    pair<int, int> endPoints() {\n        int s = 0;\n        dfs(s, -1,\
    \ s);\n        int t = s;\n        dfs(t, -1, t);\n        return make_pair(s,\
    \ t);\n    }\n    T build() {\n        int t = endPoints().second;\n        return\
    \ dp[t];\n    }\n    vector<int> restore() {\n        int t = endPoints().second;\n\
    \        vector<int> res;\n        while (~t) {\n            res.emplace_back(t);\n\
    \            t = par[t];\n        }\n        return res;\n    }\n    vector<T>\
    \ distance(int v) {\n        dfs(v, -1, v);\n        return dp;\n    }\n    vector<T>\
    \ farthest() {\n        int t = endPoints().second;\n        auto ds = dp;\n \
    \       auto dt = distance(t);\n        for (int i = 0; i < (int)ds.size(); i++)\
    \ ds[i] = max(ds[i], dt[i]);\n        return ds;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Tree Diameter\n\
    \ * @docs docs/tree/TreeDiameter.md\n */\ntemplate <typename T> struct TreeDiameter\
    \ {\n    vector<T> dp, par;\n    vector<vector<pair<int, T>>> G;\n    TreeDiameter(int\
    \ n) : dp(n), par(n), G(n) {}\n    void add_edge(int u, int v, T c) {\n      \
    \  G[u].emplace_back(v, c);\n        G[v].emplace_back(u, c);\n    }\n    void\
    \ dfs(int v, int p, int& s) {\n        par[v] = p;\n        if (p < 0) dp[v] =\
    \ T(0);\n        if (dp[s] < dp[v]) s = v;\n        for (auto e : G[v]) {\n  \
    \          int u = e.first;\n            if (u == p) continue;\n            dp[u]\
    \ = dp[v] + e.second;\n            dfs(u, v, s);\n        }\n    }\n    pair<int,\
    \ int> endPoints() {\n        int s = 0;\n        dfs(s, -1, s);\n        int\
    \ t = s;\n        dfs(t, -1, t);\n        return make_pair(s, t);\n    }\n   \
    \ T build() {\n        int t = endPoints().second;\n        return dp[t];\n  \
    \  }\n    vector<int> restore() {\n        int t = endPoints().second;\n     \
    \   vector<int> res;\n        while (~t) {\n            res.emplace_back(t);\n\
    \            t = par[t];\n        }\n        return res;\n    }\n    vector<T>\
    \ distance(int v) {\n        dfs(v, -1, v);\n        return dp;\n    }\n    vector<T>\
    \ farthest() {\n        int t = endPoints().second;\n        auto ds = dp;\n \
    \       auto dt = distance(t);\n        for (int i = 0; i < (int)ds.size(); i++)\
    \ ds[i] = max(ds[i], dt[i]);\n        return ds;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: tree/TreeDiameter.hpp
  requiredBy: []
  timestamp: '2021-07-19 14:45:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/tree_diameter.test.cpp
  - test/aoj/GRL_5_B.test.cpp
  - test/aoj/GRL_5_A.test.cpp
documentation_of: tree/TreeDiameter.hpp
layout: document
redirect_from:
- /library/tree/TreeDiameter.hpp
- /library/tree/TreeDiameter.hpp.html
title: Tree Diameter
---
## 概要

## 計算量