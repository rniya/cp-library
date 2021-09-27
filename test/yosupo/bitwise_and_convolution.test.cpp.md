---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/set_function.hpp
    title: set function (FZT, FMT, FWHT)
  - icon: ':heavy_check_mark:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_and_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_and_convolution
  bundledCode: "#line 1 \"test/yosupo/bitwise_and_convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\n\n#line\
    \ 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n#pragma region\
    \ Macros\ntypedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int\
    \ uint;\ntypedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 4 \"convolution/set_function.hpp\"\
    \n\nnamespace set_function {\n// subset sum : f(S) <- \\sum_{T \\subseteq S} f(T)\n\
    template <typename T> void subset_zeta_transform(std::vector<T>& f) {\n    int\
    \ n = f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i = 1; i < n; i\
    \ <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j & i) ==\
    \ 0) {\n                f[j | i] += f[j];\n            }\n        }\n    }\n}\n\
    \n// inverse of subset sum\n// g = FZT(f) \\iff f = FMT(g)\ntemplate <typename\
    \ T> void subset_mobius_transform(std::vector<T>& f) {\n    int n = f.size();\n\
    \    assert((n & (n - 1)) == 0);\n    for (int i = 1; i < n; i <<= 1) {\n    \
    \    for (int j = 0; j < n; j++) {\n            if ((j & i) == 0) {\n        \
    \        f[j | i] -= f[j];\n            }\n        }\n    }\n}\n\n// superset\
    \ sum : f(S) <- \\sum_{T \\supseteq S} f(T)\ntemplate <typename T> void superset_zeta_transform(std::vector<T>&\
    \ f) {\n    int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i\
    \ = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if\
    \ ((j & i) == 0) {\n                f[j] += f[j | i];\n            }\n       \
    \ }\n    }\n}\n\n// inverse of superset sum\n// g = FZT(f) \\iff f = FMT(g)\n\
    template <typename T> void superset_mobius_transform(std::vector<T>& f) {\n  \
    \  int n = f.size();\n    assert((n & (n - 1)) == 0);\n    for (int i = 1; i <\
    \ n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n            if ((j & i)\
    \ == 0) {\n                f[j] -= f[j | i];\n            }\n        }\n    }\n\
    }\n\ntemplate <typename T> void walsh_hadamard_transform(std::vector<T>& f, bool\
    \ inv = false) {\n    int n = f.size();\n    assert((n & (n - 1)) == 0);\n   \
    \ for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n \
    \           if ((j & i) == 0) {\n                T x = f[j], y = f[j | i];\n \
    \               f[j] = x + y, f[j | i] = x - y;\n            }\n        }\n  \
    \  }\n    if (inv) {\n        if (std::is_integral<T>::value) {\n            for\
    \ (auto& x : f) x /= n;\n        } else {\n            T inv_n = T(1) / f.size();\n\
    \            for (auto& x : f) x *= inv_n;\n        }\n    }\n}\n\ntemplate <typename\
    \ T> std::vector<T> and_convolution(std::vector<T> f, std::vector<T> g) {\n  \
    \  assert(f.size() == g.size());\n    superset_zeta_transform(f);\n    superset_zeta_transform(g);\n\
    \    for (size_t i = 0; i < f.size(); i++) f[i] *= g[i];\n    superset_mobius_transform(f);\n\
    \    return f;\n}\n\ntemplate <typename T> std::vector<T> or_convolution(std::vector<T>\
    \ f, std::vector<T> g) {\n    assert(f.size() == g.size());\n    subset_zeta_transform(f);\n\
    \    subset_zeta_transform(g);\n    for (size_t i = 0; i < f.size(); i++) f[i]\
    \ *= g[i];\n    subset_mobius_transform(f);\n    return f;\n}\n\ntemplate <typename\
    \ T> std::vector<T> xor_convolution(std::vector<T> f, std::vector<T> g) {\n  \
    \  assert(f.size() == g.size());\n    walsh_hadamard_transform(f);\n    walsh_hadamard_transform(g);\n\
    \    for (size_t i = 0; i < f.size(); i++) f[i] *= g[i];\n    walsh_hadamard_transform(f,\
    \ true);\n    return f;\n}\n}  // namespace set_function\n\n/**\n * @brief set\
    \ function (FZT, FMT, FWHT)\n * @docs docs/convolution/set_function.md\n */\n\
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
    \ * @docs docs/modulo/modint.md\n */\n#line 6 \"test/yosupo/bitwise_and_convolution.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int N;\n    cin >> N;\n    vector<mint> a(1 << N), b(1 << N);\n    for (int\
    \ i = 0; i < (1 << N); i++) cin >> a[i];\n    for (int i = 0; i < (1 << N); i++)\
    \ cin >> b[i];\n\n    vector<mint> c = set_function::and_convolution(a, b);\n\
    \    for (int i = 0; i < (1 << N); i++) cout << c[i] << (i + 1 == (1 << N) ? '\\\
    n' : ' ');\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_and_convolution\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../convolution/set_function.hpp\"\
    \n#include \"../../modulo/modint.hpp\"\n\nusing mint = modint<998244353>;\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N;\n\
    \    cin >> N;\n    vector<mint> a(1 << N), b(1 << N);\n    for (int i = 0; i\
    \ < (1 << N); i++) cin >> a[i];\n    for (int i = 0; i < (1 << N); i++) cin >>\
    \ b[i];\n\n    vector<mint> c = set_function::and_convolution(a, b);\n    for\
    \ (int i = 0; i < (1 << N); i++) cout << c[i] << (i + 1 == (1 << N) ? '\\n' :\
    \ ' ');\n    return 0;\n}"
  dependsOn:
  - base.hpp
  - convolution/set_function.hpp
  - modulo/modint.hpp
  isVerificationFile: true
  path: test/yosupo/bitwise_and_convolution.test.cpp
  requiredBy: []
  timestamp: '2021-09-27 13:41:22+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bitwise_and_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bitwise_and_convolution.test.cpp
- /verify/test/yosupo/bitwise_and_convolution.test.cpp.html
title: test/yosupo/bitwise_and_convolution.test.cpp
---
