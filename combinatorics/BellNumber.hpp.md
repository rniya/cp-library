---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DPL_5_G.test.cpp
    title: test/aoj/DPL_5_G.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/combinatorics/BellNumber.md
    document_title: "\u30D9\u30EB\u6570"
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"combinatorics/BellNumber.hpp\"\
    \n\n/**\n * @brief \u30D9\u30EB\u6570\n * @docs docs/combinatorics/BellNumber.md\n\
    \ */\ntemplate <typename T> T bell_number(int n, int k) {\n    if (n == 0) return\
    \ 1;\n    k = min(k, n);\n    Combination<T> COM(k);\n    vector<T> sum(k + 1);\n\
    \    sum[0] = 1;\n    for (int i = 1; i <= k; i++) {\n        if (i & 1)\n   \
    \         sum[i] = sum[i - 1] - COM.finv(i);\n        else\n            sum[i]\
    \ = sum[i - 1] + COM.finv(i);\n    }\n    T res = 0;\n    for (int i = 1; i <=\
    \ k; i++) {\n        res += T(i).pow(n) * COM.finv(i) * sum[k - i];\n    }\n \
    \   return res;\n}\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief \u30D9\u30EB\u6570\
    \n * @docs docs/combinatorics/BellNumber.md\n */\ntemplate <typename T> T bell_number(int\
    \ n, int k) {\n    if (n == 0) return 1;\n    k = min(k, n);\n    Combination<T>\
    \ COM(k);\n    vector<T> sum(k + 1);\n    sum[0] = 1;\n    for (int i = 1; i <=\
    \ k; i++) {\n        if (i & 1)\n            sum[i] = sum[i - 1] - COM.finv(i);\n\
    \        else\n            sum[i] = sum[i - 1] + COM.finv(i);\n    }\n    T res\
    \ = 0;\n    for (int i = 1; i <= k; i++) {\n        res += T(i).pow(n) * COM.finv(i)\
    \ * sum[k - i];\n    }\n    return res;\n}"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: combinatorics/BellNumber.hpp
  requiredBy: []
  timestamp: '2021-01-20 10:53:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/DPL_5_G.test.cpp
documentation_of: combinatorics/BellNumber.hpp
layout: document
redirect_from:
- /library/combinatorics/BellNumber.hpp
- /library/combinatorics/BellNumber.hpp.html
title: "\u30D9\u30EB\u6570"
---
## 概要
ベル数$B\left(n,k\right)$は$n$個の区別できる玉を$k$個の区別できない箱に入れる組合せ数, すなわち整数$1$から$n$を$k$個以下のグループに分割する場合の数である. これは, スターリング数$S\left(n,k\right)$をもとに,
$$\begin{aligned}
B\left(n,k\right)&=\sum_{j=0}^k S\left(n,k\right)\\
&=\sum_{j=0}^k \dfrac{1}{j!} \sum_{i=0}^j \left(-1\right)^{j-i}\binom{j}{i}i^n\\
&=\sum_{j=0}^k \sum_{i=0}^j \dfrac{\left(-1\right)^{j-i}}{i!\left(j-i\right)!}i^n\\
&=\sum_{i=0}^k \sum_{j=i}^k \dfrac{\left(-1\right)^{j-i}}{i!\left(j-i\right)!}i^n\\
&=\sum_{i=0}^k \sum_{j=0}^{k-i} \dfrac{\left(-1\right)^j}{i!j!}i^n\\
&=\sum_{i=0}^k \dfrac{i^n}{i!} \sum_{j=0}^{k-1} \dfrac{\left(-1\right)^j}{j!}
\end{aligned}$$
と計算できる. $\sum_{j=0}^{k-1} \frac{\left(-1\right)^j}{j!}$は累積和のように前計算できる.

## 計算量
$O\left(\min\left(n,k\right)\log{n}\right)$

## 参照
[「写像12相」を総整理！ 〜 数え上げ問題の学びの宝庫 〜 - Qiita](https://qiita.com/drken/items/f2ea4b58b0d21621bd51)