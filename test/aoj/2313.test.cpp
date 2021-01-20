#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2313"

#include "../../base.hpp"
#include "../../flow/Dinic.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, E, Q;
    cin >> N >> E >> Q;

    Dinic<int, false> D(N);
    vector<vector<int>> edge(N, vector<int>(N, -1));
    for (int i = 0; i < E; i++) {
        int F, T;
        cin >> F >> T;
        --F, --T;
        edge[F][T] = edge[T][F] = D.add_edge(F, T, 1);
    }
    vector<int> M(Q), A(Q), B(Q);
    for (int i = 0; i < Q; i++) {
        cin >> M[i] >> A[i] >> B[i];
        if (~edge[--A[i]][--B[i]]) continue;
        edge[A[i]][B[i]] = edge[B[i]][A[i]] = D.add_edge(A[i], B[i], 0);
    }

    int s = 0, t = N - 1;
    int ans = D.max_flow(s, t);
    auto query = [&](int m, int a, int b) {
        auto e = D.get_edge(edge[a][b]);
        int u = get<0>(e), v = get<1>(e), f = get<3>(e);
        if (m == 1) {
            D.change_edge(edge[a][b], 1, 0);
            ans += D.max_flow(s, t);
        } else {
            D.change_edge(edge[a][b], 0, 0);
            if (f != 1) {
                if (f < 1) swap(u, v);
                if (!D.max_flow(u, v, 1)) {
                    D.max_flow(t, v, 1);
                    D.max_flow(u, s, 1);
                    --ans;
                }
            }
        }
        return ans;
    };
    for (int i = 0; i < Q; i++) {
        cout << query(M[i], A[i], B[i]) << '\n';
    }
}