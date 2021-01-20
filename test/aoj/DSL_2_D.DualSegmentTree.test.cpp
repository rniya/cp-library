#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"

#include "../../base.hpp"
#include "../../datastructure/DualSegmentTree.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    auto h = [](int a, int b) { return b; };
    DualSegmentTree<int> seg(n, h, INT_MAX);

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
}