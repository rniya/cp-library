---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: flow/ProjectSelectionProblem.hpp
    title: Project Selection Problem
  - icon: ':warning:'
    path: test/atcoder/arc085_c.cpp
    title: test/atcoder/arc085_c.cpp
  - icon: ':warning:'
    path: test/codeforces/1404_E.cpp
    title: test/codeforces/1404_E.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2313.test.cpp
    title: test/aoj/2313.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2903.test.cpp
    title: test/aoj/2903.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.DInic.test.cpp
    title: test/aoj/GRL_6_A.DInic.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/Dinic.md
    document_title: Dinic
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n \
    \       os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return\
    \ os;\n}\ntemplate <typename T, typename U, typename V> ostream& operator<<(ostream&\
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
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\n\
    template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail)\
    \ {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"flow/Dinic.hpp\"\n\n/**\n\
    \ * @brief Dinic\n * @docs docs/flow/Dinic.md\n */\ntemplate <typename T, bool\
    \ directed> struct Dinic {\n    struct edge {\n        int to, rev;\n        T\
    \ cap;\n        edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}\n\
    \    };\n    vector<vector<edge>> G;\n    vector<pair<int, int>> pos;\n    vector<int>\
    \ level, iter;\n    Dinic(int n) : G(n), level(n), iter(n) {}\n    int add_edge(int\
    \ from, int to, T cap) {\n        pos.emplace_back(from, G[from].size());\n  \
    \      G[from].emplace_back(to, cap, G[to].size());\n        G[to].emplace_back(from,\
    \ directed ? 0 : cap, G[from].size() - 1);\n        return pos.size() - 1;\n \
    \   }\n    int add_vertex() {\n        G.emplace_back();\n        level.emplace_back();\n\
    \        iter.emplace_back();\n        return G.size() - 1;\n    }\n    tuple<int,\
    \ int, int, int> get_edge(int i) {\n        auto e = G[pos[i].first][pos[i].second];\n\
    \        auto re = G[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap\
    \ + re.cap, re.cap};\n    }\n    vector<tuple<int, int, int, int>> edges() {\n\
    \        vector<tuple<int, int, int, int>> res;\n        for (int i = 0; i < (int)pos.size();\
    \ i++) {\n            res.emplace_back(get_edge(i));\n        }\n        return\
    \ res;\n    }\n    void change_edge(int i, T new_cap, T new_flow) {\n        auto&\
    \ e = G[pos[i].first][pos[i].second];\n        auto& re = G[e.to][e.rev];\n  \
    \      e.cap = new_cap - new_flow;\n        re.cap = (directed ? new_flow : new_cap\
    \ + new_flow);\n    }\n    void bfs(int s) {\n        fill(level.begin(), level.end(),\
    \ -1);\n        queue<int> que;\n        level[s] = 0;\n        que.emplace(s);\n\
    \        while (!que.empty()) {\n            int v = que.front();\n          \
    \  que.pop();\n            for (auto& e : G[v]) {\n                if (e.cap >\
    \ 0 && level[e.to] < 0) {\n                    level[e.to] = level[v] + 1;\n \
    \                   que.emplace(e.to);\n                }\n            }\n   \
    \     }\n    }\n    T dfs(int v, int t, T f) {\n        if (v == t) return f;\n\
    \        for (int& i = iter[v]; i < (int)G[v].size(); i++) {\n            auto&\
    \ e = G[v][i];\n            if (e.cap > 0 && level[v] < level[e.to]) {\n     \
    \           T d = dfs(e.to, t, min(f, e.cap));\n                if (d <= 0) continue;\n\
    \                e.cap -= d;\n                G[e.to][e.rev].cap += d;\n     \
    \           return d;\n            }\n        }\n        return 0;\n    }\n  \
    \  T max_flow(int s, int t, T lim) {\n        T flow = 0;\n        while (lim\
    \ > 0) {\n            bfs(s);\n            if (level[t] < 0) break;\n        \
    \    fill(iter.begin(), iter.end(), 0);\n            while (lim > 0) {\n     \
    \           T f = dfs(s, t, lim);\n                if (f == 0) break;\n      \
    \          flow += f;\n                lim -= f;\n            }\n        }\n \
    \       return flow;\n    }\n    T max_flow(int s, int t) { return max_flow(s,\
    \ t, numeric_limits<T>::max()); }\n    vector<bool> min_cut(int s) {\n       \
    \ vector<bool> res(G.size());\n        queue<int> que;\n        res[s] = true;\n\
    \        que.emplace(s);\n        while (!que.empty()) {\n            int v =\
    \ que.front();\n            que.pop();\n            for (auto e : G[v]) {\n  \
    \              if (e.cap > 0 && !res[e.to]) {\n                    res[e.to] =\
    \ true;\n                    que.emplace(e.to);\n                }\n         \
    \   }\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Dinic\n * @docs\
    \ docs/flow/Dinic.md\n */\ntemplate <typename T, bool directed> struct Dinic {\n\
    \    struct edge {\n        int to, rev;\n        T cap;\n        edge(int to,\
    \ T cap, int rev) : to(to), cap(cap), rev(rev) {}\n    };\n    vector<vector<edge>>\
    \ G;\n    vector<pair<int, int>> pos;\n    vector<int> level, iter;\n    Dinic(int\
    \ n) : G(n), level(n), iter(n) {}\n    int add_edge(int from, int to, T cap) {\n\
    \        pos.emplace_back(from, G[from].size());\n        G[from].emplace_back(to,\
    \ cap, G[to].size());\n        G[to].emplace_back(from, directed ? 0 : cap, G[from].size()\
    \ - 1);\n        return pos.size() - 1;\n    }\n    int add_vertex() {\n     \
    \   G.emplace_back();\n        level.emplace_back();\n        iter.emplace_back();\n\
    \        return G.size() - 1;\n    }\n    tuple<int, int, int, int> get_edge(int\
    \ i) {\n        auto e = G[pos[i].first][pos[i].second];\n        auto re = G[e.to][e.rev];\n\
    \        return {pos[i].first, e.to, e.cap + re.cap, re.cap};\n    }\n    vector<tuple<int,\
    \ int, int, int>> edges() {\n        vector<tuple<int, int, int, int>> res;\n\
    \        for (int i = 0; i < (int)pos.size(); i++) {\n            res.emplace_back(get_edge(i));\n\
    \        }\n        return res;\n    }\n    void change_edge(int i, T new_cap,\
    \ T new_flow) {\n        auto& e = G[pos[i].first][pos[i].second];\n        auto&\
    \ re = G[e.to][e.rev];\n        e.cap = new_cap - new_flow;\n        re.cap =\
    \ (directed ? new_flow : new_cap + new_flow);\n    }\n    void bfs(int s) {\n\
    \        fill(level.begin(), level.end(), -1);\n        queue<int> que;\n    \
    \    level[s] = 0;\n        que.emplace(s);\n        while (!que.empty()) {\n\
    \            int v = que.front();\n            que.pop();\n            for (auto&\
    \ e : G[v]) {\n                if (e.cap > 0 && level[e.to] < 0) {\n         \
    \           level[e.to] = level[v] + 1;\n                    que.emplace(e.to);\n\
    \                }\n            }\n        }\n    }\n    T dfs(int v, int t, T\
    \ f) {\n        if (v == t) return f;\n        for (int& i = iter[v]; i < (int)G[v].size();\
    \ i++) {\n            auto& e = G[v][i];\n            if (e.cap > 0 && level[v]\
    \ < level[e.to]) {\n                T d = dfs(e.to, t, min(f, e.cap));\n     \
    \           if (d <= 0) continue;\n                e.cap -= d;\n             \
    \   G[e.to][e.rev].cap += d;\n                return d;\n            }\n     \
    \   }\n        return 0;\n    }\n    T max_flow(int s, int t, T lim) {\n     \
    \   T flow = 0;\n        while (lim > 0) {\n            bfs(s);\n            if\
    \ (level[t] < 0) break;\n            fill(iter.begin(), iter.end(), 0);\n    \
    \        while (lim > 0) {\n                T f = dfs(s, t, lim);\n          \
    \      if (f == 0) break;\n                flow += f;\n                lim -=\
    \ f;\n            }\n        }\n        return flow;\n    }\n    T max_flow(int\
    \ s, int t) { return max_flow(s, t, numeric_limits<T>::max()); }\n    vector<bool>\
    \ min_cut(int s) {\n        vector<bool> res(G.size());\n        queue<int> que;\n\
    \        res[s] = true;\n        que.emplace(s);\n        while (!que.empty())\
    \ {\n            int v = que.front();\n            que.pop();\n            for\
    \ (auto e : G[v]) {\n                if (e.cap > 0 && !res[e.to]) {\n        \
    \            res[e.to] = true;\n                    que.emplace(e.to);\n     \
    \           }\n            }\n        }\n        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: flow/Dinic.hpp
  requiredBy:
  - flow/ProjectSelectionProblem.hpp
  - test/codeforces/1404_E.cpp
  - test/atcoder/arc085_c.cpp
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2903.test.cpp
  - test/aoj/2313.test.cpp
  - test/aoj/GRL_6_A.DInic.test.cpp
documentation_of: flow/Dinic.hpp
layout: document
redirect_from:
- /library/flow/Dinic.hpp
- /library/flow/Dinic.hpp.html
title: Dinic
---
## 概要

## 計算量