#define PROBLEM "https://yukicoder.me/problems/no/430"

#include "../../base.hpp"
#include "../../string/RollingHash.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; int M; cin >> S >> M;
    int n=S.size();

    RollingHash RH(S,RollingHash::generate_base());
    map<uint64_t,int> mp;
    for (int j=0;j<=min(n,10);++j){
        for (int i=0;i+j<=n;++i){
            ++mp[RH.query(i,i+j)];
        }
    }

    int ans=0;
    for (;M--;){
        string C; cin >> C;
        ans+=mp[RH.get(C)];
    }

    cout << ans << '\n';
}