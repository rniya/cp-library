---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_B.test.cpp
    title: test/aoj/DPL_5_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_C.test.cpp
    title: test/aoj/DPL_5_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_D.test.cpp
    title: test/aoj/DPL_5_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_E.test.cpp
    title: test/aoj/DPL_5_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_F.test.cpp
    title: test/aoj/DPL_5_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_G.test.cpp
    title: test/aoj/DPL_5_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_I.test.cpp
    title: test/aoj/DPL_5_I.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1302.test.cpp
    title: test/yukicoder/1302.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/combinatorics/combination.md
    document_title: combination
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"combinatorics/combination.hpp\"\
    \n\n/**\n * @brief combination\n * @docs docs/combinatorics/combination.md\n */\n\
    template <class M> struct Combination {\n    vector<M> _fac, _inv, _finv;\n  \
    \  Combination(int n) : _fac(n + 1), _inv(n + 1), _finv(n + 1) {\n        _fac[0]\
    \ = _finv[n] = _inv[0] = 1;\n        for (int i = 1; i <= n; i++) _fac[i] = _fac[i\
    \ - 1] * i;\n        _finv[n] /= _fac[n];\n        for (int i = n - 1; i >= 0;\
    \ i--) _finv[i] = _finv[i + 1] * (i + 1);\n        for (int i = 1; i <= n; i++)\
    \ _inv[i] = _finv[i] * _fac[i - 1];\n    }\n    M fac(int k) const { return _fac[k];\
    \ }\n    M finv(int k) const { return _finv[k]; }\n    M inv(int k) const { return\
    \ _inv[k]; }\n    M P(int n, int r) const {\n        if (n < 0 || r < 0 || n <\
    \ r) return 0;\n        return _fac[n] * _finv[n - r];\n    }\n    M C(int n,\
    \ int r) const {\n        if (n < 0 || r < 0 || n < r) return 0;\n        return\
    \ _fac[n] * _finv[r] * _finv[n - r];\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief combination\n *\
    \ @docs docs/combinatorics/combination.md\n */\ntemplate <class M> struct Combination\
    \ {\n    vector<M> _fac, _inv, _finv;\n    Combination(int n) : _fac(n + 1), _inv(n\
    \ + 1), _finv(n + 1) {\n        _fac[0] = _finv[n] = _inv[0] = 1;\n        for\
    \ (int i = 1; i <= n; i++) _fac[i] = _fac[i - 1] * i;\n        _finv[n] /= _fac[n];\n\
    \        for (int i = n - 1; i >= 0; i--) _finv[i] = _finv[i + 1] * (i + 1);\n\
    \        for (int i = 1; i <= n; i++) _inv[i] = _finv[i] * _fac[i - 1];\n    }\n\
    \    M fac(int k) const { return _fac[k]; }\n    M finv(int k) const { return\
    \ _finv[k]; }\n    M inv(int k) const { return _inv[k]; }\n    M P(int n, int\
    \ r) const {\n        if (n < 0 || r < 0 || n < r) return 0;\n        return _fac[n]\
    \ * _finv[n - r];\n    }\n    M C(int n, int r) const {\n        if (n < 0 ||\
    \ r < 0 || n < r) return 0;\n        return _fac[n] * _finv[r] * _finv[n - r];\n\
    \    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: combinatorics/combination.hpp
  requiredBy: []
  timestamp: '2021-01-20 10:53:49+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DPL_5_E.test.cpp
  - test/aoj/DPL_5_G.test.cpp
  - test/aoj/DPL_5_D.test.cpp
  - test/aoj/DPL_5_C.test.cpp
  - test/aoj/DPL_5_I.test.cpp
  - test/aoj/DPL_5_F.test.cpp
  - test/aoj/DPL_5_B.test.cpp
  - test/yukicoder/1302.test.cpp
documentation_of: combinatorics/combination.hpp
layout: document
redirect_from:
- /library/combinatorics/combination.hpp
- /library/combinatorics/combination.hpp.html
title: combination
---
## 概要

## 計算量