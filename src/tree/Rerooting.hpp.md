---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yukicoder/1718.test.cpp
    title: test/yukicoder/1718.test.cpp
  _isVerificationFailed: true
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/tree/Rerooting.hpp\"\n#include <cassert>\n#include <functional>\n\
    #include <vector>\n\ntemplate <class key_t, class sum_t = key_t> struct Rerooting\
    \ {\n    struct edge {\n        int from, to;\n        key_t cost;\n        sum_t\
    \ dp, ndp;\n        edge(int from, int to, key_t cost, sum_t dp, sum_t ndp) :\
    \ from(from), to(to), cost(cost), dp(dp), ndp(ndp) {}\n    };\n    using F = std::function<sum_t(sum_t,\
    \ sum_t)>;\n    using G = std::function<sum_t(sum_t, edge)>;\n\n    int n;\n \
    \   std::vector<std::vector<edge>> g;\n    const F op;\n    const G mapping;\n\
    \    const sum_t id;\n\n    Rerooting(int n, const F& op, const G& mapping, const\
    \ sum_t& id)\n        : n(n), g(n), op(op), mapping(mapping), id(id), sub(n, id),\
    \ dp(n, id) {}\n\n    void add_edge(int u, int v, key_t w) {\n        assert(0\
    \ <= u and u < n);\n        assert(0 <= v and v < n);\n        g[u].emplace_back(u,\
    \ v, w, id, id);\n        g[v].emplace_back(v, u, w, id, id);\n    }\n\n    std::vector<sum_t>\
    \ solve() {\n        dfs_sub(0, -1);\n        dfs_all(0, -1, id);\n        return\
    \ dp;\n    }\n\nprivate:\n    std::vector<sum_t> sub, dp;\n\n    void dfs_sub(int\
    \ v, int p) {\n        for (auto& e : g[v]) {\n            if (e.to == p) continue;\n\
    \            dfs_sub(e.to, v);\n            e.dp = mapping(sub[e.to], e);\n  \
    \          sub[v] = op(sub[v], e.dp);\n        }\n    }\n\n    void dfs_all(int\
    \ v, int p, sum_t top) {\n        sum_t cur = id;\n        for (int i = 0; i <\
    \ (int)g[v].size(); i++) {\n            auto& e = g[v][i];\n            e.ndp\
    \ = cur;\n            if (e.to == p) e.dp = mapping(top, e);\n            cur\
    \ = op(cur, e.dp);\n        }\n        dp[v] = cur;\n        cur = id;\n     \
    \   for (int i = (int)g[v].size() - 1; i >= 0; i--) {\n            auto& e = g[v][i];\n\
    \            if (e.to != p) dfs_all(e.to, v, op(e.ndp, cur));\n            cur\
    \ = op(cur, e.dp);\n        }\n    }\n};\n"
  code: "#include <cassert>\n#include <functional>\n#include <vector>\n\ntemplate\
    \ <class key_t, class sum_t = key_t> struct Rerooting {\n    struct edge {\n \
    \       int from, to;\n        key_t cost;\n        sum_t dp, ndp;\n        edge(int\
    \ from, int to, key_t cost, sum_t dp, sum_t ndp) : from(from), to(to), cost(cost),\
    \ dp(dp), ndp(ndp) {}\n    };\n    using F = std::function<sum_t(sum_t, sum_t)>;\n\
    \    using G = std::function<sum_t(sum_t, edge)>;\n\n    int n;\n    std::vector<std::vector<edge>>\
    \ g;\n    const F op;\n    const G mapping;\n    const sum_t id;\n\n    Rerooting(int\
    \ n, const F& op, const G& mapping, const sum_t& id)\n        : n(n), g(n), op(op),\
    \ mapping(mapping), id(id), sub(n, id), dp(n, id) {}\n\n    void add_edge(int\
    \ u, int v, key_t w) {\n        assert(0 <= u and u < n);\n        assert(0 <=\
    \ v and v < n);\n        g[u].emplace_back(u, v, w, id, id);\n        g[v].emplace_back(v,\
    \ u, w, id, id);\n    }\n\n    std::vector<sum_t> solve() {\n        dfs_sub(0,\
    \ -1);\n        dfs_all(0, -1, id);\n        return dp;\n    }\n\nprivate:\n \
    \   std::vector<sum_t> sub, dp;\n\n    void dfs_sub(int v, int p) {\n        for\
    \ (auto& e : g[v]) {\n            if (e.to == p) continue;\n            dfs_sub(e.to,\
    \ v);\n            e.dp = mapping(sub[e.to], e);\n            sub[v] = op(sub[v],\
    \ e.dp);\n        }\n    }\n\n    void dfs_all(int v, int p, sum_t top) {\n  \
    \      sum_t cur = id;\n        for (int i = 0; i < (int)g[v].size(); i++) {\n\
    \            auto& e = g[v][i];\n            e.ndp = cur;\n            if (e.to\
    \ == p) e.dp = mapping(top, e);\n            cur = op(cur, e.dp);\n        }\n\
    \        dp[v] = cur;\n        cur = id;\n        for (int i = (int)g[v].size()\
    \ - 1; i >= 0; i--) {\n            auto& e = g[v][i];\n            if (e.to !=\
    \ p) dfs_all(e.to, v, op(e.ndp, cur));\n            cur = op(cur, e.dp);\n   \
    \     }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/Rerooting.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yukicoder/1718.test.cpp
documentation_of: src/tree/Rerooting.hpp
layout: document
title: "\u5168\u65B9\u4F4D\u6728 dp"
---

## 概要
`op` は根無し木同士の合成，`mapping` は根無し木の根に新たな根からの辺を加えると考えると良い．

## Links
- [全方位木DP (ReRooting) の抽象化について - メモ帳](https://null-mn.hatenablog.com/entry/2020/04/14/124151)

## 問題例
- [Educational DP Contest / DP まとめコンテスト V - Subtree](https://atcoder.jp/contests/dp/tasks/dp_v)
- [square869120Contest #4 D - Driving on a Tree](https://atcoder.jp/contests/s8pc-4/tasks/s8pc_4_d)
- [AtCoder Beginner Contest 160 F - Distributing Integers](https://atcoder.jp/contests/abc160/tasks/abc160_f)
- [AtCoder Beginner Contest 220 F - Distance Sums 2](https://atcoder.jp/contests/abc220/tasks/abc220_f)
- [AtCoder Beginner Contest 222 F - Expensive Expense](https://atcoder.jp/contests/abc222/tasks/abc222_f)
- [The 2022 ICPC Asia Hangzhou Regional Programming Contest M. Please Save Pigeland](https://codeforces.com/gym/104090/problem/M)
<!-- - [](https://yukicoder.me/problems/no/1718) -->
<!-- - [](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_A) -->
<!-- - [](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=GRL_5_B) -->
<!-- - [](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=1595) -->
<!-- - [](https://blog.hamayanhamayan.com/entry/2017/02/09/155738) -->