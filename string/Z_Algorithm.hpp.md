---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/yosupo/zalgorithm.test.cpp
    title: test/yosupo/zalgorithm.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/string/Z_Algorithm.md
    document_title: Z-Algorithm
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    const long long MOD = 1000000007;\n// const long long MOD=998244353;\nconst int\
    \ INF = 1e9;\nconst long long IINF = 1e18;\nconst int dx[4] = {1, 0, -1, 0}, dy[4]\
    \ = {0, 1, 0, -1};\nconst char dir[4] = {'D', 'R', 'U', 'L'};\n#define LOCAL\n\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"string/Z_Algorithm.hpp\"\
    \n\n/**\n * @brief Z-Algorithm\n * @docs docs/string/Z_Algorithm.md\n */\ntemplate\
    \ <typename T> vector<int> Z_Algorithm(const T& s) {\n    int n = s.size();\n\
    \    vector<int> z(n);\n    z[0] = n;\n    for (int i = 1, j = 0; i < n;) {\n\
    \        while (i + j < n && s[j] == s[i + j]) j++;\n        z[i] = j;\n     \
    \   if (j == 0) {\n            i++;\n            continue;\n        }\n      \
    \  int k = 1;\n        while (i + k < n && k + z[k] < j) z[i + k] = z[k], k++;\n\
    \        i += k;\n        j -= k;\n    }\n    return z;\n}\n\ntemplate <typename\
    \ T> vector<int> LCP(const T& s, const T& t) {\n    T u(s);\n    u.insert(u.begin(),\
    \ t.begin(), t.end());\n    vector<int> z = Z_Algorithm(u);\n    for (int& i :\
    \ z) i = min(i, (int)t.size());\n    return vector<int>(z.begin() + t.size(),\
    \ z.end());\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Z-Algorithm\n *\
    \ @docs docs/string/Z_Algorithm.md\n */\ntemplate <typename T> vector<int> Z_Algorithm(const\
    \ T& s) {\n    int n = s.size();\n    vector<int> z(n);\n    z[0] = n;\n    for\
    \ (int i = 1, j = 0; i < n;) {\n        while (i + j < n && s[j] == s[i + j])\
    \ j++;\n        z[i] = j;\n        if (j == 0) {\n            i++;\n         \
    \   continue;\n        }\n        int k = 1;\n        while (i + k < n && k +\
    \ z[k] < j) z[i + k] = z[k], k++;\n        i += k;\n        j -= k;\n    }\n \
    \   return z;\n}\n\ntemplate <typename T> vector<int> LCP(const T& s, const T&\
    \ t) {\n    T u(s);\n    u.insert(u.begin(), t.begin(), t.end());\n    vector<int>\
    \ z = Z_Algorithm(u);\n    for (int& i : z) i = min(i, (int)t.size());\n    return\
    \ vector<int>(z.begin() + t.size(), z.end());\n}\n"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/Z_Algorithm.hpp
  requiredBy: []
  timestamp: '2021-01-19 15:22:36+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/yosupo/zalgorithm.test.cpp
documentation_of: string/Z_Algorithm.hpp
layout: document
redirect_from:
- /library/string/Z_Algorithm.hpp
- /library/string/Z_Algorithm.hpp.html
title: Z-Algorithm
---
