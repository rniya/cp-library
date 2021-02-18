---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/util/binary_conversion.md
    document_title: "\u6587\u5B57\u5217\u306E2\u9032\u5909\u63DB"
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"util/binary_conversion.hpp\"\
    \n\n/**\n * @brief \u6587\u5B57\u5217\u306E2\u9032\u5909\u63DB\n * @docs docs/util/binary_conversion.md\n\
    \ */\n\nvector<bool> binary_conversion(const string& s) {\n    using u64 = uint64_t;\n\
    \n    vector<u64> num(s.size() / 9 + 10, 0);\n    for (size_t i = 0; i < s.size();\
    \ i += 9) {\n        const string t = s.substr(i, 9);\n        u64 add = 0, mul\
    \ = 1;\n        for (const auto c : t) {\n            add = add * 10 + (c - '0');\n\
    \            mul *= 10;\n        }\n        for (auto& d : num) {\n          \
    \  d = d * mul + add;\n            add = d >> 32;\n            d -= add << 32;\n\
    \        }\n    }\n\n    vector<bool> res(num.size() * 32);\n    for (size_t i\
    \ = 0; i < num.size(); i++) {\n        for (size_t j = 0; j < 32; j++) {\n   \
    \         res[i * 32 + j] = num[i] >> j & 1;\n        }\n    }\n\n    while (!res.empty()\
    \ && !res.back()) res.pop_back();\n    return res;\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief \u6587\u5B57\u5217\
    \u306E2\u9032\u5909\u63DB\n * @docs docs/util/binary_conversion.md\n */\n\nvector<bool>\
    \ binary_conversion(const string& s) {\n    using u64 = uint64_t;\n\n    vector<u64>\
    \ num(s.size() / 9 + 10, 0);\n    for (size_t i = 0; i < s.size(); i += 9) {\n\
    \        const string t = s.substr(i, 9);\n        u64 add = 0, mul = 1;\n   \
    \     for (const auto c : t) {\n            add = add * 10 + (c - '0');\n    \
    \        mul *= 10;\n        }\n        for (auto& d : num) {\n            d =\
    \ d * mul + add;\n            add = d >> 32;\n            d -= add << 32;\n  \
    \      }\n    }\n\n    vector<bool> res(num.size() * 32);\n    for (size_t i =\
    \ 0; i < num.size(); i++) {\n        for (size_t j = 0; j < 32; j++) {\n     \
    \       res[i * 32 + j] = num[i] >> j & 1;\n        }\n    }\n\n    while (!res.empty()\
    \ && !res.back()) res.pop_back();\n    return res;\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: util/binary_conversion.hpp
  requiredBy: []
  timestamp: '2021-02-18 23:23:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: util/binary_conversion.hpp
layout: document
redirect_from:
- /library/util/binary_conversion.hpp
- /library/util/binary_conversion.hpp.html
title: "\u6587\u5B57\u5217\u306E2\u9032\u5909\u63DB"
---
## 概要
文字列を2進法に変換する.

## 問題例
[Codeforces Round #285 (Div. 1) D. Misha and XOR](https://codeforces.com/contest/504/problem/D)

## 参照
https://twitter.com/noshi91/status/1324274752228192257