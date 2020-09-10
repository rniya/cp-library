#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_E"

#include "../../base.hpp"
#include "../../math/extgcd.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int a,b,x,y; cin >> a >> b;

    extgcd(a,b,x,y);
    cout << x << ' ' << y << '\n';
}