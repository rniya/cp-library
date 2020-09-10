#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_C"

#include "../../base.hpp"
#include "../../graoh/StronglyConnectedComponents.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V,E; cin >> V >> E;

    StronglyConnectedComponents SCC(V);
    for (int i=0;i<E;++i){
        int s,t; cin >> s >> t;
        SCC.add_edge(s,t);
    }
    SCC.build();

    int Q; cin >> Q;
    for (;Q--;){
        int u,v; cin >> u >> v;
        cout << (SCC[u]==SCC[v]) << '\n';
    }
}