#define PROBLEM "https://judge.yosupo.jp/problem/two_edge_connected_components"

#include "../../base.hpp"
#include "../../graph/TwoEdgeConnectedComponents.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    TwoEdgeConnectedComponents TECC(N);
    for (int i = 0; i < M; i++) {
        int a, b;
        cin >> a >> b;
        TECC.add_edge(a, b);
    }

    int K = TECC.build();
    cout << K << '\n';
    for (int i = 0; i < K; i++) {
        cout << TECC.C[i].size();
        for (int v : TECC.C[i]) cout << ' ' << v;
        cout << '\n';
    }
}