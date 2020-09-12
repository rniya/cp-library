#define PROBLEM "https://judge.yosupo.jp/problem/vertex_add_path_sum"

#include "../../base.hpp"
#include "../../datastructure/SegmentTree.hpp"
#include "../../tree/HeavyLightDecomposition.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<long long> a(N);
    for (int i=0;i<N;++i) cin >> a[i];

    HeavyLightDecomposition HLD(N);
    for (int i=0;i<N-1;++i){
        int u,v; cin >> u >> v;
        HLD.add_edge(u,v);
    }
    HLD.build();

    auto f=[](long long a,long long b){return a+b;};
    SegmentTree<long long> seg(N,f,0);
    for (int i=0;i<N;++i) HLD.update_path(i,i,[&](int l,int r){seg.update(l,a[i]);});

    for (;Q--;){
        int t; cin >> t;
        if (!t){
            int p; long long x; cin >> p >> x;
            HLD.update_path(p,p,[&](int l,int r){seg.update(l,seg[l]+x);});
        } else {
            int u,v; cin >> u >> v;
            cout << HLD.query(u,v,0LL,[&](int l,int r){return seg.query(l,r);},f) << '\n';
        }
    }
}