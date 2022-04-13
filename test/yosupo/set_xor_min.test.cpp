#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include <iostream>
#include "datastructure/BinaryTrie.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    int Q;
    std::cin >> Q;

    BinaryTrie<int, 30> BT;

    for (; Q--;) {
        int t, x;
        std::cin >> t >> x;
        if (t == 0) {
            if (BT.count(x)) continue;
            BT.insert(x);
        } else if (t == 1) {
            if (!BT.count(x)) continue;
            BT.erase(x);
        } else
            std::cout << (BT.min_element(x) ^ x) << '\n';
    }
    return 0;
}