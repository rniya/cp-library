---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: convolution/NumberTheoreticTransform.hpp
    title: Number Theoretic Transform
  - icon: ':question:'
    path: modulo/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: polynomial/FormalPowerSeries.hpp
    title: Formal Power Series
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/inv_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/inv_of_formal_power_series
  bundledCode: "#line 1 \"test/yosupo/inv_of_formal_power_series.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\n\n#line\
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
    \    }\n};\n#line 3 \"polynomial/FormalPowerSeries.hpp\"\n\n/**\n * @brief Formal\
    \ Power Series\n * @docs docs/polynomial/FormalPowerSeries.md\n */\ntemplate <typename\
    \ M> struct FormalPowerSeries : vector<M> {\n    using vector<M>::vector;\n  \
    \  using Poly = FormalPowerSeries;\n    using MUL = function<Poly(Poly, Poly)>;\n\
    \    static MUL& get_mul() {\n        static MUL mul = nullptr;\n        return\
    \ mul;\n    }\n    static void set_mul(MUL f) { get_mul() = f; }\n    void shrink()\
    \ {\n        while (this->size() && this->back() == M(0)) this->pop_back();\n\
    \    }\n    Poly pre(int deg) const { return Poly(this->begin(), this->begin()\
    \ + min((int)this->size(), deg)); }\n    Poly operator+(const M& v) const { return\
    \ Poly(*this) += v; }\n    Poly operator+(const Poly& p) const { return Poly(*this)\
    \ += p; }\n    Poly operator-(const M& v) const { return Poly(*this) -= v; }\n\
    \    Poly operator-(const Poly& p) const { return Poly(*this) -= p; }\n    Poly\
    \ operator*(const M& v) const { return Poly(*this) *= v; }\n    Poly operator*(const\
    \ Poly& p) const { return Poly(*this) *= p; }\n    Poly operator/(const Poly&\
    \ p) const { return Poly(*this) /= p; }\n    Poly operator%(const Poly& p) const\
    \ { return Poly(*this) %= p; }\n    Poly& operator+=(const M& v) {\n        if\
    \ (this->empty()) this->resize(1);\n        (*this)[0] += v;\n        return *this;\n\
    \    }\n    Poly& operator+=(const Poly& p) {\n        if (p.size() > this->size())\
    \ this->resize(p.size());\n        for (int i = 0; i < (int)p.size(); i++) (*this)[i]\
    \ += p[i];\n        return *this;\n    }\n    Poly& operator-=(const M& v) {\n\
    \        if (this->empty()) this->resize(1);\n        (*this)[0] -= v;\n     \
    \   return *this;\n    }\n    Poly& operator-=(const Poly& p) {\n        if (p.size()\
    \ > this->size()) this->resize(p.size());\n        for (int i = 0; i < (int)p.size();\
    \ i++) (*this)[i] -= p[i];\n        return *this;\n    }\n    Poly& operator*=(const\
    \ M& v) {\n        for (int i = 0; i < (int)this->size(); i++) (*this)[i] *= v;\n\
    \        return *this;\n    }\n    Poly& operator*=(const Poly& p) {\n       \
    \ if (this->empty() || p.empty()) {\n            this->clear();\n            return\
    \ *this;\n        }\n        assert(get_mul() != nullptr);\n        return *this\
    \ = get_mul()(*this, p);\n    }\n    Poly& operator/=(const Poly& p) {\n     \
    \   if (this->size() < p.size()) {\n            this->clear();\n            return\
    \ *this;\n        }\n        int n = this->size() - p.size() - 1;\n        return\
    \ *this = (rev().pre(n) * p.rev().inv(n)).pre(n).rev(n);\n    }\n    Poly& operator%=(const\
    \ Poly& p) { return *this -= *this / p * p; }\n    Poly operator<<(const int deg)\
    \ {\n        Poly res(*this);\n        res.insert(res.begin(), deg, M(0));\n \
    \       return res;\n    }\n    Poly operator>>(const int deg) {\n        if (this->size()\
    \ <= deg) return {};\n        Poly res(*this);\n        res.erase(res.begin(),\
    \ res.begin() + deg);\n        return res;\n    }\n    Poly operator-() const\
    \ {\n        Poly res(this->size());\n        for (int i = 0; i < (int)this->size();\
    \ i++) res[i] = -(*this)[i];\n        return res;\n    }\n    Poly rev(int deg\
    \ = -1) const {\n        Poly res(*this);\n        if (~deg) res.resize(deg, M(0));\n\
    \        reverse(res.begin(), res.end());\n        return res;\n    }\n    Poly\
    \ diff() const {\n        Poly res(max(0, (int)this->size() - 1));\n        for\
    \ (int i = 1; i < (int)this->size(); i++) res[i - 1] = (*this)[i] * M(i);\n  \
    \      return res;\n    }\n    Poly integral() const {\n        Poly res(this->size()\
    \ + 1);\n        res[0] = M(0);\n        for (int i = 0; i < (int)this->size();\
    \ i++) res[i + 1] = (*this)[i] / M(i + 1);\n        return res;\n    }\n    Poly\
    \ inv(int deg = -1) const {\n        assert((*this)[0] != M(0));\n        if (deg\
    \ < 0) deg = this->size();\n        Poly res({M(1) / (*this)[0]});\n        for\
    \ (int i = 1; i < deg; i <<= 1) {\n            res = (res + res - res * res *\
    \ pre(i << 1)).pre(i << 1);\n        }\n        return res.pre(deg);\n    }\n\
    \    Poly log(int deg = -1) const {\n        assert((*this)[0] == M(1));\n   \
    \     if (deg < 0) deg = this->size();\n        return (this->diff() * this->inv(deg)).pre(deg\
    \ - 1).integral();\n    }\n    Poly sqrt(int deg = -1) const {\n        assert((*this)[0]\
    \ == M(1));\n        if (deg == -1) deg = this->size();\n        Poly res({M(1)});\n\
    \        M inv2 = M(1) / M(2);\n        for (int i = 1; i < deg; i <<= 1) {\n\
    \            res = (res + pre(i << 1) * res.inv(i << 1)) * inv2;\n        }\n\
    \        return res.pre(deg);\n    }\n    Poly exp(int deg = -1) {\n        assert((*this)[0]\
    \ == M(0));\n        if (deg < 0) deg = this->size();\n        Poly res({M(1)});\n\
    \        for (int i = 1; i < deg; i <<= 1) {\n            res = (res * (pre(i\
    \ << 1) + M(1) - res.log(i << 1))).pre(i << 1);\n        }\n        return res.pre(deg);\n\
    \    }\n    Poly pow(long long k, int deg = -1) const {\n        if (deg < 0)\
    \ deg = this->size();\n        for (int i = 0; i < (int)this->size(); i++) {\n\
    \            if ((*this)[i] == M(0)) continue;\n            if (k * i > deg) return\
    \ Poly(deg, M(0));\n            M inv = M(1) / (*this)[i];\n            Poly res\
    \ = (((*this * inv) >> i).log() * k).exp() * (*this)[i].pow(k);\n            res\
    \ = (res << (i * k)).pre(deg);\n            if ((int)res.size() < deg) res.resize(deg,\
    \ M(0));\n            return res;\n        }\n        return *this;\n    }\n \
    \   Poly pow_mod(long long k, const Poly& mod) const {\n        Poly x(*this),\
    \ res = {M(1)};\n        while (k > 0) {\n            if (k & 1) res = res * x\
    \ % mod;\n            x = x * x % mod;\n            k >>= 1;\n        }\n    \
    \    return res;\n    }\n    Poly linear_mul(const M& a, const M& b) {\n     \
    \   Poly res(this->size() + 1);\n        for (int i = 0; i < this->size() + 1;\
    \ i++) {\n            res[i] = (i - 1 >= 0 ? (*this)[i - 1] * a : M(0)) + (i <\
    \ (int)this->size() ? (*this)[i] * b : M(0));\n        }\n        return res;\n\
    \    }\n    Poly linear_div(const M& a, const M& b) {\n        Poly res(this->size()\
    \ - 1);\n        M inv_b = M(1) / b;\n        for (int i = 0; i + 1 < (int)this->size();\
    \ i++) {\n            res[i] = ((*this)[i] - (i - 1 >= 0 ? res[i - 1] * a : M(0)))\
    \ * inv_b;\n        }\n        return res;\n    }\n    Poly sparse_mul(const M&\
    \ c, const M& d) {\n        Poly res(*this);\n        res.resize(this->size()\
    \ + d, M(0));\n        for (int i = 0; i < (int)this->size(); i++) {\n       \
    \     res[i + d] += (*this)[i] * c;\n        }\n        return res;\n    }\n \
    \   Poly sparse_div(const M& c, const M& d) {\n        Poly res(*this);\n    \
    \    for (int i = 0; i < res.size() - d; i++) {\n            res[i + d] -= res[i]\
    \ * c;\n        }\n        return res;\n    }\n    M operator()(const M& x) const\
    \ {\n        M res = 0, power = 1;\n        for (int i = 0; i < (int)this->size();\
    \ i++, power *= x) {\n            res += (*this)[i] * power;\n        }\n    \
    \    return res;\n    }\n};\n#line 7 \"test/yosupo/inv_of_formal_power_series.test.cpp\"\
    \n\nusing mint = modint<998244353>;\nusing FPS = FormalPowerSeries<mint>;\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    NumberTheoreticTransform<998244353>\
    \ NTT;\n    auto mul = [&](const FPS::Poly& a, const FPS::Poly& b) {\n       \
    \ auto res = NTT.multiply(a, b);\n        return FPS::Poly(res.begin(), res.end());\n\
    \    };\n    FPS::set_mul(mul);\n\n    int N;\n    cin >> N;\n    FPS a(N);\n\
    \    for (int i = 0; i < N; i++) cin >> a[i];\n    FPS b = a.inv();\n    for (int\
    \ i = 0; i < N; i++) cout << b[i] << (i + 1 == N ? '\\n' : ' ');\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/inv_of_formal_power_series\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../convolution/NumberTheoreticTransform.hpp\"\
    \n#include \"../../modulo/modint.hpp\"\n#include \"../../polynomial/FormalPowerSeries.hpp\"\
    \n\nusing mint = modint<998244353>;\nusing FPS = FormalPowerSeries<mint>;\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    NumberTheoreticTransform<998244353>\
    \ NTT;\n    auto mul = [&](const FPS::Poly& a, const FPS::Poly& b) {\n       \
    \ auto res = NTT.multiply(a, b);\n        return FPS::Poly(res.begin(), res.end());\n\
    \    };\n    FPS::set_mul(mul);\n\n    int N;\n    cin >> N;\n    FPS a(N);\n\
    \    for (int i = 0; i < N; i++) cin >> a[i];\n    FPS b = a.inv();\n    for (int\
    \ i = 0; i < N; i++) cout << b[i] << (i + 1 == N ? '\\n' : ' ');\n}"
  dependsOn:
  - base.hpp
  - convolution/NumberTheoreticTransform.hpp
  - modulo/modint.hpp
  - polynomial/FormalPowerSeries.hpp
  isVerificationFile: true
  path: test/yosupo/inv_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2021-10-01 20:18:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/inv_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/inv_of_formal_power_series.test.cpp
- /verify/test/yosupo/inv_of_formal_power_series.test.cpp.html
title: test/yosupo/inv_of_formal_power_series.test.cpp
---
