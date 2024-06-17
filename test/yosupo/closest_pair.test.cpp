#define PROBLEM "https://judge.yosupo.jp/problem/closest_pair"

#include "geometry/closest_pair.hpp"
#include <iostream>

using namespace geometry;

void solve() {
    int N;
    std::cin >> N;
    std::vector<Point<double>> P;
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        P.emplace_back(x, y);
    }

    auto [i, j, val] = closest_pair(P);
    std::cout << i << " " << j << "\n";
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    for (; T--;) solve();
}