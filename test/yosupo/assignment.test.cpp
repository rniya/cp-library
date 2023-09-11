#define PROBLEM "https://judge.yosupo.jp/problem/assignment"

#include <iostream>
#include "graph/hungarian.hpp"

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector a(N, std::vector<long long>(N));
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            std::cin >> a[i][j];
        }
    }
    auto [X, p] = hungarian(a);
    std::cout << X << '\n';
    for (int i = 0; i < N; i++) std::cout << p[i] << (i + 1 == N ? '\n' : ' ');
    return 0;
}