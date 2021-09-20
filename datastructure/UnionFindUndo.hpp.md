---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/codeforces/1444_C.cpp
    title: test/codeforces/1444_C.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
    title: test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/UnionFindUndo.md
    document_title: "UnionFind (Undo\u53EF\u80FD)"
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef\
    \ unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first <<\
    \ ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n   \
    \ for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
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
    \" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&,\
    \ const T&) {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
    \ os, const T& t) {\n    if (i) os << ',';\n    os << get<i>(t);\n    print_tuple<i\
    \ + 1, T, Args...>(os, t);\n}\ntemplate <typename... Args> ostream& operator<<(ostream&\
    \ os, const tuple<Args...>& t) {\n    os << '{';\n    print_tuple<0, tuple<Args...>,\
    \ Args...>(os, t);\n    return os << '}';\n}\n\nvoid debug_out() { cerr << '\\\
    n'; }\ntemplate <class Head, class... Tail> void debug_out(Head&& head, Tail&&...\
    \ tail) {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n \
    \   debug_out(move(tail)...);\n}\n#ifdef LOCAL\n#define debug(...)           \
    \                                                        \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ cerr << #__VA_ARGS__ << \" :[\" << __LINE__ << \":\" << __FUNCTION__ << \"]\"\
    \ << '\\n'; \\\n    cerr << \" \";                                           \
    \                          \\\n    debug_out(__VA_ARGS__)\n#else\n#define debug(...)\
    \ 42\n#endif\n\ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y,\
    \ x % y) : x; }\ntemplate <typename T> T lcm(T x, T y) { return x / gcd(x, y)\
    \ * y; }\n\nint topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\nint topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n\
    int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long\
    \ long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\nint popcount(signed t)\
    \ { return __builtin_popcount(t); }\nint popcount(long long t) { return __builtin_popcountll(t);\
    \ }\nbool ispow2(int i) { return i && (i & -i) == i; }\n\ntemplate <class T> T\
    \ ceil(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? (x + y - 1) / y :\
    \ x / y);\n}\ntemplate <class T> T floor(T x, T y) {\n    assert(y >= 1);\n  \
    \  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <class T1, class T2>\
    \ inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2> inline\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"datastructure/UnionFindUndo.hpp\"\
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
  timestamp: '2021-07-19 14:45:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
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
- `merge(x, y)`：$x$と$y$の属する集合をマージする.
- `undo()`：直前のマージを巻き戻す.
- `snapshot()`：それまでのマージ過程を保存する.
- `rollback()`：直前に`snapshot()`された時間まで状態をrollbackする.
- `same(x, y)`：現時点で$x$と$y$が同じ集合にいるかどうか判定する.
- `size(x)`：$x$の属する集合の大きさを返す.

## 計算量
クエリあたり$O(\log n)$

## 参照
[Mo's algorithm とその上位互換の話 - あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2016/07/01/000000)