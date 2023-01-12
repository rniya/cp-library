---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/datastructure/RectangleSet.hpp
    title: Rectangle Set
  - icon: ':warning:'
    path: src/datastructure/SparseTable.hpp
    title: Sparse Table
  - icon: ':warning:'
    path: src/graph/Dijkstra.hpp
    title: Dijkstra
  - icon: ':warning:'
    path: src/graph/RangeEdgeGraph.hpp
    title: Range Edge Graph
  - icon: ':warning:'
    path: src/math/fast_factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3 (Miller-Rabin primality test\
      \ + Pollard's rho algorithm)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/aplusb.test.cpp
    title: test/yosupo/aplusb.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 400, in update\n    raise BundleErrorAt(path, i + 1, \"unable to process\
    \ #include in #if / #ifdef / #ifndef other than include guards\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ src/base.hpp: line 7: unable to process #include in #if / #ifdef / #ifndef other\
    \ than include guards\n"
  code: "#pragma once\n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long\
    \ long ll;\n#define ALL(x) (x).begin(), (x).end()\n#ifdef LOCAL\n#include \"debug.hpp\"\
    \n#else\n#define debug(...) void(0)\n#endif\n\ntemplate <typename T> istream&\
    \ operator>>(istream& is, vector<T>& v) {\n    for (T& x : v) is >> x;\n    return\
    \ is;\n}\ntemplate <typename T> ostream& operator<<(ostream& os, const vector<T>&\
    \ v) {\n    for (size_t i = 0; i < v.size(); i++) {\n        os << v[i] << (i\
    \ + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n}\n\ntemplate <typename\
    \ T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename\
    \ T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\nint topbit(signed t) { return\
    \ t == 0 ? -1 : 31 - __builtin_clz(t); }\nint topbit(long long t) { return t ==\
    \ 0 ? -1 : 63 - __builtin_clzll(t); }\nint botbit(signed a) { return a == 0 ?\
    \ 32 : __builtin_ctz(a); }\nint botbit(long long a) { return a == 0 ? 64 : __builtin_ctzll(a);\
    \ }\nint popcount(signed t) { return __builtin_popcount(t); }\nint popcount(long\
    \ long t) { return __builtin_popcountll(t); }\nbool ispow2(int i) { return i &&\
    \ (i & -i) == i; }\nlong long MSK(int n) { return (1LL << n) - 1; }\n\ntemplate\
    \ <class T> T ceil(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? (x +\
    \ y - 1) / y : x / y);\n}\ntemplate <class T> T floor(T x, T y) {\n    assert(y\
    \ >= 1);\n    return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <class\
    \ T1, class T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a\
    \ = b;\n        return true;\n    }\n    return false;\n}\ntemplate <class T1,\
    \ class T2> inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n\
    \        return true;\n    }\n    return false;\n}\n\ntemplate <typename T> void\
    \ mkuni(vector<T>& v) {\n    sort(v.begin(), v.end());\n    v.erase(unique(v.begin(),\
    \ v.end()), v.end());\n}\ntemplate <typename T> int lwb(const vector<T>& v, const\
    \ T& x) { return lower_bound(v.begin(), v.end(), x) - v.begin(); }\n\nconst int\
    \ INF = (1 << 30) - 1;\nconst long long IINF = (1LL << 60) - 1;\nconst int dx[4]\
    \ = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};\nconst int MOD = 998244353;\n// const\
    \ int MOD = 1000000007;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/base.hpp
  requiredBy:
  - src/graph/Dijkstra.hpp
  - src/graph/RangeEdgeGraph.hpp
  - src/math/fast_factorize.hpp
  - src/datastructure/SparseTable.hpp
  - src/datastructure/RectangleSet.hpp
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/aplusb.test.cpp
documentation_of: src/base.hpp
layout: document
redirect_from:
- /library/src/base.hpp
- /library/src/base.hpp.html
title: src/base.hpp
---
