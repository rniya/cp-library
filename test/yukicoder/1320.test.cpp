#define PROBLEM "https://yukicoder.me/problems/no/1320"

#include <iostream>
#include "graph/DirectedShortestCycle.hpp"
#include "graph/UndirectedShortestCycle.hpp"

constexpr long long inf = (1LL << 60) - 1;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int T;
    std::cin >> T;
    int N, M;
    std::cin >> N >> M;
    long long ans = inf;
    if (T == 0) {
        UndirectedShortestCycle<long long> G(N);
        for (; M--;) {
            int u, v, w;
            std::cin >> u >> v >> w;
            G.add_edge(--u, --v, w);
        }
        for (int i = 0; i < N; i++) ans = std::min(ans, std::get<0>(G.solve(i)));
    } else {
        DirectedShortestCycle<long long> G(N);
        for (; M--;) {
            int u, v, w;
            std::cin >> u >> v >> w;
            G.add_edge(--u, --v, w);
        }
        for (int i = 0; i < N; i++) ans = std::min(ans, std::get<0>(G.solve(i)));
    }

    std::cout << (ans == inf ? -1 : ans) << '\n';
    return 0;
}