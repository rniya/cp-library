#pragma once
#include <cassert>
#include <vector>

template <typename T> struct CumulativeSum2D {
    CumulativeSum2D(const std::vector<std::vector<T>>& v) {
        n = v.size(), m = v[0].size();
        dat.assign(n + 1, std::vector<T>(m + 1, T(0)));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                dat[i + 1][j + 1] = v[i][j];
                dat[i + 1][j + 1] += dat[i + 1][j] + dat[i][j + 1] - dat[i][j];
            }
        }
    }

    T query(int xl, int xr, int yl, int yr) const {  // [xl, xr) * [yl, yr)
        assert(0 <= xl && xl <= xr && xr <= n);
        assert(0 <= yl && yl <= yr && yr <= m);
        return dat[xr][yr] - dat[xl][yr] - dat[xr][yl] + dat[xl][yl];
    }

private:
    int n, m;
    std::vector<std::vector<T>> dat;
};
