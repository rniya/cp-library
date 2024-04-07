#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_C"

#include <iostream>
#include "util/Dice.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::vector<int> u(6), v(6);
    for (int i = 0; i < 6; i++) std::cin >> u[i];
    for (int i = 0; i < 6; i++) std::cin >> v[i];

    Dice d1(u), d2(v);
    std::cout << (d1.identifier() == d2.identifier() ? "Yes" : "No") << '\n';
    return 0;
}