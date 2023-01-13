#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_I"
#define ERROR 0.000001

#include "base.hpp"
#include "geometry/geometry.hpp"

using namespace geometry;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    Circle c1, c2;
    cin >> c1 >> c2;
    cout << commonarea(c1, c2) << '\n';
    return 0;
}