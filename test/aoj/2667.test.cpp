#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2667"

#include <iostream>
#include "atcoder/lazysegtree"
#include "tree/HeavyLightDecomposition.hpp"

struct S {
    long long sum;
    int cnt;
    S(long long sum, int cnt) : sum(sum), cnt(cnt) {}
};

S op(S l, S r) { return S(l.sum + r.sum, l.cnt + r.cnt); }

S e() { return S(0, 0); }

S mapping(int x, S a) { return S(a.sum + x * a.cnt, a.cnt); }

int composition(int l, int r) { return l + r; }

int id() { return 0; }

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    HeavyLightDecomposition HLD(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        std::cin >> a >> b;
        HLD.add_edge(a, b);
    }
    HLD.build();

    std::vector<S> v(N, S(0, 1));
    atcoder::lazy_segtree<S, op, e, int, mapping, composition, id> seg(v);

    for (; Q--;) {
        int t;
        std::cin >> t;
        if (!t) {
            int u, v;
            std::cin >> u >> v;
            long long ans = 0;
            auto q = [&](int l, int r) { ans += seg.prod(l, r).sum; };
            HLD.query_path(u, v, q);
            std::cout << ans << '\n';
        } else {
            int v;
            long long x;
            std::cin >> v >> x;
            auto q = [&](int l, int r) { seg.apply(l, r, x); };
            HLD.query_subtree(v, q);
        }
    }
    return 0;
}