#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_B"

#include "../../base.hpp"
#include "../../flow/MinCostFlow.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E, F;
    cin >> V >> E >> F;

    MinCostFlow<int, int> MCF(V);

    for (int i = 0; i < E; i++) {
        int u, v, c, d;
        cin >> u >> v >> c >> d;
        MCF.add_edge(u, v, c, d);
    }

    cout << MCF.min_cost_flow(0, V - 1, F) << '\n';
}