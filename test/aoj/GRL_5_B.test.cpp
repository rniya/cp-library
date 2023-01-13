#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_B"

#include "base.hpp"
#include "tree/TreeDiameter.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    TreeDiameter<> TD(n);
    for (int i = 0; i < n - 1; i++) {
        int s, t, w;
        cin >> s >> t >> w;
        TD.add_edge(s, t, w);
    }

    vector<int> ans = TD.farthest_distance();
    for (int i = 0; i < n; i++) cout << ans[i] << '\n';
    return 0;
}