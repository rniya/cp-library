#pragma once
#include "convex_diameter.hpp"
#include "convex_hull.hpp"

namespace geometry {

template <typename T> std::pair<int, int> furthest_pair(const std::vector<Point<T>>& P) {
    int n = P.size();
    assert(n >= 2);
    auto convex = convex_hull(P);
    n = convex.size();
    if (n == 1) return {0, 1};
    if (n == 2) return {convex[0], convex[1]};
    Polygon<T> Q;
    for (int i : convex) Q.emplace_back(P[i]);
    auto [i, j] = convex_diameter(Q);
    return {convex[i], convex[j]};
}

}  // namespace geometry