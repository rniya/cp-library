---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/NumberTheoreticTransform.hpp
    title: Number Theoretic Transform
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
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
  bundledCode: "#line 1 \"test/yosupo/convolution_mod.test.cpp\"\n#define PROBLEM\
    \ \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#line 2 \"base.hpp\"\n\
    #include <bits/stdc++.h>\nusing namespace std;\ntypedef long long ll;\ntypedef\
    \ __int128_t i128;\ntypedef unsigned int uint;\ntypedef unsigned long long ull;\n\
    #define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename T> istream& operator>>(istream&\
    \ is, vector<T>& v) {\n    for (T& x : v) is >> x;\n    return is;\n}\ntemplate\
    \ <typename T> ostream& operator<<(ostream& os, const vector<T>& v) {\n    for\
    \ (int i = 0; i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size()\
    \ ? \"\" : \" \");\n    }\n    return os;\n}\ntemplate <typename T, typename U>\
    \ ostream& operator<<(ostream& os, const pair<T, U>& p) {\n    os << '(' << p.first\
    \ << ',' << p.second << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U, typename V> ostream& operator<<(ostream& os, const tuple<T, U, V>& t) {\n\
    \    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ')';\n\
    \    return os;\n}\ntemplate <typename T, typename U, typename V, typename W>\
    \ ostream& operator<<(ostream& os, const tuple<T, U, V, W>& t) {\n    os << '('\
    \ << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t) << ',' << get<3>(t) <<\
    \ ')';\n    return os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream&\
    \ os, const map<T, U>& m) {\n    os << '{';\n    for (auto itr = m.begin(); itr\
    \ != m.end();) {\n        os << '(' << itr->first << ',' << itr->second << ')';\n\
    \        if (++itr != m.end()) os << ',';\n    }\n    os << '}';\n    return os;\n\
    }\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const unordered_map<T,\
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
    \ os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\ntemplate <class Head, class...\
    \ Tail> void debug_out(Head&& head, Tail&&... tail) {\n    cerr << head;\n   \
    \ if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n}\n\
    #ifdef LOCAL\n#define debug(...)                                             \
    \                      \\\n    cerr << \" \";                                \
    \                                     \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) 42\n#endif\n\ntemplate <typename\
    \ T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename\
    \ T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class\
    \ T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n   \
    \     return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2>\
    \ inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\n#line 3 \"modulo/modint.hpp\"\n\n\
    /**\n * @brief modint\n * @docs docs/modulo/modint.md\n */\ntemplate <uint32_t\
    \ mod> class modint {\n    using i64 = int64_t;\n    using u32 = uint32_t;\n \
    \   using u64 = uint64_t;\n\npublic:\n    u32 v;\n    constexpr modint(const i64\
    \ x = 0) noexcept : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}\n    constexpr\
    \ u32& value() noexcept { return v; }\n    constexpr const u32& value() const\
    \ noexcept { return v; }\n    constexpr modint operator+(const modint& rhs) const\
    \ noexcept { return modint(*this) += rhs; }\n    constexpr modint operator-(const\
    \ modint& rhs) const noexcept { return modint(*this) -= rhs; }\n    constexpr\
    \ modint operator*(const modint& rhs) const noexcept { return modint(*this) *=\
    \ rhs; }\n    constexpr modint operator/(const modint& rhs) const noexcept { return\
    \ modint(*this) /= rhs; }\n    constexpr modint& operator+=(const modint& rhs)\
    \ noexcept {\n        v += rhs.v;\n        if (v >= mod) v -= mod;\n        return\
    \ *this;\n    }\n    constexpr modint& operator-=(const modint& rhs) noexcept\
    \ {\n        if (v < rhs.v) v += mod;\n        v -= rhs.v;\n        return *this;\n\
    \    }\n    constexpr modint& operator*=(const modint& rhs) noexcept {\n     \
    \   v = (u64)v * rhs.v % mod;\n        return *this;\n    }\n    constexpr modint&\
    \ operator/=(const modint& rhs) noexcept { return *this *= rhs.pow(mod - 2); }\n\
    \    constexpr modint pow(u64 exp) const noexcept {\n        modint self(*this),\
    \ res(1);\n        while (exp > 0) {\n            if (exp & 1) res *= self;\n\
    \            self *= self;\n            exp >>= 1;\n        }\n        return\
    \ res;\n    }\n    constexpr modint& operator++() noexcept {\n        if (++v\
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
    \ noexcept { return !v; }\n    friend istream& operator>>(istream& s, modint&\
    \ rhs) noexcept {\n        i64 v;\n        rhs = modint{(s >> v, v)};\n      \
    \  return s;\n    }\n    friend ostream& operator<<(ostream& s, const modint&\
    \ rhs) noexcept { return s << rhs.v; }\n};\n#line 4 \"convolution/NumberTheoreticTransform.hpp\"\
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
    \    }\n};\n#line 6 \"test/yosupo/convolution_mod.test.cpp\"\n\nusing mint = modint<998244353>;\n\
    \nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,\
    \ M;\n    cin >> N >> M;\n    vector<mint> a(N), b(M);\n    for (int i = 0; i\
    \ < N; i++) cin >> a[i];\n    for (int i = 0; i < M; i++) cin >> b[i];\n\n   \
    \ NumberTheoreticTransform<998244353> NTT;\n    vector<mint> c = NTT.multiply(a,\
    \ b);\n\n    for (int i = 0; i < N + M - 1; i++) cout << c[i] << (i == N + M -\
    \ 2 ? '\\n' : ' ');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ \"../../base.hpp\"\n#include \"../../convolution/NumberTheoreticTransform.hpp\"\
    \n#include \"../../modulo/modint.hpp\"\n\nusing mint = modint<998244353>;\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N, M;\n\
    \    cin >> N >> M;\n    vector<mint> a(N), b(M);\n    for (int i = 0; i < N;\
    \ i++) cin >> a[i];\n    for (int i = 0; i < M; i++) cin >> b[i];\n\n    NumberTheoreticTransform<998244353>\
    \ NTT;\n    vector<mint> c = NTT.multiply(a, b);\n\n    for (int i = 0; i < N\
    \ + M - 1; i++) cout << c[i] << (i == N + M - 2 ? '\\n' : ' ');\n}"
  dependsOn:
  - base.hpp
  - convolution/NumberTheoreticTransform.hpp
  - modulo/modint.hpp
  isVerificationFile: true
  path: test/yosupo/convolution_mod.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/convolution_mod.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/convolution_mod.test.cpp
- /verify/test/yosupo/convolution_mod.test.cpp.html
title: test/yosupo/convolution_mod.test.cpp
---
