---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.test.cpp
    title: test/aoj/GRL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/jump_on_tree.test.cpp
    title: test/yosupo/jump_on_tree.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_path_sum.test.cpp
    title: test/yosupo/vertex_add_path_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_subtree_sum.test.cpp
    title: test/yosupo/vertex_add_subtree_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_set_path_composite.test.cpp
    title: test/yosupo/vertex_set_path_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/tree/HeavyLightDecomposition.hpp\"\n#include <algorithm>\n\
    #include <cassert>\n#include <unordered_map>\n#include <utility>\n#include <vector>\n\
    \nstruct HeavyLightDecomposition {\n    std::vector<std::vector<int>> G;  // child\
    \ of vertex v on heavy edge is G[v].front() if it is not parent of v\n    int\
    \ n, time;\n    std::vector<int> par,  // parent of vertex v\n        sub,   \
    \            // size of subtree whose root is v\n        dep,               //\
    \ distance bitween root and vertex v\n        head,              // vertex that\
    \ is the nearest to root on heavy path of vertex v\n        tree_id,         \
    \  // id of tree vertex v belongs to\n        vertex_id,         // id of vertex\
    \ v (consecutive on heavy paths)\n        vertex_id_inv;     // vertex_id_inv[vertex_id[v]]\
    \ = v\n\n    HeavyLightDecomposition() {}\n\n    HeavyLightDecomposition(int n)\n\
    \        : G(n),\n          n(n),\n          time(0),\n          par(n, -1),\n\
    \          sub(n),\n          dep(n, 0),\n          head(n),\n          tree_id(n,\
    \ -1),\n          vertex_id(n, -1),\n          vertex_id_inv(n) {}\n\n    void\
    \ add_edge(int u, int v) {\n        assert(0 <= u and u < n);\n        assert(0\
    \ <= v and v < n);\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n\n    void build(std::vector<int> roots = {0}) {\n        int tree_id_cur\
    \ = 0;\n        for (int& r : roots) {\n            assert(0 <= r and r < n);\n\
    \            dfs_sz(r);\n            head[r] = r;\n            dfs_hld(r, tree_id_cur++);\n\
    \        }\n        assert(time == n);\n        for (int v = 0; v < n; v++) vertex_id_inv[vertex_id[v]]\
    \ = v;\n    }\n\n    int idx(int v) const { return vertex_id[v]; }\n\n    int\
    \ la(int v, int k) const {\n        assert(0 <= v and v < n);\n        assert(0\
    \ <= k and k <= dep[v]);\n        while (1) {\n            int u = head[v];\n\
    \            if (vertex_id[v] - k >= vertex_id[u]) return vertex_id_inv[vertex_id[v]\
    \ - k];\n            k -= vertex_id[v] - vertex_id[u] + 1;\n            v = par[u];\n\
    \        }\n    }\n\n    int lca(int u, int v) const {\n        assert(0 <= u\
    \ and u < n);\n        assert(0 <= v and v < n);\n        assert(tree_id[u] ==\
    \ tree_id[v]);\n        for (;; v = par[head[v]]) {\n            if (vertex_id[u]\
    \ > vertex_id[v]) std::swap(u, v);\n            if (head[u] == head[v]) return\
    \ u;\n        }\n    }\n\n    int jump(int s, int t, int i) const {\n        assert(0\
    \ <= s and s < n);\n        assert(0 <= t and t < n);\n        assert(0 <= i);\n\
    \        if (tree_id[s] != tree_id[t]) return -1;\n        if (i == 0) return\
    \ s;\n        int p = lca(s, t), d = dep[s] + dep[t] - 2 * dep[p];\n        if\
    \ (d < i) return -1;\n        if (dep[s] - dep[p] >= i) return la(s, i);\n   \
    \     return la(t, d - i);\n    }\n\n    int distance(int u, int v) const {\n\
    \        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n      \
    \  assert(tree_id[u] == tree_id[v]);\n        return dep[u] + dep[v] - 2 * dep[lca(u,\
    \ v)];\n    }\n\n    template <typename F> void query_path(int u, int v, const\
    \ F& f, bool vertex = false) const {\n        assert(0 <= u and u < n);\n    \
    \    assert(0 <= v and v < n);\n        assert(tree_id[u] == tree_id[v]);\n  \
    \      int p = lca(u, v);\n        for (auto& e : ascend(u, p)) f(e.second, e.first\
    \ + 1);\n        if (vertex) f(vertex_id[p], vertex_id[p] + 1);\n        for (auto&\
    \ e : descend(p, v)) f(e.first, e.second + 1);\n    }\n\n    template <typename\
    \ F> void query_path_noncommutative(int u, int v, const F& f, bool vertex = false)\
    \ const {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n\
    \        assert(tree_id[u] == tree_id[v]);\n        int p = lca(u, v);\n     \
    \   for (auto& e : ascend(u, p)) f(e.first + 1, e.second);\n        if (vertex)\
    \ f(vertex_id[p], vertex_id[p] + 1);\n        for (auto& e : descend(p, v)) f(e.first,\
    \ e.second + 1);\n    }\n\n    template <typename F> void query_subtree(int u,\
    \ const F& f, bool vertex = false) const {\n        assert(0 <= u and u < n);\n\
    \        f(vertex_id[u] + !vertex, vertex_id[u] + sub[u]);\n    }\n\n    std::pair<std::unordered_map<int,\
    \ std::vector<int>>, int> auxiliary_tree(std::vector<int> vs) {\n        int len\
    \ = vs.size();\n        std::sort(vs.begin(), vs.end(), [&](int i, int j) { return\
    \ vertex_id[i] < vertex_id[j]; });\n        for (int i = 0; i + 1 < len; i++)\
    \ vs.emplace_back(lca(vs[i], vs[i + 1]));\n        std::sort(vs.begin(), vs.end(),\
    \ [&](int i, int j) { return vertex_id[i] < vertex_id[j]; });\n        vs.erase(std::unique(vs.begin(),\
    \ vs.end()), vs.end());\n        std::vector<int> st;\n        std::unordered_map<int,\
    \ std::vector<int>> res;\n        for (int v : vs) {\n            while (not st.empty()\
    \ and vertex_id[st.back()] + sub[st.back()] <= vertex_id[v]) st.pop_back();\n\
    \            if (not st.empty()) res[st.back()].emplace_back(v);\n           \
    \ st.emplace_back(v);\n        }\n        return {res, vs[0]};\n    }\n\n  private:\n\
    \    void dfs_sz(int v) {\n        sub[v] = 1;\n        if (!G[v].empty() and\
    \ G[v].front() == par[v]) std::swap(G[v].front(), G[v].back());\n        for (int&\
    \ u : G[v]) {\n            if (u == par[v]) continue;\n            par[u] = v;\n\
    \            dep[u] = dep[v] + 1;\n            dfs_sz(u);\n            sub[v]\
    \ += sub[u];\n            if (sub[u] > sub[G[v].front()]) std::swap(u, G[v].front());\n\
    \        }\n    }\n\n    void dfs_hld(int v, int tree_id_cur) {\n        vertex_id[v]\
    \ = time++;\n        tree_id[v] = tree_id_cur;\n        for (int& u : G[v]) {\n\
    \            if (u == par[v]) continue;\n            head[u] = (u == G[v][0] ?\
    \ head[v] : u);\n            dfs_hld(u, tree_id_cur);\n        }\n    }\n\n  \
    \  std::vector<std::pair<int, int>> ascend(int u, int v) const {  // [u, v), v\
    \ is ancestor of u\n        std::vector<std::pair<int, int>> res;\n        while\
    \ (head[u] != head[v]) {\n            res.emplace_back(vertex_id[u], vertex_id[head[u]]);\n\
    \            u = par[head[u]];\n        }\n        if (u != v) res.emplace_back(vertex_id[u],\
    \ vertex_id[v] + 1);\n        return res;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> descend(int u, int v) const {  // (u, v], u is ancestor of v\n       \
    \ if (u == v) return {};\n        if (head[u] == head[v]) return {{vertex_id[u]\
    \ + 1, vertex_id[v]}};\n        auto res = descend(u, par[head[v]]);\n       \
    \ res.emplace_back(vertex_id[head[v]], vertex_id[v]);\n        return res;\n \
    \   }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <unordered_map>\n\
    #include <utility>\n#include <vector>\n\nstruct HeavyLightDecomposition {\n  \
    \  std::vector<std::vector<int>> G;  // child of vertex v on heavy edge is G[v].front()\
    \ if it is not parent of v\n    int n, time;\n    std::vector<int> par,  // parent\
    \ of vertex v\n        sub,               // size of subtree whose root is v\n\
    \        dep,               // distance bitween root and vertex v\n        head,\
    \              // vertex that is the nearest to root on heavy path of vertex v\n\
    \        tree_id,           // id of tree vertex v belongs to\n        vertex_id,\
    \         // id of vertex v (consecutive on heavy paths)\n        vertex_id_inv;\
    \     // vertex_id_inv[vertex_id[v]] = v\n\n    HeavyLightDecomposition() {}\n\
    \n    HeavyLightDecomposition(int n)\n        : G(n),\n          n(n),\n     \
    \     time(0),\n          par(n, -1),\n          sub(n),\n          dep(n, 0),\n\
    \          head(n),\n          tree_id(n, -1),\n          vertex_id(n, -1),\n\
    \          vertex_id_inv(n) {}\n\n    void add_edge(int u, int v) {\n        assert(0\
    \ <= u and u < n);\n        assert(0 <= v and v < n);\n        G[u].emplace_back(v);\n\
    \        G[v].emplace_back(u);\n    }\n\n    void build(std::vector<int> roots\
    \ = {0}) {\n        int tree_id_cur = 0;\n        for (int& r : roots) {\n   \
    \         assert(0 <= r and r < n);\n            dfs_sz(r);\n            head[r]\
    \ = r;\n            dfs_hld(r, tree_id_cur++);\n        }\n        assert(time\
    \ == n);\n        for (int v = 0; v < n; v++) vertex_id_inv[vertex_id[v]] = v;\n\
    \    }\n\n    int idx(int v) const { return vertex_id[v]; }\n\n    int la(int\
    \ v, int k) const {\n        assert(0 <= v and v < n);\n        assert(0 <= k\
    \ and k <= dep[v]);\n        while (1) {\n            int u = head[v];\n     \
    \       if (vertex_id[v] - k >= vertex_id[u]) return vertex_id_inv[vertex_id[v]\
    \ - k];\n            k -= vertex_id[v] - vertex_id[u] + 1;\n            v = par[u];\n\
    \        }\n    }\n\n    int lca(int u, int v) const {\n        assert(0 <= u\
    \ and u < n);\n        assert(0 <= v and v < n);\n        assert(tree_id[u] ==\
    \ tree_id[v]);\n        for (;; v = par[head[v]]) {\n            if (vertex_id[u]\
    \ > vertex_id[v]) std::swap(u, v);\n            if (head[u] == head[v]) return\
    \ u;\n        }\n    }\n\n    int jump(int s, int t, int i) const {\n        assert(0\
    \ <= s and s < n);\n        assert(0 <= t and t < n);\n        assert(0 <= i);\n\
    \        if (tree_id[s] != tree_id[t]) return -1;\n        if (i == 0) return\
    \ s;\n        int p = lca(s, t), d = dep[s] + dep[t] - 2 * dep[p];\n        if\
    \ (d < i) return -1;\n        if (dep[s] - dep[p] >= i) return la(s, i);\n   \
    \     return la(t, d - i);\n    }\n\n    int distance(int u, int v) const {\n\
    \        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n      \
    \  assert(tree_id[u] == tree_id[v]);\n        return dep[u] + dep[v] - 2 * dep[lca(u,\
    \ v)];\n    }\n\n    template <typename F> void query_path(int u, int v, const\
    \ F& f, bool vertex = false) const {\n        assert(0 <= u and u < n);\n    \
    \    assert(0 <= v and v < n);\n        assert(tree_id[u] == tree_id[v]);\n  \
    \      int p = lca(u, v);\n        for (auto& e : ascend(u, p)) f(e.second, e.first\
    \ + 1);\n        if (vertex) f(vertex_id[p], vertex_id[p] + 1);\n        for (auto&\
    \ e : descend(p, v)) f(e.first, e.second + 1);\n    }\n\n    template <typename\
    \ F> void query_path_noncommutative(int u, int v, const F& f, bool vertex = false)\
    \ const {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n\
    \        assert(tree_id[u] == tree_id[v]);\n        int p = lca(u, v);\n     \
    \   for (auto& e : ascend(u, p)) f(e.first + 1, e.second);\n        if (vertex)\
    \ f(vertex_id[p], vertex_id[p] + 1);\n        for (auto& e : descend(p, v)) f(e.first,\
    \ e.second + 1);\n    }\n\n    template <typename F> void query_subtree(int u,\
    \ const F& f, bool vertex = false) const {\n        assert(0 <= u and u < n);\n\
    \        f(vertex_id[u] + !vertex, vertex_id[u] + sub[u]);\n    }\n\n    std::pair<std::unordered_map<int,\
    \ std::vector<int>>, int> auxiliary_tree(std::vector<int> vs) {\n        int len\
    \ = vs.size();\n        std::sort(vs.begin(), vs.end(), [&](int i, int j) { return\
    \ vertex_id[i] < vertex_id[j]; });\n        for (int i = 0; i + 1 < len; i++)\
    \ vs.emplace_back(lca(vs[i], vs[i + 1]));\n        std::sort(vs.begin(), vs.end(),\
    \ [&](int i, int j) { return vertex_id[i] < vertex_id[j]; });\n        vs.erase(std::unique(vs.begin(),\
    \ vs.end()), vs.end());\n        std::vector<int> st;\n        std::unordered_map<int,\
    \ std::vector<int>> res;\n        for (int v : vs) {\n            while (not st.empty()\
    \ and vertex_id[st.back()] + sub[st.back()] <= vertex_id[v]) st.pop_back();\n\
    \            if (not st.empty()) res[st.back()].emplace_back(v);\n           \
    \ st.emplace_back(v);\n        }\n        return {res, vs[0]};\n    }\n\n  private:\n\
    \    void dfs_sz(int v) {\n        sub[v] = 1;\n        if (!G[v].empty() and\
    \ G[v].front() == par[v]) std::swap(G[v].front(), G[v].back());\n        for (int&\
    \ u : G[v]) {\n            if (u == par[v]) continue;\n            par[u] = v;\n\
    \            dep[u] = dep[v] + 1;\n            dfs_sz(u);\n            sub[v]\
    \ += sub[u];\n            if (sub[u] > sub[G[v].front()]) std::swap(u, G[v].front());\n\
    \        }\n    }\n\n    void dfs_hld(int v, int tree_id_cur) {\n        vertex_id[v]\
    \ = time++;\n        tree_id[v] = tree_id_cur;\n        for (int& u : G[v]) {\n\
    \            if (u == par[v]) continue;\n            head[u] = (u == G[v][0] ?\
    \ head[v] : u);\n            dfs_hld(u, tree_id_cur);\n        }\n    }\n\n  \
    \  std::vector<std::pair<int, int>> ascend(int u, int v) const {  // [u, v), v\
    \ is ancestor of u\n        std::vector<std::pair<int, int>> res;\n        while\
    \ (head[u] != head[v]) {\n            res.emplace_back(vertex_id[u], vertex_id[head[u]]);\n\
    \            u = par[head[u]];\n        }\n        if (u != v) res.emplace_back(vertex_id[u],\
    \ vertex_id[v] + 1);\n        return res;\n    }\n\n    std::vector<std::pair<int,\
    \ int>> descend(int u, int v) const {  // (u, v], u is ancestor of v\n       \
    \ if (u == v) return {};\n        if (head[u] == head[v]) return {{vertex_id[u]\
    \ + 1, vertex_id[v]}};\n        auto res = descend(u, par[head[v]]);\n       \
    \ res.emplace_back(vertex_id[head[v]], vertex_id[v]);\n        return res;\n \
    \   }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2024-08-27 15:05:21+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/vertex_set_path_composite.test.cpp
  - test/yosupo/jump_on_tree.test.cpp
  - test/yosupo/vertex_add_path_sum.test.cpp
  - test/yosupo/vertex_add_subtree_sum.test.cpp
  - test/aoj/GRL_5_C.test.cpp
documentation_of: src/tree/HeavyLightDecomposition.hpp
layout: document
title: Heavy Light Decomposition
---

## 概要

木構造を分解する手法の一つで，部分木やパスに対する更新・取得処理を効率的に行うことができる．

以下に記す内容について，時間計算量は区間 $\lbrack l, r)$ に対する更新や総積の取得といった操作が 1 区間あたり $\mathrm{O}(\log n)$ で行えるとしたうえでの計算量である．
また，各種クエリ操作についての関数において頂点についての情報を得たい際には引数の `vertex` を `true` にする必要がある（デフォルトでは `false` になっているので辺に情報が乗ったクエリ操作を扱うことになる）．

空間計算量は $\mathrm{O}(n)$ である（ただし，定数倍は重い）．

| メンバ関数                                   | 効果                                                                           | 時間計算量                                                             |
| -------------------------------------------- | ------------------------------------------------------------------------------ | ---------------------------------------------------------------------- |
| `HeavyLightDecomposition(n)`                 | 頂点数 $n$ の木として初期化する．                                              | $\mathrm{O}(n)$                                                        |
| `add_edge(u, v)`                             | 辺 $(u,v)$ を追加する．                                                        | $\mathrm{O}(1)$                                                        |
| `build()`                                    | 追加された辺情報をもとに Heavy edge, Light edge の情報を構築する．             | $\mathrm{O}(n)$                                                        |
| `idx(v)`                                     | 内部処理における頂点 $v$ の識別子を返す．一点更新や一点取得の際に必要となる．  | $\mathrm{O}(1)$                                                        |
| `la(v,k)`                                    | $v$ から根の方向に $k$ 回辺を辿った先の頂点を返す．                            | $\mathrm{O}(\log n)$                                                   |
| `lca(u, v)`                                  | 頂点 $u, v$ の最小共通祖先を返す．                                             | $\mathrm{O}(\log n)$                                                   |
| `jump(s, t, i)`                              | 頂点 $s$ から $t$ への木上の最短路上で $s$ から距離 $i$ 離れた頂点を返す．     | $\mathrm{O}(\log n)$                                                   |
| `distance(u, v)`                             | `add_edge` で追加された各辺の重みを 1 として，頂点 $u, v$ 間の距離を返す．     | $\mathrm{O}(\log n)$                                                   |
| `query_path(u, v, f, vertex)`                | 頂点 $u, v$ 間のパスに対してのクエリを処理する（演算が可換である必要がある）． | $\mathrm{O}(\log^2 n)$                                                 |
| `query_path_noncommutative(u, v, f, vertex)` | 頂点 $u, v$ 間のパスに対してのクエリを処理する（下記注意参照）．               | $\mathrm{O}(\log^2 n)$                                                 |
| `query_subtree(u, f, vertex)`                | 頂点 $u$ の部分木に対してのクエリを処理する．                                  | $\mathrm{O}(\log n)$                                                   |
| `query_subtree(vs)`                          | 頂点集合 $\textit{vs}$ に対する auxiliary tree を構築し、その情報と根を返す。  | $\vert \textit{vs} \vert = k$ として $\mathrm{O}(k (\log k + \log n))$ |

任意に根を取り dfs していき，現在見ている頂点とその子供の中で最も部分木のサイズが大きい頂点とを結ぶ edge を Heavy，それ以外を Light と分類する．
このとき，任意の頂点について根との間のパス上の Light edge の本数を $\mathrm{O}(\log n)$ で抑えることができる（Light edge を辿るごとに，もとの木における部分木のサイズが半分未満になっていくため）．

dfs において Heavy edge から優先的に探索していくようにすると，Heavy path 上の頂点群は dfs-order において連続するようになり，ある頂点からその先祖の頂点までのパスを dfs-order 上の $\mathrm{O}(\log n)$ 個の区間に分割することができる．
任意の 2 頂点間のパスは lowest common ancestor を経由することで $\mathrm{O}(\log n)$ 個の区間に分割でき，パスに対するクエリを他の列を扱うデータ構造と併せて効率的に処理することができる．
また，1 頂点に対する操作は言うまでもなく，部分木に対する操作も任意の頂点の部分木内の頂点は dfs-order において 1 つの区間を成すことから容易に扱うことが可能である．
頂点及び辺のどちらについてのクエリにも対応しており，辺の場合は子孫側の頂点に値を載せるとして処理している．

## 注意
`query_path_noncommutative` を呼ぶ際には，付随するデータ構造もそれに対応しうるものである必要がある．具体的な要件としては，区間 $[l, r)$ に対して演算が左結合か右結合かを区別して正しく処理できなければならない．逆に言えば左結合か右結合かだけが重要なので，それぞれを処理する 2 つのデータ構造を用意することで解決することも可能である．

## 出題例
- [Codeforces Round #299 (Div. 1) E. Tavas on the Path](https://codeforces.com/contest/536/problem/E)
  - `query_path_noncommutative` の辺属性クエリの verify．
- [Codeforces Round #285 (Div. 1) E. Misha and LCP on Tree](https://codeforces.com/contest/504/problem/E)
- [AtCoder Beginner Contest 269 Ex - Antichain](https://atcoder.jp/contests/abc269/tasks/abc269_h)
  - heavy path 上の分割統治を適切にまとめていくことで解ける．各 heavy path の先頭の頂点の部分木の大きさの総和が $\mathrm{O}(N \log N)$ であること等を利用する．
- [Hokkaido University Competitive Programming Camp 2023 Day 1 G: Detour](https://onlinejudge.u-aizu.ac.jp/beta/room.html#HUPC2023Day1/problems/G)
- [AtCoder Beginner Contest 311 Ex - Many Illumination Plans](https://atcoder.jp/contests/abc311/tasks/abc311_h)
  - 重軽再帰動的計画法（[参照](https://qiita.com/tmaehara/items/4b2735e56843bad89949)）

## Links
- [Easiest HLD with subtree queries - Codeforces](https://codeforces.com/blog/entry/53170)
- [Heavy-Light Decomposition - math314のブログ](https://math314.hateblo.jp/entry/2014/06/24/220107)
- [マージテクと高さ $\mathrm{O}(\log n)$ のマージ過程との融合 \| Mathenachia](https://www.mathenachia.blog/mergetech-and-logn/#toc4)
