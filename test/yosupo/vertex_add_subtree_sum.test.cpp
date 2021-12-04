#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include <iostream>
#include "atcoder/fenwicktree"
#include "tree/HeavyLightDecomposition.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];
    HeavyLightDecomposition HLD(N);
    for (int i = 1; i < N; i++) {
        int p;
        std::cin >> p;
        HLD.add_edge(p, i);
    }
    HLD.build();

    atcoder::fenwick_tree<long long> FT(N);
    for (int i = 0; i < N; i++) FT.add(HLD.idx(i), a[i]);

    for (; Q--;) {
        int t, u;
        std::cin >> t >> u;
        if (!t) {
            int x;
            std::cin >> x;
            FT.add(HLD.idx(u), x);
        } else {
            long long ans = 0;
            auto q = [&](int l, int r) { ans += FT.sum(l, r); };
            HLD.query_subtree(u, q, true);
            std::cout << ans << '\n';
        }
    }
    return 0;
}