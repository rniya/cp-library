#define PROBLEM "https://yukicoder.me/problems/no/1302"

#include "../../base.hpp"
#include "../../combinatorics/combination.hpp"
#include "../../convolution/NumberTheoreticTransform.hpp"
#include "../../modulo/modint.hpp"
#include "../../polynomial/FormalPowerSeries.hpp"

using mint = modint<998244353>;
using FPS = FormalPowerSeries<mint>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Combination<mint> COM(100010);
    NumberTheoreticTransform<998244353> NTT;
    auto mul = [&](const FPS::Poly& a, const FPS::Poly& b) {
        auto res = NTT.multiply(a, b);
        return FPS::Poly(res.begin(), res.end());
    };
    FPS::set_mul(mul);

    int N;
    cin >> N;
    FPS a(N);
    for (int i = 0; i < N; i++) a[i] = (i + 1) * COM.finv(i);
    mint ans = a.pow(N)[N - 2] * COM.fac(N - 2) / mint(N).pow(N - 2);

    cout << ans << '\n';
}