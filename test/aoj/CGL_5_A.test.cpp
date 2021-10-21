#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/CGL_5_A"
#define ERROR 0.000001

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

using namespace geometry;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    cout << fixed << setprecision(10);
    int n;
    cin >> n;
    vector<Point> ps(n);
    for (auto& p : ps) cin >> p;
    cout << closest_pair(ps) << '\n';
    return 0;
}