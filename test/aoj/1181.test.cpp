#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1181"

#include <iostream>
#include <string>
#include "util/Dice.hpp"

const int dx[4] = {1, 0, -1, 0}, dy[4] = {0, 1, 0, -1};
const int MAX = 110;
const int aspect[4] = {2, 4, 3, 1};
const std::string S = "ENWS";

void solve(int n) {
    std::vector<std::vector<int>> top(2 * MAX, std::vector<int>(2 * MAX, -1));
    std::vector<std::vector<int>> cnt(2 * MAX, std::vector<int>(2 * MAX, 0));

    auto ROLL = [&](int t, int f) {
        int x = MAX, y = MAX;
        Dice d(t, f);
        while (1) {
            cnt[x][y]++;
            int nxt = -1, Max = 0;
            for (int i = 0; i < 4; i++) {
                int nx = x + dx[i], ny = y + dy[i];
                if (cnt[nx][ny] >= cnt[x][y] - 1) continue;
                int s = d[aspect[i]];
                if (4 <= s && Max < s) {
                    Max = s;
                    nxt = i;
                }
            }
            if (nxt < 0) break;
            d.rollc(S[nxt]);
            --cnt[x][y];
            x += dx[nxt];
            y += dy[nxt];
        }
        top[x][y] = d.top();
    };
    for (; n--;) {
        int t, f;
        std::cin >> t >> f;
        ROLL(t, f);
    }

    std::vector<int> ans(6, 0);
    for (int i = 0; i < 2 * MAX; i++) {
        for (int j = 0; j < 2 * MAX; j++) {
            if (~top[i][j]) {
                ans[top[i][j] - 1]++;
            }
        }
    }

    for (int i = 0; i < 6; i++) std::cout << ans[i] << (i + 1 == 6 ? '\n' : ' ');
}

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int n;
    while (std::cin >> n, n) {
        solve(n);
    }
}