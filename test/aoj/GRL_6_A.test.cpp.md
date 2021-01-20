---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: flow/FordFulkerson.hpp
    title: Ford Fulkerson
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A
  bundledCode: "#line 1 \"test/aoj/GRL_6_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\ntypedef\
    \ long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\ntypedef\
    \ unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename\
    \ T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x : v) is >>\
    \ x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream& os,\
    \ const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n     \
    \   os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"flow/FordFulkerson.hpp\"\
    \n\n/**\n * @brief Ford Fulkerson\n * @docs docs/flow/FordFulkerson.md\n */\n\
    template <typename T, bool directed> struct FordFulkerson {\n    struct edge {\n\
    \        int to, rev;\n        T cap;\n        edge(int to, T cap, int rev) :\
    \ to(to), cap(cap), rev(rev) {}\n    };\n    vector<vector<edge>> G;\n    vector<pair<int,\
    \ int>> pos;\n    vector<int> used;\n    FordFulkerson(int n) : G(n), used(n)\
    \ {}\n    int add_edge(int from, int to, T cap) {\n        pos.emplace_back(from,\
    \ G[from].size());\n        G[from].emplace_back(to, cap, G[to].size());\n   \
    \     G[to].emplace_back(from, directed ? 0 : cap, G[from].size() - 1);\n    \
    \    return pos.size() - 1;\n    }\n    tuple<int, int, int, int> get_edge(int\
    \ i) {\n        auto e = G[pos[i].first][pos[i].second];\n        auto re = G[e.to][e.rev];\n\
    \        return {pos[i].first, e.to, e.cap + re.cap, re.cap};\n    }\n    vector<tuple<int,\
    \ int, int, int>> edges() {\n        vector<tuple<int, int, int, int>> res;\n\
    \        for (int i = 0; i < (int)pos.size(); i++) {\n            res.emplace_back(get_edge(i));\n\
    \        }\n        return res;\n    }\n    T dfs(int v, int t, T f) {\n     \
    \   if (v == t) return f;\n        used[v] = true;\n        for (auto& e : G[v])\
    \ {\n            if (!used[e.to] && e.cap > 0) {\n                T d = dfs(e.to,\
    \ t, min(f, e.cap));\n                if (d <= 0) continue;\n                e.cap\
    \ -= d;\n                G[e.to][e.rev].cap += d;\n                return d;\n\
    \            }\n        }\n        return 0;\n    }\n    T max_flow(int s, int\
    \ t, T lim) {\n        T flow = 0;\n        while (lim > 0) {\n            fill(used.begin(),\
    \ used.end(), 0);\n            T f = dfs(s, t, lim);\n            if (f == 0)\
    \ break;\n            flow += f;\n            lim -= f;\n        }\n        return\
    \ flow;\n    }\n    T max_flow(int s, int t) { return max_flow(s, t, numeric_limits<T>::max());\
    \ }\n};\n#line 5 \"test/aoj/GRL_6_A.test.cpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int V, E;\n    cin >> V >> E;\n\n    FordFulkerson<int,\
    \ true> FF(V);\n\n    for (int i = 0; i < E; i++) {\n        int u, v, c;\n  \
    \      cin >> u >> v >> c;\n        FF.add_edge(u, v, c);\n    }\n\n    cout <<\
    \ FF.max_flow(0, V - 1) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../flow/FordFulkerson.hpp\"\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int V, E;\n\
    \    cin >> V >> E;\n\n    FordFulkerson<int, true> FF(V);\n\n    for (int i =\
    \ 0; i < E; i++) {\n        int u, v, c;\n        cin >> u >> v >> c;\n      \
    \  FF.add_edge(u, v, c);\n    }\n\n    cout << FF.max_flow(0, V - 1) << '\\n';\n\
    }"
  dependsOn:
  - base.hpp
  - flow/FordFulkerson.hpp
  isVerificationFile: true
  path: test/aoj/GRL_6_A.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_6_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_6_A.test.cpp
- /verify/test/aoj/GRL_6_A.test.cpp.html
title: test/aoj/GRL_6_A.test.cpp
---
