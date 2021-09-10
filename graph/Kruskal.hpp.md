---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_2_A.test.cpp
    title: test/aoj/GRL_2_A.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/Kruskal.md
    document_title: Kruskal
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"graph/Kruskal.hpp\"\
    \n\n/**\n * @brief Kruskal\n * @docs docs/graph/Kruskal.md\n */\ntemplate <typename\
    \ T> struct Kruskal {\nprivate:\n    struct edge {\n        int from, to, used,\
    \ id;\n        T cost;\n        edge(int from, int to, T cost, int id) : from(from),\
    \ to(to), cost(cost), id(id), used(0) {}\n        bool operator<(const edge& e)\
    \ const {\n            if (cost != e.cost)\n                return cost < e.cost;\n\
    \            else if (from != e.from)\n                return from < e.from;\n\
    \            else\n                return to < e.to;\n        }\n    };\n    vector<edge>\
    \ es;\n    vector<int> par, rank;\n    int root(int x) {\n        if (par[x] ==\
    \ x) return x;\n        return par[x] = root(par[x]);\n    }\n    bool merge(int\
    \ x, int y) {\n        x = root(x), y = root(y);\n        if (x == y) return false;\n\
    \        if (rank[x] < rank[y]) swap(x, y);\n        par[y] = x;\n        rank[x]\
    \ += rank[y];\n        return true;\n    }\n    bool same(int x, int y) { return\
    \ root(x) == root(y); }\n    int size(int x) { return rank[root(x)]; }\n\npublic:\n\
    \    Kruskal(int n) : par(n), rank(n, 1) { iota(par.begin(), par.end(), 0); }\n\
    \    void add_edge(int u, int v, T c, int id = 0) { es.emplace_back(u, v, c, id);\
    \ }\n    T build() {\n        sort(es.begin(), es.end());\n        T res = 0;\n\
    \        for (auto& e : es) {\n            if (!same(e.from, e.to)) {\n      \
    \          res += e.cost;\n                e.used = 1;\n                merge(e.from,\
    \ e.to);\n            }\n        }\n        return res;\n    }\n    vector<int>\
    \ restore(T& c) {\n        int m = es.size();\n        vector<int> res(m);\n \
    \       for (int i = 0; i < m; i++) res[es[i].id] = es[i].used;\n        return\
    \ res;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Kruskal\n * @docs\
    \ docs/graph/Kruskal.md\n */\ntemplate <typename T> struct Kruskal {\nprivate:\n\
    \    struct edge {\n        int from, to, used, id;\n        T cost;\n       \
    \ edge(int from, int to, T cost, int id) : from(from), to(to), cost(cost), id(id),\
    \ used(0) {}\n        bool operator<(const edge& e) const {\n            if (cost\
    \ != e.cost)\n                return cost < e.cost;\n            else if (from\
    \ != e.from)\n                return from < e.from;\n            else\n      \
    \          return to < e.to;\n        }\n    };\n    vector<edge> es;\n    vector<int>\
    \ par, rank;\n    int root(int x) {\n        if (par[x] == x) return x;\n    \
    \    return par[x] = root(par[x]);\n    }\n    bool merge(int x, int y) {\n  \
    \      x = root(x), y = root(y);\n        if (x == y) return false;\n        if\
    \ (rank[x] < rank[y]) swap(x, y);\n        par[y] = x;\n        rank[x] += rank[y];\n\
    \        return true;\n    }\n    bool same(int x, int y) { return root(x) ==\
    \ root(y); }\n    int size(int x) { return rank[root(x)]; }\n\npublic:\n    Kruskal(int\
    \ n) : par(n), rank(n, 1) { iota(par.begin(), par.end(), 0); }\n    void add_edge(int\
    \ u, int v, T c, int id = 0) { es.emplace_back(u, v, c, id); }\n    T build()\
    \ {\n        sort(es.begin(), es.end());\n        T res = 0;\n        for (auto&\
    \ e : es) {\n            if (!same(e.from, e.to)) {\n                res += e.cost;\n\
    \                e.used = 1;\n                merge(e.from, e.to);\n         \
    \   }\n        }\n        return res;\n    }\n    vector<int> restore(T& c) {\n\
    \        int m = es.size();\n        vector<int> res(m);\n        for (int i =\
    \ 0; i < m; i++) res[es[i].id] = es[i].used;\n        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/Kruskal.hpp
  requiredBy: []
  timestamp: '2021-07-19 14:45:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_2_A.test.cpp
documentation_of: graph/Kruskal.hpp
layout: document
redirect_from:
- /library/graph/Kruskal.hpp
- /library/graph/Kruskal.hpp.html
title: Kruskal
---
## 概要

## 計算量