#pragma once
#include "Circle.hpp"

namespace geometry {

template <typename T> Circle<T> circumcircle(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    T la = (b - c).norm2(), lb = (c - a).norm2(), lc = (a - b).norm2();
    T s = la * (lb + lc - la), t = lb * (lc + la - lb), u = lc * (la + lb - lc), l = s + t + u;
    s /= l, t /= l, u /= l;
    Point<T> center = a * s + b * t + c * u;
    return Circle<T>(center, (a - center).norm());
}

}  // namespace geometry