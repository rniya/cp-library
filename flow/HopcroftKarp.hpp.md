---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_7_A.HopcroftKarp.test.cpp
    title: test/aoj/GRL_7_A.HopcroftKarp.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/bipartitematching.test.cpp
    title: test/yosupo/bipartitematching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/HopcroftKarp.md
    document_title: Hopcroft Karp
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef\
    \ unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first <<\
    \ ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n   \
    \ for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
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
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&,\
    \ const T&) {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"flow/HopcroftKarp.hpp\"\
    \n\n/**\n * @brief Hopcroft Karp\n * @docs docs/flow/HopcroftKarp.md\n */\nstruct\
    \ HopcroftKarp {\nprivate:\n    int n, m;\n    bool matched;\n    vector<vector<int>>\
    \ G, rG;\n    vector<int> match_l, match_r, level;\n    void levelize() {\n  \
    \      queue<int> que;\n        for (int i = 0; i < n; i++) {\n            level[i]\
    \ = -1;\n            if (match_l[i] < 0) {\n                level[i] = 0;\n  \
    \              que.emplace(i);\n            }\n        }\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            for\
    \ (int u : G[v]) {\n                int w = match_r[u];\n                if (~w\
    \ && level[w] < 0) {\n                    level[w] = level[v] + 1;\n         \
    \           que.emplace(w);\n                }\n            }\n        }\n   \
    \ }\n    bool find_augumenting_path(int v) {\n        for (int u : G[v]) {\n \
    \           int w = match_r[u];\n            if (w < 0 || (level[w] > level[v]\
    \ && find_augumenting_path(w))) {\n                match_l[v] = u;\n         \
    \       match_r[u] = v;\n                return true;\n            }\n       \
    \ }\n        return false;\n    }\n    vector<vector<int>> build_residual_graph()\
    \ {\n        if (!matched) max_matching();\n        const int s = n + m, t = n\
    \ + m + 1;\n        vector<vector<int>> res(n + m + 2);\n        for (int i =\
    \ 0; i < n; i++) {\n            if (match_l[i] < 0) {\n                res[s].emplace_back(i);\n\
    \            }\n        }\n        for (int i = 0; i < n; i++) {\n           \
    \ for (int j : G[i]) {\n                if (match_l[i] == j)\n               \
    \     res[j + n].emplace_back(i);\n                else\n                    res[i].emplace_back(j\
    \ + n);\n            }\n        }\n        return res;\n    }\n    vector<bool>\
    \ find_residual_path() {\n        auto g = build_residual_graph();\n        queue<int>\
    \ que;\n        vector<bool> visited(n + m + 2);\n        que.emplace(n + m);\n\
    \        visited[n + m] = true;\n        while (!que.empty()) {\n            int\
    \ v = que.front();\n            que.pop();\n            for (int u : g[v]) {\n\
    \                if (visited[u]) continue;\n                visited[u] = true;\n\
    \                que.emplace(u);\n            }\n        }\n        return visited;\n\
    \    }\n\npublic:\n    HopcroftKarp(int n, int m) : n(n), m(m), G(n), rG(m), match_l(n,\
    \ -1), match_r(m, -1), level(n), matched(false) {}\n    void add_edge(int u, int\
    \ v) {\n        G[u].emplace_back(v);\n        rG[v].emplace_back(u);\n    }\n\
    \    vector<pair<int, int>> max_matching() {\n        matched = true;\n      \
    \  while (1) {\n            levelize();\n            int match = 0;\n        \
    \    for (int i = 0; i < n; i++) {\n                if (match_l[i] < 0) {\n  \
    \                  match += find_augumenting_path(i);\n                }\n   \
    \         }\n            if (!match) break;\n        }\n        vector<pair<int,\
    \ int>> res;\n        for (int i = 0; i < n; i++) {\n            if (~match_l[i])\
    \ {\n                res.emplace_back(i, match_l[i]);\n            }\n       \
    \ }\n        return res;\n    }\n    vector<int> min_vertex_cover() {\n      \
    \  auto visited = find_residual_path();\n        vector<int> res;\n        for\
    \ (int i = 0; i < n + m; i++) {\n            if (visited[i] ^ (i < n)) {\n   \
    \             res.emplace_back(i);\n            }\n        }\n        return res;\n\
    \    }\n    vector<int> max_independent_set() {\n        auto visited = find_residual_path();\n\
    \        vector<int> res;\n        for (int i = 0; i < n + m; i++) {\n       \
    \     if (visited[i] ^ (i >= n)) {\n                res.emplace_back(i);\n   \
    \         }\n        }\n        return res;\n    }\n    vector<pair<int, int>>\
    \ min_edge_cover() {\n        auto res = max_matching();\n        for (int i =\
    \ 0; i < n; i++) {\n            if (~match_l[i]) continue;\n            if (G[i].empty())\
    \ return {};\n            res.emplace_back(i, G[i][0]);\n        }\n        for\
    \ (int i = 0; i < m; i++) {\n            if (~match_r[i]) continue;\n        \
    \    if (rG[i].empty()) return {};\n            res.emplace_back(rG[i][0], i);\n\
    \        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Hopcroft Karp\n\
    \ * @docs docs/flow/HopcroftKarp.md\n */\nstruct HopcroftKarp {\nprivate:\n  \
    \  int n, m;\n    bool matched;\n    vector<vector<int>> G, rG;\n    vector<int>\
    \ match_l, match_r, level;\n    void levelize() {\n        queue<int> que;\n \
    \       for (int i = 0; i < n; i++) {\n            level[i] = -1;\n          \
    \  if (match_l[i] < 0) {\n                level[i] = 0;\n                que.emplace(i);\n\
    \            }\n        }\n        while (!que.empty()) {\n            int v =\
    \ que.front();\n            que.pop();\n            for (int u : G[v]) {\n   \
    \             int w = match_r[u];\n                if (~w && level[w] < 0) {\n\
    \                    level[w] = level[v] + 1;\n                    que.emplace(w);\n\
    \                }\n            }\n        }\n    }\n    bool find_augumenting_path(int\
    \ v) {\n        for (int u : G[v]) {\n            int w = match_r[u];\n      \
    \      if (w < 0 || (level[w] > level[v] && find_augumenting_path(w))) {\n   \
    \             match_l[v] = u;\n                match_r[u] = v;\n             \
    \   return true;\n            }\n        }\n        return false;\n    }\n   \
    \ vector<vector<int>> build_residual_graph() {\n        if (!matched) max_matching();\n\
    \        const int s = n + m, t = n + m + 1;\n        vector<vector<int>> res(n\
    \ + m + 2);\n        for (int i = 0; i < n; i++) {\n            if (match_l[i]\
    \ < 0) {\n                res[s].emplace_back(i);\n            }\n        }\n\
    \        for (int i = 0; i < n; i++) {\n            for (int j : G[i]) {\n   \
    \             if (match_l[i] == j)\n                    res[j + n].emplace_back(i);\n\
    \                else\n                    res[i].emplace_back(j + n);\n     \
    \       }\n        }\n        return res;\n    }\n    vector<bool> find_residual_path()\
    \ {\n        auto g = build_residual_graph();\n        queue<int> que;\n     \
    \   vector<bool> visited(n + m + 2);\n        que.emplace(n + m);\n        visited[n\
    \ + m] = true;\n        while (!que.empty()) {\n            int v = que.front();\n\
    \            que.pop();\n            for (int u : g[v]) {\n                if\
    \ (visited[u]) continue;\n                visited[u] = true;\n               \
    \ que.emplace(u);\n            }\n        }\n        return visited;\n    }\n\n\
    public:\n    HopcroftKarp(int n, int m) : n(n), m(m), G(n), rG(m), match_l(n,\
    \ -1), match_r(m, -1), level(n), matched(false) {}\n    void add_edge(int u, int\
    \ v) {\n        G[u].emplace_back(v);\n        rG[v].emplace_back(u);\n    }\n\
    \    vector<pair<int, int>> max_matching() {\n        matched = true;\n      \
    \  while (1) {\n            levelize();\n            int match = 0;\n        \
    \    for (int i = 0; i < n; i++) {\n                if (match_l[i] < 0) {\n  \
    \                  match += find_augumenting_path(i);\n                }\n   \
    \         }\n            if (!match) break;\n        }\n        vector<pair<int,\
    \ int>> res;\n        for (int i = 0; i < n; i++) {\n            if (~match_l[i])\
    \ {\n                res.emplace_back(i, match_l[i]);\n            }\n       \
    \ }\n        return res;\n    }\n    vector<int> min_vertex_cover() {\n      \
    \  auto visited = find_residual_path();\n        vector<int> res;\n        for\
    \ (int i = 0; i < n + m; i++) {\n            if (visited[i] ^ (i < n)) {\n   \
    \             res.emplace_back(i);\n            }\n        }\n        return res;\n\
    \    }\n    vector<int> max_independent_set() {\n        auto visited = find_residual_path();\n\
    \        vector<int> res;\n        for (int i = 0; i < n + m; i++) {\n       \
    \     if (visited[i] ^ (i >= n)) {\n                res.emplace_back(i);\n   \
    \         }\n        }\n        return res;\n    }\n    vector<pair<int, int>>\
    \ min_edge_cover() {\n        auto res = max_matching();\n        for (int i =\
    \ 0; i < n; i++) {\n            if (~match_l[i]) continue;\n            if (G[i].empty())\
    \ return {};\n            res.emplace_back(i, G[i][0]);\n        }\n        for\
    \ (int i = 0; i < m; i++) {\n            if (~match_r[i]) continue;\n        \
    \    if (rG[i].empty()) return {};\n            res.emplace_back(rG[i][0], i);\n\
    \        }\n        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: flow/HopcroftKarp.hpp
  requiredBy: []
  timestamp: '2021-07-19 14:45:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_7_A.HopcroftKarp.test.cpp
  - test/yosupo/bipartitematching.test.cpp
documentation_of: flow/HopcroftKarp.hpp
layout: document
redirect_from:
- /library/flow/HopcroftKarp.hpp
- /library/flow/HopcroftKarp.hpp.html
title: Hopcroft Karp
---
## 概要
Hopcroft-Karpのアルゴリズムにより2部グラフにおける最大マッチング, 最小点被覆, 最大独立集合, 最小辺被覆を求める.
- 最大マッチング：どの2辺も端点を共有しないような辺集合.
- 最小点被覆：各辺の端点のうち少なくとも一方を必ず含むような点集合.
- 最大独立集合：どの2頂点も辺で結ばれていないような点集合.
- 最小辺被覆：各頂点を端点にもつ辺を必ず含むような辺集合.

一般に, 点被覆の補集合は独立集合をなし, その逆も成立する. よって, 最小点被覆の補集合が最大安定集合となり, その逆も成り立つ.

また, 最大マッチングの辺集合に対して, マッチングの端点になっていないような各頂点を端点にもつような辺をGreedyに追加していくと最小辺被覆になる.

ここで, 2部グラフにおいては最大マッチングの大きさと最小点被覆の大きさが等しくなる. また, 最大マッチングを構築する際の残余グラフから最小点被覆を実際に構成でき, 他についても構成可能となる.

よって, それぞれの大きさについては, 頂点集合の大きさを$\|V\|$, 最大マッチングの大きさを$\|M\|$とすると, 最小点被覆は$\|M\|$, 最大独立集合は$\|V\|-\|M\|$, 最小辺被覆は$\|V\|-\|M\|$(ただし, 孤立点が存在する場合は辺被覆は存在しない)となる.

- `add_edge(u, v)`：$u$と$v$の間に辺を張る.
- `max_matching()`：最大マッチングを求める.
- `min_vertex_cover()`：最小点被覆を求める.
- `max_independent_set()`：最大独立集合を求める.
- `min_edge_cover()`：最小辺被覆を求める.

また, 頂点番号の振り方に注意.
## 計算量
各クエリ$O(E\sqrt{V})$

## 参照
- [二部グラフの最小点被覆、最大安定集合 (最大独立集合)、最小辺被覆を総整理！ - Qiita](https://qiita.com/drken/items/7f98315b56c95a6181a4)
- [二部グラフの最小点被覆と最大安定集合と最小辺被覆の求め方](https://www.slideshare.net/drken1215/ss-86894312)
- [2部グラフにおける最大マッチングの個数と最小点被覆の個数の一致 - komiyamの日記](https://komiyam.hatenadiary.org/entry/20110208/1297112982)
