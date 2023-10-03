#pragma once
#include "Line.hpp"
#include "Point.hpp"

namespace geometry {

template <typename T> Point<T> projection(const Line<T>& l, const Point<T>& p) {
    Point<T> a = p - l.a, b = l.b - l.a;
    return l.a + b * a.dot(b) / b.norm2();
}

}  // namespace geometry