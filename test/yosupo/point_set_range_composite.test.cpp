#define PROBLEM "https://judge.yosupo.jp/problem/point_set_range_composite"

#include "../../base.hpp"
#include "../../datastructure/SegmentTree.hpp"
#include "../../modulo/modint.hpp"

using mint = modint<998244353>;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;

    struct node {
        mint a, b;
        node(mint a, mint b) : a(a), b(b) {}
    };
    auto f = [](node a, node b) { return node(a.a * b.a, a.b * b.a + b.b); };
    SegmentTree<node, decltype(f)> seg(N, f, node(1, 0));
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        seg.set(i, node(a, b));
    }
    seg.build();

    for (; Q--;) {
        int t;
        cin >> t;
        if (!t) {
            int p;
            int c, d;
            cin >> p >> c >> d;
            seg.update(p, node(c, d));
        } else {
            int l, r;
            int x;
            cin >> l >> r >> x;
            node ans = seg.query(l, r);
            cout << x * ans.a + ans.b << '\n';
        }
    }
    return 0;
}