#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I"

#include "../../base.hpp"
#include "../../datastructure/LazySegmentTree.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    const int inf = 1 << 30;
    int n, q;
    cin >> n >> q;

    struct node {
        long long a;
        int b;
        node(long long a, int b) : a(a), b(b) {}
    };
    auto f = [](node a, node b) { return node(a.a + b.a, a.b + b.b); };
    auto g = [](node a, long long x) { return node(x != inf ? x * a.b : a.a, a.b); };
    auto h = [](long long a, long long b) { return b; };
    LazySegmentTree<node, long long> seg(n, f, g, h, node(0, 0), inf);
    vector<node> v(n, node(0, 1));
    seg.build(v);

    for (; q--;) {
        int c, s, t, x;
        cin >> c >> s >> t;
        if (!c) {
            cin >> x;
            seg.update(s, t + 1, x);
        } else
            cout << seg.query(s, t + 1).a << '\n';
    }
}