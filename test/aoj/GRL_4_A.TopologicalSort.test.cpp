#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A"

#include "base.hpp"
#include "graph/TopologicalSort.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E;
    cin >> V >> E;
    TopologicalSort TS(V);
    for (; E--;) {
        int s, t;
        cin >> s >> t;
        TS.add_edge(s, t);
    }

    auto res = TS.build();
    cout << res.empty() << '\n';
    return 0;
}