#pragma once
#include "Point.hpp"

namespace geometry {

enum Position { COUNTER_CLOCKWISE = +1, CLOCKWISE = -1, ONLINE_BACK = +2, ONLINE_FRONT = -2, ON_SEGMENT = 0 };

template <typename T> Position ccw(const Point<T>& a, Point<T> b, Point<T> c) {
    b = b - a;
    c = c - a;
    if (sgn(b.det(c)) == 1) return COUNTER_CLOCKWISE;
    if (sgn(b.det(c)) == -1) return CLOCKWISE;
    if (sgn(b.dot(c)) == -1) return ONLINE_BACK;
    if (b.norm2() < c.norm2()) return ONLINE_FRONT;
    return ON_SEGMENT;
}

}  // namespace geometry