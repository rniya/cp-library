#define PROBLEM "https://yukicoder.me/problems/no/665"

#include "../../base.hpp"
#include "../../modulo/modint.hpp"
#include "../../polynomial/lagrange_interpolation.hpp"

using mint=modint<1000000007>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    long long n; int k; cin >> n >> k;
    vector<mint> A(k+2,0);
    for (int i=1;i<=k+1;++i) A[i]=A[i-1]+pow((mint)i,k);
    cout << lagrange_interpolation_arithmetic(A,(mint)n) << '\n';
}