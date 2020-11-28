#define PROBLEM "https://yukicoder.me/problems/no/1301"

#include "../../base.hpp"
#include "../../flow/PrimalDual.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;

    PrimalDual<int,long long> PD(N);
    for (int i=0;i<M;++i){
        int u,v,c,d; cin >> u >> v >> c >> d; --u,--v;
        PD.add_edge(u,v,1,c); PD.add_edge(v,u,1,c);
        PD.add_edge(u,v,1,d); PD.add_edge(v,u,1,d);
    }

    cout << PD.min_cost_flow(0,N-1,2) << '\n';
}