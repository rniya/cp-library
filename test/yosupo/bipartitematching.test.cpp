#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../../base.hpp"
#include "../../flow/BipartiteMathcing.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int L, R, M;
    cin >> L >> R >> M;

    BipartiteMatching BM(L, R);
    for (; M--;) {
        int a, b;
        cin >> a >> b;
        BM.add_edge(a, b);
    }

    BM.solve();
    auto ans = BM.max_matching();
    cout << ans.size() << '\n';
    for (auto p : ans) cout << p.first << ' ' << p.second << '\n';
    return 0;
}