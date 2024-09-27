---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Circle.hpp
    title: Circle
  - icon: ':heavy_check_mark:'
    path: src/geometry/Line.hpp
    title: Line
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.hpp
    title: Point
  - icon: ':heavy_check_mark:'
    path: src/geometry/ccw.hpp
    title: Counter Clockwise
  - icon: ':heavy_check_mark:'
    path: src/geometry/projection.hpp
    title: projection
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/contain.hpp
    title: Contain
  - icon: ':heavy_check_mark:'
    path: src/geometry/convex_cut.hpp
    title: Convex Cut
  - icon: ':heavy_check_mark:'
    path: src/geometry/distance.hpp
    title: Distance
  _extendedVerifiedWith:
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
    path: test/aoj/CGL_3_C.test.cpp
    title: test/aoj/CGL_3_C.test.cpp
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
  bundledCode: "#line 2 \"src/geometry/crosspoint.hpp\"\n#include <utility>\n#include\
    \ <vector>\n#line 2 \"src/geometry/Point.hpp\"\n#include <cassert>\n#include <cmath>\n\
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
    #line 3 \"src/geometry/ccw.hpp\"\n\nnamespace geometry {\n\nenum Position { COUNTER_CLOCKWISE\
    \ = +1, CLOCKWISE = -1, ONLINE_BACK = +2, ONLINE_FRONT = -2, ON_SEGMENT = 0 };\n\
    \ntemplate <typename T> Position ccw(const Point<T>& a, Point<T> b, Point<T> c)\
    \ {\n    b = b - a;\n    c = c - a;\n    if (sgn(b.det(c)) == 1) return COUNTER_CLOCKWISE;\n\
    \    if (sgn(b.det(c)) == -1) return CLOCKWISE;\n    if (sgn(b.dot(c)) == -1)\
    \ return ONLINE_BACK;\n    if (b.norm2() < c.norm2()) return ONLINE_FRONT;\n \
    \   return ON_SEGMENT;\n}\n\n}  // namespace geometry\n#line 3 \"src/geometry/Line.hpp\"\
    \n\nnamespace geometry {\n\ntemplate <typename T> struct Line {\n    Point<T>\
    \ a, b;\n\n    Line() {}\n\n    Line(const Point<T>& a, const Point<T>& b) : a(a),\
    \ b(b) {}\n\n    // A * x + B * y + C = 0\n    Line(T A, T B, T C) {}\n\n    friend\
    \ std::istream& operator>>(std::istream& is, Line& l) { return is >> l.a >> l.b;\
    \ }\n\n    friend std::ostream& operator<<(std::ostream& os, const Line& l) {\
    \ return os << l.a << \" to \" << l.b; }\n};\n\ntemplate <typename T> struct Segment\
    \ : Line<T> {\n    Segment() {}\n\n    Segment(const Point<T>& a, const Point<T>&\
    \ b) : Line<T>(a, b) {}\n};\n\n}  // namespace geometry\n#line 4 \"src/geometry/projection.hpp\"\
    \n\nnamespace geometry {\n\ntemplate <typename T> Point<T> projection(const Line<T>&\
    \ l, const Point<T>& p) {\n    Point<T> a = p - l.a, b = l.b - l.a;\n    return\
    \ l.a + b * a.dot(b) / b.norm2();\n}\n\n}  // namespace geometry\n#line 7 \"src/geometry/crosspoint.hpp\"\
    \n\nnamespace geometry {\n\ntemplate <typename T> bool is_parallel(const Line<T>&\
    \ l, const Line<T>& m) {\n    return sgn((l.b - l.a).det(m.b - m.a)) == 0;\n}\n\
    \ntemplate <typename T> bool is_orthogonal(const Line<T>& l, const Line<T>& m)\
    \ {\n    return sgn((l.b - l.a).dot(m.b - m.a)) == 0;\n}\n\ntemplate <typename\
    \ T> bool has_crosspoint(const Segment<T>& s, const Segment<T>& t) {\n    return\
    \ ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 and ccw(t.a, t.b, s.a) * ccw(t.a,\
    \ t.b, s.b) <= 0;\n}\n\ntemplate <typename T> int count_common_tangent(const Circle<T>&\
    \ c, const Circle<T>& d) {\n    T dist = (c.c - d.c).norm();\n    int tmp = sgn(dist\
    \ - (c.r + d.r));\n    if (tmp > 0) return 4;\n    if (tmp == 0) return 3;\n \
    \   tmp = sgn(dist - (sgn(c.r - d.r) > 0 ? c.r - d.r : d.r - c.r));\n    if (tmp\
    \ > 0) return 2;\n    if (tmp == 0) return 1;\n    return 0;\n}\n\ntemplate <typename\
    \ T> Point<T> crosspoint(const Line<T>& l, const Line<T>& m) {\n    assert(not\
    \ is_parallel(l, m));\n    Point<T> u = l.b - l.a, v = m.b - m.a;\n    return\
    \ l.a + u * v.det(m.a - l.a) / v.det(u);\n}\n\ntemplate <typename T> Point<T>\
    \ crosspoint(const Segment<T>& s, const Segment<T>& t) {\n    assert(has_crosspoint(s,\
    \ t));\n    if (not is_parallel(s, t)) return crosspoint(Line(s.a, s.b), Line(t.a,\
    \ t.b));\n    std::vector<Point<T>> v = {s.a, s.b, t.a, t.b};\n    for (int i\
    \ = 0; i <= 2; i++) {\n        for (int j = 2; j >= i; j--) {\n            if\
    \ (v[j + 1] < v[j]) {\n                std::swap(v[j], v[j + 1]);\n          \
    \  }\n        }\n    }\n    return v[1];\n}\n\ntemplate <typename T> std::vector<Point<T>>\
    \ crosspoint(const Circle<T>& c, const Line<T>& l) {\n    Point<T> h = projection(l,\
    \ c.c);\n    T x = c.r * c.r - (c.c - h).norm2();\n    if (sgn(x) < 0) return\
    \ {};\n    if (sgn(x) == 0) return {h};\n    Point<T> v = (l.b - l.a).unit() *\
    \ std::sqrt(x);\n    return {h - v, h + v};\n}\n\ntemplate <typename T> std::vector<Point<T>>\
    \ crosspoint(const Circle<T>& c, const Segment<T>& s) {}\n\ntemplate <typename\
    \ T> std::vector<Point<T>> crosspoint(const Circle<T>& c1, const Circle<T>& c2)\
    \ {\n    T r1 = c1.r, r2 = c2.r;\n    if (r1 < r2) return crosspoint(c2, c1);\n\
    \    T d = (c2.c - c1.c).norm();\n    if (sgn(d - (r1 + r2)) > 0 or sgn(d - (r1\
    \ - r2)) < 0) return {};\n    Point<T> v = c2.c - c1.c;\n    if (sgn(d - (r1 +\
    \ r2)) == 0 or sgn(d - (r1 - r2)) == 0) return {c1.c + v.unit() * r1};\n    T\
    \ p = ((r1 * r1 - r2 * r2) / d + d) / 2, q = std::sqrt(r1 * r1 - p * p);\n   \
    \ Point<T> h = c1.c + v.unit() * p;\n    Point<T> i = v.normal();\n    return\
    \ {h + i * q, h - i * q};\n}\n\n}  // namespace geometry\n"
  code: "#pragma once\n#include <utility>\n#include <vector>\n#include \"Circle.hpp\"\
    \n#include \"ccw.hpp\"\n#include \"projection.hpp\"\n\nnamespace geometry {\n\n\
    template <typename T> bool is_parallel(const Line<T>& l, const Line<T>& m) {\n\
    \    return sgn((l.b - l.a).det(m.b - m.a)) == 0;\n}\n\ntemplate <typename T>\
    \ bool is_orthogonal(const Line<T>& l, const Line<T>& m) {\n    return sgn((l.b\
    \ - l.a).dot(m.b - m.a)) == 0;\n}\n\ntemplate <typename T> bool has_crosspoint(const\
    \ Segment<T>& s, const Segment<T>& t) {\n    return ccw(s.a, s.b, t.a) * ccw(s.a,\
    \ s.b, t.b) <= 0 and ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;\n}\n\ntemplate\
    \ <typename T> int count_common_tangent(const Circle<T>& c, const Circle<T>& d)\
    \ {\n    T dist = (c.c - d.c).norm();\n    int tmp = sgn(dist - (c.r + d.r));\n\
    \    if (tmp > 0) return 4;\n    if (tmp == 0) return 3;\n    tmp = sgn(dist -\
    \ (sgn(c.r - d.r) > 0 ? c.r - d.r : d.r - c.r));\n    if (tmp > 0) return 2;\n\
    \    if (tmp == 0) return 1;\n    return 0;\n}\n\ntemplate <typename T> Point<T>\
    \ crosspoint(const Line<T>& l, const Line<T>& m) {\n    assert(not is_parallel(l,\
    \ m));\n    Point<T> u = l.b - l.a, v = m.b - m.a;\n    return l.a + u * v.det(m.a\
    \ - l.a) / v.det(u);\n}\n\ntemplate <typename T> Point<T> crosspoint(const Segment<T>&\
    \ s, const Segment<T>& t) {\n    assert(has_crosspoint(s, t));\n    if (not is_parallel(s,\
    \ t)) return crosspoint(Line(s.a, s.b), Line(t.a, t.b));\n    std::vector<Point<T>>\
    \ v = {s.a, s.b, t.a, t.b};\n    for (int i = 0; i <= 2; i++) {\n        for (int\
    \ j = 2; j >= i; j--) {\n            if (v[j + 1] < v[j]) {\n                std::swap(v[j],\
    \ v[j + 1]);\n            }\n        }\n    }\n    return v[1];\n}\n\ntemplate\
    \ <typename T> std::vector<Point<T>> crosspoint(const Circle<T>& c, const Line<T>&\
    \ l) {\n    Point<T> h = projection(l, c.c);\n    T x = c.r * c.r - (c.c - h).norm2();\n\
    \    if (sgn(x) < 0) return {};\n    if (sgn(x) == 0) return {h};\n    Point<T>\
    \ v = (l.b - l.a).unit() * std::sqrt(x);\n    return {h - v, h + v};\n}\n\ntemplate\
    \ <typename T> std::vector<Point<T>> crosspoint(const Circle<T>& c, const Segment<T>&\
    \ s) {}\n\ntemplate <typename T> std::vector<Point<T>> crosspoint(const Circle<T>&\
    \ c1, const Circle<T>& c2) {\n    T r1 = c1.r, r2 = c2.r;\n    if (r1 < r2) return\
    \ crosspoint(c2, c1);\n    T d = (c2.c - c1.c).norm();\n    if (sgn(d - (r1 +\
    \ r2)) > 0 or sgn(d - (r1 - r2)) < 0) return {};\n    Point<T> v = c2.c - c1.c;\n\
    \    if (sgn(d - (r1 + r2)) == 0 or sgn(d - (r1 - r2)) == 0) return {c1.c + v.unit()\
    \ * r1};\n    T p = ((r1 * r1 - r2 * r2) / d + d) / 2, q = std::sqrt(r1 * r1 -\
    \ p * p);\n    Point<T> h = c1.c + v.unit() * p;\n    Point<T> i = v.normal();\n\
    \    return {h + i * q, h - i * q};\n}\n\n}  // namespace geometry"
  dependsOn:
  - src/geometry/Circle.hpp
  - src/geometry/Point.hpp
  - src/geometry/ccw.hpp
  - src/geometry/projection.hpp
  - src/geometry/Line.hpp
  isVerificationFile: false
  path: src/geometry/crosspoint.hpp
  requiredBy:
  - src/geometry/distance.hpp
  - src/geometry/convex_cut.hpp
  - src/geometry/contain.hpp
  timestamp: '2023-10-04 02:32:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_2_A.test.cpp
  - test/aoj/CGL_7_A.test.cpp
  - test/aoj/CGL_2_C.test.cpp
  - test/aoj/CGL_2_B.test.cpp
  - test/aoj/CGL_7_D.test.cpp
  - test/aoj/CGL_4_C.test.cpp
  - test/aoj/CGL_7_E.test.cpp
  - test/aoj/CGL_3_C.test.cpp
  - test/aoj/CGL_2_D.test.cpp
documentation_of: src/geometry/crosspoint.hpp
layout: document
title: Crosspoint
---
