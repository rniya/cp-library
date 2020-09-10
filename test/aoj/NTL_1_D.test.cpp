#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_D"

#include "../../base.hpp"
#include "../../math/euler_phi.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;

    cout << eular_phi(n) << '\n';
}