#pragma once
#include <algorithm>
#include <numeric>
#include <utility>
#include <vector>
#include "Point.hpp"

namespace geometry {

template <typename T> std::vector<int> sort_points_by_argument(const std::vector<Point<T>>& P) {
    auto type = [](const Point<T>& p) {
        if (p.x == 0 and p.y == 0) return 0;
        return (p.y < 0 or (p.y == 0 and p.x > 0)) ? -1 : 1;
    };
    int n = P.size();
    std::vector<int> res(n);
    std::iota(begin(res), end(res), 0);
    std::sort(begin(res), end(res), [&](int l, int r) {
        int L = type(P[l]), R = type(P[r]);
        return L != R ? L < R : P[l].x * P[r].y > P[l].y * P[r].x;
    });
    return res;
}

template <typename T> std::vector<int> sort_points_by_argument(const std::vector<std::pair<T, T>>& P) {
    std::vector<Point<T>> tmp;
    for (const auto& [x, y] : P) tmp.emplace_back(x, y);
    return sort_points_by_argument(tmp);
}

}  // namespace geometry