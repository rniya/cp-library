#define PROBLEM "https://judge.yosupo.jp/problem/division_of_polynomials"

#include "polynomial/FormalPowerSeries.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;
using Poly = FormalPowerSeries<mint>;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;
    Poly f(N), g(M);
    for (int i = 0; i < N; i++) std::cin >> f[i];
    for (int i = 0; i < M; i++) std::cin >> g[i];

    auto q = f / g, r = f % g;
    std::cout << q.size() << ' ' << r.size() << '\n';
    for (size_t i = 0; i < q.size(); i++) std::cout << q[i] << (i + 1 == q.size() ? '\n' : ' ');
    for (size_t i = 0; i < r.size(); i++) std::cout << r[i] << (i + 1 == r.size() ? '\n' : ' ');
}