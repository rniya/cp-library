---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/LazySegmentTree.hpp
    title: Lazy Segment Tree
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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E
  bundledCode: "#line 1 \"test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E\"\n\n#line 2 \"\
    base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#pragma region Macros\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n \
    \       os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ map<T, U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();)\
    \ {\n        os << '(' << itr->first << ',' << itr->second << ')';\n        if\
    \ (++itr != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate\
    \ <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T,\
    \ U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();) {\n\
    \        os << '(' << itr->first << ',' << itr->second << ')';\n        if (++itr\
    \ != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const set<T>& s) {\n    os << '{';\n   \
    \ for (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n       \
    \ if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\n\
    template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {\n\
    \    os << '{';\n    for (auto itr = s.begin(); itr != s.end();) {\n        os\
    \ << *itr;\n        if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n\
    \    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream& os, const\
    \ unordered_set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const deque<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n  \
    \      os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&, const T&)\
    \ {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
    \ os, const T& t) {\n    if (i) os << ',';\n    os << get<i>(t);\n    print_tuple<i\
    \ + 1, T, Args...>(os, t);\n}\ntemplate <typename... Args> ostream& operator<<(ostream&\
    \ os, const tuple<Args...>& t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>,\
    \ Args...>(os, t);\n    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\\
    n'; }\ntemplate <class Head, class... Tail> void debug_out(Head&& head, Tail&&...\
    \ tail) {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n \
    \   debug_out(move(tail)...);\n}\n#ifdef LOCAL\n#define debug(...)           \
    \                                                        \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ cerr << #__VA_ARGS__ << \" :[\" << __LINE__ << \":\" << __FUNCTION__ << \"]\"\
    \ << '\\n'; \\\n    cerr << \" \";                                           \
    \                          \\\n    debug_out(__VA_ARGS__)\n#else\n#define debug(...)\
    \ 42\n#endif\n\ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y,\
    \ x % y) : x; }\ntemplate <typename T> T lcm(T x, T y) { return x / gcd(x, y)\
    \ * y; }\n\nint topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\nint topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n\
    int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long\
    \ long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\nint popcount(signed t)\
    \ { return __builtin_popcount(t); }\nint popcount(long long t) { return __builtin_popcountll(t);\
    \ }\nbool ispow2(int i) { return i && (i & -i) == i; }\n\ntemplate <class T> T\
    \ ceil(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? (x + y - 1) / y :\
    \ x / y);\n}\ntemplate <class T> T floor(T x, T y) {\n    assert(y >= 1);\n  \
    \  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <class T1, class T2>\
    \ inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2> inline\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 4 \"datastructure/LazySegmentTree.hpp\"\
    \n\ntemplate <typename Monoid, typename OperatorMonoid, typename F, typename G,\
    \ typename H> struct LazySegmentTree {\n    LazySegmentTree(int n, const F f,\
    \ const G g, const H h, const Monoid& e, const OperatorMonoid& id)\n        :\
    \ n(n), f(f), g(g), h(h), e(e), id(id) {\n        size = 1;\n        height =\
    \ 0;\n        while (size < n) size <<= 1, height++;\n        data.assign(size\
    \ << 1, e);\n        lazy.assign(size << 1, id);\n    }\n\n    void set(int k,\
    \ Monoid x) {\n        assert(0 <= k && k < n);\n        data[k + size] = x;\n\
    \    }\n\n    void build() {\n        for (int k = size - 1; k > 0; k--) {\n \
    \           data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);\n        }\n    }\n\
    \n    void update(int a, int b, const OperatorMonoid& x) {\n        assert(0 <=\
    \ a && a <= b && b <= n);\n        if (a == b) return;\n        thrust(a += size);\n\
    \        thrust(b += size - 1);\n        for (int l = a, r = b + 1; l < r; l >>=\
    \ 1, r >>= 1) {\n            if (l & 1) lazy[l] = h(lazy[l], x), ++l;\n      \
    \      if (r & 1) --r, lazy[r] = h(lazy[r], x);\n        }\n        recalc(a);\n\
    \        recalc(b);\n    }\n\n    void set_val(int k, Monoid x) {\n        assert(0\
    \ <= k && k < n);\n        thrust(k += size);\n        data[k] = x;\n        lazy[k]\
    \ = id;\n        recalc(k);\n    }\n\n    Monoid query(int a, int b) {\n     \
    \   assert(0 <= a && a <= b && b <= n);\n        if (a == b) return e;\n     \
    \   thrust(a += size);\n        thrust(b += size - 1);\n        Monoid L = e,\
    \ R = e;\n        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {\n    \
    \        if (l & 1) L = f(L, apply(l++));\n            if (r & 1) R = f(apply(--r),\
    \ R);\n        }\n        return f(L, R);\n    }\n\n    Monoid operator[](int\
    \ k) {\n        thrust(k += size);\n        return apply(k);\n    }\n\n    template\
    \ <typename C> int find_first(int l, const C& check) {\n        assert(0 <= l\
    \ && l <= n);\n        assert(!check(e));\n        if (l == n) return n;\n   \
    \     Monoid L = e;\n        if (l == 0) {\n            if (check(f(L, apply(1))))\
    \ return find_subtree(1, check, L, false);\n            return n;\n        }\n\
    \        thrust(l + size);\n        int r = size;\n        for (l += size, r +=\
    \ size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n               \
    \ Monoid nxt = f(L, apply(l));\n                if (check(nxt)) return find_subtree(l,\
    \ check, L, false);\n                L = nxt;\n                l++;\n        \
    \    }\n        }\n        return n;\n    }\n\n    template <typename C> int find_last(int\
    \ r, const C& check) {\n        assert(0 <= r && r <= n);\n        assert(!check(e));\n\
    \        if (r == 0) return 0;\n        Monoid R = e;\n        if (r == n) {\n\
    \            if (check(f(apply(1), R))) return find_subtree(1, check, R, true);\n\
    \            return -1;\n        }\n        thrust(r + size - 1);\n        int\
    \ l = size;\n        for (r += size; l < r; l >>= 1, r >>= 1) {\n            if\
    \ (r & 1) {\n                Monoid nxt = f(apply(--r), R);\n                if\
    \ (check(nxt)) return find_subtree(r, check, R, true);\n                R = nxt;\n\
    \            }\n        }\n        return -1;\n    }\n\nprivate:\n    int n, size,\
    \ height;\n    std::vector<Monoid> data;\n    std::vector<OperatorMonoid> lazy;\n\
    \    const F f;\n    const G g;\n    const H h;\n    const Monoid e;\n    const\
    \ OperatorMonoid id;\n\n    inline Monoid apply(int k) { return lazy[k] == id\
    \ ? data[k] : g(data[k], lazy[k]); }\n\n    inline void propagate(int k) {\n \
    \       if (lazy[k] == id) return;\n        lazy[k << 1 | 0] = h(lazy[k << 1 |\
    \ 0], lazy[k]);\n        lazy[k << 1 | 1] = h(lazy[k << 1 | 1], lazy[k]);\n  \
    \      data[k] = apply(k);\n        lazy[k] = id;\n    }\n\n    inline void thrust(int\
    \ k) {\n        for (int i = height; i > 0; i--) propagate(k >> i);\n    }\n\n\
    \    inline void recalc(int k) {\n        while (k >>= 1) data[k] = f(apply(k\
    \ << 1 | 0), apply(k << 1 | 1));\n    }\n\n    template <typename C> int find_subtree(int\
    \ a, const C& check, Monoid& M, bool type) {\n        while (a < size) {\n   \
    \         propagate(a);\n            Monoid nxt = type ? f(apply(a << 1 | type),\
    \ M) : f(M, apply(a << 1 | type));\n            if (check(nxt))\n            \
    \    a = a << 1 | type;\n            else\n                M = nxt, a = (a <<\
    \ 1 | 1) - type;\n        }\n        return a - size;\n    }\n};\n\n/**\n * @brief\
    \ Lazy Segment Tree\n * @docs docs/datastructure/LazySegmentTree.md\n */\n#line\
    \ 5 \"tree/HeavyLightDecomposition.hpp\"\n\nstruct HeavyLightDecomposition {\n\
    \    HeavyLightDecomposition(int n)\n        : n(n),\n          time(0),\n   \
    \       G(n),\n          par(n, -1),\n          sub(n),\n          dep(n, 0),\n\
    \          head(n),\n          tree_id(n, -1),\n          vertex_id(n, -1),\n\
    \          vertex_id_inv(n) {}\n    void add_edge(int u, int v) {\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        G[u].emplace_back(v);\n\
    \        G[v].emplace_back(u);\n    }\n\n    void build(std::vector<int> roots\
    \ = {0}) {\n        int tree_id_cur = 0;\n        for (int& r : roots) {\n   \
    \         assert(0 <= r && r < n);\n            dfs_sz(r);\n            head[r]\
    \ = r;\n            dfs_hld(r, tree_id_cur++);\n        }\n        assert(time\
    \ == n);\n        for (int v = 0; v < n; v++) vertex_id_inv[vertex_id[v]] = v;\n\
    \    }\n\n    int idx(int v) const { return vertex_id[v]; }\n\n    int la(int\
    \ v, int k) {\n        assert(0 <= v && v < n);\n        assert(0 <= k && k <=\
    \ dep[v]);\n        while (1) {\n            int u = head[v];\n            if\
    \ (vertex_id[v] - k >= vertex_id[u]) return vertex_id_inv[vertex_id[v] - k];\n\
    \            k -= vertex_id[v] - vertex_id[u] + 1;\n            v = par[u];\n\
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
    \ + sub[u]);\n    }\n\nprivate:\n    int n, time;\n    std::vector<std::vector<int>>\
    \ G;  // child of vertex v on heavy edge is G[v].front() if it is not parent of\
    \ v\n    std::vector<int> par              // parent of vertex v\n        ,\n\
    \        sub  // size of subtree whose root is v\n        ,\n        dep  // distance\
    \ bitween root and vertex v\n        ,\n        head  // vertex that is the nearest\
    \ to root on heavy path of vertex v\n        ,\n        tree_id  // id of tree\
    \ vertex v belongs to\n        ,\n        vertex_id  // id of vertex v (consecutive\
    \ on heavy paths)\n        ,\n        vertex_id_inv;  // vertex_id_inv[vertex_id[v]]\
    \ = v\n\n    void dfs_sz(int v) {\n        sub[v] = 1;\n        if (!G[v].empty()\
    \ && G[v].front() == par[v]) std::swap(G[v].front(), G[v].back());\n        for\
    \ (int& u : G[v]) {\n            if (u == par[v]) continue;\n            par[u]\
    \ = v;\n            dep[u] = dep[v] + 1;\n            dfs_sz(u);\n           \
    \ sub[v] += sub[u];\n            if (sub[u] > sub[G[v].front()]) std::swap(u,\
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
    \        return res;\n    }\n};\n\n/**\n * @brief Heavy Light Decomposition\n\
    \ * @docs docs/tree/HeavyLightDecomposition.md\n */\n#line 6 \"test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n;\n\
    \    cin >> n;\n\n    HeavyLightDecomposition HLD(n);\n    for (int i = 0; i <\
    \ n; i++) {\n        int k;\n        cin >> k;\n        for (; k--;) {\n     \
    \       int c;\n            cin >> c;\n            HLD.add_edge(i, c);\n     \
    \   }\n    }\n    HLD.build();\n\n    struct node {\n        long long a;\n  \
    \      int b;\n        node(long long a, int b) : a(a), b(b) {}\n    };\n    auto\
    \ f = [](node a, node b) { return node(a.a + b.a, a.b + b.b); };\n    auto g =\
    \ [](node a, long long x) { return node(a.a + x * a.b, a.b); };\n    auto h =\
    \ [](long long a, long long b) { return a + b; };\n    LazySegmentTree<node, long\
    \ long, decltype(f), decltype(g), decltype(h)> seg(n, f, g, h, node(0, 0), 0);\n\
    \    for (int i = 0; i < n; i++) seg.set(i, node(0, 1));\n    seg.build();\n\n\
    \    int q;\n    cin >> q;\n    for (; q--;) {\n        int t;\n        cin >>\
    \ t;\n        if (!t) {\n            int v;\n            long long w;\n      \
    \      cin >> v >> w;\n            auto q = [&](int l, int r) { seg.update(l,\
    \ r, w); };\n            HLD.query_path(0, v, q);\n        } else {\n        \
    \    int u;\n            cin >> u;\n            long long ans = 0;\n         \
    \   auto q = [&](int l, int r) { ans += seg.query(l, r).a; };\n            HLD.query_path(0,\
    \ u, q);\n            cout << ans << '\\n';\n        }\n    }\n    return 0;\n\
    }\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E\"\n\n\
    #include \"../../base.hpp\"\n#include \"../../datastructure/LazySegmentTree.hpp\"\
    \n#include \"../../tree/HeavyLightDecomposition.hpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int n;\n    cin >> n;\n\n    HeavyLightDecomposition\
    \ HLD(n);\n    for (int i = 0; i < n; i++) {\n        int k;\n        cin >> k;\n\
    \        for (; k--;) {\n            int c;\n            cin >> c;\n         \
    \   HLD.add_edge(i, c);\n        }\n    }\n    HLD.build();\n\n    struct node\
    \ {\n        long long a;\n        int b;\n        node(long long a, int b) :\
    \ a(a), b(b) {}\n    };\n    auto f = [](node a, node b) { return node(a.a + b.a,\
    \ a.b + b.b); };\n    auto g = [](node a, long long x) { return node(a.a + x *\
    \ a.b, a.b); };\n    auto h = [](long long a, long long b) { return a + b; };\n\
    \    LazySegmentTree<node, long long, decltype(f), decltype(g), decltype(h)> seg(n,\
    \ f, g, h, node(0, 0), 0);\n    for (int i = 0; i < n; i++) seg.set(i, node(0,\
    \ 1));\n    seg.build();\n\n    int q;\n    cin >> q;\n    for (; q--;) {\n  \
    \      int t;\n        cin >> t;\n        if (!t) {\n            int v;\n    \
    \        long long w;\n            cin >> v >> w;\n            auto q = [&](int\
    \ l, int r) { seg.update(l, r, w); };\n            HLD.query_path(0, v, q);\n\
    \        } else {\n            int u;\n            cin >> u;\n            long\
    \ long ans = 0;\n            auto q = [&](int l, int r) { ans += seg.query(l,\
    \ r).a; };\n            HLD.query_path(0, u, q);\n            cout << ans << '\\\
    n';\n        }\n    }\n    return 0;\n}"
  dependsOn:
  - base.hpp
  - datastructure/LazySegmentTree.hpp
  - tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
  requiredBy: []
  timestamp: '2021-09-25 17:45:48+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
- /verify/test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp.html
title: test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
---
