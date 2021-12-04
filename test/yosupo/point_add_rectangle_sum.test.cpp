#define PROBLEM "https://judge.yosupo.jp/problem/point_add_rectangle_sum"

#include <iostream>
#include "atcoder/fenwicktree"
#include "datastructure/RangeTree.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    auto f = [](long long a, long long b) { return a + b; };
    using FT = atcoder::fenwick_tree<long long>;
    auto st_new = [](int n) { return new FT(n); };
    auto st_set = [](FT& FT, int i, long long x) { FT.add(i, x); };
    auto st_prod = [](FT& FT, int l, int r) { return FT.sum(l, r); };
    RangeTree<FT, long long, int> RT(st_new, st_set, st_prod, f, 0LL);

    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> x(N), y(N), w(N), c(Q), s(Q), t(Q), u(Q), v(Q);
    for (int i = 0; i < N; i++) {
        std::cin >> x[i] >> y[i] >> w[i];
        RT.add_point(x[i], y[i]);
    }
    for (int i = 0; i < Q; i++) {
        std::cin >> c[i] >> s[i] >> t[i] >> u[i];
        if (c[i] == 0)
            RT.add_point(s[i], t[i]);
        else
            std::cin >> v[i];
    }

    RT.build();
    for (int i = 0; i < N; i++) RT.set(x[i], y[i], w[i]);
    for (int i = 0; i < Q; i++) {
        if (c[i] == 0)
            RT.set(s[i], t[i], u[i]);
        else
            std::cout << RT.prod(s[i], u[i], t[i], v[i]) << '\n';
    }
    return 0;
}