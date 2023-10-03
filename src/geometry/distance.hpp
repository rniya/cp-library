#pragma once
#include <algorithm>
#include "crosspoint.hpp"
#include "projection.hpp"

namespace geometry {

template <typename T> T distance(const Point<T>& p, const Point<T>& q) { return (p - q).norm(); }

template <typename T> T distance(const Line<T>& l, const Point<T>& p) { return distance(p, projection(l, p)); }

template <typename T> T distance(const Segment<T>& s, const Point<T>& p) {
    Point<T> h = projection(s, p);
    return ccw(s.a, s.b, h) == ON_SEGMENT ? distance(p, h) : std::min(distance(p, s.a), distance(p, s.b));
}

template <typename T> T distance(const Segment<T>& s, const Segment<T>& t) {
    return has_crosspoint(s, t) ? 0
                                : std::min({distance(s, t.a), distance(s, t.b), distance(t, s.a), distance(t, s.b)});
}

}  // namespace geometry