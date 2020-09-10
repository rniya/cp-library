#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/2871"

#include "../../base.hpp"
#include "../../datastructure/LazySegmetnTree.hpp"
#include "../../tree/EulerTourforVertex.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;

    EulerTourforVertex ET(n);
    for (int i=1;i<n;++i){
        int p; cin >> p;
        ET.add_edge(--p,i);
    }
    vector<char> c(n);
    for (int i=0;i<n;++i) cin >> c[i];

    ET.build();
    struct node{
        int G,W;
        node(int G,int W):G(G),W(W){}
    };
    auto f=[](node a,node b){return node(a.G+b.G,a.W+b.W);};
    auto g=[](node a,int x){return x?node(a.W,a.G):a;};
    auto h=[](int a,int b){return a^b;};
    LazySegmentTree<node,int> seg(n,f,g,h,node(0,0),0);
    for (int i=0;i<n;++i) seg.set_val(ET.idx(i),c[i]=='G'?node(1,0):node(0,1));
    auto F=[&](int l,int r){seg.update(l,r,1);};

    for (;q--;){
        int v; cin >> v;
        ET.exec(--v,F);
        auto ans=seg.query(0,n);
        cout << (ans.G>ans.W?"broccoli":"cauliflower") << '\n';
    }
}