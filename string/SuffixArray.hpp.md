---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_of_substrings.test.cpp
    title: test/yosupo/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/suffixarray.test.cpp
    title: test/yosupo/suffixarray.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/SuffixArray.md
    document_title: Suffix Array + Longest Common Prefix Array
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
    \ x) - v.begin(); }\n#pragma endregion\n#line 3 \"string/SuffixArray.hpp\"\n\n\
    /**\n * @brief Suffix Array + Longest Common Prefix Array\n * @docs docs/string/SuffixArray.md\n\
    \ */\nnamespace SuffixArray {\nvector<int> sa_is(const vector<int>& s, int upper)\
    \ {\n    int n = s.size();\n    if (n == 0) return {};\n    if (n == 1) return\
    \ {0};\n    if (n == 2) return {s[0] < s[1] ? vector<int>{0, 1} : vector<int>{1,\
    \ 0}};\n\n    vector<int> sa(n), lms, lms_map(n, -1), sum_l(upper + 1, 0), sum_s(upper\
    \ + 1, 0);\n    vector<bool> is_s(n, false);\n    int m = 0;\n    for (int i =\
    \ n - 2; i >= 0; i--) is_s[i] = (s[i] == s[i + 1] ? is_s[i + 1] : (s[i] < s[i\
    \ + 1]));\n    for (int i = 0; i < n; i++) {\n        if (!is_s[i])\n        \
    \    sum_s[s[i]]++;\n        else {\n            sum_l[s[i] + 1]++;\n        \
    \    if (!i || !is_s[i - 1]) {\n                lms_map[i] = m++;\n          \
    \      lms.emplace_back(i);\n            }\n        }\n    }\n    for (int i =\
    \ 0; i <= upper; i++) {\n        sum_s[i] += sum_l[i];\n        if (i < upper)\
    \ sum_l[i + 1] += sum_s[i];\n    }\n\n    auto induced_sort = [&](const vector<int>&\
    \ lms) {\n        fill(sa.begin(), sa.end(), -1);\n        vector<int> buf(upper\
    \ + 1);\n        copy(sum_s.begin(), sum_s.end(), buf.begin());\n        for (int\
    \ idx : lms) sa[buf[s[idx]]++] = idx;\n\n        copy(sum_l.begin(), sum_l.end(),\
    \ buf.begin());\n        sa[buf[s[n - 1]]++] = n - 1;\n        for (int i = 0;\
    \ i < n; i++) {\n            if (sa[i] < 1 || is_s[sa[i] - 1]) continue;\n   \
    \         int c = s[sa[i] - 1];\n            sa[buf[c]++] = sa[i] - 1;\n     \
    \   }\n\n        copy(sum_l.begin(), sum_l.end(), buf.begin());\n        for (int\
    \ i = n - 1; i >= 0; i--) {\n            if (sa[i] < 1 || !is_s[sa[i] - 1]) continue;\n\
    \            int c = s[sa[i] - 1];\n            sa[--buf[c + 1]] = sa[i] - 1;\n\
    \        }\n    };\n\n    induced_sort(lms);\n    if (m) {\n        vector<int>\
    \ sorted_lms;\n        for (int& idx : sa) {\n            if (~lms_map[idx]) {\n\
    \                sorted_lms.emplace_back(idx);\n            }\n        }\n   \
    \     vector<int> rec_s(m);\n        int rec_upper = 0;\n        rec_s[lms_map[sorted_lms[0]]]\
    \ = rec_upper;\n\n        for (int i = 1; i < m; i++) {\n            int l = sorted_lms[i\
    \ - 1], r = sorted_lms[i];\n            int end_l = (lms_map[l] + 1 < m ? lms[lms_map[l]\
    \ + 1] : n);\n            int end_r = (lms_map[r] + 1 < m ? lms[lms_map[r] + 1]\
    \ : n);\n            bool same = true;\n            if (end_l - l != end_r - r)\n\
    \                same = false;\n            else {\n                for (; l <\
    \ end_l; l++, r++) {\n                    if (s[l] != s[r]) {\n              \
    \          break;\n                    }\n                }\n                if\
    \ (l == n || s[l] != s[r]) same = false;\n            }\n            rec_s[lms_map[sorted_lms[i]]]\
    \ = (same ? rec_upper : ++rec_upper);\n        }\n\n        if (rec_upper + 1\
    \ != m) {\n            auto rec_sa = sa_is(rec_s, rec_upper);\n            for\
    \ (int i = 0; i < m; i++) sorted_lms[i] = lms[rec_sa[i]];\n        }\n       \
    \ induced_sort(sorted_lms);\n    }\n\n    return sa;\n}\n\nvector<int> suffix_array(const\
    \ vector<int>& s, int upper) {\n    for (int x : s) assert(0 <= x && x <= upper);\n\
    \    return sa_is(s, upper);\n}\ntemplate <class T> vector<int> suffix_array(const\
    \ vector<T>& s) {\n    int n = s.size();\n    vector<int> idx(n);\n    iota(idx.begin(),\
    \ idx.end(), 0);\n    sort(idx.begin(), idx.end(), [&](int x, int y) { return\
    \ s[x] < s[y]; });\n    vector<int> ns(n);\n    int cur = 0;\n    for (int i =\
    \ 0; i < n; i++) {\n        if (i && s[idx[i - 1]] != s[idx[i]]) cur++;\n    \
    \    ns[idx[i]] = cur;\n    }\n    return sa_is(s, cur);\n}\nvector<int> suffix_array(const\
    \ string& s) {\n    vector<int> ns;\n    for (char c : s) ns.emplace_back(c);\n\
    \    return sa_is(ns, 255);\n}\n\ntemplate <class T> vector<int> lcp_array(const\
    \ vector<T>& s, const vector<int>& sa) {\n    int n = s.size();\n    vector<int>\
    \ rank(n);\n    for (int i = 0; i < n; i++) rank[sa[i]] = i;\n    vector<int>\
    \ lcp(n - 1);\n    for (int i = 0, h = 0; i < n; i++) {\n        if (h > 0) h--;\n\
    \        if (rank[i] == 0) continue;\n        int j = sa[rank[i] - 1];\n     \
    \   for (; j + h < n && i + h < n; h++) {\n            if (s[j + h] != s[i + h])\
    \ {\n                break;\n            }\n        }\n        lcp[rank[i] - 1]\
    \ = h;\n    }\n    return lcp;\n}\n\nvector<int> lcp_array(const string& s, const\
    \ vector<int>& sa) {\n    vector<int> ns;\n    for (char c : s) ns.emplace_back(c);\n\
    \    return lcp_array(ns, sa);\n}\n}  // namespace SuffixArray\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Suffix Array + Longest\
    \ Common Prefix Array\n * @docs docs/string/SuffixArray.md\n */\nnamespace SuffixArray\
    \ {\nvector<int> sa_is(const vector<int>& s, int upper) {\n    int n = s.size();\n\
    \    if (n == 0) return {};\n    if (n == 1) return {0};\n    if (n == 2) return\
    \ {s[0] < s[1] ? vector<int>{0, 1} : vector<int>{1, 0}};\n\n    vector<int> sa(n),\
    \ lms, lms_map(n, -1), sum_l(upper + 1, 0), sum_s(upper + 1, 0);\n    vector<bool>\
    \ is_s(n, false);\n    int m = 0;\n    for (int i = n - 2; i >= 0; i--) is_s[i]\
    \ = (s[i] == s[i + 1] ? is_s[i + 1] : (s[i] < s[i + 1]));\n    for (int i = 0;\
    \ i < n; i++) {\n        if (!is_s[i])\n            sum_s[s[i]]++;\n        else\
    \ {\n            sum_l[s[i] + 1]++;\n            if (!i || !is_s[i - 1]) {\n \
    \               lms_map[i] = m++;\n                lms.emplace_back(i);\n    \
    \        }\n        }\n    }\n    for (int i = 0; i <= upper; i++) {\n       \
    \ sum_s[i] += sum_l[i];\n        if (i < upper) sum_l[i + 1] += sum_s[i];\n  \
    \  }\n\n    auto induced_sort = [&](const vector<int>& lms) {\n        fill(sa.begin(),\
    \ sa.end(), -1);\n        vector<int> buf(upper + 1);\n        copy(sum_s.begin(),\
    \ sum_s.end(), buf.begin());\n        for (int idx : lms) sa[buf[s[idx]]++] =\
    \ idx;\n\n        copy(sum_l.begin(), sum_l.end(), buf.begin());\n        sa[buf[s[n\
    \ - 1]]++] = n - 1;\n        for (int i = 0; i < n; i++) {\n            if (sa[i]\
    \ < 1 || is_s[sa[i] - 1]) continue;\n            int c = s[sa[i] - 1];\n     \
    \       sa[buf[c]++] = sa[i] - 1;\n        }\n\n        copy(sum_l.begin(), sum_l.end(),\
    \ buf.begin());\n        for (int i = n - 1; i >= 0; i--) {\n            if (sa[i]\
    \ < 1 || !is_s[sa[i] - 1]) continue;\n            int c = s[sa[i] - 1];\n    \
    \        sa[--buf[c + 1]] = sa[i] - 1;\n        }\n    };\n\n    induced_sort(lms);\n\
    \    if (m) {\n        vector<int> sorted_lms;\n        for (int& idx : sa) {\n\
    \            if (~lms_map[idx]) {\n                sorted_lms.emplace_back(idx);\n\
    \            }\n        }\n        vector<int> rec_s(m);\n        int rec_upper\
    \ = 0;\n        rec_s[lms_map[sorted_lms[0]]] = rec_upper;\n\n        for (int\
    \ i = 1; i < m; i++) {\n            int l = sorted_lms[i - 1], r = sorted_lms[i];\n\
    \            int end_l = (lms_map[l] + 1 < m ? lms[lms_map[l] + 1] : n);\n   \
    \         int end_r = (lms_map[r] + 1 < m ? lms[lms_map[r] + 1] : n);\n      \
    \      bool same = true;\n            if (end_l - l != end_r - r)\n          \
    \      same = false;\n            else {\n                for (; l < end_l; l++,\
    \ r++) {\n                    if (s[l] != s[r]) {\n                        break;\n\
    \                    }\n                }\n                if (l == n || s[l]\
    \ != s[r]) same = false;\n            }\n            rec_s[lms_map[sorted_lms[i]]]\
    \ = (same ? rec_upper : ++rec_upper);\n        }\n\n        if (rec_upper + 1\
    \ != m) {\n            auto rec_sa = sa_is(rec_s, rec_upper);\n            for\
    \ (int i = 0; i < m; i++) sorted_lms[i] = lms[rec_sa[i]];\n        }\n       \
    \ induced_sort(sorted_lms);\n    }\n\n    return sa;\n}\n\nvector<int> suffix_array(const\
    \ vector<int>& s, int upper) {\n    for (int x : s) assert(0 <= x && x <= upper);\n\
    \    return sa_is(s, upper);\n}\ntemplate <class T> vector<int> suffix_array(const\
    \ vector<T>& s) {\n    int n = s.size();\n    vector<int> idx(n);\n    iota(idx.begin(),\
    \ idx.end(), 0);\n    sort(idx.begin(), idx.end(), [&](int x, int y) { return\
    \ s[x] < s[y]; });\n    vector<int> ns(n);\n    int cur = 0;\n    for (int i =\
    \ 0; i < n; i++) {\n        if (i && s[idx[i - 1]] != s[idx[i]]) cur++;\n    \
    \    ns[idx[i]] = cur;\n    }\n    return sa_is(s, cur);\n}\nvector<int> suffix_array(const\
    \ string& s) {\n    vector<int> ns;\n    for (char c : s) ns.emplace_back(c);\n\
    \    return sa_is(ns, 255);\n}\n\ntemplate <class T> vector<int> lcp_array(const\
    \ vector<T>& s, const vector<int>& sa) {\n    int n = s.size();\n    vector<int>\
    \ rank(n);\n    for (int i = 0; i < n; i++) rank[sa[i]] = i;\n    vector<int>\
    \ lcp(n - 1);\n    for (int i = 0, h = 0; i < n; i++) {\n        if (h > 0) h--;\n\
    \        if (rank[i] == 0) continue;\n        int j = sa[rank[i] - 1];\n     \
    \   for (; j + h < n && i + h < n; h++) {\n            if (s[j + h] != s[i + h])\
    \ {\n                break;\n            }\n        }\n        lcp[rank[i] - 1]\
    \ = h;\n    }\n    return lcp;\n}\n\nvector<int> lcp_array(const string& s, const\
    \ vector<int>& sa) {\n    vector<int> ns;\n    for (char c : s) ns.emplace_back(c);\n\
    \    return lcp_array(ns, sa);\n}\n}  // namespace SuffixArray"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/SuffixArray.hpp
  requiredBy: []
  timestamp: '2021-10-31 14:57:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/suffixarray.test.cpp
  - test/yosupo/number_of_substrings.test.cpp
documentation_of: string/SuffixArray.hpp
layout: document
redirect_from:
- /library/string/SuffixArray.hpp
- /library/string/SuffixArray.hpp.html
title: Suffix Array + Longest Common Prefix Array
---
## 概要
以下, 文字列 `s` の $l$ 番目から $r - 1$ 番目までの部分文字列を `s[l,r)` , $l$ 番目から末尾までの部分文字列を `s[l)` と表すことにする.

与えられた文字列 $S$ の Suffix Array を返す.
Suffix Array `sa` とは, 順列 $(0, 1, \cdots, n - 1)$ をその index から始まる接尾辞の辞書順によってソートしたものである.

これは SA-IS と呼ばれるアルゴリズムによって $O(\|S\|)$ で構築することができる.

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