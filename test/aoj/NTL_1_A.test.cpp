#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/6/NTL/1/NTL_1_A"

#include "../../base.hpp"
#include "../../math/prime_factor.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n; cin >> n;

    map<int,int> ans=prime_factor(n);
    cout << n << ':';
    for (auto p:ans){
        for (int i=0;i<p.second;++i){
            cout << ' ' << p.first;
        }
    }
    cout << '\n';
}