---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.hpp
    title: Point
  - icon: ':heavy_check_mark:'
    path: src/geometry/Polygon.hpp
    title: Polygon
  - icon: ':heavy_check_mark:'
    path: src/geometry/ccw.hpp
    title: Counter Clockwise
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: src/geometry/furthest_pair.hpp
    title: Furthest Pair
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_B.test.cpp
    title: test/aoj/CGL_4_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/furthest_pair.test.cpp
    title: test/yosupo/furthest_pair.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/convex_diameter.hpp\"\n#include <algorithm>\n\
    #include <tuple>\n#include <utility>\n#line 2 \"src/geometry/Polygon.hpp\"\n#include\
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
    \ }\n\n}  // namespace geometry\n#line 3 \"src/geometry/ccw.hpp\"\n\nnamespace\
    \ geometry {\n\nenum Position { COUNTER_CLOCKWISE = +1, CLOCKWISE = -1, ONLINE_BACK\
    \ = +2, ONLINE_FRONT = -2, ON_SEGMENT = 0 };\n\ntemplate <typename T> Position\
    \ ccw(const Point<T>& a, Point<T> b, Point<T> c) {\n    b = b - a;\n    c = c\
    \ - a;\n    if (sgn(b.det(c)) == 1) return COUNTER_CLOCKWISE;\n    if (sgn(b.det(c))\
    \ == -1) return CLOCKWISE;\n    if (sgn(b.dot(c)) == -1) return ONLINE_BACK;\n\
    \    if (b.norm2() < c.norm2()) return ONLINE_FRONT;\n    return ON_SEGMENT;\n\
    }\n\n}  // namespace geometry\n#line 4 \"src/geometry/Polygon.hpp\"\n\nnamespace\
    \ geometry {\n\ntemplate <typename T> struct Polygon : std::vector<Point<T>> {\n\
    \    using std::vector<Point<T>>::vector;\n\n    Polygon(int n) : std::vector<Point<T>>(n)\
    \ {}\n\n    T area2() {\n        T sum = 0;\n        int n = this->size();\n \
    \       for (int i = 0; i < n; i++) sum += (*this)[i].det((*this)[i + 1 == n ?\
    \ 0 : i + 1]);\n        return sum < 0 ? -sum : sum;\n    }\n\n    T area() {\
    \ return area2() / 2; }\n\n    bool is_convex() {\n        int n = this->size();\n\
    \        for (int j = 0; j < n; j++) {\n            int i = (j == 0 ? n - 1 :\
    \ j - 1), k = (j == n - 1 ? 0 : j + 1);\n            if (ccw((*this)[i], (*this)[j],\
    \ (*this)[k]) == CLOCKWISE) return false;\n        }\n        return true;\n \
    \   }\n};\n\n}  // namespace geometry\n#line 6 \"src/geometry/convex_diameter.hpp\"\
    \n\nnamespace geometry {\n\ntemplate <typename T> std::pair<int, int> convex_diameter(const\
    \ Polygon<T>& convex) {\n    int n = convex.size();\n    auto [si, sj] = [&] {\n\
    \        auto [it_min, it_max] = std::minmax_element(begin(convex), end(convex));\n\
    \        return std::pair<int, int>{it_min - begin(convex), it_max - begin(convex)};\n\
    \    }();\n    T max_dist = -1;\n    std::pair<int, int> argmax{-1, -1};\n   \
    \ for (int i = si, j = sj; i != sj or j != si;) {\n        T d = (convex[i] -\
    \ convex[j]).norm2();\n        if (max_dist < d) {\n            max_dist = d;\n\
    \            argmax = {i, j};\n        }\n        int ni = (i + 1 == n ? 0 : i\
    \ + 1), nj = (j + 1 == n ? 0 : j + 1);\n        if ((convex[ni] - convex[i]).det(convex[nj]\
    \ - convex[j]) < 0)\n            i = ni;\n        else\n            j = nj;\n\
    \    }\n    return argmax;\n}\n\n}  // namespace geometry\n"
  code: "#pragma once\n#include <algorithm>\n#include <tuple>\n#include <utility>\n\
    #include \"Polygon.hpp\"\n\nnamespace geometry {\n\ntemplate <typename T> std::pair<int,\
    \ int> convex_diameter(const Polygon<T>& convex) {\n    int n = convex.size();\n\
    \    auto [si, sj] = [&] {\n        auto [it_min, it_max] = std::minmax_element(begin(convex),\
    \ end(convex));\n        return std::pair<int, int>{it_min - begin(convex), it_max\
    \ - begin(convex)};\n    }();\n    T max_dist = -1;\n    std::pair<int, int> argmax{-1,\
    \ -1};\n    for (int i = si, j = sj; i != sj or j != si;) {\n        T d = (convex[i]\
    \ - convex[j]).norm2();\n        if (max_dist < d) {\n            max_dist = d;\n\
    \            argmax = {i, j};\n        }\n        int ni = (i + 1 == n ? 0 : i\
    \ + 1), nj = (j + 1 == n ? 0 : j + 1);\n        if ((convex[ni] - convex[i]).det(convex[nj]\
    \ - convex[j]) < 0)\n            i = ni;\n        else\n            j = nj;\n\
    \    }\n    return argmax;\n}\n\n}  // namespace geometry"
  dependsOn:
  - src/geometry/Polygon.hpp
  - src/geometry/ccw.hpp
  - src/geometry/Point.hpp
  isVerificationFile: false
  path: src/geometry/convex_diameter.hpp
  requiredBy:
  - src/geometry/furthest_pair.hpp
  timestamp: '2024-06-20 02:02:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_4_B.test.cpp
  - test/yosupo/furthest_pair.test.cpp
documentation_of: src/geometry/convex_diameter.hpp
layout: document
title: Convex Diameter
---
