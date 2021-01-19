#pragma once
#include "../base.hpp"

/**
 * @brief Sparse table
 * @docs docs/datastructure/SparseTable.md
 */
template <typename T> struct SparseTable {
    typedef function<T(T, T)> F;
    vector<vector<T>> dat;
    vector<int> lookup;
    const F f;
    SparseTable(F f) : f(f) {}
    void build(const vector<T>& v) {
        int n = v.size(), h = 1;
        while ((1 << h) <= n) h++;
        dat.assign(h, vector<T>(n));
        lookup.assign(n + 1, 0);
        for (int i = 2; i <= n; i++) lookup[i] = lookup[i >> 1] + 1;
        for (int j = 0; j < n; j++) dat[0][j] = v[j];
        for (int i = 1, mask = 1; i < h; i++, mask <<= 1) {
            for (int j = 0; j < n; j++) {
                dat[i][j] = f(dat[i - 1][j], dat[i - 1][min(j + mask, n - 1)]);
            }
        }
    }
    T query(int a, int b) {
        int d = lookup[b - a];
        return f(dat[d][a], dat[d][b - (1 << d)]);
    }
};