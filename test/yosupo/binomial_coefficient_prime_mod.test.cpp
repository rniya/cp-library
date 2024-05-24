#include <iostream>
#include "atcoder/modint"
#include "math/binomial.hpp"

using mint = atcoder::modint;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int T, m;
    std::cin >> T >> m;
    mint::set_mod(m);
    Binomial<mint> BINOM;
    for (; T--;) {
        int n, k;
        std::cin >> n >> k;
        std::cout << BINOM.C(n, k).val() << '\n';
    }
    return 0;
}