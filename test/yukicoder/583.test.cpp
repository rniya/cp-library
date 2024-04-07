#define PROBLEM "https://yukicoder.me/problems/no/583"

#include <iostream>
#include "graph/EulerianTrail.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, M;
    std::cin >> N >> M;

    EulerianTrail<false> ET(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        std::cin >> a >> b;
        ET.add_edge(a, b);
    }

    std::cout << (ET.solve_semi().size() == 1 ? "YES" : "NO") << '\n';
}