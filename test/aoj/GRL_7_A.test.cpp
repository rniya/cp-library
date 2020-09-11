#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/7/GRL_7_A"

#include "../../base.hpp"
#include "../../flow/BipartiteMatching.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int X,Y,E; cin >> X >> Y >> E;

    BipartiteMatching BM(X+Y);
    for (int i=0;i<E;++i){
        int x,y; cin >> x >> y;
        BM.add_edge(x,y+X);
    }

    cout << BM.build() << '\n';
}