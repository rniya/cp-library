---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_B.test.cpp
    title: test/aoj/GRL_6_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/MinCostFlow.md
    document_title: "\u6700\u5C0F\u8CBB\u7528\u6D41"
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"flow/MinCostFlow.hpp\"\
    \n\n/**\n * @brief \u6700\u5C0F\u8CBB\u7528\u6D41\n * @docs docs/flow/MinCostFlow.md\n\
    \ */\ntemplate <typename Cap, typename Cost> struct MinCostFlow {\n    const Cost\
    \ inf = numeric_limits<Cost>::max() / 2;\n    struct edge {\n        int to;\n\
    \        Cap cap;\n        Cost cost;\n        int rev;\n        edge(int to,\
    \ Cap cap, Cost cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}\n \
    \   };\n    vector<vector<edge>> G;\n    vector<pair<int, int>> pos;\n    vector<Cost>\
    \ dist;\n    vector<int> prevv, preve;\n    MinCostFlow(int n) : G(n), dist(n),\
    \ prevv(n), preve(n) {}\n    int add_edge(int from, int to, Cap cap, Cost cost)\
    \ {\n        pos.emplace_back(from, G[from].size());\n        G[from].emplace_back(to,\
    \ cap, cost, G[to].size());\n        G[to].emplace_back(from, 0, -cost, G[from].size()\
    \ - 1);\n        return pos.size() - 1;\n    }\n    tuple<int, int, Cap, Cap,\
    \ Cost> get_edge(int i) {\n        auto e = G[pos[i].first][pos[i].second];\n\
    \        auto re = G[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap\
    \ + re.cap, re.cap, e.cost};\n    }\n    vector<tuple<int, int, Cap, Cap, Cost>>\
    \ edges() {\n        vector<tuple<int, int, Cap, Cap, Cost>> res;\n        for\
    \ (size_t i = 0; i < pos.size(); i++) res.emplace_back(get_edge(i));\n       \
    \ return res;\n    }\n    Cost min_cost_flow(int s, int t, Cap f) {\n        Cost\
    \ res = 0;\n        while (f > 0) {\n            fill(dist.begin(), dist.end(),\
    \ inf);\n            dist[s] = 0;\n            bool update = true;\n         \
    \   while (update) {\n                update = false;\n                for (size_t\
    \ v = 0; v < G.size(); v++) {\n                    if (dist[v] == inf) continue;\n\
    \                    for (size_t i = 0; i < G[v].size(); i++) {\n            \
    \            edge& e = G[v][i];\n                        if (e.cap > 0 && dist[e.to]\
    \ > dist[v] + e.cost) {\n                            dist[e.to] = dist[v] + e.cost;\n\
    \                            prevv[e.to] = v;\n                            preve[e.to]\
    \ = i;\n                            update = true;\n                        }\n\
    \                    }\n                }\n            }\n            if (dist[t]\
    \ == inf) return -1;\n            Cap d = f;\n            for (int v = t; v !=\
    \ s; v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);\n            f -= d;\n\
    \            res += dist[t] * d;\n            for (int v = t; v != s; v = prevv[v])\
    \ {\n                edge& e = G[prevv[v]][preve[v]];\n                e.cap -=\
    \ d;\n                G[v][e.rev].cap += d;\n            }\n        }\n      \
    \  return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief \u6700\u5C0F\u8CBB\
    \u7528\u6D41\n * @docs docs/flow/MinCostFlow.md\n */\ntemplate <typename Cap,\
    \ typename Cost> struct MinCostFlow {\n    const Cost inf = numeric_limits<Cost>::max()\
    \ / 2;\n    struct edge {\n        int to;\n        Cap cap;\n        Cost cost;\n\
    \        int rev;\n        edge(int to, Cap cap, Cost cost, int rev) : to(to),\
    \ cap(cap), cost(cost), rev(rev) {}\n    };\n    vector<vector<edge>> G;\n   \
    \ vector<pair<int, int>> pos;\n    vector<Cost> dist;\n    vector<int> prevv,\
    \ preve;\n    MinCostFlow(int n) : G(n), dist(n), prevv(n), preve(n) {}\n    int\
    \ add_edge(int from, int to, Cap cap, Cost cost) {\n        pos.emplace_back(from,\
    \ G[from].size());\n        G[from].emplace_back(to, cap, cost, G[to].size());\n\
    \        G[to].emplace_back(from, 0, -cost, G[from].size() - 1);\n        return\
    \ pos.size() - 1;\n    }\n    tuple<int, int, Cap, Cap, Cost> get_edge(int i)\
    \ {\n        auto e = G[pos[i].first][pos[i].second];\n        auto re = G[e.to][e.rev];\n\
    \        return {pos[i].first, e.to, e.cap + re.cap, re.cap, e.cost};\n    }\n\
    \    vector<tuple<int, int, Cap, Cap, Cost>> edges() {\n        vector<tuple<int,\
    \ int, Cap, Cap, Cost>> res;\n        for (size_t i = 0; i < pos.size(); i++)\
    \ res.emplace_back(get_edge(i));\n        return res;\n    }\n    Cost min_cost_flow(int\
    \ s, int t, Cap f) {\n        Cost res = 0;\n        while (f > 0) {\n       \
    \     fill(dist.begin(), dist.end(), inf);\n            dist[s] = 0;\n       \
    \     bool update = true;\n            while (update) {\n                update\
    \ = false;\n                for (size_t v = 0; v < G.size(); v++) {\n        \
    \            if (dist[v] == inf) continue;\n                    for (size_t i\
    \ = 0; i < G[v].size(); i++) {\n                        edge& e = G[v][i];\n \
    \                       if (e.cap > 0 && dist[e.to] > dist[v] + e.cost) {\n  \
    \                          dist[e.to] = dist[v] + e.cost;\n                  \
    \          prevv[e.to] = v;\n                            preve[e.to] = i;\n  \
    \                          update = true;\n                        }\n       \
    \             }\n                }\n            }\n            if (dist[t] ==\
    \ inf) return -1;\n            Cap d = f;\n            for (int v = t; v != s;\
    \ v = prevv[v]) d = min(d, G[prevv[v]][preve[v]].cap);\n            f -= d;\n\
    \            res += dist[t] * d;\n            for (int v = t; v != s; v = prevv[v])\
    \ {\n                edge& e = G[prevv[v]][preve[v]];\n                e.cap -=\
    \ d;\n                G[v][e.rev].cap += d;\n            }\n        }\n      \
    \  return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: flow/MinCostFlow.hpp
  requiredBy: []
  timestamp: '2021-09-11 01:27:48+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_B.test.cpp
documentation_of: flow/MinCostFlow.hpp
layout: document
redirect_from:
- /library/flow/MinCostFlow.hpp
- /library/flow/MinCostFlow.hpp.html
title: "\u6700\u5C0F\u8CBB\u7528\u6D41"
---
## 概要
最小費用流を計算するが, 基本的には[Primal Dual](https://rniya.github.io/competitive-programming-library/flow/PrimalDual.hpp)の方が高速なのでそちらを使うほうが良い.

## 計算量
$O(fEV)$