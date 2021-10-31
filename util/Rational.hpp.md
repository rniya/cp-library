---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1131.test.cpp
    title: test/aoj/1131.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/util/Rational.md
    document_title: Rational Number
    links: []
  bundledCode: "#line 2 \"util/Rational.hpp\"\n#include <iostream>\n\ntemplate <typename\
    \ T> class Rational {\n    T num, den;\n\n    static T my_gcd(T x_, T y_) {\n\
    \        unsigned long long x = x_ < 0 ? -x_ : x_, y = y_ < 0 ? -y_ : y_;\n  \
    \      if (!x or !y) return x + y;\n        int n = __builtin_ctzll(x), m = __builtin_ctzll(y);\n\
    \        x >>= n, y >>= m;\n        while (x != y) {\n            if (x > y)\n\
    \                x = (x - y) >> __builtin_ctzll(x - y);\n            else\n  \
    \              y = (y - x) >> __builtin_ctzll(y - x);\n        }\n        return\
    \ x << (n > m ? m : n);\n    }\n\n    void normalize() {\n        return;  //\
    \ comment out this flexibly\n        T g = my_gcd(num, den);\n        num /= g,\
    \ den /= g;\n        if (den < 0) num = -num, den = -den;\n    }\n\npublic:\n\
    \    Rational() {}\n    Rational(T num) : num(num), den(T(1)) {}\n    Rational(T\
    \ num, T den) : num(num), den(den) { normalize(); }\n\n    Rational operator+(const\
    \ Rational& r) const { return Rational(num * r.den + den * r.num, den * r.den);\
    \ }\n    Rational operator-(const Rational& r) const { return Rational(num * r.den\
    \ - den * r.num, den * r.den); }\n    Rational operator*(const Rational& r) const\
    \ { return Rational(num * r.num, den * r.den); }\n    Rational operator/(const\
    \ Rational& r) const { return Rational(num * r.den, den * r.num); }\n    Rational&\
    \ operator+=(const Rational& r) { return *this = *this + r; }\n    Rational& operator-=(const\
    \ Rational& r) { return *this = *this - r; }\n    Rational& operator*=(const Rational&\
    \ r) { return *this = *this * r; }\n    Rational& operator/=(const Rational& r)\
    \ { return *this = *this / r; }\n\n    Rational operator+(const T& val) const\
    \ { return *this + Rational(val); }\n    Rational operator-(const T& val) const\
    \ { return *this - Rational(val); }\n    Rational operator*(const T& val) const\
    \ { return *this * Rational(val); }\n    Rational operator/(const T& val) const\
    \ { return *this / Rational(val); }\n    Rational& operator+=(const T& val) {\
    \ return *this = *this + val; }\n    Rational& operator-=(const T& val) { return\
    \ *this = *this - val; }\n    Rational& operator*=(const T& val) { return *this\
    \ = *this * val; }\n    Rational& operator/=(const T& val) { return *this = *this\
    \ / val; }\n    friend Rational operator+(const T& val, const Rational& r) { return\
    \ r + val; }\n    friend Rational operator-(const T& val, const Rational& r) {\
    \ return r - val; }\n    friend Rational operator*(const T& val, const Rational&\
    \ r) { return r * val; }\n    friend Rational operator/(const T& val, const Rational&\
    \ r) { return r / val; }\n\n    Rational operator-() const { return Rational(-num,\
    \ den); }\n    Rational abs() const { return Rational(num < 0 ? -num : num, den);\
    \ }\n\n    bool operator==(const Rational& r) const {\n        if (den == 0 and\
    \ r.den == 0) return num == r.num;\n        if (den == 0 or r.den == 0) return\
    \ false;\n        return num * r.den == den * r.num;\n    }\n    bool operator!=(const\
    \ Rational& r) const { return !(*this == r); }\n    bool operator<(const Rational&\
    \ r) const {\n        if (den == 0 and r.den == 0) return num < r.num;\n     \
    \   if (den == 0) return num < 0;\n        if (r.den == 0) return r.num > 0;\n\
    \        return num * r.den < den * r.num;\n    }\n    bool operator<=(const Rational&\
    \ r) const { return (*this == r) or (*this < r); }\n    bool operator>(const Rational&\
    \ r) const { return r < *this; }\n    bool operator>=(const Rational& r) const\
    \ { return (*this == r) or (*this > r); }\n\n    bool operator==(const T& val)\
    \ const { return *this == Rational(val); }\n    bool operator!=(const T& val)\
    \ const { return *this != Rational(val); }\n    bool operator<(const T& val) const\
    \ { return *this < Rational(val); }\n    bool operator<=(const T& val) const {\
    \ return *this <= Rational(val); }\n    bool operator>(const T& val) const { return\
    \ *this > Rational(val); }\n    bool operator>=(const T& val) const { return *this\
    \ >= Rational(val); }\n    friend bool operator==(const T& val, const Rational&\
    \ r) { return r == val; }\n    friend bool operator!=(const T& val, const Rational&\
    \ r) { return r != val; }\n    friend bool operator<(const T& val, const Rational&\
    \ r) { return r > val; }\n    friend bool operator<=(const T& val, const Rational&\
    \ r) { return r >= val; }\n    friend bool operator>(const T& val, const Rational&\
    \ r) { return r < val; }\n    friend bool operator>=(const T& val, const Rational&\
    \ r) { return r <= val; }\n\n    explicit operator double() const { return (double)num\
    \ / (double)den; }\n    explicit operator long double() const { return (long double)num\
    \ / (long double)den; }\n    friend std::ostream& operator<<(std::ostream& os,\
    \ const Rational& r) { return os << r.num << '/' << r.den; }\n};\n\n/**\n * @brief\
    \ Rational Number\n * @docs docs/util/Rational.md\n */\n"
  code: "#pragma once\n#include <iostream>\n\ntemplate <typename T> class Rational\
    \ {\n    T num, den;\n\n    static T my_gcd(T x_, T y_) {\n        unsigned long\
    \ long x = x_ < 0 ? -x_ : x_, y = y_ < 0 ? -y_ : y_;\n        if (!x or !y) return\
    \ x + y;\n        int n = __builtin_ctzll(x), m = __builtin_ctzll(y);\n      \
    \  x >>= n, y >>= m;\n        while (x != y) {\n            if (x > y)\n     \
    \           x = (x - y) >> __builtin_ctzll(x - y);\n            else\n       \
    \         y = (y - x) >> __builtin_ctzll(y - x);\n        }\n        return x\
    \ << (n > m ? m : n);\n    }\n\n    void normalize() {\n        return;  // comment\
    \ out this flexibly\n        T g = my_gcd(num, den);\n        num /= g, den /=\
    \ g;\n        if (den < 0) num = -num, den = -den;\n    }\n\npublic:\n    Rational()\
    \ {}\n    Rational(T num) : num(num), den(T(1)) {}\n    Rational(T num, T den)\
    \ : num(num), den(den) { normalize(); }\n\n    Rational operator+(const Rational&\
    \ r) const { return Rational(num * r.den + den * r.num, den * r.den); }\n    Rational\
    \ operator-(const Rational& r) const { return Rational(num * r.den - den * r.num,\
    \ den * r.den); }\n    Rational operator*(const Rational& r) const { return Rational(num\
    \ * r.num, den * r.den); }\n    Rational operator/(const Rational& r) const {\
    \ return Rational(num * r.den, den * r.num); }\n    Rational& operator+=(const\
    \ Rational& r) { return *this = *this + r; }\n    Rational& operator-=(const Rational&\
    \ r) { return *this = *this - r; }\n    Rational& operator*=(const Rational& r)\
    \ { return *this = *this * r; }\n    Rational& operator/=(const Rational& r) {\
    \ return *this = *this / r; }\n\n    Rational operator+(const T& val) const {\
    \ return *this + Rational(val); }\n    Rational operator-(const T& val) const\
    \ { return *this - Rational(val); }\n    Rational operator*(const T& val) const\
    \ { return *this * Rational(val); }\n    Rational operator/(const T& val) const\
    \ { return *this / Rational(val); }\n    Rational& operator+=(const T& val) {\
    \ return *this = *this + val; }\n    Rational& operator-=(const T& val) { return\
    \ *this = *this - val; }\n    Rational& operator*=(const T& val) { return *this\
    \ = *this * val; }\n    Rational& operator/=(const T& val) { return *this = *this\
    \ / val; }\n    friend Rational operator+(const T& val, const Rational& r) { return\
    \ r + val; }\n    friend Rational operator-(const T& val, const Rational& r) {\
    \ return r - val; }\n    friend Rational operator*(const T& val, const Rational&\
    \ r) { return r * val; }\n    friend Rational operator/(const T& val, const Rational&\
    \ r) { return r / val; }\n\n    Rational operator-() const { return Rational(-num,\
    \ den); }\n    Rational abs() const { return Rational(num < 0 ? -num : num, den);\
    \ }\n\n    bool operator==(const Rational& r) const {\n        if (den == 0 and\
    \ r.den == 0) return num == r.num;\n        if (den == 0 or r.den == 0) return\
    \ false;\n        return num * r.den == den * r.num;\n    }\n    bool operator!=(const\
    \ Rational& r) const { return !(*this == r); }\n    bool operator<(const Rational&\
    \ r) const {\n        if (den == 0 and r.den == 0) return num < r.num;\n     \
    \   if (den == 0) return num < 0;\n        if (r.den == 0) return r.num > 0;\n\
    \        return num * r.den < den * r.num;\n    }\n    bool operator<=(const Rational&\
    \ r) const { return (*this == r) or (*this < r); }\n    bool operator>(const Rational&\
    \ r) const { return r < *this; }\n    bool operator>=(const Rational& r) const\
    \ { return (*this == r) or (*this > r); }\n\n    bool operator==(const T& val)\
    \ const { return *this == Rational(val); }\n    bool operator!=(const T& val)\
    \ const { return *this != Rational(val); }\n    bool operator<(const T& val) const\
    \ { return *this < Rational(val); }\n    bool operator<=(const T& val) const {\
    \ return *this <= Rational(val); }\n    bool operator>(const T& val) const { return\
    \ *this > Rational(val); }\n    bool operator>=(const T& val) const { return *this\
    \ >= Rational(val); }\n    friend bool operator==(const T& val, const Rational&\
    \ r) { return r == val; }\n    friend bool operator!=(const T& val, const Rational&\
    \ r) { return r != val; }\n    friend bool operator<(const T& val, const Rational&\
    \ r) { return r > val; }\n    friend bool operator<=(const T& val, const Rational&\
    \ r) { return r >= val; }\n    friend bool operator>(const T& val, const Rational&\
    \ r) { return r < val; }\n    friend bool operator>=(const T& val, const Rational&\
    \ r) { return r <= val; }\n\n    explicit operator double() const { return (double)num\
    \ / (double)den; }\n    explicit operator long double() const { return (long double)num\
    \ / (long double)den; }\n    friend std::ostream& operator<<(std::ostream& os,\
    \ const Rational& r) { return os << r.num << '/' << r.den; }\n};\n\n/**\n * @brief\
    \ Rational Number\n * @docs docs/util/Rational.md\n */\n"
  dependsOn: []
  isVerificationFile: false
  path: util/Rational.hpp
  requiredBy: []
  timestamp: '2021-10-31 14:57:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1131.test.cpp
documentation_of: util/Rational.hpp
layout: document
redirect_from:
- /library/util/Rational.hpp
- /library/util/Rational.hpp.html
title: Rational Number
---
## 概要
有理数を効率的に処理するためのライブラリ. 基本的な四則演算や比較演算子等に対応している. また $1/0$ や $-1/0$ によって $\pm \infty$ にも対応している.

デフォルトでは約分は行わない設定となっている (約分する際には分子と分母の $\gcd$ を求める必要があるが, これによって TLE する可能性がある, [問題例](https://onlinejudge.u-aizu.ac.jp/problems/1131)) が, 関数 `normalize()` 内の `return` 文をコメントアウトすることで適宜調整可能である.
