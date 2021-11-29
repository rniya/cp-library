---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/enumerate_palindromes.test.cpp
    title: test/yosupo/enumerate_palindromes.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/Manacher.md
    document_title: Manacher
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
    \ x) - v.begin(); }\n#pragma endregion\n#line 3 \"string/Manacher.hpp\"\n\n/**\n\
    \ * @brief Manacher\n * @docs docs/string/Manacher.md\n */\nvector<int> Manacher(const\
    \ string& s) {\n    int n = s.size();\n    vector<int> res(n);\n    for (int i\
    \ = 0, j = 0; i < n;) {\n        while (i - j >= 0 && i + j < n && s[i - j] ==\
    \ s[i + j]) j++;\n        res[i] = j;\n        int k = 1;\n        while (i -\
    \ k >= 0 && i + k < n && k + res[i - k] < j) res[i + k] = res[i - k], k++;\n \
    \       i += k, j -= k;\n    }\n    return res;\n}\n\nvector<int> PalindromeTable(const\
    \ string& s) {\n    int n = s.size();\n    string t(n * 2 + 1, '$');\n    for\
    \ (int i = 0; i < n; i++) t[i * 2 + 1] = s[i];\n    vector<int> v = Manacher(t),\
    \ res;\n    for (int i = 1; i < n * 2; i++) res.emplace_back(v[i] - 1);\n    return\
    \ res;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Manacher\n * @docs\
    \ docs/string/Manacher.md\n */\nvector<int> Manacher(const string& s) {\n    int\
    \ n = s.size();\n    vector<int> res(n);\n    for (int i = 0, j = 0; i < n;) {\n\
    \        while (i - j >= 0 && i + j < n && s[i - j] == s[i + j]) j++;\n      \
    \  res[i] = j;\n        int k = 1;\n        while (i - k >= 0 && i + k < n &&\
    \ k + res[i - k] < j) res[i + k] = res[i - k], k++;\n        i += k, j -= k;\n\
    \    }\n    return res;\n}\n\nvector<int> PalindromeTable(const string& s) {\n\
    \    int n = s.size();\n    string t(n * 2 + 1, '$');\n    for (int i = 0; i <\
    \ n; i++) t[i * 2 + 1] = s[i];\n    vector<int> v = Manacher(t), res;\n    for\
    \ (int i = 1; i < n * 2; i++) res.emplace_back(v[i] - 1);\n    return res;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/Manacher.hpp
  requiredBy: []
  timestamp: '2021-10-31 14:57:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/enumerate_palindromes.test.cpp
documentation_of: string/Manacher.hpp
layout: document
redirect_from:
- /library/string/Manacher.hpp
- /library/string/Manacher.hpp.html
title: Manacher
---
## 概要

## 計算量