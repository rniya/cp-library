#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_A"

#include <iostream>
#include "util/Dice.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::vector<int> v(6);
    for (int& x : v) std::cin >> x;
    Dice d(v);
    std::string S;
    std::cin >> S;
    for (char& c : S) d.rollc(c);
    std::cout << d.top() << '\n';
    return 0;
}