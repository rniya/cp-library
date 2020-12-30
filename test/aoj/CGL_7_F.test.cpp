#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F"
#define ERROR 0.000001

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    Point p; Circle c; cin >> p >> c;
    auto res=tangent(c,p);
    cout << res.first << '\n' << res.second << '\n';
}