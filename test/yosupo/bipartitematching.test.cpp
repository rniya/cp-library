#define PROBLEM "https://judge.yosupo.jp/problem/bipartitematching"

#include "../../base.hpp"
#include "../../flow/HopcroftKarp.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int L, R, M;
    cin >> L >> R >> M;

    HopcroftKarp HK(L, R);
    for (; M--;) {
        int a, b;
        cin >> a >> b;
        HK.add_edge(a, b);
    }

    auto ans = HK.max_matching();
    cout << ans.size() << '\n';
    for (auto p : ans) cout << p.first << ' ' << p.second << '\n';
}