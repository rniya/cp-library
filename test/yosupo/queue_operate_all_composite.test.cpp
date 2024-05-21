#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include <iostream>
#include "atcoder/modint"
#include "datastructure/SlidingWindowAggregation.hpp"

using mint = atcoder::modint998244353;

struct S {
    mint a, b;
    S(mint a, mint b) : a(a), b(b) {}
};

S op(S a, S b) { return S(a.a * b.a, a.b * b.a + b.b); }

S e() { return S(1, 0); }

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);

    SlidingWindowAggregation<S, op, e> swag;

    int Q;
    std::cin >> Q;
    for (; Q--;) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int a, b;
            std::cin >> a >> b;
            swag.push(S(a, b));
        } else if (t == 1) {
            swag.pop();
        } else {
            int x;
            std::cin >> x;
            S res = swag.fold();
            mint ans = res.a * x + res.b;
            std::cout << ans.val() << '\n';
        }
    }
}