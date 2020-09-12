#define PROBLEM "https://judge.yosupo.jp/problem/two_sat"

#include "../../base.hpp"
#include "../../graph/StronglyConnectedComponents.hpp"
#include "../../graph/TwoSatisfiability.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string p,cnf; cin >> p >> cnf;
    int N,M; cin >> N >> M;

    TwoSatisfiability TS(N+1);
    for (int i=0;i<M;++i){
        int a,b,c; cin >> a >> b >> c;
        TS.add_or((a<0?TS.neg(-a):a),(b<0?TS.neg(-b):b));
    }

    vector<int> ans=TS.build();
    if (ans.empty()){cout << "s UNSATISFIABLE" << '\n'; return 0;}
    cout << "s SATISFIABLE" << '\n';
    cout << "v ";
    for (int i=1;i<=N;++i) cout << (ans[i]?i:-i) << ' ';
    cout << "0\n";
}