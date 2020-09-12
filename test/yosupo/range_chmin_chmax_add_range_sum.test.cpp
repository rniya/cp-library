#define PROBLEM "https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum"

#include "../../base.hpp"
#include "../../datastructure/SegmentTreeBeats.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<long long> a(N);
    for (int i=0;i<N;++i) cin >> a[i];

    SegmentTreeBeats<long long> seg(N);
    seg.build(a);

    for (;Q--;){
        int t,l,r; long long b; cin >> t >> l >> r;
        if (t==0){
            cin >> b;
            seg.update_min(l,r,b);
        } else if (t==1){
            cin >> b;
            seg.update_max(l,r,b);
        } else if (t==2){
            cin >> b;
            seg.update_add(l,r,b);
        } else cout << seg.query_sum(l,r) << '\n';
    }
}