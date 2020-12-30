#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_A"

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q; cin >> q;
    for (;q--;){
        Line s_1,s_2; cin >> s_1 >> s_2;
        if (parallel(s_1,s_2)) cout << 2 << '\n';
        else if (orthogonal(s_1,s_2)) cout << 1 << '\n';
        else cout << 0 << '\n';
    }
}