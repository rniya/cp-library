#define PROBLEM "https://yukicoder.me/problems/no/1289"

#include "convolution/set_function.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<int> A(1 << N);
    int sum = 0;
    for (int i = 0; i < (1 << N); i++) {
        std::cin >> A[i];
        sum += A[i];
    }

    set_function::subset_zeta_transform(A);
    mint ans = 0, inv = mint(sum).inv();

    for (int mask = 0; mask < (1 << N) - 1; mask++) {
        mint add = (1 - inv * A[mask]).inv();
        if (__builtin_popcount((1 << N) - 1 - mask) & 1)
            ans += add;
        else
            ans -= add;
    }

    std::cout << ans << '\n';
    return 0;
}