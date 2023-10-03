#pragma once
#include <tuple>
#include "Polygon.hpp"
#include "distance.hpp"

namespace geometry {

template <typename T> std::tuple<int, int, T> convex_diameter(const Polygon<T>& convex) {
    int n = convex.size();
    auto [si, sj] = [&] {
        auto [it_min, it_max] = std::minmax_element(begin(convex), end(convex));
        return std::pair<int, int>{it_min - begin(convex), it_max - begin(convex)};
    }();
    T max_dist = -1;
    std::pair<int, int> argmax{-1, -1};
    for (int i = si, j = sj; i != sj or j != si;) {
        T d = distance(convex[i], convex[j]);
        if (max_dist < d) {
            max_dist = d;
            argmax = {i, j};
        }
        int ni = (i + 1 == n ? 0 : i + 1), nj = (j + 1 == n ? 0 : j + 1);
        if ((convex[ni] - convex[i]).det(convex[nj] - convex[j]) < 0)
            i = ni;
        else
            j = nj;
    }
    return {argmax.first, argmax.second, max_dist};
}

}  // namespace geometry