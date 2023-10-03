#pragma once
#include "projection.hpp"

namespace geometry {

template <typename T> Point<T> reflection(const Line<T>& l, const Point<T>& p) {
    Point h = projection(l, p);
    return h + (h - p);
}

}  // namespace geometry