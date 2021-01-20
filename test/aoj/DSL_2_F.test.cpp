#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_F"

#include "../../base.hpp"
#include "../../datastructure/LazySegmentTree.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    auto f = [](int a, int b) { return min(a, b); };
    auto g = [](int a, int b) { return (~b ? b : a); };
    auto h = [](int a, int b) { return b; };
    LazySegmentTree<int, int> seg(n, f, g, h, INT_MAX, -1);

    for (; q--;) {
        int c, s, t, x;
        cin >> c >> s >> t;
        if (!c) {
            cin >> x;
            seg.update(s, t + 1, x);
        } else
            cout << seg.query(s, t + 1) << '\n';
    }
}