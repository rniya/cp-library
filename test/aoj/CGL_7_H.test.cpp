#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_H"
#define ERROR 0.00001

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

using namespace geometry;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int n, r;
    cin >> n >> r;
    Circle c(Point(0, 0), r);
    Polygon P(n);
    for (auto& p : P) cin >> p;
    cout << commonarea(c, P) << '\n';
    return 0;
}