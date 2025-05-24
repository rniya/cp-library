---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp
    title: test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/StaticTopTree.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <queue>\n#include <utility>\n#include <vector>\n\nstruct\
    \ StaticTopTree {\n    struct Node {\n        int l, r, p, head, tail;\n     \
    \   bool is_compress;\n        Node() {}\n        Node(int l, int r, int p, bool\
    \ is_compress) : l(l), r(r), p(p), is_compress(is_compress) {}\n    };\n    int\
    \ n;\n    std::vector<std::vector<int>> G;\n    std::vector<Node> nodes;\n\n \
    \   StaticTopTree(int n) : n(n), G(n), nodes(n, {-1, -1, -1, false}) {}\n\n  \
    \  void add_edge(int u, int v) {\n        assert(0 <= u and u < n);\n        assert(0\
    \ <= v and v < n);\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n\n    void build(int r = 0) {\n        dfs_sz(r, -1);\n        dfs_stt(r);\n\
    \        assert(int(nodes.size()) == 2 * n - 1);\n    }\n\n  private:\n    int\
    \ make_node(int l, int r, bool is_compress) {\n        int v = nodes.size();\n\
    \        nodes.emplace_back(l, r, -1, is_compress);\n        nodes[l].p = nodes[r].p\
    \ = v;\n        return v;\n    }\n\n    int dfs_sz(int v, int p) {\n        for\
    \ (int& u : G[v]) {\n            if (u == p) {\n                std::swap(u, G[v].back());\n\
    \                G[v].pop_back();\n                break;\n            }\n   \
    \     }\n        int sum = 1, best = 0;\n        for (int& u : G[v]) {\n     \
    \       int ch = dfs_sz(u, v);\n            sum += ch;\n            if (best <\
    \ ch) {\n                best = ch;\n                std::swap(u, G[v].front());\n\
    \            }\n        }\n        return sum;\n    }\n\n    std::pair<int, int>\
    \ dfs_stt(int v) {\n        std::vector<std::pair<int, int>> st;\n        st.emplace_back(0,\
    \ v);\n        auto merge_last = [&]() {\n            auto [hr, ir] = st.back();\n\
    \            st.pop_back();\n            auto [hl, il] = st.back();\n        \
    \    st.pop_back();\n            st.emplace_back(std::max(hl, hr) + 1, make_node(il,\
    \ ir, true));\n        };\n\n        for (int cur = v; not G[cur].empty(); cur\
    \ = G[cur].front()) {\n            int nxt = G[cur].front(), marked = nxt;\n \
    \           std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,\
    \ int>>,\n                                std::greater<std::pair<int, int>>>\n\
    \                pq;\n            pq.emplace(0, marked);\n            for (int\
    \ i = 1; i < int(G[cur].size()); i++) {\n                pq.emplace(dfs_stt(G[cur][i]));\n\
    \            }\n            while (pq.size() >= 2) {\n                auto [hl,\
    \ il] = pq.top();\n                pq.pop();\n                auto [hr, ir] =\
    \ pq.top();\n                pq.pop();\n                if (ir == marked) {\n\
    \                    std::swap(il, ir);\n                }\n                int\
    \ i = make_node(il, ir, false);\n                if (il == marked) {\n       \
    \             marked = i;\n                }\n                pq.emplace(std::max(hl,\
    \ hr) + 1, i);\n            }\n            st.emplace_back(pq.top());\n\n    \
    \        while (true) {\n                int len = st.size();\n              \
    \  if (len >= 3 and (st[len - 3].first == st[len - 2].first or st[len - 3].first\
    \ <= st[len - 1].first)) {\n                    auto tmp = st.back();\n      \
    \              st.pop_back();\n                    merge_last();\n           \
    \         st.emplace_back(tmp);\n                } else if (len >= 2 and st[len\
    \ - 2].first <= st[len - 1].first) {\n                    merge_last();\n    \
    \            } else {\n                    break;\n                }\n       \
    \     }\n        }\n\n        while (st.size() >= 2) {\n            merge_last();\n\
    \        }\n        return st.back();\n    }\n};\n\ntemplate <typename TREEDP>\
    \ struct DynamicTreeDP {\n    using T = typename TREEDP::T;\n\n    template <typename\
    \ F>\n    DynamicTreeDP(int n, const StaticTopTree& stt, const F& vertex) : n(n),\
    \ stt(stt), dp(2 * n - 1) {\n        for (int i = 0; i < n; i++) {\n         \
    \   dp[i] = vertex(i);\n        }\n        for (int i = n; i < 2 * n - 1; i++)\
    \ {\n            update(i);\n        }\n    }\n\n    void set(int v, T x) {\n\
    \        assert(0 <= v and v < n);\n        dp[v] = x;\n        for (int i = stt.nodes[v].p;\
    \ i != -1; i = stt.nodes[i].p) {\n            update(i);\n        }\n    }\n\n\
    \    T all_prod() const { return dp.back(); }\n\n  private:\n    int n;\n    const\
    \ StaticTopTree& stt;\n    std::vector<T> dp;\n\n    void update(int k) {\n  \
    \      const auto &L = dp[stt.nodes[k].l], &R = dp[stt.nodes[k].r];\n        dp[k]\
    \ = (stt.nodes[k].is_compress ? TREEDP::compress(L, R) : TREEDP::rake(L, R));\n\
    \    }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n\nstruct StaticTopTree {\n    struct Node\
    \ {\n        int l, r, p, head, tail;\n        bool is_compress;\n        Node()\
    \ {}\n        Node(int l, int r, int p, bool is_compress) : l(l), r(r), p(p),\
    \ is_compress(is_compress) {}\n    };\n    int n;\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<Node> nodes;\n\n    StaticTopTree(int n) : n(n), G(n), nodes(n,\
    \ {-1, -1, -1, false}) {}\n\n    void add_edge(int u, int v) {\n        assert(0\
    \ <= u and u < n);\n        assert(0 <= v and v < n);\n        G[u].emplace_back(v);\n\
    \        G[v].emplace_back(u);\n    }\n\n    void build(int r = 0) {\n       \
    \ dfs_sz(r, -1);\n        dfs_stt(r);\n        assert(int(nodes.size()) == 2 *\
    \ n - 1);\n    }\n\n  private:\n    int make_node(int l, int r, bool is_compress)\
    \ {\n        int v = nodes.size();\n        nodes.emplace_back(l, r, -1, is_compress);\n\
    \        nodes[l].p = nodes[r].p = v;\n        return v;\n    }\n\n    int dfs_sz(int\
    \ v, int p) {\n        for (int& u : G[v]) {\n            if (u == p) {\n    \
    \            std::swap(u, G[v].back());\n                G[v].pop_back();\n  \
    \              break;\n            }\n        }\n        int sum = 1, best = 0;\n\
    \        for (int& u : G[v]) {\n            int ch = dfs_sz(u, v);\n         \
    \   sum += ch;\n            if (best < ch) {\n                best = ch;\n   \
    \             std::swap(u, G[v].front());\n            }\n        }\n        return\
    \ sum;\n    }\n\n    std::pair<int, int> dfs_stt(int v) {\n        std::vector<std::pair<int,\
    \ int>> st;\n        st.emplace_back(0, v);\n        auto merge_last = [&]() {\n\
    \            auto [hr, ir] = st.back();\n            st.pop_back();\n        \
    \    auto [hl, il] = st.back();\n            st.pop_back();\n            st.emplace_back(std::max(hl,\
    \ hr) + 1, make_node(il, ir, true));\n        };\n\n        for (int cur = v;\
    \ not G[cur].empty(); cur = G[cur].front()) {\n            int nxt = G[cur].front(),\
    \ marked = nxt;\n            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int,\
    \ int>>,\n                                std::greater<std::pair<int, int>>>\n\
    \                pq;\n            pq.emplace(0, marked);\n            for (int\
    \ i = 1; i < int(G[cur].size()); i++) {\n                pq.emplace(dfs_stt(G[cur][i]));\n\
    \            }\n            while (pq.size() >= 2) {\n                auto [hl,\
    \ il] = pq.top();\n                pq.pop();\n                auto [hr, ir] =\
    \ pq.top();\n                pq.pop();\n                if (ir == marked) {\n\
    \                    std::swap(il, ir);\n                }\n                int\
    \ i = make_node(il, ir, false);\n                if (il == marked) {\n       \
    \             marked = i;\n                }\n                pq.emplace(std::max(hl,\
    \ hr) + 1, i);\n            }\n            st.emplace_back(pq.top());\n\n    \
    \        while (true) {\n                int len = st.size();\n              \
    \  if (len >= 3 and (st[len - 3].first == st[len - 2].first or st[len - 3].first\
    \ <= st[len - 1].first)) {\n                    auto tmp = st.back();\n      \
    \              st.pop_back();\n                    merge_last();\n           \
    \         st.emplace_back(tmp);\n                } else if (len >= 2 and st[len\
    \ - 2].first <= st[len - 1].first) {\n                    merge_last();\n    \
    \            } else {\n                    break;\n                }\n       \
    \     }\n        }\n\n        while (st.size() >= 2) {\n            merge_last();\n\
    \        }\n        return st.back();\n    }\n};\n\ntemplate <typename TREEDP>\
    \ struct DynamicTreeDP {\n    using T = typename TREEDP::T;\n\n    template <typename\
    \ F>\n    DynamicTreeDP(int n, const StaticTopTree& stt, const F& vertex) : n(n),\
    \ stt(stt), dp(2 * n - 1) {\n        for (int i = 0; i < n; i++) {\n         \
    \   dp[i] = vertex(i);\n        }\n        for (int i = n; i < 2 * n - 1; i++)\
    \ {\n            update(i);\n        }\n    }\n\n    void set(int v, T x) {\n\
    \        assert(0 <= v and v < n);\n        dp[v] = x;\n        for (int i = stt.nodes[v].p;\
    \ i != -1; i = stt.nodes[i].p) {\n            update(i);\n        }\n    }\n\n\
    \    T all_prod() const { return dp.back(); }\n\n  private:\n    int n;\n    const\
    \ StaticTopTree& stt;\n    std::vector<T> dp;\n\n    void update(int k) {\n  \
    \      const auto &L = dp[stt.nodes[k].l], &R = dp[stt.nodes[k].r];\n        dp[k]\
    \ = (stt.nodes[k].is_compress ? TREEDP::compress(L, R) : TREEDP::rake(L, R));\n\
    \    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/StaticTopTree.hpp
  requiredBy: []
  timestamp: '2025-05-24 15:05:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/point_set_tree_path_composite_sum_fixed_root.test.cpp
documentation_of: src/tree/StaticTopTree.hpp
layout: document
title: Static Top Tree
---

## 概要

木の生成過程を二分木としてもつデータ構造．
Static Top Tree の各頂点はもとの木における 1 つのパスが expose された部分木を表す．
Static Top Tree の葉はもとの木の各頂点（と virtual な根を結んだ木）に対応し，これらを virtual な根同士を縮約するようにマージする rake 操作，heavy path に沿って上下にマージする compress 操作によって全体の木を作り上げている（[このブログ](https://maspypy.com/library-checker-point-set-tree-path-composite-sum)の図がわかりやすい）．
$n$ 頂点の木に対する Static Top Tree の高さは $\mathrm{O}(\log n)$ であり，これにより分割統治等各種計算を効率的に行える．

実装の際には以下のような構造体 `TreeDP` を要する．
`T` には部分木内の各種データや expose されたパスに対応するデータをもつと良い．
また，`rake(l, r)` においては `l` の expose されたパスがマージ後のそれに対応し，`compress(l, r)` では `l` のパスの下に `r` のパスをつなげるようにマージが行われる．

`DynamicTreeDP` では各頂点に対して，その頂点に載るデータだけでなくそれと親頂点を結ぶ辺（これが expose されていると考えて良い）上のデータも載せる．

```c++
struct TreeDP {
    struct T {};

    static T rake(const T& l, const T& r) {}

    static T compress(const T& l, const T& r) {}
};
```


## 出題例
- [AtCoder Beginner Contest 269 Ex - Antichain](https://atcoder.jp/contests/abc269/tasks/abc269_h)
- [AtCoder Beginner Contest 351 G - Hash on Tree](https://atcoder.jp/contests/abc351/tasks/abc351_g)
- [The 3rd Universal Cup. Stage 37: Wuhan B. Black Red Tree](https://contest.ucup.ac/contest/2025/problem/10737)