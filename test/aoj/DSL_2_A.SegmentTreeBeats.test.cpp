#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A"

#include "../../base.hpp"
#include "../../SegmentTreeBeats.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;

    SegmentTreeBeats<int> seg(n);
    vector<int> v(n,INT_MAX);
    seg.build(v);

    for (;q--;){
        int c,x,y; cin >> c >> x >> y;
        if (!c) seg.update_val(x,x+1,y);
        else cout << seg.query_min(x,y+1) << '\n';
    }
}