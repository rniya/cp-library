#define PROBLEM "https://yukicoder.me/problems/no/1984"

#include <iostream>
#include "graph/ProjectSelectionProblem.hpp"

const long long inf = 1LL << 40;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, M, K, P;
    std::cin >> N >> M >> K >> P;
    std::vector<int> E(N), F(M), V(K);
    for (int& val : E) std::cin >> val;
    for (int& val : F) std::cin >> val;
    for (int& val : V) std::cin >> val;
    ProjectSelectionProblem<long long> PSP(N + M + K);
    for (int i = 0; i < N; i++) {
        int L;
        std::cin >> L;
        for (; L--;) {
            int A;
            std::cin >> A;
            A--;
            PSP.add_cost_10(i, N + M + A, inf);
        }
        PSP.add_profit_1(i, E[i]);
    }
    for (int i = 0; i < M; i++) PSP.add_profit_0(N + i, F[i]);
    for (int i = 0; i < K; i++) PSP.add_cost_1(N + M + i, V[i]);
    for (; P--;) {
        int I, J;
        std::cin >> I >> J;
        I--, J--;
        PSP.add_cost_10(I, N + J, inf);
    }

    auto [C, res] = PSP.max_profit();
    std::cout << C << '\n';
    for (int i = N; i < N + M; i++) res[i] = not res[i];
    int T = 0;
    for (auto val : res) T += val;
    std::cout << T << '\n';
    for (int i = N + M; i < N + M + K; i++) {
        if (res[i]) {
            std::cout << "Preparation " << i - (N + M) + 1 << '\n';
        }
    }
    for (int i = 0; i < N; i++) {
        if (res[i]) {
            std::cout << "Goal " << i + 1 << '\n';
        }
    }
    for (int i = N; i < N + M; i++) {
        if (res[i]) {
            std::cout << "Action " << i - N + 1 << '\n';
        }
    }
    return 0;
}