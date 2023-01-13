#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B"
#define ERROR 0.000001

#include "base.hpp"
#include "geometry/geometry.hpp"

using namespace geometry;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    Polygon g(n);
    for (auto& p : g) cin >> p;
    cout << get<2>(convex_diameter(g)) << '\n';
    return 0;
}