#define PROBLEM "https://yukicoder.me/problems/no/665"

#include "polynomial/lagrange_interpolation.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint1000000007;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    long long n;
    int k;
    std::cin >> n >> k;
    std::vector<mint> A(k + 2, 0);
    for (int i = 1; i <= k + 1; i++) A[i] = A[i - 1] + ((mint)i).pow(k);
    std::cout << lagrange_interpolation(A, (mint)n) << '\n';
}