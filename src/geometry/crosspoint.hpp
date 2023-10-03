#pragma once
#include <utility>
#include <vector>
#include "Circle.hpp"
#include "ccw.hpp"
#include "projection.hpp"

namespace geometry {

template <typename T> bool is_parallel(const Line<T>& l, const Line<T>& m) {
    return sgn((l.b - l.a).det(m.b - m.a)) == 0;
}

template <typename T> bool is_orthogonal(const Line<T>& l, const Line<T>& m) {
    return sgn((l.b - l.a).dot(m.b - m.a)) == 0;
}

template <typename T> bool has_crosspoint(const Segment<T>& s, const Segment<T>& t) {
    return ccw(s.a, s.b, t.a) * ccw(s.a, s.b, t.b) <= 0 and ccw(t.a, t.b, s.a) * ccw(t.a, t.b, s.b) <= 0;
}

template <typename T> int count_common_tangent(const Circle<T>& c, const Circle<T>& d) {
    T dist = (c.c - d.c).norm();
    int tmp = sgn(dist - (c.r + d.r));
    if (tmp > 0) return 4;
    if (tmp == 0) return 3;
    tmp = sgn(dist - (sgn(c.r - d.r) > 0 ? c.r - d.r : d.r - c.r));
    if (tmp > 0) return 2;
    if (tmp == 0) return 1;
    return 0;
}

template <typename T> Point<T> crosspoint(const Line<T>& l, const Line<T>& m) {
    assert(not is_parallel(l, m));
    Point<T> u = l.b - l.a, v = m.b - m.a;
    return l.a + u * v.det(m.a - l.a) / v.det(u);
}

template <typename T> Point<T> crosspoint(const Segment<T>& s, const Segment<T>& t) {
    assert(has_crosspoint(s, t));
    if (not is_parallel(s, t)) return crosspoint(Line(s.a, s.b), Line(t.a, t.b));
    std::vector<Point<T>> v = {s.a, s.b, t.a, t.b};
    for (int i = 0; i <= 2; i++) {
        for (int j = 2; j >= i; j--) {
            if (v[j + 1] < v[j]) {
                std::swap(v[j], v[j + 1]);
            }
        }
    }
    return v[1];
}

template <typename T> std::vector<Point<T>> crosspoint(const Circle<T>& c, const Line<T>& l) {
    Point<T> h = projection(l, c.c);
    T x = c.r * c.r - (c.c - h).norm2();
    if (sgn(x) < 0) return {};
    if (sgn(x) == 0) return {h};
    Point<T> v = (l.b - l.a).unit() * std::sqrt(x);
    return {h - v, h + v};
}

template <typename T> std::vector<Point<T>> crosspoint(const Circle<T>& c, const Segment<T>& s) {}

template <typename T> std::vector<Point<T>> crosspoint(const Circle<T>& c1, const Circle<T>& c2) {
    T r1 = c1.r, r2 = c2.r;
    if (r1 < r2) return crosspoint(c2, c1);
    T d = (c2.c - c1.c).norm();
    if (sgn(d - (r1 + r2)) > 0 or sgn(d - (r1 - r2)) < 0) return {};
    Point<T> v = c2.c - c1.c;
    if (sgn(d - (r1 + r2)) == 0 or sgn(d - (r1 - r2)) == 0) return {c1.c + v.unit() * r1};
    T p = ((r1 * r1 - r2 * r2) / d + d) / 2, q = std::sqrt(r1 * r1 - p * p);
    Point<T> h = c1.c + v.unit() * p;
    Point<T> i = v.normal();
    return {h + i * q, h - i * q};
}

}  // namespace geometry