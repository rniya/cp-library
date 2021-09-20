#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../base.hpp"
#include "../../datastructure/SegmentTree.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;

    auto f = [](long long a, long long b) { return a + b; };
    SegmentTree<long long, decltype(f)> seg(N, f, 0);
    for (int i = 0; i < N; i++) {
        long long a;
        cin >> a;
        seg.set(i, a);
    }
    seg.build();

    for (; Q--;) {
        int t;
        cin >> t;
        if (!t) {
            int p, x;
            cin >> p >> x;
            seg.add(p, x);
        } else {
            int l, r;
            cin >> l >> r;
            cout << seg.query(l, r) << '\n';
        }
    }
    return 0;
}