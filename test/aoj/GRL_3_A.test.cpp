#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_A"

#include "../../base.hpp"
#include "../../graph/LowLink.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int V,E; cin >> V >> E;

    LowLink L(V);
    for (int i=0;i<E;++i){
        int s,t; cin >> s >> t;
        L.add_edge(s,t);
    }

    L.build();
    vector<int> ans=L.articulation;
    sort(ans.begin(),ans.end());
    for (int v:ans) cout << v << '\n';
}