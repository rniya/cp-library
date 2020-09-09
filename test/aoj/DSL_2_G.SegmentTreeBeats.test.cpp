#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G"

#include "../../base.hpp"
#include "../../SegmentTreeBeats.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;

    SegmentTreeBeats<long long> seg(n);
    vector<long long> v(n,0);
    seg.build(v);

    for (;q--;){
        int c; cin >> c;
        if (!c){
            int s,t; long long x; cin >> s >> t >> x;
            seg.update_add(s-1,t,x);
        } else {
            int s,t; cin >> s >> t;
            cout << seg.query_sum(s-1,t) << '\n';
        }
    }
}