#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A"

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(0);
    int n;
    cin >> n;
    Polygon P(n);
    cin >> P;
    auto res = convex_hull(P, true);
    cout << res.size() << '\n';
    for (auto p : res) cout << p.x << ' ' << p.y << '\n';
}