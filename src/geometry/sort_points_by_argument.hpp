#pragma once
#include <utility>
#include <vector>
#include "Point.hpp"

namespace geometry {

template <typename T> std::vector<int> sort_points_by_argument(const std::vector<Point<T>>& P) {}

template <typename T> std::vector<int> sort_points_by_argument(const std::vector<std::pair<T, T>>& P) {
    std::vector<Point<T>> tmp;
    for (const auto& [x, y] : P) tmp.emplace_back(x, y);
    return sort_points_by_argument(tmp);
}

}  // namespace geometry