#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/4/GRL_4_A"

#include "base.hpp"
#include "graph/CycleDetection.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V, E;
    cin >> V >> E;

    CycleDetection<true> CD(V);
    for (int i = 0; i < E; i++) {
        int s, t;
        cin >> s >> t;
        CD.add_edge(s, t);
    }

    cout << (CD.build().empty() ? 0 : 1) << '\n';
}