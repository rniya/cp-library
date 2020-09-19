#define IGNORE

#define PROBLEM "https://atcoder.jp/contests/abc137/tasks/abc137_e"

#include "../../base.hpp"
#include "../../graph/BellmanFord.hpp"


int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;

    BellmanFord<long long> BF(N);
    for (int i=0;i<M;++i){
        int a,b,c; cin >> a >> b >> c;
        BF.add_edge(--a,--b,-c);
    }

    int neg;
    long long ans=BF.shortest_path(0,N-1,neg);
    if (neg) cout << "inf" << '\n';
    else cout << -ans << '\n';
}