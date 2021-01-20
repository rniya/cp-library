---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':x:'
    path: graph/StronglyConnectedComponents.hpp
    title: Strongly Connected Components
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/graph/TwoSatisfiability.md
    document_title: 2-SAT
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"graph/StronglyConnectedComponents.hpp\"\
    \n\n/**\n * @brief Strongly Connected Components\n * @docs docs/graph/StronglyConnectedComponents.md\n\
    \ */\nstruct StronglyConnectedComponents {\n    vector<vector<int>> G, rG, C,\
    \ T;\n    vector<int> vs, cmp, used;\n    StronglyConnectedComponents(int n) :\
    \ G(n), rG(n), cmp(n), used(n) {}\n    void add_edge(int u, int v) {\n       \
    \ G[u].emplace_back(v);\n        rG[v].emplace_back(u);\n    }\n    void dfs(int\
    \ v) {\n        used[v] = 1;\n        for (int u : G[v])\n            if (!used[u])\
    \ dfs(u);\n        vs.emplace_back(v);\n    }\n    void rdfs(int v, int k) {\n\
    \        used[v] = 1;\n        cmp[v] = k;\n        C[k].emplace_back(v);\n  \
    \      for (int u : rG[v])\n            if (!used[u]) rdfs(u, k);\n    }\n   \
    \ int build() {\n        int n = G.size();\n        for (int i = 0; i < n; i++)\n\
    \            if (!used[i]) dfs(i);\n        fill(used.begin(), used.end(), 0);\n\
    \        int k = 0;\n        for (int i = n - 1; i >= 0; --i) {\n            if\
    \ (!used[vs[i]]) {\n                C.emplace_back(), T.emplace_back();\n    \
    \            rdfs(vs[i], k++);\n            }\n        }\n        for (int v =\
    \ 0; v < n; v++) {\n            for (int u : G[v]) {\n                if (cmp[v]\
    \ != cmp[u]) {\n                    T[cmp[v]].emplace_back(cmp[u]);\n        \
    \        }\n            }\n        }\n        for (int i = 0; i < k; i++) {\n\
    \            sort(T[i].begin(), T[i].end());\n            T[i].erase(unique(T[i].begin(),\
    \ T[i].end()), T[i].end());\n        }\n        return k;\n    }\n    int operator[](int\
    \ i) const { return cmp[i]; }\n};\n#line 4 \"graph/TwoSatisfiability.hpp\"\n\n\
    /**\n * @brief 2-SAT\n * @docs docs/graph/TwoSatisfiability.md\n */\nstruct TwoSatisfiability\
    \ {\n    int n;\n    StronglyConnectedComponents SCC;\n    TwoSatisfiability(int\
    \ n) : n(n), SCC(n * 2) {}\n    int neg(int v) { return (n + v) % (n * 2); }\n\
    \    void add_if(int u, int v) {\n        SCC.add_edge(u, v);\n        SCC.add_edge(neg(v),\
    \ neg(u));\n    }\n    void add_or(int u, int v) { add_if(neg(u), v); }\n    void\
    \ add_nand(int u, int v) { add_if(u, neg(v)); }\n    void set_true(int v) { SCC.add_edge(neg(v),\
    \ v); }\n    void set_false(int v) { SCC.add_edge(v, neg(v)); }\n    vector<int>\
    \ build() {\n        SCC.build();\n        vector<int> res(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            if (SCC[i] == SCC[n + i]) return {};\n   \
    \         res[i] = SCC[i] > SCC[n + i];\n        }\n        return res;\n    }\n\
    };\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"StronglyConnectedComponents.hpp\"\
    \n\n/**\n * @brief 2-SAT\n * @docs docs/graph/TwoSatisfiability.md\n */\nstruct\
    \ TwoSatisfiability {\n    int n;\n    StronglyConnectedComponents SCC;\n    TwoSatisfiability(int\
    \ n) : n(n), SCC(n * 2) {}\n    int neg(int v) { return (n + v) % (n * 2); }\n\
    \    void add_if(int u, int v) {\n        SCC.add_edge(u, v);\n        SCC.add_edge(neg(v),\
    \ neg(u));\n    }\n    void add_or(int u, int v) { add_if(neg(u), v); }\n    void\
    \ add_nand(int u, int v) { add_if(u, neg(v)); }\n    void set_true(int v) { SCC.add_edge(neg(v),\
    \ v); }\n    void set_false(int v) { SCC.add_edge(v, neg(v)); }\n    vector<int>\
    \ build() {\n        SCC.build();\n        vector<int> res(n);\n        for (int\
    \ i = 0; i < n; i++) {\n            if (SCC[i] == SCC[n + i]) return {};\n   \
    \         res[i] = SCC[i] > SCC[n + i];\n        }\n        return res;\n    }\n\
    };"
  dependsOn:
  - base.hpp
  - graph/StronglyConnectedComponents.hpp
  isVerificationFile: false
  path: graph/TwoSatisfiability.hpp
  requiredBy: []
  timestamp: '2021-01-20 10:53:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/two_sat.test.cpp
documentation_of: graph/TwoSatisfiability.hpp
layout: document
redirect_from:
- /library/graph/TwoSatisfiability.hpp
- /library/graph/TwoSatisfiability.hpp.html
title: 2-SAT
---
## 概要

## 計算量