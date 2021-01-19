---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: tree/LowestCommonAncestor.hpp
    title: Lowest Common Ancestor
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
  bundledCode: "#line 1 \"test/aoj/GRL_5_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\"\
    \n\n#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\nconst\
    \ long long MOD = 1000000007;\n// const long long MOD=998244353;\nconst int INF\
    \ = 1e9;\nconst long long IINF = 1e18;\nconst int dx[4] = {1, 0, -1, 0}, dy[4]\
    \ = {0, 1, 0, -1};\nconst char dir[4] = {'D', 'R', 'U', 'L'};\n#define LOCAL\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n      \
    \  os << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const pair<T,\
    \ U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
    }\ntemplate <typename T, typename U, typename V> ostream& operator<<(ostream&\
    \ os, const tuple<T, U, V>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t)\
    \ << ',' << get<2>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U,\
    \ V, W>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t)\
    \ << ',' << get<3>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U> ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n\
    \    for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const unordered_map<T, U>& m) {\n    os << '{';\n  \
    \  for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const multiset<T>& s) {\n    os << '{';\n    for (auto itr = s.begin();\
    \ itr != s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os <<\
    \ ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream&\
    \ operator<<(ostream& os, const unordered_set<T>& s) {\n    os << '{';\n    for\
    \ (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n        if (++itr\
    \ != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const deque<T>& v) {\n    for (int i = 0;\
    \ i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" : \" \"\
    );\n    }\n    return os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate\
    \ <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail) {\n\
    \    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
    }\n#ifdef LOCAL\n#define debug(...)                                          \
    \                         \\\n    cerr << \" \";                             \
    \                                        \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) 42\n#endif\n\ntemplate <typename\
    \ T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename\
    \ T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class\
    \ T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n   \
    \     return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2>\
    \ inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\n#line 3 \"tree/LowestCommonAncestor.hpp\"\
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
    \            }\n        }\n    }\n    int lca(int u, int v) {\n        if (dep[u]\
    \ > dep[v]) swap(u, v);\n        for (int k = 0; k < h; k++) {\n            if\
    \ ((dep[v] - dep[u]) & 1 << k) {\n                v = par[k][v];\n           \
    \ }\n        }\n        if (u == v) return u;\n        for (int k = h - 1; k >=\
    \ 0; --k) {\n            if (par[k][u] != par[k][v]) {\n                u = par[k][u];\n\
    \                v = par[k][v];\n            }\n        }\n        return par[0][u];\n\
    \    }\n    int distance(int u, int v) { return dep[u] + dep[v] - dep[lca(u, v)]\
    \ * 2; }\n};\n#line 5 \"test/aoj/GRL_5_C.test.cpp\"\n\nint main(){\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int n; cin >> n;\n\n    LowestCommonAncestor\
    \ LCA(n);\n    for (int i=0;i<n;++i){\n        int k; cin >> k;\n        for (;k--;){\n\
    \            int c; cin >> c;\n            LCA.add_edge(i,c);\n        }\n   \
    \ }\n    LCA.build();\n\n    int q; cin >> q;\n    for (;q--;){\n        int u,v;\
    \ cin >> u >> v;\n        cout << LCA.lca(u,v) << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\"\n\n\
    #include \"../../base.hpp\"\n#include \"../../tree/LowestCommonAncestor.hpp\"\n\
    \nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n; cin\
    \ >> n;\n\n    LowestCommonAncestor LCA(n);\n    for (int i=0;i<n;++i){\n    \
    \    int k; cin >> k;\n        for (;k--;){\n            int c; cin >> c;\n  \
    \          LCA.add_edge(i,c);\n        }\n    }\n    LCA.build();\n\n    int q;\
    \ cin >> q;\n    for (;q--;){\n        int u,v; cin >> u >> v;\n        cout <<\
    \ LCA.lca(u,v) << '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - tree/LowestCommonAncestor.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_C.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 15:22:36+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_C.test.cpp
- /verify/test/aoj/GRL_5_C.test.cpp.html
title: test/aoj/GRL_5_C.test.cpp
---
