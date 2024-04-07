#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include <iostream>
#include "datastructure/SparseTable.hpp"

int op(int l, int r) { return l < r ? l : r; }

int e() { return (1 << 30) - 1; }

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int N, Q;
    std::cin >> N >> Q;
    std::vector<int> a(N);
    for (int& val : a) std::cin >> val;

    SparseTable<int, op, e> ST(a);

    for (; Q--;) {
        int l, r;
        std::cin >> l >> r;
        std::cout << ST.prod(l, r) << '\n';
    }
}