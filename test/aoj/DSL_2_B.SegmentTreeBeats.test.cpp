#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_B"

#include "../../base.hpp"
#include "../..//datastructure/SegmentTreeBeats.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;

    SegmentTreeBeats<int> seg(n);
    vector<int> v(n,0);
    seg.build(v);

    for (;q--;){
        int c,x,y; cin >> c >> x >> y;
        if (!c) seg.update_add(x-1,x,y);
        else cout << seg.query_sum(x-1,y) << '\n';
    }
}