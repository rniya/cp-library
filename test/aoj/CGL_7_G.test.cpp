#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_G"
#define ERROR 0.00001

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

using namespace geometry;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    Circle c1, c2;
    cin >> c1 >> c2;
    vector<Point> res;
    for (auto l : common_tangent(c1, c2)) res.emplace_back(contain(c1, l.a) ? l.a : l.b);
    sort(res.begin(), res.end());
    for (auto p : res) cout << p << '\n';
    return 0;
}