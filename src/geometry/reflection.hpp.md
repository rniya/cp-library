---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Line.hpp
    title: Line
  - icon: ':question:'
    path: src/geometry/Point.hpp
    title: Point
  - icon: ':heavy_check_mark:'
    path: src/geometry/projection.hpp
    title: projection
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_B.test.cpp
    title: test/aoj/CGL_1_B.test.cpp
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
    \ }\n\n}  // namespace geometry\n#line 3 \"src/geometry/Line.hpp\"\n\nnamespace\
    \ geometry {\n\ntemplate <typename T> struct Line {\n    Point<T> a, b;\n\n  \
    \  Line() {}\n\n    Line(const Point<T>& a, const Point<T>& b) : a(a), b(b) {}\n\
    \n    // A * x + B * y + C = 0\n    Line(T A, T B, T C) {}\n\n    friend std::istream&\
    \ operator>>(std::istream& is, Line& l) { return is >> l.a >> l.b; }\n\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const Line& l) { return os << l.a\
    \ << \" to \" << l.b; }\n};\n\ntemplate <typename T> struct Segment : Line<T>\
    \ {\n    Segment() {}\n\n    Segment(const Point<T>& a, const Point<T>& b) : Line<T>(a,\
    \ b) {}\n};\n\n}  // namespace geometry\n#line 4 \"src/geometry/projection.hpp\"\
    \n\nnamespace geometry {\n\ntemplate <typename T> Point<T> projection(const Line<T>&\
    \ l, const Point<T>& p) {\n    Point<T> a = p - l.a, b = l.b - l.a;\n    return\
    \ l.a + b * a.dot(b) / b.norm2();\n}\n\n}  // namespace geometry\n#line 3 \"src/geometry/reflection.hpp\"\
    \n\nnamespace geometry {\n\ntemplate <typename T> Point<T> reflection(const Line<T>&\
    \ l, const Point<T>& p) {\n    Point h = projection(l, p);\n    return h + (h\
    \ - p);\n}\n\n}  // namespace geometry\n"
  code: "#pragma once\n#include \"projection.hpp\"\n\nnamespace geometry {\n\ntemplate\
    \ <typename T> Point<T> reflection(const Line<T>& l, const Point<T>& p) {\n  \
    \  Point h = projection(l, p);\n    return h + (h - p);\n}\n\n}  // namespace\
    \ geometry"
  dependsOn:
  - src/geometry/projection.hpp
  - src/geometry/Line.hpp
  - src/geometry/Point.hpp
  isVerificationFile: false
  path: src/geometry/reflection.hpp
  requiredBy: []
  timestamp: '2023-10-04 02:32:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_1_B.test.cpp
documentation_of: src/geometry/reflection.hpp
layout: document
title: reflection
---
