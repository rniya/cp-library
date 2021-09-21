---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/string/SuffixArray.md
    document_title: Suffix Array
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    #pragma region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef\
    \ unsigned int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(),\
    \ (x).end()\n\ntemplate <typename T> istream& operator>>(istream& is, vector<T>&\
    \ v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T>\
    \ ostream& operator<<(ostream& os, const vector<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first <<\
    \ ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n   \
    \ for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
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
    \" : \" \");\n    }\n    return os;\n}\n\ntemplate <int i, typename T> void print_tuple(ostream&,\
    \ const T&) {}\ntemplate <int i, typename T, typename H, class... Args> void print_tuple(ostream&\
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
    \ 42\n#endif\n\ntemplate <typename T> T gcd(T x, T y) { return y != 0 ? gcd(y,\
    \ x % y) : x; }\ntemplate <typename T> T lcm(T x, T y) { return x / gcd(x, y)\
    \ * y; }\n\nint topbit(signed t) { return t == 0 ? -1 : 31 - __builtin_clz(t);\
    \ }\nint topbit(long long t) { return t == 0 ? -1 : 63 - __builtin_clzll(t); }\n\
    int botbit(signed a) { return a == 0 ? 32 : __builtin_ctz(a); }\nint botbit(long\
    \ long a) { return a == 0 ? 64 : __builtin_ctzll(a); }\nint popcount(signed t)\
    \ { return __builtin_popcount(t); }\nint popcount(long long t) { return __builtin_popcountll(t);\
    \ }\nbool ispow2(int i) { return i && (i & -i) == i; }\n\ntemplate <class T> T\
    \ ceil(T x, T y) {\n    assert(y >= 1);\n    return (x > 0 ? (x + y - 1) / y :\
    \ x / y);\n}\ntemplate <class T> T floor(T x, T y) {\n    assert(y >= 1);\n  \
    \  return (x > 0 ? x / y : (x - y + 1) / y);\n}\n\ntemplate <class T1, class T2>\
    \ inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2> inline\
    \ bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n        return\
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"hold/SuffixArray_old.hpp\"\
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
  path: hold/SuffixArray_old.hpp
  requiredBy: []
  timestamp: '2021-09-12 18:03:48+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: hold/SuffixArray_old.hpp
layout: document
redirect_from:
- /library/hold/SuffixArray_old.hpp
- /library/hold/SuffixArray_old.hpp.html
title: Suffix Array
---
## 概要
以下, 文字列 `s` の $l$ 番目から $r - 1$ 番目までの部分文字列を `s[l,r)` , $l$ 番目から末尾までの部分文字列を `s[l)` と表すことにする.

与えられた文字列 $S$ の Suffix Array を返す.
Suffix Array `sa` とは, 順列 $(0, 1, \cdots, n - 1)$ をその index から始まる接尾辞の辞書順によってソートしたものである.

これは SA-IS と呼ばれるアルゴリズムによって $O(|S|)$ で構築することができる.

また、先で得られた Suffix Array をもとに Lognest Common Prefix Array も構築できる。これは Suffix Array における隣同士の接尾辞において先頭何文字が共通しているかを表す長さ $n - 1$ の配列である。すなわち、 `lcp[i]` は接尾辞 `s[sa[i])` と `s[sa[i+1])` の LCP の長さに等しい。LCP Array を応用すると、隣り合う接尾辞だけでなく任意の接尾辞の LCP の長さを求めることができる。文字列 $S$ と $T$ の LCP の長さを $f(S, T)$ 、$S$ の位置 $i$ から始まる接尾辞を $S_i$ と表すとして、$l < r$ とすると、

$$\begin{aligned}
f(S_l, S_r) &= \min(f(S_l, S_{l+1}), f(S_{l+1}, S_{l+2}), \cdots, f(S_{r-1}, S_r)) \\
&= \min(LCP_l, LCP_{l+1}, \cdots, LCP_{r-1})
\end{aligned}$$

が成立する。これは Sparse Table 等を用いて効率的に扱うことも可能である。

## 計算量

## 問題例
- [CodeChef August Lunchtime 2021 Division 1 - Longest Spanning Substrings](https://www.codechef.com/LTIME99A/problems/LNGSUB)

## 参照
- [SA-IS - Shogo Computing Laboratory](https://shogo82148.github.io/homepage/memo/algorithm/suffix-array/sa-is.html)
- [SA-IS 法のメモ - まめめも](https://mametter.hatenablog.com/entry/20180130/p1#f-1aedbc3e)
- [Two Efficient Algorithms for Linear Time Suffix Array Construction](https://ieeexplore.ieee.org/document/5582081)