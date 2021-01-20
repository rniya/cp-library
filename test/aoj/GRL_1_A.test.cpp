#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_A"

#include "../../base.hpp"
#include "../../graph/Dijkstra.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E, r;
    cin >> V >> E >> r;

    Dijkstra<long long> D(V);
    for (int i = 0; i < E; i++) {
        int s, t, d;
        cin >> s >> t >> d;
        D.add_edge(s, t, d);
    }

    D.build(r);
    for (int i = 0; i < V; i++) {
        if (D[i] > 1e18)
            cout << "INF" << '\n';
        else
            cout << D[i] << '\n';
    }
}