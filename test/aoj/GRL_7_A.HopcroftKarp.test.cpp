#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/GRL_7_A"

#include "../../base.hpp"
#include "../../flow/HopcroftKarp.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int X,Y,E; cin >> X >> Y >> E;

    HopcroftKarp HK(X,Y);
    for (int i=0;i<E;++i){
        int x,y; cin >> x >> y;
        HK.add_edge(x,y);
    }

    cout << HK.max_matching().size() << '\n';
}