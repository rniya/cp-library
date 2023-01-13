#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_A"

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

    int ans = TD.get_diameter_path().first;
    cout << ans << '\n';
    return 0;
}