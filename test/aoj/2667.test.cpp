#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2667"

#include "../../base.hpp"
#include "../../datastructure/LazySegmentTree.hpp"
#include "../../tree/HeavyLightDecomposition.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;

    HeavyLightDecomposition HLD(N);
    for (int i = 0; i < N - 1; i++) {
        int a, b;
        cin >> a >> b;
        HLD.add_edge(a, b);
    }
    HLD.build();

    struct node {
        long long a;
        int b;
        node(long long a, int b) : a(a), b(b) {}
    };
    auto f = [](node a, node b) { return node(a.a + b.a, a.b + b.b); };
    auto g = [](node a, long long x) { return node(a.a + x * a.b, a.b); };
    auto h = [](long long a, long long b) { return a + b; };
    LazySegmentTree<node, long long> seg(N, f, g, h, node(0, 0), 0);
    vector<node> v(N, node(0, 1));
    seg.build(v);

    for (; Q--;) {
        int t;
        cin >> t;
        if (!t) {
            int u, v;
            cin >> u >> v;
            cout << HLD.query_path(
                        u, v, 0LL, [&](int l, int r) { return seg.query(l, r).a; }, h, true)
                 << '\n';
        } else {
            int v;
            long long x;
            cin >> v >> x;
            HLD.update_sub(
                v, [&](int l, int r) { seg.update(l, r, x); }, true);
        }
    }
}