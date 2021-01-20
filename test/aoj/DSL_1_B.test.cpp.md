---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/WeightedUnionFind.hpp
    title: Weighted UnionFind
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B
  bundledCode: "#line 1 \"test/aoj/DSL_1_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\
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
    \ count() { return num; }\n};\n#line 5 \"test/aoj/DSL_1_B.test.cpp\"\n\nint main()\
    \ {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n, q;\n    cin\
    \ >> n >> q;\n\n    WeightedUnionFind<int> UF(n);\n\n    for (; q--;) {\n    \
    \    int c, x, y, z;\n        cin >> c >> x >> y;\n        if (!c) {\n       \
    \     cin >> z;\n            UF.merge(x, y, z);\n        } else {\n          \
    \  if (UF.same(x, y))\n                cout << UF.diff(x, y) << '\\n';\n     \
    \       else\n                cout << '?' << '\\n';\n        }\n    }\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/WeightedUnionFind.hpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n,\
    \ q;\n    cin >> n >> q;\n\n    WeightedUnionFind<int> UF(n);\n\n    for (; q--;)\
    \ {\n        int c, x, y, z;\n        cin >> c >> x >> y;\n        if (!c) {\n\
    \            cin >> z;\n            UF.merge(x, y, z);\n        } else {\n   \
    \         if (UF.same(x, y))\n                cout << UF.diff(x, y) << '\\n';\n\
    \            else\n                cout << '?' << '\\n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/WeightedUnionFind.hpp
  isVerificationFile: true
  path: test/aoj/DSL_1_B.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_1_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_1_B.test.cpp
- /verify/test/aoj/DSL_1_B.test.cpp.html
title: test/aoj/DSL_1_B.test.cpp
---
