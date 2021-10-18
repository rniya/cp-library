#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2903"

#include "../../base.hpp"
#include "../../flow/ProjectSelectionProblem.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int R, C;
    cin >> R >> C;
    vector<string> S(R);
    for (int i = 0; i < R; i++) cin >> S[i];

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
                    PSP.x_false_y_false_profit(id(i, j), id(nx, ny), 1);
                else
                    PSP.x_true_y_true_profit(id(i, j), id(nx, ny), 1);
            }
        }
    }

    cout << ans + PSP.solve() << '\n';
}