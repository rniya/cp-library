#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2903"

#include <iostream>
#include "graph/BinaryOptimization.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int R, C;
    std::cin >> R >> C;
    std::vector<std::string> S(R);
    for (int i = 0; i < R; i++) std::cin >> S[i];

    auto id = [&](int i, int j) { return i * C + j; };
    BinaryOptimization<int, false> BOPT(R * C);
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
                    BOPT.add(id(i, j), id(nx, ny), {1, 0, 0, 0});
                else
                    BOPT.add(id(i, j), id(nx, ny), {0, 0, 0, 1});
            }
        }
    }

    std::cout << ans - BOPT.solve().first << '\n';
}