---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.hpp
    title: "Point \u69CB\u9020\u4F53"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_A.test.cpp
    title: test/aoj/CGL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_convex_hull.test.cpp
    title: test/yosupo/static_convex_hull.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/convex_hull.hpp\"\n#include <algorithm>\n#include\
    \ <numeric>\n#include <vector>\n#line 2 \"src/geometry/Point.hpp\"\n#include <cassert>\n\
    #include <cmath>\n#include <iostream>\n#include <type_traits>\n\nnamespace geometry\
    \ {\n\ntemplate <typename T> struct Point {\n    static T EPS;\n\n    static void\
    \ set_eps(T eps) { EPS = eps; }\n\n    T x, y;\n\n    Point() {}\n\n    Point(T\
    \ x, T y) : x(x), y(y) {}\n\n    Point operator+(const Point& p) const { return\
    \ Point(x + p.x, y + p.y); }\n\n    Point operator-(const Point& p) const { return\
    \ Point(x - p.x, y - p.y); }\n\n    Point operator*(T t) const { return Point(x\
    \ * t, y * t); }\n\n    Point operator/(T t) const { return Point(x / t, y / t);\
    \ }\n\n    bool operator==(const Point& p) const { return x == p.x and y == p.y;\
    \ }\n\n    bool operator!=(const Point& p) const { return not((*this) == p); }\n\
    \n    bool operator<(const Point& p) const { return x != p.x ? x < p.x : y < p.y;\
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
    \ }\n\n}  // namespace geometry\n#line 6 \"src/geometry/convex_hull.hpp\"\n\n\
    namespace geometry {\n\ntemplate <typename T> std::vector<int> convex_hull(const\
    \ std::vector<Point<T>>& P, bool inclusive = false) {\n    int n = P.size();\n\
    \    if (n == 0) return {};\n    if (n == 1) return {0};\n    if (n == 2) return\
    \ (P[0] != P[1] or inclusive ? std::vector<int>{0, 1} : std::vector<int>{0});\n\
    \    std::vector<int> ord(n);\n    std::iota(ord.begin(), ord.end(), 0);\n   \
    \ std::sort(ord.begin(), ord.end(), [&](int l, int r) { return P[l] < P[r]; });\n\
    \    std::vector<int> ch(n + 1, -1);\n    int s = 0, t = 0;\n    for (int _ =\
    \ 0; _ < 2; _++, s = --t, std::reverse(ord.begin(), ord.end())) {\n        for\
    \ (int& i : ord) {\n            for (; t >= s + 2; t--) {\n                auto\
    \ det = (P[ch[t - 1]] - P[ch[t - 2]]).det(P[i] - P[ch[t - 2]]);\n            \
    \    if (inclusive ? det >= 0 : det > 0) break;\n            }\n            ch[t++]\
    \ = i;\n        }\n    }\n    while (not inclusive and t >= 2 and P[ch[0]] ==\
    \ P[ch[t - 1]]) t--;\n    return {begin(ch), begin(ch) + t};\n}\n\n}  // namespace\
    \ geometry\n"
  code: "#pragma once\n#include <algorithm>\n#include <numeric>\n#include <vector>\n\
    #include \"Point.hpp\"\n\nnamespace geometry {\n\ntemplate <typename T> std::vector<int>\
    \ convex_hull(const std::vector<Point<T>>& P, bool inclusive = false) {\n    int\
    \ n = P.size();\n    if (n == 0) return {};\n    if (n == 1) return {0};\n   \
    \ if (n == 2) return (P[0] != P[1] or inclusive ? std::vector<int>{0, 1} : std::vector<int>{0});\n\
    \    std::vector<int> ord(n);\n    std::iota(ord.begin(), ord.end(), 0);\n   \
    \ std::sort(ord.begin(), ord.end(), [&](int l, int r) { return P[l] < P[r]; });\n\
    \    std::vector<int> ch(n + 1, -1);\n    int s = 0, t = 0;\n    for (int _ =\
    \ 0; _ < 2; _++, s = --t, std::reverse(ord.begin(), ord.end())) {\n        for\
    \ (int& i : ord) {\n            for (; t >= s + 2; t--) {\n                auto\
    \ det = (P[ch[t - 1]] - P[ch[t - 2]]).det(P[i] - P[ch[t - 2]]);\n            \
    \    if (inclusive ? det >= 0 : det > 0) break;\n            }\n            ch[t++]\
    \ = i;\n        }\n    }\n    while (not inclusive and t >= 2 and P[ch[0]] ==\
    \ P[ch[t - 1]]) t--;\n    return {begin(ch), begin(ch) + t};\n}\n\n}  // namespace\
    \ geometry\n"
  dependsOn:
  - src/geometry/Point.hpp
  isVerificationFile: false
  path: src/geometry/convex_hull.hpp
  requiredBy: []
  timestamp: '2024-05-22 03:00:55+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_4_A.test.cpp
  - test/yosupo/static_convex_hull.test.cpp
documentation_of: src/geometry/convex_hull.hpp
layout: document
title: "\u51F8\u5305"
---
