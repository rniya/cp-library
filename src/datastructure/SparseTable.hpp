#pragma once
#include <cassert>
#include <vector>

template <class S, S (*op)(S, S), S (*e)()> struct SparseTable {
    SparseTable() {}

    SparseTable(const std::vector<S>& v) : n(v.size()) {
        table.resize(n + 1);
        table[0] = table[1] = 0;
        for (int i = 2; i <= n; i++) table[i] = table[i >> 1] + 1;
        int h = table.back() + 1;
        d.assign(h, std::vector<S>(n, e()));
        d[0] = v;
        for (int i = 1; i < h; i++) {
            for (int j = 0; j + (1 << i) <= n; j++) {
                d[i][j] = op(d[i - 1][j], d[i - 1][j + (1 << (i - 1))]);
            }
        }
    }
    S prod(int l, int r) const {
        assert(0 <= l and r <= n);
        if (l >= r) return e();
        int h = table[r - l];
        return op(d[h][l], d[h][r - (1 << h)]);
    }

  private:
    int n;
    std::vector<std::vector<S>> d;
    std::vector<int> table;
};