#define PROBLEM "https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root"

#include <iostream>
#include "atcoder/modint"
#include "tree/StaticTopTree.hpp"

using mint = atcoder::modint998244353;

struct TreeDP {
    struct Path {
        mint a, b, c, sub;
    };

    struct Point {
        mint val, sub;
    };

    std::vector<int> a, b, c;

    Path vertex(int v) { return {b[v], mint(a[v]) * b[v] + c[v], c[v], 1}; }

    Path compress(const Path& l, const Path& r) {
        return {l.a * r.a, l.a * r.b + l.b + l.c * r.sub, l.c + l.a * r.c, l.sub + r.sub};
    }

    Path add_vertex(const Point& p, int v) {
        return {b[v], (p.val + a[v]) * b[v] + (p.sub + 1) * c[v], c[v], p.sub + 1};
    }

    Point rake(const Point& l, const Point& r) { return {l.val + r.val, l.sub + r.sub}; }

    Point add_edge(const Path& p) { return {p.b, p.sub}; }
};

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> a(N), u(N - 1), v(N - 1), b(N - 1), c(N - 1);
    for (int i = 0; i < N; i++) {
        std::cin >> a[i];
    }
    StaticTopTree stt(N);
    for (int i = 0; i < N - 1; i++) {
        std::cin >> u[i] >> v[i] >> b[i] >> c[i];
        stt.add_edge(u[i], v[i]);
    }

    stt.build();
    std::vector<int> par(N);
    auto& G = stt.G;
    std::queue<int> que;
    par[0] = -1;
    que.emplace(0);
    while (not que.empty()) {
        int v = que.front();
        que.pop();
        for (const int& u : G[v]) {
            par[u] = v;
            que.emplace(u);
        }
    }
    std::vector<int> B(N), C(N);
    for (int i = 0; i < N - 1; i++) {
        if (par[v[i]] != u[i]) {
            std::swap(u[i], v[i]);
        }
        assert(par[v[i]] == u[i]);
        B[v[i]] = b[i], C[v[i]] = c[i];
    }
    B[0] = 1, C[0] = 0;
    TreeDP treedp{a, B, C};
    DynamicDPonStaticTopTree dp(stt, treedp);

    for (; Q--;) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int w, x;
            std::cin >> w >> x;
            treedp.a[w] = x;
            dp.set(w);
        } else {
            int e, y, z;
            std::cin >> e >> y >> z;
            int w = v[e];
            treedp.b[w] = y;
            treedp.c[w] = z;
            dp.set(w);
        }
        mint ans = dp.all_prod().b;
        std::cout << ans.val() << '\n';
    }
    return 0;
}