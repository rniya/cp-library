#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_D"

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
    LazySegmentTree<int, int, decltype(f), decltype(g), decltype(h)> seg(n, f, g, h, INT_MAX, -1);

    for (; q--;) {
        int c, s, t, x, i;
        cin >> c;
        if (!c) {
            cin >> s >> t >> x;
            seg.update(s, t + 1, x);
        } else {
            cin >> i;
            cout << seg[i] << '\n';
        }
    }
    return 0;
}