#pragma once
#include "Point.hpp"

namespace geometry {

template <typename T> struct Line {
    Point<T> a, b;

    Line() {}

    Line(const Point<T>& a, const Point<T>& b) : a(a), b(b) {}

    // A * x + B * y + C = 0
    Line(T A, T B, T C) {}

    friend std::istream& operator>>(std::istream& is, Line& l) { return is >> l.a >> l.b; }

    friend std::ostream& operator<<(std::ostream& os, const Line& l) { return os << l.a << " to " << l.b; }
};

template <typename T> struct Segment : Line<T> {
    Segment() {}

    Segment(const Point<T>& a, const Point<T>& b) : Line<T>(a, b) {}
};

}  // namespace geometry