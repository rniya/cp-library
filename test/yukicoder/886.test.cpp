#define PROBLEM "https://yukicoder.me/problems/no/886"

#include "math/gcd_convolution.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint1000000007;
const int MAX_H = 3000010;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int H, W;
    std::cin >> H >> W;

    std::vector<mint> a(MAX_H, 0), b(MAX_H, 0);
    for (int i = 0; i < H; i++) a[i] = (H - i) * (i > 0 ? 2 : 1);
    for (int i = 0; i < W; i++) b[i] = (W - i) * (i > 0 ? 2 : 1);

    auto c = gcd_convolution::gcd_convolution(a, b);
    mint ans = c[1] / 2;
    std::cout << ans << '\n';
    return 0;
}