---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
  bundledCode: "#line 1 \"test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp\"\n#define\
    \ PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\"\n\n#line 2 \"\
    base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long\
    \ ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\ntypedef unsigned\
    \ long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename\
    \ T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x : v) is >>\
    \ x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream& os,\
    \ const vector<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n        os\
    \ << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n}\ntemplate\
    \ <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>&\
    \ p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"tree/HeavyLightDecomposition.hpp\"\
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
    \ + edge, vid[u] + sub[u]);\n    }\n};\n#line 5 \"test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n;\n\
    \    cin >> n;\n\n    HeavyLightDecomposition HLD(n);\n    for (int i = 0; i <\
    \ n; i++) {\n        int k;\n        cin >> k;\n        for (; k--;) {\n     \
    \       int c;\n            cin >> c;\n            HLD.add_edge(i, c);\n     \
    \   }\n    }\n    HLD.build();\n\n    int q;\n    cin >> q;\n    for (; q--;)\
    \ {\n        int u, v;\n        cin >> u >> v;\n        cout << HLD.lca(u, v)\
    \ << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\"\n\n\
    #include \"../../base.hpp\"\n#include \"../../tree/HeavyLightDecomposition.hpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n;\n\
    \    cin >> n;\n\n    HeavyLightDecomposition HLD(n);\n    for (int i = 0; i <\
    \ n; i++) {\n        int k;\n        cin >> k;\n        for (; k--;) {\n     \
    \       int c;\n            cin >> c;\n            HLD.add_edge(i, c);\n     \
    \   }\n    }\n    HLD.build();\n\n    int q;\n    cin >> q;\n    for (; q--;)\
    \ {\n        int u, v;\n        cin >> u >> v;\n        cout << HLD.lca(u, v)\
    \ << '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 11:24:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp
- /verify/test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp.html
title: test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp
---