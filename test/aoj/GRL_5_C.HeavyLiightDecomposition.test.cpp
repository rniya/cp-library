#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C"

#include "../../base.hpp"
#include "../../tree/HeavyLightDecomposition.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    HeavyLightDecomposition HLD(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (; k--;) {
            int c;
            cin >> c;
            HLD.add_edge(i, c);
        }
    }
    HLD.build();

    int q;
    cin >> q;
    for (; q--;) {
        int u, v;
        cin >> u >> v;
        cout << HLD.lca(u, v) << '\n';
    }
}