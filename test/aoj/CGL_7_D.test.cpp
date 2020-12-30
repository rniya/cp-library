#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_D"

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    Circle c; cin >> c;
    int q; cin >> q;
    for (;q--;){
        Line l; cin >> l;
        auto res=crosspoint(c,l);
        cout << res.first << ' ' << res.second << '\n';
    }
}