#define PROBLEM "https://yukicoder.me/problems/no/886"

#include "../../base.hpp"
#include "../../convolution/gcd_convolution.hpp"
#include "../../modulo/modint.hpp"

using mint = modint<1000000007>;
const int MAX_H = 3000010;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;

    vector<mint> a(MAX_H, 0), b(MAX_H, 0);
    for (int i = 0; i < H; i++) a[i] = (H - i) * (i > 0 ? 2 : 1);
    for (int i = 0; i < W; i++) b[i] = (W - i) * (i > 0 ? 2 : 1);

    auto c = gcd_convolution::gcd_convolution(a, b);
    mint ans = c[1] / 2;
    cout << ans << '\n';
    return 0;
}