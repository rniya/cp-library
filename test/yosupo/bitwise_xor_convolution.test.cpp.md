---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/XORconvolution.hpp
    title: "\u6DFB\u5B57XOR\u7573\u307F\u8FBC\u307F"
  - icon: ':question:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bitwise_xor_convolution
    links:
    - https://judge.yosupo.jp/problem/bitwise_xor_convolution
  bundledCode: "#line 1 \"test/yosupo/bitwise_xor_convolution.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\n\n#line\
    \ 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\ntypedef long\
    \ long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\ntypedef unsigned\
    \ long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename\
    \ T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x : v) is >>\
    \ x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream& os,\
    \ const vector<T>& v) {\n    for (int i = 0; i < v.size(); i++) {\n        os\
    \ << v[i] << (i + 1 == v.size() ? \"\" : \" \");\n    }\n    return os;\n}\ntemplate\
    \ <typename T, typename U> ostream& operator<<(ostream& os, const pair<T, U>&\
    \ p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return os;\n\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"convolution/XORconvolution.hpp\"\
    \n\n/**\n * @brief \u6DFB\u5B57XOR\u7573\u307F\u8FBC\u307F\n * @docs docs/convolution/XORconvolution.md\n\
    \ */\ntemplate <typename T> void fwt(vector<T>& f) {\n    int n = f.size();\n\
    \    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0; j < n; j++) {\n\
    \            if (!(j & i)) {\n                T x = f[j], y = f[j | i];\n    \
    \            f[j] = x + y;\n                f[j | i] = x - y;\n            }\n\
    \        }\n    }\n}\n\ntemplate <typename T> void ifwt(vector<T>& f) {\n    int\
    \ n = f.size();\n    for (int i = 1; i < n; i <<= 1) {\n        for (int j = 0;\
    \ j < n; j++) {\n            if (!(j & i)) {\n                T x = f[j], y =\
    \ f[j | i];\n                f[j] = (x + y) / 2;\n                f[j | i] = (x\
    \ - y) / 2;\n            }\n        }\n    }\n}\n\ntemplate <typename T> vector<T>\
    \ XOR_convolution(vector<T> A, vector<T> B) {\n    int n = A.size();\n    assert(__builtin_popcount(n)\
    \ == 1);\n    assert(A.size() == B.size());\n    fwt(A);\n    fwt(B);\n    for\
    \ (int i = 0; i < n; i++) A[i] *= B[i];\n    ifwt(A);\n    return A;\n}\n#line\
    \ 3 \"modulo/modint.hpp\"\n\n/**\n * @brief modint\n * @docs docs/modulo/modint.md\n\
    \ */\ntemplate <uint32_t mod> class modint {\n    using i64 = int64_t;\n    using\
    \ u32 = uint32_t;\n    using u64 = uint64_t;\n\npublic:\n    u32 v;\n    constexpr\
    \ modint(const i64 x = 0) noexcept : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x\
    \ % mod) {}\n    constexpr u32& value() noexcept { return v; }\n    constexpr\
    \ const u32& value() const noexcept { return v; }\n    constexpr modint operator+(const\
    \ modint& rhs) const noexcept { return modint(*this) += rhs; }\n    constexpr\
    \ modint operator-(const modint& rhs) const noexcept { return modint(*this) -=\
    \ rhs; }\n    constexpr modint operator*(const modint& rhs) const noexcept { return\
    \ modint(*this) *= rhs; }\n    constexpr modint operator/(const modint& rhs) const\
    \ noexcept { return modint(*this) /= rhs; }\n    constexpr modint& operator+=(const\
    \ modint& rhs) noexcept {\n        v += rhs.v;\n        if (v >= mod) v -= mod;\n\
    \        return *this;\n    }\n    constexpr modint& operator-=(const modint&\
    \ rhs) noexcept {\n        if (v < rhs.v) v += mod;\n        v -= rhs.v;\n   \
    \     return *this;\n    }\n    constexpr modint& operator*=(const modint& rhs)\
    \ noexcept {\n        v = (u64)v * rhs.v % mod;\n        return *this;\n    }\n\
    \    constexpr modint& operator/=(const modint& rhs) noexcept { return *this *=\
    \ rhs.pow(mod - 2); }\n    constexpr modint pow(u64 exp) const noexcept {\n  \
    \      modint self(*this), res(1);\n        while (exp > 0) {\n            if\
    \ (exp & 1) res *= self;\n            self *= self;\n            exp >>= 1;\n\
    \        }\n        return res;\n    }\n    constexpr modint& operator++() noexcept\
    \ {\n        if (++v == mod) v = 0;\n        return *this;\n    }\n    constexpr\
    \ modint& operator--() noexcept {\n        if (v == 0) v = mod;\n        return\
    \ --v, *this;\n    }\n    constexpr modint operator++(int) noexcept {\n      \
    \  modint t = *this;\n        return ++*this, t;\n    }\n    constexpr modint\
    \ operator--(int) noexcept {\n        modint t = *this;\n        return --*this,\
    \ t;\n    }\n    constexpr modint operator-() const noexcept { return modint(mod\
    \ - v); }\n    template <class T> friend constexpr modint operator+(T x, modint\
    \ y) noexcept { return modint(x) + y; }\n    template <class T> friend constexpr\
    \ modint operator-(T x, modint y) noexcept { return modint(x) - y; }\n    template\
    \ <class T> friend constexpr modint operator*(T x, modint y) noexcept { return\
    \ modint(x) * y; }\n    template <class T> friend constexpr modint operator/(T\
    \ x, modint y) noexcept { return modint(x) / y; }\n    constexpr bool operator==(const\
    \ modint& rhs) const noexcept { return v == rhs.v; }\n    constexpr bool operator!=(const\
    \ modint& rhs) const noexcept { return v != rhs.v; }\n    constexpr bool operator!()\
    \ const noexcept { return !v; }\n    friend istream& operator>>(istream& s, modint&\
    \ rhs) noexcept {\n        i64 v;\n        rhs = modint{(s >> v, v)};\n      \
    \  return s;\n    }\n    friend ostream& operator<<(ostream& s, const modint&\
    \ rhs) noexcept { return s << rhs.v; }\n};\n#line 6 \"test/yosupo/bitwise_xor_convolution.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int N;\n    cin >> N;\n    vector<mint> a(1 << N), b(1 << N);\n    for (int\
    \ i = 0; i < (1 << N); i++) cin >> a[i];\n    for (int i = 0; i < (1 << N); i++)\
    \ cin >> b[i];\n\n    vector<mint> c = XOR_convolution(a, b);\n    for (int i\
    \ = 0; i < (1 << N); i++) cout << c[i] << (i + 1 == (1 << N) ? '\\n' : ' ');\n\
    }\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bitwise_xor_convolution\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../convolution/XORconvolution.hpp\"\
    \n#include \"../../modulo/modint.hpp\"\n\nusing mint = modint<998244353>;\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N;\n\
    \    cin >> N;\n    vector<mint> a(1 << N), b(1 << N);\n    for (int i = 0; i\
    \ < (1 << N); i++) cin >> a[i];\n    for (int i = 0; i < (1 << N); i++) cin >>\
    \ b[i];\n\n    vector<mint> c = XOR_convolution(a, b);\n    for (int i = 0; i\
    \ < (1 << N); i++) cout << c[i] << (i + 1 == (1 << N) ? '\\n' : ' ');\n}"
  dependsOn:
  - base.hpp
  - convolution/XORconvolution.hpp
  - modulo/modint.hpp
  isVerificationFile: true
  path: test/yosupo/bitwise_xor_convolution.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 11:11:13+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bitwise_xor_convolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bitwise_xor_convolution.test.cpp
- /verify/test/yosupo/bitwise_xor_convolution.test.cpp.html
title: test/yosupo/bitwise_xor_convolution.test.cpp
---
