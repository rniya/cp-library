#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/lesson/1/ALDS1/14/ALDS1_14_B"

#include "../../base.hpp"
#include "../../string/RollingHash.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S,T; cin >> S >> T;

    RollingHash rh1(S),rh2(T);
    int s=S.size(),t=T.size();

    for (int i=0;i+t<=s;++i){
        if (rh1.get(i,i+t)==rh2.get(0,t)){
            cout << i << '\n';
        }
    }
}