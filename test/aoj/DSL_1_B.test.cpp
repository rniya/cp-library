#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_B"

#include "base.hpp"
#include "datastructure/PotentializedUnionFind.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    PotentializedUnionFind<int> UF(n);

    for (; q--;) {
        int c, x, y, z;
        cin >> c >> x >> y;
        if (!c) {
            cin >> z;
            UF.merge(x, y, z);
        } else {
            if (UF.same(x, y))
                cout << UF.diff(x, y) << '\n';
            else
                cout << '?' << '\n';
        }
    }
    return 0;
}