#define PROBLEM "https://yukicoder.me/problems/no/3046"

#include "../../base.hpp"
#include "../../modulo/modint.hpp"
#include "../../convolution/ArbitaryModConvolution.hpp"
#include "../../polynomial/FormalPowerSeries.hpp"

using mint=modint<MOD>;
using FPS=FormalPowerSeries<mint>;
const int MAX_N=100010;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    auto mul=[&](const FPS::Poly &a,const FPS::Poly &b){
        auto res=ArbitaryModConvolution(a,b);
        return FPS::Poly(res.begin(),res.end());
    };
    FPS::set_mul(mul);

    int K,N; cin >> K >> N;
    FPS a(MAX_N,0); a[0]+=1;
    for (;N--;){
        int x; cin >> x;
        a[x]-=1;
    }
    a=a.inv();
    cout << a[K] << '\n';
}