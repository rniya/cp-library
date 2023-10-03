#pragma once
#include "Point.hpp"

namespace geometry {

template <typename T> struct Circle {
    Point<T> c;
    T r;

    Circle() {}

    Circle(Point<T> c, T r) : c(c), r(r) {}

    friend std::istream& operator>>(std::istream& is, Circle& c) { return is >> c.c >> c.r; }

    friend std::ostream& operator<<(std::ostream& os, const Circle& c) { return os << c.c << ' ' << c.r; }
};

}  // namespace geometry