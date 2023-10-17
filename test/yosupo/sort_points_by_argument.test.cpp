#define PROBLEM "https://judge.yosupo.jp/problem/sort_points_by_argument"

#include "geometry/sort_points_by_argument.hpp"
#include <iostream>

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<Point<long long>> P(N);
    for (auto& p : P) std::cin >> p;
    auto ord = sort_points_by_argument(P);
    for (int& idx : ord) std::cout << P[idx].x << ' ' << P[idx].y << '\n';
}
