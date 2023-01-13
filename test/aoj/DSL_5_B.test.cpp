#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/5/DSL_5_B"

#include "base.hpp"
#include "datastructure/CumulativeSum2D.hpp"

const int MAX_X = 1010;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    vector<vector<int>> v(MAX_X, vector<int>(MAX_X, 0));
    for (; N--;) {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        ++v[a][b];
        ++v[c][d];
        --v[a][d];
        --v[c][b];
    }

    CumulativeSum2D<int> CS(v);
    int ans = 0;
    for (int i = 0; i < MAX_X; i++) {
        for (int j = 0; j < MAX_X; j++) {
            ans = max(ans, CS.query(0, i, 0, j));
        }
    }

    cout << ans << '\n';
}