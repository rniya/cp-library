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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "#line 1 \"test/yosupo/vertex_add_path_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#include <iostream>\n\
    #line 1 \"atcoder/segtree.hpp\"\n\n\n\n#include <algorithm>\n#include <cassert>\n\
    #include <vector>\n\n#line 1 \"atcoder/internal_bit.hpp\"\n\n\n\n#ifdef _MSC_VER\n\
    #include <intrin.h>\n#endif\n\nnamespace atcoder {\n\nnamespace internal {\n\n\
    // @param n `0 <= n`\n// @return minimum non-negative `x` s.t. `n <= 2**x`\nint\
    \ ceil_pow2(int n) {\n    int x = 0;\n    while ((1U << x) < (unsigned int)(n))\
    \ x++;\n    return x;\n}\n\n// @param n `1 <= n`\n// @return minimum non-negative\
    \ `x` s.t. `(n & (1 << x)) != 0`\nconstexpr int bsf_constexpr(unsigned int n)\
    \ {\n    int x = 0;\n    while (!(n & (1 << x))) x++;\n    return x;\n}\n\n//\
    \ @param n `1 <= n`\n// @return minimum non-negative `x` s.t. `(n & (1 << x))\
    \ != 0`\nint bsf(unsigned int n) {\n#ifdef _MSC_VER\n    unsigned long index;\n\
    \    _BitScanForward(&index, n);\n    return index;\n#else\n    return __builtin_ctz(n);\n\
    #endif\n}\n\n}  // namespace internal\n\n}  // namespace atcoder\n\n\n#line 9\
    \ \"atcoder/segtree.hpp\"\n\nnamespace atcoder {\n\ntemplate <class S, S (*op)(S,\
    \ S), S (*e)()> struct segtree {\n  public:\n    segtree() : segtree(0) {}\n \
    \   explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}\n    explicit\
    \ segtree(const std::vector<S>& v) : _n(int(v.size())) {\n        log = internal::ceil_pow2(_n);\n\
    \        size = 1 << log;\n        d = std::vector<S>(2 * size, e());\n      \
    \  for (int i = 0; i < _n; i++) d[size + i] = v[i];\n        for (int i = size\
    \ - 1; i >= 1; i--) {\n            update(i);\n        }\n    }\n\n    void set(int\
    \ p, S x) {\n        assert(0 <= p && p < _n);\n        p += size;\n        d[p]\
    \ = x;\n        for (int i = 1; i <= log; i++) update(p >> i);\n    }\n\n    S\
    \ get(int p) const {\n        assert(0 <= p && p < _n);\n        return d[p +\
    \ size];\n    }\n\n    S prod(int l, int r) const {\n        assert(0 <= l &&\
    \ l <= r && r <= _n);\n        S sml = e(), smr = e();\n        l += size;\n \
    \       r += size;\n\n        while (l < r) {\n            if (l & 1) sml = op(sml,\
    \ d[l++]);\n            if (r & 1) smr = op(d[--r], smr);\n            l >>= 1;\n\
    \            r >>= 1;\n        }\n        return op(sml, smr);\n    }\n\n    S\
    \ all_prod() const { return d[1]; }\n\n    template <bool (*f)(S)> int max_right(int\
    \ l) const {\n        return max_right(l, [](S x) { return f(x); });\n    }\n\
    \    template <class F> int max_right(int l, F f) const {\n        assert(0 <=\
    \ l && l <= _n);\n        assert(f(e()));\n        if (l == _n) return _n;\n \
    \       l += size;\n        S sm = e();\n        do {\n            while (l %\
    \ 2 == 0) l >>= 1;\n            if (!f(op(sm, d[l]))) {\n                while\
    \ (l < size) {\n                    l = (2 * l);\n                    if (f(op(sm,\
    \ d[l]))) {\n                        sm = op(sm, d[l]);\n                    \
    \    l++;\n                    }\n                }\n                return l\
    \ - size;\n            }\n            sm = op(sm, d[l]);\n            l++;\n \
    \       } while ((l & -l) != l);\n        return _n;\n    }\n\n    template <bool\
    \ (*f)(S)> int min_left(int r) const {\n        return min_left(r, [](S x) { return\
    \ f(x); });\n    }\n    template <class F> int min_left(int r, F f) const {\n\
    \        assert(0 <= r && r <= _n);\n        assert(f(e()));\n        if (r ==\
    \ 0) return 0;\n        r += size;\n        S sm = e();\n        do {\n      \
    \      r--;\n            while (r > 1 && (r % 2)) r >>= 1;\n            if (!f(op(d[r],\
    \ sm))) {\n                while (r < size) {\n                    r = (2 * r\
    \ + 1);\n                    if (f(op(d[r], sm))) {\n                        sm\
    \ = op(d[r], sm);\n                        r--;\n                    }\n     \
    \           }\n                return r + 1 - size;\n            }\n         \
    \   sm = op(d[r], sm);\n        } while ((r & -r) != r);\n        return 0;\n\
    \    }\n\n  private:\n    int _n, size, log;\n    std::vector<S> d;\n\n    void\
    \ update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }\n};\n\n}  // namespace\
    \ atcoder\n\n\n#line 3 \"tree/HeavyLightDecomposition.hpp\"\n#include <utility>\n\
    #line 5 \"tree/HeavyLightDecomposition.hpp\"\n\nstruct HeavyLightDecomposition\
    \ {\n    std::vector<std::vector<int>> G;  // child of vertex v on heavy edge\
    \ is G[v].front() if it is not parent of v\n\n    HeavyLightDecomposition(int\
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
    \        return res;\n    }\n};\n#line 6 \"test/yosupo/vertex_add_path_sum.test.cpp\"\
    \n\nlong long op(long long l, long long r) { return l + r; }\n\nlong long e()\
    \ { return 0; }\n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int> a(N);\n    for (int\
    \ i = 0; i < N; i++) std::cin >> a[i];\n    HeavyLightDecomposition HLD(N);\n\
    \    for (int i = 0; i < N - 1; i++) {\n        int u, v;\n        std::cin >>\
    \ u >> v;\n        HLD.add_edge(u, v);\n    }\n\n    HLD.build();\n    std::vector<long\
    \ long> v(N);\n    for (int i = 0; i < N; i++) v[HLD.idx(i)] = a[i];\n    atcoder::segtree<long\
    \ long, op, e> seg(v);\n\n    for (; Q--;) {\n        int t;\n        std::cin\
    \ >> t;\n        if (!t) {\n            int p;\n            long long x;\n   \
    \         std::cin >> p >> x;\n            int idx = HLD.idx(p);\n           \
    \ seg.set(idx, seg.get(idx) + x);\n        } else {\n            int u, v;\n \
    \           std::cin >> u >> v;\n            long long ans = 0;\n            auto\
    \ q = [&](int l, int r) { ans += seg.prod(l, r); };\n            HLD.query_path(u,\
    \ v, q, true);\n            std::cout << ans << '\\n';\n        }\n    }\n   \
    \ return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include <iostream>\n#include \"atcoder/segtree\"\n#include \"tree/HeavyLightDecomposition.hpp\"\
    \n\nlong long op(long long l, long long r) { return l + r; }\n\nlong long e()\
    \ { return 0; }\n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int> a(N);\n    for (int\
    \ i = 0; i < N; i++) std::cin >> a[i];\n    HeavyLightDecomposition HLD(N);\n\
    \    for (int i = 0; i < N - 1; i++) {\n        int u, v;\n        std::cin >>\
    \ u >> v;\n        HLD.add_edge(u, v);\n    }\n\n    HLD.build();\n    std::vector<long\
    \ long> v(N);\n    for (int i = 0; i < N; i++) v[HLD.idx(i)] = a[i];\n    atcoder::segtree<long\
    \ long, op, e> seg(v);\n\n    for (; Q--;) {\n        int t;\n        std::cin\
    \ >> t;\n        if (!t) {\n            int p;\n            long long x;\n   \
    \         std::cin >> p >> x;\n            int idx = HLD.idx(p);\n           \
    \ seg.set(idx, seg.get(idx) + x);\n        } else {\n            int u, v;\n \
    \           std::cin >> u >> v;\n            long long ans = 0;\n            auto\
    \ q = [&](int l, int r) { ans += seg.prod(l, r); };\n            HLD.query_path(u,\
    \ v, q, true);\n            std::cout << ans << '\\n';\n        }\n    }\n   \
    \ return 0;\n}"
  dependsOn:
  - tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2021-12-29 23:24:50+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_path_sum.test.cpp
- /verify/test/yosupo/vertex_add_path_sum.test.cpp.html
title: test/yosupo/vertex_add_path_sum.test.cpp
---
