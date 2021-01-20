---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/string/Knuth_Morris_Pratt.md
    document_title: "Knuth Moriss Pratt (KMP\u6CD5)"
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"string/Knuth_Morris_Pratt.hpp\"\
    \n\n/**\n * @brief Knuth Moriss Pratt (KMP\u6CD5)\n * @docs docs/string/Knuth_Morris_Pratt.md\n\
    \ */\nstruct Knuth_Morris_Pratt {\n    string s;\n    int n;\n    vector<int>\
    \ kmp;\n    Knuth_Morris_Pratt(const string& s) : s(s) { build(); }\n    void\
    \ build() {\n        n = s.size();\n        kmp.assign(n + 1, -1);\n        for\
    \ (int i = 0, j = -1; i < n; kmp[++i] = ++j) {\n            while (j >= 0 && s[i]\
    \ != s[j]) j = kmp[j];\n        }\n    }\n    vector<int> KMP() { return kmp;\
    \ }\n    vector<int> next_period() {\n        vector<int> np = kmp;\n        for\
    \ (int i = 1; i < (int)kmp.size(); i++) np[i] = i - np[i];\n        return np;\n\
    \    }\n    vector<int> pattern_match(const string& t) {\n        int m = t.size();\n\
    \        vector<int> res;\n        int i = 0, j = 0;\n        while (i + j < m)\
    \ {\n            if (s[j] == t[i + j]) {\n                if (++j != n) continue;\n\
    \                res.emplace_back(i);\n            }\n            i += j - kmp[j];\n\
    \            j = max(kmp[j], 0);\n        }\n        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Knuth Moriss Pratt\
    \ (KMP\u6CD5)\n * @docs docs/string/Knuth_Morris_Pratt.md\n */\nstruct Knuth_Morris_Pratt\
    \ {\n    string s;\n    int n;\n    vector<int> kmp;\n    Knuth_Morris_Pratt(const\
    \ string& s) : s(s) { build(); }\n    void build() {\n        n = s.size();\n\
    \        kmp.assign(n + 1, -1);\n        for (int i = 0, j = -1; i < n; kmp[++i]\
    \ = ++j) {\n            while (j >= 0 && s[i] != s[j]) j = kmp[j];\n        }\n\
    \    }\n    vector<int> KMP() { return kmp; }\n    vector<int> next_period() {\n\
    \        vector<int> np = kmp;\n        for (int i = 1; i < (int)kmp.size(); i++)\
    \ np[i] = i - np[i];\n        return np;\n    }\n    vector<int> pattern_match(const\
    \ string& t) {\n        int m = t.size();\n        vector<int> res;\n        int\
    \ i = 0, j = 0;\n        while (i + j < m) {\n            if (s[j] == t[i + j])\
    \ {\n                if (++j != n) continue;\n                res.emplace_back(i);\n\
    \            }\n            i += j - kmp[j];\n            j = max(kmp[j], 0);\n\
    \        }\n        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/Knuth_Morris_Pratt.hpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/Knuth_Morris_Pratt.hpp
layout: document
redirect_from:
- /library/string/Knuth_Morris_Pratt.hpp
- /library/string/Knuth_Morris_Pratt.hpp.html
title: "Knuth Moriss Pratt (KMP\u6CD5)"
---
## 概要

## 計算量