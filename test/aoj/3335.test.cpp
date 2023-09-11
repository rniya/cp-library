#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/3335"

#include <iostream>
#include "atcoder/modint"
#include "math/binomial.hpp"
#include "math/count_young_paths.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    Binomial<mint> BINOM;
    std::string S;
    std::cin >> S;

    std::vector<int> lim;
    int one = 0;
    for (int i = 0; i < int(S.size()); i++) {
        if (S[i] != '1') continue;
        lim.emplace_back(i - one + 1);
        one++;
    }
    if (one == 0) {
        std::cout << 1 << '\n';
        return 0;
    }
    std::vector<mint> init(one, 0);
    init[0] = 1;
    auto res = count_young_paths(lim, init, BINOM);
    mint ans = accumulate(begin(res), end(res), mint(0));
    std::cout << ans.val() << '\n';
    return 0;
}