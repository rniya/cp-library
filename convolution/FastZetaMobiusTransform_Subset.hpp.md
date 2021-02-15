---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1289.test.cpp
    title: test/yukicoder/1289.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/convolution/FastZetaMobiusTransform.md
    document_title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u30FB\u30E1\u30D3\u30A6\u30B9\u5909\
      \u63DB(\u4E0B\u4F4D\u96C6\u5408)"
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"convolution/FastZetaMobiusTransform_Subset.hpp\"\
    \n\n/**\n * @brief \u9AD8\u901F\u30BC\u30FC\u30BF\u30FB\u30E1\u30D3\u30A6\u30B9\
    \u5909\u63DB(\u4E0B\u4F4D\u96C6\u5408)\n * @docs docs/convolution/FastZetaMobiusTransform.md\n\
    \ */\ntemplate <typename T> void FastZetaTransform(int n, vector<T>& f) {\n  \
    \  for (int i = 0; i < n; i++) {\n        for (int j = 0; j < (1 << n); j++) {\n\
    \            if ((j >> i) & 1) {\n                f[j] += f[j ^ (1 << i)];\n \
    \           }\n        }\n    }\n}\n\ntemplate <typename T> void FastMobiusTransform(int\
    \ n, vector<T>& f) {\n    for (int i = 0; i < n; i++) {\n        for (int j =\
    \ 0; j < (1 << n); j++) {\n            if ((j >> i) & 1) {\n                f[j]\
    \ -= f[j ^ (1 << i)];\n            }\n        }\n    }\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief \u9AD8\u901F\u30BC\
    \u30FC\u30BF\u30FB\u30E1\u30D3\u30A6\u30B9\u5909\u63DB(\u4E0B\u4F4D\u96C6\u5408\
    )\n * @docs docs/convolution/FastZetaMobiusTransform.md\n */\ntemplate <typename\
    \ T> void FastZetaTransform(int n, vector<T>& f) {\n    for (int i = 0; i < n;\
    \ i++) {\n        for (int j = 0; j < (1 << n); j++) {\n            if ((j >>\
    \ i) & 1) {\n                f[j] += f[j ^ (1 << i)];\n            }\n       \
    \ }\n    }\n}\n\ntemplate <typename T> void FastMobiusTransform(int n, vector<T>&\
    \ f) {\n    for (int i = 0; i < n; i++) {\n        for (int j = 0; j < (1 << n);\
    \ j++) {\n            if ((j >> i) & 1) {\n                f[j] -= f[j ^ (1 <<\
    \ i)];\n            }\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: convolution/FastZetaMobiusTransform_Subset.hpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1289.test.cpp
documentation_of: convolution/FastZetaMobiusTransform_Subset.hpp
layout: document
redirect_from:
- /library/convolution/FastZetaMobiusTransform_Subset.hpp
- /library/convolution/FastZetaMobiusTransform_Subset.hpp.html
title: "\u9AD8\u901F\u30BC\u30FC\u30BF\u30FB\u30E1\u30D3\u30A6\u30B9\u5909\u63DB(\u4E0B\
  \u4F4D\u96C6\u5408)"
---
## 概要
- 高速ゼータ変換(上位集合)：集合$S$を部分集合に含むような集合$T$についての$f(T)$の総和, すなわち,
$$g(S)=\sum_{T\supseteq S} f(T)$$
を計算する.
- 高速ゼータ変換(下位集合)：集合$S$の部分集合$T$についての$f(T)$の総和, すなわち,
$$g(S)=\sum_{T\subseteq S} f(T)$$
を計算する.
- 高速メビウス変換(上位集合)：高速ゼータ変換(上位集合)の逆変換, すなわち,
$$f(S)=\sum_{T\supseteq S} (-1)^{|T|-|S|}g(T)$$
を計算する.
- 高速メビウス変換(下位集合)：高速ゼータ変換(上位集合)の逆変換, すなわち,
$$f(S)=\sum_{T\subseteq S} (-1)^{|S|-|T|}g(T)$$
を計算する.

また高速ゼータ変換は演算を$+$に限定せずとも環上で動く([参考](http://home.wakatabe.com/ryo/wiki/index.php?%E3%82%A2%E3%83%AB%E3%82%B4%E3%83%AA%E3%82%BA%E3%83%A0#qef794e9), 未整備)

## 計算量
どれも$O(n2^n)$

## 参照
- [高速ゼータ変換について - Qiita](https://qiita.com/Euglenese/items/260f9ddf513f772d7e42)
- [高速ゼータ・メビウス変換 - Mister雑記](https://misteer.hatenablog.com/entry/zeta-moebius)
