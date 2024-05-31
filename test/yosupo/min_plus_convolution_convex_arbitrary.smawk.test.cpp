#define PROBLEM "https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary"

#include <cassert>
#include <iostream>
#include "optimization/smawk.hpp"

template <typename T>
std::vector<T> min_plus_convolution_convex_arbitrary(const std::vector<T>& a, const std::vector<T>& b) {
    int n = a.size(), m = b.size();
    assert(n and m);
    for (int i = 0; i + 2 < n; i++) assert(a[i + 1] - a[i] <= a[i + 2] - a[i + 1]);
    auto f = [&](int i, int j) { return a[i - j] + b[j]; };
    auto select = [&](int i, int j, int k) {
        if (i < k) return false;
        if (n <= i - j) return true;
        return f(i, j) >= f(i, k);
    };
    auto argmin = smawk(n + m - 1, m, select);
    std::vector<T> c(n + m - 1);
    for (int i = 0; i < n + m - 1; i++) c[i] = f(i, argmin[i]);
    return c;
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::vector<int> a(N), b(M);
    for (int i = 0; i < N; i++) std::cin >> a[i];
    for (int i = 0; i < M; i++) std::cin >> b[i];
    auto c = min_plus_convolution_convex_arbitrary(a, b);
    for (int i = 0; i < N + M - 1; i++) std::cout << c[i] << (i + 1 == N + M - 1 ? '\n' : ' ');
    return 0;
}