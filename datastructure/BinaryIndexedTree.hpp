#pragma once
#include "../base.hpp"

/**
 * @brief Binary Indexed Tree
 * @docs docs/datastructure/BinaryIndexedTree.md
 */
template <typename T> class BinaryIndexedTree {
    T sum(int i) {
        T res = T();
        for (; i > 0; i -= (i & -i)) res += dat[i];
        return res;
    }

public:
    int n;
    vector<T> dat;
    BinaryIndexedTree(int n_) : n(n_ + 1), dat(n + 1, 0) {}
    void add(int i, const T& x) {
        for (++i; i <= n; i += (i & -i)) dat[i] += x;
    }
    T query(int l, int r) { return sum(r) - sum(l); }
    int lower_bound(T x) const {
        if (x <= 0) return 0;
        int pos = 0, k = 1;
        while (k < n) k <<= 1;
        for (; k > 0; k >>= 1) {
            if (pos + k <= n && dat[pos + k] < x) {
                x -= dat[pos + k];
                pos += k;
            }
        }
        return pos;
    }
    int upper_bound(T x) const { return lower_bound(x + 1); }
    T operator[](int i) { return query(i, i + 1); }
};