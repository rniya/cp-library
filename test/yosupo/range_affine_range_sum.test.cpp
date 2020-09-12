#define PROBLEM "https://judge.yosupo.jp/problem/range_affine_range_sum"

#include "../../base.hpp"
#include "../../modulo/modint.hpp"
#include "../../datastructure/LazySegmentTree.hpp"

using mint=modint<998244353>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<mint> a(N);
    for (int i=0;i<N;++i) cin >> a[i];

    struct node{
        mint sum; int a;
        node(mint sum,int a):sum(sum),a(a){}
    };
    struct add{
        mint b,c;
        add(mint b,mint c):b(b),c(c){}
        const bool operator==(const add &rhs){
            return b==rhs.b&&c==rhs.c;
        }
    };
    auto f=[](node a,node b){return node(a.sum+b.sum,a.a+b.a);};
    auto g=[](node a,add x){return node(a.sum*x.b+x.c*a.a,a.a);};
    auto h=[](add a,add b){return add(a.b*b.b,a.c*b.b+b.c);};
    LazySegmentTree<node,add> seg(N,f,g,h,node(0,0),add(1,0));
    vector<node> v;
    for (int i=0;i<N;++i) v.emplace_back(a[i],1);
    seg.build(v);

    for (;Q--;){
        int t,l,r; cin >> t >> l >> r;
        if (!t){
            mint b,c; cin >> b >> c;
            seg.update(l,r,add(b,c));
        } else cout << seg.query(l,r).sum << '\n';
    }
}