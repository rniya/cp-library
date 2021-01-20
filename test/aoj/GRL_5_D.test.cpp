#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D"

#include "../../base.hpp"
#include "../../datastructure/BinaryIndexedTree.hpp"
#include "../../tree/EulerTourforEdge.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;

    EulerTourforEdge ET(n);
    for (int i = 0; i < n; i++) {
        int k;
        cin >> k;
        for (; k--;) {
            int c;
            cin >> c;
            ET.add_edge(i, c);
        }
    }

    ET.build();
    BinaryIndexedTree<int> BIT(2 * n);
    auto f = [&](int l, int r) { return BIT.query(l, r); };
    auto g = [&](int k, int w) { BIT.add(k, w); };

    int q;
    cin >> q;
    for (; q--;) {
        int t;
        cin >> t;
        if (!t) {
            int v, w;
            cin >> v >> w;
            ET.update(v, w, g);
        } else {
            int u;
            cin >> u;
            cout << ET.query<int>(u, f) << '\n';
        }
    }
}