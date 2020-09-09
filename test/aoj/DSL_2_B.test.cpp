#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DSL_2_B"

#include "../../base.hpp"
#include "../../datastructure/BinaryIndexedTree.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,q; cin >> n >> q;

    BinaryIndexedTree<int> BIT(n+1);

    for (;q--;){
        int c,x,y; cin >> c >> x >> y;
        if (!c) BIT.add(x,y);
        else cout << BIT.query(x,y+1) << '\n';
    }
}