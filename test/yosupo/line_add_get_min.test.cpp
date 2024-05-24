#define PROBLEM "https://judge.yosupo.jp/problem/line_add_get_min"

#include <iostream>
#include "datastructure/LineContainer.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    LineContainer<true> L;
    for (; N--;) {
        int a;
        long long b;
        std::cin >> a >> b;
        L.add(a, b);
    }
    for (; Q--;) {
        int t;
        std::cin >> t;
        if (t == 0) {
            int a;
            long long b;
            std::cin >> a >> b;
            L.add(a, b);
        } else {
            int p;
            std::cin >> p;
            std::cout << L.query(p) << '\n';
        }
    }
    return 0;
}