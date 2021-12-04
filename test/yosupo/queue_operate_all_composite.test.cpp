#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "datastructure/SlidingWindowAggregation.hpp"
#include "util/modint.hpp"

using mint = atcoder::modint998244353;

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    struct node {
        mint a, b;
        node(mint a, mint b) : a(a), b(b) {}
    };
    auto f = [](node a, node b) { return node(a.a * b.a, a.b * b.a + b.b); };
    SlidingWindowAggregation<node> SWAG(f, node(1, 0));

    int Q;
    std::cin >> Q;
    for (; Q--;) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int a, b;
            std::cin >> a >> b;
            SWAG.push(node(a, b));
        } else if (t == 1) {
            SWAG.pop();
        } else {
            int x;
            std::cin >> x;
            node ans = SWAG.fold();
            std::cout << ans.a * x + ans.b << '\n';
        }
    }
}