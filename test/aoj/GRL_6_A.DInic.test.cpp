#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/6/GRL_6_A"

#include "../../base.hpp"
#include "../../flow/Dinic.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V,E; cin >> V >> E;

    Dinic<int,true> D(V);
    for (int i=0;i<E;++i){
        int u,v,c; cin >> u >> v >> c;
        D.add_edge(u,v,c);
    }

    cout << D.max_flow(0,V-1) << '\n';
}