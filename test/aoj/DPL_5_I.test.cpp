#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_I"

#include "../../base.hpp"
#include "../../modulo/modint.hpp"
#include "../../combinatorics/combination.hpp"

using mint=modint<1000000007>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    Combination<mint> COM(1010);
    int n,k; cin >> n >> k;

    mint ans=0;
    for (int i=0;i<k;++i){
        mint add=COM.C(k,i)*mint(k-i).pow(n);
        if (i&1) ans-=add;
        else ans+=add;
    }

    cout << ans*COM.finv(k) << '\n';
}