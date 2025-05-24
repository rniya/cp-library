#define PROBLEM "https://judge.yosupo.jp/problem/bell_number"

#include "enumerative_combinatorics/bell_number.hpp"
#include <iostream>
#include "atcoder/modint"

using mint = atcoder::modint998244353;

void solve() {
    int N;
    std::cin >> N;
    auto res = bell_number<mint>(N);
    for (int i = 0; i <= N; i++) {
        std::cout << res[i].val() << " \n"[i == N];
    }
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    solve();
    return 0;
}