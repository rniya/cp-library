#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../../base.hpp"
#include "../../graph/BlockCutTree.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    BlockCutTree BCT(N);
    for (; M--;) {
        int a, b;
        cin >> a >> b;
        BCT.add_edge(a, b);
    }

    BCT.build();
    auto ans = BCT.two_edge_connected_components();
    cout << ans.size() << '\n';
    for (auto& v : ans) {
        cout << v.size();
        for (int& x : v) cout << ' ' << x;
        cout << '\n';
    }
}