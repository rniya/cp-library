---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/geometry/Point.hpp
    title: Point
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/sort_points_by_argument.test.cpp
    title: test/yosupo/sort_points_by_argument.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/sort_points_by_argument.hpp\"\n#include <algorithm>\n\
    #include <numeric>\n#include <utility>\n#include <vector>\n#line 2 \"src/geometry/Point.hpp\"\
    \n#include <cassert>\n#include <cmath>\n#include <iostream>\n#include <type_traits>\n\
    \nnamespace geometry {\n\ntemplate <typename T> struct Point {\n    static T EPS;\n\
    \n    static void set_eps(T eps) { EPS = eps; }\n\n    T x, y;\n\n    Point()\
    \ {}\n\n    Point(T x, T y) : x(x), y(y) {}\n\n    Point operator+(const Point&\
    \ p) const { return Point(x + p.x, y + p.y); }\n\n    Point operator-(const Point&\
    \ p) const { return Point(x - p.x, y - p.y); }\n\n    Point operator*(T t) const\
    \ { return Point(x * t, y * t); }\n\n    Point operator/(T t) const { return Point(x\
    \ / t, y / t); }\n\n    bool operator==(const Point& p) const { return x == p.x\
    \ and y == p.y; }\n\n    bool operator!=(const Point& p) const { return not((*this)\
    \ == p); }\n\n    bool operator<(const Point& p) const { return x != p.x ? x <\
    \ p.x : y < p.y; }\n\n    friend std::istream& operator>>(std::istream& is, Point&\
    \ p) { return is >> p.x >> p.y; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Point& p) { return os << p.x << ' ' << p.y; }\n\n    T norm() { return\
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
    \ }\n\n}  // namespace geometry\n#line 7 \"src/geometry/sort_points_by_argument.hpp\"\
    \n\nnamespace geometry {\n\ntemplate <typename T> std::vector<int> sort_points_by_argument(const\
    \ std::vector<Point<T>>& P) {\n    auto type = [](const Point<T>& p) {\n     \
    \   if (p.x == 0 and p.y == 0) return 0;\n        return (p.y < 0 or (p.y == 0\
    \ and p.x > 0)) ? -1 : 1;\n    };\n    int n = P.size();\n    std::vector<int>\
    \ res(n);\n    std::iota(begin(res), end(res), 0);\n    std::sort(begin(res),\
    \ end(res), [&](int l, int r) {\n        int L = type(P[l]), R = type(P[r]);\n\
    \        return L != R ? L < R : P[l].x * P[r].y > P[l].y * P[r].x;\n    });\n\
    \    return res;\n}\n\ntemplate <typename T> std::vector<int> sort_points_by_argument(const\
    \ std::vector<std::pair<T, T>>& P) {\n    std::vector<Point<T>> tmp;\n    for\
    \ (const auto& [x, y] : P) tmp.emplace_back(x, y);\n    return sort_points_by_argument(tmp);\n\
    }\n\n}  // namespace geometry\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <utility>\n\
    #include <vector>\n#include \"Point.hpp\"\n\nnamespace geometry {\n\ntemplate\
    \ <typename T> std::vector<int> sort_points_by_argument(const std::vector<Point<T>>&\
    \ P) {\n    auto type = [](const Point<T>& p) {\n        if (p.x == 0 and p.y\
    \ == 0) return 0;\n        return (p.y < 0 or (p.y == 0 and p.x > 0)) ? -1 : 1;\n\
    \    };\n    int n = P.size();\n    std::vector<int> res(n);\n    std::iota(begin(res),\
    \ end(res), 0);\n    std::sort(begin(res), end(res), [&](int l, int r) {\n   \
    \     int L = type(P[l]), R = type(P[r]);\n        return L != R ? L < R : P[l].x\
    \ * P[r].y > P[l].y * P[r].x;\n    });\n    return res;\n}\n\ntemplate <typename\
    \ T> std::vector<int> sort_points_by_argument(const std::vector<std::pair<T, T>>&\
    \ P) {\n    std::vector<Point<T>> tmp;\n    for (const auto& [x, y] : P) tmp.emplace_back(x,\
    \ y);\n    return sort_points_by_argument(tmp);\n}\n\n}  // namespace geometry"
  dependsOn:
  - src/geometry/Point.hpp
  isVerificationFile: false
  path: src/geometry/sort_points_by_argument.hpp
  requiredBy: []
  timestamp: '2023-10-17 23:40:16+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/sort_points_by_argument.test.cpp
documentation_of: src/geometry/sort_points_by_argument.hpp
layout: document
title: Sort Points by Argument
---
