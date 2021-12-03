#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include <iostream>
#include "atcoder/segtree"
#include "tree/HeavyLightDecomposition.hpp"

long long op(long long l, long long r) { return l + r; }

long long e() { return 0; }

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> a(N);
    for (int i = 0; i < N; i++) std::cin >> a[i];
    HeavyLightDecomposition HLD(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        HLD.add_edge(u, v);
    }

    HLD.build();
    std::vector<long long> v(N);
    for (int i = 0; i < N; i++) v[HLD.idx(i)] = a[i];
    atcoder::segtree<long long, op, e> seg(v);

    for (; Q--;) {
        int t;
        std::cin >> t;
        if (!t) {
            int p;
            long long x;
            std::cin >> p >> x;
            int idx = HLD.idx(p);
            seg.set(idx, seg.get(idx) + x);
        } else {
            int u, v;
            std::cin >> u >> v;
            long long ans = 0;
            auto q = [&](int l, int r) { ans += seg.prod(l, r); };
            HLD.query_path(u, v, q, true);
            std::cout << ans << '\n';
        }
    }
    return 0;
}