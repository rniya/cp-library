#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include <iostream>
#include "tree/TreeDiameter.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;

    TreeDiameter<long long> TD(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        long long c;
        std::cin >> a >> b >> c;
        TD.add_edge(a, b, c);
    }

    auto res = TD.get_diameter_path();
    long long X = res.first;
    auto ans = res.second;
    int Y = ans.size();
    std::cout << X << ' ' << Y << '\n';
    for (int i = 0; i < Y; i++) std::cout << ans[i] << (i + 1 == Y ? '\n' : ' ');
    return 0;
}