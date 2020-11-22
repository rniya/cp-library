#define PROBLEM "https://judge.yosupo.jp/problem/static_range_inversions_query"

#include "../../base.hpp"
#include "../../util/compress.hpp"
#include "../../datastructure/BinaryIndexedTree.hpp"
#include "../../other/Mo.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<int> A(N);
    for (int i=0;i<N;++i) cin >> A[i];

    Mo mo(N);
    for (int i=0;i<Q;++i){
        int l,r; cin >> l >> r;
        mo.insert(l,r);
    }

    map<int,int> mp=compress(A);
    for (int i=0;i<N;++i) A[i]=mp[A[i]];
    int n=mp.size();
    BinaryIndexedTree<int> BIT(n);
    vector<long long> ans(Q);
    long long inv=0; int sum=0;
    auto add_left=[&](int idx){
        inv+=BIT.query(0,A[idx]);
        ++sum; BIT.add(A[idx],1);
    };
    auto add_right=[&](int idx){
        inv+=BIT.query(A[idx]+1,n);
        ++sum; BIT.add(A[idx],1);
    };
    auto del_left=[&](int idx){
        inv-=BIT.query(0,A[idx]);
        --sum; BIT.add(A[idx],-1);
    };
    auto del_right=[&](int idx){
        inv-=BIT.query(A[idx]+1,n);
        --sum; BIT.add(A[idx],-1);
    };
    auto rem=[&](int idx){
        ans[idx]=inv;
    };

    mo.build(add_left,add_right,del_left,del_right,rem);

    for (int i=0;i<Q;++i) cout << ans[i] << '\n';
}