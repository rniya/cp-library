#define PROBLEM "https://judge.yosupo.jp/problem/longest_increasing_subsequence"

#include "math/longest_increasing_subsequence.hpp"
#include <iostream>

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int& x : A) std::cin >> x;

    auto ans = longest_increasing_subsequence_restore(A);
    int K = longest_increasing_subsequence(A);
    std::cout << K << '\n';
    for (int i = 0; i < K; i++) std::cout << ans[i] << (i + 1 == K ? '\n' : ' ');
}