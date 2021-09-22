#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_B"

#include "../../base.hpp"
#include "../../graph/TopologicalSort.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E;
    cin >> V >> E;

    TopologicalSort TS(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        TS.add_edge(s, t);
    }

    vector<int> ans = TS.build();
    for (int& v : ans) cout << v << '\n';
}