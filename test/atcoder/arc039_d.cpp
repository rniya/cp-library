#define IGNORE

#define PROBLEM "https://atcoder.jp/contests/arc039/tasks/arc039_d"

#include "../../base.hpp"
#include "../../graph/TwoEdgeConnectedComponents.hpp"
#include "../../tree/LowestCommonAncestor.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, M;
    cin >> N >> M;

    TwoEdgeConnectedComponents TECC(N);
    for (int i = 0; i < M; i++) {
        int X, Y;
        cin >> X >> Y;
        TECC.add_edge(--X, --Y);
    }
    int n = TECC.build();

    LowestCommonAncestor LCA(n);
    for (int v = 0; v < n; v++) {
        for (int u : TECC.T[v]) {
            if (v < u) LCA.add_edge(v, u);
        }
    }
    LCA.build();

    int Q;
    cin >> Q;
    for (; Q--;) {
        int A, B, C;
        cin >> A >> B >> C;
        A = TECC[--A], B = TECC[--B], C = TECC[--C];
        cout << (LCA.distance(A, C) == LCA.distance(A, B) + LCA.distance(B, C) ? "OK" : "NG") << '\n';
    }
}