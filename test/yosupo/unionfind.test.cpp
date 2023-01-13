#define PROBLEM "https://judge.yosupo.jp/problem/unionfind"

#include "datastructure/UnionFind.hpp"
#include "base.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N, Q;
    cin >> N >> Q;

    UnionFind UF(N);
    for (; Q--;) {
        int t, u, v;
        cin >> t >> u >> v;
        if (!t)
            UF.merge(u, v);
        else
            cout << UF.same(u, v) << '\n';
    }
}