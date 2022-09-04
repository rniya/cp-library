---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/jump_on_tree
    links:
    - https://judge.yosupo.jp/problem/jump_on_tree
  bundledCode: "#line 1 \"test/yosupo/jump_on_tree.test.cpp\"\n#define PROBLEM \"\
    https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#include <iostream>\n#line 2\
    \ \"tree/HeavyLightDecomposition.hpp\"\n#include <cassert>\n#include <utility>\n\
    #include <vector>\n\nstruct HeavyLightDecomposition {\n    std::vector<std::vector<int>>\
    \ G;  // child of vertex v on heavy edge is G[v].front() if it is not parent of\
    \ v\n    int n, time;\n    std::vector<int> par,  // parent of vertex v\n    \
    \    sub,               // size of subtree whose root is v\n        dep,     \
    \          // distance bitween root and vertex v\n        head,              //\
    \ vertex that is the nearest to root on heavy path of vertex v\n        tree_id,\
    \           // id of tree vertex v belongs to\n        vertex_id,         // id\
    \ of vertex v (consecutive on heavy paths)\n        vertex_id_inv;     // vertex_id_inv[vertex_id[v]]\
    \ = v\n\n    HeavyLightDecomposition(int n)\n        : G(n),\n          n(n),\n\
    \          time(0),\n          par(n, -1),\n          sub(n),\n          dep(n,\
    \ 0),\n          head(n),\n          tree_id(n, -1),\n          vertex_id(n, -1),\n\
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
    \        f(vertex_id[u] + !vertex, vertex_id[u] + sub[u]);\n    }\n\nprivate:\n\
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
    \   }\n};\n#line 5 \"test/yosupo/jump_on_tree.test.cpp\"\n\nint main() {\n   \
    \ std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    int N, Q;\n   \
    \ std::cin >> N >> Q;\n    HeavyLightDecomposition HLD(N);\n    for (int i = 0;\
    \ i < N - 1; i++) {\n        int a, b;\n        std::cin >> a >> b;\n        HLD.add_edge(a,\
    \ b);\n    }\n\n    HLD.build();\n    for (; Q--;) {\n        int s, t, i;\n \
    \       std::cin >> s >> t >> i;\n        std::cout << HLD.jump(s, t, i) << '\\\
    n';\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#include\
    \ <iostream>\n#include \"tree/HeavyLightDecomposition.hpp\"\n\nint main() {\n\
    \    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    int N, Q;\n\
    \    std::cin >> N >> Q;\n    HeavyLightDecomposition HLD(N);\n    for (int i\
    \ = 0; i < N - 1; i++) {\n        int a, b;\n        std::cin >> a >> b;\n   \
    \     HLD.add_edge(a, b);\n    }\n\n    HLD.build();\n    for (; Q--;) {\n   \
    \     int s, t, i;\n        std::cin >> s >> t >> i;\n        std::cout << HLD.jump(s,\
    \ t, i) << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/yosupo/jump_on_tree.test.cpp
  requiredBy: []
  timestamp: '2022-09-04 18:06:09+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/jump_on_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/jump_on_tree.test.cpp
- /verify/test/yosupo/jump_on_tree.test.cpp.html
title: test/yosupo/jump_on_tree.test.cpp
---
