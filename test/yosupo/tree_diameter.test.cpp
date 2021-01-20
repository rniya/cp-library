#define PROBLEM "https://judge.yosupo.jp/problem/tree_diameter"

#include "../../base.hpp"
#include "../../tree/TreeDiameter.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    TreeDiameter<long long> TD(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        long long c;
        cin >> a >> b >> c;
        TD.add_edge(a, b, c);
    }

    long long X = TD.build();
    vector<int> ans = TD.restore();
    int Y = ans.size();
    cout << X << ' ' << Y << '\n';
    for (int i = 0; i < Y; i++) cout << ans[i] << (i + 1 == Y ? '\n' : ' ');
}