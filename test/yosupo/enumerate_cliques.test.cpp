#define PROBLEM "https://judge.yosupo.jp/problem/enumerate_cliques"

#include "graph/enumerate_cliques.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;
    std::vector<int> x(N);
    for (int i = 0; i < N; i++) std::cin >> x[i];
    std::vector<std::vector<bool>> G(N, std::vector<bool>(N, false));
    for (; M--;) {
        int u, v;
        std::cin >> u >> v;
        G[u][v] = G[v][u] = true;
    }

    auto calc = [&](std::vector<int> clique) {
        mint res = 1;
        for (int& v : clique) res *= x[v];
        return res;
    };
    mint ans = 0;
    for (const auto& clique : enumerate_cliques(G)) ans += calc(clique);
    std::cout << ans << '\n';
    return 0;
}