#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_B"

#include "../../base.hpp"
#include "../../math/modpow.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long m,n; cin >> m >> n;

    cout << modpow(m,n,1000000007) << '\n';
}