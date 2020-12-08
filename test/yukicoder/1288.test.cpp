#define PROBLEM "https://yukicoder.me/problems/no/1288"

#include "../../base.hpp"
#include "../../flow/PrimalDual.hpp"

const long long inf=1e9;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; string S; cin >> N >> S;

    PrimalDual<int,long long> PD(4*N+2);
    int s=4*N,t=4*N+1;
    PD.add_edge(s,0,N,0);
    for (int i=0;i<N;++i){
        int V; cin >> V;
        V=inf-V;
        if (S[i]=='y') PD.add_edge(i,i+N,1,V);
        if (S[i]=='u') PD.add_edge(i+N,i+2*N,1,V);
        if (S[i]=='k') PD.add_edge(i+2*N,i+3*N,1,V);
        if (S[i]=='i') PD.add_edge(i+3*N,t,1,V);
        if (i==N-1) continue;
        for (int j=0;j<4;++j) PD.add_edge(i+j*N,i+1+j*N,N,0);
    }
    PD.add_edge(s,t,N,4*inf);

    cout << 4*inf*N-PD.min_cost_flow(s,t,N) << '\n';
}