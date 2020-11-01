#define IGNORE

#define PROBLEM "https://codeforces.com/contest/1444/problem/C"

#include "../../base.hpp"
#include "../../datastructure/UnionFindUndo.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,m,k; cin >> n >> m >> k;
    vector<int> c(n);
    for (int i=0;i<n;++i) cin >> c[i];

    UnionFindUndo UF(2*n);
    auto merge=[&](int a,int b){
        UF.merge(a,b+n);
        UF.merge(a+n,b);
    };
    map<pair<int,int>,vector<pair<int,int>>> mp;
    for (int i=0;i<m;++i){
        int a,b; cin >> a >> b;
        int ca=c[--a],cb=c[--b];
        if (ca>cb) swap(a,b),swap(ca,cb);
        if (ca==cb) merge(a,b);
        else mp[{ca,cb}].emplace_back(a,b);
    }
    UF.snapshot();

    int soli=0;
    vector<bool> ok(k,true);
    for (int i=0;i<n;++i){
        if (!ok[c[i]]) continue;
        if (UF.same(i,i+n)){
            ok[c[i]]=false;
            ++soli;
        }
    }
    ll ans=(ll)k*(k-1)/2-(ll)(k-soli+k-1)*soli/2;

    for (auto x:mp){
        int ca=x.first.first,cb=x.first.second;
        if (!ok[ca]) continue;
        if (!ok[cb]) continue;
        int check=0;
        for (auto e:x.second){
            int a=e.first,b=e.second;
            merge(a,b);
            check|=UF.same(a,a+n);
        }
        ans-=check;
        UF.rollback();
    }

    cout << ans << '\n';
}