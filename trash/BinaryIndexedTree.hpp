#pragma once
#include <cassert>
#include <vector>

template <typename T> struct BinaryIndexedTree {
    BinaryIndexedTree(int n) : n(n), data(n) {}

    void add(int k, T x) {
        assert(0 <= k && k < n);
        for (k++; k <= n; k += k & -k) data[k - 1] += x;
    }

    T query(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        return sum(r) - sum(l);
    }

    T operator[](int i) const { return query(i, i + 1); }

    int lower_bound(T x) const {
        if (x <= 0) return 0;
        int cur = 0, k = 1;
        while (k < n) k <<= 1;
        for (; k > 0; k >>= 1) {
            if (cur + k <= n && data[cur + k - 1] < x) {
                x -= data[cur + k - 1];
                cur += k;
            }
        }
        return cur;
    }
    int upper_bound(T x) const { return lower_bound(x + 1); }

private:
    int n;
    std::vector<T> data;

    T sum(int r) const {
        T res = 0;
        for (; r > 0; r -= r & -r) res += data[r - 1];
        return res;
    }
};

/**
 * @brief Binary Indexd Tree (Fenwick Tree)
 * @docs docs/datastructure/BinaryIndexedTree.md
 */