#define PROBLEM "https://judge.yosupo.jp/problem/set_xor_min"

#include "../../base.hpp"
#include "../../datastructure/BinaryTrie.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int Q;
    cin >> Q;

    BinaryTrie<int, 30> BT;

    for (; Q--;) {
        int t, x;
        cin >> t >> x;
        if (t == 0) {
            if (BT.count(x)) continue;
            BT.insert(x);
        } else if (t == 1) {
            if (!BT.count(x)) continue;
            BT.erase(x);
        } else
            cout << (BT.min_element(x) ^ x) << '\n';
    }
}