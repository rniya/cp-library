#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_D"

#include "../../base.hpp"
#include "../../datastructure/SegmentTreeBeats.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;

    SegmentTreeBeats<int> seg(n);
    vector<int> v(n,INT_MAX);
    seg.build(v);

    for (;q--;){
        int c; cin >> c;
        if (!c){
            int s,t,x; cin >> s >> t >> x;
            seg.update_val(s,t+1,x);
        } else {
            int i; cin >> i;
            cout << seg[i] << '\n';
        }
    }
}