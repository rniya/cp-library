---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_3_D.SlidingWindowAggregation.test.cpp
    title: test/aoj/DSL_3_D.SlidingWindowAggregation.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/SlidingWindowAggregation.md
    document_title: Sliding Window Aggregation (SWAG)
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
    \  return (x > 0 ? x / y : (x + y - 1) / y);\n}\n\ntemplate <class T1, class T2>\
    \ inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2> inline\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n\nconst int INF = 1e9;\n\
    const long long IINF = 1e18;\nconst int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1,\
    \ 0, -1};\nconst char dir[4] = {'D', 'R', 'U', 'L'};\nconst long long MOD = 1000000007;\n\
    // const long long MOD = 998244353;\n#line 3 \"datastructure/SlidingWindowAggregation.hpp\"\
    \n\n/**\n * @brief Sliding Window Aggregation (SWAG)\n * @docs docs/datastructure/SlidingWindowAggregation.md\n\
    \ */\ntemplate <typename Monoid> struct SlidingWindowAggregation {\n    typedef\
    \ function<Monoid(Monoid, Monoid)> F;\n    stack<pair<Monoid, Monoid>> front_stack,\
    \ back_stack;\n    F f;\n    Monoid id;\n    SlidingWindowAggregation(F f, Monoid\
    \ id) : f(f), id(id), front_stack(), back_stack() {\n        front_stack.emplace(id,\
    \ id);\n        back_stack.emplace(id, id);\n    }\n    void push(const Monoid&\
    \ x) { back_stack.emplace(x, f(back_stack.top().second, x)); }\n    void pop()\
    \ {\n        if (front_stack.size() == 1) {\n            while (1 < (int)back_stack.size())\
    \ {\n                Monoid t = back_stack.top().first;\n                Monoid\
    \ calc = f(t, front_stack.top().second);\n                front_stack.emplace(t,\
    \ calc);\n                back_stack.pop();\n            }\n        }\n      \
    \  front_stack.pop();\n    }\n    Monoid fold() { return f(front_stack.top().second,\
    \ back_stack.top().second); }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Sliding Window Aggregation\
    \ (SWAG)\n * @docs docs/datastructure/SlidingWindowAggregation.md\n */\ntemplate\
    \ <typename Monoid> struct SlidingWindowAggregation {\n    typedef function<Monoid(Monoid,\
    \ Monoid)> F;\n    stack<pair<Monoid, Monoid>> front_stack, back_stack;\n    F\
    \ f;\n    Monoid id;\n    SlidingWindowAggregation(F f, Monoid id) : f(f), id(id),\
    \ front_stack(), back_stack() {\n        front_stack.emplace(id, id);\n      \
    \  back_stack.emplace(id, id);\n    }\n    void push(const Monoid& x) { back_stack.emplace(x,\
    \ f(back_stack.top().second, x)); }\n    void pop() {\n        if (front_stack.size()\
    \ == 1) {\n            while (1 < (int)back_stack.size()) {\n                Monoid\
    \ t = back_stack.top().first;\n                Monoid calc = f(t, front_stack.top().second);\n\
    \                front_stack.emplace(t, calc);\n                back_stack.pop();\n\
    \            }\n        }\n        front_stack.pop();\n    }\n    Monoid fold()\
    \ { return f(front_stack.top().second, back_stack.top().second); }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/SlidingWindowAggregation.hpp
  requiredBy: []
  timestamp: '2021-07-19 13:35:43+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/queue_operate_all_composite.test.cpp
  - test/aoj/DSL_3_D.SlidingWindowAggregation.test.cpp
documentation_of: datastructure/SlidingWindowAggregation.hpp
layout: document
redirect_from:
- /library/datastructure/SlidingWindowAggregation.hpp
- /library/datastructure/SlidingWindowAggregation.hpp.html
title: Sliding Window Aggregation (SWAG)
---
## 概要

## 計算量