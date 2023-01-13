#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_F"
#define ERROR 0.00001

#include "base.hpp"
#include "geometry/geometry.hpp"

using namespace geometry;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    Point p;
    Circle c;
    cin >> p >> c;
    auto res = tangent_to_circle(c, p);
    if (res[0] > res[1]) swap(res[0], res[1]);
    cout << res[0] << '\n' << res[1] << '\n';
    return 0;
}