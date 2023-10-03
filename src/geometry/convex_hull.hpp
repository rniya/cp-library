#pragma once
#include <algorithm>
#include <numeric>
#include <vector>
#include "Point.hpp"

namespace geometry {

template <typename T> std::vector<int> convex_hull(const std::vector<Point<T>>& P, bool inclusive = false) {
    int n = P.size();
    if (n == 1) return {0};
    if (n == 2) return {0, 1};
    std::vector<int> ord(n);
    std::iota(begin(ord), end(ord), 0);
    std::sort(begin(ord), end(ord), [&](int l, int r) { return P[l] < P[r]; });
    std::vector<int> ch(n + 1, -1);
    int s = 0, t = 0;
    for (int _ = 0; _ < 2; _++, s = --t, std::reverse(begin(ord), end(ord))) {
        for (int& i : ord) {
            for (; t >= s + 2; t--) {
                auto det = (P[ch[t - 1]] - P[ch[t - 2]]).det(P[i] - P[ch[t - 2]]);
                if (inclusive ? det >= 0 : det > 0) break;
            }
            ch[t++] = i;
        }
    }
    return {begin(ch), begin(ch) + t - (t == 2 and ch[0] == ch[1])};
}

}  // namespace geometry
