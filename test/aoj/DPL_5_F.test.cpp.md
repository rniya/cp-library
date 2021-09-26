---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: combinatorics/binomial.hpp
    title: binomial
  - icon: ':question:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_F
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_F
  bundledCode: "#line 1 \"test/aoj/DPL_5_F.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_F\"\
    \n\n#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#pragma\
    \ region Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned\
    \ int uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\
    \ntemplate <typename T> istream& operator>>(istream& is, vector<T>& v) {\n   \
    \ for (T& x : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n \
    \       os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ map<T, U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();)\
    \ {\n        os << '(' << itr->first << ',' << itr->second << ')';\n        if\
    \ (++itr != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate\
    \ <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T,\
    \ U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr != m.end();) {\n\
    \        os << '(' << itr->first << ',' << itr->second << ')';\n        if (++itr\
    \ != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const set<T>& s) {\n    os << '{';\n   \
    \ for (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n       \
    \ if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\n\
    template <typename T> ostream& operator<<(ostream& os, const multiset<T>& s) {\n\
    \    os << '{';\n    for (auto itr = s.begin(); itr != s.end();) {\n        os\
    \ << *itr;\n        if (++itr != s.end()) os << ',';\n    }\n    os << '}';\n\
    \    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream& os, const\
    \ unordered_set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const deque<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n  \
    \      os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 4 \"combinatorics/binomial.hpp\"\
    \n\ntemplate <typename T> struct Binomial {\n    Binomial(int MAX = 0) : n(1),\
    \ facs(1, T(1)), finvs(1, T(1)), invs(1, T(1)) {\n        while (n <= MAX) extend();\n\
    \    }\n\n    T fac(int i) {\n        assert(i >= 0);\n        while (n <= i)\
    \ extend();\n        return facs[i];\n    }\n\n    T finv(int i) {\n        assert(i\
    \ >= 0);\n        while (n <= i) extend();\n        return finvs[i];\n    }\n\n\
    \    T inv(int i) {\n        assert(i >= 0);\n        while (n <= i) extend();\n\
    \        return invs[i];\n    }\n\n    T P(int n, int r) {\n        if (n < 0\
    \ || n < r || r < 0) return T(0);\n        return fac(n) * finv(n - r);\n    }\n\
    \n    T C(int n, int r) {\n        if (n < 0 || n < r || r < 0) return T(0);\n\
    \        return fac(n) * finv(n - r) * finv(r);\n    }\n\n    T H(int n, int r)\
    \ {\n        if (n < 0 || r < 0) return T(0);\n        return r == 0 ? 1 : C(n\
    \ + r - 1, r);\n    }\n\n    T C_naive(int n, int r) {\n        if (n < 0 || n\
    \ < r || r < 0) return T(0);\n        T res = 1;\n        r = std::min(r, n -\
    \ r);\n        for (int i = 1; i <= r; i++) res *= inv(i) * (n--);\n        return\
    \ res;\n    }\n\nprivate:\n    int n;\n    std::vector<T> facs, finvs, invs;\n\
    \n    inline void extend() {\n        int m = n << 1;\n        facs.resize(m);\n\
    \        finvs.resize(m);\n        invs.resize(m);\n        for (int i = n; i\
    \ < m; i++) facs[i] = facs[i - 1] * i;\n        finvs[m - 1] = T(1) / facs[m -\
    \ 1];\n        invs[m - 1] = finvs[m - 1] * facs[m - 2];\n        for (int i =\
    \ m - 2; i >= n; i--) {\n            finvs[i] = finvs[i + 1] * (i + 1);\n    \
    \        invs[i] = finvs[i] * facs[i - 1];\n        }\n        n = m;\n    }\n\
    };\n\n/**\n * @brief binomial\n * @docs docs/combinatorics/binomial.md\n */\n\
    #line 5 \"modulo/modint.hpp\"\n\ntemplate <uint64_t Modulus> class modint {\n\
    \    using i64 = int64_t;\n    using u32 = uint32_t;\n    using u64 = uint64_t;\n\
    \n    static_assert(Modulus < static_cast<uint32_t>(1) << 31, \"Modulus must be\
    \ less than 2**31\");\n    static constexpr u32 mod = Modulus;\n    u32 v;\n\n\
    public:\n    constexpr modint(const i64 x = 0) noexcept : v(x < 0 ? mod - 1 -\
    \ (-(x + 1) % mod) : x % mod) {}\n    constexpr u32& value() noexcept { return\
    \ v; }\n    constexpr const u32& value() const noexcept { return v; }\n    constexpr\
    \ modint operator+(const modint& rhs) const noexcept { return modint(*this) +=\
    \ rhs; }\n    constexpr modint operator-(const modint& rhs) const noexcept { return\
    \ modint(*this) -= rhs; }\n    constexpr modint operator*(const modint& rhs) const\
    \ noexcept { return modint(*this) *= rhs; }\n    constexpr modint operator/(const\
    \ modint& rhs) const noexcept { return modint(*this) /= rhs; }\n    constexpr\
    \ modint& operator+=(const modint& rhs) noexcept {\n        v += rhs.v;\n    \
    \    if (v >= mod) v -= mod;\n        return *this;\n    }\n    constexpr modint&\
    \ operator-=(const modint& rhs) noexcept {\n        if (v < rhs.v) v += mod;\n\
    \        v -= rhs.v;\n        return *this;\n    }\n    constexpr modint& operator*=(const\
    \ modint& rhs) noexcept {\n        v = (u64)v * rhs.v % mod;\n        return *this;\n\
    \    }\n    constexpr modint& operator/=(const modint& rhs) noexcept { return\
    \ *this *= rhs.inv(); }\n    constexpr modint pow(long long n) const noexcept\
    \ {\n        assert(0 <= n);\n        modint self(*this), res(1);\n        while\
    \ (n > 0) {\n            if (n & 1) res *= self;\n            self *= self;\n\
    \            n >>= 1;\n        }\n        return res;\n    }\n    constexpr modint\
    \ inv() const noexcept {\n        assert(*this != 0);\n        return pow(mod\
    \ - 2);\n    }\n    constexpr modint& operator++() noexcept {\n        if (++v\
    \ == mod) v = 0;\n        return *this;\n    }\n    constexpr modint& operator--()\
    \ noexcept {\n        if (v == 0) v = mod;\n        return --v, *this;\n    }\n\
    \    constexpr modint operator++(int) noexcept {\n        modint t = *this;\n\
    \        return ++*this, t;\n    }\n    constexpr modint operator--(int) noexcept\
    \ {\n        modint t = *this;\n        return --*this, t;\n    }\n    constexpr\
    \ modint operator-() const noexcept { return modint(mod - v); }\n    template\
    \ <class T> friend constexpr modint operator+(T x, modint y) noexcept { return\
    \ modint(x) + y; }\n    template <class T> friend constexpr modint operator-(T\
    \ x, modint y) noexcept { return modint(x) - y; }\n    template <class T> friend\
    \ constexpr modint operator*(T x, modint y) noexcept { return modint(x) * y; }\n\
    \    template <class T> friend constexpr modint operator/(T x, modint y) noexcept\
    \ { return modint(x) / y; }\n    constexpr bool operator==(const modint& rhs)\
    \ const noexcept { return v == rhs.v; }\n    constexpr bool operator!=(const modint&\
    \ rhs) const noexcept { return v != rhs.v; }\n    constexpr bool operator!() const\
    \ noexcept { return !v; }\n    friend std::istream& operator>>(std::istream& s,\
    \ modint& rhs) noexcept {\n        i64 v;\n        rhs = modint{(s >> v, v)};\n\
    \        return s;\n    }\n    friend std::ostream& operator<<(std::ostream& s,\
    \ const modint& rhs) noexcept { return s << rhs.v; }\n};\n\n/**\n * @brief modint\n\
    \ * @docs docs/modulo/modint.md\n */\n#line 6 \"test/aoj/DPL_5_F.test.cpp\"\n\n\
    using mint = modint<1000000007>;\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    Binomial<mint> BINOM;\n    int n, k;\n    cin >> n >> k;\n\n    cout << BINOM.C(n\
    \ - 1, n - k) << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_F\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../combinatorics/binomial.hpp\"\
    \n#include \"../../modulo/modint.hpp\"\n\nusing mint = modint<1000000007>;\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    Binomial<mint>\
    \ BINOM;\n    int n, k;\n    cin >> n >> k;\n\n    cout << BINOM.C(n - 1, n -\
    \ k) << '\\n';\n}"
  dependsOn:
  - base.hpp
  - combinatorics/binomial.hpp
  - modulo/modint.hpp
  isVerificationFile: true
  path: test/aoj/DPL_5_F.test.cpp
  requiredBy: []
  timestamp: '2021-09-26 16:55:29+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_F.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_F.test.cpp
- /verify/test/aoj/DPL_5_F.test.cpp.html
title: test/aoj/DPL_5_F.test.cpp
---
