---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Circle.hpp
    title: src/geometry/Circle.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Line.hpp
    title: src/geometry/Line.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/Polygon.hpp
    title: src/geometry/Polygon.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/ccw.hpp
    title: src/geometry/ccw.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/circumcircle.hpp
    title: src/geometry/circumcircle.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/closest_pair.hpp
    title: src/geometry/closest_pair.hpp
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
    path: src/geometry/convex_hull.hpp
    title: "\u51F8\u5305"
  - icon: ':heavy_check_mark:'
    path: src/geometry/crosspoint.hpp
    title: src/geometry/crosspoint.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/distance.hpp
    title: src/geometry/distance.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/incircle.hpp
    title: src/geometry/incircle.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/projection.hpp
    title: src/geometry/projection.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/reflection.hpp
    title: src/geometry/reflection.hpp
  - icon: ':heavy_check_mark:'
    path: src/geometry/sort_points_by_argument.hpp
    title: "\u504F\u89D2\u30BD\u30FC\u30C8"
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_A.test.cpp
    title: test/aoj/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_B.test.cpp
    title: test/aoj/CGL_1_B.test.cpp
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
    path: test/aoj/CGL_4_A.test.cpp
    title: test/aoj/CGL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_B.test.cpp
    title: test/aoj/CGL_4_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_C.test.cpp
    title: test/aoj/CGL_4_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_A.test.cpp
    title: test/aoj/CGL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_B.test.cpp
    title: test/aoj/CGL_7_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_C.test.cpp
    title: test/aoj/CGL_7_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_D.test.cpp
    title: test/aoj/CGL_7_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_E.test.cpp
    title: test/aoj/CGL_7_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sort_points_by_argument.test.cpp
    title: test/yosupo/sort_points_by_argument.test.cpp
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
    \ }\n\n}  // namespace geometry\n"
  code: "#pragma once\n#include <cassert>\n#include <cmath>\n#include <iostream>\n\
    #include <type_traits>\n\nnamespace geometry {\n\ntemplate <typename T> struct\
    \ Point {\n    static T EPS;\n\n    static void set_eps(T eps) { EPS = eps; }\n\
    \n    T x, y;\n\n    Point() {}\n\n    Point(T x, T y) : x(x), y(y) {}\n\n   \
    \ Point operator+(const Point& p) const { return Point(x + p.x, y + p.y); }\n\n\
    \    Point operator-(const Point& p) const { return Point(x - p.x, y - p.y); }\n\
    \n    Point operator*(T t) const { return Point(x * t, y * t); }\n\n    Point\
    \ operator/(T t) const { return Point(x / t, y / t); }\n\n    bool operator==(const\
    \ Point& p) const { return x == p.x and y == p.y; }\n\n    bool operator!=(const\
    \ Point& p) const { return not((*this) == p); }\n\n    bool operator<(const Point&\
    \ p) const { return x != p.x ? x < p.x : y < p.y; }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, Point& p) { return is >> p.x >> p.y; }\n\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const Point& p) { return os << p.x\
    \ << ' ' << p.y; }\n\n    T norm() { return std::sqrt(x * x + y * y); }\n\n  \
    \  T norm2() { return x * x + y * y; }\n\n    T arg() { return std::atan2(y, x);\
    \ }\n\n    T dot(const Point& p) { return x * p.x + y * p.y; }\n\n    T det(const\
    \ Point& p) { return x * p.y - y * p.x; }\n\n    Point perp() { return Point(-y,\
    \ x); }\n\n    Point unit() { return *this / norm(); }\n\n    Point normal() {\
    \ return perp().unit(); }\n\n    Point rotate(T rad) { return Point(std::cos(rad)\
    \ * x - std::sin(rad) * y, std::sin(rad) * x + std::cos(rad) * y); }\n};\n\ntemplate\
    \ <> double Point<double>::EPS = 1e-9;\ntemplate <> long double Point<long double>::EPS\
    \ = 1e-12;\ntemplate <> int Point<int>::EPS = 0;\ntemplate <> long long Point<long\
    \ long>::EPS = 0;\n\ntemplate <typename T> int sgn(T x) { return x < -Point<T>::EPS\
    \ ? -1 : x > Point<T>::EPS ? 1 : 0; }\n\n}  // namespace geometry"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/Point.hpp
  requiredBy:
  - src/geometry/projection.hpp
  - src/geometry/contain.hpp
  - src/geometry/convex_hull.hpp
  - src/geometry/crosspoint.hpp
  - src/geometry/closest_pair.hpp
  - src/geometry/convex_cut.hpp
  - src/geometry/distance.hpp
  - src/geometry/Polygon.hpp
  - src/geometry/sort_points_by_argument.hpp
  - src/geometry/Line.hpp
  - src/geometry/ccw.hpp
  - src/geometry/reflection.hpp
  - src/geometry/incircle.hpp
  - src/geometry/circumcircle.hpp
  - src/geometry/Circle.hpp
  - src/geometry/convex_diameter.hpp
  timestamp: '2023-10-04 02:32:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sort_points_by_argument.test.cpp
  - test/aoj/CGL_1_A.test.cpp
  - test/aoj/CGL_3_A.test.cpp
  - test/aoj/CGL_7_A.test.cpp
  - test/aoj/CGL_1_C.test.cpp
  - test/aoj/CGL_2_C.test.cpp
  - test/aoj/CGL_4_B.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_1_B.test.cpp
  - test/aoj/CGL_2_B.test.cpp
  - test/aoj/CGL_2_A.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/CGL_3_C.test.cpp
  - test/aoj/CGL_7_E.test.cpp
  - test/aoj/CGL_4_C.test.cpp
  - test/aoj/CGL_5_A.test.cpp
  - test/aoj/CGL_4_A.test.cpp
  - test/aoj/CGL_7_D.test.cpp
  - test/aoj/CGL_2_D.test.cpp
  - test/aoj/CGL_3_B.test.cpp
documentation_of: src/geometry/Point.hpp
layout: document
redirect_from:
- /library/src/geometry/Point.hpp
- /library/src/geometry/Point.hpp.html
title: src/geometry/Point.hpp
---
