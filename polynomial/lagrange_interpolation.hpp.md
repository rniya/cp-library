---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/665.test.cpp
    title: test/yukicoder/665.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/polynomial/lagrange_interpolation.md
    document_title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593"
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"polynomial/lagrange_interpolation.hpp\"\
    \n\n/**\n * @brief \u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593\n * @docs\
    \ docs/polynomial/lagrange_interpolation.md\n */\ntemplate <typename M> M lagrange_interpolation(vector<M>\
    \ x, vector<M> y, M T) {\n    int n = x.size() - 1;\n    M res = 0;\n    for (int\
    \ i = 0; i <= n; i++) {\n        M c = 1;\n        for (int j = 0; j <= n; j++)\
    \ {\n            if (i == j) continue;\n            (c *= T - x[j]) /= x[i] -\
    \ x[j];\n        }\n        res += c * y[i];\n    }\n    return res;\n}\n\ntemplate\
    \ <typename M> M lagrange_interpolation_arithmetic(vector<M>& y, M T) {\n    int\
    \ n = y.size() - 1;\n    if (T.v <= n) return y[T.v];\n    vector<M> left(n +\
    \ 1, 1), right(n + 1, 1), fac(n + 1, 1), finv(n + 1, 1);\n    for (int i = 0;\
    \ i < n; i++) left[i + 1] = left[i] * (T - i);\n    for (int i = n - 1; i >= 0;\
    \ --i) right[i] = right[i + 1] * (T - (i + 1));\n    for (int i = 1; i <= n; i++)\
    \ fac[i] = fac[i - 1] * i;\n    finv[n] = (M)1 / fac[n];\n    for (int i = n;\
    \ i > 0; --i) finv[i - 1] = finv[i] * i;\n    M res = 0;\n    for (int i = 0;\
    \ i <= n; i++) {\n        M add = y[i] * left[i] * right[i] * finv[i] * finv[n\
    \ - i];\n        if ((n - i) & 1)\n            res -= add;\n        else\n   \
    \         res += add;\n    }\n    return res;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief \u30E9\u30B0\u30E9\
    \u30F3\u30B8\u30E5\u88DC\u9593\n * @docs docs/polynomial/lagrange_interpolation.md\n\
    \ */\ntemplate <typename M> M lagrange_interpolation(vector<M> x, vector<M> y,\
    \ M T) {\n    int n = x.size() - 1;\n    M res = 0;\n    for (int i = 0; i <=\
    \ n; i++) {\n        M c = 1;\n        for (int j = 0; j <= n; j++) {\n      \
    \      if (i == j) continue;\n            (c *= T - x[j]) /= x[i] - x[j];\n  \
    \      }\n        res += c * y[i];\n    }\n    return res;\n}\n\ntemplate <typename\
    \ M> M lagrange_interpolation_arithmetic(vector<M>& y, M T) {\n    int n = y.size()\
    \ - 1;\n    if (T.v <= n) return y[T.v];\n    vector<M> left(n + 1, 1), right(n\
    \ + 1, 1), fac(n + 1, 1), finv(n + 1, 1);\n    for (int i = 0; i < n; i++) left[i\
    \ + 1] = left[i] * (T - i);\n    for (int i = n - 1; i >= 0; --i) right[i] = right[i\
    \ + 1] * (T - (i + 1));\n    for (int i = 1; i <= n; i++) fac[i] = fac[i - 1]\
    \ * i;\n    finv[n] = (M)1 / fac[n];\n    for (int i = n; i > 0; --i) finv[i -\
    \ 1] = finv[i] * i;\n    M res = 0;\n    for (int i = 0; i <= n; i++) {\n    \
    \    M add = y[i] * left[i] * right[i] * finv[i] * finv[n - i];\n        if ((n\
    \ - i) & 1)\n            res -= add;\n        else\n            res += add;\n\
    \    }\n    return res;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: polynomial/lagrange_interpolation.hpp
  requiredBy: []
  timestamp: '2021-01-20 10:53:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/665.test.cpp
documentation_of: polynomial/lagrange_interpolation.hpp
layout: document
redirect_from:
- /library/polynomial/lagrange_interpolation.hpp
- /library/polynomial/lagrange_interpolation.hpp.html
title: "\u30E9\u30B0\u30E9\u30F3\u30B8\u30E5\u88DC\u9593"
---
## 概要

## 計算量