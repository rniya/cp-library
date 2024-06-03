---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/tree_path_composite_sum.test.cpp
    title: test/yosupo/tree_path_composite_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/Rerooting.hpp\"\n#include <cassert>\n#include <vector>\n\
    \ntemplate <class TreeDP> struct Rerooting {\n    using T = TreeDP::T;\n\n   \
    \ struct edge {\n        int to, e;\n        T dp, ndp;\n        edge(int to,\
    \ int e, T dp, T ndp) : to(to), e(e), dp(dp), ndp(ndp) {}\n    };\n\n    std::vector<std::vector<edge>>\
    \ G;\n\n    Rerooting(int n, const TreeDP& treedp) : n(n), m(0), G(n), treedp(treedp),\
    \ sub(n), dp(n) {}\n\n    void add_edge(int u, int v) {\n        assert(0 <= u\
    \ and u < n);\n        assert(0 <= v and v < n);\n        G[u].emplace_back(v,\
    \ m, treedp.e(), treedp.e());\n        G[v].emplace_back(u, m, treedp.e(), treedp.e());\n\
    \        m++;\n    }\n\n    std::vector<T> solve() {\n        dfs_sub(0, -1);\n\
    \        dfs_all(0, -1, treedp.e());\n        return dp;\n    }\n\n  private:\n\
    \    int n, m;\n    TreeDP treedp;\n    std::vector<T> sub, dp;\n\n    void dfs_sub(int\
    \ v, int p) {\n        sub[v] = treedp.e();\n        for (auto& e : G[v]) {\n\
    \            if (e.to == p) continue;\n            dfs_sub(e.to, v);\n       \
    \     sub[v] = treedp.op(sub[v], treedp.add_edge(sub[e.to], e.e));\n        }\n\
    \        sub[v] = treedp.add_vertex(sub[v], v);\n    }\n\n    void dfs_all(int\
    \ v, int p, const T& top) {\n        T cur = treedp.e();\n        for (int i =\
    \ 0; i < int(G[v].size()); i++) {\n            auto& e = G[v][i];\n          \
    \  e.ndp = cur;\n            e.dp = treedp.add_edge(e.to == p ? top : sub[e.to],\
    \ e.e);\n            cur = treedp.op(cur, e.dp);\n        }\n        dp[v] = treedp.add_vertex(cur,\
    \ v);\n        cur = treedp.e();\n        for (int i = int(G[v].size()) - 1; i\
    \ >= 0; i--) {\n            auto& e = G[v][i];\n            e.ndp = treedp.add_vertex(treedp.op(e.ndp,\
    \ cur), v);\n            if (e.to != p) dfs_all(e.to, v, e.ndp);\n           \
    \ cur = treedp.op(cur, e.dp);\n        }\n    }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n\ntemplate <class TreeDP>\
    \ struct Rerooting {\n    using T = TreeDP::T;\n\n    struct edge {\n        int\
    \ to, e;\n        T dp, ndp;\n        edge(int to, int e, T dp, T ndp) : to(to),\
    \ e(e), dp(dp), ndp(ndp) {}\n    };\n\n    std::vector<std::vector<edge>> G;\n\
    \n    Rerooting(int n, const TreeDP& treedp) : n(n), m(0), G(n), treedp(treedp),\
    \ sub(n), dp(n) {}\n\n    void add_edge(int u, int v) {\n        assert(0 <= u\
    \ and u < n);\n        assert(0 <= v and v < n);\n        G[u].emplace_back(v,\
    \ m, treedp.e(), treedp.e());\n        G[v].emplace_back(u, m, treedp.e(), treedp.e());\n\
    \        m++;\n    }\n\n    std::vector<T> solve() {\n        dfs_sub(0, -1);\n\
    \        dfs_all(0, -1, treedp.e());\n        return dp;\n    }\n\n  private:\n\
    \    int n, m;\n    TreeDP treedp;\n    std::vector<T> sub, dp;\n\n    void dfs_sub(int\
    \ v, int p) {\n        sub[v] = treedp.e();\n        for (auto& e : G[v]) {\n\
    \            if (e.to == p) continue;\n            dfs_sub(e.to, v);\n       \
    \     sub[v] = treedp.op(sub[v], treedp.add_edge(sub[e.to], e.e));\n        }\n\
    \        sub[v] = treedp.add_vertex(sub[v], v);\n    }\n\n    void dfs_all(int\
    \ v, int p, const T& top) {\n        T cur = treedp.e();\n        for (int i =\
    \ 0; i < int(G[v].size()); i++) {\n            auto& e = G[v][i];\n          \
    \  e.ndp = cur;\n            e.dp = treedp.add_edge(e.to == p ? top : sub[e.to],\
    \ e.e);\n            cur = treedp.op(cur, e.dp);\n        }\n        dp[v] = treedp.add_vertex(cur,\
    \ v);\n        cur = treedp.e();\n        for (int i = int(G[v].size()) - 1; i\
    \ >= 0; i--) {\n            auto& e = G[v][i];\n            e.ndp = treedp.add_vertex(treedp.op(e.ndp,\
    \ cur), v);\n            if (e.to != p) dfs_all(e.to, v, e.ndp);\n           \
    \ cur = treedp.op(cur, e.dp);\n        }\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/Rerooting.hpp
  requiredBy: []
  timestamp: '2024-06-04 02:28:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/tree_path_composite_sum.test.cpp
documentation_of: src/tree/Rerooting.hpp
layout: document
title: Rerooting
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