#define IGNORE

#define PROBLEM "https://atcoder.jp/contests/agc002/tasks/agc002_d"

#include "../../base.hpp"
#include "../../datastructure/PartiallyPersistentUnionFind.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;

    PartiallyPersistentUnionFind UF(N);

    for (int i=0;i<M;++i){
        int a,b; cin >> a >> b;
        UF.merge(--a,--b);
    }

    int Q; cin >> Q;
    for (;Q--;){
        int x,y,z; cin >> x >> y >> z; --x,--y;
        int lb=0,ub=M+1;
        while(ub-lb>1){
            int mid=(ub+lb)>>1;
            int s=UF.size(mid,x);
            if (!UF.same(mid,x,y)) s+=UF.size(mid,y);
            (s>=z?ub:lb)=mid;
        }
        cout << ub << '\n';
    }
}