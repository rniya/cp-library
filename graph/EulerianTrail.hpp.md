---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/codeforces/1361_C.cpp
    title: test/codeforces/1361_C.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/583.test.cpp
    title: test/yukicoder/583.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/EulerianTrail.md
    document_title: "\u30AA\u30A4\u30E9\u30FC\u8DEF\u30FB\u6E96\u30AA\u30A4\u30E9\u30FC\
      \u8DEF\u306E\u69CB\u7BC9"
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"graph/EulerianTrail.hpp\"\
    \n\n/**\n * @brief \u30AA\u30A4\u30E9\u30FC\u8DEF\u30FB\u6E96\u30AA\u30A4\u30E9\
    \u30FC\u8DEF\u306E\u69CB\u7BC9\n * @docs docs/graph/EulerianTrail.md\n */\ntemplate\
    \ <bool directed> class EulerianTrail {\n    void dfs(int v, int& s, int& t, int&\
    \ check) {\n        visited[v] = 1;\n        if (directed) {\n            if (abs(deg[v])\
    \ > 1)\n                check = 0;\n            else if (deg[v] == 1) {\n    \
    \            if (~s)\n                    check = 0;\n                else\n \
    \                   s = v;\n            }\n        } else {\n            if (deg[v]\
    \ & 1) {\n                if (s < 0)\n                    s = v;\n           \
    \     else if (t < 0)\n                    t = v;\n                else\n    \
    \                check = 0;\n            }\n        }\n        for (int u : BG[v])\
    \ {\n            if (visited[u]) continue;\n            dfs(u, s, t, check);\n\
    \        }\n    }\n    vector<int> go(int s) {\n        stack<pair<int, int>>\
    \ st;\n        vector<int> ord;\n        st.emplace(s, -1);\n        while (!st.empty())\
    \ {\n            int v = st.top().first;\n            visited[v] = 1;\n      \
    \      if (G[v].empty()) {\n                ord.emplace_back(st.top().second);\n\
    \                st.pop();\n            } else {\n                auto e = G[v].back();\n\
    \                G[v].pop_back();\n                if (used[e.second]) continue;\n\
    \                used[e.second] = 1;\n                st.emplace(e);\n       \
    \     }\n        }\n        ord.pop_back();\n        reverse(ord.begin(), ord.end());\n\
    \        return ord;\n    }\n\npublic:\n    vector<vector<pair<int, int>>> G;\n\
    \    vector<vector<int>> BG;\n    vector<pair<int, int>> es;\n    vector<int>\
    \ used, visited, deg;\n    EulerianTrail(int n) : G(n), BG(n), visited(n, 0),\
    \ deg(n, 0) {}\n    void add_edge(int u, int v) {\n        int m = es.size();\n\
    \        es.emplace_back(u, v);\n        used.emplace_back(0);\n        BG[u].emplace_back(v);\n\
    \        BG[v].emplace_back(u);\n        G[u].emplace_back(v, m);\n        deg[u]++;\n\
    \        if (directed)\n            --deg[v];\n        else\n            G[v].emplace_back(u,\
    \ m), deg[v]++;\n    }\n    vector<vector<int>> build() {\n        for (int i\
    \ = 0; i < G.size(); i++) {\n            if (directed && deg[i] != 0) return {};\n\
    \            if (!directed && (deg[i] & 1)) return {};\n        }\n        vector<vector<int>>\
    \ res;\n        for (int i = 0; i < G.size(); i++) {\n            if (G[i].empty()\
    \ || visited[i]) continue;\n            res.emplace_back(go(i));\n        }\n\
    \        return res;\n    }\n    vector<vector<int>> build_semi() {\n        vector<vector<int>>\
    \ res;\n        for (int i = 0; i < G.size(); i++) {\n            if (visited[i])\
    \ continue;\n            int s = -1, t = -1, check = 1;\n            dfs(i, s,\
    \ t, check);\n            if (!check) return {};\n            res.emplace_back(go(~s\
    \ ? s : i));\n            if (res.back().empty()) res.pop_back();\n        }\n\
    \        return res;\n    }\n    pair<int, int> operator[](int i) { return es[i];\
    \ }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief \u30AA\u30A4\u30E9\
    \u30FC\u8DEF\u30FB\u6E96\u30AA\u30A4\u30E9\u30FC\u8DEF\u306E\u69CB\u7BC9\n * @docs\
    \ docs/graph/EulerianTrail.md\n */\ntemplate <bool directed> class EulerianTrail\
    \ {\n    void dfs(int v, int& s, int& t, int& check) {\n        visited[v] = 1;\n\
    \        if (directed) {\n            if (abs(deg[v]) > 1)\n                check\
    \ = 0;\n            else if (deg[v] == 1) {\n                if (~s)\n       \
    \             check = 0;\n                else\n                    s = v;\n \
    \           }\n        } else {\n            if (deg[v] & 1) {\n             \
    \   if (s < 0)\n                    s = v;\n                else if (t < 0)\n\
    \                    t = v;\n                else\n                    check =\
    \ 0;\n            }\n        }\n        for (int u : BG[v]) {\n            if\
    \ (visited[u]) continue;\n            dfs(u, s, t, check);\n        }\n    }\n\
    \    vector<int> go(int s) {\n        stack<pair<int, int>> st;\n        vector<int>\
    \ ord;\n        st.emplace(s, -1);\n        while (!st.empty()) {\n          \
    \  int v = st.top().first;\n            visited[v] = 1;\n            if (G[v].empty())\
    \ {\n                ord.emplace_back(st.top().second);\n                st.pop();\n\
    \            } else {\n                auto e = G[v].back();\n               \
    \ G[v].pop_back();\n                if (used[e.second]) continue;\n          \
    \      used[e.second] = 1;\n                st.emplace(e);\n            }\n  \
    \      }\n        ord.pop_back();\n        reverse(ord.begin(), ord.end());\n\
    \        return ord;\n    }\n\npublic:\n    vector<vector<pair<int, int>>> G;\n\
    \    vector<vector<int>> BG;\n    vector<pair<int, int>> es;\n    vector<int>\
    \ used, visited, deg;\n    EulerianTrail(int n) : G(n), BG(n), visited(n, 0),\
    \ deg(n, 0) {}\n    void add_edge(int u, int v) {\n        int m = es.size();\n\
    \        es.emplace_back(u, v);\n        used.emplace_back(0);\n        BG[u].emplace_back(v);\n\
    \        BG[v].emplace_back(u);\n        G[u].emplace_back(v, m);\n        deg[u]++;\n\
    \        if (directed)\n            --deg[v];\n        else\n            G[v].emplace_back(u,\
    \ m), deg[v]++;\n    }\n    vector<vector<int>> build() {\n        for (int i\
    \ = 0; i < G.size(); i++) {\n            if (directed && deg[i] != 0) return {};\n\
    \            if (!directed && (deg[i] & 1)) return {};\n        }\n        vector<vector<int>>\
    \ res;\n        for (int i = 0; i < G.size(); i++) {\n            if (G[i].empty()\
    \ || visited[i]) continue;\n            res.emplace_back(go(i));\n        }\n\
    \        return res;\n    }\n    vector<vector<int>> build_semi() {\n        vector<vector<int>>\
    \ res;\n        for (int i = 0; i < G.size(); i++) {\n            if (visited[i])\
    \ continue;\n            int s = -1, t = -1, check = 1;\n            dfs(i, s,\
    \ t, check);\n            if (!check) return {};\n            res.emplace_back(go(~s\
    \ ? s : i));\n            if (res.back().empty()) res.pop_back();\n        }\n\
    \        return res;\n    }\n    pair<int, int> operator[](int i) { return es[i];\
    \ }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/EulerianTrail.hpp
  requiredBy:
  - test/codeforces/1361_C.cpp
  timestamp: '2021-01-19 15:36:15+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/583.test.cpp
documentation_of: graph/EulerianTrail.hpp
layout: document
redirect_from:
- /library/graph/EulerianTrail.hpp
- /library/graph/EulerianTrail.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u8DEF\u30FB\u6E96\u30AA\u30A4\u30E9\u30FC\u8DEF\u306E\
  \u69CB\u7BC9"
---
## 概要
有向/無向グラフが与えられたときに, オイラー路/準オイラー路を構築する.
- `add_edge(u,v)`：辺$(u,v)$を追加する.
- `build()`：各連結成分についてオイラー路を構築する. オイラー路が存在しない連結成分があれば空列を返す.
- `build_semi()`：各連結成分について準オイラー路を構築する. 準オイラー路が存在しない連結成分があれば空列を返す.
- `operator[]`：$i$番目に追加した辺の情報$(u,v)$を返す.

## 計算量
どれも$O(V+E)$

## 参照
[競プロにおけるオイラー路とその応用について - Learning Algorithms](https://kokiymgch.hatenablog.com/entry/2017/12/07/193238)