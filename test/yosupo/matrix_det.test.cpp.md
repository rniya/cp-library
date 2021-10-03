---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: linearalgebra/Matrix.hpp
    title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
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
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
  bundledCode: "#line 1 \"test/yosupo/matrix_det.test.cpp\"\n#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\
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
    \ true;\n    }\n    return false;\n}\n#pragma endregion\n#line 5 \"linearalgebra/Matrix.hpp\"\
    \n\ntemplate <typename T> struct Matrix {\n    std::vector<std::vector<T>> A;\n\
    \n    Matrix(size_t n, size_t m) : A(n, std::vector<T>(m, 0)) {}\n\n    Matrix(size_t\
    \ n) : A(n, std::vector<T>(n, 0)) {}\n\n    size_t size() const { return A.size();\
    \ }\n\n    size_t height() const { return A.size(); }\n\n    size_t width() const\
    \ { return A[0].size(); }\n\n    inline const std::vector<T>& operator[](int k)\
    \ const { return A[k]; }\n\n    inline std::vector<T>& operator[](int k) { return\
    \ A[k]; }\n\n    static Matrix I(size_t n) {\n        Matrix res(n);\n       \
    \ for (size_t i = 0; i < n; i++) res[i][i] = 1;\n        return res;\n    }\n\n\
    \    Matrix& operator+=(const Matrix& B) {\n        size_t n = height(), m = width();\n\
    \        assert(n == B.height() && m == B.width());\n        for (size_t i = 0;\
    \ i < n; i++) {\n            for (size_t j = 0; j < m; j++) {\n              \
    \  (*this)[i][j] += B[i][j];\n            }\n        }\n        return *this;\n\
    \    }\n\n    Matrix& operator-=(const Matrix& B) {\n        size_t n = height(),\
    \ m = width();\n        assert(n == B.height() && m == B.width());\n        for\
    \ (size_t i = 0; i < n; i++) {\n            for (size_t j = 0; j < m; j++) {\n\
    \                (*this)[i][j] -= B[i][j];\n            }\n        }\n       \
    \ return *this;\n    }\n\n    Matrix& operator*=(const Matrix& B) {\n        size_t\
    \ n = height(), m = B.width(), p = width();\n        assert(p == B.height());\n\
    \        std::vector<std::vector<T>> C(n, std::vector<T>(m, 0));\n        for\
    \ (size_t i = 0; i < n; i++) {\n            for (size_t k = 0; k < p; k++) {\n\
    \                for (size_t j = 0; j < m; j++) {\n                    C[i][j]\
    \ += (*this)[i][k] * B[k][j];\n                }\n            }\n        }\n \
    \       A.swap(C);\n        return *this;\n    }\n\n    Matrix& operator*=(const\
    \ T& v) {\n        for (size_t i = 0; i < height(); i++) {\n            for (size_t\
    \ j = 0; j < width(); j++) {\n                (*this)[i][j] *= v;\n          \
    \  }\n        }\n        return *this;\n    }\n\n    Matrix& operator/=(const\
    \ T& v) {\n        T inv = T(1) / v;\n        for (size_t i = 0; i < height();\
    \ i++) {\n            for (size_t j = 0; j < width(); j++) {\n               \
    \ (*this)[i][j] *= inv;\n            }\n        }\n        return *this;\n   \
    \ }\n\n    Matrix& operator^=(long long k) {\n        assert(0 <= k);\n      \
    \  Matrix B = Matrix::I(size());\n        while (k > 0) {\n            if (k &\
    \ 1) B *= *this;\n            *this *= *this;\n            k >>= 1;\n        }\n\
    \        A.swap(B.A);\n        return *this;\n    }\n\n    Matrix operator-()\
    \ const {\n        Matrix res(height(), width());\n        for (size_t i = 0;\
    \ i < height(); i++) {\n            for (size_t j = 0; j < width(); j++) {\n \
    \               res[i][j] = -(*this)[i][j];\n            }\n        }\n      \
    \  return res;\n    }\n\n    Matrix operator+(const Matrix& B) const { return\
    \ Matrix(*this) += B; }\n\n    Matrix operator-(const Matrix& B) const { return\
    \ Matrix(*this) -= B; }\n\n    Matrix operator*(const Matrix& B) const { return\
    \ Matrix(*this) *= B; }\n\n    Matrix operator*(const T& v) const { return Matrix(*this)\
    \ *= v; }\n\n    Matrix operator/(const T& v) const { return Matrix(*this) /=\
    \ v; }\n\n    Matrix operator^(const long long k) const { return Matrix(*this)\
    \ ^= k; }\n\n    bool operator==(const Matrix& B) const {\n        assert(height()\
    \ == B.height() && width() == B.width());\n        return A == B.A;\n    }\n\n\
    \    bool operator!=(const Matrix& B) const {\n        assert(height() == B.height()\
    \ && width() == B.width());\n        return A != B.A;\n    }\n\n    Matrix transpose()\
    \ const {\n        Matrix res(width(), height());\n        for (size_t i = 0;\
    \ i < height(); i++) {\n            for (size_t j = 0; j < width(); j++) {\n \
    \               res[j][i] = (*this)[i][j];\n            }\n        }\n       \
    \ return res;\n    }\n\n    T determinant() const {\n        assert(height() ==\
    \ width());\n        Matrix B(*this);\n        T res = 1;\n        for (size_t\
    \ i = 0; i < height(); i++) {\n            int pivot = -1;\n            for (size_t\
    \ j = i; j < height(); j++) {\n                if (B[j][i] != 0) {\n         \
    \           pivot = j;\n                    break;\n                }\n      \
    \      }\n            if (pivot == -1) return 0;\n            if (pivot != (int)i)\
    \ {\n                res *= -1;\n                std::swap(B[i], B[pivot]);\n\
    \            }\n            res *= B[i][i];\n            T inv = T(1) / B[i][i];\n\
    \            for (size_t j = 0; j < width(); j++) B[i][j] *= inv;\n          \
    \  for (size_t j = i + 1; j < height(); j++) {\n                T a = B[j][i];\n\
    \                for (size_t k = 0; k < width(); k++) {\n                    B[j][k]\
    \ -= B[i][k] * a;\n                }\n            }\n        }\n        return\
    \ res;\n    }\n\n    friend std::ostream& operator<<(std::ostream& os, const Matrix&\
    \ p) {\n        size_t n = p.height(), m = p.width();\n        os << \"[(\" <<\
    \ n << \" * \" << m << \" Matrix)\";\n        os << \"\\n[columun sums: \";\n\
    \        for (size_t j = 0; j < m; j++) {\n            T sum = 0;\n          \
    \  for (size_t i = 0; i < n; i++) sum += p[i][j];\n            ;\n           \
    \ os << sum << (j + 1 < m ? \",\" : \"\");\n        }\n        os << \"]\";\n\
    \        for (size_t i = 0; i < n; i++) {\n            os << \"\\n[\";\n     \
    \       for (size_t j = 0; j < m; j++) os << p[i][j] << (j + 1 < m ? \",\" : \"\
    \");\n            os << \"]\";\n        }\n        os << \"]\\n\";\n        return\
    \ os;\n    }\n};\n\n/**\n * @brief \u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA\n\
    \ * @docs docs/linearalgebra/Matrix.md\n */\n#line 5 \"modulo/modint.hpp\"\n\n\
    template <uint64_t Modulus> class modint {\n    using i64 = int64_t;\n    using\
    \ u32 = uint32_t;\n    using u64 = uint64_t;\n\n    static_assert(Modulus < static_cast<uint32_t>(1)\
    \ << 31, \"Modulus must be less than 2**31\");\n    static constexpr u32 mod =\
    \ Modulus;\n    u32 v;\n\npublic:\n    constexpr modint(const i64 x = 0) noexcept\
    \ : v(x < 0 ? mod - 1 - (-(x + 1) % mod) : x % mod) {}\n    constexpr u32& val()\
    \ noexcept { return v; }\n    constexpr const u32& val() const noexcept { return\
    \ v; }\n    constexpr modint operator+(const modint& rhs) const noexcept { return\
    \ modint(*this) += rhs; }\n    constexpr modint operator-(const modint& rhs) const\
    \ noexcept { return modint(*this) -= rhs; }\n    constexpr modint operator*(const\
    \ modint& rhs) const noexcept { return modint(*this) *= rhs; }\n    constexpr\
    \ modint operator/(const modint& rhs) const noexcept { return modint(*this) /=\
    \ rhs; }\n    constexpr modint& operator+=(const modint& rhs) noexcept {\n   \
    \     v += rhs.v;\n        if (v >= mod) v -= mod;\n        return *this;\n  \
    \  }\n    constexpr modint& operator-=(const modint& rhs) noexcept {\n       \
    \ if (v < rhs.v) v += mod;\n        v -= rhs.v;\n        return *this;\n    }\n\
    \    constexpr modint& operator*=(const modint& rhs) noexcept {\n        v = (u64)v\
    \ * rhs.v % mod;\n        return *this;\n    }\n    constexpr modint& operator/=(const\
    \ modint& rhs) noexcept { return *this *= rhs.inv(); }\n    constexpr modint pow(long\
    \ long n) const noexcept {\n        assert(0 <= n);\n        modint self(*this),\
    \ res(1);\n        while (n > 0) {\n            if (n & 1) res *= self;\n    \
    \        self *= self;\n            n >>= 1;\n        }\n        return res;\n\
    \    }\n    constexpr modint inv() const noexcept {\n        assert(*this != 0);\n\
    \        return pow(mod - 2);\n    }\n    constexpr modint& operator++() noexcept\
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
    \ const noexcept { return !v; }\n    friend std::istream& operator>>(std::istream&\
    \ s, modint& rhs) noexcept {\n        i64 v;\n        rhs = modint{(s >> v, v)};\n\
    \        return s;\n    }\n    friend std::ostream& operator<<(std::ostream& s,\
    \ const modint& rhs) noexcept { return s << rhs.v; }\n};\n\n/**\n * @brief modint\n\
    \ * @docs docs/modulo/modint.md\n */\n#line 6 \"test/yosupo/matrix_det.test.cpp\"\
    \n\nusing mint = modint<998244353>;\n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int N;\n    cin >> N;\n    Matrix<mint> a(N);\n    for (int i = 0; i < N;\
    \ i++) {\n        for (int j = 0; j < N; j++) {\n            cin >> a[i][j];\n\
    \        }\n    }\n\n    cout << a.determinant() << '\\n';\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include\
    \ \"../../base.hpp\"\n#include \"../../linearalgebra/Matrix.hpp\"\n#include \"\
    ../../modulo/modint.hpp\"\n\nusing mint = modint<998244353>;\n\nint main() {\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N;\n    cin >> N;\n\
    \    Matrix<mint> a(N);\n    for (int i = 0; i < N; i++) {\n        for (int j\
    \ = 0; j < N; j++) {\n            cin >> a[i][j];\n        }\n    }\n\n    cout\
    \ << a.determinant() << '\\n';\n}"
  dependsOn:
  - base.hpp
  - linearalgebra/Matrix.hpp
  - modulo/modint.hpp
  isVerificationFile: true
  path: test/yosupo/matrix_det.test.cpp
  requiredBy: []
  timestamp: '2021-10-01 20:18:39+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/matrix_det.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_det.test.cpp
- /verify/test/yosupo/matrix_det.test.cpp.html
title: test/yosupo/matrix_det.test.cpp
---
