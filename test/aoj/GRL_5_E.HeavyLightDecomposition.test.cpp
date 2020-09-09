#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E"

#include "../../base.hpp"
#include "../../datastructure/LazySegmentTree.hpp"
#include "../../tree/HeavyLightDecomposition.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;

    HeavyLightDecomposition HLD(n);
    for (int i=0;i<n;++i){
        int k; cin >> k;
        for (;k--;){
            int c; cin >> c;
            HLD.add_edge(i,c);
        }
    }
    HLD.build();

    struct node{
        long long a; int b;
        node(long long a,int b):a(a),b(b){}
    };
    auto f=[](node a,node b){return node(a.a+b.a,a.b+b.b);};
    auto g=[](node a,long long x){return node(a.a+x*a.b,a.b);};
    auto h=[](long long a,long long b){return a+b;};
    LazySegmentTree<node,long long> seg(n,f,g,h,node(0,0),0);
    vector<node> v(n,node(0,1));
    seg.build(v);

    int q; cin >> q;
    for (;q--;){
        int t; cin >> t;
        if (!t){
            int v; long long w; cin >> v >> w;
            HLD.update_path(0,v,[&](int l,int r){seg.update(l,r,w);},true);
        } else {
            int u; cin >> u;
            cout << HLD.query(0,u,0LL,[&](int l,int r){return seg.query(l,r).a;},h) << '\n';
        }
    }
}