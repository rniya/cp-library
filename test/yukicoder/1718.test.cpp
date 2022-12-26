#define PROBLEM "https://yukicoder.me/problems/no/1718"

#include <iostream>
#include <utility>
#include "tree/Rerooting.hpp"

struct S {
    int back, go;
    bool must;
    S(int back, int go, bool must) : back(back), go(go), must(must) {}
};

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, K;
    std::cin >> N >> K;
    std::vector<bool> D(N, false);
    auto op = [](S l, S r) { return S(l.back + r.back, std::min(l.go + r.back, l.back + r.go), l.must | r.must); };
    auto mapping = [&](S x, auto e) {
        bool must = x.must | D[e.to];
        return S(x.back + (must ? 2 : 0), x.go + (must ? 1 : 0), must);
    };
    Rerooting<int, S> G(N, op, mapping, S(0, 0, false));
    for (int i = 0; i < N - 1; i++) {
        int u, v;
        std::cin >> u >> v;
        G.add_edge(--u, --v, 1);
    }
    for (; K--;) {
        int d;
        std::cin >> d;
        D[--d] = true;
    }

    auto ans = G.solve();
    for (int i = 0; i < N; i++) std::cout << ans[i].go << '\n';
    return 0;
}