---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/SegmentTree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: modulo/modint.hpp
    title: modint
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
    PROBLEM: https://judge.yosupo.jp/problem/vertex_set_path_composite
    links:
    - https://judge.yosupo.jp/problem/vertex_set_path_composite
  bundledCode: "#line 1 \"test/yosupo/vertex_set_path_composite.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\n\n#line\
    \ 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#pragma region\
    \ Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int\
    \ uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\
    \ntemplate <typename T> istream& operator>>(istream& is, vector<T>& v) {\n   \
    \ for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 5 \"modulo/modint.hpp\"\
    \n\ntemplate <uint64_t Modulus> class modint {\n    using i64 = int64_t;\n   \
    \ using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static_assert(Modulus\
    \ < static_cast<uint32_t>(1) << 31, \"Modulus must be less than 2**31\");\n  \
    \  static constexpr u32 mod = Modulus;\n    u32 v;\n\npublic:\n    constexpr modint(const\
    \ i64 x = 0) noexcept : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}\n \
    \   constexpr u32& value() noexcept { return v; }\n    constexpr const u32& value()\
    \ const noexcept { return v; }\n    constexpr modint operator+(const modint& rhs)\
    \ const noexcept { return modint(*this) += rhs; }\n    constexpr modint operator-(const\
    \ modint& rhs) const noexcept { return modint(*this) -= rhs; }\n    constexpr\
    \ modint operator*(const modint& rhs) const noexcept { return modint(*this) *=\
    \ rhs; }\n    constexpr modint operator/(const modint& rhs) const noexcept { return\
    \ modint(*this) /= rhs; }\n    constexpr modint& operator+=(const modint& rhs)\
    \ noexcept {\n        v += rhs.v;\n        if (v >= mod) v -= mod;\n        return\
    \ *this;\n    }\n    constexpr modint& operator-=(const modint& rhs) noexcept\
    \ {\n        if (v < rhs.v) v += mod;\n        v -= rhs.v;\n        return *this;\n\
    \    }\n    constexpr modint& operator*=(const modint& rhs) noexcept {\n     \
    \   v = (u64)v * rhs.v % mod;\n        return *this;\n    }\n    constexpr modint&\
    \ operator/=(const modint& rhs) noexcept { return *this *= rhs.inv(); }\n    constexpr\
    \ modint pow(u64 exp) const noexcept {\n        assert(0 <= exp);\n        modint\
    \ self(*this), res(1);\n        while (exp > 0) {\n            if (exp & 1) res\
    \ *= self;\n            self *= self;\n            exp >>= 1;\n        }\n   \
    \     return res;\n    }\n    constexpr modint inv() const noexcept {\n      \
    \  assert(*this != 0);\n        return pow(mod - 2);\n    }\n    constexpr modint&\
    \ operator++() noexcept {\n        if (++v == mod) v = 0;\n        return *this;\n\
    \    }\n    constexpr modint& operator--() noexcept {\n        if (v == 0) v =\
    \ mod;\n        return --v, *this;\n    }\n    constexpr modint operator++(int)\
    \ noexcept {\n        modint t = *this;\n        return ++*this, t;\n    }\n \
    \   constexpr modint operator--(int) noexcept {\n        modint t = *this;\n \
    \       return --*this, t;\n    }\n    constexpr modint operator-() const noexcept\
    \ { return modint(mod - v); }\n    template <class T> friend constexpr modint\
    \ operator+(T x, modint y) noexcept { return modint(x) + y; }\n    template <class\
    \ T> friend constexpr modint operator-(T x, modint y) noexcept { return modint(x)\
    \ - y; }\n    template <class T> friend constexpr modint operator*(T x, modint\
    \ y) noexcept { return modint(x) * y; }\n    template <class T> friend constexpr\
    \ modint operator/(T x, modint y) noexcept { return modint(x) / y; }\n    constexpr\
    \ bool operator==(const modint& rhs) const noexcept { return v == rhs.v; }\n \
    \   constexpr bool operator!=(const modint& rhs) const noexcept { return v !=\
    \ rhs.v; }\n    constexpr bool operator!() const noexcept { return !v; }\n   \
    \ friend std::istream& operator>>(std::istream& s, modint& rhs) noexcept {\n \
    \       i64 v;\n        rhs = modint{(s >> v, v)};\n        return s;\n    }\n\
    \    friend std::ostream& operator<<(std::ostream& s, const modint& rhs) noexcept\
    \ { return s << rhs.v; }\n};\n\n/**\n * @brief modint\n * @docs docs/modulo/modint.md\n\
    \ */\n#line 4 \"datastructure/SegmentTree.hpp\"\n\ntemplate <typename Monoid,\
    \ typename F> struct SegmentTree {\n    SegmentTree(int n, const F f, const Monoid&\
    \ e) : n(n), f(f), e(e) {\n        size = 1;\n        while (size < n) size <<=\
    \ 1;\n        data.assign(size << 1, e);\n    }\n\n    void set(int k, Monoid\
    \ x) {\n        assert(0 <= k && k < n);\n        data[k + size] = x;\n    }\n\
    \n    void build() {\n        for (int k = size - 1; k > 0; k--) {\n         \
    \   data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);\n        }\n    }\n\n   \
    \ void update(int k, Monoid x) {\n        assert(0 <= k && k < n);\n        k\
    \ += size;\n        data[k] = x;\n        while (k >>= 1) data[k] = f(data[k <<\
    \ 1 | 0], data[k << 1 | 1]);\n    }\n\n    void add(int k, Monoid x) {\n     \
    \   assert(0 <= k && k < n);\n        k += size;\n        data[k] += x;\n    \
    \    while (k >>= 1) data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);\n    }\n\
    \n    Monoid query(int l, int r) const {\n        assert(0 <= l && l <= r && r\
    \ <= n);\n        Monoid L = e, R = e;\n        for (l += size, r += size; l <\
    \ r; l >>= 1, r >>= 1) {\n            if (l & 1) L = f(L, data[l++]);\n      \
    \      if (r & 1) R = f(data[--r], R);\n        }\n        return f(L, R);\n \
    \   }\n\n    Monoid all_prod() const { return data[1]; }\n\n    Monoid operator[](const\
    \ int& k) const { return data[k + size]; }\n\n    template <typename C> int find_first(int\
    \ l, const C& check) {\n        assert(0 <= l && l <= n);\n        assert(!check(e));\n\
    \        if (l == n) return n;\n        Monoid L = e;\n        if (l == 0) {\n\
    \            if (check(f(L, data[1]))) return find_subtree(1, check, L, false);\n\
    \            return n;\n        }\n        int r = size;\n        for (l += size,\
    \ r += size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) {\n          \
    \      Monoid nxt = f(L, data[l]);\n                if (check(nxt)) return find_subtree(l,\
    \ check, L, false);\n                L = nxt;\n                l++;\n        \
    \    }\n        }\n        return n;\n    }\n\n    template <typename C> int find_last(int\
    \ r, const C& check) {\n        assert(0 <= r && r <= n);\n        assert(!check(e));\n\
    \        if (r == 0) return 0;\n        Monoid R = e;\n        if (r == n) {\n\
    \            if (check(f(data[1], R))) return find_subtree(1, check, R, true);\n\
    \            return -1;\n        }\n        int l = size;\n        for (r += size;\
    \ l < r; l >>= 1, r >>= 1) {\n            if (r & 1) {\n                Monoid\
    \ nxt = f(data[--r], R);\n                if (check(nxt)) return find_subtree(r,\
    \ check, R, false);\n                R = nxt;\n            }\n        }\n    \
    \    return -1;\n    }\n\nprivate:\n    int n, size;\n    std::vector<Monoid>\
    \ data;\n    const F f;\n    const Monoid e;\n\n    template <typename C> int\
    \ find_subtree(int a, const C& check, Monoid& M, bool type) {\n        while (a\
    \ < size) {\n            Monoid nxt = type ? f(data[a << 1 | type], M) : f(M,\
    \ data[a << 1 | type]);\n            if (check(nxt))\n                a = a <<\
    \ 1 | type;\n            else\n                M = nxt, a = (a << 1 | 1) - type;\n\
    \        }\n        return a - size;\n    }\n};\n\n/**\n * @brief Segment Tree\n\
    \ * @docs docs/datastructure/SegmentTree.md\n */\n#line 5 \"tree/HeavyLightDecomposition.hpp\"\
    \n\nstruct HeavyLightDecomposition {\n    HeavyLightDecomposition(int n)\n   \
    \     : n(n), time(0), G(n), par(n, -1), sub(n), dep(n, 0), head(n), tree_id(n,\
    \ -1), vertex_id(n, -1) {}\n    void add_edge(int u, int v) {\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        G[u].emplace_back(v);\n\
    \        G[v].emplace_back(u);\n    }\n\n    void build(std::vector<int> roots\
    \ = {0}) {\n        int tree_id_cur = 0;\n        for (int& r : roots) {\n   \
    \         assert(0 <= r && r < n);\n            dfs_sz(r);\n            head[r]\
    \ = r;\n            dfs_hld(r, tree_id_cur++);\n        }\n    }\n\n    int idx(int\
    \ v) const { return vertex_id[v]; }\n\n    int lca(int u, int v) const {\n   \
    \     assert(0 <= u && u < n);\n        assert(0 <= v && v < n);\n        assert(tree_id[u]\
    \ == tree_id[v]);\n        for (;; v = par[head[v]]) {\n            if (vertex_id[u]\
    \ > vertex_id[v]) std::swap(u, v);\n            if (head[u] == head[v]) return\
    \ u;\n        }\n    }\n\n    int distance(int u, int v) const {\n        assert(0\
    \ <= u && u < n);\n        assert(0 <= v && v < n);\n        assert(tree_id[u]\
    \ == tree_id[v]);\n        return dep[u] + dep[v] - 2 * dep[lca(u, v)];\n    }\n\
    \n    template <typename F> void query_path(int u, int v, const F& f, bool vertex\
    \ = false) const {\n        assert(0 <= u && u < n);\n        assert(0 <= v &&\
    \ v < n);\n        assert(tree_id[u] == tree_id[v]);\n        int p = lca(u, v);\n\
    \        for (auto& e : ascend(u, p)) f(e.second, e.first + 1);\n        if (vertex)\
    \ f(vertex_id[p], vertex_id[p] + 1);\n        for (auto& e : descend(p, v)) f(e.first,\
    \ e.second + 1);\n    }\n\n    template <typename F> void query_path_noncommutative(int\
    \ u, int v, const F& f, bool vertex = false) const {\n        assert(0 <= u &&\
    \ u < n);\n        assert(0 <= v && v < n);\n        assert(tree_id[u] == tree_id[v]);\n\
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
    \ vertex v belongs to\n        ,\n        vertex_id;  // id of vertex v (consecutive\
    \ on heavy paths)\n\n    void dfs_sz(int v) {\n        sub[v] = 1;\n        if\
    \ (!G[v].empty() && G[v].front() == par[v]) std::swap(G[v].front(), G[v].back());\n\
    \        for (int& u : G[v]) {\n            if (u == par[v]) continue;\n     \
    \       par[u] = v;\n            dep[u] = dep[v] + 1;\n            dfs_sz(u);\n\
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
    \        return res;\n    }\n};\n\n/**\n * @brief Heavy Light Decomposition\n\
    \ * @docs docs/tree/HeavyLightDecomposition.md\n */\n#line 7 \"test/yosupo/vertex_set_path_composite.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N), b(N);\n    for (int\
    \ i = 0; i < N; i++) cin >> a[i] >> b[i];\n    HeavyLightDecomposition HLD(N);\n\
    \    for (int i = 0; i < N - 1; i++) {\n        int u, v;\n        cin >> u >>\
    \ v;\n        HLD.add_edge(u, v);\n    }\n\n    HLD.build();\n    struct node\
    \ {\n        mint a, b;\n        node(mint a, mint b) : a(a), b(b) {}\n    };\n\
    \    auto f = [](node a, node b) { return node(a.a * b.a, a.b * b.a + b.b); };\n\
    \    auto g = [](node a, node b) { return node(a.a * b.a, b.b * a.a + a.b); };\n\
    \    SegmentTree<node, decltype(f)> segl(N, f, node(1, 0));\n    SegmentTree<node,\
    \ decltype(g)> segr(N, g, node(1, 0));\n    for (int i = 0; i < N; i++) {\n  \
    \      int x = HLD.idx(i);\n        segl.set(x, node(a[i], b[i]));\n        segr.set(x,\
    \ node(a[i], b[i]));\n    }\n    segl.build();\n    segr.build();\n\n    for (;\
    \ Q--;) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n        \
    \    int p, c, d;\n            cin >> p >> c >> d;\n            int x = HLD.idx(p);\n\
    \            segl.update(x, node(c, d));\n            segr.update(x, node(c, d));\n\
    \        } else {\n            int u, v, x;\n            cin >> u >> v >> x;\n\
    \            mint ans = x;\n            auto q = [&](int l, int r) {\n       \
    \         if (l <= r) {\n                    node res = segl.query(l, r);\n  \
    \                  ans = res.a * ans + res.b;\n                } else {\n    \
    \                node res = segr.query(r, l);\n                    ans = res.a\
    \ * ans + res.b;\n                }\n            };\n            HLD.query_path_noncommutative(u,\
    \ v, q, true);\n            cout << ans << '\\n';\n        }\n    }\n    return\
    \ 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_set_path_composite\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n#include\
    \ \"../../datastructure/SegmentTree.hpp\"\n#include \"../../tree/HeavyLightDecomposition.hpp\"\
    \n\nusing mint = modint<998244353>;\n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    cin >> N >> Q;\n    vector<int> a(N), b(N);\n    for (int\
    \ i = 0; i < N; i++) cin >> a[i] >> b[i];\n    HeavyLightDecomposition HLD(N);\n\
    \    for (int i = 0; i < N - 1; i++) {\n        int u, v;\n        cin >> u >>\
    \ v;\n        HLD.add_edge(u, v);\n    }\n\n    HLD.build();\n    struct node\
    \ {\n        mint a, b;\n        node(mint a, mint b) : a(a), b(b) {}\n    };\n\
    \    auto f = [](node a, node b) { return node(a.a * b.a, a.b * b.a + b.b); };\n\
    \    auto g = [](node a, node b) { return node(a.a * b.a, b.b * a.a + a.b); };\n\
    \    SegmentTree<node, decltype(f)> segl(N, f, node(1, 0));\n    SegmentTree<node,\
    \ decltype(g)> segr(N, g, node(1, 0));\n    for (int i = 0; i < N; i++) {\n  \
    \      int x = HLD.idx(i);\n        segl.set(x, node(a[i], b[i]));\n        segr.set(x,\
    \ node(a[i], b[i]));\n    }\n    segl.build();\n    segr.build();\n\n    for (;\
    \ Q--;) {\n        int t;\n        cin >> t;\n        if (t == 0) {\n        \
    \    int p, c, d;\n            cin >> p >> c >> d;\n            int x = HLD.idx(p);\n\
    \            segl.update(x, node(c, d));\n            segr.update(x, node(c, d));\n\
    \        } else {\n            int u, v, x;\n            cin >> u >> v >> x;\n\
    \            mint ans = x;\n            auto q = [&](int l, int r) {\n       \
    \         if (l <= r) {\n                    node res = segl.query(l, r);\n  \
    \                  ans = res.a * ans + res.b;\n                } else {\n    \
    \                node res = segr.query(r, l);\n                    ans = res.a\
    \ * ans + res.b;\n                }\n            };\n            HLD.query_path_noncommutative(u,\
    \ v, q, true);\n            cout << ans << '\\n';\n        }\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - datastructure/SegmentTree.hpp
  - tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/yosupo/vertex_set_path_composite.test.cpp
  requiredBy: []
  timestamp: '2021-09-21 22:39:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_set_path_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_set_path_composite.test.cpp
- /verify/test/yosupo/vertex_set_path_composite.test.cpp.html
title: test/yosupo/vertex_set_path_composite.test.cpp
---
