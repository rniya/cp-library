#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/4/CGL/5/CGL_5_A"
#define ERROR 0.000001

#include <iomanip>
#include "closest_pair.hpp"

using namespace geometry;

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout << std::fixed << std::setprecision(15);
    int n;
    std::cin >> n;
    std::vector<Point<double>> ps(n);
    for (auto& p : ps) std::cin >> p;
    auto res = std::get<2>(closest_pair(ps));
    std::cout << res << '\n';
}