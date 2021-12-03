#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "atcoder/segtree"
#include "tree/HeavyLightDecomposition.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;

struct S {
    mint a, b;
    S(mint a = 1, mint b = 0) : a(a), b(b) {}
};

S opl(S l, S r) { return S(l.a * r.a, l.b * r.a + r.b); };

S opr(S l, S r) { return S(l.a * r.a, r.b * l.a + l.b); }

S e() { return S(1, 0); }

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) std::cin >> a[i] >> b[i];
    HeavyLightDecomposition HLD(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        HLD.add_edge(u, v);
    }

    HLD.build();
    std::vector<S> v(N);
    for (int i = 0; i < N; i++) {
        int idx = HLD.idx(i);
        v[idx] = S(a[i], b[i]);
    }
    atcoder::segtree<S, opl, e> segl(v);
    atcoder::segtree<S, opr, e> segr(v);

    for (; Q--;) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int p, c, d;
            std::cin >> p >> c >> d;
            int x = HLD.idx(p);
            segl.set(x, S(c, d));
            segr.set(x, S(c, d));
        } else {
            int u, v, x;
            std::cin >> u >> v >> x;
            mint ans = x;
            auto q = [&](int l, int r) {
                if (l <= r) {
                    S res = segl.prod(l, r);
                    ans = res.a * ans + res.b;
                } else {
                    S res = segr.prod(r, l);
                    ans = res.a * ans + res.b;
                }
            };
            HLD.query_path_noncommutative(u, v, q, true);
            std::cout << ans << '\n';
        }
    }
    return 0;
}