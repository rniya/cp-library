#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A"

#include "../../base.hpp"
#include "../../graph/BlockCutTree.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E;
    cin >> V >> E;

    BlockCutTree BCT(V);
    vector<int> s(E), t(E);
    for (int i = 0; i < E; i++) {
        cin >> s[i] >> t[i];
        BCT.add_edge(s[i], t[i]);
    }

    BCT.build();
    for (int i = 0; i < V; i++) {
        if (BCT.is_articulation[i]) {
            cout << i << '\n';
        }
    }
    return 0;
}