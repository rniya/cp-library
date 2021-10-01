#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/2/CGL_2_B"

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

using namespace geometry;

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int q;
    cin >> q;
    for (; q--;) {
        Segment s_1, s_2;
        cin >> s_1 >> s_2;
        cout << intersect(s_1, s_2) << '\n';
    }
    return 0;
}