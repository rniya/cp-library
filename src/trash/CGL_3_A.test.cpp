#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A"

#include "base.hpp"
#include "geometry/geometry.hpp"

using namespace geometry;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(1);
    int n;
    cin >> n;
    Polygon g(n);
    for (auto& p : g) cin >> p;
    cout << g.area() << '\n';
    return 0;
}