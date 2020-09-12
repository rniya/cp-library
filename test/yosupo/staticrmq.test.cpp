#define PROBLEM "https://judge.yosupo.jp/problem/staticrmq"

#include "../../base.hpp"
#include "../../datastructure/SparseTable.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<int> a(N);
    for (int i=0;i<N;++i) cin >> a[i];

    SparseTable<int> ST([](int a,int b){return min(a,b);});
    ST.build(a);

    for (;Q--;){
        int l,r; cin >> l >> r;
        cout << ST.query(l,r) << '\n';
    }
}