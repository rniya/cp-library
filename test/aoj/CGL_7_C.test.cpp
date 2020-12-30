#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_C"
#define ERROR 0.000001

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    Point p_1,p_2,p_3; cin >> p_1 >> p_2 >> p_3;
    auto res=circumcenter(p_1,p_2,p_3);
    cout << res << '\n';
}