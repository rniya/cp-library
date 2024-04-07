#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_D"

#include <iostream>
#include <set>
#include "util/Dice.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n;
    std::cin >> n;
    std::set<Dice> s;
    std::vector<int> v(6);
    for (size_t i = 0; i < n; i++) {
        for (int j = 0; j < 6; j++) std::cin >> v[j];
        Dice d(v);
        s.emplace(d.identifier());
    }
    std::cout << (s.size() == n ? "Yes" : "No") << '\n';
    return 0;
}