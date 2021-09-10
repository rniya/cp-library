---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_D.test.cpp
    title: test/aoj/GRL_5_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/tree/EulerTourforEdge.md
    document_title: "Euler Tour (\u30D1\u30B9\u306B\u5BFE\u3059\u308B\u64CD\u4F5C)"
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"tree/EulerTourforEdge.hpp\"\
    \n\n/**\n * @brief Euler Tour (\u30D1\u30B9\u306B\u5BFE\u3059\u308B\u64CD\u4F5C\
    )\n * @docs docs/tree/EulerTourforEdge.md\n */\nclass EulerTourforEdge {\n   \
    \ vector<int> ds, us, dep, btm;\n    void dfs(int v, int p, int d) {\n       \
    \ dep[v] = d;\n        for (int u : G[v]) {\n            if (u == p) continue;\n\
    \            ds[u] = btm.size();\n            btm.emplace_back(u);\n         \
    \   dfs(u, v, d + 1);\n            us[u] = btm.size();\n            btm.emplace_back(u);\n\
    \        }\n    }\n\npublic:\n    vector<vector<int>> G;\n    EulerTourforEdge(int\
    \ n) : ds(n), us(n), dep(n), G(n) {}\n    void add_edge(int u, int v) {\n    \
    \    G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n    void build(int\
    \ r = 0) {\n        btm.clear();\n        ds[r] = btm.size();\n        btm.emplace_back(r);\n\
    \        dfs(r, -1, 0);\n        us[r] = btm.size();\n        btm.emplace_back(r);\n\
    \    }\n    int child(int u, int v) { return dep[u] < dep[v] ? v : u; }\n    int\
    \ bottom(int e) { return btm[e]; }\n    template <typename T, typename F> T query(int\
    \ v, F f) { return f(0, us[v]); }\n    // u or v must be lca(u,v)\n    template\
    \ <typename T, typename F> T query(int u, int v, F f) {\n        if (dep[u] <\
    \ dep[v]) swap(u, v);\n        return query<T>(u, f) - query<T>(v, f);\n    }\n\
    \    // v is child of the edge\n    template <typename T, typename G> void update(int\
    \ v, T x, G g) {\n        g(ds[v], x);\n        g(us[v], -x);\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Euler Tour (\u30D1\
    \u30B9\u306B\u5BFE\u3059\u308B\u64CD\u4F5C)\n * @docs docs/tree/EulerTourforEdge.md\n\
    \ */\nclass EulerTourforEdge {\n    vector<int> ds, us, dep, btm;\n    void dfs(int\
    \ v, int p, int d) {\n        dep[v] = d;\n        for (int u : G[v]) {\n    \
    \        if (u == p) continue;\n            ds[u] = btm.size();\n            btm.emplace_back(u);\n\
    \            dfs(u, v, d + 1);\n            us[u] = btm.size();\n            btm.emplace_back(u);\n\
    \        }\n    }\n\npublic:\n    vector<vector<int>> G;\n    EulerTourforEdge(int\
    \ n) : ds(n), us(n), dep(n), G(n) {}\n    void add_edge(int u, int v) {\n    \
    \    G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n    void build(int\
    \ r = 0) {\n        btm.clear();\n        ds[r] = btm.size();\n        btm.emplace_back(r);\n\
    \        dfs(r, -1, 0);\n        us[r] = btm.size();\n        btm.emplace_back(r);\n\
    \    }\n    int child(int u, int v) { return dep[u] < dep[v] ? v : u; }\n    int\
    \ bottom(int e) { return btm[e]; }\n    template <typename T, typename F> T query(int\
    \ v, F f) { return f(0, us[v]); }\n    // u or v must be lca(u,v)\n    template\
    \ <typename T, typename F> T query(int u, int v, F f) {\n        if (dep[u] <\
    \ dep[v]) swap(u, v);\n        return query<T>(u, f) - query<T>(v, f);\n    }\n\
    \    // v is child of the edge\n    template <typename T, typename G> void update(int\
    \ v, T x, G g) {\n        g(ds[v], x);\n        g(us[v], -x);\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: tree/EulerTourforEdge.hpp
  requiredBy: []
  timestamp: '2021-07-19 14:45:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_5_D.test.cpp
documentation_of: tree/EulerTourforEdge.hpp
layout: document
redirect_from:
- /library/tree/EulerTourforEdge.hpp
- /library/tree/EulerTourforEdge.hpp.html
title: "Euler Tour (\u30D1\u30B9\u306B\u5BFE\u3059\u308B\u64CD\u4F5C)"
---
## 概要

## 計算量