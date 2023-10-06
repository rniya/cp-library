#pragma once
#include "Circle.hpp"

namespace geometry {

template <typename T> Circle<T> incircle(const Point<T>& a, const Point<T>& b, const Point<T>& c) {
    T la = (b - c).norm(), lb = (c - a).norm(), lc = (a - b).norm();
    Point<T> center = (a * la + b * lb + c * lc) / (la + lb + lc);
    T radius = std::abs((b - a).det(c - a)) / (la + lb + lc);
    return Circle<T>(center, radius);
}

}  // namespace geometry