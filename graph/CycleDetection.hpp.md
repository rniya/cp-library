---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2891.test.cpp
    title: test/aoj/2891.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_4_A.test.cpp
    title: test/aoj/GRL_4_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/CycleDetection.md
    document_title: Cycle Detection
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"graph/CycleDetection.hpp\"\
    \n\n/**\n * @brief Cycle Detection\n * @docs docs/graph/CycleDetection.md\n */\n\
    template <bool directed> struct CycleDetection {\n    vector<vector<int>> G;\n\
    \    vector<int> seen, finished;\n    stack<int> hist;\n    int pos;\n    CycleDetection(int\
    \ n) : G(n), seen(n, 0), finished(n, 0), pos(-1) {}\n    void add_edge(int u,\
    \ int v) { G[u].emplace_back(v); }\n    void dfs(int v, int p) {\n        seen[v]\
    \ = 1;\n        hist.emplace(v);\n        for (int u : G[v]) {\n            if\
    \ (!directed && u == p) continue;\n            if (finished[u]) continue;\n  \
    \          if (seen[u] && !finished[u]) {\n                pos = u;\n        \
    \        return;\n            }\n            dfs(u, v);\n            if (~pos)\
    \ return;\n        }\n        finished[v] = 1;\n        hist.pop();\n    }\n \
    \   vector<int> build() {\n        for (int v = 0; v < (int)G.size(); v++) {\n\
    \            if (!seen[v]) dfs(v, -1);\n            if (~pos) break;\n       \
    \ }\n        vector<int> res;\n        while (!hist.empty()) {\n            int\
    \ t = hist.top();\n            hist.pop();\n            res.emplace_back(t);\n\
    \            if (t == pos) break;\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Cycle Detection\n\
    \ * @docs docs/graph/CycleDetection.md\n */\ntemplate <bool directed> struct CycleDetection\
    \ {\n    vector<vector<int>> G;\n    vector<int> seen, finished;\n    stack<int>\
    \ hist;\n    int pos;\n    CycleDetection(int n) : G(n), seen(n, 0), finished(n,\
    \ 0), pos(-1) {}\n    void add_edge(int u, int v) { G[u].emplace_back(v); }\n\
    \    void dfs(int v, int p) {\n        seen[v] = 1;\n        hist.emplace(v);\n\
    \        for (int u : G[v]) {\n            if (!directed && u == p) continue;\n\
    \            if (finished[u]) continue;\n            if (seen[u] && !finished[u])\
    \ {\n                pos = u;\n                return;\n            }\n      \
    \      dfs(u, v);\n            if (~pos) return;\n        }\n        finished[v]\
    \ = 1;\n        hist.pop();\n    }\n    vector<int> build() {\n        for (int\
    \ v = 0; v < (int)G.size(); v++) {\n            if (!seen[v]) dfs(v, -1);\n  \
    \          if (~pos) break;\n        }\n        vector<int> res;\n        while\
    \ (!hist.empty()) {\n            int t = hist.top();\n            hist.pop();\n\
    \            res.emplace_back(t);\n            if (t == pos) break;\n        }\n\
    \        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/CycleDetection.hpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_4_A.test.cpp
  - test/aoj/2891.test.cpp
documentation_of: graph/CycleDetection.hpp
layout: document
redirect_from:
- /library/graph/CycleDetection.hpp
- /library/graph/CycleDetection.hpp.html
title: Cycle Detection
---
## 概要

## 計算量