#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/1/CGL_1_A"

#include "../../base.hpp"
#include "../../geometry/geometry.hpp"

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    Line l;
    cin >> l;
    int q;
    cin >> q;
    for (; q--;) {
        Point p;
        cin >> p;
        cout << projection(l, p) << '\n';
    }
}