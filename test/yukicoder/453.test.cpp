#define PROBLEM "https://yukicoder.me/problems/no/453"

#include <iomanip>
#include <iostream>
#include "flow/Simplex.hpp"

int main() {
    std::cin.tie(0);
    std::ios::sync_with_stdio(false);
    std::cout << std::fixed << std::setprecision(10);
    double C, D;
    std::cin >> C >> D;

    std::vector<std::vector<double>> A{{3.0 / 4.0, 2.0 / 7.0}, {1.0 / 4.0, 5.0 / 7.0}};
    std::vector<double> b{C, D};
    std::vector<double> c{1000, 2000};
    Simplex simplex(A, b, c);

    std::cout << simplex.opt << '\n';
    return 0;
}