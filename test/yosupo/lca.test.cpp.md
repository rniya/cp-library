---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/lca
    links:
    - https://judge.yosupo.jp/problem/lca
  bundledCode: "#line 1 \"test/yosupo/lca.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\
    \n\n#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#pragma\
    \ region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned\
    \ int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"tree/LowestCommonAncestor.hpp\"\
    \n\n/**\n * @brief Lowest Common Ancestor\n * @docs docs/tree/LowestCommonAncestor.md\n\
    \ */\nstruct LowestCommonAncestor {\n    int n, h;\n    vector<vector<int>> G,\
    \ par;\n    vector<int> dep;\n    LowestCommonAncestor(int n) : n(n), G(n), dep(n)\
    \ {\n        h = 1;\n        while ((1 << h) <= n) h++;\n        par.assign(h,\
    \ vector<int>(n, -1));\n    }\n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n\
    \        G[v].emplace_back(u);\n    }\n    void dfs(int v, int p, int d) {\n \
    \       par[0][v] = p;\n        dep[v] = d;\n        for (int u : G[v]) {\n  \
    \          if (u != p) dfs(u, v, d + 1);\n        }\n    }\n    void build(int\
    \ r = 0) {\n        dfs(r, -1, 0);\n        for (int k = 0; k < h - 1; k++) {\n\
    \            for (int v = 0; v < n; v++) {\n                if (par[k][v] >= 0)\
    \ {\n                    par[k + 1][v] = par[k][par[k][v]];\n                }\n\
    \            }\n        }\n    }\n    int ancestor(int v, int x) {\n        assert(x\
    \ <= dep[v]);\n        for (int k = 0; k < h; k++) {\n            if (x >> k &\
    \ 1) {\n                v = par[k][v];\n            }\n        }\n        return\
    \ v;\n    }\n    int lca(int u, int v) {\n        if (dep[u] > dep[v]) swap(u,\
    \ v);\n        for (int k = 0; k < h; k++) {\n            if ((dep[v] - dep[u])\
    \ & 1 << k) {\n                v = par[k][v];\n            }\n        }\n    \
    \    if (u == v) return u;\n        for (int k = h - 1; k >= 0; --k) {\n     \
    \       if (par[k][u] != par[k][v]) {\n                u = par[k][u];\n      \
    \          v = par[k][v];\n            }\n        }\n        return par[0][u];\n\
    \    }\n    int distance(int u, int v) { return dep[u] + dep[v] - dep[lca(u, v)]\
    \ * 2; }\n};\n#line 5 \"test/yosupo/lca.test.cpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int N, Q;\n    cin >> N >> Q;\n\n    LowestCommonAncestor\
    \ LCA(N);\n    for (int i = 1; i < N; i++) {\n        int p;\n        cin >> p;\n\
    \        LCA.add_edge(p, i);\n    }\n    LCA.build();\n\n    for (; Q--;) {\n\
    \        int u, v;\n        cin >> u >> v;\n        cout << LCA.lca(u, v) << '\\\
    n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/lca\"\n\n#include \"../../base.hpp\"\
    \n#include \"../../tree/LowestCommonAncestor.hpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int N, Q;\n    cin >> N >> Q;\n\n    LowestCommonAncestor\
    \ LCA(N);\n    for (int i = 1; i < N; i++) {\n        int p;\n        cin >> p;\n\
    \        LCA.add_edge(p, i);\n    }\n    LCA.build();\n\n    for (; Q--;) {\n\
    \        int u, v;\n        cin >> u >> v;\n        cout << LCA.lca(u, v) << '\\\
    n';\n    }\n}"
  dependsOn:
  - base.hpp
  - tree/LowestCommonAncestor.hpp
  isVerificationFile: true
  path: test/yosupo/lca.test.cpp
  requiredBy: []
  timestamp: '2021-07-19 14:45:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/lca.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/lca.test.cpp
- /verify/test/yosupo/lca.test.cpp.html
title: test/yosupo/lca.test.cpp
---
