#define IGNORE

#define PROBLEM "https://atcoder.jp/contests/dp/tasks/dp_z"

#include "../../base.hpp"
#include "../../datastructure/ConvexHullTrick.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; long long C; cin >> N >> C;
    vector<long long> h(N);
    for (int i=0;i<N;++i) cin >> h[i];

    ConvexHullTrick<long long> CHT;

    vector<long long> dp(N,0);
    for (int i=0;i<N;++i){
        if (i) dp[i]=CHT.query_monotone_inc(h[i])+h[i]*h[i]+C;
        CHT.add(-2*h[i],h[i]*h[i]+dp[i]);
    }

    cout << dp[N-1] << '\n';
}