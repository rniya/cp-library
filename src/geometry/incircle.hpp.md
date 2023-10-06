---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Circle.hpp
    title: src/geometry/Circle.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.hpp
    title: src/geometry/Point.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_B.test.cpp
    title: test/aoj/CGL_7_B.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/Point.hpp\"\n#include <cassert>\n#include <cmath>\n\
    #include <iostream>\n#include <type_traits>\n\nnamespace geometry {\n\ntemplate\
    \ <typename T> struct Point {\n    static T EPS;\n\n    static void set_eps(T\
    \ eps) { EPS = eps; }\n\n    T x, y;\n\n    Point() {}\n\n    Point(T x, T y)\
    \ : x(x), y(y) {}\n\n    Point operator+(const Point& p) const { return Point(x\
    \ + p.x, y + p.y); }\n\n    Point operator-(const Point& p) const { return Point(x\
    \ - p.x, y - p.y); }\n\n    Point operator*(T t) const { return Point(x * t, y\
    \ * t); }\n\n    Point operator/(T t) const { return Point(x / t, y / t); }\n\n\
    \    bool operator==(const Point& p) const { return x == p.x and y == p.y; }\n\
    \n    bool operator!=(const Point& p) const { return not((*this) == p); }\n\n\
    \    bool operator<(const Point& p) const { return x != p.x ? x < p.x : y < p.y;\
    \ }\n\n    friend std::istream& operator>>(std::istream& is, Point& p) { return\
    \ is >> p.x >> p.y; }\n\n    friend std::ostream& operator<<(std::ostream& os,\
    \ const Point& p) { return os << p.x << ' ' << p.y; }\n\n    T norm() { return\
    \ std::sqrt(x * x + y * y); }\n\n    T norm2() { return x * x + y * y; }\n\n \
    \   T arg() { return std::atan2(y, x); }\n\n    T dot(const Point& p) { return\
    \ x * p.x + y * p.y; }\n\n    T det(const Point& p) { return x * p.y - y * p.x;\
    \ }\n\n    Point perp() { return Point(-y, x); }\n\n    Point unit() { return\
    \ *this / norm(); }\n\n    Point normal() { return perp().unit(); }\n\n    Point\
    \ rotate(T rad) { return Point(std::cos(rad) * x - std::sin(rad) * y, std::sin(rad)\
    \ * x + std::cos(rad) * y); }\n};\n\ntemplate <> double Point<double>::EPS = 1e-9;\n\
    template <> long double Point<long double>::EPS = 1e-12;\ntemplate <> int Point<int>::EPS\
    \ = 0;\ntemplate <> long long Point<long long>::EPS = 0;\n\ntemplate <typename\
    \ T> int sgn(T x) { return x < -Point<T>::EPS ? -1 : x > Point<T>::EPS ? 1 : 0;\
    \ }\n\n}  // namespace geometry\n#line 3 \"src/geometry/Circle.hpp\"\n\nnamespace\
    \ geometry {\n\ntemplate <typename T> struct Circle {\n    Point<T> c;\n    T\
    \ r;\n\n    Circle() {}\n\n    Circle(Point<T> c, T r) : c(c), r(r) {}\n\n   \
    \ friend std::istream& operator>>(std::istream& is, Circle& c) { return is >>\
    \ c.c >> c.r; }\n\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ Circle& c) { return os << c.c << ' ' << c.r; }\n};\n\n}  // namespace geometry\n\
    #line 3 \"src/geometry/incircle.hpp\"\n\nnamespace geometry {\n\ntemplate <typename\
    \ T> Circle<T> incircle(const Point<T>& a, const Point<T>& b, const Point<T>&\
    \ c) {\n    T la = (b - c).norm(), lb = (c - a).norm(), lc = (a - b).norm();\n\
    \    Point<T> center = (a * la + b * lb + c * lc) / (la + lb + lc);\n    T radius\
    \ = std::abs((b - a).det(c - a)) / (la + lb + lc);\n    return Circle<T>(center,\
    \ radius);\n}\n\n}  // namespace geometry\n"
  code: "#pragma once\n#include \"Circle.hpp\"\n\nnamespace geometry {\n\ntemplate\
    \ <typename T> Circle<T> incircle(const Point<T>& a, const Point<T>& b, const\
    \ Point<T>& c) {\n    T la = (b - c).norm(), lb = (c - a).norm(), lc = (a - b).norm();\n\
    \    Point<T> center = (a * la + b * lb + c * lc) / (la + lb + lc);\n    T radius\
    \ = std::abs((b - a).det(c - a)) / (la + lb + lc);\n    return Circle<T>(center,\
    \ radius);\n}\n\n}  // namespace geometry"
  dependsOn:
  - src/geometry/Circle.hpp
  - src/geometry/Point.hpp
  isVerificationFile: false
  path: src/geometry/incircle.hpp
  requiredBy: []
  timestamp: '2023-10-07 00:10:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_7_B.test.cpp
documentation_of: src/geometry/incircle.hpp
layout: document
redirect_from:
- /library/src/geometry/incircle.hpp
- /library/src/geometry/incircle.hpp.html
title: src/geometry/incircle.hpp
---
