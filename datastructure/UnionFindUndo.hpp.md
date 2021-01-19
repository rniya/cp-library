---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/codeforces/1444_C.cpp
    title: test/codeforces/1444_C.cpp
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
    title: test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/datastructure/UnionFindUndo.md
    document_title: "UnionFind (Undo\u53EF\u80FD)"
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"datastructure/UnionFindUndo.hpp\"\
    \n\n/**\n * @brief UnionFind (Undo\u53EF\u80FD)\n * @docs docs/datastructure/UnionFindUndo.md\n\
    \ */\nstruct UnionFindUndo {\n    vector<int> dat;\n    stack<pair<int, int>>\
    \ hist;\n    UnionFindUndo(int n) : dat(n, -1) {}\n    int root(int x) { return\
    \ (dat[x] < 0 ? x : root(dat[x])); }\n    bool merge(int x, int y) {\n       \
    \ x = root(x);\n        y = root(y);\n        hist.emplace(x, dat[x]);\n     \
    \   hist.emplace(y, dat[y]);\n        if (x == y) return false;\n        if (dat[x]\
    \ > dat[y]) swap(x, y);\n        dat[x] += dat[y];\n        dat[y] = x;\n    \
    \    return true;\n    }\n    void undo() {\n        dat[hist.top().first] = hist.top().second;\n\
    \        hist.pop();\n        dat[hist.top().first] = hist.top().second;\n   \
    \     hist.pop();\n    }\n    void snapshot() {\n        while (!hist.empty())\
    \ hist.pop();\n    }\n    void rollback() {\n        while (!hist.empty()) undo();\n\
    \    }\n    bool same(int x, int y) { return root(x) == root(y); }\n    int size(int\
    \ x) { return -dat[root(x)]; }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief UnionFind (Undo\u53EF\
    \u80FD)\n * @docs docs/datastructure/UnionFindUndo.md\n */\nstruct UnionFindUndo\
    \ {\n    vector<int> dat;\n    stack<pair<int, int>> hist;\n    UnionFindUndo(int\
    \ n) : dat(n, -1) {}\n    int root(int x) { return (dat[x] < 0 ? x : root(dat[x]));\
    \ }\n    bool merge(int x, int y) {\n        x = root(x);\n        y = root(y);\n\
    \        hist.emplace(x, dat[x]);\n        hist.emplace(y, dat[y]);\n        if\
    \ (x == y) return false;\n        if (dat[x] > dat[y]) swap(x, y);\n        dat[x]\
    \ += dat[y];\n        dat[y] = x;\n        return true;\n    }\n    void undo()\
    \ {\n        dat[hist.top().first] = hist.top().second;\n        hist.pop();\n\
    \        dat[hist.top().first] = hist.top().second;\n        hist.pop();\n   \
    \ }\n    void snapshot() {\n        while (!hist.empty()) hist.pop();\n    }\n\
    \    void rollback() {\n        while (!hist.empty()) undo();\n    }\n    bool\
    \ same(int x, int y) { return root(x) == root(y); }\n    int size(int x) { return\
    \ -dat[root(x)]; }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/UnionFindUndo.hpp
  requiredBy:
  - test/codeforces/1444_C.cpp
  timestamp: '2021-01-19 14:04:24+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
documentation_of: datastructure/UnionFindUndo.hpp
layout: document
redirect_from:
- /library/datastructure/UnionFindUndo.hpp
- /library/datastructure/UnionFindUndo.hpp.html
title: "UnionFind (Undo\u53EF\u80FD)"
---
## 概要
経路圧縮せずにマージテクにより集合を管理する過程を保持することでrollbackを可能にしたUnionFind.
- `root(x)`：$x$の集合の根を返す.
- `merge(x,y)`：$x$と$y$の属する集合をマージする.
- `undo()`：直前のマージを巻き戻す.
- `snapshot()`：それまでのマージ過程を保存する.
- `rollback()`：直前に`snapshot()`された時間まで状態をrollbackする.
- `same(x,y)`：現時点で$x$と$y$が同じ集合にいるかどうか判定する.
- `size(x)`：$x$の属する集合の大きさを返す.

## 計算量
クエリあたり$O(\log n)$

## 参照
[Mo's algorithm とその上位互換の話 - あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2016/07/01/000000)