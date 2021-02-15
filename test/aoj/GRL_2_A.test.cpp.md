---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/Kruskal.hpp
    title: Kruskal
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A
  bundledCode: "#line 1 \"test/aoj/GRL_2_A.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"graph/Kruskal.hpp\"\n\n\
    /**\n * @brief Kruskal\n * @docs docs/graph/Kruskal.md\n */\ntemplate <typename\
    \ T> struct Kruskal {\nprivate:\n    struct edge {\n        int from, to, used,\
    \ id;\n        T cost;\n        edge(int from, int to, T cost, int id) : from(from),\
    \ to(to), cost(cost), id(id), used(0) {}\n        bool operator<(const edge& e)\
    \ const {\n            if (cost != e.cost)\n                return cost < e.cost;\n\
    \            else if (from != e.from)\n                return from < e.from;\n\
    \            else\n                return to < e.to;\n        }\n    };\n    vector<edge>\
    \ es;\n    vector<int> par, rank;\n    int root(int x) {\n        if (par[x] ==\
    \ x) return x;\n        return par[x] = root(par[x]);\n    }\n    bool merge(int\
    \ x, int y) {\n        x = root(x), y = root(y);\n        if (x == y) return false;\n\
    \        if (rank[x] < rank[y]) swap(x, y);\n        par[y] = x;\n        rank[x]\
    \ += rank[y];\n        return true;\n    }\n    bool same(int x, int y) { return\
    \ root(x) == root(y); }\n    int size(int x) { return rank[root(x)]; }\n\npublic:\n\
    \    Kruskal(int n) : par(n), rank(n, 1) { iota(par.begin(), par.end(), 0); }\n\
    \    void add_edge(int u, int v, T c, int id = 0) { es.emplace_back(u, v, c, id);\
    \ }\n    T build() {\n        sort(es.begin(), es.end());\n        T res = 0;\n\
    \        for (auto& e : es) {\n            if (!same(e.from, e.to)) {\n      \
    \          res += e.cost;\n                e.used = 1;\n                merge(e.from,\
    \ e.to);\n            }\n        }\n        return res;\n    }\n    vector<int>\
    \ restore(T& c) {\n        int m = es.size();\n        vector<int> res(m);\n \
    \       for (int i = 0; i < m; i++) res[es[i].id] = es[i].used;\n        return\
    \ res;\n    }\n};\n#line 5 \"test/aoj/GRL_2_A.test.cpp\"\n\nint main() {\n   \
    \ cin.tie(0);\n    ios::sync_with_stdio(false);\n    int V, E;\n    cin >> V >>\
    \ E;\n\n    Kruskal<int> K(V);\n\n    for (int i = 0; i < E; i++) {\n        int\
    \ s, t, w;\n        cin >> s >> t >> w;\n        K.add_edge(s, t, w);\n    }\n\
    \n    cout << K.build() << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../graph/Kruskal.hpp\"\n\nint main()\
    \ {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int V, E;\n    cin\
    \ >> V >> E;\n\n    Kruskal<int> K(V);\n\n    for (int i = 0; i < E; i++) {\n\
    \        int s, t, w;\n        cin >> s >> t >> w;\n        K.add_edge(s, t, w);\n\
    \    }\n\n    cout << K.build() << '\\n';\n}"
  dependsOn:
  - base.hpp
  - graph/Kruskal.hpp
  isVerificationFile: true
  path: test/aoj/GRL_2_A.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_2_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_2_A.test.cpp
- /verify/test/aoj/GRL_2_A.test.cpp.html
title: test/aoj/GRL_2_A.test.cpp
---
