---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Circle.hpp
    title: Circle
  - icon: ':heavy_check_mark:'
    path: src/geometry/Line.hpp
    title: Line
  - icon: ':heavy_check_mark:'
    path: src/geometry/Polygon.hpp
    title: Polygon
  - icon: ':heavy_check_mark:'
    path: src/geometry/ccw.hpp
    title: Counter Clockwise
  - icon: ':heavy_check_mark:'
    path: src/geometry/circumcircle.hpp
    title: Circumcircle
  - icon: ':heavy_check_mark:'
    path: src/geometry/closest_pair.hpp
    title: Closest Pair
  - icon: ':heavy_check_mark:'
    path: src/geometry/contain.hpp
    title: Contain
  - icon: ':heavy_check_mark:'
    path: src/geometry/convex_cut.hpp
    title: Convex Cut
  - icon: ':heavy_check_mark:'
    path: src/geometry/convex_diameter.hpp
    title: Convex Diameter
  - icon: ':heavy_check_mark:'
    path: src/geometry/convex_hull.hpp
    title: Convex Hull
  - icon: ':heavy_check_mark:'
    path: src/geometry/crosspoint.hpp
    title: Crosspoint
  - icon: ':heavy_check_mark:'
    path: src/geometry/distance.hpp
    title: Distance
  - icon: ':heavy_check_mark:'
    path: src/geometry/furthest_pair.hpp
    title: Furthest Pair
  - icon: ':heavy_check_mark:'
    path: src/geometry/incircle.hpp
    title: Incircle
  - icon: ':heavy_check_mark:'
    path: src/geometry/projection.hpp
    title: projection
  - icon: ':heavy_check_mark:'
    path: src/geometry/reflection.hpp
    title: reflection
  - icon: ':heavy_check_mark:'
    path: src/geometry/sort_points_by_argument.hpp
    title: Sort Points by Argument
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
    path: test/yosupo/closest_pair.test.cpp
    title: test/yosupo/closest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/furthest_pair.test.cpp
    title: test/yosupo/furthest_pair.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sort_points_by_argument.test.cpp
    title: test/yosupo/sort_points_by_argument.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_convex_hull.test.cpp
    title: test/yosupo/static_convex_hull.test.cpp
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
  - src/geometry/furthest_pair.hpp
  - src/geometry/circumcircle.hpp
  - src/geometry/distance.hpp
  - src/geometry/convex_diameter.hpp
  - src/geometry/crosspoint.hpp
  - src/geometry/projection.hpp
  - src/geometry/convex_hull.hpp
  - src/geometry/sort_points_by_argument.hpp
  - src/geometry/convex_cut.hpp
  - src/geometry/closest_pair.hpp
  - src/geometry/ccw.hpp
  - src/geometry/incircle.hpp
  - src/geometry/contain.hpp
  - src/geometry/Polygon.hpp
  - src/geometry/Line.hpp
  - src/geometry/Circle.hpp
  - src/geometry/reflection.hpp
  timestamp: '2023-10-04 02:32:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_5_A.test.cpp
  - test/aoj/CGL_4_B.test.cpp
  - test/aoj/CGL_3_B.test.cpp
  - test/aoj/CGL_3_C.test.cpp
  - test/aoj/CGL_4_C.test.cpp
  - test/aoj/CGL_3_A.test.cpp
  - test/aoj/CGL_7_A.test.cpp
  - test/aoj/CGL_4_A.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_7_E.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/CGL_7_D.test.cpp
  - test/aoj/CGL_1_C.test.cpp
  - test/aoj/CGL_2_D.test.cpp
  - test/aoj/CGL_2_B.test.cpp
  - test/aoj/CGL_1_B.test.cpp
  - test/aoj/CGL_2_C.test.cpp
  - test/aoj/CGL_1_A.test.cpp
  - test/aoj/CGL_2_A.test.cpp
  - test/yosupo/furthest_pair.test.cpp
  - test/yosupo/closest_pair.test.cpp
  - test/yosupo/static_convex_hull.test.cpp
  - test/yosupo/sort_points_by_argument.test.cpp
documentation_of: src/geometry/Point.hpp
layout: document
title: Point
---
