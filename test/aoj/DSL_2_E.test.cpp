#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_E"

#include "../../base.hpp"
#include "../../datastructure/LazySegmentTree.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;

    auto f=[](int a,int b){return a+b;};
    LazySegmentTree<int,int> seg(n,f,f,f,0,0);

    for (;q--;){
        int c,s,t,x,i; cin >> c;
        if (!c){
            cin >> s >> t >> x;
            seg.update(s-1,t,x);
        } else {
            cin >> i;
            cout << seg[i-1] << '\n';
        }
    }
}