---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    document_title: "3 \u6B21\u5143\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA"
    links: []
  bundledCode: "#line 2 \"geometry/geometry3D.hpp\"\n#include <cmath>\n#include <iostream>\n\
    \nnamespace geometry3D {\n\nusing Real = double;\nconstexpr Real EPS = 1e-8;\n\
    constexpr Real PI = 3.14159265358979323846L;\n\ninline int sgn(Real x) { return\
    \ x < -EPS ? -1 : x > EPS ? 1 : 0; }\n\ninline int compare(Real a, Real b) { return\
    \ sgn(a - b); }\n\ninline bool equals(Real a, Real b) { return compare(a, b) ==\
    \ 0; }\n\nstruct Point3D {\n    Real x, y, z;\n\n    Point3D() {}\n\n    Point3D(Real\
    \ x, Real y, Real z) : x(x), y(y), z(z) {}\n\n    Point3D& operator+=(const Point3D&\
    \ p) {\n        x += p.x, y += p.y, z += p.z;\n        return *this;\n    }\n\n\
    \    Point3D& operator-=(const Point3D& p) {\n        x -= p.x, y -= p.y, z -=\
    \ p.z;\n        return *this;\n    }\n\n    Point3D& operator*=(const Real& k)\
    \ {\n        x *= k, y *= k, z *= k;\n        return *this;\n    }\n\n    Point3D&\
    \ operator/=(const Real& k) {\n        x /= k, y /= k, z /= k;\n        return\
    \ *this;\n    }\n\n    Point3D operator+(const Point3D& p) const { return Point3D(*this)\
    \ += p; }\n\n    Point3D operator-(const Point3D& p) const { return Point3D(*this)\
    \ -= p; }\n\n    Point3D operator*(const Real& k) const { return Point3D(*this)\
    \ *= k; }\n\n    Point3D operator/(const Real& k) const { return Point3D(*this)\
    \ /= k; }\n\n    Point3D operator-() const { return Point3D(-x, -y, -z); }\n\n\
    \    bool operator==(const Point3D& p) const { return equals(x, p.x) and equals(y,\
    \ p.y) and equals(z, p.z); }\n\n    bool operator!=(const Point3D& p) const {\
    \ return !((*this) == p); }\n\n    bool operator<(const Point3D& p) const { return\
    \ !equals(x, p.x) ? x < p.x : !equals(y, p.y) ? y < p.y : z < p.z; }\n\n    bool\
    \ operator>(const Point3D& p) const { return !equals(x, p.x) ? x > p.x : !equals(y,\
    \ p.y) ? y > p.y : z > p.z; }\n\n    friend std::istream& operator>>(std::istream&\
    \ is, Point3D& p) { return is >> p.x >> p.y >> p.z; }\n\n    friend std::ostream&\
    \ operator<<(std::ostream& os, const Point3D& p) {\n        return os << p.x <<\
    \ ' ' << p.y << ' ' << p.z;\n    }\n\n    Real norm() const { return x * x + y\
    \ * y + z * z; }\n\n    Real abs() const { return sqrt(norm()); }\n\n    Point3D\
    \ unit() const { return *this / abs(); }\n};\n\nReal dot(const Point3D& p, const\
    \ Point3D& q) { return p.x * q.x + p.y * q.y + p.z * q.z; }\n\nPoint3D cross(const\
    \ Point3D& p, const Point3D& q) {\n    return Point3D(p.y * q.z - p.z * q.y, p.z\
    \ * q.x - p.x * q.z, p.x * q.y - p.y * q.x);\n}\n\nstruct Segment3D {\n    Point3D\
    \ a, b;\n\n    Segment3D() {}\n\n    Segment3D(const Point3D& a, const Point3D&\
    \ b) : a(a), b(b) {}\n\n    friend std::istream& operator>>(std::istream& is,\
    \ Segment3D& s) { return is >> s.a >> s.b; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Segment3D& s) { return os << s.a << \" to \" << s.b; }\n};\n\nstruct\
    \ Sphere {\n    Point3D center;\n    Real radius;\n\n    Sphere() {}\n\n    Sphere(const\
    \ Point3D& center, const Real& radius) : center(center), radius(radius) {}\n\n\
    \    friend std::istream& operator>>(std::istream& is, Sphere& c) { return is\
    \ >> c.center >> c.radius; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, Sphere& c) { return os << c.center << ' ' << c.radius; }\n};\n\n}  // namespace\
    \ geometry3D\n\n/**\n * @brief 3 \u6B21\u5143\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\
    \u30EA\n */\n"
  code: "#pragma once\n#include <cmath>\n#include <iostream>\n\nnamespace geometry3D\
    \ {\n\nusing Real = double;\nconstexpr Real EPS = 1e-8;\nconstexpr Real PI = 3.14159265358979323846L;\n\
    \ninline int sgn(Real x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }\n\ninline\
    \ int compare(Real a, Real b) { return sgn(a - b); }\n\ninline bool equals(Real\
    \ a, Real b) { return compare(a, b) == 0; }\n\nstruct Point3D {\n    Real x, y,\
    \ z;\n\n    Point3D() {}\n\n    Point3D(Real x, Real y, Real z) : x(x), y(y),\
    \ z(z) {}\n\n    Point3D& operator+=(const Point3D& p) {\n        x += p.x, y\
    \ += p.y, z += p.z;\n        return *this;\n    }\n\n    Point3D& operator-=(const\
    \ Point3D& p) {\n        x -= p.x, y -= p.y, z -= p.z;\n        return *this;\n\
    \    }\n\n    Point3D& operator*=(const Real& k) {\n        x *= k, y *= k, z\
    \ *= k;\n        return *this;\n    }\n\n    Point3D& operator/=(const Real& k)\
    \ {\n        x /= k, y /= k, z /= k;\n        return *this;\n    }\n\n    Point3D\
    \ operator+(const Point3D& p) const { return Point3D(*this) += p; }\n\n    Point3D\
    \ operator-(const Point3D& p) const { return Point3D(*this) -= p; }\n\n    Point3D\
    \ operator*(const Real& k) const { return Point3D(*this) *= k; }\n\n    Point3D\
    \ operator/(const Real& k) const { return Point3D(*this) /= k; }\n\n    Point3D\
    \ operator-() const { return Point3D(-x, -y, -z); }\n\n    bool operator==(const\
    \ Point3D& p) const { return equals(x, p.x) and equals(y, p.y) and equals(z, p.z);\
    \ }\n\n    bool operator!=(const Point3D& p) const { return !((*this) == p); }\n\
    \n    bool operator<(const Point3D& p) const { return !equals(x, p.x) ? x < p.x\
    \ : !equals(y, p.y) ? y < p.y : z < p.z; }\n\n    bool operator>(const Point3D&\
    \ p) const { return !equals(x, p.x) ? x > p.x : !equals(y, p.y) ? y > p.y : z\
    \ > p.z; }\n\n    friend std::istream& operator>>(std::istream& is, Point3D& p)\
    \ { return is >> p.x >> p.y >> p.z; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Point3D& p) {\n        return os << p.x << ' ' << p.y << ' ' << p.z;\n\
    \    }\n\n    Real norm() const { return x * x + y * y + z * z; }\n\n    Real\
    \ abs() const { return sqrt(norm()); }\n\n    Point3D unit() const { return *this\
    \ / abs(); }\n};\n\nReal dot(const Point3D& p, const Point3D& q) { return p.x\
    \ * q.x + p.y * q.y + p.z * q.z; }\n\nPoint3D cross(const Point3D& p, const Point3D&\
    \ q) {\n    return Point3D(p.y * q.z - p.z * q.y, p.z * q.x - p.x * q.z, p.x *\
    \ q.y - p.y * q.x);\n}\n\nstruct Segment3D {\n    Point3D a, b;\n\n    Segment3D()\
    \ {}\n\n    Segment3D(const Point3D& a, const Point3D& b) : a(a), b(b) {}\n\n\
    \    friend std::istream& operator>>(std::istream& is, Segment3D& s) { return\
    \ is >> s.a >> s.b; }\n\n    friend std::ostream& operator<<(std::ostream& os,\
    \ const Segment3D& s) { return os << s.a << \" to \" << s.b; }\n};\n\nstruct Sphere\
    \ {\n    Point3D center;\n    Real radius;\n\n    Sphere() {}\n\n    Sphere(const\
    \ Point3D& center, const Real& radius) : center(center), radius(radius) {}\n\n\
    \    friend std::istream& operator>>(std::istream& is, Sphere& c) { return is\
    \ >> c.center >> c.radius; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, Sphere& c) { return os << c.center << ' ' << c.radius; }\n};\n\n}  // namespace\
    \ geometry3D\n\n/**\n * @brief 3 \u6B21\u5143\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\
    \u30EA\n */"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry3D.hpp
  requiredBy: []
  timestamp: '2021-10-10 15:55:16+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: geometry/geometry3D.hpp
layout: document
redirect_from:
- /library/geometry/geometry3D.hpp
- /library/geometry/geometry3D.hpp.html
title: "3 \u6B21\u5143\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA"
---
