#pragma once
#include "Polygon.hpp"
#include "crosspoint.hpp"

namespace geometry {

template <typename T> Polygon<T> convex_cut(const Polygon<T>& convex, const Line<T>& l) {
    int n = convex.size();
    Polygon<T> res;
    for (int i = 0, j = 1; i < n; i++, j++) {
        if (j == n) j -= n;
        Point<T> p = convex[i], q = convex[j];
        int dp = sgn((l.b - l.a).det(p - l.a)), dq = sgn((l.b - l.a).det(q - l.a));
        if (dp >= 0) res.emplace_back(p);
        if (dp * dq < 0) res.emplace_back(crosspoint(l, Line(p, q)));
    }
    return res;
}

}  // namespace geometry