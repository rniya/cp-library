---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_A.test.cpp
    title: test/aoj/CGL_1_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_B.test.cpp
    title: test/aoj/CGL_1_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_1_C.test.cpp
    title: test/aoj/CGL_1_C.test.cpp
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
    path: test/aoj/CGL_3_A.test.cpp
    title: test/aoj/CGL_3_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_B.test.cpp
    title: test/aoj/CGL_3_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_3_C.test.cpp
    title: test/aoj/CGL_3_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_A.test.cpp
    title: test/aoj/CGL_4_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_B.test.cpp
    title: test/aoj/CGL_4_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_4_C.test.cpp
    title: test/aoj/CGL_4_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_5_A.test.cpp
    title: test/aoj/CGL_5_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_A.test.cpp
    title: test/aoj/CGL_7_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_B.test.cpp
    title: test/aoj/CGL_7_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_C.test.cpp
    title: test/aoj/CGL_7_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_D.test.cpp
    title: test/aoj/CGL_7_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_E.test.cpp
    title: test/aoj/CGL_7_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_F.test.cpp
    title: test/aoj/CGL_7_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_G.test.cpp
    title: test/aoj/CGL_7_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_H.test.cpp
    title: test/aoj/CGL_7_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/CGL_7_I.test.cpp
    title: test/aoj/CGL_7_I.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/geometry/geometry.md
    document_title: "2 \u6B21\u5143\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA"
    links: []
  bundledCode: "#line 2 \"geometry/geometry.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <cmath>\n#include <iostream>\n#include <tuple>\n#include\
    \ <vector>\n\nnamespace geometry {\nusing Real = double;  // change this flexibly\
    \ if you want more precision\nconstexpr Real EPS = 1e-8;\nconstexpr Real PI =\
    \ 3.14159265358979323846L;\n\ninline int sgn(Real x) { return x < -EPS ? -1 :\
    \ x > EPS ? 1 : 0; }\n\ninline int compare(Real a, Real b) { return sgn(a - b);\
    \ }\n\ninline bool equals(Real a, Real b) { return compare(a, b) == 0; }\n\nstruct\
    \ Point {\n    Real x, y;\n\n    Point() {}\n\n    Point(Real x, Real y) : x(x),\
    \ y(y) {}\n\n    Point& operator+=(const Point& p) {\n        x += p.x, y += p.y;\n\
    \        return *this;\n    }\n\n    Point& operator-=(const Point& p) {\n   \
    \     x -= p.x, y -= p.y;\n        return *this;\n    }\n\n    Point& operator*=(const\
    \ Real& k) {\n        x *= k, y *= k;\n        return *this;\n    }\n\n    Point&\
    \ operator/=(const Real& k) {\n        x /= k, y /= k;\n        return *this;\n\
    \    }\n\n    Point operator+(const Point& p) const { return Point(*this) += p;\
    \ }\n\n    Point operator-(const Point& p) const { return Point(*this) -= p; }\n\
    \n    Point operator*(const Real& k) const { return Point(*this) *= k; }\n\n \
    \   Point operator/(const Real& k) const { return Point(*this) /= k; }\n\n   \
    \ Point operator*(const Point& p) const { return Point(x * p.x - y * p.y, x *\
    \ p.y + y * p.x); }\n\n    Point operator-() const { return Point(-x, -y); }\n\
    \n    bool operator==(const Point& p) const { return (compare(x, p.x) == 0 &&\
    \ compare(y, p.y) == 0); }\n\n    bool operator!=(const Point& p) const { return\
    \ !(*this == p); }\n\n    bool operator<(const Point& p) const {\n        return\
    \ compare(x, p.x) < 0 || (compare(x, p.x) == 0 && compare(y, p.y) < 0);\n    }\n\
    \n    bool operator>(const Point& p) const {\n        return compare(x, p.x) >\
    \ 0 || (compare(x, p.x) == 0 && compare(y, p.y) > 0);\n    }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, Point& p) { return is >> p.x >> p.y; }\n\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const Point& p) { return os << p.x\
    \ << ' ' << p.y; }\n\n    Real norm() const { return x * x + y * y; }\n\n    Real\
    \ abs() const { return std::hypot(x, y); }\n\n    Real arg() const { return std::atan2(y,\
    \ x); }\n\n    Point normal() const { return Point(-y, x); }\n\n    Point unit()\
    \ const { return *this / abs(); }\n\n    Point conj() const { return Point(x,\
    \ -y); }\n\n    Point rotate(Real theta) const {\n        return Point(x * std::cos(theta)\
    \ - y * std::sin(theta), x * std::sin(theta) + y * std::cos(theta));\n    }\n\
    };\n\nPoint polar(const Real& r, const Real& theta) { return Point(cos(theta),\
    \ sin(theta)) * r; }\n\nReal dot(const Point& p, const Point& q) { return p.x\
    \ * q.x + p.y * q.y; }\n\nReal cross(const Point& p, const Point& q) { return\
    \ p.x * q.y - p.y * q.x; }\n\nReal distance(const Point& p, const Point& q) {\
    \ return (p - q).abs(); }\n\nstruct Line {\n    Point a, b;\n\n    Line() {}\n\
    \n    Line(const Point& a, const Point& b) : a(a), b(b) {}\n\n    Line(const Real&\
    \ A, const Real& B, const Real& C) {  // Ax + By = c\n        if (equals(A, 0))\
    \ {\n            assert(!equals(B, 0));\n            a = Point(0, C / B);\n  \
    \          b = Point(1, C / B);\n        } else if (equals(B, 0)) {\n        \
    \    a = Point(C / A, 0);\n            b = Point(C / A, 1);\n        } else {\n\
    \            a = Point(0, C / B);\n            b = Point(C / A, 0);\n        }\n\
    \    }\n\n    Point diff() const { return b - a; }\n\n    friend std::istream&\
    \ operator>>(std::istream& is, Line& l) { return is >> l.a >> l.b; }\n\n    friend\
    \ std::ostream& operator<<(std::ostream& os, const Line& l) { return os << l.a\
    \ << \" to \" << l.b; }\n};\n\nstruct Segment : Line {\n    Segment() {}\n\n \
    \   Segment(Point a, Point b) : Line(a, b) {}\n\n    Real length() const { return\
    \ diff().abs(); }\n};\n\nPoint proj(const Line& l, const Point& p) {\n    Point\
    \ v = l.diff().unit();\n    return l.a + v * dot(v, p - l.a);\n}\n\nPoint refl(const\
    \ Line& l, const Point& p) {\n    Point h = proj(l, p);\n    return h + (h - p);\n\
    }\n\nbool orthogonal(const Line& l, const Line& m) { return equals(dot(l.diff(),\
    \ m.diff()), 0); }\n\nbool parallel(const Line& l, const Line& m) { return equals(cross(l.diff(),\
    \ m.diff()), 0); }\n\nenum Position { COUNTER_CLOCKWISE = +1, CLOCKWISE = -1,\
    \ ONLINE_BACK = +2, ONLINE_FRONT = -2, ON_SEGMENT = 0 };\n\nPosition ccw(const\
    \ Point& a, Point b, Point c) {\n    b -= a, c -= a;\n    if (sgn(cross(b, c))\
    \ == +1) return COUNTER_CLOCKWISE;\n    if (sgn(cross(b, c)) == -1) return CLOCKWISE;\n\
    \    if (sgn(dot(b, c)) == -1) return ONLINE_BACK;\n    if (compare(b.norm(),\
    \ c.norm()) == -1) return ONLINE_FRONT;\n    return ON_SEGMENT;\n}\n\nbool intersect(const\
    \ Line& l, const Point& p) { return abs(ccw(l.a, l.b, p)) != 1; }\n\nbool intersect(const\
    \ Line& l, const Line& m) {\n    Real A = cross(l.diff(), m.diff()), B = cross(l.diff(),\
    \ l.b - m.a);\n    if (equals(A, 0) && equals(B, 0)) return true;\n    return\
    \ !parallel(l, m);\n}\n\nbool intersect(const Line& l, const Segment& s) {\n \
    \   return sgn(cross(l.diff(), s.a - l.a)) * sgn(cross(l.diff(), s.b - l.a)) <=\
    \ 0;\n}\n\nbool intersect(const Segment& s, const Point& p) { return ccw(s.a,\
    \ s.b, p) == ON_SEGMENT; }\n\nbool intersect(const Segment& s, const Segment&\
    \ t) {\n    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b,\
    \ s.a) * ccw(t.a, t.b, s.b) <= 0;\n}\n\nReal distance(const Line& l, const Point&\
    \ p) { return distance(p, proj(l, p)); }\n\nReal distance(const Line& l, const\
    \ Line& m) { return intersect(l, m) ? 0 : distance(l, m.a); }\n\nReal distance(const\
    \ Line& l, const Segment& s) {\n    return intersect(l, s) ? 0 : std::min(distance(l,\
    \ s.a), distance(l, s.b));\n}\n\nReal distance(const Segment& s, const Point&\
    \ p) {\n    Point h = proj(s, p);\n    return intersect(s, h) ? distance(p, h)\
    \ : std::min(distance(p, s.a), distance(p, s.b));\n}\n\nReal distance(const Segment&\
    \ s, const Segment& t) {\n    if (intersect(s, t)) return 0;\n    return std::min({distance(s,\
    \ t.a), distance(s, t.b), distance(t, s.a), distance(t, s.b)});\n}\n\nPoint crosspoint(const\
    \ Line& l, const Line& m) {\n    assert(intersect(l, m));\n    Real A = cross(l.diff(),\
    \ m.diff()), B = cross(l.diff(), l.b - m.a);\n    if (equals(A, 0) && equals(B,\
    \ 0)) return m.a;\n    return m.a + m.diff() * B / A;\n}\n\nstruct Circle {\n\
    \    Point center;\n    Real radius;\n\n    Circle() {}\n\n    Circle(const Point&\
    \ center, const Real& radius) : center(center), radius(radius) {}\n\n    friend\
    \ std::istream& operator>>(std::istream& is, Circle& c) { return is >> c.center\
    \ >> c.radius; }\n\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ Circle& c) { return os << c.center << ' ' << c.radius; }\n};\n\nbool intersect(const\
    \ Circle& c, const Line& l) { return compare(c.radius, distance(l, c.center))\
    \ >= 0; }\n\nint intersect(const Circle& c, const Segment& s) {\n    Point h =\
    \ proj(s, c.center);\n    if (compare(distance(c.center, h), c.radius) > 0) return\
    \ 0;\n    Real d1 = (c.center - s.a).abs(), d2 = (c.center - s.b).abs();\n   \
    \ if (compare(c.radius, d1) >= 0 && compare(c.radius, d2) >= 0) return 0;\n  \
    \  if (compare(c.radius, d1) * compare(c.radius, d2) < 0) return 1;\n    if (sgn(dot(s.a\
    \ - h, s.b - h)) < 0) return 2;\n    return 0;\n}\n\nstd::vector<Point> crosspoint(const\
    \ Circle& c, const Line& l) {\n    Point h = proj(l, c.center);\n    Real d =\
    \ c.radius * c.radius - (c.center - h).norm();\n    if (sgn(d) < 0) return {};\n\
    \    if (sgn(d) == 0) return {h};\n    Point v = l.diff().unit() * sqrt(d);\n\
    \    return {h - v, h + v};\n}\n\nstd::vector<Point> crosspoint(const Circle&\
    \ c, const Segment& s) {\n    int num = intersect(c, s);\n    if (num == 0) return\
    \ {};\n    auto res = crosspoint(c, Line(s.a, s.b));\n    if (num == 2) return\
    \ res;\n    if (sgn(dot(s.a - res[0], s.b - res[0])) > 0) std::swap(res[0], res[1]);\n\
    \    return {res[0]};\n}\n\n// requirement : c != d\nstd::vector<Point> crosspoint(const\
    \ Circle& c1, const Circle& c2) {\n    Real r1 = c1.radius, r2 = c2.radius;\n\
    \    if (r1 < r2) return crosspoint(c2, c1);\n    Real d = distance(c1.center,\
    \ c2.center);\n    if (compare(d, r1 + r2) > 0 || compare(d, r1 - r2) < 0) return\
    \ {};\n    Real alpha = std::acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));\n\
    \    Real theta = (c2.center - c1.center).arg();\n    Point p = c1.center + polar(r1,\
    \ theta + alpha);\n    Point q = c1.center + polar(r1, theta - alpha);\n    if\
    \ (p == q) return {p};\n    return {p, q};\n}\n\nReal commonarea(Circle c1, Circle\
    \ c2) {\n    Real r1 = c1.radius, r2 = c2.radius;\n    Real d = (c1.center - c2.center).abs();\n\
    \    if (compare(r1 + r2, d) <= 0) return 0;\n    if (compare(std::fabs(r1 - r2),\
    \ d) >= 0) return PI * min(r1, r2) * min(r1, r2);\n    Real res = 0;\n    for\
    \ (int _ = 0; _ < 2; _++) {\n        r1 = c1.radius, r2 = c2.radius;\n       \
    \ Real cosine = (d * d + r1 * r1 - r2 * r2) / (2 * d * r1);\n        Real theta\
    \ = std::acos(cosine) * 2;\n        res += (theta - std::sin(theta)) * r1 * r1\
    \ / 2;\n        swap(c1, c2);\n    }\n    return res;\n}\n\nLine bisector(const\
    \ Point& p, const Point& q) {\n    Point c = (p + q) * 0.5;\n    Point v = (q\
    \ - p).normal();\n    return Line(c - v, c + v);\n}\n\nCircle circumcircle(Point\
    \ a, Point b, const Point& c) {\n    Point center = crosspoint(bisector(a, c),\
    \ bisector(b, c));\n    return Circle(center, distance(c, center));\n}\n\nCircle\
    \ incircle(const Point& a, const Point& b, const Point& c) {\n    Real A = (b\
    \ - c).abs(), B = (c - a).abs(), C = (a - b).abs();\n    Point center = (a * A\
    \ + b * B + c * C) / (A + B + C);\n    return Circle(center, distance(Segment(a,\
    \ b), center));\n}\n\nstd::vector<Point> center_given_radius(const Point& a, const\
    \ Point& b, const Real& r) {\n    Point m = (b - a) * 0.5;\n    Real d1 = m.abs();\n\
    \    if (equals(d1, 0) || d1 > r) return {};\n    Real d2 = sqrt(r * r - d1 *\
    \ d1);\n    Point n = m.normal() * d2 / d1;\n    Point p = a + m - n, q = a +\
    \ m + n;\n    if (p == q) return {p};\n    return {p, q};\n}\n\nint count_tangent(const\
    \ Circle& c1, const Circle& c2) {\n    Real r1 = c1.radius, r2 = c2.radius;\n\
    \    if (r1 < r2) return count_tangent(c2, c1);\n    Real d = distance(c1.center,\
    \ c2.center);\n    if (compare(d, r1 + r2) > 0) return 4;\n    if (compare(d,\
    \ r1 + r2) == 0) return 3;\n    if (compare(d, r1 - r2) > 0) return 2;\n    if\
    \ (compare(d, r1 - r2) == 0) return 1;\n    return 0;\n}\n\nstd::vector<Point>\
    \ tangent_to_circle(const Circle& c, const Point& p) {\n    return crosspoint(c,\
    \ Circle(p, sqrt((c.center - p).norm() - c.radius * c.radius)));\n}\n\nstd::vector<Line>\
    \ common_tangent(const Circle& c1, const Circle& c2) {\n    if (c1.radius < c2.radius)\
    \ return common_tangent(c2, c1);\n    std::vector<Line> res;\n    Real g = distance(c1.center,\
    \ c2.center);\n    if (equals(g, 0)) return res;\n    Point u = (c2.center - c1.center)\
    \ / g, v = u.normal();\n    for (int s : {-1, 1}) {\n        Real h = (c1.radius\
    \ + c2.radius * s) / g;\n        if (equals(1 - h * h, 0))\n            res.emplace_back(c1.center\
    \ + u * c1.radius, c1.center + (u + v) * c1.radius);\n        else if (compare(1\
    \ - h * h, 0) > 0) {\n            Point U = u * h, V = v * std::sqrt(1 - h * h);\n\
    \            res.emplace_back(c1.center + (U + V) * c1.radius, c2.center - (U\
    \ + V) * c2.radius * s);\n            res.emplace_back(c1.center + (U - V) * c1.radius,\
    \ c2.center - (U - V) * c2.radius * s);\n        }\n    }\n    return res;\n}\n\
    \nenum Contain { OUT, ON, IN };\n\nstruct Polygon : std::vector<Point> {\n   \
    \ using std::vector<Point>::vector;\n\n    Polygon(int n) : std::vector<Point>(n)\
    \ {}\n\n    std::vector<Segment> segments() const {\n        assert(size() > 1);\n\
    \        std::vector<Segment> segs;\n        for (size_t i = 0; i < size(); i++)\
    \ segs.emplace_back((*this)[i], (*this)[(i + 1) % size()]);\n        return segs;\n\
    \    }\n\n    Real area() const {\n        Real sum = 0;\n        for (size_t\
    \ i = 0; i < size(); i++) sum += cross((*this)[i], (*this)[(i + 1) % size()]);\n\
    \        return std::abs(sum) / 2;\n    }\n\n    bool is_convex(bool accept_on_segment\
    \ = true) const {\n        int n = size();\n        for (int i = 0; i < n; i++)\
    \ {\n            if (accept_on_segment) {\n                if (ccw((*this)[i],\
    \ (*this)[(i + 1) % n], (*this)[(i + 2) % n]) == CLOCKWISE) {\n              \
    \      return false;\n                }\n            } else {\n              \
    \  if (ccw((*this)[i], (*this)[(i + 1) % n], (*this)[(i + 2) % n]) != COUNTER_CLOCKWISE)\
    \ {\n                    return false;\n                }\n            }\n   \
    \     }\n        return true;\n    }\n};\n\nContain contain(const Polygon& P,\
    \ const Point& p) {\n    bool in = false;\n    for (size_t i = 0; i < P.size();\
    \ i++) {\n        if (ccw(P[i], P[(i + 1) % P.size()], p) == ON_SEGMENT) return\
    \ ON;\n        Point a = P[i] - p, b = P[(i + 1) % P.size()] - p;\n        if\
    \ (a.y > b.y) std::swap(a, b);\n        if (sgn(a.y) <= 0 && sgn(b.y) > 0 && sgn(cross(a,\
    \ b)) < 0) in = !in;\n    }\n    return in ? IN : OUT;\n}\n\nContain contain(const\
    \ Circle& c, const Point& p) {\n    Real d = distance(c.center, p);\n    int cp\
    \ = compare(d, c.radius);\n    if (cp > 0) return OUT;\n    if (cp < 0) return\
    \ IN;\n    return ON;\n}\n\nPolygon convex_hull(Polygon& P, bool accept_on_segment\
    \ = false) {\n    int n = P.size(), k = 0;\n    if (n <= 2) return P;\n    std::sort(P.begin(),\
    \ P.end());\n    Polygon ch(n * 2);\n    auto check = [&](int i) {\n        if\
    \ (accept_on_segment) return ccw(ch[k - 2], ch[k - 1], P[i]) == CLOCKWISE;\n \
    \       return ccw(ch[k - 2], ch[k - 1], P[i]) != COUNTER_CLOCKWISE;\n    };\n\
    \    for (int i = 0; i < n; ch[k++] = P[i++]) {\n        while (k >= 2 && check(i))\
    \ {\n            k--;\n        }\n    }\n    for (int i = n - 2, t = k + 1; i\
    \ >= 0; ch[k++] = P[i--]) {\n        while (k >= t && check(i)) {\n          \
    \  k--;\n        }\n    }\n    ch.resize(k - 1);\n    int start = 0;\n    for\
    \ (int i = 1; i < k - 1; i++) {\n        if (equals(ch[i].y, ch[start].y) ? ch[i].x\
    \ < ch[start].x : ch[i].y < ch[start].y) {\n            start = i;\n        }\n\
    \    }\n    std::rotate(ch.begin(), ch.begin() + start, ch.end());\n    return\
    \ ch;\n}\n\nstd::tuple<int, int, Real> convex_diameter(const Polygon& convex)\
    \ {\n    assert(convex.is_convex());\n    int n = convex.size();\n    Real max_dist\
    \ = -1;\n    std::pair<int, int> argmax = {-1, -1};\n    for (int i = 0, j = 0;\
    \ i < n; i++) {\n        while (j + 1 < n && distance(convex[i], convex[j + 1])\
    \ > distance(convex[i], convex[j])) j++;\n        double cur_dist = distance(convex[i],\
    \ convex[j]);\n        if (max_dist < cur_dist) {\n            max_dist = cur_dist;\n\
    \            argmax = {i, j};\n        }\n    }\n    return {argmax.first, argmax.second,\
    \ max_dist};\n}\n\nPolygon convex_cut(const Polygon& convex, const Line& l) {\n\
    \    assert(convex.is_convex());\n    int n = convex.size();\n    Polygon res;\n\
    \    for (int i = 0; i < n; i++) {\n        const Point& cur = convex[i];\n  \
    \      const Point& nxt = convex[(i + 1) % n];\n        if (ccw(l.a, l.b, cur)\
    \ != CLOCKWISE) res.emplace_back(cur);\n        if (ccw(l.a, l.b, cur) * ccw(l.a,\
    \ l.b, nxt) < 0) res.emplace_back(crosspoint(Segment(cur, nxt), l));\n    }\n\
    \    return res;\n}\n\nPolygon voronoi(const Polygon& P, const std::vector<Point>&\
    \ ps, size_t idx) {\n    Polygon res = P;\n    for (size_t i = 0; i < ps.size();\
    \ i++) {\n        if (i == idx) continue;\n        res = convex_cut(res, bisector(ps[idx],\
    \ ps[i]));\n    }\n    return res;\n}\n\nnamespace internal {\n\nReal commonarea_impl(const\
    \ Circle& c, const Point& a, const Point& b) {\n    auto va = c.center - a, vb\
    \ = c.center - b;\n    Real f = cross(va, vb), res = 0;\n    if (equals(f, 0))\
    \ return res;\n    if (compare(std::max(va.abs(), vb.abs()), c.radius) <= 0) return\
    \ f;\n    if (compare(distance(Segment(a, b), c.center), c.radius) >= 0) return\
    \ c.radius * c.radius * (vb * va.conj()).arg();\n    auto cand = crosspoint(c,\
    \ Segment(a, b));\n    cand.emplace(cand.begin(), a);\n    cand.emplace_back(b);\n\
    \    for (size_t i = 0; i + 1 < cand.size(); i++) res += commonarea_impl(c, cand[i],\
    \ cand[i + 1]);\n    return res;\n}\n\n}  // namespace internal\n\nReal commonarea(const\
    \ Circle& c, const Polygon& P) {\n    if (P.size() < 3) return 0;\n    Real res\
    \ = 0;\n    int n = P.size();\n    for (int i = 0; i < n; i++) res += internal::commonarea_impl(c,\
    \ P[i], P[(i + 1) % n]);\n    return res / 2;\n}\n\nReal closest_pair(std::vector<Point>\
    \ ps) {\n    int n = ps.size();\n    if (n == 1) return 0;\n    sort(ps.begin(),\
    \ ps.end());\n    auto compare_y = [&](const Point& p, const Point& q) { return\
    \ p.y < q.y; };\n    vector<Point> cand(n);\n    const Real inf = 1e18;\n\n  \
    \  auto dfs = [&](auto self, int l, int r) -> Real {\n        if (r - l <= 1)\
    \ return inf;\n        int mid = (l + r) >> 1;\n        auto x_mid = ps[mid].x;\n\
    \        auto res = std::min(self(self, l, mid), self(self, mid, r));\n      \
    \  std::inplace_merge(ps.begin() + l, ps.begin() + mid, ps.begin() + r, compare_y);\n\
    \        for (int i = l, cur = 0; i < r; i++) {\n            if (std::fabs(ps[i].x\
    \ - x_mid) >= res) continue;\n            for (int j = cur - 1; j >= 0; j--) {\n\
    \                auto diff = ps[i] - cand[j];\n                if (diff.y >= res)\
    \ break;\n                res = std::min(res, diff.abs());\n            }\n  \
    \          cand[cur++] = ps[i];\n        }\n        return res;\n    };\n    return\
    \ dfs(dfs, 0, n);\n}\n\n}  // namespace geometry\n\n/**\n * @brief 2 \u6B21\u5143\
    \u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\n * @docs docs/geometry/geometry.md\n\
    \ */\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <iostream>\n#include <tuple>\n#include <vector>\n\nnamespace geometry\
    \ {\nusing Real = double;  // change this flexibly if you want more precision\n\
    constexpr Real EPS = 1e-8;\nconstexpr Real PI = 3.14159265358979323846L;\n\ninline\
    \ int sgn(Real x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }\n\ninline int compare(Real\
    \ a, Real b) { return sgn(a - b); }\n\ninline bool equals(Real a, Real b) { return\
    \ compare(a, b) == 0; }\n\nstruct Point {\n    Real x, y;\n\n    Point() {}\n\n\
    \    Point(Real x, Real y) : x(x), y(y) {}\n\n    Point& operator+=(const Point&\
    \ p) {\n        x += p.x, y += p.y;\n        return *this;\n    }\n\n    Point&\
    \ operator-=(const Point& p) {\n        x -= p.x, y -= p.y;\n        return *this;\n\
    \    }\n\n    Point& operator*=(const Real& k) {\n        x *= k, y *= k;\n  \
    \      return *this;\n    }\n\n    Point& operator/=(const Real& k) {\n      \
    \  x /= k, y /= k;\n        return *this;\n    }\n\n    Point operator+(const\
    \ Point& p) const { return Point(*this) += p; }\n\n    Point operator-(const Point&\
    \ p) const { return Point(*this) -= p; }\n\n    Point operator*(const Real& k)\
    \ const { return Point(*this) *= k; }\n\n    Point operator/(const Real& k) const\
    \ { return Point(*this) /= k; }\n\n    Point operator*(const Point& p) const {\
    \ return Point(x * p.x - y * p.y, x * p.y + y * p.x); }\n\n    Point operator-()\
    \ const { return Point(-x, -y); }\n\n    bool operator==(const Point& p) const\
    \ { return (compare(x, p.x) == 0 && compare(y, p.y) == 0); }\n\n    bool operator!=(const\
    \ Point& p) const { return !(*this == p); }\n\n    bool operator<(const Point&\
    \ p) const {\n        return compare(x, p.x) < 0 || (compare(x, p.x) == 0 && compare(y,\
    \ p.y) < 0);\n    }\n\n    bool operator>(const Point& p) const {\n        return\
    \ compare(x, p.x) > 0 || (compare(x, p.x) == 0 && compare(y, p.y) > 0);\n    }\n\
    \n    friend std::istream& operator>>(std::istream& is, Point& p) { return is\
    \ >> p.x >> p.y; }\n\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ Point& p) { return os << p.x << ' ' << p.y; }\n\n    Real norm() const { return\
    \ x * x + y * y; }\n\n    Real abs() const { return std::hypot(x, y); }\n\n  \
    \  Real arg() const { return std::atan2(y, x); }\n\n    Point normal() const {\
    \ return Point(-y, x); }\n\n    Point unit() const { return *this / abs(); }\n\
    \n    Point conj() const { return Point(x, -y); }\n\n    Point rotate(Real theta)\
    \ const {\n        return Point(x * std::cos(theta) - y * std::sin(theta), x *\
    \ std::sin(theta) + y * std::cos(theta));\n    }\n};\n\nPoint polar(const Real&\
    \ r, const Real& theta) { return Point(cos(theta), sin(theta)) * r; }\n\nReal\
    \ dot(const Point& p, const Point& q) { return p.x * q.x + p.y * q.y; }\n\nReal\
    \ cross(const Point& p, const Point& q) { return p.x * q.y - p.y * q.x; }\n\n\
    Real distance(const Point& p, const Point& q) { return (p - q).abs(); }\n\nstruct\
    \ Line {\n    Point a, b;\n\n    Line() {}\n\n    Line(const Point& a, const Point&\
    \ b) : a(a), b(b) {}\n\n    Line(const Real& A, const Real& B, const Real& C)\
    \ {  // Ax + By = c\n        if (equals(A, 0)) {\n            assert(!equals(B,\
    \ 0));\n            a = Point(0, C / B);\n            b = Point(1, C / B);\n \
    \       } else if (equals(B, 0)) {\n            a = Point(C / A, 0);\n       \
    \     b = Point(C / A, 1);\n        } else {\n            a = Point(0, C / B);\n\
    \            b = Point(C / A, 0);\n        }\n    }\n\n    Point diff() const\
    \ { return b - a; }\n\n    friend std::istream& operator>>(std::istream& is, Line&\
    \ l) { return is >> l.a >> l.b; }\n\n    friend std::ostream& operator<<(std::ostream&\
    \ os, const Line& l) { return os << l.a << \" to \" << l.b; }\n};\n\nstruct Segment\
    \ : Line {\n    Segment() {}\n\n    Segment(Point a, Point b) : Line(a, b) {}\n\
    \n    Real length() const { return diff().abs(); }\n};\n\nPoint proj(const Line&\
    \ l, const Point& p) {\n    Point v = l.diff().unit();\n    return l.a + v * dot(v,\
    \ p - l.a);\n}\n\nPoint refl(const Line& l, const Point& p) {\n    Point h = proj(l,\
    \ p);\n    return h + (h - p);\n}\n\nbool orthogonal(const Line& l, const Line&\
    \ m) { return equals(dot(l.diff(), m.diff()), 0); }\n\nbool parallel(const Line&\
    \ l, const Line& m) { return equals(cross(l.diff(), m.diff()), 0); }\n\nenum Position\
    \ { COUNTER_CLOCKWISE = +1, CLOCKWISE = -1, ONLINE_BACK = +2, ONLINE_FRONT = -2,\
    \ ON_SEGMENT = 0 };\n\nPosition ccw(const Point& a, Point b, Point c) {\n    b\
    \ -= a, c -= a;\n    if (sgn(cross(b, c)) == +1) return COUNTER_CLOCKWISE;\n \
    \   if (sgn(cross(b, c)) == -1) return CLOCKWISE;\n    if (sgn(dot(b, c)) == -1)\
    \ return ONLINE_BACK;\n    if (compare(b.norm(), c.norm()) == -1) return ONLINE_FRONT;\n\
    \    return ON_SEGMENT;\n}\n\nbool intersect(const Line& l, const Point& p) {\
    \ return abs(ccw(l.a, l.b, p)) != 1; }\n\nbool intersect(const Line& l, const\
    \ Line& m) {\n    Real A = cross(l.diff(), m.diff()), B = cross(l.diff(), l.b\
    \ - m.a);\n    if (equals(A, 0) && equals(B, 0)) return true;\n    return !parallel(l,\
    \ m);\n}\n\nbool intersect(const Line& l, const Segment& s) {\n    return sgn(cross(l.diff(),\
    \ s.a - l.a)) * sgn(cross(l.diff(), s.b - l.a)) <= 0;\n}\n\nbool intersect(const\
    \ Segment& s, const Point& p) { return ccw(s.a, s.b, p) == ON_SEGMENT; }\n\nbool\
    \ intersect(const Segment& s, const Segment& t) {\n    return ccw(s.a, s.b, t.a)\
    \ * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;\n\
    }\n\nReal distance(const Line& l, const Point& p) { return distance(p, proj(l,\
    \ p)); }\n\nReal distance(const Line& l, const Line& m) { return intersect(l,\
    \ m) ? 0 : distance(l, m.a); }\n\nReal distance(const Line& l, const Segment&\
    \ s) {\n    return intersect(l, s) ? 0 : std::min(distance(l, s.a), distance(l,\
    \ s.b));\n}\n\nReal distance(const Segment& s, const Point& p) {\n    Point h\
    \ = proj(s, p);\n    return intersect(s, h) ? distance(p, h) : std::min(distance(p,\
    \ s.a), distance(p, s.b));\n}\n\nReal distance(const Segment& s, const Segment&\
    \ t) {\n    if (intersect(s, t)) return 0;\n    return std::min({distance(s, t.a),\
    \ distance(s, t.b), distance(t, s.a), distance(t, s.b)});\n}\n\nPoint crosspoint(const\
    \ Line& l, const Line& m) {\n    assert(intersect(l, m));\n    Real A = cross(l.diff(),\
    \ m.diff()), B = cross(l.diff(), l.b - m.a);\n    if (equals(A, 0) && equals(B,\
    \ 0)) return m.a;\n    return m.a + m.diff() * B / A;\n}\n\nstruct Circle {\n\
    \    Point center;\n    Real radius;\n\n    Circle() {}\n\n    Circle(const Point&\
    \ center, const Real& radius) : center(center), radius(radius) {}\n\n    friend\
    \ std::istream& operator>>(std::istream& is, Circle& c) { return is >> c.center\
    \ >> c.radius; }\n\n    friend std::ostream& operator<<(std::ostream& os, const\
    \ Circle& c) { return os << c.center << ' ' << c.radius; }\n};\n\nbool intersect(const\
    \ Circle& c, const Line& l) { return compare(c.radius, distance(l, c.center))\
    \ >= 0; }\n\nint intersect(const Circle& c, const Segment& s) {\n    Point h =\
    \ proj(s, c.center);\n    if (compare(distance(c.center, h), c.radius) > 0) return\
    \ 0;\n    Real d1 = (c.center - s.a).abs(), d2 = (c.center - s.b).abs();\n   \
    \ if (compare(c.radius, d1) >= 0 && compare(c.radius, d2) >= 0) return 0;\n  \
    \  if (compare(c.radius, d1) * compare(c.radius, d2) < 0) return 1;\n    if (sgn(dot(s.a\
    \ - h, s.b - h)) < 0) return 2;\n    return 0;\n}\n\nstd::vector<Point> crosspoint(const\
    \ Circle& c, const Line& l) {\n    Point h = proj(l, c.center);\n    Real d =\
    \ c.radius * c.radius - (c.center - h).norm();\n    if (sgn(d) < 0) return {};\n\
    \    if (sgn(d) == 0) return {h};\n    Point v = l.diff().unit() * sqrt(d);\n\
    \    return {h - v, h + v};\n}\n\nstd::vector<Point> crosspoint(const Circle&\
    \ c, const Segment& s) {\n    int num = intersect(c, s);\n    if (num == 0) return\
    \ {};\n    auto res = crosspoint(c, Line(s.a, s.b));\n    if (num == 2) return\
    \ res;\n    if (sgn(dot(s.a - res[0], s.b - res[0])) > 0) std::swap(res[0], res[1]);\n\
    \    return {res[0]};\n}\n\n// requirement : c != d\nstd::vector<Point> crosspoint(const\
    \ Circle& c1, const Circle& c2) {\n    Real r1 = c1.radius, r2 = c2.radius;\n\
    \    if (r1 < r2) return crosspoint(c2, c1);\n    Real d = distance(c1.center,\
    \ c2.center);\n    if (compare(d, r1 + r2) > 0 || compare(d, r1 - r2) < 0) return\
    \ {};\n    Real alpha = std::acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));\n\
    \    Real theta = (c2.center - c1.center).arg();\n    Point p = c1.center + polar(r1,\
    \ theta + alpha);\n    Point q = c1.center + polar(r1, theta - alpha);\n    if\
    \ (p == q) return {p};\n    return {p, q};\n}\n\nReal commonarea(Circle c1, Circle\
    \ c2) {\n    Real r1 = c1.radius, r2 = c2.radius;\n    Real d = (c1.center - c2.center).abs();\n\
    \    if (compare(r1 + r2, d) <= 0) return 0;\n    if (compare(std::fabs(r1 - r2),\
    \ d) >= 0) return PI * min(r1, r2) * min(r1, r2);\n    Real res = 0;\n    for\
    \ (int _ = 0; _ < 2; _++) {\n        r1 = c1.radius, r2 = c2.radius;\n       \
    \ Real cosine = (d * d + r1 * r1 - r2 * r2) / (2 * d * r1);\n        Real theta\
    \ = std::acos(cosine) * 2;\n        res += (theta - std::sin(theta)) * r1 * r1\
    \ / 2;\n        swap(c1, c2);\n    }\n    return res;\n}\n\nLine bisector(const\
    \ Point& p, const Point& q) {\n    Point c = (p + q) * 0.5;\n    Point v = (q\
    \ - p).normal();\n    return Line(c - v, c + v);\n}\n\nCircle circumcircle(Point\
    \ a, Point b, const Point& c) {\n    Point center = crosspoint(bisector(a, c),\
    \ bisector(b, c));\n    return Circle(center, distance(c, center));\n}\n\nCircle\
    \ incircle(const Point& a, const Point& b, const Point& c) {\n    Real A = (b\
    \ - c).abs(), B = (c - a).abs(), C = (a - b).abs();\n    Point center = (a * A\
    \ + b * B + c * C) / (A + B + C);\n    return Circle(center, distance(Segment(a,\
    \ b), center));\n}\n\nstd::vector<Point> center_given_radius(const Point& a, const\
    \ Point& b, const Real& r) {\n    Point m = (b - a) * 0.5;\n    Real d1 = m.abs();\n\
    \    if (equals(d1, 0) || d1 > r) return {};\n    Real d2 = sqrt(r * r - d1 *\
    \ d1);\n    Point n = m.normal() * d2 / d1;\n    Point p = a + m - n, q = a +\
    \ m + n;\n    if (p == q) return {p};\n    return {p, q};\n}\n\nint count_tangent(const\
    \ Circle& c1, const Circle& c2) {\n    Real r1 = c1.radius, r2 = c2.radius;\n\
    \    if (r1 < r2) return count_tangent(c2, c1);\n    Real d = distance(c1.center,\
    \ c2.center);\n    if (compare(d, r1 + r2) > 0) return 4;\n    if (compare(d,\
    \ r1 + r2) == 0) return 3;\n    if (compare(d, r1 - r2) > 0) return 2;\n    if\
    \ (compare(d, r1 - r2) == 0) return 1;\n    return 0;\n}\n\nstd::vector<Point>\
    \ tangent_to_circle(const Circle& c, const Point& p) {\n    return crosspoint(c,\
    \ Circle(p, sqrt((c.center - p).norm() - c.radius * c.radius)));\n}\n\nstd::vector<Line>\
    \ common_tangent(const Circle& c1, const Circle& c2) {\n    if (c1.radius < c2.radius)\
    \ return common_tangent(c2, c1);\n    std::vector<Line> res;\n    Real g = distance(c1.center,\
    \ c2.center);\n    if (equals(g, 0)) return res;\n    Point u = (c2.center - c1.center)\
    \ / g, v = u.normal();\n    for (int s : {-1, 1}) {\n        Real h = (c1.radius\
    \ + c2.radius * s) / g;\n        if (equals(1 - h * h, 0))\n            res.emplace_back(c1.center\
    \ + u * c1.radius, c1.center + (u + v) * c1.radius);\n        else if (compare(1\
    \ - h * h, 0) > 0) {\n            Point U = u * h, V = v * std::sqrt(1 - h * h);\n\
    \            res.emplace_back(c1.center + (U + V) * c1.radius, c2.center - (U\
    \ + V) * c2.radius * s);\n            res.emplace_back(c1.center + (U - V) * c1.radius,\
    \ c2.center - (U - V) * c2.radius * s);\n        }\n    }\n    return res;\n}\n\
    \nenum Contain { OUT, ON, IN };\n\nstruct Polygon : std::vector<Point> {\n   \
    \ using std::vector<Point>::vector;\n\n    Polygon(int n) : std::vector<Point>(n)\
    \ {}\n\n    std::vector<Segment> segments() const {\n        assert(size() > 1);\n\
    \        std::vector<Segment> segs;\n        for (size_t i = 0; i < size(); i++)\
    \ segs.emplace_back((*this)[i], (*this)[(i + 1) % size()]);\n        return segs;\n\
    \    }\n\n    Real area() const {\n        Real sum = 0;\n        for (size_t\
    \ i = 0; i < size(); i++) sum += cross((*this)[i], (*this)[(i + 1) % size()]);\n\
    \        return std::abs(sum) / 2;\n    }\n\n    bool is_convex(bool accept_on_segment\
    \ = true) const {\n        int n = size();\n        for (int i = 0; i < n; i++)\
    \ {\n            if (accept_on_segment) {\n                if (ccw((*this)[i],\
    \ (*this)[(i + 1) % n], (*this)[(i + 2) % n]) == CLOCKWISE) {\n              \
    \      return false;\n                }\n            } else {\n              \
    \  if (ccw((*this)[i], (*this)[(i + 1) % n], (*this)[(i + 2) % n]) != COUNTER_CLOCKWISE)\
    \ {\n                    return false;\n                }\n            }\n   \
    \     }\n        return true;\n    }\n};\n\nContain contain(const Polygon& P,\
    \ const Point& p) {\n    bool in = false;\n    for (size_t i = 0; i < P.size();\
    \ i++) {\n        if (ccw(P[i], P[(i + 1) % P.size()], p) == ON_SEGMENT) return\
    \ ON;\n        Point a = P[i] - p, b = P[(i + 1) % P.size()] - p;\n        if\
    \ (a.y > b.y) std::swap(a, b);\n        if (sgn(a.y) <= 0 && sgn(b.y) > 0 && sgn(cross(a,\
    \ b)) < 0) in = !in;\n    }\n    return in ? IN : OUT;\n}\n\nContain contain(const\
    \ Circle& c, const Point& p) {\n    Real d = distance(c.center, p);\n    int cp\
    \ = compare(d, c.radius);\n    if (cp > 0) return OUT;\n    if (cp < 0) return\
    \ IN;\n    return ON;\n}\n\nPolygon convex_hull(Polygon& P, bool accept_on_segment\
    \ = false) {\n    int n = P.size(), k = 0;\n    if (n <= 2) return P;\n    std::sort(P.begin(),\
    \ P.end());\n    Polygon ch(n * 2);\n    auto check = [&](int i) {\n        if\
    \ (accept_on_segment) return ccw(ch[k - 2], ch[k - 1], P[i]) == CLOCKWISE;\n \
    \       return ccw(ch[k - 2], ch[k - 1], P[i]) != COUNTER_CLOCKWISE;\n    };\n\
    \    for (int i = 0; i < n; ch[k++] = P[i++]) {\n        while (k >= 2 && check(i))\
    \ {\n            k--;\n        }\n    }\n    for (int i = n - 2, t = k + 1; i\
    \ >= 0; ch[k++] = P[i--]) {\n        while (k >= t && check(i)) {\n          \
    \  k--;\n        }\n    }\n    ch.resize(k - 1);\n    int start = 0;\n    for\
    \ (int i = 1; i < k - 1; i++) {\n        if (equals(ch[i].y, ch[start].y) ? ch[i].x\
    \ < ch[start].x : ch[i].y < ch[start].y) {\n            start = i;\n        }\n\
    \    }\n    std::rotate(ch.begin(), ch.begin() + start, ch.end());\n    return\
    \ ch;\n}\n\nstd::tuple<int, int, Real> convex_diameter(const Polygon& convex)\
    \ {\n    assert(convex.is_convex());\n    int n = convex.size();\n    Real max_dist\
    \ = -1;\n    std::pair<int, int> argmax = {-1, -1};\n    for (int i = 0, j = 0;\
    \ i < n; i++) {\n        while (j + 1 < n && distance(convex[i], convex[j + 1])\
    \ > distance(convex[i], convex[j])) j++;\n        double cur_dist = distance(convex[i],\
    \ convex[j]);\n        if (max_dist < cur_dist) {\n            max_dist = cur_dist;\n\
    \            argmax = {i, j};\n        }\n    }\n    return {argmax.first, argmax.second,\
    \ max_dist};\n}\n\nPolygon convex_cut(const Polygon& convex, const Line& l) {\n\
    \    assert(convex.is_convex());\n    int n = convex.size();\n    Polygon res;\n\
    \    for (int i = 0; i < n; i++) {\n        const Point& cur = convex[i];\n  \
    \      const Point& nxt = convex[(i + 1) % n];\n        if (ccw(l.a, l.b, cur)\
    \ != CLOCKWISE) res.emplace_back(cur);\n        if (ccw(l.a, l.b, cur) * ccw(l.a,\
    \ l.b, nxt) < 0) res.emplace_back(crosspoint(Segment(cur, nxt), l));\n    }\n\
    \    return res;\n}\n\nPolygon voronoi(const Polygon& P, const std::vector<Point>&\
    \ ps, size_t idx) {\n    Polygon res = P;\n    for (size_t i = 0; i < ps.size();\
    \ i++) {\n        if (i == idx) continue;\n        res = convex_cut(res, bisector(ps[idx],\
    \ ps[i]));\n    }\n    return res;\n}\n\nnamespace internal {\n\nReal commonarea_impl(const\
    \ Circle& c, const Point& a, const Point& b) {\n    auto va = c.center - a, vb\
    \ = c.center - b;\n    Real f = cross(va, vb), res = 0;\n    if (equals(f, 0))\
    \ return res;\n    if (compare(std::max(va.abs(), vb.abs()), c.radius) <= 0) return\
    \ f;\n    if (compare(distance(Segment(a, b), c.center), c.radius) >= 0) return\
    \ c.radius * c.radius * (vb * va.conj()).arg();\n    auto cand = crosspoint(c,\
    \ Segment(a, b));\n    cand.emplace(cand.begin(), a);\n    cand.emplace_back(b);\n\
    \    for (size_t i = 0; i + 1 < cand.size(); i++) res += commonarea_impl(c, cand[i],\
    \ cand[i + 1]);\n    return res;\n}\n\n}  // namespace internal\n\nReal commonarea(const\
    \ Circle& c, const Polygon& P) {\n    if (P.size() < 3) return 0;\n    Real res\
    \ = 0;\n    int n = P.size();\n    for (int i = 0; i < n; i++) res += internal::commonarea_impl(c,\
    \ P[i], P[(i + 1) % n]);\n    return res / 2;\n}\n\nReal closest_pair(std::vector<Point>\
    \ ps) {\n    int n = ps.size();\n    if (n == 1) return 0;\n    sort(ps.begin(),\
    \ ps.end());\n    auto compare_y = [&](const Point& p, const Point& q) { return\
    \ p.y < q.y; };\n    vector<Point> cand(n);\n    const Real inf = 1e18;\n\n  \
    \  auto dfs = [&](auto self, int l, int r) -> Real {\n        if (r - l <= 1)\
    \ return inf;\n        int mid = (l + r) >> 1;\n        auto x_mid = ps[mid].x;\n\
    \        auto res = std::min(self(self, l, mid), self(self, mid, r));\n      \
    \  std::inplace_merge(ps.begin() + l, ps.begin() + mid, ps.begin() + r, compare_y);\n\
    \        for (int i = l, cur = 0; i < r; i++) {\n            if (std::fabs(ps[i].x\
    \ - x_mid) >= res) continue;\n            for (int j = cur - 1; j >= 0; j--) {\n\
    \                auto diff = ps[i] - cand[j];\n                if (diff.y >= res)\
    \ break;\n                res = std::min(res, diff.abs());\n            }\n  \
    \          cand[cur++] = ps[i];\n        }\n        return res;\n    };\n    return\
    \ dfs(dfs, 0, n);\n}\n\n}  // namespace geometry\n\n/**\n * @brief 2 \u6B21\u5143\
    \u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA\n * @docs docs/geometry/geometry.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: geometry/geometry.hpp
  requiredBy: []
  timestamp: '2021-11-04 01:39:18+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/CGL_1_B.test.cpp
  - test/aoj/CGL_2_B.test.cpp
  - test/aoj/CGL_4_C.test.cpp
  - test/aoj/CGL_7_F.test.cpp
  - test/aoj/CGL_4_A.test.cpp
  - test/aoj/CGL_4_B.test.cpp
  - test/aoj/CGL_7_D.test.cpp
  - test/aoj/CGL_7_E.test.cpp
  - test/aoj/CGL_3_B.test.cpp
  - test/aoj/CGL_1_A.test.cpp
  - test/aoj/CGL_2_D.test.cpp
  - test/aoj/CGL_3_C.test.cpp
  - test/aoj/CGL_7_I.test.cpp
  - test/aoj/CGL_1_C.test.cpp
  - test/aoj/CGL_7_H.test.cpp
  - test/aoj/CGL_7_A.test.cpp
  - test/aoj/CGL_2_C.test.cpp
  - test/aoj/CGL_5_A.test.cpp
  - test/aoj/CGL_7_C.test.cpp
  - test/aoj/CGL_3_A.test.cpp
  - test/aoj/CGL_2_A.test.cpp
  - test/aoj/CGL_7_B.test.cpp
  - test/aoj/CGL_7_G.test.cpp
documentation_of: geometry/geometry.hpp
layout: document
redirect_from:
- /library/geometry/geometry.hpp
- /library/geometry/geometry.hpp.html
title: "2 \u6B21\u5143\u5E7E\u4F55\u30E9\u30A4\u30D6\u30E9\u30EA"
---
## 概要
2 次元幾何ライブラリ. 主に ICPC 用.

点, 直線, 線分, 円, 及び多角形を扱う構造体 `Point, Line, Segment, Circle, Polygon` がある. 直線はその上の相異なる 2 点で, 線分は両端点で表現される.

関数が多すぎるので整理.

| 関数                                    | 効果                                                                                                                                                           | 時間計算量       |
| --------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------- |
| `Point(x, y)`                           | 座標をセットして初期化する.                                                                                                                                    | $O(1)$           |
| `Point::norm()`                         | $x^2 + y^2$ を返す.                                                                                                                                            | $O(1)$           |
| `Point::abs()`                          | 原点からの距離 $\sqrt{x^2 + y^2}$ を返す.                                                                                                                      | $O(1)$           |
| `Point::arg()`                          | ベクトルとみなした際の偏角を返す.                                                                                                                              | $O(1)$           |
| `Point::normal()`                       | ベクトルとみなした際の法線ベクトルを返す.                                                                                                                      | $O(1)$           |
| `Point::unit()`                         | ベクトルとみなした際の正規化されたベクトルを返す.                                                                                                              | $O(1)$           |
| `Point::rotate(theta)`                  | 原点中心に $\theta$ 回転させた後の点を返す.                                                                                                                    | $O(1)$           |
| `polar(r, theta)`                       | 極座標系での点 $(r, \theta)$ を直交座標に変換して返す.                                                                                                         | $O(1)$           |
| `dot(p, q)`                             | 2 つのベクトルの内積を返す.                                                                                                                                    | $O(1)$           |
| `cross(p, q)`                           | 2 つのベクトルの外積を返す.                                                                                                                                    | $O(1)$           |
| `distance(p, q)`                        | 2 点 $a, b$ 間の距離を返す.                                                                                                                                    | $O(1)$           |
| `Line(a, b)`                            | 点 $a$ 及び $b$ をその上にもつ直線として初期化する.                                                                                                            | $O(1)$           |
| `Line(A, B, C)`                         | 直線 $Ax + By = C$ として初期化する.                                                                                                                           | $O(1)$           |
| `Line::diff()`                          | $b - a$ を返す.                                                                                                                                                | $O(1)$           |
| `proj(l, p)`                            | 点 $p$ を直線 $l$ に正射影してできる点を返す.                                                                                                                  | $O(1)$           |
| `refl(l, p)`                            | 点 $p$ と直線 $l$ について対称な点を返す.                                                                                                                      | $O(1)$           |
| `orthogonal(l, m)`                      | 2 直線が直行するかどうか判定する.                                                                                                                              | $O(1)$           |
| `parallel(l, m)`                        | 2 直線が平行かどうか判定する.                                                                                                                                  | $O(1)$           |
| `ccw(a, b, c)`                          | $a \to b \to c$ と移動する際の移動方向を分類する.                                                                                                              | $O(1)$           |
| `intersect(l, p)`                       | 点 $p$ が直線 $l$ 上にあるかどうか判定する.                                                                                                                    | $O(1)$           |
| `intersect(l, m)`                       | 2 直線 $l, m$ が交点をもつか判定する.                                                                                                                          | $O(1)$           |
| `intersect(l, s)`                       | 直線 $l$ と線分 $s$ が交点をもつか判定する.                                                                                                                    | $O(1)$           |
| `intersect(s, p)`                       | 点 $p$ が線分 $s$ 上にあるかどうか判定する.                                                                                                                    | $O(1)$           |
| `intersect(s, t)`                       | 2 線分 $s, t$ が交点をもつか判定する.                                                                                                                          | $O(1)$           |
| `distance(l, p)`                        | 点 $p$ が直線 $l$ の間の距離を返す.                                                                                                                            | $O(1)$           |
| `distance(l, m)`                        | 2 直線 $l, m$ の間の距離を返す.                                                                                                                                | $O(1)$           |
| `distance(l, s)`                        | 直線 $l$ と線分 $s$ の間の距離を返す.                                                                                                                          | $O(1)$           |
| `distance(s, p)`                        | 点 $p$ が線分 $s$ の間の距離を返す.                                                                                                                            | $O(1)$           |
| `distance(s, t)`                        | 2 線分 $s, t$ の間の距離を返す.                                                                                                                                | $O(1)$           |
| `crosspoint(l, m)`                      | 2 直線 $l$ と $m$ の交点を返す.                                                                                                                                | $O(1)$           |
| `Circle(center, radius)`                | 中心 $center$ , 半径 $radius$ の円として初期化する.                                                                                                            | $O(1)$           |
| `intersect(c, l)`                       | 円 $c$ と直線 $l$ が交点をもつか判定する.                                                                                                                      | $O(1)$           |
| `intersect(c, s)`                       | 円 $c$ と線分 $s$ の交点の個数を返す.                                                                                                                          | $O(1)$           |
| `crosspoint(c, l)`                      | 円 $c$ と直線 $l$ の交点を全て求める.                                                                                                                          | $O(1)$           |
| `crosspoint(c, s)`                      | 円 $c$ と線分 $s$ の交点を全て求める.                                                                                                                          | $O(1)$           |
| `crosspoint(c1, c2)`                    | 2 円 $c1, c2$ の交点を全て求める.                                                                                                                              | $O(1)$           |
| `commonarea(c1, c2)`                    | 2 円 $c1, c2$ の共通部分の面積を求める.                                                                                                                        | $O(1)$           |
| `bisector(p, q)`                        | 2 点 $p, q$ の垂直二等分線を返す.                                                                                                                              | $O(1)$           |
| `circumcircle(a, b, c)`                 | 3 点 $a, b, c$ を頂点とする三角形の外接円を返す.                                                                                                               | $O(1)$           |
| `incircle(a, b, c)`                     | 3 点 $a, b, c$ を頂点とする三角形の内接円を返す.                                                                                                               | $O(1)$           |
| `center_given_radius(a, b, r)`          | 2 点 $a, b$ を通る半径 $r$ の円の中心の候補を全て求める.                                                                                                       | $O(1)$           |
| `count_tangent(c1, c2)`                 | 2 円 $c1, c2$ の共通接線の本数を返す.                                                                                                                          | $O(1)$           |
| `tangent_to_circle(c, p)`               | 点 $p$ から円 $c$ に引いた接線の接点を全て求める.                                                                                                              | $O(1)$           |
| `common_tangent(c1, c2)`                | 2 円 $c1, c2$ の共通接線を返す.                                                                                                                                | $O(1)$           |
| `Polygon(n)`                            | $n$ 頂点の多角形として初期化する. `std::vector` を継承しているので同じように扱って問題ない (はず) .                                                            | $O(n)$           |
| `Polygon::segments()`                   | 多角形の隣接頂点同士を結ぶ線分集合を返す.                                                                                                                      | $O(n)$           |
| `Polygon::area()`                       | 多角形の面積を返す.                                                                                                                                            | $O(n)$           |
| `Polygon::is_convex(accept_on_segment)` | 多角形が凸かどうか判定する.                                                                                                                                    | $O(n)$           |
| `contain(P, p)`                         | 多角形 $P$ が点 $p$ を含むか判定する.                                                                                                                          | $O(n)$           |
| `contain(c, p)`                         | 円 $c$ が点 $p$ を含むか判定する.                                                                                                                              | $O(1)$           |
| `convex_hull(P, accept_on_segment)`     | 点集合 $P$ から凸包を構成する.                                                                                                                                 | $O(n \log n)$    |
| `convex_diameter(convex)`               | 凸多角形 $convex$ の直径とその両端点を返す (最遠点対) .                                                                                                        | $O(n)$           |
| `convex_cut(convex, l)`                 | 凸多角形 $convex$ を直線 $l$ で切断した際に左側にできる (厳密には $l$ を構成する 2 点 $a, b$ について,  $a$ から $b$ に進む際に左側にある方) 凸多角形を求める. | $O(n)$           |
| `voronoi(P, ps, idx)`                   | 多角形 $P$ 内を点集合 $ps$ による voronoi 図で分割した際の 点  $ps_i$ の支配する領域を求める.                                                                  | $O(\|P\|\|ps\|)$ |
| `commonarea(c, P)`                      | 円 $c$ と多角形 $P$ の共通部分の面積を求める.                                                                                                                  | $O(n)$           |
| `closest_pair(ps)`                      | 点集合 $ps$ 内の相異なる 2 点間の距離の最小値を求める (最近点対) .                                                                                             | $O(n \log n)$    |

## TODO
- 凸多角形に対する点の包含関係の $O(\log n)$ での判定
- 線分の重複除去
- 最小包含円