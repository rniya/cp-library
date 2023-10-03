#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_A"
#define ERROR 0.00000001

#include "geometry/convex_hull.hpp"

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    int n;
    std::cin >> n;
    std::vector<Point<int>> P(n);
    for (auto& p : P) std::cin >> p;
    auto res = convex_hull(P, true);
    int start = 0;
    for (int i = 1; i < int(res.size()); i++) {
        if (P[res[i]].y == P[res[start]].y ? P[res[i]].x < P[res[start]].x : P[res[i]].y < P[res[start]].y) {
            start = i;
        }
    }
    std::rotate(begin(res), begin(res) + start, end(res));
    std::cout << res.size() << '\n';
    for (int& i : res) std::cout << P[i].x << ' ' << P[i].y << '\n';
    return 0;
}