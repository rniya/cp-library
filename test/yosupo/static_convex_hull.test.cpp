#define PROBLEM "https://judge.yosupo.jp/problem/static_convex_hull"

#include <iostream>
#include "geometry/convex_hull.hpp"

using namespace geometry;

void solve() {
    int N;
    std::cin >> N;
    std::vector<Point<long long>> P;
    for (int i = 0; i < N; i++) {
        int x, y;
        std::cin >> x >> y;
        P.emplace_back(x, y);
    }

    auto res = convex_hull(P);
    std::cout << res.size() << "\n";
    for (int i : res) std::cout << P[i].x << " " << P[i].y << "\n";
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int T;
    std::cin >> T;
    for (; T--;) solve();
    return 0;
}