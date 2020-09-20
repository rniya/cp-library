#define IGNORE

#define PROBLEM "https://atcoder.jp/contests/ukuku09/tasks/ukuku09_d"

#include "../../base.hpp"
#include "../../string/Manacher.hpp"
#include "../../datastructure/SegmentTree.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; string S; cin >> N >> Q >> S;

    vector<int> v=Manacher(S);
    SegmentTree<int> seg(N,[](int a,int b){return max(a,b);},0);
    seg.build(v);

    for (;Q--;){
        int l,r; cin >> l >> r; --l;
        int lb=0,ub=(r-l+1)/2+1;
        while(ub-lb>1){
            int mid=(lb+ub)>>1;
            int x=seg.query(l+mid-1,r-mid+1);
            (mid<=x?lb:ub)=mid;
        }
        cout << lb*2-1 << '\n';
    }
}