#define PROBLEM "https://judge.yosupo.jp/problem/shortest_path"

#include "../../base.hpp"
#include "../../graph/Dijkstra.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M, s, t;
    cin >> N >> M >> s >> t;

    Dijkstra<long long> D(N);
    for (int i = 0; i < M; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        D.add_edge(a, b, c);
    }

    D.build(s);
    vector<int> ans = D.restore(t);
    if (ans.empty()) {
        cout << -1 << '\n';
        return 0;
    }
    cout << D[t] << ' ' << ans.size() - 1 << '\n';
    for (int i = 0; i + 1 < ans.size(); i++) {
        cout << ans[i] << ' ' << ans[i + 1] << '\n';
    }
}