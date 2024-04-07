#define PROBLEM "https://yukicoder.me/problems/no/1678"

#include <iostream>
#include "graph/PrimalDualonDAG.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, K;
    std::cin >> N >> K;

    PrimalDualonDAG<int, long long> PD(2 * N + 1);
    int s = N, t = 2 * N;
    for (int i = 0; i < N; i++) {
        int A, M;
        std::cin >> A >> M;
        PD.add_edge(N + i, i, K, A);
        PD.add_edge(i, N + i + 1, K, -A);
        PD.add_edge(N + i, N + i + 1, K, 0);
        for (; M--;) {
            int B;
            std::cin >> B;
            PD.add_edge(--B, i, 1, 0);
        }
    }

    long long ans = -PD.min_cost_flow(s, t, K);
    std::cout << ans << '\n';
}