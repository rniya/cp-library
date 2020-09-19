#define IGNORE

#define PROBLEM "https://atcoder.jp/contests/abc137/tasks/abc137_e"

#include "../../base.hpp"
#include "../../graph/BellmanFord.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M,P; cin >> N >> M >> P;

    BellmanFord<int> BF(N);
    for (int i=0;i<M;++i){
        int A,B,C; cin >> A >> B >> C;
        BF.add_edge(--A,--B,P-C);
    }

    int neg;
    int ans=BF.shortest_path(0,N-1,neg);
    cout << (neg?-1:max(0,-ans)) << '\n';
}