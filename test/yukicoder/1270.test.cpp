#define PROBLEM "https://yukicoder.me/problems/no/1270"

#include "../../base.hpp"
#include "../../datastructure/BinaryIndexedTree.hpp"
#include "../../datastructure/LazySegmentTree.hpp"
#include "../../other/Mo.hpp"

const int inf = 1e9;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i], --a[i];

    vector<int> left(N + 1, 0), right(N + 1, 0);
    BinaryIndexedTree<int> BIT1(N), BIT2(N);
    for (int i = 0; i < N; i++) {
        left[i + 1] = left[i] + BIT1.query(a[i] + 1, N);
        BIT1.add(a[i], 1);
    }
    for (int i = N - 1; i >= 0; --i) {
        right[i] = right[i + 1] + BIT2.query(0, a[i]);
        BIT2.add(a[i], 1);
    }

    vector<int> l(Q), r(Q), ans(Q, 0);
    Mo mo(N);
    for (int i = 0; i < Q; i++) {
        cin >> l[i] >> r[i];
        mo.insert(--l[i], r[i]);
        ans[i] += left[l[i]] + right[r[i]];
    }

    BinaryIndexedTree<int> BIT3(N), BIT4(N);
    int inv = 0;
    auto f = [](int a, int b) { return min(a, b); };
    auto g = [](int a, int b) { return a + b; };
    LazySegmentTree<int, int> seg(N, f, g, g, inf, 0);
    vector<int> v(N, 0);
    seg.build(v);
    for (int i = 0; i < N; i++) {
        BIT4.add(a[i], 1);
        seg.update(a[i] + 1, N, 1);
    }

    auto add_left = [&](int idx) {
        inv -= BIT4.query(0, a[idx]);
        BIT3.add(a[idx], -1);
        seg.update(0, a[idx], -1);
    };
    auto add_right = [&](int idx) {
        inv -= BIT3.query(a[idx] + 1, N);
        BIT4.add(a[idx], -1);
        seg.update(a[idx] + 1, N, -1);
    };
    auto del_left = [&](int idx) {
        inv += BIT4.query(0, a[idx]);
        BIT3.add(a[idx], 1);
        seg.update(0, a[idx], 1);
    };
    auto del_right = [&](int idx) {
        inv += BIT3.query(a[idx] + 1, N);
        BIT4.add(a[idx], 1);
        seg.update(a[idx] + 1, N, 1);
    };
    auto rem = [&](int idx) { ans[idx] += inv + seg.query(0, N) * (r[idx] - l[idx]); };
    mo.build(add_left, add_right, del_left, del_right, rem);

    for (int i = 0; i < Q; i++) cout << ans[i] << '\n';
}