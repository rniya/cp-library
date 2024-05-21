#define PROBLEM "https://judge.yosupo.jp/problem/wildcard_pattern_matching"

#include "string/wildcard_pattern_matching.hpp"
#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::string S, T;
    std::cin >> S >> T;

    auto ans = wildcard_pattern_matching(S, T, '*');
    for (auto x : ans) std::cout << x;
    std::cout << "\n";
    return 0;
}