#pragma once
#include <cassert>
#include <numeric>
#include <vector>

struct Simplex {
    bool infinity,           // which the problem is unbounded or not
        infeasible;          // which the problem is infeasible or not
    int n,                   // the number of variables
        m;                   // the number of constraints
    std::vector<double> x;   // optimal solution
    double opt;              // optimal value
    std::vector<int> index;  // indices of non-basis (< n) and basis (otherwise)
    int r, s;                // pivot row / column
    std::vector<std::vector<double>> tableau;

    /**
     * @brief Construct a new Simplex object
     *
     * @param A Coefficients of constraints
     * @param b Bounds of constraints
     * @param c Coefficients of objective function
     * @param mode choose pivot by smallest subscript rule if mode = 0, largest coefficient rule otherwise
     * @details Maximize cx s.t. Ax <= b and x >= 0
     */
    Simplex(const std::vector<std::vector<double>>& A,
            const std::vector<double>& b,
            const std::vector<double>& c,
            int mode = 0) {
        infinity = infeasible = false;
        init(A, b, c);
        solve(mode);
    }

private:
    static constexpr double EPS = 1e-10;

    inline int sgn(const double& x) { return x < -EPS ? -1 : x > EPS ? 1 : 0; }

    inline int compare(const double& a, const double& b) { return sgn(a - b); }

    inline bool equals(const double& a, const double& b) { return compare(a, b) == 0; }

    void init(const std::vector<std::vector<double>>& A, const std::vector<double>& b, const std::vector<double>& c) {
        m = A.size(), n = c.size();

        index.resize(n + 1 + m);
        std::iota(index.begin(), index.end(), 0);
        tableau.assign(m + 2, std::vector<double>(n + 2, 0));

        r = m;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) tableau[i][j] = -A[i][j];
            tableau[i][n] = 1;
            tableau[i][n + 1] = b[i];
            if (tableau[i][n + 1] < tableau[r][n + 1]) r = i;
        }
        for (int j = 0; j < n; j++) tableau[m][j] = c[j];
        tableau[m + 1][n] = -1;
    }

    void smallest_subscript_rule() {
        r = s = -1;
        for (int j = 0; j < n + 1; j++) {
            if (s < 0 or index[j] < index[s]) {
                if (compare(tableau[m + 1][j], 0) > 0 or
                    (equals(tableau[m + 1][j], 0) and compare(tableau[m][j], 0) > 0)) {
                    s = j;
                }
            }
        }
        if (s < 0) return;
        r = -1;
        for (int i = 0; i < m; i++) {
            if (compare(tableau[i][s], 0) >= 0) continue;
            if (r < 0)
                r = i;
            else if (compare(tableau[i][n + 1] / (-tableau[i][s]), tableau[r][n + 1] / (-tableau[r][s])) < 0)
                r = i;
            else if (equals(tableau[i][n + 1] / (-tableau[i][s]), tableau[r][n + 1] / (-tableau[r][s])) and
                     index[n + 1 + i] < index[n + 1 + r]) {
                r = i;
            }
        }
    }

    void largest_coefficient_rule() {
        r = s = -1;
        double Max = 0;
        for (int j = 0; j < n + 1; j++) {
            if (compare(tableau[m + 1][j], Max) > 0)
                s = j, Max = tableau[m + 1][j];
            else if (equals(tableau[m + 1][j], 0) and compare(tableau[m][j], Max) > 0)
                s = j, Max = tableau[m][j];
        }
        if (s < 0) return;
        r = -1;
        for (int i = 0; i < m; i++) {
            if (compare(tableau[i][s], 0) >= 0) continue;
            if (r < 0)
                r = i;
            else if (compare(tableau[i][n + 1] / (-tableau[i][s]), tableau[r][n + 1] / (-tableau[r][s])) < 0)
                r = i;
        }
    }

    void solve(int mode) {
        std::vector<int> nonzero;
        for (s = n;;) {
            if (r < m) {
                std::swap(index[s], index[n + 1 + r]);
                tableau[r][s] = double(1) / tableau[r][s];
                nonzero.clear();
                for (int j = 0; j < n + 2; j++) {
                    if (j == s) continue;
                    tableau[r][j] *= -tableau[r][s];
                    if (!equals(tableau[r][j], 0)) nonzero.emplace_back(j);
                }
                for (int i = 0; i < m + 2; i++) {
                    if (i == r or equals(tableau[i][s], 0)) continue;
                    for (const auto& j : nonzero) tableau[i][j] += tableau[i][s] * tableau[r][j];
                    tableau[i][s] *= tableau[r][s];
                }
            }

            if (mode == 0)
                smallest_subscript_rule();
            else
                largest_coefficient_rule();
            if (s < 0) break;
            if (r < 0) {
                infinity = true;
                return;
            }
        }

        if (compare(tableau[m + 1][n + 1], 0) < 0) {
            infeasible = true;
            return;
        }
        x.assign(n, 0);
        for (int i = 0; i < m; i++) {
            if (index[n + 1 + i] < n) {
                x[index[n + 1 + i]] = tableau[i][n + 1];
            }
        }
        opt = tableau[m][n + 1];
    }
};
