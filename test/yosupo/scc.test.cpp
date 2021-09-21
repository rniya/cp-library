#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../../base.hpp"
#include "../../graph/StronglyConnectedComponents.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    StronglyConnectedComponents SCC(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        SCC.add_edge(a, b);
    }

    auto res = SCC.build();
    cout << res.size() << '\n';
    for (auto& group : res) {
        cout << group.size();
        for (int& v : group) cout << ' ' << v;
        cout << '\n';
    }
}