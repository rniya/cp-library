#define PROBLEM "https://yukicoder.me/problems/no/1984"

#include <iostream>
#include "optimization/BinaryOptimization.hpp"

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
    BinaryOptimization<long long, false> BOPT(N + M + K);
    for (int i = 0; i < N; i++) {
        int L;
        std::cin >> L;
        for (; L--;) {
            int A;
            std::cin >> A;
            A--;
            BOPT.add(i, N + M + A, {0, 0, -inf, 0});
        }
        BOPT.add(i, {0, E[i]});
    }
    for (int i = 0; i < M; i++) BOPT.add(N + i, {F[i], 0});
    for (int i = 0; i < K; i++) BOPT.add(N + M + i, {0, -V[i]});
    for (; P--;) {
        int I, J;
        std::cin >> I >> J;
        I--, J--;
        BOPT.add(I, N + J, {0, 0, -inf, 0});
    }

    auto [C, res] = BOPT.solve();
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