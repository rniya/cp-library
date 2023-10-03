#pragma once
#include "Circle.hpp"
#include "Polygon.hpp"
#include "distance.hpp"

namespace geometry {

enum class Containment { OUT, ON, IN };

template <typename T> Containment contain(const Circle<T>& c, const Point<T>& p) {
    int x = sgn(distance(c.c, p) - c.r);
    return x == -1 ? Containment::IN : x == 1 ? Containment::OUT : Containment::ON;
}

template <typename T> Containment contain(const Polygon<T>& P, const Point<T>& p) {
    bool in = false;
    int n = P.size();
    for (int i = 0, j = 1; i < n; i++, j++) {
        if (j == n) j -= n;
        Point a = P[i] - p, b = P[j] - p;
        if (a.y > b.y) std::swap(a, b);
        if (sgn(a.y) <= 0 and sgn(b.y) > 0 and sgn(a.det(b)) < 0) in = not in;
        if (sgn(a.det(b)) == 0 and sgn(a.dot(b)) <= 0) return Containment::ON;
    }
    return in ? Containment::IN : Containment::OUT;
}

}  // namespace geometry