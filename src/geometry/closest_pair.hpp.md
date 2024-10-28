---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/geometry/Point.hpp
    title: Point
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/closest_pair.test.cpp
    title: test/yosupo/closest_pair.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/closest_pair.hpp\"\n#include <algorithm>\n\
    #include <limits>\n#include <numeric>\n#include <tuple>\n#include <utility>\n\
    #include <vector>\n#line 2 \"src/geometry/Point.hpp\"\n#include <cassert>\n#include\
    \ <cmath>\n#include <iostream>\n#include <type_traits>\n\nnamespace geometry {\n\
    \ntemplate <typename T> struct Point {\n    static T EPS;\n\n    static void set_eps(T\
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
    \ }\n\n}  // namespace geometry\n#line 9 \"src/geometry/closest_pair.hpp\"\n\n\
    namespace geometry {\n\ntemplate <typename T> std::tuple<int, int, T> closest_pair(std::vector<Point<T>>\
    \ P) {\n    int n = P.size();\n    if (n == 1) return {0, 0, 0};\n    std::vector<int>\
    \ ord(n);\n    std::iota(begin(ord), end(ord), 0);\n    std::sort(begin(ord),\
    \ end(ord), [&](int p, int q) { return P[p] < P[q]; });\n    T inf = std::numeric_limits<T>::max(),\
    \ min_dist = inf;\n    std::pair<int, int> ans{-1, -1};\n\n    auto dfs = [&](auto\
    \ self, int l, int r) -> T {\n        if (r - l <= 1) return inf;\n        int\
    \ mid = (l + r) >> 1;\n        auto x_mid = P[ord[mid]].x;\n        auto res =\
    \ std::min(self(self, l, mid), self(self, mid, r));\n        std::inplace_merge(begin(ord)\
    \ + l, begin(ord) + mid, begin(ord) + r,\n                           [&](int p,\
    \ int q) { return P[p].y < P[q].y; });\n        std::vector<int> tmp;\n      \
    \  for (int i = l; i < r; i++) {\n            if (sgn(std::abs(P[ord[i]].x - x_mid)\
    \ - res) >= 0) continue;\n            for (int j = int(tmp.size()) - 1; j >= 0;\
    \ j--) {\n                auto d = P[ord[i]] - P[tmp[j]];\n                if\
    \ (sgn(d.y - res) >= 0) break;\n                if (d.norm() < res) {\n      \
    \              res = d.norm();\n                    if (d.norm() < min_dist) {\n\
    \                        min_dist = d.norm();\n                        ans = {ord[i],\
    \ tmp[j]};\n                    }\n                }\n            }\n        \
    \    tmp.emplace_back(ord[i]);\n        }\n        return res;\n    };\n    dfs(dfs,\
    \ 0, n);\n    return {ans.first, ans.second, min_dist};\n}\n\n}  // namespace\
    \ geometry\n"
  code: "#pragma once\n#include <algorithm>\n#include <limits>\n#include <numeric>\n\
    #include <tuple>\n#include <utility>\n#include <vector>\n#include \"Point.hpp\"\
    \n\nnamespace geometry {\n\ntemplate <typename T> std::tuple<int, int, T> closest_pair(std::vector<Point<T>>\
    \ P) {\n    int n = P.size();\n    if (n == 1) return {0, 0, 0};\n    std::vector<int>\
    \ ord(n);\n    std::iota(begin(ord), end(ord), 0);\n    std::sort(begin(ord),\
    \ end(ord), [&](int p, int q) { return P[p] < P[q]; });\n    T inf = std::numeric_limits<T>::max(),\
    \ min_dist = inf;\n    std::pair<int, int> ans{-1, -1};\n\n    auto dfs = [&](auto\
    \ self, int l, int r) -> T {\n        if (r - l <= 1) return inf;\n        int\
    \ mid = (l + r) >> 1;\n        auto x_mid = P[ord[mid]].x;\n        auto res =\
    \ std::min(self(self, l, mid), self(self, mid, r));\n        std::inplace_merge(begin(ord)\
    \ + l, begin(ord) + mid, begin(ord) + r,\n                           [&](int p,\
    \ int q) { return P[p].y < P[q].y; });\n        std::vector<int> tmp;\n      \
    \  for (int i = l; i < r; i++) {\n            if (sgn(std::abs(P[ord[i]].x - x_mid)\
    \ - res) >= 0) continue;\n            for (int j = int(tmp.size()) - 1; j >= 0;\
    \ j--) {\n                auto d = P[ord[i]] - P[tmp[j]];\n                if\
    \ (sgn(d.y - res) >= 0) break;\n                if (d.norm() < res) {\n      \
    \              res = d.norm();\n                    if (d.norm() < min_dist) {\n\
    \                        min_dist = d.norm();\n                        ans = {ord[i],\
    \ tmp[j]};\n                    }\n                }\n            }\n        \
    \    tmp.emplace_back(ord[i]);\n        }\n        return res;\n    };\n    dfs(dfs,\
    \ 0, n);\n    return {ans.first, ans.second, min_dist};\n}\n\n}  // namespace\
    \ geometry"
  dependsOn:
  - src/geometry/Point.hpp
  isVerificationFile: false
  path: src/geometry/closest_pair.hpp
  requiredBy: []
  timestamp: '2023-10-04 02:32:44+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/closest_pair.test.cpp
  - test/aoj/CGL_5_A.test.cpp
documentation_of: src/geometry/closest_pair.hpp
layout: document
title: Closest Pair
---
