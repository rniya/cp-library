---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':x:'
    path: convolution/ArbitaryModConvolution.hpp
    title: "Arbirary Mod Convolution (\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)"
  - icon: ':question:'
    path: convolution/NumberTheoreticTransform.hpp
    title: Number Theoretic Transform
  - icon: ':question:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod_1000000007
    links:
    - https://judge.yosupo.jp/problem/convolution_mod_1000000007
  bundledCode: "#line 1 \"test/yosupo/convolution_mod_1000000007.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\n\n#line\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 5 \"modulo/modint.hpp\"\
    \n\ntemplate <uint64_t Modulus> class modint {\n    using i64 = int64_t;\n   \
    \ using u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static_assert(Modulus\
    \ < static_cast<uint32_t>(1) << 31, \"Modulus must be less than 2**31\");\n  \
    \  static constexpr u32 mod = Modulus;\n    u32 v;\n\npublic:\n    constexpr modint(const\
    \ i64 x = 0) noexcept : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}\n \
    \   constexpr u32& value() noexcept { return v; }\n    constexpr const u32& value()\
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
    \ modint pow(u64 exp) const noexcept {\n        assert(0 <= exp);\n        modint\
    \ self(*this), res(1);\n        while (exp > 0) {\n            if (exp & 1) res\
    \ *= self;\n            self *= self;\n            exp >>= 1;\n        }\n   \
    \     return res;\n    }\n    constexpr modint inv() const noexcept {\n      \
    \  assert(*this != 0);\n        return pow(mod - 2);\n    }\n    constexpr modint&\
    \ operator++() noexcept {\n        if (++v == mod) v = 0;\n        return *this;\n\
    \    }\n    constexpr modint& operator--() noexcept {\n        if (v == 0) v =\
    \ mod;\n        return --v, *this;\n    }\n    constexpr modint operator++(int)\
    \ noexcept {\n        modint t = *this;\n        return ++*this, t;\n    }\n \
    \   constexpr modint operator--(int) noexcept {\n        modint t = *this;\n \
    \       return --*this, t;\n    }\n    constexpr modint operator-() const noexcept\
    \ { return modint(mod - v); }\n    template <class T> friend constexpr modint\
    \ operator+(T x, modint y) noexcept { return modint(x) + y; }\n    template <class\
    \ T> friend constexpr modint operator-(T x, modint y) noexcept { return modint(x)\
    \ - y; }\n    template <class T> friend constexpr modint operator*(T x, modint\
    \ y) noexcept { return modint(x) * y; }\n    template <class T> friend constexpr\
    \ modint operator/(T x, modint y) noexcept { return modint(x) / y; }\n    constexpr\
    \ bool operator==(const modint& rhs) const noexcept { return v == rhs.v; }\n \
    \   constexpr bool operator!=(const modint& rhs) const noexcept { return v !=\
    \ rhs.v; }\n    constexpr bool operator!() const noexcept { return !v; }\n   \
    \ friend std::istream& operator>>(std::istream& s, modint& rhs) noexcept {\n \
    \       i64 v;\n        rhs = modint{(s >> v, v)};\n        return s;\n    }\n\
    \    friend std::ostream& operator<<(std::ostream& s, const modint& rhs) noexcept\
    \ { return s << rhs.v; }\n};\n\n/**\n * @brief modint\n * @docs docs/modulo/modint.md\n\
    \ */\n#line 4 \"convolution/NumberTheoreticTransform.hpp\"\n\n/**\n * @brief Number\
    \ Theoretic Transform\n * @docs docs/convolution/NumberTheoreticTransform.md\n\
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
    \    }\n};\n#line 5 \"convolution/ArbitaryModConvolution.hpp\"\n\n/**\n * @brief\
    \ Arbirary Mod Convolution (\u4EFB\u610Fmod\u7573\u307F\u8FBC\u307F)\n * @docs\
    \ docs/convolution/ArbitaryModConvolution.md\n */\ntemplate <typename M> vector<M>\
    \ ArbitaryModConvolution(const vector<M>& a, const vector<M>& b) {\n    int n\
    \ = a.size(), m = b.size();\n    static constexpr int mod0 = 167772161, mod1 =\
    \ 469762049, mod2 = 754974721;\n    using mint0 = modint<mod0>;\n    using mint1\
    \ = modint<mod1>;\n    using mint2 = modint<mod2>;\n    NumberTheoreticTransform<mod0>\
    \ ntt0;\n    NumberTheoreticTransform<mod1> ntt1;\n    NumberTheoreticTransform<mod2>\
    \ ntt2;\n    vector<mint0> a0(n), b0(m);\n    vector<mint1> a1(n), b1(m);\n  \
    \  vector<mint2> a2(n), b2(m);\n    for (int i = 0; i < n; i++) a0[i] = a[i].value(),\
    \ a1[i] = a[i].value(), a2[i] = a[i].value();\n    for (int i = 0; i < m; i++)\
    \ b0[i] = b[i].value(), b1[i] = b[i].value(), b2[i] = b[i].value();\n    auto\
    \ c0 = ntt0.multiply(a0, b0);\n    auto c1 = ntt1.multiply(a1, b1);\n    auto\
    \ c2 = ntt2.multiply(a2, b2);\n    static const mint1 inv0 = (mint1)1 / mod0;\n\
    \    static const mint2 inv1 = (mint2)1 / mod1, inv0inv1 = inv1 / mod0;\n    static\
    \ const M m0 = mod0, m0m1 = m0 * mod1;\n    vector<M> res(n + m - 1);\n    for\
    \ (int i = 0; i < n + m - 1; i++) {\n        int v0 = c0[i].v;\n        int v1\
    \ = (inv0 * (c1[i] - v0)).v;\n        int v2 = (inv0inv1 * (c2[i] - v0) - inv1\
    \ * v1).v;\n        res[i] = v0 + m0 * v1 + m0m1 * v2;\n    }\n    return res;\n\
    }\n#line 5 \"test/yosupo/convolution_mod_1000000007.test.cpp\"\n\nusing mint =\
    \ modint<1000000007>;\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int N, M;\n    cin >> N >> M;\n    vector<mint> a(N), b(M);\n    for (int\
    \ i = 0; i < N; i++) cin >> a[i];\n    for (int i = 0; i < M; i++) cin >> b[i];\n\
    \n    vector<mint> c = ArbitaryModConvolution(a, b);\n    for (int i = 0; i <\
    \ N + M - 1; i++) cout << c[i] << (i == N + M - 2 ? '\\n' : ' ');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod_1000000007\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../convolution/ArbitaryModConvolution.hpp\"\
    \n\nusing mint = modint<1000000007>;\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int N, M;\n    cin >> N >> M;\n    vector<mint> a(N), b(M);\n    for (int\
    \ i = 0; i < N; i++) cin >> a[i];\n    for (int i = 0; i < M; i++) cin >> b[i];\n\
    \n    vector<mint> c = ArbitaryModConvolution(a, b);\n    for (int i = 0; i <\
    \ N + M - 1; i++) cout << c[i] << (i == N + M - 2 ? '\\n' : ' ');\n}"
  dependsOn:
  - base.hpp
  - convolution/ArbitaryModConvolution.hpp
  - modulo/modint.hpp
  - convolution/NumberTheoreticTransform.hpp
  isVerificationFile: true
  path: test/yosupo/convolution_mod_1000000007.test.cpp
  requiredBy: []
  timestamp: '2021-09-21 16:26:52+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/convolution_mod_1000000007.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/convolution_mod_1000000007.test.cpp
- /verify/test/yosupo/convolution_mod_1000000007.test.cpp.html
title: test/yosupo/convolution_mod_1000000007.test.cpp
---
