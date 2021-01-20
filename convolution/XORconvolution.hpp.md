---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/bitwise_xor_convolution.test.cpp
    title: test/yosupo/bitwise_xor_convolution.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1240.test.cpp
    title: test/yukicoder/1240.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/convolution/XORconvolution.md
    document_title: "\u6DFB\u5B57XOR\u7573\u307F\u8FBC\u307F"
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"convolution/XORconvolution.hpp\"\
    \n\n/**\n * @brief \u6DFB\u5B57XOR\u7573\u307F\u8FBC\u307F\n * @docs docs/convolution/XORconvolution.md\n\
    \ */\ntemplate <typename T> void fwt(vector<T>& f) {\n    int n = f.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n\
    \            if (!(j & i)) {\n                T x = f[j], y = f[j | i];\n    \
    \            f[j] = x + y;\n                f[j | i] = x - y;\n            }\n\
    \        }\n    }\n}\n\ntemplate <typename T> void ifwt(vector<T>& f) {\n    int\
    \ n = f.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0;\
    \ j < n; j++) {\n            if (!(j & i)) {\n                T x = f[j], y =\
    \ f[j | i];\n                f[j] = (x + y) / 2;\n                f[j | i] = (x\
    \ - y) / 2;\n            }\n        }\n    }\n}\n\ntemplate <typename T> vector<T>\
    \ XOR_convolution(vector<T> A, vector<T> B) {\n    int n = A.size();\n    assert(__builtin_popcount(n)\
    \ == 1);\n    assert(A.size() == B.size());\n    fwt(A);\n    fwt(B);\n    for\
    \ (int i = 0; i < n; i++) A[i] *= B[i];\n    ifwt(A);\n    return A;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief \u6DFB\u5B57XOR\u7573\
    \u307F\u8FBC\u307F\n * @docs docs/convolution/XORconvolution.md\n */\ntemplate\
    \ <typename T> void fwt(vector<T>& f) {\n    int n = f.size();\n    for (int i\
    \ = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if\
    \ (!(j & i)) {\n                T x = f[j], y = f[j | i];\n                f[j]\
    \ = x + y;\n                f[j | i] = x - y;\n            }\n        }\n    }\n\
    }\n\ntemplate <typename T> void ifwt(vector<T>& f) {\n    int n = f.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n\
    \            if (!(j & i)) {\n                T x = f[j], y = f[j | i];\n    \
    \            f[j] = (x + y) / 2;\n                f[j | i] = (x - y) / 2;\n  \
    \          }\n        }\n    }\n}\n\ntemplate <typename T> vector<T> XOR_convolution(vector<T>\
    \ A, vector<T> B) {\n    int n = A.size();\n    assert(__builtin_popcount(n) ==\
    \ 1);\n    assert(A.size() == B.size());\n    fwt(A);\n    fwt(B);\n    for (int\
    \ i = 0; i < n; i++) A[i] *= B[i];\n    ifwt(A);\n    return A;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: convolution/XORconvolution.hpp
  requiredBy: []
  timestamp: '2021-01-20 10:53:49+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/bitwise_xor_convolution.test.cpp
  - test/yukicoder/1240.test.cpp
documentation_of: convolution/XORconvolution.hpp
layout: document
redirect_from:
- /library/convolution/XORconvolution.hpp
- /library/convolution/XORconvolution.hpp.html
title: "\u6DFB\u5B57XOR\u7573\u307F\u8FBC\u307F"
---
## 概要
添字XORでの畳み込みを行う. すなわち,
$$c_k=\sum_{i\oplus j=k}a_ib_j$$
を計算する.

列$a,b$に対して離散Hadamard変換を施した後に掛け合わせて, 逆Hadamard変換することで求めたい列$c$が得られる. この際, 列$a,b$の長さは$2$の冪乗である必要がある. また$\mathbb{F}_p$上での逆Hadamard変換では$2$で割る操作がネックになることもあるので, 定数倍改善が必要な場合は適宜$2$の逆元を掛けるように書き換える必要がある.

## 計算量
$|a|=2^n$として, $O(n2^n)$

## 参照
[色々な畳み込み - kazuma8128’s blog](https://kazuma8128.hatenablog.com/entry/2018/05/31/144519)