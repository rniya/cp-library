#define PROBLEM "https://yukicoder.me/problems/no/952"

#include "../../base.hpp"
#include "../../datastructure/ConvexHullTrick.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    const long long inf=(1LL<<62)-1;
    int N; cin >> N;
    vector<long long> A(N);
    for (int i=0;i<N;++i) cin >> A[i];

    vector<long long> sum(N+1,0);
    for (int i=0;i<N;++i) sum[i+1]=sum[i]+A[i];

    vector<ConvexHullTrick<long long>> CHT(N+2);
    vector<vector<long long>> dp(N+1,vector<long long>(N+1,inf));
    dp[0][0]=0;
    CHT[0].add(0,0);

    for (int i=0;i<N;++i){
        for (int j=0;j<=i+1;++j){
            dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
            if (!CHT[i+1-j].empty()) dp[i+1][j]=min(dp[i+1][j],sum[i+1]*sum[i+1]+CHT[i+1-j].query_monotone_dec(-2*sum[i+1]));
            if (i<N-1) CHT[i+1-j].add(sum[i+1],dp[i][j]+sum[i+1]*sum[i+1]);
        }
    }

    for (int j=1;j<=N;++j) cout << dp[N][j] << '\n';
}