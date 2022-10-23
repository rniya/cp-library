#define PROBLEM "https://judge.yosupo.jp/problem/sharp_p_subset_sum"

#include "polynomial/subset_sum.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, T;
    std::cin >> N >> T;
    std::vector<int> s(N);
    for (int& x : s) std::cin >> x;

    auto res = subset_sum<mint>(s, T);
    for (int i = 1; i <= T; i++) std::cout << res[i] << (i == T ? '\n' : ' ');
}