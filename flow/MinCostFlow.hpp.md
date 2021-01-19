---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_B.test.cpp
    title: test/aoj/GRL_6_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/MinCostFlow.md
    document_title: "\u6700\u5C0F\u8CBB\u7528\u6D41"
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"flow/MinCostFlow.hpp\"\n\
    \n/**\n * @brief \u6700\u5C0F\u8CBB\u7528\u6D41\n * @docs docs/flow/MinCostFlow.md\n\
    \ */\ntemplate <typename T, typename E> struct MinCostFlow {\n    const E inf\
    \ = numeric_limits<E>::max();\n    struct edge {\n        int to, rev;\n     \
    \   T cap;\n        E cost;\n        edge(int to, T cap, E cost, int rev) : to(to),\
    \ cap(cap), cost(cost), rev(rev) {}\n    };\n    vector<vector<edge>> G;\n   \
    \ vector<pair<int, int>> pos;\n    vector<E> dist;\n    vector<int> prevv, preve;\n\
    \    MinCostFlow(int n) : G(n), dist(n), prevv(n), preve(n) {}\n    int add_edge(int\
    \ from, int to, T cap, E cost) {\n        pos.emplace_back(from, G[from].size());\n\
    \        G[from].emplace_back(to, cap, cost, G[to].size());\n        G[to].emplace_back(from,\
    \ 0, -cost, G[from].size() - 1);\n        return pos.size() - 1;\n    }\n    tuple<int,\
    \ int, int, int, int> get_edge(int i) {\n        auto e = G[pos[i].first][pos[i].second];\n\
    \        auto re = G[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap\
    \ + re.cap, re.cap, e.cost};\n    }\n    vector<tuple<int, int, int, int, int>>\
    \ edges() {\n        vector<tuple<int, int, int, int, int>> res;\n        for\
    \ (int i = 0; i < pos.size(); i++) {\n            res.emplace_back(get_edge(i));\n\
    \        }\n        return res;\n    }\n    E min_cost_flow(int s, int t, T f)\
    \ {\n        E res = 0;\n        while (f > 0) {\n            fill(dist.begin(),\
    \ dist.end(), inf);\n            dist[s] = 0;\n            bool update = true;\n\
    \            while (update) {\n                update = false;\n             \
    \   for (int v = 0; v < G.size(); v++) {\n                    if (dist[v] == inf)\
    \ continue;\n                    for (int i = 0; i < G[v].size(); i++) {\n   \
    \                     edge& e = G[v][i];\n                        if (e.cap >\
    \ 0 && dist[e.to] > dist[v] + e.cost) {\n                            dist[e.to]\
    \ = dist[v] + e.cost;\n                            prevv[e.to] = v;\n        \
    \                    preve[e.to] = i;\n                            update = true;\n\
    \                        }\n                    }\n                }\n       \
    \     }\n            if (dist[t] == inf) return -1;\n            T d = f;\n  \
    \          for (int v = t; v != s; v = prevv[v]) {\n                d = min(d,\
    \ G[prevv[v]][preve[v]].cap);\n            }\n            f -= d;\n          \
    \  res += dist[t] * d;\n            for (int v = t; v != s; v = prevv[v]) {\n\
    \                edge& e = G[prevv[v]][preve[v]];\n                e.cap -= d;\n\
    \                G[v][e.rev].cap += d;\n            }\n        }\n        return\
    \ res;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief \u6700\u5C0F\u8CBB\
    \u7528\u6D41\n * @docs docs/flow/MinCostFlow.md\n */\ntemplate <typename T, typename\
    \ E> struct MinCostFlow {\n    const E inf = numeric_limits<E>::max();\n    struct\
    \ edge {\n        int to, rev;\n        T cap;\n        E cost;\n        edge(int\
    \ to, T cap, E cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}\n  \
    \  };\n    vector<vector<edge>> G;\n    vector<pair<int, int>> pos;\n    vector<E>\
    \ dist;\n    vector<int> prevv, preve;\n    MinCostFlow(int n) : G(n), dist(n),\
    \ prevv(n), preve(n) {}\n    int add_edge(int from, int to, T cap, E cost) {\n\
    \        pos.emplace_back(from, G[from].size());\n        G[from].emplace_back(to,\
    \ cap, cost, G[to].size());\n        G[to].emplace_back(from, 0, -cost, G[from].size()\
    \ - 1);\n        return pos.size() - 1;\n    }\n    tuple<int, int, int, int,\
    \ int> get_edge(int i) {\n        auto e = G[pos[i].first][pos[i].second];\n \
    \       auto re = G[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap +\
    \ re.cap, re.cap, e.cost};\n    }\n    vector<tuple<int, int, int, int, int>>\
    \ edges() {\n        vector<tuple<int, int, int, int, int>> res;\n        for\
    \ (int i = 0; i < pos.size(); i++) {\n            res.emplace_back(get_edge(i));\n\
    \        }\n        return res;\n    }\n    E min_cost_flow(int s, int t, T f)\
    \ {\n        E res = 0;\n        while (f > 0) {\n            fill(dist.begin(),\
    \ dist.end(), inf);\n            dist[s] = 0;\n            bool update = true;\n\
    \            while (update) {\n                update = false;\n             \
    \   for (int v = 0; v < G.size(); v++) {\n                    if (dist[v] == inf)\
    \ continue;\n                    for (int i = 0; i < G[v].size(); i++) {\n   \
    \                     edge& e = G[v][i];\n                        if (e.cap >\
    \ 0 && dist[e.to] > dist[v] + e.cost) {\n                            dist[e.to]\
    \ = dist[v] + e.cost;\n                            prevv[e.to] = v;\n        \
    \                    preve[e.to] = i;\n                            update = true;\n\
    \                        }\n                    }\n                }\n       \
    \     }\n            if (dist[t] == inf) return -1;\n            T d = f;\n  \
    \          for (int v = t; v != s; v = prevv[v]) {\n                d = min(d,\
    \ G[prevv[v]][preve[v]].cap);\n            }\n            f -= d;\n          \
    \  res += dist[t] * d;\n            for (int v = t; v != s; v = prevv[v]) {\n\
    \                edge& e = G[prevv[v]][preve[v]];\n                e.cap -= d;\n\
    \                G[v][e.rev].cap += d;\n            }\n        }\n        return\
    \ res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: flow/MinCostFlow.hpp
  requiredBy: []
  timestamp: '2021-01-19 14:11:46+09:00'
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

## 計算量