---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':x:'
    path: combinatorics/combination.hpp
    title: combination
  - icon: ':x:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_C
  bundledCode: "#line 1 \"test/aoj/DPL_5_C.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_C\"\
    \n\n#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\ntypedef\
    \ long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\ntypedef\
    \ unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate <typename\
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
    \ return true;\n    }\n    return false;\n}\n#line 3 \"combinatorics/combination.hpp\"\
    \n\n/**\n * @brief combination\n * @docs docs/combinatorics/combination.md\n */\n\
    template <class M> struct Combination {\n    vector<M> _fac, _inv, _finv;\n  \
    \  Combination(int n) : _fac(n + 1), _inv(n + 1), _finv(n + 1) {\n        _fac[0]\
    \ = _finv[n] = _inv[0] = 1;\n        for (int i = 1; i <= n; i++) _fac[i] = _fac[i\
    \ - 1] * i;\n        _finv[n] /= _fac[n];\n        for (int i = n - 1; i >= 0;\
    \ i--) _finv[i] = _finv[i + 1] * (i + 1);\n        for (int i = 1; i <= n; i++)\
    \ _inv[i] = _finv[i] * _fac[i - 1];\n    }\n    M fac(int k) const { return _fac[k];\
    \ }\n    M finv(int k) const { return _finv[k]; }\n    M inv(int k) const { return\
    \ _inv[k]; }\n    M P(int n, int r) const {\n        if (n < 0 || r < 0 || n <\
    \ r) return 0;\n        return _fac[n] * _finv[n - r];\n    }\n    M C(int n,\
    \ int r) const {\n        if (n < 0 || r < 0 || n < r) return 0;\n        return\
    \ _fac[n] * _finv[r] * _finv[n - r];\n    }\n};\n#line 3 \"modulo/modint.hpp\"\
    \n\n/**\n * @brief modint\n * @docs docs/modulo/modint.md\n */\ntemplate <uint32_t\
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
    \ rhs) noexcept { return s << rhs.v; }\n};\n#line 6 \"test/aoj/DPL_5_C.test.cpp\"\
    \n\nusing mint = modint<1000000007>;\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    Combination<mint> COM(1010);\n    int n, k;\n    cin >> n >> k;\n\n    mint\
    \ ans = 0;\n    for (int i = 0; i < k; i++) {\n        mint add = COM.C(k, i)\
    \ * mint(k - i).pow(n);\n        if (i & 1)\n            ans -= add;\n       \
    \ else\n            ans += add;\n    }\n\n    cout << ans << '\\n';\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_C\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../combinatorics/combination.hpp\"\
    \n#include \"../../modulo/modint.hpp\"\n\nusing mint = modint<1000000007>;\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    Combination<mint>\
    \ COM(1010);\n    int n, k;\n    cin >> n >> k;\n\n    mint ans = 0;\n    for\
    \ (int i = 0; i < k; i++) {\n        mint add = COM.C(k, i) * mint(k - i).pow(n);\n\
    \        if (i & 1)\n            ans -= add;\n        else\n            ans +=\
    \ add;\n    }\n\n    cout << ans << '\\n';\n}"
  dependsOn:
  - base.hpp
  - combinatorics/combination.hpp
  - modulo/modint.hpp
  isVerificationFile: true
  path: test/aoj/DPL_5_C.test.cpp
  requiredBy: []
  timestamp: '2021-01-20 11:24:35+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DPL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_C.test.cpp
- /verify/test/aoj/DPL_5_C.test.cpp.html
title: test/aoj/DPL_5_C.test.cpp
---