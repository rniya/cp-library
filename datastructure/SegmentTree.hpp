#pragma once
#include <cassert>
#include <vector>

template <typename Monoid, typename F> struct SegmentTree {
    SegmentTree(int n, const F f, const Monoid& e) : n(n), f(f), e(e) {
        size = 1;
        while (size < n) size <<= 1;
        data.assign(size << 1, e);
    }

    void set(int k, Monoid x) {
        assert(0 <= k && k < n);
        data[k + size] = x;
    }

    void build() {
        for (int k = size - 1; k > 0; k--) {
            data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);
        }
    }

    void update(int k, Monoid x) {
        assert(0 <= k && k < n);
        k += size;
        data[k] = x;
        while (k >>= 1) data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);
    }

    void add(int k, Monoid x) {
        assert(0 <= k && k < n);
        k += size;
        data[k] += x;
        while (k >>= 1) data[k] = f(data[k << 1 | 0], data[k << 1 | 1]);
    }

    Monoid query(int l, int r) const {
        assert(0 <= l && l <= r && r <= n);
        Monoid L = e, R = e;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = f(L, data[l++]);
            if (r & 1) R = f(data[--r], R);
        }
        return f(L, R);
    }

    Monoid all_prod() const { return data[1]; }

    Monoid operator[](const int& k) const { return data[k + size]; }

    template <typename C> int find_first(int l, const C& check) {
        assert(0 <= l && l <= n);
        assert(!check(e));
        if (l == n) return n;
        Monoid L = e;
        if (l == 0) {
            if (check(f(L, data[1]))) return find_subtree(1, check, L, false);
            return n;
        }
        int r = size;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                Monoid nxt = f(L, data[l]);
                if (check(nxt)) return find_subtree(l, check, L, false);
                L = nxt;
                l++;
            }
        }
        return n;
    }

    template <typename C> int find_last(int r, const C& check) {
        assert(0 <= r && r <= n);
        assert(!check(e));
        if (r == 0) return 0;
        Monoid R = e;
        if (r == n) {
            if (check(f(data[1], R))) return find_subtree(1, check, R, true);
            return -1;
        }
        int l = size;
        for (r += size; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                Monoid nxt = f(data[--r], R);
                if (check(nxt)) return find_subtree(r, check, R, false);
                R = nxt;
            }
        }
        return -1;
    }

private:
    int n, size;
    std::vector<Monoid> data;
    const F f;
    const Monoid e;

    template <typename C> int find_subtree(int a, const C& check, Monoid& M, bool type) {
        while (a < size) {
            Monoid nxt = type ? f(data[a << 1 | type], M) : f(M, data[a << 1 | type]);
            if (check(nxt))
                a = a << 1 | type;
            else
                M = nxt, a = (a << 1 | type) - 1;
        }
        return a - size;
    }
};

/**
 * @brief Segment Tree
 * @docs docs/datastructure/SegmentTree.md
 */