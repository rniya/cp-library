---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.hpp
    title: src/geometry/Point.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Polygon.hpp
    title: src/geometry/Polygon.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/contain.hpp
    title: src/geometry/contain.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/convex_cut.hpp
    title: src/geometry/convex_cut.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/convex_diameter.hpp
    title: src/geometry/convex_diameter.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/crosspoint.hpp
    title: src/geometry/crosspoint.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/distance.hpp
    title: src/geometry/distance.hpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_C.test.cpp
    title: test/aoj/CGL_1_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_A.test.cpp
    title: test/aoj/CGL_2_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_B.test.cpp
    title: test/aoj/CGL_2_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_C.test.cpp
    title: test/aoj/CGL_2_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_2_D.test.cpp
    title: test/aoj/CGL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_A.test.cpp
    title: test/aoj/CGL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_B.test.cpp
    title: test/aoj/CGL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_C.test.cpp
    title: test/aoj/CGL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_B.test.cpp
    title: test/aoj/CGL_4_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_C.test.cpp
    title: test/aoj/CGL_4_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_A.test.cpp
    title: test/aoj/CGL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_D.test.cpp
    title: test/aoj/CGL_7_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_E.test.cpp
    title: test/aoj/CGL_7_E.test.cpp
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
    \ }\n\n}  // namespace geometry\n#line 3 \"src/geometry/ccw.hpp\"\n\nnamespace\
    \ geometry {\n\nenum Position { COUNTER_CLOCKWISE = +1, CLOCKWISE = -1, ONLINE_BACK\
    \ = +2, ONLINE_FRONT = -2, ON_SEGMENT = 0 };\n\ntemplate <typename T> Position\
    \ ccw(const Point<T>& a, Point<T> b, Point<T> c) {\n    b = b - a;\n    c = c\
    \ - a;\n    if (sgn(b.det(c)) == 1) return COUNTER_CLOCKWISE;\n    if (sgn(b.det(c))\
    \ == -1) return CLOCKWISE;\n    if (sgn(b.dot(c)) == -1) return ONLINE_BACK;\n\
    \    if (b.norm2() < c.norm2()) return ONLINE_FRONT;\n    return ON_SEGMENT;\n\
    }\n\n}  // namespace geometry\n"
  code: "#pragma once\n#include \"Point.hpp\"\n\nnamespace geometry {\n\nenum Position\
    \ { COUNTER_CLOCKWISE = +1, CLOCKWISE = -1, ONLINE_BACK = +2, ONLINE_FRONT = -2,\
    \ ON_SEGMENT = 0 };\n\ntemplate <typename T> Position ccw(const Point<T>& a, Point<T>\
    \ b, Point<T> c) {\n    b = b - a;\n    c = c - a;\n    if (sgn(b.det(c)) == 1)\
    \ return COUNTER_CLOCKWISE;\n    if (sgn(b.det(c)) == -1) return CLOCKWISE;\n\
    \    if (sgn(b.dot(c)) == -1) return ONLINE_BACK;\n    if (b.norm2() < c.norm2())\
    \ return ONLINE_FRONT;\n    return ON_SEGMENT;\n}\n\n}  // namespace geometry"
  dependsOn:
  - src/geometry/Point.hpp
  isVerificationFile: false
  path: src/geometry/ccw.hpp
  requiredBy:
  - src/geometry/Polygon.hpp
  - src/geometry/crosspoint.hpp
  - src/geometry/convex_cut.hpp
  - src/geometry/distance.hpp
  - src/geometry/convex_diameter.hpp
  - src/geometry/contain.hpp
  timestamp: '2023-10-04 02:32:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_3_B.test.cpp
  - test/aoj/CGL_7_D.test.cpp
  - test/aoj/CGL_2_D.test.cpp
  - test/aoj/CGL_2_C.test.cpp
  - test/aoj/CGL_2_B.test.cpp
  - test/aoj/CGL_4_C.test.cpp
  - test/aoj/CGL_4_B.test.cpp
  - test/aoj/CGL_7_E.test.cpp
  - test/aoj/CGL_1_C.test.cpp
  - test/aoj/CGL_2_A.test.cpp
  - test/aoj/CGL_3_A.test.cpp
  - test/aoj/CGL_7_A.test.cpp
  - test/aoj/CGL_3_C.test.cpp
documentation_of: src/geometry/ccw.hpp
layout: document
redirect_from:
- /library/src/geometry/ccw.hpp
- /library/src/geometry/ccw.hpp.html
title: src/geometry/ccw.hpp
---
