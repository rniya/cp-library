#pragma once
#include <algorithm>
#include <numeric>
#include <vector>
#include "Point.hpp"

namespace geometry {

template <typename T> std::vector<int> convex_hull(const std::vector<Point<T>>& P, bool inclusive = false) {
    int n = P.size();
    if (n == 0) return {};
    if (n == 1) return {0};
    if (n == 2) return (P[0] != P[1] or inclusive ? std::vector<int>{0, 1} : std::vector<int>{0});
    std::vector<int> ord(n);
    std::iota(ord.begin(), ord.end(), 0);
    std::sort(ord.begin(), ord.end(), [&](int l, int r) { return P[l] < P[r]; });
    std::vector<int> ch(n + 1, -1);
    int s = 0, t = 0;
    for (int _ = 0; _ < 2; _++, s = --t, std::reverse(ord.begin(), ord.end())) {
        for (int& i : ord) {
            for (; t >= s + 2; t--) {
                auto det = (P[ch[t - 1]] - P[ch[t - 2]]).det(P[i] - P[ch[t - 2]]);
                if (inclusive ? det >= 0 : det > 0) break;
            }
            ch[t++] = i;
        }
    }
    while (not inclusive and t >= 2 and P[ch[0]] == P[ch[t - 1]]) t--;
    return {begin(ch), begin(ch) + t};
}

}  // namespace geometry
