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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"graph/CycleDetection.hpp\"\
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
  timestamp: '2021-07-19 14:45:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2891.test.cpp
  - test/aoj/GRL_4_A.test.cpp
documentation_of: graph/CycleDetection.hpp
layout: document
redirect_from:
- /library/graph/CycleDetection.hpp
- /library/graph/CycleDetection.hpp.html
title: Cycle Detection
---
## 概要

## 計算量