#define PROBLEM "https://judge.yosupo.jp/problem/scc"

#include "../../base.hpp"
#include "../../graph/StronglyConnectedComponents.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M; cin >> N >> M;

    StronglyConnectedComponents SCC(N);
    for (int i=0;i<M;++i){
        int a,b; cin >> a >> b;
        SCC.add_edge(a,b);
    }

    int K=SCC.build();
    cout << K << '\n';
    for (int i=0;i<K;++i){
        cout << SCC.C[i].size();
        for (int v:SCC.C[i]) cout << ' ' << v;
        cout << '\n';
    }
}