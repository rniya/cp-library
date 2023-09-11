#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1615"

#include <iostream>
#include "graph/maxflow_lowerbound.hpp"

void solve(int n, int m) {
    std::vector<int> u(m), v(m);
    for (int i = 0; i < m; i++) std::cin >> u[i] >> v[i], u[i]--, v[i]--;

    auto check = [&](int l, int h) {
        int s = m + n, t = s + 1;
        maxflow_lowerbound<int> graph(t + 1);
        for (int i = 0; i < m; i++) {
            graph.add_edge(s, i, 1, 1);
            graph.add_edge(i, m + u[i], 0, 1);
            graph.add_edge(i, m + v[i], 0, 1);
        }
        for (int i = 0; i < n; i++) graph.add_edge(m + i, t, l, h);
        return graph.flow(s, t) >= 0;
    };
    int L = 0, H = n;
    for (int l = 0, h = 0; h <= n; h++) {
        for (; l <= h and check(l, h); l++) {
            L = l, H = h;
        }
    }
    std::cout << L << ' ' << H << '\n';
}

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    for (int n, m; std::cin >> n >> m, n;) solve(n, m);
    return 0;
}