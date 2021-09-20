#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/all/DSL_2_A"

#include "../../base.hpp"
#include "../../datastructure/SegmentTree.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    auto f = [](int a, int b) { return min(a, b); };
    SegmentTree<int, decltype(f)> seg(n, f, INT_MAX);

    for (; q--;) {
        int c, x, y;
        cin >> c >> x >> y;
        if (!c)
            seg.update(x, y);
        else
            cout << seg.query(x, y + 1) << '\n';
    }
    return 0;
}