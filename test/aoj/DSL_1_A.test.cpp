#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/1/DSL_1_A"

#include "../../base.hpp"
#include "../../datastructure/UnionFind.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n, q;
    cin >> n >> q;

    UnionFind UF(n);

    for (; q--;) {
        int c, x, y;
        cin >> c >> x >> y;
        if (!c)
            UF.merge(x, y);
        else
            cout << UF.same(x, y) << '\n';
    }
}