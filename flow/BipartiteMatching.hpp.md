---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/GRL_7_A.test.cpp
    title: test/aoj/GRL_7_A.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/flow/BipartiteMatching.md
    document_title: "2\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\
      \u30F3\u30B0"
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"flow/BipartiteMatching.hpp\"\
    \n\n/**\n * @brief 2\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\
    \u30F3\u30B0\n * @docs docs/flow/BipartiteMatching.md\n */\nstruct BipartiteMatching\
    \ {\n    vector<vector<int>> G;\n    vector<int> match, alive, used;\n    int\
    \ time = 0;\n    BipartiteMatching(int n) : G(n), match(n, -1), alive(n, 1), used(n,\
    \ 0) {}\n    void add_edge(int u, int v) {\n        G[u].emplace_back(v);\n  \
    \      G[v].emplace_back(u);\n    }\n    bool dfs(int v) {\n        used[v] =\
    \ time;\n        for (int u : G[v]) {\n            int w = match[u];\n       \
    \     if (!alive[u]) continue;\n            if (w < 0 || (used[w] != time && dfs(w)))\
    \ {\n                match[v] = u;\n                match[u] = v;\n          \
    \      return true;\n            }\n        }\n        return false;\n    }\n\
    \    int build() {\n        int res = 0;\n        for (int i = 0; i < G.size();\
    \ i++) {\n            if (!alive[i]) continue;\n            if (~match[i]) continue;\n\
    \            time++;\n            res += dfs(i);\n        }\n        return res;\n\
    \    }\n    int enable(int v) {\n        alive[v] = 1;\n        time++;\n    \
    \    return dfs(v);\n    }\n    int disable(int v) {\n        alive[v] = 0;\n\
    \        if (match[v] < 0) return 0;\n        match[v] = -1;\n        match[match[v]]\
    \ = -1;\n        time++;\n        int res = dfs(match[v]);\n        return res\
    \ - 1;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief 2\u90E8\u30B0\u30E9\
    \u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0\n * @docs docs/flow/BipartiteMatching.md\n\
    \ */\nstruct BipartiteMatching {\n    vector<vector<int>> G;\n    vector<int>\
    \ match, alive, used;\n    int time = 0;\n    BipartiteMatching(int n) : G(n),\
    \ match(n, -1), alive(n, 1), used(n, 0) {}\n    void add_edge(int u, int v) {\n\
    \        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n    bool\
    \ dfs(int v) {\n        used[v] = time;\n        for (int u : G[v]) {\n      \
    \      int w = match[u];\n            if (!alive[u]) continue;\n            if\
    \ (w < 0 || (used[w] != time && dfs(w))) {\n                match[v] = u;\n  \
    \              match[u] = v;\n                return true;\n            }\n  \
    \      }\n        return false;\n    }\n    int build() {\n        int res = 0;\n\
    \        for (int i = 0; i < G.size(); i++) {\n            if (!alive[i]) continue;\n\
    \            if (~match[i]) continue;\n            time++;\n            res +=\
    \ dfs(i);\n        }\n        return res;\n    }\n    int enable(int v) {\n  \
    \      alive[v] = 1;\n        time++;\n        return dfs(v);\n    }\n    int\
    \ disable(int v) {\n        alive[v] = 0;\n        if (match[v] < 0) return 0;\n\
    \        match[v] = -1;\n        match[match[v]] = -1;\n        time++;\n    \
    \    int res = dfs(match[v]);\n        return res - 1;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: flow/BipartiteMatching.hpp
  requiredBy: []
  timestamp: '2021-01-20 10:53:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/GRL_7_A.test.cpp
documentation_of: flow/BipartiteMatching.hpp
layout: document
redirect_from:
- /library/flow/BipartiteMatching.hpp
- /library/flow/BipartiteMatching.hpp.html
title: "2\u90E8\u30B0\u30E9\u30D5\u306E\u6700\u5927\u30DE\u30C3\u30C1\u30F3\u30B0"
---
## 概要
2部グラフの最大マッチングを求める. 基本的にはHopcroft-Karpのアルゴリズムの方が高速なのでそちらを使うのが良い. 頂点番号の振り方に注意.

- `add_edge(u,v)`：$u$と$v$の間に辺を張る.
- `build()`：最大マッチングの大きさを求める.

## 計算量
$O(EV)$