#define PROBLEM "https://judge.yosupo.jp/problem/vertex_set_path_composite"

#include "../../base.hpp"
#include "../../modulo/modint.hpp"
#include "../../datastructure/SegmentTree.hpp"
#include "../../tree/HeavyLightDecomposition.hpp"

using mint = modint<998244353>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N), b(N);
    for (int i = 0; i < N; i++) cin >> a[i] >> b[i];
    HeavyLightDecomposition HLD(N);
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        cin >> u >> v;
        HLD.add_edge(u, v);
    }

    HLD.build();
    struct node {
        mint a, b;
        node(mint a, mint b) : a(a), b(b) {}
    };
    auto f = [](node a, node b) { return node(a.a * b.a, a.b * b.a + b.b); };
    auto g = [](node a, node b) { return node(a.a * b.a, b.b * a.a + a.b); };
    SegmentTree<node, decltype(f)> segl(N, f, node(1, 0));
    SegmentTree<node, decltype(g)> segr(N, g, node(1, 0));
    for (int i = 0; i < N; i++) {
        int x = HLD.idx(i);
        segl.set(x, node(a[i], b[i]));
        segr.set(x, node(a[i], b[i]));
    }
    segl.build();
    segr.build();

    for (; Q--;) {
        int t;
        cin >> t;
        if (t == 0) {
            int p, c, d;
            cin >> p >> c >> d;
            int x = HLD.idx(p);
            segl.update(x, node(c, d));
            segr.update(x, node(c, d));
        } else {
            int u, v, x;
            cin >> u >> v >> x;
            mint ans = x;
            auto q = [&](int l, int r) {
                if (l <= r) {
                    node res = segl.query(l, r);
                    ans = res.a * ans + res.b;
                } else {
                    node res = segr.query(r, l);
                    ans = res.a * ans + res.b;
                }
            };
            HLD.query_path_noncommutative(u, v, q, true);
            cout << ans << '\n';
        }
    }
    return 0;
}