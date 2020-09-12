#define PROBLEM "https://judge.yosupo.jp/problem/point_add_range_sum"

#include "../../base.hpp"
#include "../../datastructure/SegmentTree.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<long long> a(N);
    for (int i=0;i<N;++i) cin >> a[i];

    SegmentTree<long long> seg(N,[](long long a,long long b){return a+b;},0);
    seg.build(a);

    for (;Q--;){
        int t; cin >> t;
        if (!t){
            int p,x; cin >> p >> x;
            seg.update(p,seg[p]+x);
        } else {
            int l,r; cin >> l >> r;
            cout << seg.query(l,r) << '\n';
        }
    }
}