#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include "../../base.hpp"
#include "../../datastructure/BinaryIndexedTree.hpp"
#include "../../datastructure/RangeTree.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    auto f = [](long long a, long long b) { return a + b; };
    using BIT = BinaryIndexedTree<long long>;
    auto st_new = [](int n) { return new BIT(n); };
    auto st_set = [](BIT& bit, int i, long long x) { bit.add(i, x); };
    auto st_prod = [](BIT& bit, int l, int r) { return bit.query(l, r); };
    RangeTree<BIT, long long, int> RT(st_new, st_set, st_prod, f, 0LL);

    int N, Q;
    cin >> N >> Q;
    vector<int> x(N), y(N), w(N), c(Q), s(Q), t(Q), u(Q), v(Q);
    for (int i = 0; i < N; i++) {
        cin >> x[i] >> y[i] >> w[i];
        RT.add_point(x[i], y[i]);
    }
    for (int i = 0; i < Q; i++) {
        cin >> c[i] >> s[i] >> t[i] >> u[i];
        if (c[i] == 0)
            RT.add_point(s[i], t[i]);
        else
            cin >> v[i];
    }

    RT.build();
    for (int i = 0; i < N; i++) RT.set(x[i], y[i], w[i]);
    for (int i = 0; i < Q; i++) {
        if (c[i] == 0)
            RT.set(s[i], t[i], u[i]);
        else
            cout << RT.query(s[i], u[i], t[i], v[i]) << '\n';
    }
    return 0;
}