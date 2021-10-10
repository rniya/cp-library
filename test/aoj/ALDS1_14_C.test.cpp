#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/ALDS1_14_C"

#include "../../base.hpp"
#include "../../string/RollingHash2D.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int H, W;
    cin >> H >> W;
    vector<string> S(H);
    for (auto& s : S) cin >> s;
    int R, C;
    cin >> R >> C;
    vector<string> T(R);
    for (auto& t : T) cin >> t;

    RollingHash2D RH;
    auto a = RH.build(S);
    auto correct = RH.get(T);

    for (int i = 0; i + R <= H; i++) {
        for (int j = 0; j + C <= W; j++) {
            if (RH.query(a, i, i + R, j, j + C) == correct) {
                cout << i << ' ' << j << '\n';
            }
        }
    }
    return 0;
}