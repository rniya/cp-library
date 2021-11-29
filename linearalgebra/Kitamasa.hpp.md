---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/linearalgebra/Kitamasa.md
    document_title: Kitamasa
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#define LOCAL\n#include <bits/stdc++.h>\nusing\
    \ namespace std;\n#pragma region Macros\ntypedef long long ll;\ntypedef __int128_t\
    \ i128;\ntypedef unsigned int uint;\ntypedef unsigned long long ull;\n#define\
    \ ALL(x) (x).begin(), (x).end()\n\ntemplate <typename T> istream& operator>>(istream&\
    \ is, vector<T>& v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate\
    \ <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {\n    for\
    \ (size_t i = 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size()\
    \ ? \"\" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first\
    \ << ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename\
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
    \ T> ostream& operator<<(ostream& os, const deque<T>& v) {\n    for (size_t i\
    \ = 0; i < v.size(); i++) {\n        os << v[i] << (i + 1 == v.size() ? \"\" :\
    \ \" \");\n    }\n    return os;\n}\ntemplate <typename T, size_t N> ostream&\
    \ operator<<(ostream& os, const array<T, N>& v) {\n    for (size_t i = 0; i <\
    \ N; i++) {\n        os << v[i] << (i + 1 == N ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&, const T&)\
    \ {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
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
    \ void(0)\n#endif\n\ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y,\
    \ x % y) : x; }\ntemplate <typename T> T lcm(T x, T y) { return x / gcd(x, y)\
    \ * y; }\n\nint topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\nint topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n\
    int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long\
    \ long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\nint popcount(signed t)\
    \ { return __builtin_popcount(t); }\nint popcount(long long t) { return __builtin_popcountll(t);\
    \ }\nbool ispow2(int i) { return i && (i & -i) == i; }\nlong long MSK(int n) {\
    \ return (1LL << n) - 1; }\n\ntemplate <class T> T ceil(T x, T y) {\n    assert(y\
    \ >= 1);\n    return (x > 0 ? (x + y - 1) / y : x / y);\n}\ntemplate <class T>\
    \ T floor(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? x / y : (x - y\
    \ + 1) / y);\n}\n\ntemplate <class T1, class T2> inline bool chmin(T1& a, T2 b)\
    \ {\n    if (a > b) {\n        a = b;\n        return true;\n    }\n    return\
    \ false;\n}\ntemplate <class T1, class T2> inline bool chmax(T1& a, T2 b) {\n\
    \    if (a < b) {\n        a = b;\n        return true;\n    }\n    return false;\n\
    }\n\ntemplate <typename T> void mkuni(vector<T>& v) {\n    sort(v.begin(), v.end());\n\
    \    v.erase(unique(v.begin(), v.end()), v.end());\n}\ntemplate <typename T> int\
    \ lwb(const vector<T>& v, const T& x) { return lower_bound(v.begin(), v.end(),\
    \ x) - v.begin(); }\n#pragma endregion\n#line 3 \"linearalgebra/Kitamasa.hpp\"\
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
  dependsOn: []
  isVerificationFile: false
  path: linearalgebra/Kitamasa.hpp
  requiredBy: []
  timestamp: '2021-10-31 14:57:50+09:00'
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