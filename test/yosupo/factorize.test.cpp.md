---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: math/fast_factorize.hpp
    title: "\u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3 (Miller-Rabin primality test\
      \ + Pollard's rho algorithm)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/factorize
    links:
    - https://judge.yosupo.jp/problem/factorize
  bundledCode: "#line 1 \"test/yosupo/factorize.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 3 \"math/fast_factorize.hpp\"\
    \n\n/**\n * @brief \u9AD8\u901F\u7D20\u56E0\u6570\u5206\u89E3 (Miller-Rabin primality\
    \ test + Pollard's rho algorithm)\n * @docs docs/math/fast_factorize.md\n */\n\
    namespace fast_factorize {\nusing u64 = uint64_t;\n\nmt19937_64 mt(random_device{}());\n\
    u64 rng(u64 n) { return uniform_int_distribution<u64>(0, n - 1)(mt); }\n\nstruct\
    \ montgomery64 {\n    using i64 = int64_t;\n    using u64 = uint64_t;\n    using\
    \ u128 = __uint128_t;\n\n    static u64 mod, r, n2;\n\n    static u64 get_r()\
    \ {\n        u64 res = mod;\n        for (int _ = 0; _ < 5; _++) res *= 2 - mod\
    \ * res;\n        return -res;\n    }\n\n    static void set_mod(u64 m) {\n  \
    \      assert(m < (1ULL << 62));\n        assert((m & 1) == 1);\n        mod =\
    \ m;\n        n2 = -u128(m) % m;\n        r = get_r();\n        assert(r * mod\
    \ == -1ULL);\n    }\n    static u64 get_mod() { return mod; }\n\n    static u64\
    \ reduce(const u128& x) noexcept { return (x + u128(u64(x) * r) * mod) >> 64;\
    \ }\n\n    u64 v;\n    montgomery64() : v(0) {}\n    montgomery64(const i64& v)\
    \ : v(reduce((u128(v) + mod) * n2)) {}\n    u64 value() const {\n        u64 res\
    \ = reduce(v);\n        return res >= mod ? res - mod : res;\n    }\n    montgomery64&\
    \ operator+=(const montgomery64& rhs) {\n        if (i64(v += rhs.v - (mod <<\
    \ 1)) < 0) v += mod << 1;\n        return *this;\n    }\n    montgomery64& operator-=(const\
    \ montgomery64& rhs) {\n        if (i64(v -= rhs.v) < 0) v += mod << 1;\n    \
    \    return *this;\n    }\n    montgomery64& operator*=(const montgomery64& rhs)\
    \ {\n        v = reduce(u128(v) * rhs.v);\n        return *this;\n    }\n    montgomery64\
    \ operator+(const montgomery64& rhs) const { return montgomery64(*this) += rhs;\
    \ }\n    montgomery64 operator-(const montgomery64& rhs) const { return montgomery64(*this)\
    \ -= rhs; }\n    montgomery64 operator*(const montgomery64& rhs) const { return\
    \ montgomery64(*this) *= rhs; }\n    bool operator==(const montgomery64& rhs)\
    \ const {\n        return (v >= mod ? v - mod : v) == (rhs.v >= mod ? rhs.v -\
    \ mod : rhs.v);\n    }\n    bool operator!=(const montgomery64& rhs) const {\n\
    \        return (v >= mod ? v - mod : v) != (rhs.v >= mod ? rhs.v - mod : rhs.v);\n\
    \    }\n    montgomery64 pow(u64 n) const {\n        montgomery64 self(*this),\
    \ res(1);\n        while (n > 0) {\n            if (n & 1) res *= self;\n    \
    \        self *= self;\n            n >>= 1;\n        }\n        return res;\n\
    \    }\n    friend istream& operator>>(istream& s, montgomery64& rhs) {\n    \
    \    i64 v;\n        rhs = montgomery64{(s >> v, v)};\n        return s;\n   \
    \ }\n    friend ostream& operator<<(ostream& s, const montgomery64& rhs) { return\
    \ s << rhs.v; }\n};\ntypename montgomery64::u64 montgomery64::mod, montgomery64::r,\
    \ montgomery64::n2;\n\nbool miller_rabin(const u64& n, const vector<u64>& as)\
    \ {\n    if (montgomery64::get_mod() != n) montgomery64::set_mod(n);\n    const\
    \ u64 d = (n - 1) >> __builtin_ctzll(n - 1);\n    const montgomery64 one(1), minus_one(n\
    \ - 1);\n    for (u64 a : as) {\n        if (n <= a) break;\n        u64 t = d;\n\
    \        montgomery64 y = montgomery64(a).pow(t);\n        while (t != n - 1 &&\
    \ y != one && y != minus_one) {\n            y *= y;\n            t <<= 1;\n \
    \       }\n        if (y != minus_one && t % 2 == 0) return false;\n    }\n  \
    \  return true;\n}\nbool is_prime(const u64& n) {\n    if (n == 2 || n == 3 ||\
    \ n == 5 || n == 7) return true;\n    if (n % 2 == 0 || n % 3 == 0 || n % 5 ==\
    \ 0 || n % 7 == 0) return false;\n    if (n < 121) return n > 1;\n    if (n <\
    \ (1ULL << 32)) return miller_rabin(n, {2, 7, 61});\n    return miller_rabin(n,\
    \ {2, 325, 9375, 28178, 450775, 9780504, 1795265022});\n}\n\nu64 pollard_rho(const\
    \ u64& n) {\n    if (~n & 1) return 2;\n    if (is_prime(n)) return n;\n    if\
    \ (montgomery64::get_mod() != n) montgomery64::set_mod(n);\n    montgomery64 R,\
    \ one(1);\n    auto f = [&](const montgomery64& x) { return x * x + R; };\n  \
    \  constexpr int m = 128;\n    while (1) {\n        montgomery64 x, y, ys, q =\
    \ one;\n        R = rng(n - 2) + 2, y = rng(n - 2) + 2;\n        u64 g = 1;\n\
    \        for (int r = 1; g == 1; r <<= 1) {\n            x = y;\n            for\
    \ (int i = 0; i < r; i++) y = f(y);\n            for (int k = 0; g == 1 && k <\
    \ r; k += m) {\n                ys = y;\n                for (int i = 0; i < min(m,\
    \ r - k); i++) q *= x - (y = f(y));\n                g = gcd(q.value(), n);\n\
    \            }\n        }\n        if (g == n) {\n            do g = gcd((x -\
    \ (ys = f(ys))).value(), n);\n            while (g == 1);\n        }\n       \
    \ if (g != n) return g;\n    }\n    cerr << \"failed\" << '\\n';\n    assert(false);\n\
    \    return -1;\n}\n\nvector<u64> inner_factorize(u64 n) {\n    if (n <= 1) return\
    \ {};\n    u64 p = pollard_rho(n);\n    if (p == n) return {p};\n    auto l =\
    \ inner_factorize(p);\n    auto r = inner_factorize(n / p);\n    copy(r.begin(),\
    \ r.end(), back_inserter(l));\n    return l;\n}\nvector<u64> factorize(u64 n)\
    \ {\n    auto res = inner_factorize(n);\n    sort(res.begin(), res.end());\n \
    \   return res;\n}\n}  // namespace fast_factorize\n#line 5 \"test/yosupo/factorize.test.cpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int Q;\n\
    \    cin >> Q;\n    for (; Q--;) {\n        long long a;\n        cin >> a;\n\
    \        auto res = fast_factorize::factorize(a);\n        cout << res.size();\n\
    \        for (auto& x : res) cout << ' ' << x;\n        cout << '\\n';\n    }\n\
    \    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/factorize\"\n\n#include\
    \ \"../../base.hpp\"\n#include \"../../math/fast_factorize.hpp\"\n\nint main()\
    \ {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int Q;\n    cin >>\
    \ Q;\n    for (; Q--;) {\n        long long a;\n        cin >> a;\n        auto\
    \ res = fast_factorize::factorize(a);\n        cout << res.size();\n        for\
    \ (auto& x : res) cout << ' ' << x;\n        cout << '\\n';\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - base.hpp
  - math/fast_factorize.hpp
  isVerificationFile: true
  path: test/yosupo/factorize.test.cpp
  requiredBy: []
  timestamp: '2021-09-16 21:38:19+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/factorize.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/factorize.test.cpp
- /verify/test/yosupo/factorize.test.cpp.html
title: test/yosupo/factorize.test.cpp
---
