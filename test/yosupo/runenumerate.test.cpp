#define PROBLEM "https://judge.yosupo.jp/problem/runenumerate"

#include <iostream>
#include "string/run_enumerate.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::string S;
    std::cin >> S;

    auto res = run_enumerate::enumerate(S);
    std::sort(res.begin(), res.end());
    std::cout << res.size() << '\n';
    for (auto [t, l, r] : res) std::cout << t << ' ' << l << ' ' << r << '\n';
    return 0;
}