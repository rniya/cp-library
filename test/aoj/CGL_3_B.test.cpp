#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_B"

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n;
    cin >> n;
    Polygon g(n);
    cin >> g;
    cout << is_convex(g) << '\n';
}