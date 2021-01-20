#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"

#include "../../base.hpp"
#include "../../datastructure/SegmentTree.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    SegmentTree<int> seg(
        n, [](int a, int b) { return min(a, b); }, INT_MAX);

    for (; q--;) {
        int c, x, y;
        cin >> c >> x >> y;
        if (!c)
            seg.update(x, y);
        else
            cout << seg.query(x, y + 1) << '\n';
    }
}