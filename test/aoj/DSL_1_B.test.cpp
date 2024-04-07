#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"

#include <iostream>
#include "datastructure/PotentializedUnionFind.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n, q;
    std::cin >> n >> q;

    PotentializedUnionFind<int> UF(n);

    for (; q--;) {
        int c, x, y, z;
        std::cin >> c >> x >> y;
        if (!c) {
            std::cin >> z;
            UF.merge(x, y, z);
        } else {
            if (UF.same(x, y))
                std::cout << UF.diff(x, y) << '\n';
            else
                std::cout << '?' << '\n';
        }
    }
    return 0;
}