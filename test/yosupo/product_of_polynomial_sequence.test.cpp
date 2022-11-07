#define PROBLEM "https://judge.yosupo.jp/problem/product_of_polynomial_sequence"

#include "polynomial/FormalPowerSeries.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;
using FPS = FormalPowerSeries<mint>;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<FPS> fs;
    for (; N--;) {
        int d;
        std::cin >> d;
        FPS a(d + 1);
        for (int i = 0; i <= d; i++) std::cin >> a[i];
        fs.emplace_back(a);
    }

    auto res = FPS::product_of_polynomial_sequence(fs);
    for (size_t i = 0; i < res.size(); i++) std::cout << res[i] << (i + 1 == res.size() ? '\n' : ' ');
    return 0;
}