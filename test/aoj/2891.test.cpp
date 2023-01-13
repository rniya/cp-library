#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2891"

#include "base.hpp"
#include "graph/CycleDetection.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;

    CycleDetection<false> CD(N);
    for (int i = 0; i < N; i++) {
        int u, v;
        cin >> u >> v;
        --u, --v;
        CD.add_edge(u, v);
        CD.add_edge(v, u);
    }
    vector<int> res = CD.build();
    vector<int> check(N, 0);
    for (int u : res) check[u] = 1;

    int Q;
    cin >> Q;
    for (; Q--;) {
        int a, b;
        cin >> a >> b;
        cout << (check[--a] && check[--b] ? 2 : 1) << '\n';
    }
}