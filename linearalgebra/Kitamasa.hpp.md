---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/tdpc_fibonacci.cpp
    title: test/atcoder/tdpc_fibonacci.cpp
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/linearalgebra/Kitamasa.md
    document_title: Kitamasa
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n \
    \       os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"linearalgebra/Kitamasa.hpp\"\
    \n\n/**\n * @brief Kitamasa\n * @docs docs/linearalgebra/Kitamasa.md\n */\ntemplate\
    \ <typename K> struct Kitamasa {\n    int k;\n    vector<K> cs;\n    vector<vector<K>>\
    \ pcs;\n    Kitamasa(const vector<K>& C) : cs(C), pcs(1), k(C.size()) {\n    \
    \    pcs[0].assign(2 * k + 1, K(0));\n        pcs[0][1] = K(1);\n    }\n    vector<K>\
    \ merge(const vector<K>& xs, const vector<K>& ys) {\n        vector<K> zs(2 *\
    \ k + 1, K(0));\n        for (int i = 1; i <= k; i++) {\n            for (int\
    \ j = 1; j <= k; j++) {\n                zs[i + j] += xs[i] * ys[j];\n       \
    \     }\n        }\n        for (int i = 2 * k; i > k; zs[i--] = K(0)) {\n   \
    \         for (int j = 1; j <= k; j++) {\n                zs[i - j] += cs[k -\
    \ j] * zs[i];\n            }\n        }\n        return zs;\n    }\n    // Be\
    \ careful n is 0-indexed\n    K calc(const vector<K>& A, long long n) {\n    \
    \    vector<K> res(pcs[0]);\n        for (int i = 0; n; i++, n >>= 1) {\n    \
    \        if ((int)pcs.size() <= i) pcs.emplace_back(merge(pcs[i - 1], pcs[i -\
    \ 1]));\n            if (~n & 1) continue;\n            res = merge(res, pcs[i]);\n\
    \        }\n        K ans = K(0);\n        for (int i = 1; i <= k; i++) ans +=\
    \ res[i] * A[i - 1];\n        return ans;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Kitamasa\n * @docs\
    \ docs/linearalgebra/Kitamasa.md\n */\ntemplate <typename K> struct Kitamasa {\n\
    \    int k;\n    vector<K> cs;\n    vector<vector<K>> pcs;\n    Kitamasa(const\
    \ vector<K>& C) : cs(C), pcs(1), k(C.size()) {\n        pcs[0].assign(2 * k +\
    \ 1, K(0));\n        pcs[0][1] = K(1);\n    }\n    vector<K> merge(const vector<K>&\
    \ xs, const vector<K>& ys) {\n        vector<K> zs(2 * k + 1, K(0));\n       \
    \ for (int i = 1; i <= k; i++) {\n            for (int j = 1; j <= k; j++) {\n\
    \                zs[i + j] += xs[i] * ys[j];\n            }\n        }\n     \
    \   for (int i = 2 * k; i > k; zs[i--] = K(0)) {\n            for (int j = 1;\
    \ j <= k; j++) {\n                zs[i - j] += cs[k - j] * zs[i];\n          \
    \  }\n        }\n        return zs;\n    }\n    // Be careful n is 0-indexed\n\
    \    K calc(const vector<K>& A, long long n) {\n        vector<K> res(pcs[0]);\n\
    \        for (int i = 0; n; i++, n >>= 1) {\n            if ((int)pcs.size() <=\
    \ i) pcs.emplace_back(merge(pcs[i - 1], pcs[i - 1]));\n            if (~n & 1)\
    \ continue;\n            res = merge(res, pcs[i]);\n        }\n        K ans =\
    \ K(0);\n        for (int i = 1; i <= k; i++) ans += res[i] * A[i - 1];\n    \
    \    return ans;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: linearalgebra/Kitamasa.hpp
  requiredBy:
  - test/atcoder/tdpc_fibonacci.cpp
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: linearalgebra/Kitamasa.hpp
layout: document
redirect_from:
- /library/linearalgebra/Kitamasa.hpp
- /library/linearalgebra/Kitamasa.hpp.html
title: Kitamasa
---
## 概要

## 計算量