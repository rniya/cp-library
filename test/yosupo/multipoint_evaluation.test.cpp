#define PROBLEM "https://judge.yosupo.jp/problem/multipoint_evaluation"

#include "polynomial/multipoint_evaluation.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;
using Poly = FormalPowerSeries<mint>;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;
    Poly c(N);
    std::vector<mint> p(M);
    for (int i = 0; i < N; i++) std::cin >> c[i];
    for (int i = 0; i < M; i++) std::cin >> p[i];

    subproduct_tree<mint> tree(p);
    auto f = tree.multipoint_evaluation(c);
    for (int i = 0; i < M; i++) std::cout << f[i] << (i + 1 == M ? '\n' : ' ');
}