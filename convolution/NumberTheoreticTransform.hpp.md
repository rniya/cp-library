---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: convolution/ArbitaryModConvolution.hpp
    title: "Arbirary Mod Convolution (\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.test.cpp
    title: test/yosupo/convolution_mod.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod_1000000007.test.cpp
    title: test/yosupo/convolution_mod_1000000007.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/exp_of_formal_power_series.test.cpp
    title: test/yosupo/exp_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/inv_of_formal_power_series.test.cpp
    title: test/yosupo/inv_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/log_of_formal_power_series.test.cpp
    title: test/yosupo/log_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/pow_of_formal_power_series.test.cpp
    title: test/yosupo/pow_of_formal_power_series.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
    title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1068.test.cpp
    title: test/yukicoder/1068.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1302.test.cpp
    title: test/yukicoder/1302.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/3046.test.cpp
    title: test/yukicoder/3046.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/931.test.cpp
    title: test/yukicoder/931.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/convolution/NumberTheoreticTransform.md
    document_title: Number Theoretic Transform
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 5 \"modulo/modint.hpp\"\
    \n\ntemplate <uint64_t Modulus> class modint {\n    using i64 = int64_t;\n   \
    \ using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static_assert(Modulus\
    \ < static_cast<uint32_t>(1) << 31, \"Modulus must be less than 2**31\");\n  \
    \  static constexpr u32 mod = Modulus;\n    u32 v;\n\npublic:\n    constexpr modint(const\
    \ i64 x = 0) noexcept : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}\n \
    \   constexpr u32& val() noexcept { return v; }\n    constexpr const u32& val()\
    \ const noexcept { return v; }\n    constexpr modint operator+(const modint& rhs)\
    \ const noexcept { return modint(*this) += rhs; }\n    constexpr modint operator-(const\
    \ modint& rhs) const noexcept { return modint(*this) -= rhs; }\n    constexpr\
    \ modint operator*(const modint& rhs) const noexcept { return modint(*this) *=\
    \ rhs; }\n    constexpr modint operator/(const modint& rhs) const noexcept { return\
    \ modint(*this) /= rhs; }\n    constexpr modint& operator+=(const modint& rhs)\
    \ noexcept {\n        v += rhs.v;\n        if (v >= mod) v -= mod;\n        return\
    \ *this;\n    }\n    constexpr modint& operator-=(const modint& rhs) noexcept\
    \ {\n        if (v < rhs.v) v += mod;\n        v -= rhs.v;\n        return *this;\n\
    \    }\n    constexpr modint& operator*=(const modint& rhs) noexcept {\n     \
    \   v = (u64)v * rhs.v % mod;\n        return *this;\n    }\n    constexpr modint&\
    \ operator/=(const modint& rhs) noexcept { return *this *= rhs.inv(); }\n    constexpr\
    \ modint pow(long long n) const noexcept {\n        assert(0 <= n);\n        modint\
    \ self(*this), res(1);\n        while (n > 0) {\n            if (n & 1) res *=\
    \ self;\n            self *= self;\n            n >>= 1;\n        }\n        return\
    \ res;\n    }\n    constexpr modint inv() const noexcept {\n        assert(*this\
    \ != 0);\n        return pow(mod - 2);\n    }\n    constexpr modint& operator++()\
    \ noexcept {\n        if (++v == mod) v = 0;\n        return *this;\n    }\n \
    \   constexpr modint& operator--() noexcept {\n        if (v == 0) v = mod;\n\
    \        return --v, *this;\n    }\n    constexpr modint operator++(int) noexcept\
    \ {\n        modint t = *this;\n        return ++*this, t;\n    }\n    constexpr\
    \ modint operator--(int) noexcept {\n        modint t = *this;\n        return\
    \ --*this, t;\n    }\n    constexpr modint operator-() const noexcept { return\
    \ modint(mod - v); }\n    template <class T> friend constexpr modint operator+(T\
    \ x, modint y) noexcept { return modint(x) + y; }\n    template <class T> friend\
    \ constexpr modint operator-(T x, modint y) noexcept { return modint(x) - y; }\n\
    \    template <class T> friend constexpr modint operator*(T x, modint y) noexcept\
    \ { return modint(x) * y; }\n    template <class T> friend constexpr modint operator/(T\
    \ x, modint y) noexcept { return modint(x) / y; }\n    constexpr bool operator==(const\
    \ modint& rhs) const noexcept { return v == rhs.v; }\n    constexpr bool operator!=(const\
    \ modint& rhs) const noexcept { return v != rhs.v; }\n    constexpr bool operator!()\
    \ const noexcept { return !v; }\n    friend std::istream& operator>>(std::istream&\
    \ s, modint& rhs) noexcept {\n        i64 v;\n        rhs = modint{(s >> v, v)};\n\
    \        return s;\n    }\n    friend std::ostream& operator<<(std::ostream& s,\
    \ const modint& rhs) noexcept { return s << rhs.v; }\n};\n\n/**\n * @brief modint\n\
    \ * @docs docs/modulo/modint.md\n */\n#line 4 \"convolution/NumberTheoreticTransform.hpp\"\
    \n\n/**\n * @brief Number Theoretic Transform\n * @docs docs/convolution/NumberTheoreticTransform.md\n\
    \ */\ntemplate <int mod> struct NumberTheoreticTransform {\n    using Mint = modint<mod>;\n\
    \    vector<Mint> roots;\n    vector<int> rev;\n    int base, max_base;\n    Mint\
    \ root;\n    NumberTheoreticTransform() : base(1), rev{0, 1}, roots{Mint(0), Mint(1)}\
    \ {\n        int tmp = mod - 1;\n        for (max_base = 0; tmp % 2 == 0; max_base++)\
    \ tmp >>= 1;\n        root = 2;\n        while (root.pow((mod - 1) >> 1) == 1)\
    \ root++;\n        root = root.pow((mod - 1) >> max_base);\n    }\n    void ensure_base(int\
    \ nbase) {\n        if (nbase <= base) return;\n        rev.resize(1 << nbase);\n\
    \        for (int i = 0; i < (1 << nbase); i++) {\n            rev[i] = (rev[i\
    \ >> 1] >> 1) | ((i & 1) << (nbase - 1));\n        }\n        roots.resize(1 <<\
    \ nbase);\n        for (; base < nbase; base++) {\n            Mint z = root.pow(1\
    \ << (max_base - 1 - base));\n            for (int i = 1 << (base - 1); i < (1\
    \ << base); i++) {\n                roots[i << 1] = roots[i];\n              \
    \  roots[i << 1 | 1] = roots[i] * z;\n            }\n        }\n    }\n    void\
    \ ntt(vector<Mint>& a) {\n        const int n = a.size();\n        int zeros =\
    \ __builtin_ctz(n);\n        ensure_base(zeros);\n        int shift = base - zeros;\n\
    \        for (int i = 0; i < n; i++) {\n            if (i < (rev[i] >> shift))\
    \ {\n                swap(a[i], a[rev[i] >> shift]);\n            }\n        }\n\
    \        for (int k = 1; k < n; k <<= 1) {\n            for (int i = 0; i < n;\
    \ i += (k << 1)) {\n                for (int j = 0; j < k; j++) {\n          \
    \          Mint z = a[i + j + k] * roots[j + k];\n                    a[i + j\
    \ + k] = a[i + j] - z;\n                    a[i + j] = a[i + j] + z;\n       \
    \         }\n            }\n        }\n    }\n    vector<Mint> multiply(vector<Mint>\
    \ a, vector<Mint> b) {\n        int need = a.size() + b.size() - 1;\n        int\
    \ nbase = 1;\n        while ((1 << nbase) < need) nbase++;\n        ensure_base(nbase);\n\
    \        int sz = 1 << nbase;\n        a.resize(sz, Mint(0));\n        b.resize(sz,\
    \ Mint(0));\n        ntt(a);\n        ntt(b);\n        Mint inv_sz = 1 / Mint(sz);\n\
    \        for (int i = 0; i < sz; i++) a[i] *= b[i] * inv_sz;\n        reverse(a.begin()\
    \ + 1, a.end());\n        ntt(a);\n        a.resize(need);\n        return a;\n\
    \    }\n    vector<int> multiply(vector<int> a, vector<int> b) {\n        vector<Mint>\
    \ A(a.size()), B(b.size());\n        for (int i = 0; i < a.size(); i++) A[i] =\
    \ Mint(a[i]);\n        for (int i = 0; i < b.size(); i++) B[i] = Mint(b[i]);\n\
    \        vector<Mint> C = multiply(A, B);\n        vector<int> res(C.size());\n\
    \        for (int i = 0; i < C.size(); i++) res[i] = C[i].v;\n        return res;\n\
    \    }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"../modulo/modint.hpp\"\
    \n\n/**\n * @brief Number Theoretic Transform\n * @docs docs/convolution/NumberTheoreticTransform.md\n\
    \ */\ntemplate <int mod> struct NumberTheoreticTransform {\n    using Mint = modint<mod>;\n\
    \    vector<Mint> roots;\n    vector<int> rev;\n    int base, max_base;\n    Mint\
    \ root;\n    NumberTheoreticTransform() : base(1), rev{0, 1}, roots{Mint(0), Mint(1)}\
    \ {\n        int tmp = mod - 1;\n        for (max_base = 0; tmp % 2 == 0; max_base++)\
    \ tmp >>= 1;\n        root = 2;\n        while (root.pow((mod - 1) >> 1) == 1)\
    \ root++;\n        root = root.pow((mod - 1) >> max_base);\n    }\n    void ensure_base(int\
    \ nbase) {\n        if (nbase <= base) return;\n        rev.resize(1 << nbase);\n\
    \        for (int i = 0; i < (1 << nbase); i++) {\n            rev[i] = (rev[i\
    \ >> 1] >> 1) | ((i & 1) << (nbase - 1));\n        }\n        roots.resize(1 <<\
    \ nbase);\n        for (; base < nbase; base++) {\n            Mint z = root.pow(1\
    \ << (max_base - 1 - base));\n            for (int i = 1 << (base - 1); i < (1\
    \ << base); i++) {\n                roots[i << 1] = roots[i];\n              \
    \  roots[i << 1 | 1] = roots[i] * z;\n            }\n        }\n    }\n    void\
    \ ntt(vector<Mint>& a) {\n        const int n = a.size();\n        int zeros =\
    \ __builtin_ctz(n);\n        ensure_base(zeros);\n        int shift = base - zeros;\n\
    \        for (int i = 0; i < n; i++) {\n            if (i < (rev[i] >> shift))\
    \ {\n                swap(a[i], a[rev[i] >> shift]);\n            }\n        }\n\
    \        for (int k = 1; k < n; k <<= 1) {\n            for (int i = 0; i < n;\
    \ i += (k << 1)) {\n                for (int j = 0; j < k; j++) {\n          \
    \          Mint z = a[i + j + k] * roots[j + k];\n                    a[i + j\
    \ + k] = a[i + j] - z;\n                    a[i + j] = a[i + j] + z;\n       \
    \         }\n            }\n        }\n    }\n    vector<Mint> multiply(vector<Mint>\
    \ a, vector<Mint> b) {\n        int need = a.size() + b.size() - 1;\n        int\
    \ nbase = 1;\n        while ((1 << nbase) < need) nbase++;\n        ensure_base(nbase);\n\
    \        int sz = 1 << nbase;\n        a.resize(sz, Mint(0));\n        b.resize(sz,\
    \ Mint(0));\n        ntt(a);\n        ntt(b);\n        Mint inv_sz = 1 / Mint(sz);\n\
    \        for (int i = 0; i < sz; i++) a[i] *= b[i] * inv_sz;\n        reverse(a.begin()\
    \ + 1, a.end());\n        ntt(a);\n        a.resize(need);\n        return a;\n\
    \    }\n    vector<int> multiply(vector<int> a, vector<int> b) {\n        vector<Mint>\
    \ A(a.size()), B(b.size());\n        for (int i = 0; i < a.size(); i++) A[i] =\
    \ Mint(a[i]);\n        for (int i = 0; i < b.size(); i++) B[i] = Mint(b[i]);\n\
    \        vector<Mint> C = multiply(A, B);\n        vector<int> res(C.size());\n\
    \        for (int i = 0; i < C.size(); i++) res[i] = C[i].v;\n        return res;\n\
    \    }\n};"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  isVerificationFile: false
  path: convolution/NumberTheoreticTransform.hpp
  requiredBy:
  - convolution/ArbitaryModConvolution.hpp
  timestamp: '2021-10-01 20:18:39+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1068.test.cpp
  - test/yukicoder/931.test.cpp
  - test/yukicoder/3046.test.cpp
  - test/yukicoder/1302.test.cpp
  - test/yosupo/convolution_mod.test.cpp
  - test/yosupo/stirling_number_of_the_second_kind.test.cpp
  - test/yosupo/inv_of_formal_power_series.test.cpp
  - test/yosupo/log_of_formal_power_series.test.cpp
  - test/yosupo/exp_of_formal_power_series.test.cpp
  - test/yosupo/convolution_mod_1000000007.test.cpp
  - test/yosupo/pow_of_formal_power_series.test.cpp
documentation_of: convolution/NumberTheoreticTransform.hpp
layout: document
redirect_from:
- /library/convolution/NumberTheoreticTransform.hpp
- /library/convolution/NumberTheoreticTransform.hpp.html
title: Number Theoretic Transform
---
## 概要
剰余環$\mathbb{Z}/p\mathbb{Z}$上でFFTを行う. このとき, $p$としてはNTT-friendlyな素数($998244353,1012924417,924844033$など)である必要がある.

## 問題例
[AGC047 C Product Modulo](https://atcoder.jp/contests/agc047/tasks/agc047_c)
一般に素数$P$について, 添字の剰余環$\mathbb{Z}/P\mathbb{Z}$における積での畳み込み, すなわち,
$$c_k=\sum_{i\times j\bmod P=k}a_ib_j$$
が計算できる. 具体的には, $P$の原子根$r$が取れて, $\mathbb{Z}/P\mathbb{Z}$の乗法群と$\mathbb{Z}/(P-1)\mathbb{Z}$が同型であることから, 各添字を$r$を底とした離散対数に変換して, その上でNTTを施した後に解を復元すれば良い. [これ](https://yukicoder.me/problems/no/931)が類題.
[AtCoder Beginner Contest 213 H - Stroll](https://atcoder.jp/contests/abc213/tasks/abc213_h)

## 計算量
$O(n\log n)$