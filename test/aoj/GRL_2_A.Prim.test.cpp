#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/2/GRL_2_A"

#include "../../base.hpp"
#include "../../graph/Prim.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V,E; cin >> V >> E;

    Prim<int> P(V);

    for (int i=0;i<E;++i){
        int s,t,w; cin >> s >> t >> w;
        P.add_edge(s,t,w);
    }

    cout << P.build() << '\n';
}