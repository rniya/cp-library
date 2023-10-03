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
    path: test/aoj/CGL_7_C.test.cpp
    title: test/aoj/CGL_7_C.test.cpp
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
    #line 2 \"src/geometry/circumcircle.hpp\"\n\nnamespace geometry {\n\ntemplate\
    \ <typename T> Circle<T> circumcircle(const Point<T>& a, const Point<T>& b, const\
    \ Point<T>& c) {\n    T la = (b - c).norm2(), lb = (c - a).norm2(), lc = (a -\
    \ b).norm2();\n    T s = la * (lb + lc - la), t = lb * (lc + la - lb), u = lc\
    \ * (la + lb - lc), l = s + t + u;\n    s /= l, t /= l, u /= l;\n    Point<T>\
    \ center = a * s + b * t + c * u;\n    return Circle<T>(center, (a - center).norm());\n\
    }\n\n}  // namespace geometry\n"
  code: "#include \"Circle.hpp\"\n\nnamespace geometry {\n\ntemplate <typename T>\
    \ Circle<T> circumcircle(const Point<T>& a, const Point<T>& b, const Point<T>&\
    \ c) {\n    T la = (b - c).norm2(), lb = (c - a).norm2(), lc = (a - b).norm2();\n\
    \    T s = la * (lb + lc - la), t = lb * (lc + la - lb), u = lc * (la + lb - lc),\
    \ l = s + t + u;\n    s /= l, t /= l, u /= l;\n    Point<T> center = a * s + b\
    \ * t + c * u;\n    return Circle<T>(center, (a - center).norm());\n}\n\n}  //\
    \ namespace geometry"
  dependsOn:
  - src/geometry/Circle.hpp
  - src/geometry/Point.hpp
  isVerificationFile: false
  path: src/geometry/circumcircle.hpp
  requiredBy: []
  timestamp: '2023-10-04 02:32:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_7_C.test.cpp
documentation_of: src/geometry/circumcircle.hpp
layout: document
redirect_from:
- /library/src/geometry/circumcircle.hpp
- /library/src/geometry/circumcircle.hpp.html
title: src/geometry/circumcircle.hpp
---
