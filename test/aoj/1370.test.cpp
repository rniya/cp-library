#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/1370"

#include "../../base.hpp"
#include "../../string/RollingHash.hpp"

const int MAX_N=4010;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    vector<vector<uint64_t>> hash(MAX_N);
    RollingHash rh;
    int ans=0;

    for (int i=0;i<2;++i){
        string S; cin >> S;
        int n=S.size();
        vector<int> cnt(26,0);
        for (int j=0;j<n;++j){
            for (int k=1;j+k<=n;++k){
                ++cnt[S[j+k-1]-'a'];
                uint64_t h=rh.get(cnt);
                if (!i) hash[k].emplace_back(h);
                else if (binary_search(hash[k].begin(),hash[k].end(),h)) ans=max(ans,k);
            }
            for (int k=0;k<26;++k) cnt[k]=0;
        }
        if (i) continue;
        for (int j=1;j<=n;++j) sort(hash[j].begin(),hash[j].end());
    }

    cout << ans << '\n';
}