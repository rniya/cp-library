#pragma once
#include <algorithm>
#include <limits>
#include <numeric>
#include <tuple>
#include <utility>
#include <vector>
#include "Point.hpp"

namespace geometry {

template <typename T> std::tuple<int, int, T> closest_pair(std::vector<Point<T>> P) {
    int n = P.size();
    if (n == 1) return {0, 0, 0};
    std::vector<int> ord(n);
    std::iota(begin(ord), end(ord), 0);
    std::sort(begin(ord), end(ord), [&](int p, int q) { return P[p] < P[q]; });
    T inf = std::numeric_limits<T>::max(), min_dist = inf;
    std::pair<int, int> ans{-1, -1};

    auto dfs = [&](auto self, int l, int r) -> T {
        if (r - l <= 1) return inf;
        int mid = (l + r) >> 1;
        auto x_mid = P[ord[mid]].x;
        auto res = std::min(self(self, l, mid), self(self, mid, r));
        std::inplace_merge(begin(ord) + l, begin(ord) + mid, begin(ord) + r,
                           [&](int p, int q) { return P[p].y < P[q].y; });
        std::vector<int> tmp;
        for (int i = l; i < r; i++) {
            if (sgn(std::abs(P[ord[i]].x - x_mid) - res) >= 0) continue;
            for (int j = int(tmp.size()) - 1; j >= 0; j--) {
                auto d = P[ord[i]] - P[tmp[j]];
                if (sgn(d.y - res) >= 0) break;
                if (d.norm() < res) {
                    res = d.norm();
                    if (d.norm() < min_dist) {
                        min_dist = d.norm();
                        ans = {ord[i], tmp[j]};
                    }
                }
            }
            tmp.emplace_back(ord[i]);
        }
        return res;
    };
    dfs(dfs, 0, n);
    return {ans.first, ans.second, min_dist};
}

}  // namespace geometry