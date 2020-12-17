#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_subtree_sum"

#include "../../base.hpp"
#include "../../tree/HeavyLightDecomposition.hpp"
#include "../../datastructure/BinaryIndexedTree.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<int> a(N);
    for (int i=0;i<N;++i) cin >> a[i];

    HeavyLightDecomposition HLD(N);
    for (int i=1;i<N;++i){
        int p; cin >> p;
        HLD.add_edge(p,i);
    }
    HLD.build();

    BinaryIndexedTree<long long> BIT(N);
    for (int i=0;i<N;++i) BIT.add(HLD.idx(i),a[i]);

    for (;Q--;){
        int t,u; cin >> t >> u;
        if (!t){
            int x; cin >> x;
            BIT.add(HLD.idx(u),x);
        } else {
            cout << HLD.query_sub<long long>(u,[&](int l,int r){return BIT.query(l,r);}) << '\n';
        }
    }
}