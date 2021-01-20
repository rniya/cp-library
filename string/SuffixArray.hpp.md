---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/LongestCommonPrefixArray.hpp
    title: Longest Common Prefix Array
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_D.test.cpp
    title: test/aoj/ALDS1_14_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_of_substrings.test.cpp
    title: test/yosupo/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/suffixarray.test.cpp
    title: test/yosupo/suffixarray.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/SuffixArray.md
    document_title: Suffix Array
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"string/SuffixArray.hpp\"\
    \n\n/**\n * @brief Suffix Array\n * @docs docs/string/SuffixArray.md\n */\nstruct\
    \ SuffixArray {\n    string s;\n    vector<int> SA;\n    SuffixArray(const string&\
    \ S) : s(S) {\n        int n = s.size();\n        s.push_back('$');\n        SA.resize(n\
    \ + 1);\n        iota(SA.begin(), SA.end(), 0);\n        sort(SA.begin(), SA.end(),\
    \ [&](int a, int b) { return s[a] == s[b] ? a > b : s[a] < s[b]; });\n       \
    \ vector<int> c(s.begin(), s.end()), cnt(n + 1), nxt(n + 1);\n        for (int\
    \ j = 1; j <= n; j <<= 1) {\n            for (int i = 0; i <= n; i++) {\n    \
    \            nxt[SA[i]] =\n                    ((i && c[SA[i - 1]] == c[SA[i]]\
    \ && SA[i - 1] + j < n && c[SA[i - 1] + j / 2] == c[SA[i] + j / 2])\n        \
    \                 ? nxt[SA[i - 1]]\n                         : i);\n         \
    \   }\n            iota(cnt.begin(), cnt.end(), 0);\n            copy(SA.begin(),\
    \ SA.end(), c.begin());\n            for (int i = 0; i <= n; i++) {\n        \
    \        if (c[i] - j >= 0) {\n                    SA[cnt[nxt[c[i] - j]]++] =\
    \ c[i] - j;\n                }\n            }\n            nxt.swap(c);\n    \
    \    }\n    }\n    bool comp(const string& t, int si = 0, int ti = 0) {\n    \
    \    int sn = s.size(), tn = t.size();\n        for (; si < sn && ti < tn; si++,\
    \ ti++) {\n            if (s[si] < t[ti]) return true;\n            if (s[si]\
    \ > t[ti]) return false;\n        }\n        return si >= sn && ti < tn;\n   \
    \ }\n    int lower_bound(const string& t) {\n        int lb = -1, ub = SA.size();\n\
    \        while (ub - lb > 1) {\n            int mid = (ub + lb) >> 1;\n      \
    \      (comp(t, SA[mid]) ? lb : ub) = mid;\n        }\n        return ub;\n  \
    \  }\n    pair<int, int> lower_upper_bound(string& t) {\n        int l = lower_bound(t);\n\
    \        int lb = l - 1, ub = SA.size();\n        t.back()++;\n        while (ub\
    \ - lb > 1) {\n            int mid = (ub + lb) >> 1;\n            (comp(t, SA[mid])\
    \ ? lb : ub) = mid;\n        }\n        t.back()--;\n        return {l, ub};\n\
    \    }\n    int count(string& t) {\n        pair<int, int> p = lower_upper_bound(t);\n\
    \        return p.second - p.first;\n    }\n    int operator[](int i) const {\
    \ return SA[i]; }\n    int size() const { return s.size(); }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Suffix Array\n *\
    \ @docs docs/string/SuffixArray.md\n */\nstruct SuffixArray {\n    string s;\n\
    \    vector<int> SA;\n    SuffixArray(const string& S) : s(S) {\n        int n\
    \ = s.size();\n        s.push_back('$');\n        SA.resize(n + 1);\n        iota(SA.begin(),\
    \ SA.end(), 0);\n        sort(SA.begin(), SA.end(), [&](int a, int b) { return\
    \ s[a] == s[b] ? a > b : s[a] < s[b]; });\n        vector<int> c(s.begin(), s.end()),\
    \ cnt(n + 1), nxt(n + 1);\n        for (int j = 1; j <= n; j <<= 1) {\n      \
    \      for (int i = 0; i <= n; i++) {\n                nxt[SA[i]] =\n        \
    \            ((i && c[SA[i - 1]] == c[SA[i]] && SA[i - 1] + j < n && c[SA[i -\
    \ 1] + j / 2] == c[SA[i] + j / 2])\n                         ? nxt[SA[i - 1]]\n\
    \                         : i);\n            }\n            iota(cnt.begin(),\
    \ cnt.end(), 0);\n            copy(SA.begin(), SA.end(), c.begin());\n       \
    \     for (int i = 0; i <= n; i++) {\n                if (c[i] - j >= 0) {\n \
    \                   SA[cnt[nxt[c[i] - j]]++] = c[i] - j;\n                }\n\
    \            }\n            nxt.swap(c);\n        }\n    }\n    bool comp(const\
    \ string& t, int si = 0, int ti = 0) {\n        int sn = s.size(), tn = t.size();\n\
    \        for (; si < sn && ti < tn; si++, ti++) {\n            if (s[si] < t[ti])\
    \ return true;\n            if (s[si] > t[ti]) return false;\n        }\n    \
    \    return si >= sn && ti < tn;\n    }\n    int lower_bound(const string& t)\
    \ {\n        int lb = -1, ub = SA.size();\n        while (ub - lb > 1) {\n   \
    \         int mid = (ub + lb) >> 1;\n            (comp(t, SA[mid]) ? lb : ub)\
    \ = mid;\n        }\n        return ub;\n    }\n    pair<int, int> lower_upper_bound(string&\
    \ t) {\n        int l = lower_bound(t);\n        int lb = l - 1, ub = SA.size();\n\
    \        t.back()++;\n        while (ub - lb > 1) {\n            int mid = (ub\
    \ + lb) >> 1;\n            (comp(t, SA[mid]) ? lb : ub) = mid;\n        }\n  \
    \      t.back()--;\n        return {l, ub};\n    }\n    int count(string& t) {\n\
    \        pair<int, int> p = lower_upper_bound(t);\n        return p.second - p.first;\n\
    \    }\n    int operator[](int i) const { return SA[i]; }\n    int size() const\
    \ { return s.size(); }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/SuffixArray.hpp
  requiredBy:
  - string/LongestCommonPrefixArray.hpp
  timestamp: '2021-01-20 10:53:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/number_of_substrings.test.cpp
  - test/yosupo/suffixarray.test.cpp
  - test/aoj/ALDS1_14_D.test.cpp
documentation_of: string/SuffixArray.hpp
layout: document
redirect_from:
- /library/string/SuffixArray.hpp
- /library/string/SuffixArray.hpp.html
title: Suffix Array
---
## 概要

## 計算量