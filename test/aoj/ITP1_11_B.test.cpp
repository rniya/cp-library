#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_B"

#include <iostream>
#include <map>
#include <utility>
#include "util/Dice.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::vector<int> v(6);
    for (int i = 0; i < 6; i++) std::cin >> v[i];

    Dice d(v);
    auto ds = d.make_all();
    std::map<std::pair<int, int>, int> mp;
    for (auto& x : ds) mp[{x.top(), x.front()}] = x.right();

    int q;
    std::cin >> q;
    for (; q--;) {
        int t, f;
        std::cin >> t >> f;
        std::cout << mp[{t, f}] << '\n';
    }
    return 0;
}