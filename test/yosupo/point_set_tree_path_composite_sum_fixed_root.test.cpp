#define PROBLEM "https://judge.yosupo.jp/problem/point_set_tree_path_composite_sum_fixed_root"

#include <iostream>
#include "atcoder/modint"
#include "tree/StaticTopTree.hpp"

using mint = atcoder::modint998244353;

struct TreeDP {
    struct T {
        mint a, b, cnt, sum;
    };

    static T rake(const T& l, const T& r) { return {l.a, l.b, l.cnt + r.cnt, l.sum + r.sum}; }

    static T compress(const T& l, const T& r) {
        mint a = l.a * r.a, b = l.a * r.b + l.b, cnt = l.cnt + r.cnt, sum = l.sum + l.a * r.sum + l.b * r.cnt;
        return {a, b, cnt, sum};
    }
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
    std::vector<std::vector<int>> g(N);
    for (int i = 0; i < N - 1; i++) {
        std::cin >> u[i] >> v[i] >> b[i] >> c[i];
        stt.add_edge(u[i], v[i]);
        g[u[i]].emplace_back(i);
        g[v[i]].emplace_back(i);
    }

    stt.build();
    std::vector<int> p(N);
    auto dfs = [&](auto self, int cur, int pe) -> void {
        p[cur] = pe;
        if (pe != -1) {
            if (cur != v[pe]) {
                std::swap(u[pe], v[pe]);
            }
        }
        for (int i : g[cur]) {
            if (i == pe) {
                continue;
            }
            self(self, u[i] ^ v[i] ^ cur, i);
        }
    };
    dfs(dfs, 0, -1);
    auto vertex = [&](int v) -> TreeDP::T {
        if (v == 0) {
            return {1, 0, 1, a[v]};
        }
        int e = p[v];
        return {b[e], c[e], 1, mint(b[e]) * a[v] + c[e]};
    };
    DynamicTreeDP<TreeDP> dp(N, stt, vertex);

    for (; Q--;) {
        int type;
        std::cin >> type;
        if (type == 0) {
            int w, x;
            std::cin >> w >> x;
            a[w] = x;
            dp.set(w, vertex(w));
        } else {
            int e, y, z;
            std::cin >> e >> y >> z;
            b[e] = y, c[e] = z;
            dp.set(v[e], vertex(v[e]));
        }
        auto ans = dp.all_prod().sum;
        std::cout << ans.val() << "\n";
    }
    return 0;
}