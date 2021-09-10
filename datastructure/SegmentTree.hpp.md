---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/ukuku09_d.cpp
    title: test/atcoder/ukuku09_d.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_range_sum.test.cpp
    title: test/yosupo/point_add_range_sum.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/vertex_add_path_sum.test.cpp
    title: test/yosupo/vertex_add_path_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/SegmentTree.md
    document_title: Segment Tree
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"datastructure/SegmentTree.hpp\"\
    \n\n/**\n * @brief Segment Tree\n * @docs docs/datastructure/SegmentTree.md\n\
    \ */\ntemplate <typename Monoid> struct SegmentTree {\n    typedef function<Monoid(Monoid,\
    \ Monoid)> F;\n    int n;\n    F f;\n    Monoid id;\n    vector<Monoid> dat;\n\
    \    SegmentTree(int n_, F f, Monoid id) : f(f), id(id) { init(n_); }\n    void\
    \ init(int n_) {\n        n = 1;\n        while (n < n_) n <<= 1;\n        dat.assign(n\
    \ << 1, id);\n    }\n    void build(const vector<Monoid>& v) {\n        for (int\
    \ i = 0; i < (int)v.size(); i++) dat[i + n] = v[i];\n        for (int i = n -\
    \ 1; i; i--) dat[i] = f(dat[i << 1 | 0], dat[i << 1 | 1]);\n    }\n    void update(int\
    \ k, Monoid x) {\n        dat[k += n] = x;\n        while (k >>= 1) dat[k] = f(dat[k\
    \ << 1 | 0], dat[k << 1 | 1]);\n    }\n    Monoid query(int a, int b) {\n    \
    \    if (a >= b) return id;\n        Monoid vl = id, vr = id;\n        for (int\
    \ l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) vl\
    \ = f(vl, dat[l++]);\n            if (r & 1) vr = f(dat[--r], vr);\n        }\n\
    \        return f(vl, vr);\n    }\n    template <typename C> int find_subtree(int\
    \ k, const C& check, Monoid& M, bool type) {\n        while (k < n) {\n      \
    \      Monoid nxt = type ? f(dat[k << 1 | type], M) : f(M, dat[k << 1 | type]);\n\
    \            if (check(nxt))\n                k = k << 1 | type;\n           \
    \ else\n                M = nxt, k = k << 1 | (type ^ 1);\n        }\n       \
    \ return k - n;\n    }\n    // min i s.t. f(seg[a],seg[a+1],...,seg[i]) satisfy\
    \ \"check\"\n    template <typename C> int find_first(int a, const C& check) {\n\
    \        Monoid L = id;\n        if (a <= 0) {\n            if (check(f(L, dat[1])))\
    \ return find_subtree(1, check, L, false);\n            return -1;\n        }\n\
    \        int b = n;\n        for (int l = a + n, r = b + n; l < r; l >>= 1, r\
    \ >>= 1) {\n            if (l & 1) {\n                Monoid nxt = f(L, dat[l]);\n\
    \                if (check(nxt)) return find_subtree(l, check, L, false);\n  \
    \              L = nxt;\n                l++;\n            }\n        }\n    \
    \    return -1;\n    }\n    // max i s.t. f(seg[i],...,seg[b-2],seg[b-1]) satisfy\
    \ \"check\"\n    template <typename C> int find_last(int b, const C& check) {\n\
    \        Monoid R = id;\n        if (b >= n) {\n            if (check(f(dat[1],\
    \ R))) return find_subtree(1, check, R, true);\n            return -1;\n     \
    \   }\n        int a = n;\n        for (int l = a, r = b + n; l < r; l >>= 1,\
    \ r >>= 1) {\n            if (r & 1) {\n                Monoid nxt = f(dat[--r],\
    \ R);\n                if (check(nxt)) return find_subtree(r, check, R, true);\n\
    \                R = nxt;\n            }\n        }\n        return -1;\n    }\n\
    \    Monoid operator[](int i) { return dat[i + n]; }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Segment Tree\n *\
    \ @docs docs/datastructure/SegmentTree.md\n */\ntemplate <typename Monoid> struct\
    \ SegmentTree {\n    typedef function<Monoid(Monoid, Monoid)> F;\n    int n;\n\
    \    F f;\n    Monoid id;\n    vector<Monoid> dat;\n    SegmentTree(int n_, F\
    \ f, Monoid id) : f(f), id(id) { init(n_); }\n    void init(int n_) {\n      \
    \  n = 1;\n        while (n < n_) n <<= 1;\n        dat.assign(n << 1, id);\n\
    \    }\n    void build(const vector<Monoid>& v) {\n        for (int i = 0; i <\
    \ (int)v.size(); i++) dat[i + n] = v[i];\n        for (int i = n - 1; i; i--)\
    \ dat[i] = f(dat[i << 1 | 0], dat[i << 1 | 1]);\n    }\n    void update(int k,\
    \ Monoid x) {\n        dat[k += n] = x;\n        while (k >>= 1) dat[k] = f(dat[k\
    \ << 1 | 0], dat[k << 1 | 1]);\n    }\n    Monoid query(int a, int b) {\n    \
    \    if (a >= b) return id;\n        Monoid vl = id, vr = id;\n        for (int\
    \ l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) vl\
    \ = f(vl, dat[l++]);\n            if (r & 1) vr = f(dat[--r], vr);\n        }\n\
    \        return f(vl, vr);\n    }\n    template <typename C> int find_subtree(int\
    \ k, const C& check, Monoid& M, bool type) {\n        while (k < n) {\n      \
    \      Monoid nxt = type ? f(dat[k << 1 | type], M) : f(M, dat[k << 1 | type]);\n\
    \            if (check(nxt))\n                k = k << 1 | type;\n           \
    \ else\n                M = nxt, k = k << 1 | (type ^ 1);\n        }\n       \
    \ return k - n;\n    }\n    // min i s.t. f(seg[a],seg[a+1],...,seg[i]) satisfy\
    \ \"check\"\n    template <typename C> int find_first(int a, const C& check) {\n\
    \        Monoid L = id;\n        if (a <= 0) {\n            if (check(f(L, dat[1])))\
    \ return find_subtree(1, check, L, false);\n            return -1;\n        }\n\
    \        int b = n;\n        for (int l = a + n, r = b + n; l < r; l >>= 1, r\
    \ >>= 1) {\n            if (l & 1) {\n                Monoid nxt = f(L, dat[l]);\n\
    \                if (check(nxt)) return find_subtree(l, check, L, false);\n  \
    \              L = nxt;\n                l++;\n            }\n        }\n    \
    \    return -1;\n    }\n    // max i s.t. f(seg[i],...,seg[b-2],seg[b-1]) satisfy\
    \ \"check\"\n    template <typename C> int find_last(int b, const C& check) {\n\
    \        Monoid R = id;\n        if (b >= n) {\n            if (check(f(dat[1],\
    \ R))) return find_subtree(1, check, R, true);\n            return -1;\n     \
    \   }\n        int a = n;\n        for (int l = a, r = b + n; l < r; l >>= 1,\
    \ r >>= 1) {\n            if (r & 1) {\n                Monoid nxt = f(dat[--r],\
    \ R);\n                if (check(nxt)) return find_subtree(r, check, R, true);\n\
    \                R = nxt;\n            }\n        }\n        return -1;\n    }\n\
    \    Monoid operator[](int i) { return dat[i + n]; }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/SegmentTree.hpp
  requiredBy:
  - test/atcoder/ukuku09_d.cpp
  timestamp: '2021-07-19 14:45:19+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/point_add_range_sum.test.cpp
  - test/yosupo/vertex_add_path_sum.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
  - test/aoj/DSL_2_A.test.cpp
documentation_of: datastructure/SegmentTree.hpp
layout: document
redirect_from:
- /library/datastructure/SegmentTree.hpp
- /library/datastructure/SegmentTree.hpp.html
title: Segment Tree
---
## 概要

## 計算量