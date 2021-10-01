---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667.test.cpp
    title: test/aoj/2667.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp
    title: test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
    title: test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
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
    _deprecated_at_docs: docs/tree/HeavyLightDecomposition.md
    document_title: Heavy Light Decomposition
    links: []
  bundledCode: "#line 2 \"tree/HeavyLightDecomposition.hpp\"\n#include <cassert>\n\
    #include <utility>\n#include <vector>\n\nstruct HeavyLightDecomposition {\n  \
    \  std::vector<std::vector<int>> G;  // child of vertex v on heavy edge is G[v].front()\
    \ if it is not parent of v\n\n    HeavyLightDecomposition(int n)\n        : G(n),\n\
    \          n(n),\n          time(0),\n          par(n, -1),\n          sub(n),\n\
    \          dep(n, 0),\n          head(n),\n          tree_id(n, -1),\n       \
    \   vertex_id(n, -1),\n          vertex_id_inv(n) {}\n    void add_edge(int u,\
    \ int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n\
    \        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n\n    void\
    \ build(std::vector<int> roots = {0}) {\n        int tree_id_cur = 0;\n      \
    \  for (int& r : roots) {\n            assert(0 <= r && r < n);\n            dfs_sz(r);\n\
    \            head[r] = r;\n            dfs_hld(r, tree_id_cur++);\n        }\n\
    \        assert(time == n);\n        for (int v = 0; v < n; v++) vertex_id_inv[vertex_id[v]]\
    \ = v;\n    }\n\n    int idx(int v) const { return vertex_id[v]; }\n\n    int\
    \ la(int v, int k) {\n        assert(0 <= v && v < n);\n        assert(0 <= k\
    \ && k <= dep[v]);\n        while (1) {\n            int u = head[v];\n      \
    \      if (vertex_id[v] - k >= vertex_id[u]) return vertex_id_inv[vertex_id[v]\
    \ - k];\n            k -= vertex_id[v] - vertex_id[u] + 1;\n            v = par[u];\n\
    \        }\n    }\n\n    int lca(int u, int v) const {\n        assert(0 <= u\
    \ && u < n);\n        assert(0 <= v && v < n);\n        assert(tree_id[u] == tree_id[v]);\n\
    \        for (;; v = par[head[v]]) {\n            if (vertex_id[u] > vertex_id[v])\
    \ std::swap(u, v);\n            if (head[u] == head[v]) return u;\n        }\n\
    \    }\n\n    int distance(int u, int v) const {\n        assert(0 <= u && u <\
    \ n);\n        assert(0 <= v && v < n);\n        assert(tree_id[u] == tree_id[v]);\n\
    \        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n\n    template <typename\
    \ F> void query_path(int u, int v, const F& f, bool vertex = false) const {\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        assert(tree_id[u]\
    \ == tree_id[v]);\n        int p = lca(u, v);\n        for (auto& e : ascend(u,\
    \ p)) f(e.second, e.first + 1);\n        if (vertex) f(vertex_id[p], vertex_id[p]\
    \ + 1);\n        for (auto& e : descend(p, v)) f(e.first, e.second + 1);\n   \
    \ }\n\n    template <typename F> void query_path_noncommutative(int u, int v,\
    \ const F& f, bool vertex = false) const {\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        assert(tree_id[u] == tree_id[v]);\n\
    \        int p = lca(u, v);\n        for (auto& e : ascend(u, p)) f(e.first +\
    \ 1, e.second);\n        if (vertex) f(vertex_id[p], vertex_id[p] + 1);\n    \
    \    for (auto& e : descend(p, v)) f(e.first, e.second + 1);\n    }\n\n    template\
    \ <typename F> void query_subtree(int u, const F& f, bool vertex = false) const\
    \ {\n        assert(0 <= u && u < n);\n        f(vertex_id[u] + !vertex, vertex_id[u]\
    \ + sub[u]);\n    }\n\nprivate:\n    int n, time;\n    std::vector<int> par, \
    \ // parent of vertex v\n        sub,               // size of subtree whose root\
    \ is v\n        dep,               // distance bitween root and vertex v\n   \
    \     head,              // vertex that is the nearest to root on heavy path of\
    \ vertex v\n        tree_id,           // id of tree vertex v belongs to\n   \
    \     vertex_id,         // id of vertex v (consecutive on heavy paths)\n    \
    \    vertex_id_inv;     // vertex_id_inv[vertex_id[v]] = v\n\n    void dfs_sz(int\
    \ v) {\n        sub[v] = 1;\n        if (!G[v].empty() && G[v].front() == par[v])\
    \ std::swap(G[v].front(), G[v].back());\n        for (int& u : G[v]) {\n     \
    \       if (u == par[v]) continue;\n            par[u] = v;\n            dep[u]\
    \ = dep[v] + 1;\n            dfs_sz(u);\n            sub[v] += sub[u];\n     \
    \       if (sub[u] > sub[G[v].front()]) std::swap(u, G[v].front());\n        }\n\
    \    }\n\n    void dfs_hld(int v, int tree_id_cur) {\n        vertex_id[v] = time++;\n\
    \        tree_id[v] = tree_id_cur;\n        for (int& u : G[v]) {\n          \
    \  if (u == par[v]) continue;\n            head[u] = (u == G[v][0] ? head[v] :\
    \ u);\n            dfs_hld(u, tree_id_cur);\n        }\n    }\n\n    std::vector<std::pair<int,\
    \ int>> ascend(int u, int v) const {  // [u, v), v is ancestor of u\n        std::vector<std::pair<int,\
    \ int>> res;\n        while (head[u] != head[v]) {\n            res.emplace_back(vertex_id[u],\
    \ vertex_id[head[u]]);\n            u = par[head[u]];\n        }\n        if (u\
    \ != v) res.emplace_back(vertex_id[u], vertex_id[v] + 1);\n        return res;\n\
    \    }\n\n    std::vector<std::pair<int, int>> descend(int u, int v) const { \
    \ // (u, v], u is ancestor of v\n        if (u == v) return {};\n        if (head[u]\
    \ == head[v]) return {{vertex_id[u] + 1, vertex_id[v]}};\n        auto res = descend(u,\
    \ par[head[v]]);\n        res.emplace_back(vertex_id[head[v]], vertex_id[v]);\n\
    \        return res;\n    }\n};\n\n/**\n * @brief Heavy Light Decomposition\n\
    \ * @docs docs/tree/HeavyLightDecomposition.md\n */\n"
  code: "#pragma once\n#include <cassert>\n#include <utility>\n#include <vector>\n\
    \nstruct HeavyLightDecomposition {\n    std::vector<std::vector<int>> G;  // child\
    \ of vertex v on heavy edge is G[v].front() if it is not parent of v\n\n    HeavyLightDecomposition(int\
    \ n)\n        : G(n),\n          n(n),\n          time(0),\n          par(n, -1),\n\
    \          sub(n),\n          dep(n, 0),\n          head(n),\n          tree_id(n,\
    \ -1),\n          vertex_id(n, -1),\n          vertex_id_inv(n) {}\n    void add_edge(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n\n\
    \    void build(std::vector<int> roots = {0}) {\n        int tree_id_cur = 0;\n\
    \        for (int& r : roots) {\n            assert(0 <= r && r < n);\n      \
    \      dfs_sz(r);\n            head[r] = r;\n            dfs_hld(r, tree_id_cur++);\n\
    \        }\n        assert(time == n);\n        for (int v = 0; v < n; v++) vertex_id_inv[vertex_id[v]]\
    \ = v;\n    }\n\n    int idx(int v) const { return vertex_id[v]; }\n\n    int\
    \ la(int v, int k) {\n        assert(0 <= v && v < n);\n        assert(0 <= k\
    \ && k <= dep[v]);\n        while (1) {\n            int u = head[v];\n      \
    \      if (vertex_id[v] - k >= vertex_id[u]) return vertex_id_inv[vertex_id[v]\
    \ - k];\n            k -= vertex_id[v] - vertex_id[u] + 1;\n            v = par[u];\n\
    \        }\n    }\n\n    int lca(int u, int v) const {\n        assert(0 <= u\
    \ && u < n);\n        assert(0 <= v && v < n);\n        assert(tree_id[u] == tree_id[v]);\n\
    \        for (;; v = par[head[v]]) {\n            if (vertex_id[u] > vertex_id[v])\
    \ std::swap(u, v);\n            if (head[u] == head[v]) return u;\n        }\n\
    \    }\n\n    int distance(int u, int v) const {\n        assert(0 <= u && u <\
    \ n);\n        assert(0 <= v && v < n);\n        assert(tree_id[u] == tree_id[v]);\n\
    \        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n\n    template <typename\
    \ F> void query_path(int u, int v, const F& f, bool vertex = false) const {\n\
    \        assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        assert(tree_id[u]\
    \ == tree_id[v]);\n        int p = lca(u, v);\n        for (auto& e : ascend(u,\
    \ p)) f(e.second, e.first + 1);\n        if (vertex) f(vertex_id[p], vertex_id[p]\
    \ + 1);\n        for (auto& e : descend(p, v)) f(e.first, e.second + 1);\n   \
    \ }\n\n    template <typename F> void query_path_noncommutative(int u, int v,\
    \ const F& f, bool vertex = false) const {\n        assert(0 <= u && u < n);\n\
    \        assert(0 <= v && v < n);\n        assert(tree_id[u] == tree_id[v]);\n\
    \        int p = lca(u, v);\n        for (auto& e : ascend(u, p)) f(e.first +\
    \ 1, e.second);\n        if (vertex) f(vertex_id[p], vertex_id[p] + 1);\n    \
    \    for (auto& e : descend(p, v)) f(e.first, e.second + 1);\n    }\n\n    template\
    \ <typename F> void query_subtree(int u, const F& f, bool vertex = false) const\
    \ {\n        assert(0 <= u && u < n);\n        f(vertex_id[u] + !vertex, vertex_id[u]\
    \ + sub[u]);\n    }\n\nprivate:\n    int n, time;\n    std::vector<int> par, \
    \ // parent of vertex v\n        sub,               // size of subtree whose root\
    \ is v\n        dep,               // distance bitween root and vertex v\n   \
    \     head,              // vertex that is the nearest to root on heavy path of\
    \ vertex v\n        tree_id,           // id of tree vertex v belongs to\n   \
    \     vertex_id,         // id of vertex v (consecutive on heavy paths)\n    \
    \    vertex_id_inv;     // vertex_id_inv[vertex_id[v]] = v\n\n    void dfs_sz(int\
    \ v) {\n        sub[v] = 1;\n        if (!G[v].empty() && G[v].front() == par[v])\
    \ std::swap(G[v].front(), G[v].back());\n        for (int& u : G[v]) {\n     \
    \       if (u == par[v]) continue;\n            par[u] = v;\n            dep[u]\
    \ = dep[v] + 1;\n            dfs_sz(u);\n            sub[v] += sub[u];\n     \
    \       if (sub[u] > sub[G[v].front()]) std::swap(u, G[v].front());\n        }\n\
    \    }\n\n    void dfs_hld(int v, int tree_id_cur) {\n        vertex_id[v] = time++;\n\
    \        tree_id[v] = tree_id_cur;\n        for (int& u : G[v]) {\n          \
    \  if (u == par[v]) continue;\n            head[u] = (u == G[v][0] ? head[v] :\
    \ u);\n            dfs_hld(u, tree_id_cur);\n        }\n    }\n\n    std::vector<std::pair<int,\
    \ int>> ascend(int u, int v) const {  // [u, v), v is ancestor of u\n        std::vector<std::pair<int,\
    \ int>> res;\n        while (head[u] != head[v]) {\n            res.emplace_back(vertex_id[u],\
    \ vertex_id[head[u]]);\n            u = par[head[u]];\n        }\n        if (u\
    \ != v) res.emplace_back(vertex_id[u], vertex_id[v] + 1);\n        return res;\n\
    \    }\n\n    std::vector<std::pair<int, int>> descend(int u, int v) const { \
    \ // (u, v], u is ancestor of v\n        if (u == v) return {};\n        if (head[u]\
    \ == head[v]) return {{vertex_id[u] + 1, vertex_id[v]}};\n        auto res = descend(u,\
    \ par[head[v]]);\n        res.emplace_back(vertex_id[head[v]], vertex_id[v]);\n\
    \        return res;\n    }\n};\n\n/**\n * @brief Heavy Light Decomposition\n\
    \ * @docs docs/tree/HeavyLightDecomposition.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: tree/HeavyLightDecomposition.hpp
  requiredBy: []
  timestamp: '2021-10-01 11:32:51+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2667.test.cpp
  - test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
  - test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp
  - test/yosupo/vertex_add_subtree_sum.test.cpp
  - test/yosupo/vertex_add_path_sum.test.cpp
  - test/yosupo/vertex_set_path_composite.test.cpp
documentation_of: tree/HeavyLightDecomposition.hpp
layout: document
redirect_from:
- /library/tree/HeavyLightDecomposition.hpp
- /library/tree/HeavyLightDecomposition.hpp.html
title: Heavy Light Decomposition
---
## 概要
木構造を分解する手法の一つ. 各 edge を Heavy と Light の 2 種類に分けて, Heavy な edge で繋がれた頂点群を一つにまとめるとみなして新たな木を構築すると, 任意の頂点の深さを高々 $O(\log n)$ で抑えることができ (子供の方向に向かって辺を辿るごとに, もとの木における部分木のサイズが半分未満になっていくため) , もとの木でのパスや部分木に対するクエリを効率的に処理することができる. 現在見ている頂点と結ばれている子供の中で最も部分木のサイズが大きい頂点とを結ぶ edge を Heavy, それ以外を Light と分類している. 頂点及び辺のどちらについてのクエリについても対応しており, 辺の場合は子孫側の頂点に値を載せるとして処理している.

以下に記す内容について, 時間計算量は区間 $[l,r)$ に対する更新や総積の取得といった操作が 1 区間あたり $O(\log n)$ で行えるとしたうえでの計算量である. また, 各種クエリ操作についての関数において頂点についての情報を得たい際には引数の `vertex` を `true` にする必要がある (デフォルトでは `false` になっているので辺についてのクエリ操作を扱うことになる) .

| メンバ関数                                   | 効果                                                                                                      | 時間計算量      |
| -------------------------------------------- | --------------------------------------------------------------------------------------------------------- | --------------- |
| `HeavyLightDecomposition(n)`                 | 頂点数 $n$ の木として初期化する.                                                                          | $O(n)$          |
| `add_edge(u, v)`                             | 辺 $(u,v)$ を追加する.                                                                                    | $O(1)$          |
| `build()`                                    | 追加された辺情報をもとに Heavy edge, Light edge の情報を構築する.                                         | $O(n)$          |
| `idx(v)`                                     | 内部処理における頂点 $v$ の識別子を返す. 一点更新や一点取得の際に必要となる.                              | $O(1)$          |
| `la(v,k)`                                    | $v$ から根の方向に $k$ 回辺を辿った先の頂点を返す.                                                        | $O(\log n)$     |
| `lca(u, v)`                                  | 頂点 $u, v$ の最小共通祖先を返す.                                                                         | $O(\log n)$     |
| `distance(u, v)`                             | `add_edge` で追加された各辺の重みを 1 として, 頂点 $u, v$ 間の距離を返す.                                 | $O(\log n)$     |
| `query_path(u, v, f, vertex)`                | 頂点 $u, v$ 間のパスに対してのクエリを処理する (演算が可換, すなわち扱う対象がモノイドである必要がある) . | $O((\log n)^2)$ |
| `query_path_noncommutative(u, v, f, vertex)` | 頂点 $u, v$ 間のパスに対してのクエリを処理する (Remark 参照) .                                            | $O((\log n)^2)$ |
| `query_subtree(u, f, vertex)`                | 頂点 $u$ の部分木に対してのクエリを処理する.                                                              | $O(\log n)$     |

#### Remark
`query_path_noncommutative` を呼ぶ際には, 付随するデータ構造もそれに対応しうるものである必要がある. 具体的な要件としては, 区間 $[l,r)$ に対して演算が左結合か右結合かを区別して正しく処理できなければならない. 逆に言えば左結合か右結合かだけが重要なので, それぞれを処理する 2 つのデータ構造を用意することで解決することも可能である.

## Links
- [Easiest HLD with subtree queries - Codeforces](https://codeforces.com/blog/entry/53170)
- [Heavy-Light Decomposition - math314のブログ](https://math314.hateblo.jp/entry/2014/06/24/220107)
