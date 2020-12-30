#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_C"

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    Point p_0,p_1; cin >> p_0 >> p_1;
    int q; cin >> q;
    for (;q--;){
        Point p_2; cin >> p_2;
        int res=ccw(p_0,p_1,p_2);
        if (res==1) cout << "COUNTER_CLOCKWISE" << '\n';
        else if (res==-1) cout << "CLOCKWISE" << '\n';
        else if (res==2) cout << "ONLINE_BACK" << '\n';
        else if (res==-2) cout << "ONLINE_FRONT" << '\n';
        else cout << "ON_SEGMENT" << '\n';
    }
}