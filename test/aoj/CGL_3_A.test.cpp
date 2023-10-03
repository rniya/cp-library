#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/3/CGL_3_A"

#include <iomanip>
#include "Polygon.hpp"

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(1);
    int n;
    std::cin >> n;
    Polygon<double> P(n);
    for (auto& p : P) std::cin >> p;
    auto res = P.area();
    std::cout << res << '\n';
}