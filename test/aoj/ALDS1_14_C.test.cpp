#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C"

#include <iostream>
#include "string/RollingHash2D.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int H, W;
    std::cin >> H >> W;
    std::vector<std::string> S(H);
    for (auto& s : S) std::cin >> s;
    int R, C;
    std::cin >> R >> C;
    std::vector<std::string> T(R);
    for (auto& t : T) std::cin >> t;

    RollingHash2D RH;
    auto a = RH.build(S);
    auto correct = RH.get(T);

    for (int i = 0; i + R <= H; i++) {
        for (int j = 0; j + C <= W; j++) {
            if (RH.query(a, i, i + R, j, j + C) == correct) {
                std::cout << i << ' ' << j << '\n';
            }
        }
    }
    return 0;
}