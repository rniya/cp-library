#define PROBLEM "https://judge.yosupo.jp/problem/persistent_unionfind"

#include "../../base.hpp"
#include "../../datastructure/UnionFindUndo.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<int> t(Q),u(Q),v(Q);
    vector<vector<int>> G(Q+1);
    for (int i=0;i<Q;++i){
        int k; cin >> t[i] >> k >> u[i] >> v[i];
        G[++k].emplace_back(i+1);
    }

    UnionFindUndo UF(N);
    vector<int> ans(Q,-1);
    auto dfs=[&](auto self,int cur)->void{
        if (cur){
            if (!t[cur-1]) UF.merge(u[cur-1],v[cur-1]);
            else ans[cur-1]=UF.same(u[cur-1],v[cur-1]);
        }
        for (int nxt:G[cur]) self(self,nxt);
        if (cur&&!t[cur-1]) UF.undo();
    };
    dfs(dfs,0);
    for (int i=0;i<Q;++i){
        if (~ans[i]){
            cout << ans[i] << '\n';
        }
    }
}