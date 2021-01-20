---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_1_B.test.cpp
    title: test/aoj/DSL_1_B.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/datastructure/WeightedUnionFind.md
    document_title: Weighted UnionFind
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"datastructure/WeightedUnionFind.hpp\"\
    \n\n/**\n * @brief Weighted UnionFind\n * @docs docs/datastructure/WeightedUnionFind.md\n\
    \ */\ntemplate <typename Abel> struct WeightedUnionFind {\n    int num;\n    vector<int>\
    \ par, rank;\n    vector<Abel> diff_weight;\n    WeightedUnionFind(int n, Abel\
    \ id = 0) : num(n), par(n), rank(n, 1), diff_weight(n, Abel(0)) {\n        iota(par.begin(),\
    \ par.end(), 0);\n    }\n    int root(int x) {\n        if (x == par[x]) return\
    \ x;\n        int t = root(par[x]);\n        diff_weight[x] += diff_weight[par[x]];\n\
    \        return par[x] = t;\n    }\n    bool merge(int x, int y, Abel w) {\n \
    \       w += weight(x), w -= weight(y);\n        x = root(x), y = root(y);\n \
    \       if (x == y) return false;\n        if (rank[x] < rank[y]) swap(x, y),\
    \ w = -w;\n        par[y] = x;\n        rank[x] += rank[y];\n        diff_weight[y]\
    \ = w;\n        num--;\n        return true;\n    }\n    Abel weight(int x) {\n\
    \        root(x);\n        return diff_weight[x];\n    }\n    Abel diff(int x,\
    \ int y) { return weight(y) - weight(x); }\n    bool same(int x, int y) { return\
    \ root(x) == root(y); }\n    int size(int x) { return rank[root(x)]; }\n    int\
    \ count() { return num; }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Weighted UnionFind\n\
    \ * @docs docs/datastructure/WeightedUnionFind.md\n */\ntemplate <typename Abel>\
    \ struct WeightedUnionFind {\n    int num;\n    vector<int> par, rank;\n    vector<Abel>\
    \ diff_weight;\n    WeightedUnionFind(int n, Abel id = 0) : num(n), par(n), rank(n,\
    \ 1), diff_weight(n, Abel(0)) {\n        iota(par.begin(), par.end(), 0);\n  \
    \  }\n    int root(int x) {\n        if (x == par[x]) return x;\n        int t\
    \ = root(par[x]);\n        diff_weight[x] += diff_weight[par[x]];\n        return\
    \ par[x] = t;\n    }\n    bool merge(int x, int y, Abel w) {\n        w += weight(x),\
    \ w -= weight(y);\n        x = root(x), y = root(y);\n        if (x == y) return\
    \ false;\n        if (rank[x] < rank[y]) swap(x, y), w = -w;\n        par[y] =\
    \ x;\n        rank[x] += rank[y];\n        diff_weight[y] = w;\n        num--;\n\
    \        return true;\n    }\n    Abel weight(int x) {\n        root(x);\n   \
    \     return diff_weight[x];\n    }\n    Abel diff(int x, int y) { return weight(y)\
    \ - weight(x); }\n    bool same(int x, int y) { return root(x) == root(y); }\n\
    \    int size(int x) { return rank[root(x)]; }\n    int count() { return num;\
    \ }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/WeightedUnionFind.hpp
  requiredBy: []
  timestamp: '2021-01-20 10:53:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_1_B.test.cpp
documentation_of: datastructure/WeightedUnionFind.hpp
layout: document
redirect_from:
- /library/datastructure/WeightedUnionFind.hpp
- /library/datastructure/WeightedUnionFind.hpp.html
title: Weighted UnionFind
---
## 概要

## 計算量