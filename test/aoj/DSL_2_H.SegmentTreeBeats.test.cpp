#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_H"

#include "../../base.hpp"
#include "../../SegmentTreeBeats.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;

    SegmentTreeBeats<int> seg(n);
    vector<int> v(n,0);
    seg.build(v);

    for (;q--;){
        int c; cin >> c;
        if (!c){
            int s,t,x; cin >> s >> t >> x;
            seg.update_add(s,t+1,x);
        } else {
            int s,t; cin >> s >> t;
            cout << seg.query_min(s,t+1) << '\n';
        }
    }
}