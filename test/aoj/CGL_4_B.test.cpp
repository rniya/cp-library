#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/4/CGL_4_B"
#define ERROR 0.000001

#include <iomanip>
#include "geometry/convex_diameter.hpp"

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
    int n;
    std::cin >> n;
    Polygon<int> P(n);
    for (auto& p : P) std::cin >> p;
    auto [i, j] = convex_diameter(P);
    auto d = P[i] - P[j];
    double res = std::sqrt(d.x * d.x + d.y * d.y);
    std::cout << res << '\n';
}