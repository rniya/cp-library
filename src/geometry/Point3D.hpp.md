---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/geometry/Point3D.hpp\"\n\nnamespace geometry {\n\ntemplate\
    \ <typename T> struct Point3D {\n    static T EPS;\n\n    static void set_eps(T\
    \ eps) { EPS = eps; }\n\n    T x, y, z;\n\n    Point3D() {}\n\n    Point3D(T x,\
    \ T y, T z) : x(x), y(y), z(z) {}\n\n    Point3D operator+(const Point3D& p) const\
    \ { return Point(x + p.x, y + p.y, z + p.z); }\n\n    Point3D operator-(const\
    \ Point3D& p) const { return Point(x - p.x, y - p.y, z - p.z); }\n\n    Point3D\
    \ operator*(T t) const { return Point(x * t, y * t, z * t); }\n\n    Point3D operator/(T\
    \ t) const { return Point(x / t, y / t, z / t); }\n\n    bool operator==(const\
    \ Point3D& p) const { return x == p.x and y == p.y and z == p.z; }\n\n    bool\
    \ operator!=(const Point3D& p) const { return not((*this) == p); }\n\n    bool\
    \ operator<(const Point3D& p) const { return x != p.x ? x < p.x : y != p.y ? y\
    \ < p.y : z < p.z; }\n\n    friend std::istream& operator>>(std::istream& is,\
    \ Point3D& p) { return is >> p.x >> p.y >> p.z; }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Point3D& p) {\n        return os << p.x <<\
    \ ' ' << p.y << ' ' << p.z;\n    }\n\n    T norm() { return std::sqrt(x * x +\
    \ y * y + z * z); }\n\n    T norm2() { return x * x + y * y + z * z; }\n\n   \
    \ T dot(const Point3D& p) { return x * p.x + y * p.y + z * p.z; }\n\n    Point3D\
    \ cross(const Point3D& p) { return Point3D(y * p.z - z * p.y, z * p.x - x * p.z,\
    \ x * p.y - y * p.x); }\n\n    Point3D unit() { return *this / norm(); }\n};\n\
    \ntemplate <> double Point3D<double>::EPS = 1e-9;\ntemplate <> long double Point3D<long\
    \ double>::EPS = 1e-12;\ntemplate <> int Point3D<int>::EPS = 0;\ntemplate <> long\
    \ long Point3D<long long>::EPS = 0;\n\n}  // namespace geometry\n"
  code: "#pragma once\n\nnamespace geometry {\n\ntemplate <typename T> struct Point3D\
    \ {\n    static T EPS;\n\n    static void set_eps(T eps) { EPS = eps; }\n\n  \
    \  T x, y, z;\n\n    Point3D() {}\n\n    Point3D(T x, T y, T z) : x(x), y(y),\
    \ z(z) {}\n\n    Point3D operator+(const Point3D& p) const { return Point(x +\
    \ p.x, y + p.y, z + p.z); }\n\n    Point3D operator-(const Point3D& p) const {\
    \ return Point(x - p.x, y - p.y, z - p.z); }\n\n    Point3D operator*(T t) const\
    \ { return Point(x * t, y * t, z * t); }\n\n    Point3D operator/(T t) const {\
    \ return Point(x / t, y / t, z / t); }\n\n    bool operator==(const Point3D& p)\
    \ const { return x == p.x and y == p.y and z == p.z; }\n\n    bool operator!=(const\
    \ Point3D& p) const { return not((*this) == p); }\n\n    bool operator<(const\
    \ Point3D& p) const { return x != p.x ? x < p.x : y != p.y ? y < p.y : z < p.z;\
    \ }\n\n    friend std::istream& operator>>(std::istream& is, Point3D& p) { return\
    \ is >> p.x >> p.y >> p.z; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Point3D& p) {\n        return os << p.x << ' ' << p.y << ' ' << p.z;\n\
    \    }\n\n    T norm() { return std::sqrt(x * x + y * y + z * z); }\n\n    T norm2()\
    \ { return x * x + y * y + z * z; }\n\n    T dot(const Point3D& p) { return x\
    \ * p.x + y * p.y + z * p.z; }\n\n    Point3D cross(const Point3D& p) { return\
    \ Point3D(y * p.z - z * p.y, z * p.x - x * p.z, x * p.y - y * p.x); }\n\n    Point3D\
    \ unit() { return *this / norm(); }\n};\n\ntemplate <> double Point3D<double>::EPS\
    \ = 1e-9;\ntemplate <> long double Point3D<long double>::EPS = 1e-12;\ntemplate\
    \ <> int Point3D<int>::EPS = 0;\ntemplate <> long long Point3D<long long>::EPS\
    \ = 0;\n\n}  // namespace geometry"
  dependsOn: []
  isVerificationFile: false
  path: src/geometry/Point3D.hpp
  requiredBy: []
  timestamp: '2023-11-03 03:12:33+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/geometry/Point3D.hpp
layout: document
title: Point (3D)
---
