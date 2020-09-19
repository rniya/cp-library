#define IGNORE

#define PROBLEM "https://atcoder.jp/contests/colopl2018-final-open/tasks/colopl2018_final_c"

#include "../../base.hpp"
#include "../../datastructure/ConvexHullTrick.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N; cin >> N;
    vector<long long> a(N);
    for (int i=0;i<N;++i) cin >> a[i];

    ConvexHullTrick<long long> CHT;

    for (long long i=0;i<N;++i) CHT.add(-2*i,a[i]+i*i);
    for (long long i=0;i<N;++i) cout << CHT.query_monotone_inc(i)+i*i << '\n';
}