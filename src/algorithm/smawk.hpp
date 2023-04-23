#include <vector>

template <class F> std::vector<int> smawk(int N, int M, const F& f) {
    auto solve = [&](auto&& self, const std::vector<int>& row, const std::vector<int>& col) -> std::vector<int> {
        int n = row.size();
        if (n == 0) return {};
        std::vector<int> nrow, ncol;
        for (const int& i : col) {
            while (not ncol.empty() and f(row[ncol.size() - 1], ncol.back()) > f(row[ncol.size() - 1], i))
                ncol.pop_back();
            if (int(ncol.size()) < n) ncol.emplace_back(i);
        }
        for (int i = 1; i < n; i += 2) nrow.emplace_back(row[i]);
        auto nres = self(self, nrow, ncol);
        std::vector<int> res(n);
        for (int i = 0; i < int(nres.size()); i++) res[2 * i + 1] = nres[i];
        for (int i = 0, j = 0; i < n; i += 2) {
            res[i] = ncol[j];
            int last = i + 1 == n ? ncol.back() : res[i + 1];
            while (ncol[j] < last) {
                j++;
                if (f(row[i], res[i]) > f(row[i], ncol[j])) res[i] = ncol[j];
            }
        }
        return res;
    };
    std::vector<int> row(N), col(M);
    iota(begin(row), end(row), 0);
    iota(begin(col), end(col), 0);
    return solve(solve, row, col);
}