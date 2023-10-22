#define PROBLEM "https://yukicoder.me/problems/no/2513"

#include <iostream>
#include "polynomial/difference_product.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> A(N);
    for (int& x : A) std::cin >> x;

    mint ans = difference_product<mint>(A);
    std::cout << ans.val() << '\n';
    return 0;
}