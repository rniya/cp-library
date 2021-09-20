#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../../base.hpp"
#include "../../datastructure/LazySegmentTree.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    struct node {
        long long a;
        int b;
        node(long long a, int b) : a(a), b(b) {}
    };
    auto f = [](node a, node b) { return node(a.a + b.a, a.b + b.b); };
    auto g = [](node a, long long x) { return node(a.a + x * a.b, a.b); };
    auto h = [](long long a, long long b) { return a + b; };
    LazySegmentTree<node, long long, decltype(f), decltype(g), decltype(h)> seg(n, f, g, h, node(0, 0), 0);
    for (int i = 0; i < n; i++) seg.set(i, node(0, 1));
    seg.build();

    for (; q--;) {
        int c, s, t, x;
        cin >> c >> s >> t;
        if (!c) {
            cin >> x;
            seg.update(s - 1, t, x);
        } else
            cout << seg.query(s - 1, t).a << '\n';
    }
    return 0;
}