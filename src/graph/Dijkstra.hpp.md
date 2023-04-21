---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/shortest_path.test.cpp
    title: test/yosupo/shortest_path.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/base.hpp\"\n#include <bits/stdc++.h>\n#ifdef LOCAL\n\
    #include <debug.hpp>\n#else\n#define debug(...) void(0)\n#endif\n\nusing namespace\
    \ std;\n\ntypedef long long ll;\n#define all(x) begin(x), end(x)\nconstexpr int\
    \ INF = (1 << 30) - 1;\nconstexpr long long IINF = (1LL << 60) - 1;\nconstexpr\
    \ int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};\n\ntemplate <class T> istream&\
    \ operator>>(istream& is, vector<T>& v) {\n    for (auto& x : v) is >> x;\n  \
    \  return is;\n}\n\ntemplate <class T> ostream& operator<<(ostream& os, const\
    \ vector<T>& v) {\n    auto sep = \"\";\n    for (const auto& x : v) os << exchange(sep,\
    \ \" \") << x;\n    return os;\n}\n\ntemplate <class T, class U = T> bool chmin(T&\
    \ x, U&& y) { return y < x and (x = forward<U>(y), true); }\n\ntemplate <class\
    \ T, class U = T> bool chmax(T& x, U&& y) { return x < y and (x = forward<U>(y),\
    \ true); }\n\ntemplate <class T> void mkuni(vector<T>& v) {\n    sort(begin(v),\
    \ end(v));\n    v.erase(unique(begin(v), end(v)), end(v));\n}\n\ntemplate <class\
    \ T> int lwb(const vector<T>& v, const T& x) { return lower_bound(begin(v), end(v),\
    \ x) - begin(v); }\n#line 3 \"src/graph/Dijkstra.hpp\"\n\ntemplate <typename T>\
    \ struct Dijkstra {\n    struct edge {\n        int to;\n        T cost;\n   \
    \     edge(int to, T cost) : to(to), cost(cost) {}\n        bool operator<(const\
    \ edge& e) const { return cost > e.cost; }\n    };\n    vector<vector<edge>> G;\n\
    \    vector<T> dp;\n    vector<int> pre;\n    Dijkstra(int n) : G(n), dp(n), pre(n)\
    \ {}\n    void add_edge(int u, int v, T c) { G[u].emplace_back(v, c); }\n    vector<T>\
    \ build(int s) {\n        int n = G.size();\n        fill(dp.begin(), dp.end(),\
    \ numeric_limits<T>::max());\n        fill(pre.begin(), pre.end(), -1);\n    \
    \    priority_queue<edge> pq;\n        dp[s] = 0;\n        pq.emplace(s, dp[s]);\n\
    \        while (!pq.empty()) {\n            auto p = pq.top();\n            pq.pop();\n\
    \            int v = p.to;\n            if (dp[v] < p.cost) continue;\n      \
    \      for (auto e : G[v]) {\n                if (dp[v] + e.cost < dp[e.to]) {\n\
    \                    dp[e.to] = dp[v] + e.cost;\n                    pre[e.to]\
    \ = v;\n                    pq.emplace(e.to, dp[e.to]);\n                }\n \
    \           }\n        }\n        return dp;\n    }\n    vector<int> restore(int\
    \ t) {\n        vector<int> res;\n        if (pre[t] < 0) return res;\n      \
    \  while (~t) {\n            res.emplace_back(t);\n            t = pre[t];\n \
    \       }\n        reverse(res.begin(), res.end());\n        return res;\n   \
    \ }\n    T operator[](int to) { return dp[to]; }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\ntemplate <typename T> struct Dijkstra\
    \ {\n    struct edge {\n        int to;\n        T cost;\n        edge(int to,\
    \ T cost) : to(to), cost(cost) {}\n        bool operator<(const edge& e) const\
    \ { return cost > e.cost; }\n    };\n    vector<vector<edge>> G;\n    vector<T>\
    \ dp;\n    vector<int> pre;\n    Dijkstra(int n) : G(n), dp(n), pre(n) {}\n  \
    \  void add_edge(int u, int v, T c) { G[u].emplace_back(v, c); }\n    vector<T>\
    \ build(int s) {\n        int n = G.size();\n        fill(dp.begin(), dp.end(),\
    \ numeric_limits<T>::max());\n        fill(pre.begin(), pre.end(), -1);\n    \
    \    priority_queue<edge> pq;\n        dp[s] = 0;\n        pq.emplace(s, dp[s]);\n\
    \        while (!pq.empty()) {\n            auto p = pq.top();\n            pq.pop();\n\
    \            int v = p.to;\n            if (dp[v] < p.cost) continue;\n      \
    \      for (auto e : G[v]) {\n                if (dp[v] + e.cost < dp[e.to]) {\n\
    \                    dp[e.to] = dp[v] + e.cost;\n                    pre[e.to]\
    \ = v;\n                    pq.emplace(e.to, dp[e.to]);\n                }\n \
    \           }\n        }\n        return dp;\n    }\n    vector<int> restore(int\
    \ t) {\n        vector<int> res;\n        if (pre[t] < 0) return res;\n      \
    \  while (~t) {\n            res.emplace_back(t);\n            t = pre[t];\n \
    \       }\n        reverse(res.begin(), res.end());\n        return res;\n   \
    \ }\n    T operator[](int to) { return dp[to]; }\n};\n"
  dependsOn:
  - src/base.hpp
  isVerificationFile: false
  path: src/graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2023-04-22 02:23:28+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/shortest_path.test.cpp
documentation_of: src/graph/Dijkstra.hpp
layout: document
title: Dijkstra
---

## 概要
