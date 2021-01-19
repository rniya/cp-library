#define IGNORE

#define PROBLEM "https://codeforces.com/contest/1179/problem/C"

#include "../../base.hpp"
#include "../../datastructure/LazySegmentTree.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    const int MAX_A = 1e6 + 10, INF = 1e9;
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for (int i = 0; i < n; i++) cin >> a[i];
    for (int i = 0; i < m; i++) cin >> b[i];

    auto f = [](int a, int b) { return min(a, b); };
    auto g = [](int a, int b) { return a + b; };
    LazySegmentTree<int, int> seg(MAX_A, f, g, g, INF, 0);
    vector<int> v(MAX_A, 0);
    seg.build(v);
    for (int i = 0; i < n; i++) seg.update(a[i], MAX_A, 1);
    for (int i = 0; i < m; i++) seg.update(b[i], MAX_A, -1);

    int q;
    cin >> q;
    for (; q--;) {
        int t, i, x;
        cin >> t >> i >> x;
        --i;
        if (t == 1) {
            seg.update(a[i], MAX_A, -1);
            a[i] = x;
            seg.update(a[i], MAX_A, 1);
        } else {
            seg.update(b[i], MAX_A, 1);
            b[i] = x;
            seg.update(b[i], MAX_A, -1);
        }
        int ans = seg.find_last(MAX_A, [&](int x) { return x < n - m; });
        cout << (ans < 0 ? -1 : ans + 1) << '\n';
    }
}