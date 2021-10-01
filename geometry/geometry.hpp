#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <iostream>
#include <tuple>
#include <vector>

namespace geometry {
using Real = double;
constexpr Real EPS = 1e-8;
constexpr Real PI = 3.14159265358979323846L;

inline int sgn(Real x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }

inline int compare(Real a, Real b) { return sgn(a - b); }

inline bool equals(Real a, Real b) { return compare(a, b) == 0; }

struct Point {
    Real x, y;

    Point() {}

    Point(Real x, Real y) : x(x), y(y) {}

    Point& operator+=(const Point& p) {
        x += p.x, y += p.y;
        return *this;
    }

    Point& operator-=(const Point& p) {
        x -= p.x, y -= p.y;
        return *this;
    }

    Point& operator*=(const Real& k) {
        x *= k, y *= k;
        return *this;
    }

    Point& operator/=(const Real& k) {
        x /= k, y /= k;
        return *this;
    }

    Point operator+(const Point& p) const { return Point(*this) += p; }

    Point operator-(const Point& p) const { return Point(*this) -= p; }

    Point operator*(const Real& k) const { return Point(*this) *= k; }

    Point operator/(const Real& k) const { return Point(*this) /= k; }

    Point operator-() const { return Point(-x, -y); }

    bool operator==(const Point& p) const { return (compare(x, p.x) == 0 && compare(y, p.y) == 0); }

    bool operator!=(const Point& p) const { return !(*this == p); }

    bool operator<(const Point& p) const {
        return compare(x, p.x) < 0 || (compare(x, p.x) == 0 && compare(y, p.y) < 0);
    }

    bool operator>(const Point& p) const {
        return compare(x, p.x) > 0 || (compare(x, p.x) == 0 && compare(y, p.y) > 0);
    }

    friend std::istream& operator>>(std::istream& is, Point& p) { return is >> p.x >> p.y; }

    friend std::ostream& operator<<(std::ostream& os, const Point& p) { return os << p.x << ' ' << p.y; }

    Real norm() const { return x * x + y * y; }

    Real abs() const { return std::hypot(x, y); }

    Real arg() const { return std::atan2(y, x); }

    Point normal() const { return Point(-y, x); }

    Point unit() const { return *this / abs(); }

    Point rotate(Real theta) const {
        return Point(x * std::cos(theta) - y * std::sin(theta), x * std::sin(theta) + y * std::cos(theta));
    }
};

Point polar(const Real& r, const Real& theta) { return Point(cos(theta), sin(theta)) * r; }

Real dot(const Point& p, const Point& q) { return p.x * q.x + p.y * q.y; }

Real cross(const Point& p, const Point& q) { return p.x * q.y - p.y * q.x; }

Real distance(const Point& p, const Point& q) { return (p - q).abs(); }

struct Line {
    Point a, b;

    Line() {}

    Line(const Point& a, const Point& b) : a(a), b(b) {}

    Line(const Real& A, const Real& B, const Real& C) {  // Ax + By = c
        if (equals(A, 0)) {
            assert(!equals(B, 0));
            a = Point(0, C / B);
            b = Point(1, C / B);
        } else if (equals(B, 0)) {
            a = Point(C / A, 0);
            b = Point(C / A, 1);
        } else {
            a = Point(0, C / B);
            b = Point(C / A, 0);
        }
    }

    friend std::istream& operator>>(std::istream& is, Line& l) { return is >> l.a >> l.b; }

    friend std::ostream& operator<<(std::ostream& os, const Line& l) { return os << l.a << " to " << l.b; }

    Point diff() const { return b - a; }
};

struct Segment : Line {
    Segment() {}

    Segment(Point a, Point b) : Line(a, b) {}

    Real length() const { return diff().abs(); }
};

Point proj(const Line& l, const Point& p) {
    Point v = l.diff().unit();
    return l.a + v * dot(v, p - l.a);
}

Point refl(const Line& l, const Point& p) {
    Point h = proj(l, p);
    return h + (h - p);
}

bool orthogonal(const Line& l, const Line& m) { return equals(dot(l.diff(), m.diff()), 0); }

bool parallel(const Line& l, const Line& m) { return equals(cross(l.diff(), m.diff()), 0); }

enum Position { COUNTER_CLOCKWISE = +1, CLOCKWISE = -1, ONLINE_BACK = +2, ONLINE_FRONT = -2, ON_SEGMENT = 0 };

Position ccw(const Point& a, Point b, Point c) {
    b -= a, c -= a;
    if (sgn(cross(b, c)) == +1) return COUNTER_CLOCKWISE;
    if (sgn(cross(b, c)) == -1) return CLOCKWISE;
    if (sgn(dot(b, c)) == -1) return ONLINE_BACK;
    if (compare(b.norm(), c.norm()) == -1) return ONLINE_FRONT;
    return ON_SEGMENT;
}

bool intersect(const Line& l, const Point& p) { return abs(ccw(l.a, l.b, p)) != 1; }

bool intersect(const Line& l, const Line& m) {
    Real A = cross(l.diff(), m.diff()), B = cross(l.diff(), l.b - m.a);
    if (equals(A, 0) && equals(B, 0)) return true;
    return !parallel(l, m);
}

bool intersect(const Line& l, const Segment& s) {
    return sgn(cross(l.diff(), s.a - l.a)) * sgn(cross(l.diff(), s.b - l.a)) <= 0;
}

bool intersect(const Segment& s, const Point& p) { return ccw(s.a, s.b, p) == ON_SEGMENT; }

bool intersect(const Segment& s, const Segment& t) {
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 && ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

Real distance(const Line& l, const Point& p) { return distance(p, proj(l, p)); }

Real distance(const Line& l, const Line& m) { return intersect(l, m) ? 0 : distance(l, m.a); }

Real distance(const Line& l, const Segment& s) {
    return intersect(l, s) ? 0 : std::min(distance(l, s.a), distance(l, s.b));
}

Real distance(const Segment& s, const Point& p) {
    Point h = proj(s, p);
    return intersect(s, h) ? distance(p, h) : std::min(distance(p, s.a), distance(p, s.b));
}

Real distance(const Segment& s, const Segment& t) {
    if (intersect(s, t)) return 0;
    return std::min({distance(s, t.a), distance(s, t.b), distance(t, s.a), distance(t, s.b)});
}

Point crosspoint(const Line& l, const Line& m) {
    assert(intersect(l, m));
    Real A = cross(l.diff(), m.diff()), B = cross(l.diff(), l.b - m.a);
    if (equals(A, 0) && equals(B, 0)) return m.a;
    return m.a + m.diff() * B / A;
}

struct Circle {
    Point center;
    Real radius;

    Circle() {}

    Circle(const Point& center, const Real& radius) : center(center), radius(radius) {}

    friend std::istream& operator>>(std::istream& is, Circle& c) { return is >> c.center >> c.radius; }

    friend std::ostream& operator<<(std::ostream& os, const Circle& c) { return os << c.center << ' ' << c.radius; }
};

bool intersect(const Circle& c, const Line& l) { return compare(c.radius, distance(l, c.center)) >= 0; }

int intersect(const Circle& c, const Segment& s) {
    Point h = proj(s, c.center);
    if (compare(distance(c.center, h), c.radius) > 0) return 0;
    Real d1 = (c.center - s.a).abs(), d2 = (c.center - s.b).abs();
    if (compare(c.radius, d1) >= 0 && compare(c.radius, d2) >= 0) return 0;
    if (compare(c.radius, d1) * compare(c.radius, d2) < 0) return 1;
    if (sgn(dot(s.a - h, s.b - h)) < 0) return 2;
    return 0;
}

std::vector<Point> crosspoint(const Circle& c, const Line& l) {
    Point h = proj(l, c.center);
    Real d = c.radius * c.radius - (c.center - h).norm();
    if (sgn(d) < 0) return {};
    if (sgn(d) == 0) return {h};
    Point v = l.diff().unit() * sqrt(d);
    return {h - v, h + v};
}

std::vector<Point> crosspoint(const Circle& c, const Segment& s) {
    int num = intersect(c, s);
    if (num == 0) return {};
    auto res = crosspoint(c, Line(s.a, s.b));
    if (num == 2) return res;
    if (sgn(dot(s.a - res[0], s.b - res[0])) > 0) std::swap(res[0], res[1]);
    return {res[0]};
}

// requirement : c != d
std::vector<Point> crosspoint(const Circle& c1, const Circle& c2) {
    Real r1 = c1.radius, r2 = c2.radius;
    if (r1 < r2) return crosspoint(c2, c1);
    Real d = distance(c1.center, c2.center);
    if (compare(d, r1 + r2) > 0 || compare(d, r1 - r2) < 0) return {};
    Real alpha = std::acos((r1 * r1 + d * d - r2 * r2) / (2 * r1 * d));
    Real theta = (c2.center - c1.center).arg();
    Point p = c1.center + polar(r1, theta + alpha);
    Point q = c1.center + polar(r1, theta - alpha);
    if (p == q) return {p};
    return {p, q};
}

Line bisector(const Point& p, const Point& q) {
    Point c = (p + q) * 0.5;
    Point v = (q - p).normal();
    return Line(c - v, c + v);
}

Circle circumcircle(Point a, Point b, const Point& c) {
    Point center = crosspoint(bisector(a, c), bisector(b, c));
    return Circle(center, distance(c, center));
}

std::vector<Point> center_given_radius(const Point& a, const Point& b, const Real& r) {
    Point m = (b - a) * 0.5;
    Real d1 = m.abs();
    if (equals(d1, 0) || d1 > r) return {};
    Real d2 = sqrt(r * r - d1 * d1);
    Point n = m.normal() * d2 / d1;
    Point p = a + m - n, q = a + m + n;
    if (p == q) return {p};
    return {p, q};
}

int count_tangent(const Circle& c1, const Circle& c2) {
    Real r1 = c1.radius, r2 = c2.radius;
    if (r1 < r2) return count_tangent(c2, c1);
    Real d = distance(c1.center, c2.center);
    if (compare(d, r1 + r2) > 0) return 4;
    if (compare(d, r1 + r2) == 0) return 3;
    if (compare(d, r1 - r2) > 0) return 2;
    if (compare(d, r1 - r2) == 0) return 1;
    return 0;
}

std::vector<Point> tangent_to_circle(const Circle& c, const Point& p) {
    return crosspoint(c, Circle(p, sqrt((c.center - p).norm() - c.radius * c.radius)));
}

enum Contain { OUT, ON, IN };

struct Polygon : std::vector<Point> {
    using std::vector<Point>::vector;

    Polygon(int n) : std::vector<Point>(n) {}

    std::vector<Segment> segments() const {
        assert(size() > 1);
        std::vector<Segment> segs;
        for (size_t i = 0; i < size(); i++) segs.emplace_back((*this)[i], (*this)[(i + 1) % size()]);
        return segs;
    }

    Real area() const {
        Real sum = 0;
        for (size_t i = 0; i < size(); i++) sum += cross((*this)[i], (*this)[(i + 1) % size()]);
        return std::abs(sum) / 2;
    }

    bool is_convex(bool accept_on_segment = true) const {
        int n = size();
        for (int i = 0; i < n; i++) {
            if (accept_on_segment) {
                if (ccw((*this)[i], (*this)[(i + 1) % n], (*this)[(i + 2) % n]) == CLOCKWISE) {
                    return false;
                }
            } else {
                if (ccw((*this)[i], (*this)[(i + 1) % n], (*this)[(i + 2) % n]) != COUNTER_CLOCKWISE) {
                    return false;
                }
            }
        }
        return true;
    }
};

Contain contain(const Polygon& P, const Point& p) {
    bool in = false;
    for (size_t i = 0; i < P.size(); i++) {
        if (ccw(P[i], P[(i + 1) % P.size()], p) == ON_SEGMENT) return ON;
        Point a = P[i] - p, b = P[(i + 1) % P.size()] - p;
        if (a.y > b.y) std::swap(a, b);
        if (sgn(a.y) <= 0 && sgn(b.y) > 0 && sgn(cross(a, b)) < 0) in = !in;
    }
    return in ? IN : OUT;
}

Polygon convex_hull(Polygon& P, bool accept_on_segment = false) {
    int n = P.size(), k = 0;
    if (n <= 2) return P;
    std::sort(P.begin(), P.end());
    Polygon ch(n * 2);
    auto check = [&](int i) {
        if (accept_on_segment) return ccw(ch[k - 2], ch[k - 1], P[i]) == CLOCKWISE;
        return ccw(ch[k - 2], ch[k - 1], P[i]) != COUNTER_CLOCKWISE;
    };
    for (int i = 0; i < n; ch[k++] = P[i++]) {
        while (k >= 2 && check(i)) {
            k--;
        }
    }
    for (int i = n - 2, t = k + 1; i >= 0; ch[k++] = P[i--]) {
        while (k >= t && check(i)) {
            k--;
        }
    }
    ch.resize(k - 1);
    int start = 0;
    for (int i = 1; i < k - 1; i++) {
        if (equals(ch[i].y, ch[start].y) ? ch[i].x < ch[start].x : ch[i].y < ch[start].y) {
            start = i;
        }
    }
    std::rotate(ch.begin(), ch.begin() + start, ch.end());
    return ch;
}

std::tuple<int, int, Real> convex_diameter(const Polygon& convex) {
    assert(convex.is_convex());
    int n = convex.size();
    Real max_dist = -1;
    std::pair<int, int> argmax = {-1, -1};
    for (int i = 0, j = 0; i < n; i++) {
        while (j + 1 < n && distance(convex[i], convex[j + 1]) > distance(convex[i], convex[j])) j++;
        double cur_dist = distance(convex[i], convex[j]);
        if (max_dist < cur_dist) {
            max_dist = cur_dist;
            argmax = {i, j};
        }
    }
    return {argmax.first, argmax.second, max_dist};
}

Polygon convex_cut(const Polygon& convex, const Line& l) {
    assert(convex.is_convex());
    int n = convex.size();
    Polygon res;
    for (int i = 0; i < n; i++) {
        const Point& cur = convex[i];
        const Point& nxt = convex[(i + 1) % n];
        if (ccw(l.a, l.b, cur) != CLOCKWISE) res.emplace_back(cur);
        if (ccw(l.a, l.b, cur) * ccw(l.a, l.b, nxt) < 0) res.emplace_back(crosspoint(Segment(cur, nxt), l));
    }
    return res;
}

Polygon voronoi(const Polygon& P, const std::vector<Point>& ps, size_t idx) {
    Polygon res = P;
    for (size_t i = 0; i < ps.size(); i++) {
        if (i == idx) continue;
        res = convex_cut(res, bisector(ps[idx], ps[i]));
    }
    return res;
}

}  // namespace geometry

/**
 * @brief 2 次元幾何ライブラリ
 * @docs docs/geometry/geometry.md
 */
