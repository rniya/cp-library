#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include <iostream>
#include <string>
#include "graph/TwoSAT.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::string p, cnf;
    int N, M;
    std::cin >> p >> cnf >> N >> M;

    TwoSAT TS(N + 1);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        std::cin >> a >> b >> c;
        TS.add_clause(abs(a), (a > 0), abs(b), (b > 0));
    }

    if (!TS.satisfiable()) {
        std::cout << "s UNSATISFIABLE" << '\n';
        return 0;
    }
    std::cout << "s SATISFIABLE" << '\n';
    std::cout << "v ";
    auto ans = TS.answer();
    for (int i = 1; i <= N; i++) std::cout << (ans[i] ? i : -i) << ' ';
    std::cout << "0\n";
    return 0;
}