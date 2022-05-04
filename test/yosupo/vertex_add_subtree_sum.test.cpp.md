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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo/vertex_add_subtree_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#include <iostream>\n\
    #line 1 \"atcoder/fenwicktree.hpp\"\n\n\n\n#include <cassert>\n#include <vector>\n\
    \n#line 1 \"atcoder/internal_type_traits.hpp\"\n\n\n\n#line 5 \"atcoder/internal_type_traits.hpp\"\
    \n#include <numeric>\n#include <type_traits>\n\nnamespace atcoder {\n\nnamespace\
    \ internal {\n\n#ifndef _MSC_VER\ntemplate <class T>\nusing is_signed_int128 =\n\
    \    typename std::conditional<std::is_same<T, __int128_t>::value ||\n       \
    \                           std::is_same<T, __int128>::value,\n              \
    \                std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing is_unsigned_int128 =\n    typename std::conditional<std::is_same<T,\
    \ __uint128_t>::value ||\n                                  std::is_same<T, unsigned\
    \ __int128>::value,\n                              std::true_type,\n         \
    \                     std::false_type>::type;\n\ntemplate <class T>\nusing make_unsigned_int128\
    \ =\n    typename std::conditional<std::is_same<T, __int128_t>::value,\n     \
    \                         __uint128_t,\n                              unsigned\
    \ __int128>;\n\ntemplate <class T>\nusing is_integral = typename std::conditional<std::is_integral<T>::value\
    \ ||\n                                                  is_signed_int128<T>::value\
    \ ||\n                                                  is_unsigned_int128<T>::value,\n\
    \                                              std::true_type,\n             \
    \                                 std::false_type>::type;\n\ntemplate <class T>\n\
    using is_signed_int = typename std::conditional<(is_integral<T>::value &&\n  \
    \                                               std::is_signed<T>::value) ||\n\
    \                                                    is_signed_int128<T>::value,\n\
    \                                                std::true_type,\n           \
    \                                     std::false_type>::type;\n\ntemplate <class\
    \ T>\nusing is_unsigned_int =\n    typename std::conditional<(is_integral<T>::value\
    \ &&\n                               std::is_unsigned<T>::value) ||\n        \
    \                          is_unsigned_int128<T>::value,\n                   \
    \           std::true_type,\n                              std::false_type>::type;\n\
    \ntemplate <class T>\nusing to_unsigned = typename std::conditional<\n    is_signed_int128<T>::value,\n\
    \    make_unsigned_int128<T>,\n    typename std::conditional<std::is_signed<T>::value,\n\
    \                              std::make_unsigned<T>,\n                      \
    \        std::common_type<T>>::type>::type;\n\n#else\n\ntemplate <class T> using\
    \ is_integral = typename std::is_integral<T>;\n\ntemplate <class T>\nusing is_signed_int\
    \ =\n    typename std::conditional<is_integral<T>::value && std::is_signed<T>::value,\n\
    \                              std::true_type,\n                             \
    \ std::false_type>::type;\n\ntemplate <class T>\nusing is_unsigned_int =\n   \
    \ typename std::conditional<is_integral<T>::value &&\n                       \
    \           std::is_unsigned<T>::value,\n                              std::true_type,\n\
    \                              std::false_type>::type;\n\ntemplate <class T>\n\
    using to_unsigned = typename std::conditional<is_signed_int<T>::value,\n     \
    \                                         std::make_unsigned<T>,\n           \
    \                                   std::common_type<T>>::type;\n\n#endif\n\n\
    template <class T>\nusing is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;\n\
    \ntemplate <class T>\nusing is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;\n\
    \ntemplate <class T> using to_unsigned_t = typename to_unsigned<T>::type;\n\n\
    }  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 8 \"atcoder/fenwicktree.hpp\"\
    \n\nnamespace atcoder {\n\n// Reference: https://en.wikipedia.org/wiki/Fenwick_tree\n\
    template <class T> struct fenwick_tree {\n    using U = internal::to_unsigned_t<T>;\n\
    \n  public:\n    fenwick_tree() : _n(0) {}\n    explicit fenwick_tree(int n) :\
    \ _n(n), data(n) {}\n\n    void add(int p, T x) {\n        assert(0 <= p && p\
    \ < _n);\n        p++;\n        while (p <= _n) {\n            data[p - 1] +=\
    \ U(x);\n            p += p & -p;\n        }\n    }\n\n    T sum(int l, int r)\
    \ {\n        assert(0 <= l && l <= r && r <= _n);\n        return sum(r) - sum(l);\n\
    \    }\n\n  private:\n    int _n;\n    std::vector<U> data;\n\n    U sum(int r)\
    \ {\n        U s = 0;\n        while (r > 0) {\n            s += data[r - 1];\n\
    \            r -= r & -r;\n        }\n        return s;\n    }\n};\n\n}  // namespace\
    \ atcoder\n\n\n#line 3 \"tree/HeavyLightDecomposition.hpp\"\n#include <utility>\n\
    #line 5 \"tree/HeavyLightDecomposition.hpp\"\n\nstruct HeavyLightDecomposition\
    \ {\n    std::vector<std::vector<int>> G;  // child of vertex v on heavy edge\
    \ is G[v].front() if it is not parent of v\n    int n, time;\n    std::vector<int>\
    \ par,  // parent of vertex v\n        sub,               // size of subtree whose\
    \ root is v\n        dep,               // distance bitween root and vertex v\n\
    \        head,              // vertex that is the nearest to root on heavy path\
    \ of vertex v\n        tree_id,           // id of tree vertex v belongs to\n\
    \        vertex_id,         // id of vertex v (consecutive on heavy paths)\n \
    \       vertex_id_inv;     // vertex_id_inv[vertex_id[v]] = v\n\n    HeavyLightDecomposition(int\
    \ n)\n        : G(n),\n          n(n),\n          time(0),\n          par(n, -1),\n\
    \          sub(n),\n          dep(n, 0),\n          head(n),\n          tree_id(n,\
    \ -1),\n          vertex_id(n, -1),\n          vertex_id_inv(n) {}\n\n    void\
    \ add_edge(int u, int v) {\n        assert(0 <= u && u < n);\n        assert(0\
    \ <= v && v < n);\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n\n    void build(std::vector<int> roots = {0}) {\n        int tree_id_cur\
    \ = 0;\n        for (int& r : roots) {\n            assert(0 <= r && r < n);\n\
    \            dfs_sz(r);\n            head[r] = r;\n            dfs_hld(r, tree_id_cur++);\n\
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
    \ + sub[u]);\n    }\n\nprivate:\n    void dfs_sz(int v) {\n        sub[v] = 1;\n\
    \        if (!G[v].empty() && G[v].front() == par[v]) std::swap(G[v].front(),\
    \ G[v].back());\n        for (int& u : G[v]) {\n            if (u == par[v]) continue;\n\
    \            par[u] = v;\n            dep[u] = dep[v] + 1;\n            dfs_sz(u);\n\
    \            sub[v] += sub[u];\n            if (sub[u] > sub[G[v].front()]) std::swap(u,\
    \ G[v].front());\n        }\n    }\n\n    void dfs_hld(int v, int tree_id_cur)\
    \ {\n        vertex_id[v] = time++;\n        tree_id[v] = tree_id_cur;\n     \
    \   for (int& u : G[v]) {\n            if (u == par[v]) continue;\n          \
    \  head[u] = (u == G[v][0] ? head[v] : u);\n            dfs_hld(u, tree_id_cur);\n\
    \        }\n    }\n\n    std::vector<std::pair<int, int>> ascend(int u, int v)\
    \ const {  // [u, v), v is ancestor of u\n        std::vector<std::pair<int, int>>\
    \ res;\n        while (head[u] != head[v]) {\n            res.emplace_back(vertex_id[u],\
    \ vertex_id[head[u]]);\n            u = par[head[u]];\n        }\n        if (u\
    \ != v) res.emplace_back(vertex_id[u], vertex_id[v] + 1);\n        return res;\n\
    \    }\n\n    std::vector<std::pair<int, int>> descend(int u, int v) const { \
    \ // (u, v], u is ancestor of v\n        if (u == v) return {};\n        if (head[u]\
    \ == head[v]) return {{vertex_id[u] + 1, vertex_id[v]}};\n        auto res = descend(u,\
    \ par[head[v]]);\n        res.emplace_back(vertex_id[head[v]], vertex_id[v]);\n\
    \        return res;\n    }\n};\n#line 6 \"test/yosupo/vertex_add_subtree_sum.test.cpp\"\
    \n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int> a(N);\n    for (int\
    \ i = 0; i < N; i++) std::cin >> a[i];\n    HeavyLightDecomposition HLD(N);\n\
    \    for (int i = 1; i < N; i++) {\n        int p;\n        std::cin >> p;\n \
    \       HLD.add_edge(p, i);\n    }\n    HLD.build();\n\n    atcoder::fenwick_tree<long\
    \ long> FT(N);\n    for (int i = 0; i < N; i++) FT.add(HLD.idx(i), a[i]);\n\n\
    \    for (; Q--;) {\n        int t, u;\n        std::cin >> t >> u;\n        if\
    \ (!t) {\n            int x;\n            std::cin >> x;\n            FT.add(HLD.idx(u),\
    \ x);\n        } else {\n            long long ans = 0;\n            auto q =\
    \ [&](int l, int r) { ans += FT.sum(l, r); };\n            HLD.query_subtree(u,\
    \ q, true);\n            std::cout << ans << '\\n';\n        }\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include <iostream>\n#include \"atcoder/fenwicktree\"\n#include \"tree/HeavyLightDecomposition.hpp\"\
    \n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int> a(N);\n    for (int\
    \ i = 0; i < N; i++) std::cin >> a[i];\n    HeavyLightDecomposition HLD(N);\n\
    \    for (int i = 1; i < N; i++) {\n        int p;\n        std::cin >> p;\n \
    \       HLD.add_edge(p, i);\n    }\n    HLD.build();\n\n    atcoder::fenwick_tree<long\
    \ long> FT(N);\n    for (int i = 0; i < N; i++) FT.add(HLD.idx(i), a[i]);\n\n\
    \    for (; Q--;) {\n        int t, u;\n        std::cin >> t >> u;\n        if\
    \ (!t) {\n            int x;\n            std::cin >> x;\n            FT.add(HLD.idx(u),\
    \ x);\n        } else {\n            long long ans = 0;\n            auto q =\
    \ [&](int l, int r) { ans += FT.sum(l, r); };\n            HLD.query_subtree(u,\
    \ q, true);\n            std::cout << ans << '\\n';\n        }\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2022-05-04 22:30:20+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_subtree_sum.test.cpp
- /verify/test/yosupo/vertex_add_subtree_sum.test.cpp.html
title: test/yosupo/vertex_add_subtree_sum.test.cpp
---
