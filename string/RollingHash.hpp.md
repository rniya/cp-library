---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1370.test.cpp
    title: test/aoj/1370.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_B.test.cpp
    title: test/aoj/ALDS1_14_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/430.test.cpp
    title: test/yukicoder/430.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/RollingHash.md
    document_title: Rolling Hash
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"string/RollingHash.hpp\"\
    \n\n/**\n * @brief Rolling Hash\n * @docs docs/string/RollingHash.md\n */\nclass\
    \ RollingHash {\n    using u64 = uint64_t;\n    using u128 = __uint128_t;\n  \
    \  static const u64 mod = (1ULL << 61) - 1;\n    const u64 base;\n    vector<u64>\
    \ hash, power;\n    static inline u64 add(u64 a, u64 b) {\n        if ((a += b)\
    \ >= mod) a -= mod;\n        return a;\n    }\n    static inline u64 mul(u64 a,\
    \ u64 b) {\n        u128 c = (u128)a * b;\n        return add(c >> 61, c & mod);\n\
    \    }\n\npublic:\n    static inline u64 generate_base() {\n        mt19937_64\
    \ mt(chrono::steady_clock::now().time_since_epoch().count());\n        uniform_int_distribution<u64>\
    \ rand(2, RollingHash::mod - 1);\n        return rand(mt);\n    }\n    RollingHash(u64\
    \ base = generate_base()) : base(base) {}\n    template <typename T> RollingHash(const\
    \ T& s, u64 base = generate_base()) : base(base) {\n        int n = s.size();\n\
    \        hash.assign(n + 1, 0);\n        power.assign(n + 1, 0);\n        power[0]\
    \ = 1;\n        for (int i = 0; i < n; i++) {\n            hash[i + 1] = add(mul(hash[i],\
    \ base), s[i]);\n            power[i + 1] = mul(power[i], base);\n        }\n\
    \    }\n    u64 query(int l, int r) const { return add(hash[r], mod - mul(hash[l],\
    \ power[r - l])); }\n    int lcp(int a, int b) const {\n        int len = min(hash.size()\
    \ - a, hash.size() - b);\n        int lb = 0, ub = len;\n        while (ub - lb\
    \ > 1) {\n            int mid = (lb + ub) >> 1;\n            (query(a, a + mid)\
    \ == query(b, b + mid) ? lb : ub) = mid;\n        }\n        return lb;\n    }\n\
    \    template <typename T> u64 get(const T& t) {\n        u64 res = 0;\n     \
    \   for (int i = 0; i < (int)t.size(); i++) res = add(mul(res, base), t[i]);\n\
    \        return res;\n    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n\n/**\n * @brief Rolling Hash\n *\
    \ @docs docs/string/RollingHash.md\n */\nclass RollingHash {\n    using u64 =\
    \ uint64_t;\n    using u128 = __uint128_t;\n    static const u64 mod = (1ULL <<\
    \ 61) - 1;\n    const u64 base;\n    vector<u64> hash, power;\n    static inline\
    \ u64 add(u64 a, u64 b) {\n        if ((a += b) >= mod) a -= mod;\n        return\
    \ a;\n    }\n    static inline u64 mul(u64 a, u64 b) {\n        u128 c = (u128)a\
    \ * b;\n        return add(c >> 61, c & mod);\n    }\n\npublic:\n    static inline\
    \ u64 generate_base() {\n        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());\n\
    \        uniform_int_distribution<u64> rand(2, RollingHash::mod - 1);\n      \
    \  return rand(mt);\n    }\n    RollingHash(u64 base = generate_base()) : base(base)\
    \ {}\n    template <typename T> RollingHash(const T& s, u64 base = generate_base())\
    \ : base(base) {\n        int n = s.size();\n        hash.assign(n + 1, 0);\n\
    \        power.assign(n + 1, 0);\n        power[0] = 1;\n        for (int i =\
    \ 0; i < n; i++) {\n            hash[i + 1] = add(mul(hash[i], base), s[i]);\n\
    \            power[i + 1] = mul(power[i], base);\n        }\n    }\n    u64 query(int\
    \ l, int r) const { return add(hash[r], mod - mul(hash[l], power[r - l])); }\n\
    \    int lcp(int a, int b) const {\n        int len = min(hash.size() - a, hash.size()\
    \ - b);\n        int lb = 0, ub = len;\n        while (ub - lb > 1) {\n      \
    \      int mid = (lb + ub) >> 1;\n            (query(a, a + mid) == query(b, b\
    \ + mid) ? lb : ub) = mid;\n        }\n        return lb;\n    }\n    template\
    \ <typename T> u64 get(const T& t) {\n        u64 res = 0;\n        for (int i\
    \ = 0; i < (int)t.size(); i++) res = add(mul(res, base), t[i]);\n        return\
    \ res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/RollingHash.hpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1370.test.cpp
  - test/aoj/ALDS1_14_B.test.cpp
  - test/yukicoder/430.test.cpp
documentation_of: string/RollingHash.hpp
layout: document
redirect_from:
- /library/string/RollingHash.hpp
- /library/string/RollingHash.hpp.html
title: Rolling Hash
---
## 概要
$\bmod 2^{61}-1$で基数は$\left[2,2^{61}-1\right)$の乱数によるRolling Hash.
- `generate_base()`：基数を生成する. 2つ以上の文字列に対しては同じ基数を用いねばならないので注意.
- `query(l,r)`：$[l,r)$のhash値を返す.
- `lcp(a,b)`：$a$文字目を$b$文字目を始点としたLongest Common Prefixの長さを返す.
- `get(t)`：文字列$t$のhash値を返す.

## 計算量
- `generate_base()`：$O(1)$
- `query(l,r)`：$O(1)$
- `lcp(a,b)`；$O(\log n)$
- `get(t)`：$O(|t|)$

## 問題例
[Codeforces Round #542 [Alex Lopashev Thanks-Round] (Div. 1) C. Morse Code](https://codeforces.com/contest/1129/problem/C) $\bmod$の値が小さいとかなりの確率で衝突し, hash値を2つもとうとするとTLEにハマるので, このRolling Hashが有効.

## 参照
[安全で爆速なRollingHashの話 - Qiita](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)