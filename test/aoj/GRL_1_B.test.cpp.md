---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/BellmanFord.hpp
    title: Bellman Ford
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B
  bundledCode: "#line 1 \"test/aoj/GRL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"graph/BellmanFord.hpp\"\
    \n\n/**\n * @brief Bellman Ford\n * @docs docs/graph/BellmanFord.md\n */\ntemplate\
    \ <typename T> struct BellmanFord {\n    const T inf = numeric_limits<T>::max();\n\
    \    struct edge {\n        int u, v;\n        T w;\n        edge(int u, int v,\
    \ T w) : u(u), v(v), w(w) {}\n    };\n    int n;\n    vector<vector<int>> G;\n\
    \    vector<int> check, reach;\n    vector<edge> es;\n    BellmanFord(int n) :\
    \ n(n), G(n), check(n), reach(n, 1) {}\n    void add_edge(int u, int v, T w) {\n\
    \        es.emplace_back(u, v, w);\n        G[u].emplace_back(v);\n    }\n   \
    \ vector<T> build(int s, int& neg_loop) {\n        vector<T> d(n, inf);\n    \
    \    d[s] = 0;\n        for (int i = 0; i < n; i++) {\n            bool update\
    \ = false;\n            for (auto e : es) {\n                if (!reach[e.u] ||\
    \ !reach[e.v] || d[e.u] == inf) continue;\n                if (d[e.u] + e.w <\
    \ d[e.v]) {\n                    d[e.v] = d[e.u] + e.w;\n                    update\
    \ = true;\n                }\n            }\n            if (!update) break;\n\
    \            if (i == n - 1) {\n                neg_loop = 1;\n              \
    \  return d;\n            }\n        }\n        neg_loop = 0;\n        return\
    \ d;\n    }\n    void dfs(int v) {\n        if (check[v]) return;\n        check[v]\
    \ = 1;\n        for (int u : G[v]) dfs(u);\n    }\n    T shortest_path(int s,\
    \ int t, int& neg_loop) {\n        for (int i = 0; i < n; i++) {\n           \
    \ fill(check.begin(), check.end(), 0);\n            dfs(i);\n            reach[i]\
    \ = check[t];\n        }\n        return build(s, neg_loop)[t];\n    }\n};\n#line\
    \ 5 \"test/aoj/GRL_1_B.test.cpp\"\n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int V,E,r; cin >> V >> E >> r;\n\n    BellmanFord<int> BF(V);\n\n    for\
    \ (int i=0;i<E;++i){\n        int s,t,d; cin >> s >> t >> d;\n        BF.add_edge(s,t,d);\n\
    \    }\n\n    int neg;\n    vector<int> ans=BF.build(r,neg);\n    if (neg){cout\
    \ << \"NEGATIVE CYCLE\" << '\\n'; return 0;}\n    for (int i=0;i<V;++i){\n   \
    \     if (ans[i]>1e9) cout << \"INF\" << '\\n';\n        else cout << ans[i] <<\
    \ '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_B\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../graph/BellmanFord.hpp\"\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int V,E,r;\
    \ cin >> V >> E >> r;\n\n    BellmanFord<int> BF(V);\n\n    for (int i=0;i<E;++i){\n\
    \        int s,t,d; cin >> s >> t >> d;\n        BF.add_edge(s,t,d);\n    }\n\n\
    \    int neg;\n    vector<int> ans=BF.build(r,neg);\n    if (neg){cout << \"NEGATIVE\
    \ CYCLE\" << '\\n'; return 0;}\n    for (int i=0;i<V;++i){\n        if (ans[i]>1e9)\
    \ cout << \"INF\" << '\\n';\n        else cout << ans[i] << '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - graph/BellmanFord.hpp
  isVerificationFile: true
  path: test/aoj/GRL_1_B.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 15:36:15+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_1_B.test.cpp
- /verify/test/aoj/GRL_1_B.test.cpp.html
title: test/aoj/GRL_1_B.test.cpp
---