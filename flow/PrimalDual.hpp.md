---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_B.PrimalDual.test.cpp
    title: test/aoj/GRL_6_B.PrimalDual.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1288.test.cpp
    title: test/yukicoder/1288.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1301.test.cpp
    title: test/yukicoder/1301.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/PrimalDual.md
    document_title: Primal Dual
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"flow/PrimalDual.hpp\"\n\
    \n/**\n * @brief Primal Dual\n * @docs docs/flow/PrimalDual.md\n */\ntemplate\
    \ <typename T, typename E> struct PrimalDual {\n    const E inf = numeric_limits<E>::max();\n\
    \    struct edge {\n        int to, rev;\n        T cap;\n        E cost;\n  \
    \      edge(int to, T cap, E cost, int rev) : to(to), cap(cap), cost(cost), rev(rev)\
    \ {}\n    };\n    vector<vector<edge>> G;\n    vector<pair<int, int>> pos;\n \
    \   vector<E> h, dist;\n    vector<int> prevv, preve;\n    PrimalDual(int n) :\
    \ G(n), h(n), dist(n), prevv(n), preve(n) {}\n    int add_edge(int from, int to,\
    \ T cap, E cost) {\n        pos.emplace_back(from, G[from].size());\n        G[from].emplace_back(to,\
    \ cap, cost, G[to].size());\n        G[to].emplace_back(from, 0, -cost, G[from].size()\
    \ - 1);\n        return pos.size() - 1;\n    }\n    tuple<int, int, int, int,\
    \ int> get_edge(int i) {\n        auto e = G[pos[i].first][pos[i].second];\n \
    \       auto re = G[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap +\
    \ re.cap, re.cap, e.cost};\n    }\n    vector<tuple<int, int, int, int, int>>\
    \ edges() {\n        vector<tuple<int, int, int, int, int>> res;\n        for\
    \ (int i = 0; i < (int)pos.size(); i++) {\n            res.emplace_back(get_edge(i));\n\
    \        }\n        return res;\n    }\n    void dijkstra(int s) {\n        struct\
    \ P {\n            E c;\n            int v;\n            P(E c, int v) : c(c),\
    \ v(v) {}\n            bool operator<(const P& rhs) const { return c > rhs.c;\
    \ }\n        };\n        priority_queue<P> pq;\n        fill(dist.begin(), dist.end(),\
    \ inf);\n        dist[s] = 0;\n        pq.emplace(dist[s], s);\n        while\
    \ (!pq.empty()) {\n            auto p = pq.top();\n            pq.pop();\n   \
    \         int v = p.v;\n            if (dist[v] < p.c) continue;\n           \
    \ for (int i = 0; i < (int)G[v].size(); i++) {\n                auto& e = G[v][i];\n\
    \                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])\
    \ {\n                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];\n   \
    \                 prevv[e.to] = v;\n                    preve[e.to] = i;\n   \
    \                 pq.emplace(dist[e.to], e.to);\n                }\n         \
    \   }\n        }\n    }\n    vector<pair<T, E>> slope(int s, int t, T lim) {\n\
    \        T f = 0;\n        E c = 0, pre = -1;\n        vector<pair<T, E>> res;\n\
    \        res.emplace_back(f, c);\n        while (f < lim) {\n            dijkstra(s);\n\
    \            if (dist[t] == inf) break;\n            for (int v = 0; v < (int)G.size();\
    \ v++) h[v] += dist[v];\n            T d = lim - f;\n            for (int v =\
    \ t; v != s; v = prevv[v]) {\n                d = min(d, G[prevv[v]][preve[v]].cap);\n\
    \            }\n            for (int v = t; v != s; v = prevv[v]) {\n        \
    \        auto& e = G[prevv[v]][preve[v]];\n                e.cap -= d;\n     \
    \           G[v][e.rev].cap += d;\n            }\n            f += d;\n      \
    \      c += h[t] * d;\n            if (pre == h[t]) res.pop_back();\n        \
    \    res.emplace_back(f, c);\n            pre = c;\n        }\n        return\
    \ res;\n    }\n    E min_cost_flow(int s, int t, T f) {\n        auto res = slope(s,\
    \ t, f).back();\n        return res.first == f ? res.second : -1;\n    }\n   \
    \ pair<T, E> min_cost_max_flow(int s, int t) { return slope(s, t, numeric_limits<T>::max()).back();\
    \ }\n    vector<pair<T, E>> min_cost_slope(int s, int t) { return slope(s, t,\
    \ numeric_limits<T>::max()); }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Primal Dual\n *\
    \ @docs docs/flow/PrimalDual.md\n */\ntemplate <typename T, typename E> struct\
    \ PrimalDual {\n    const E inf = numeric_limits<E>::max();\n    struct edge {\n\
    \        int to, rev;\n        T cap;\n        E cost;\n        edge(int to, T\
    \ cap, E cost, int rev) : to(to), cap(cap), cost(cost), rev(rev) {}\n    };\n\
    \    vector<vector<edge>> G;\n    vector<pair<int, int>> pos;\n    vector<E> h,\
    \ dist;\n    vector<int> prevv, preve;\n    PrimalDual(int n) : G(n), h(n), dist(n),\
    \ prevv(n), preve(n) {}\n    int add_edge(int from, int to, T cap, E cost) {\n\
    \        pos.emplace_back(from, G[from].size());\n        G[from].emplace_back(to,\
    \ cap, cost, G[to].size());\n        G[to].emplace_back(from, 0, -cost, G[from].size()\
    \ - 1);\n        return pos.size() - 1;\n    }\n    tuple<int, int, int, int,\
    \ int> get_edge(int i) {\n        auto e = G[pos[i].first][pos[i].second];\n \
    \       auto re = G[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap +\
    \ re.cap, re.cap, e.cost};\n    }\n    vector<tuple<int, int, int, int, int>>\
    \ edges() {\n        vector<tuple<int, int, int, int, int>> res;\n        for\
    \ (int i = 0; i < (int)pos.size(); i++) {\n            res.emplace_back(get_edge(i));\n\
    \        }\n        return res;\n    }\n    void dijkstra(int s) {\n        struct\
    \ P {\n            E c;\n            int v;\n            P(E c, int v) : c(c),\
    \ v(v) {}\n            bool operator<(const P& rhs) const { return c > rhs.c;\
    \ }\n        };\n        priority_queue<P> pq;\n        fill(dist.begin(), dist.end(),\
    \ inf);\n        dist[s] = 0;\n        pq.emplace(dist[s], s);\n        while\
    \ (!pq.empty()) {\n            auto p = pq.top();\n            pq.pop();\n   \
    \         int v = p.v;\n            if (dist[v] < p.c) continue;\n           \
    \ for (int i = 0; i < (int)G[v].size(); i++) {\n                auto& e = G[v][i];\n\
    \                if (e.cap > 0 && dist[e.to] > dist[v] + e.cost + h[v] - h[e.to])\
    \ {\n                    dist[e.to] = dist[v] + e.cost + h[v] - h[e.to];\n   \
    \                 prevv[e.to] = v;\n                    preve[e.to] = i;\n   \
    \                 pq.emplace(dist[e.to], e.to);\n                }\n         \
    \   }\n        }\n    }\n    vector<pair<T, E>> slope(int s, int t, T lim) {\n\
    \        T f = 0;\n        E c = 0, pre = -1;\n        vector<pair<T, E>> res;\n\
    \        res.emplace_back(f, c);\n        while (f < lim) {\n            dijkstra(s);\n\
    \            if (dist[t] == inf) break;\n            for (int v = 0; v < (int)G.size();\
    \ v++) h[v] += dist[v];\n            T d = lim - f;\n            for (int v =\
    \ t; v != s; v = prevv[v]) {\n                d = min(d, G[prevv[v]][preve[v]].cap);\n\
    \            }\n            for (int v = t; v != s; v = prevv[v]) {\n        \
    \        auto& e = G[prevv[v]][preve[v]];\n                e.cap -= d;\n     \
    \           G[v][e.rev].cap += d;\n            }\n            f += d;\n      \
    \      c += h[t] * d;\n            if (pre == h[t]) res.pop_back();\n        \
    \    res.emplace_back(f, c);\n            pre = c;\n        }\n        return\
    \ res;\n    }\n    E min_cost_flow(int s, int t, T f) {\n        auto res = slope(s,\
    \ t, f).back();\n        return res.first == f ? res.second : -1;\n    }\n   \
    \ pair<T, E> min_cost_max_flow(int s, int t) { return slope(s, t, numeric_limits<T>::max()).back();\
    \ }\n    vector<pair<T, E>> min_cost_slope(int s, int t) { return slope(s, t,\
    \ numeric_limits<T>::max()); }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: flow/PrimalDual.hpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1301.test.cpp
  - test/yukicoder/1288.test.cpp
  - test/aoj/GRL_6_B.PrimalDual.test.cpp
documentation_of: flow/PrimalDual.hpp
layout: document
redirect_from:
- /library/flow/PrimalDual.hpp
- /library/flow/PrimalDual.hpp.html
title: Primal Dual
---
## 概要
最小費用流を計算する.

- `add_edge(from, to, cap, cost)`：$from$から$to$への容量$cap$, 費用$cost$の辺を追加する.
- `get_edge(i)`：$i$番目に追加した辺の{始点, 終点, 容量, 実際に流れている量, 費用}の情報を返す.
- `edges()`：全ての辺の情報を返す.
- `min_cost_flow(s, t, f)`：始点$s$から終点$t$へ流量$f$を流す際の最小費用を返す.
- `min_cost_max_flow(s, t)`：最大流量, およびそのときの最小費用を返す.
- `min_cost_slope(s, t)`：各流量に対する最小費用は折れ線状のグラフとなるが, そのグラフの各頂点の流量および最小費用を返す.

## 計算量
$O(fE\log V)$