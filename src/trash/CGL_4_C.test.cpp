#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_C"
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
    int q;
    cin >> q;
    for (; q--;) {
        Line l;
        cin >> l;
        cout << convex_cut(g, l).area() << '\n';
    }
    return 0;
}