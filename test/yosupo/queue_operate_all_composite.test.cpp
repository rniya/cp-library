#define PROBLEM "https://judge.yosupo.jp/problem/queue_operate_all_composite"

#include "../../base.hpp"
#include "../../modulo/modint.hpp"
#include "../../datastructure/SlidingWindowAggregation.hpp"

using mint=modint<998244353>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    struct node{
        mint a,b;
        node(mint a,mint b):a(a),b(b){}
    };
    auto f=[](node a,node b){return node(a.a*b.a,a.b*b.a+b.b);};
    SlidingWindowAggregation<node> SWAG(f,node(1,0));

    int Q; cin >> Q;
    for (;Q--;){
        int t; cin >> t;
        if (t==0){
            int a,b; cin >> a >> b;
            SWAG.push(node(a,b));
        } else if (t==1){
            SWAG.pop();
        } else {
            int x; cin >> x;
            node ans=SWAG.fold();
            cout << ans.a*x+ans.b << '\n';
        }
    }
}