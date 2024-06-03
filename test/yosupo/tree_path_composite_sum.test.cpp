#define PROBLEM "https://judge.yosupo.jp/problem/tree_path_composite_sum"

#include <iostream>
#include "atcoder/modint"
#include "tree/Rerooting.hpp"

using mint = atcoder::modint998244353;

struct TreeDP {
    struct T {
        mint sum, cnt;
    };

    std::vector<int> a, b, c;

    T e() { return {0, 0}; }

    T op(const T& l, const T& r) { return {l.sum + r.sum, l.cnt + r.cnt}; }

    T add_vertex(const T& t, int v) { return {t.sum + a[v], t.cnt + 1}; }

    T add_edge(const T& t, int e) { return {t.sum * b[e] + t.cnt * c[e], t.cnt}; }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> a(N), u(N - 1), v(N - 1), b(N - 1), c(N - 1);
    for (int i = 0; i < N; i++) std::cin >> a[i];
    for (int i = 0; i < N - 1; i++) std::cin >> u[i] >> v[i] >> b[i] >> c[i];

    TreeDP treedp{a, b, c};
    Rerooting<TreeDP> G(N, treedp);
    for (int i = 0; i < N - 1; i++) G.add_edge(u[i], v[i]);

    auto ans = G.solve();
    for (int i = 0; i < N; i++) std::cout << ans[i].sum.val() << (i + 1 == N ? '\n' : ' ');
    return 0;
}