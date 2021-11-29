#define PROBLEM "https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind"
#define IGNORE

#include "../../base.hpp"
#include "../../convolution/NumberTheoreticTransform.hpp"
#include "../../modulo/modint.hpp"
#include "../../polynomial/StirlingSecond.hpp"

using mint = modint<998244353>;
using FPS = FormalPowerSeries<mint>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    NumberTheoreticTransform<998244353> NTT;
    auto mul = [&](const FPS::Poly& a, const FPS::Poly& b) {
        auto res = NTT.multiply(a, b);
        return FPS::Poly(res.begin(), res.end());
    };
    FPS::set_mul(mul);

    int N;
    cin >> N;
    FPS ans = StirlingSecond<mint>(N);
    for (int i = 0; i <= N; i++) cout << ans[i] << (i == N ? '\n' : ' ');
}