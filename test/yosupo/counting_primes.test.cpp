#define PROBLEM "https://judge.yosupo.jp/problem/bitwise_xor_convolution"

#include "math/counting_primes.hpp"
#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    long long N;
    std::cin >> N;

    std::cout << counting_primes(N) << "\n";
    return 0;
}