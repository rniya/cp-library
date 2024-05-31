#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex"

#include "convolution/min_plus_convolution_convex_convex.hpp"
#include <iostream>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::vector<int> a(N), b(M);
    for (int i = 0; i < N; i++) std::cin >> a[i];
    for (int i = 0; i < M; i++) std::cin >> b[i];
    auto c = min_plus_convolution_convex_convex(a, b);
    for (int i = 0; i < N + M - 1; i++) std::cout << c[i] << (i + 1 == N + M - 1 ? '\n' : ' ');
    return 0;
}