---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  - icon: ':heavy_check_mark:'
    path: tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "#line 1 \"test/yosupo/vertex_add_subtree_sum.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\n\n#line 2 \"base.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\nconst long long MOD = 1000000007;\n\
    // const long long MOD=998244353;\nconst int INF = 1e9;\nconst long long IINF\
    \ = 1e18;\nconst int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};\nconst char\
    \ dir[4] = {'D', 'R', 'U', 'L'};\n#define LOCAL\ntypedef long long ll;\ntypedef\
    \ __int128_t i128;\ntypedef unsigned int uint;\ntypedef unsigned long long ull;\n\
    #define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename T> istream& operator>>(istream&\
    \ is, vector<T>& v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate\
    \ <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {\n    for\
    \ (int i = 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ?\
    \ \"\" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first\
    \ << ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U, typename V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t) {\n\
    \    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';\n\
    \    return os;\n}\ntemplate <typename T, typename U, typename V, typename W>\
    \ ostream& operator<<(ostream& os, const tuple<T, U, V, W>& t) {\n    os << '('\
    \ << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) <<\
    \ ')';\n    return os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream&\
    \ os, const map<T, U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr\
    \ != m.end();) {\n        os << '(' << itr->first << ',' << itr->second << ')';\n\
    \        if (++itr != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T,\
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
    \ os, const deque<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n       \
    \ os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n}\n\
    \nvoid debug_out() { cerr << '\\n'; }\ntemplate <class Head, class... Tail> void\
    \ debug_out(Head&& head, Tail&&... tail) {\n    cerr << head;\n    if (sizeof...(Tail)\
    \ > 0) cerr << \", \";\n    debug_out(move(tail)...);\n}\n#ifdef LOCAL\n#define\
    \ debug(...)                                                                 \
    \  \\\n    cerr << \" \";                                                    \
    \                 \\\n    cerr << #__VA_ARGS__ << \" :[\" << __LINE__ << \":\"\
    \ << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \";                  \
    \                                                   \\\n    debug_out(__VA_ARGS__)\n\
    #else\n#define debug(...) 42\n#endif\n\ntemplate <typename T> T gcd(T x, T y)\
    \ { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename T> T lcm(T x, T y)\
    \ { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class T2> inline bool chmin(T1&\
    \ a, T2 b) {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n\
    \    return false;\n}\ntemplate <class T1, class T2> inline bool chmax(T1& a,\
    \ T2 b) {\n    if (a < b) {\n        a = b;\n        return true;\n    }\n   \
    \ return false;\n}\n#line 3 \"tree/HeavyLightDecomposition.hpp\"\n\n/**\n * @brief\
    \ Heavy Light Decomposition\n * @docsdocs/tree/HeavyLightDecomposition.md\n */\n\
    class HeavyLightDecomposition {\n    void dfs_sz(int v) {\n        if (G[v].size()\
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
    \ + edge, vid[u] + sub[u]);\n    }\n};\n#line 3 \"datastructure/BinaryIndexedTree.hpp\"\
    \n\n/**\n * @brief Binary Indexed Tree\n * @docs docs/datastructure/BinaryIndexedTree.md\n\
    \ */\ntemplate <typename T> class BinaryIndexedTree {\n    T sum(int i) {\n  \
    \      T res = T();\n        for (; i > 0; i -= (i & -i)) res += dat[i];\n   \
    \     return res;\n    }\n\npublic:\n    int n;\n    vector<T> dat;\n    BinaryIndexedTree(int\
    \ n_) : n(n_ + 1), dat(n + 1, 0) {}\n    void add(int i, const T& x) {\n     \
    \   for (++i; i <= n; i += (i & -i)) dat[i] += x;\n    }\n    T query(int l, int\
    \ r) { return sum(r) - sum(l); }\n    int lower_bound(T x) const {\n        if\
    \ (x <= 0) return 0;\n        int pos = 0, k = 1;\n        while (k < n) k <<=\
    \ 1;\n        for (; k > 0; k >>= 1) {\n            if (pos + k <= n && dat[pos\
    \ + k] < x) {\n                x -= dat[pos + k];\n                pos += k;\n\
    \            }\n        }\n        return pos;\n    }\n    int upper_bound(T x)\
    \ const { return lower_bound(x + 1); }\n    T operator[](int i) { return query(i,\
    \ i + 1); }\n};\n#line 6 \"test/yosupo/vertex_add_subtree_sum.test.cpp\"\n\nint\
    \ main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,Q; cin\
    \ >> N >> Q;\n    vector<int> a(N);\n    for (int i=0;i<N;++i) cin >> a[i];\n\n\
    \    HeavyLightDecomposition HLD(N);\n    for (int i=1;i<N;++i){\n        int\
    \ p; cin >> p;\n        HLD.add_edge(p,i);\n    }\n    HLD.build();\n\n    BinaryIndexedTree<long\
    \ long> BIT(N);\n    for (int i=0;i<N;++i) BIT.add(HLD.idx(i),a[i]);\n\n    for\
    \ (;Q--;){\n        int t,u; cin >> t >> u;\n        if (!t){\n            int\
    \ x; cin >> x;\n            BIT.add(HLD.idx(u),x);\n        } else {\n       \
    \     cout << HLD.query_sub<long long>(u,[&](int l,int r){return BIT.query(l,r);})\
    \ << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../tree/HeavyLightDecomposition.hpp\"\
    \n#include \"../../datastructure/BinaryIndexedTree.hpp\"\n\nint main(){\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int N,Q; cin >> N >> Q;\n    vector<int>\
    \ a(N);\n    for (int i=0;i<N;++i) cin >> a[i];\n\n    HeavyLightDecomposition\
    \ HLD(N);\n    for (int i=1;i<N;++i){\n        int p; cin >> p;\n        HLD.add_edge(p,i);\n\
    \    }\n    HLD.build();\n\n    BinaryIndexedTree<long long> BIT(N);\n    for\
    \ (int i=0;i<N;++i) BIT.add(HLD.idx(i),a[i]);\n\n    for (;Q--;){\n        int\
    \ t,u; cin >> t >> u;\n        if (!t){\n            int x; cin >> x;\n      \
    \      BIT.add(HLD.idx(u),x);\n        } else {\n            cout << HLD.query_sub<long\
    \ long>(u,[&](int l,int r){return BIT.query(l,r);}) << '\\n';\n        }\n   \
    \ }\n}"
  dependsOn:
  - base.hpp
  - tree/HeavyLightDecomposition.hpp
  - datastructure/BinaryIndexedTree.hpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 15:22:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_subtree_sum.test.cpp
- /verify/test/yosupo/vertex_add_subtree_sum.test.cpp.html
title: test/yosupo/vertex_add_subtree_sum.test.cpp
---
