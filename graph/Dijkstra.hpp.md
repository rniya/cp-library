---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_1_A.test.cpp
    title: test/aoj/GRL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/shortest_path.test.cpp
    title: test/yosupo/shortest_path.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/Dijkstra.md
    document_title: Dijkstra
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    const long long MOD = 1000000007;\n// const long long MOD=998244353;\nconst int\
    \ INF = 1e9;\nconst long long IINF = 1e18;\nconst int dx[4] = {1, 0, -1, 0}, dy[4]\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"graph/Dijkstra.hpp\"\n\n\
    /**\n * @brief Dijkstra\n * @docs docs/graph/Dijkstra.md\n */\ntemplate <typename\
    \ T> struct Dijkstra {\n    struct edge {\n        int to;\n        T cost;\n\
    \        edge(int to, T cost) : to(to), cost(cost) {}\n        bool operator<(const\
    \ edge& e) const { return cost > e.cost; }\n    };\n    vector<vector<edge>> G;\n\
    \    vector<T> dp;\n    vector<int> pre;\n    Dijkstra(int n) : G(n), dp(n), pre(n)\
    \ {}\n    void add_edge(int u, int v, T c) { G[u].emplace_back(v, c); }\n    void\
    \ build(int s) {\n        int n = G.size();\n        fill(dp.begin(), dp.end(),\
    \ numeric_limits<T>::max());\n        fill(pre.begin(), pre.end(), -1);\n    \
    \    priority_queue<edge> pq;\n        dp[s] = 0;\n        pq.emplace(s, dp[s]);\n\
    \        while (!pq.empty()) {\n            auto p = pq.top();\n            pq.pop();\n\
    \            int v = p.to;\n            if (dp[v] < p.cost) continue;\n      \
    \      for (auto e : G[v]) {\n                if (dp[v] + e.cost < dp[e.to]) {\n\
    \                    dp[e.to] = dp[v] + e.cost;\n                    pre[e.to]\
    \ = v;\n                    pq.emplace(e.to, dp[e.to]);\n                }\n \
    \           }\n        }\n    }\n    vector<int> restore(int t) {\n        vector<int>\
    \ res;\n        if (pre[t] < 0) return res;\n        while (~t) {\n          \
    \  res.emplace_back(t);\n            t = pre[t];\n        }\n        reverse(res.begin(),\
    \ res.end());\n        return res;\n    }\n    T operator[](int to) { return dp[to];\
    \ }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Dijkstra\n * @docs\
    \ docs/graph/Dijkstra.md\n */\ntemplate <typename T> struct Dijkstra {\n    struct\
    \ edge {\n        int to;\n        T cost;\n        edge(int to, T cost) : to(to),\
    \ cost(cost) {}\n        bool operator<(const edge& e) const { return cost > e.cost;\
    \ }\n    };\n    vector<vector<edge>> G;\n    vector<T> dp;\n    vector<int> pre;\n\
    \    Dijkstra(int n) : G(n), dp(n), pre(n) {}\n    void add_edge(int u, int v,\
    \ T c) { G[u].emplace_back(v, c); }\n    void build(int s) {\n        int n =\
    \ G.size();\n        fill(dp.begin(), dp.end(), numeric_limits<T>::max());\n \
    \       fill(pre.begin(), pre.end(), -1);\n        priority_queue<edge> pq;\n\
    \        dp[s] = 0;\n        pq.emplace(s, dp[s]);\n        while (!pq.empty())\
    \ {\n            auto p = pq.top();\n            pq.pop();\n            int v\
    \ = p.to;\n            if (dp[v] < p.cost) continue;\n            for (auto e\
    \ : G[v]) {\n                if (dp[v] + e.cost < dp[e.to]) {\n              \
    \      dp[e.to] = dp[v] + e.cost;\n                    pre[e.to] = v;\n      \
    \              pq.emplace(e.to, dp[e.to]);\n                }\n            }\n\
    \        }\n    }\n    vector<int> restore(int t) {\n        vector<int> res;\n\
    \        if (pre[t] < 0) return res;\n        while (~t) {\n            res.emplace_back(t);\n\
    \            t = pre[t];\n        }\n        reverse(res.begin(), res.end());\n\
    \        return res;\n    }\n    T operator[](int to) { return dp[to]; }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/Dijkstra.hpp
  requiredBy: []
  timestamp: '2021-01-19 15:36:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/shortest_path.test.cpp
  - test/aoj/GRL_1_A.test.cpp
documentation_of: graph/Dijkstra.hpp
layout: document
redirect_from:
- /library/graph/Dijkstra.hpp
- /library/graph/Dijkstra.hpp.html
title: Dijkstra
---
## 概要

## 計算量