#define PROBLEM "https://judge.yosupo.jp/problem/number_of_increasing_sequences_between_two_sequences"

#include "math/number_of_increasing_sequences_between_two_sequences.hpp"
#include <iostream>
#include "atcoder/modint"

using mint = atcoder::modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::vector<int> A(N), B(N);
    for (int i = 0; i < N; i++) std::cin >> A[i];
    for (int i = 0; i < N; i++) std::cin >> B[i];

    auto ans = number_of_increasing_sequences_between_two_sequences<mint>(A, B);
    std::cout << ans.val() << "\n";
    return 0;
}