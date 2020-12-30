#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E"
#define ERROR 0.000001

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    Circle c_1,c_2; cin >> c_1 >> c_2;
    auto res=crosspoint(c_1,c_2);
    cout << res.first << ' ' << res.second << '\n';
}