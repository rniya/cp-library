#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B"

#include <iostream>
#include "tree/TreeDiameter.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;

    TreeDiameter<> TD(n);
    for (int i = 0; i < n - 1; i++) {
        int s, t, w;
        std::cin >> s >> t >> w;
        TD.add_edge(s, t, w);
    }

    auto ans = TD.farthest_distance();
    for (int i = 0; i < n; i++) std::cout << ans[i] << '\n';
    return 0;
}