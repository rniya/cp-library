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
    \ \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\n#line 2 \"base.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\n#pragma region Macros\ntypedef\
    \ long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\ntypedef\
    \ unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename\
    \ T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x : v) is >>\
    \ x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream& os,\
    \ const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n     \
    \   os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 4 \"datastructure/SegmentTree.hpp\"\
    \n\ntemplate <typename Monoid, typename F> struct SegmentTree {\n    SegmentTree(int\
    \ n, const F f, const Monoid& e) : n(n), f(f), e(e) {\n        size = 1;\n   \
    \     while (size < n) size <<= 1;\n        data.assign(size << 1, e);\n    }\n\
    \n    void set(int k, Monoid x) {\n        assert(0 <= k && k < n);\n        data[k\
    \ + size] = x;\n    }\n\n    void build() {\n        for (int k = size - 1; k\
    \ > 0; k--) {\n            data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);\n\
    \        }\n    }\n\n    void update(int k, Monoid x) {\n        assert(0 <= k\
    \ && k < n);\n        k += size;\n        data[k] = x;\n        while (k >>= 1)\
    \ data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);\n    }\n\n    void add(int\
    \ k, Monoid x) {\n        assert(0 <= k && k < n);\n        k += size;\n     \
    \   data[k] += x;\n        while (k >>= 1) data[k] = f(data[k << 1 | 0], data[k\
    \ << 1 | 1]);\n    }\n\n    Monoid query(int l, int r) const {\n        assert(0\
    \ <= l && l <= r && r <= n);\n        Monoid L = e, R = e;\n        for (l +=\
    \ size, r += size; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) L = f(L,\
    \ data[l++]);\n            if (r & 1) R = f(data[--r], R);\n        }\n      \
    \  return f(L, R);\n    }\n\n    Monoid all_prod() const { return data[1]; }\n\
    \n    Monoid operator[](const int& k) const { return data[k + size]; }\n\n   \
    \ template <typename C> int find_first(int l, const C& check) {\n        assert(0\
    \ <= l && l <= n);\n        assert(!check(e));\n        if (l == n) return n;\n\
    \        Monoid L = e;\n        if (l == 0) {\n            if (check(f(L, data[1])))\
    \ return find_subtree(1, check, L, false);\n            return n;\n        }\n\
    \        int r = size;\n        for (l += size, r += size; l < r; l >>= 1, r >>=\
    \ 1) {\n            if (l & 1) {\n                Monoid nxt = f(L, data[l]);\n\
    \                if (check(nxt)) return find_subtree(l, check, L, false);\n  \
    \              L = nxt;\n                l++;\n            }\n        }\n    \
    \    return n;\n    }\n\n    template <typename C> int find_last(int r, const\
    \ C& check) {\n        assert(0 <= r && r <= n);\n        assert(!check(e));\n\
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
    \ 1 | type;\n            else\n                M = nxt, a = (a << 1 | type) -\
    \ 1;\n        }\n        return a - size;\n    }\n};\n\n/**\n * @brief Segment\
    \ Tree\n * @docs docs/datastructure/SegmentTree.md\n */\n#line 3 \"tree/HeavyLightDecomposition.hpp\"\
    \n\n/**\n * @brief Heavy Light Decomposition\n * @docsdocs/tree/HeavyLightDecomposition.md\n\
    \ */\nclass HeavyLightDecomposition {\n    void dfs_sz(int v) {\n        if (G[v].size()\
    \ && G[v][0] == par[v]) swap(G[v][0], G[v].back());\n        for (int& u : G[v])\
    \ {\n            if (u == par[v]) continue;\n            par[u] = v;\n       \
    \     dep[u] = dep[v] + 1;\n            dfs_sz(u);\n            sub[v] += sub[u];\n\
    \            if (sub[u] > sub[G[v][0]]) swap(u, G[v][0]);\n        }\n    }\n\
    \    void dfs_hld(int v, int c, int& times) {\n        vid[v] = times++;\n   \
    \     type[v] = c;\n        for (int u : G[v]) {\n            if (u == par[v])\
    \ continue;\n            head[u] = (u == G[v][0] ? head[v] : u);\n           \
    \ dfs_hld(u, c, times);\n        }\n    }\n\npublic:\n    vector<vector<int>>\
    \ G;\n    vector<int> vid, head, sub, par, dep, type;\n    HeavyLightDecomposition(int\
    \ n) : G(n), vid(n, -1), head(n), sub(n, 1), par(n, -1), dep(n, 0), type(n) {}\n\
    \    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n\
    \    }\n    void build(vector<int> rs = {0}) {\n        int c = 0, times = 0;\n\
    \        for (int r : rs) {\n            dfs_sz(r);\n            head[r] = r;\n\
    \            dfs_hld(r, c++, times);\n        }\n    }\n    int idx(int u) { return\
    \ vid[u]; }\n    int lca(int u, int v) {\n        for (;; v = par[head[v]]) {\n\
    \            if (vid[u] > vid[v]) swap(u, v);\n            if (head[u] == head[v])\
    \ return u;\n        }\n    }\n    int distance(int u, int v) { return dep[u]\
    \ + dep[v] - 2 * dep[lca(u, v)]; }\n    template <typename F> void update_path(int\
    \ u, int v, const F& f, bool edge = false) {\n        for (;; v = par[head[v]])\
    \ {\n            if (vid[u] > vid[v]) swap(u, v);\n            if (head[u] ==\
    \ head[v]) break;\n            f(vid[head[v]], vid[v] + 1);\n        }\n     \
    \   f(vid[u] + edge, vid[v] + 1);\n    }\n    template <typename F> void update_sub(int\
    \ u, const F& f, bool edge = false) { f(vid[u] + edge, vid[u] + sub[u]); }\n \
    \   template <typename T, typename Q, typename F>\n    T query_path(int u, int\
    \ v, const T& id, const Q& q, const F& f, bool edge = false) {\n        T l =\
    \ id, r = id;\n        for (;; v = par[head[v]]) {\n            if (vid[u] > vid[v])\
    \ swap(u, v), swap(l, r);\n            if (head[u] == head[v]) break;\n      \
    \      l = f(l, q(vid[head[v]], vid[v] + 1));\n        }\n        return f(r,\
    \ f(l, q(vid[u] + edge, vid[v] + 1)));\n    }\n    template <typename T, typename\
    \ Q> T query_sub(int u, const Q& q, bool edge = false) {\n        return q(vid[u]\
    \ + edge, vid[u] + sub[u]);\n    }\n};\n#line 6 \"test/yosupo/vertex_add_path_sum.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,\
    \ Q;\n    cin >> N >> Q;\n    vector<long long> a(N);\n    for (int i = 0; i <\
    \ N; i++) cin >> a[i];\n\n    HeavyLightDecomposition HLD(N);\n    for (int i\
    \ = 0; i < N - 1; i++) {\n        int u, v;\n        cin >> u >> v;\n        HLD.add_edge(u,\
    \ v);\n    }\n    HLD.build();\n\n    auto f = [](long long a, long long b) {\
    \ return a + b; };\n    SegmentTree<long long, decltype(f)> seg(N, f, 0);\n  \
    \  for (int i = 0; i < N; i++) seg.set(HLD.idx(i), a[i]);\n    seg.build();\n\n\
    \    for (; Q--;) {\n        int t;\n        cin >> t;\n        if (!t) {\n  \
    \          int p;\n            long long x;\n            cin >> p >> x;\n    \
    \        int i = HLD.idx(p);\n            seg.add(i, x);\n        } else {\n \
    \           int u, v;\n            cin >> u >> v;\n            cout << HLD.query_path(\n\
    \                        u, v, 0LL, [&](int l, int r) { return seg.query(l, r);\
    \ }, f)\n                 << '\\n';\n        }\n    }\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../../base.hpp\"\n#include \"../../datastructure/SegmentTree.hpp\"\
    \n#include \"../../tree/HeavyLightDecomposition.hpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int N, Q;\n    cin >> N >> Q;\n    vector<long\
    \ long> a(N);\n    for (int i = 0; i < N; i++) cin >> a[i];\n\n    HeavyLightDecomposition\
    \ HLD(N);\n    for (int i = 0; i < N - 1; i++) {\n        int u, v;\n        cin\
    \ >> u >> v;\n        HLD.add_edge(u, v);\n    }\n    HLD.build();\n\n    auto\
    \ f = [](long long a, long long b) { return a + b; };\n    SegmentTree<long long,\
    \ decltype(f)> seg(N, f, 0);\n    for (int i = 0; i < N; i++) seg.set(HLD.idx(i),\
    \ a[i]);\n    seg.build();\n\n    for (; Q--;) {\n        int t;\n        cin\
    \ >> t;\n        if (!t) {\n            int p;\n            long long x;\n   \
    \         cin >> p >> x;\n            int i = HLD.idx(p);\n            seg.add(i,\
    \ x);\n        } else {\n            int u, v;\n            cin >> u >> v;\n \
    \           cout << HLD.query_path(\n                        u, v, 0LL, [&](int\
    \ l, int r) { return seg.query(l, r); }, f)\n                 << '\\n';\n    \
    \    }\n    }\n    return 0;\n}"
  dependsOn:
  - base.hpp
  - datastructure/SegmentTree.hpp
  - tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2021-09-20 21:09:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_path_sum.test.cpp
- /verify/test/yosupo/vertex_add_path_sum.test.cpp.html
title: test/yosupo/vertex_add_path_sum.test.cpp
---
