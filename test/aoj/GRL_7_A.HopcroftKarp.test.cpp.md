---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: flow/HopcroftKarp.hpp
    title: Hopcroft Karp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A
  bundledCode: "#line 1 \"test/aoj/GRL_7_A.HopcroftKarp.test.cpp\"\n#define PROBLEM\
    \ \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A\"\n\n#line 2 \"base.hpp\"\
    \n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef\
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
    \ return false;\n}\n#line 3 \"flow/HopcroftKarp.hpp\"\n\n/**\n * @brief Hopcroft\
    \ Karp\n * @docs docs/flow/HopcroftKarp.md\n */\nstruct HopcroftKarp {\nprivate:\n\
    \    int n, m;\n    bool matched;\n    vector<vector<int>> G, rG;\n    vector<int>\
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
    \        }\n        return res;\n    }\n};\n#line 5 \"test/aoj/GRL_7_A.HopcroftKarp.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int X,\
    \ Y, E;\n    cin >> X >> Y >> E;\n\n    HopcroftKarp HK(X, Y);\n    for (int i\
    \ = 0; i < E; i++) {\n        int x, y;\n        cin >> x >> y;\n        HK.add_edge(x,\
    \ y);\n    }\n\n    cout << HK.max_matching().size() << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A\"\n\n\
    #include \"../../base.hpp\"\n#include \"../../flow/HopcroftKarp.hpp\"\n\nint main()\
    \ {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int X, Y, E;\n   \
    \ cin >> X >> Y >> E;\n\n    HopcroftKarp HK(X, Y);\n    for (int i = 0; i < E;\
    \ i++) {\n        int x, y;\n        cin >> x >> y;\n        HK.add_edge(x, y);\n\
    \    }\n\n    cout << HK.max_matching().size() << '\\n';\n}"
  dependsOn:
  - base.hpp
  - flow/HopcroftKarp.hpp
  isVerificationFile: true
  path: test/aoj/GRL_7_A.HopcroftKarp.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 11:24:35+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_7_A.HopcroftKarp.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_7_A.HopcroftKarp.test.cpp
- /verify/test/aoj/GRL_7_A.HopcroftKarp.test.cpp.html
title: test/aoj/GRL_7_A.HopcroftKarp.test.cpp
---
