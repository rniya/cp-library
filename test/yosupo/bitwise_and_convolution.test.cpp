#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_and_convolution"

#include "math/set_function.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<mint> a(1 << N), b(1 << N);
    for (int i = 0; i < (1 << N); i++) std::cin >> a[i];
    for (int i = 0; i < (1 << N); i++) std::cin >> b[i];

    std::vector<mint> c = set_function::and_convolution(a, b);
    for (int i = 0; i < (1 << N); i++) std::cout << c[i] << (i + 1 == (1 << N) ? '\n' : ' ');
    return 0;
}