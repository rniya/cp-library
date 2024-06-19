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
  - icon: ':heavy_check_mark:'
    path: src/geometry/convex_diameter.hpp
    title: Convex Diameter
  - icon: ':heavy_check_mark:'
    path: src/geometry/convex_hull.hpp
    title: Convex Hull
  _extendedRequiredBy: []
  _extendedVerifiedWith:
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
    \    }\n    return argmax;\n}\n\n}  // namespace geometry\n#line 3 \"src/geometry/convex_hull.hpp\"\
    \n#include <numeric>\n#line 6 \"src/geometry/convex_hull.hpp\"\n\nnamespace geometry\
    \ {\n\ntemplate <typename T> std::vector<int> convex_hull(const std::vector<Point<T>>&\
    \ P, bool inclusive = false) {\n    int n = P.size();\n    if (n == 0) return\
    \ {};\n    if (n == 1) return {0};\n    if (n == 2) return (P[0] != P[1] or inclusive\
    \ ? std::vector<int>{0, 1} : std::vector<int>{0});\n    std::vector<int> ord(n);\n\
    \    std::iota(ord.begin(), ord.end(), 0);\n    std::sort(ord.begin(), ord.end(),\
    \ [&](int l, int r) { return P[l] < P[r]; });\n    std::vector<int> ch(n + 1,\
    \ -1);\n    int s = 0, t = 0;\n    for (int _ = 0; _ < 2; _++, s = --t, std::reverse(ord.begin(),\
    \ ord.end())) {\n        for (int& i : ord) {\n            for (; t >= s + 2;\
    \ t--) {\n                auto det = (P[ch[t - 1]] - P[ch[t - 2]]).det(P[i] -\
    \ P[ch[t - 2]]);\n                if (inclusive ? det >= 0 : det > 0) break;\n\
    \            }\n            ch[t++] = i;\n        }\n    }\n    while (not inclusive\
    \ and t >= 2 and P[ch[0]] == P[ch[t - 1]]) t--;\n    return {begin(ch), begin(ch)\
    \ + t};\n}\n\n}  // namespace geometry\n#line 4 \"src/geometry/furthest_pair.hpp\"\
    \n\nnamespace geometry {\n\ntemplate <typename T> std::pair<int, int> furthest_pair(const\
    \ std::vector<Point<T>>& P) {\n    int n = P.size();\n    assert(n >= 2);\n  \
    \  auto convex = convex_hull(P);\n    n = convex.size();\n    if (n == 1) return\
    \ {0, 1};\n    if (n == 2) return {convex[0], convex[1]};\n    Polygon<T> Q;\n\
    \    for (int i : convex) Q.emplace_back(P[i]);\n    auto [i, j] = convex_diameter(Q);\n\
    \    return {convex[i], convex[j]};\n}\n\n}  // namespace geometry\n"
  code: "#pragma once\n#include \"convex_diameter.hpp\"\n#include \"convex_hull.hpp\"\
    \n\nnamespace geometry {\n\ntemplate <typename T> std::pair<int, int> furthest_pair(const\
    \ std::vector<Point<T>>& P) {\n    int n = P.size();\n    assert(n >= 2);\n  \
    \  auto convex = convex_hull(P);\n    n = convex.size();\n    if (n == 1) return\
    \ {0, 1};\n    if (n == 2) return {convex[0], convex[1]};\n    Polygon<T> Q;\n\
    \    for (int i : convex) Q.emplace_back(P[i]);\n    auto [i, j] = convex_diameter(Q);\n\
    \    return {convex[i], convex[j]};\n}\n\n}  // namespace geometry"
  dependsOn:
  - src/geometry/convex_diameter.hpp
  - src/geometry/Polygon.hpp
  - src/geometry/ccw.hpp
  - src/geometry/Point.hpp
  - src/geometry/convex_hull.hpp
  isVerificationFile: false
  path: src/geometry/furthest_pair.hpp
  requiredBy: []
  timestamp: '2024-06-20 02:02:41+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/furthest_pair.test.cpp
documentation_of: src/geometry/furthest_pair.hpp
layout: document
title: Furthest Pair
---
