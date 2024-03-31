#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2903"

#include <iostream>
#include "graph/ProjectSelectionProblem.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int R, C;
    std::cin >> R >> C;
    std::vector<std::string> S(R);
    for (int i = 0; i < R; i++) std::cin >> S[i];

    auto id = [&](int i, int j) { return i * C + j; };
    ProjectSelectionProblem<int> PSP(R * C);
    int ans = 0;
    for (int i = 0; i < R; i++) {
        for (int j = 0; j < C; j++) {
            if (S[i][j] != '#') continue;
            ans++;
            for (int k = 0; k < 2; k++) {
                int nx = i + k, ny = j + 1 - k;
                if (R <= nx || C <= ny) continue;
                if (S[nx][ny] != '#') continue;
                if (!k)
                    PSP.add_profit_00(id(i, j), id(nx, ny), 1);
                else
                    PSP.add_profit_11(id(i, j), id(nx, ny), 1);
            }
        }
    }

    std::cout << ans - PSP.max_profit().first << '\n';
}