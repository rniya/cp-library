#define PROBLEM "https://judge.yosupo.jp/problem/lca"

#include "../../base.hpp"
#include "../../tree/LowestCommonAncestor.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;

    LowestCommonAncestor LCA(N);
    for (int i=1;i<N;++i){
        int p; cin >> p;
        LCA.add_edge(p,i);
    }
    LCA.build();

    for (;Q--;){
        int u,v; cin >> u >> v;
        cout << LCA.lca(u,v) << '\n';
    }
}