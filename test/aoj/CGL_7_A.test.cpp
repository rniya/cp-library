#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/7/CGL_7_A"

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

using namespace geometry;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Circle c_1, c_2;
    cin >> c_1 >> c_2;
    cout << count_tangent(c_1, c_2) << '\n';
    return 0;
}