#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_E"
#define ERROR 0.000001

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

using namespace geometry;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    Circle c_1, c_2;
    cin >> c_1 >> c_2;
    auto res = crosspoint(c_1, c_2);
    if (res.size() == 1)
        cout << res[0] << ' ' << res[0] << '\n';
    else {
        if (res[1] < res[0]) swap(res[0], res[1]);
        cout << res[0] << ' ' << res[1] << '\n';
    }
    return 0;
}