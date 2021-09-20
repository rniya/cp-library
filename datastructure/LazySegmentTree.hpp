#pragma once
#include <cassert>
#include <vector>

template <typename Monoid, typename OperatorMonoid, typename F, typename G, typename H> struct LazySegmentTree {
    LazySegmentTree(int n, const F f, const G g, const H h, const Monoid& e, const OperatorMonoid& id)
        : n(n), f(f), g(g), h(h), e(e), id(id) {
        size = 1;
        height = 0;
        while (size < n) size <<= 1, height++;
        data.assign(size << 1, e);
        lazy.assign(size << 1, id);
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

    void update(int a, int b, const OperatorMonoid& x) {
        assert(0 <= a && a <= b && b <= n);
        if (a == b) return;
        thrust(a += size);
        thrust(b += size - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) lazy[l] = h(lazy[l], x), ++l;
            if (r & 1) --r, lazy[r] = h(lazy[r], x);
        }
        recalc(a);
        recalc(b);
    }

    void set_val(int k, Monoid x) {
        assert(0 <= k && k < n);
        thrust(k += size);
        data[k] = x;
        lazy[k] = id;
        recalc(k);
    }

    Monoid query(int a, int b) {
        assert(0 <= a && a <= b && b <= n);
        if (a == b) return e;
        thrust(a += size);
        thrust(b += size - 1);
        Monoid L = e, R = e;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) L = f(L, apply(l++));
            if (r & 1) R = f(apply(--r), R);
        }
        return f(L, R);
    }

    Monoid operator[](int k) {
        thrust(k += size);
        return apply(k);
    }

    template <typename C> int find_first(int l, const C& check) {
        assert(0 <= l && l <= n);
        assert(!check(e));
        if (l == n) return n;
        Monoid L = e;
        if (l == 0) {
            if (check(f(L, apply(1)))) return find_subtree(1, check, L, false);
            return n;
        }
        thrust(l + size);
        int r = size;
        for (l += size, r += size; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                Monoid nxt = f(L, apply(l));
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
            if (check(f(apply(1), R))) return find_subtree(1, check, R, true);
            return -1;
        }
        thrust(r + size - 1);
        int l = size;
        for (r += size; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                Monoid nxt = f(apply(--r), R);
                if (check(nxt)) return find_subtree(r, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }

private:
    int n, size, height;
    std::vector<Monoid> data;
    std::vector<OperatorMonoid> lazy;
    const F f;
    const G g;
    const H h;
    const Monoid e;
    const OperatorMonoid id;

    inline Monoid apply(int k) { return lazy[k] == id ? data[k] : g(data[k], lazy[k]); }

    inline void propagate(int k) {
        if (lazy[k] == id) return;
        lazy[k << 1 | 0] = h(lazy[k << 1 | 0], lazy[k]);
        lazy[k << 1 | 1] = h(lazy[k << 1 | 1], lazy[k]);
        data[k] = apply(k);
        lazy[k] = id;
    }

    inline void thrust(int k) {
        for (int i = height; i > 0; i--) propagate(k >> i);
    }

    inline void recalc(int k) {
        while (k >>= 1) data[k] = f(apply(k << 1 | 0), apply(k << 1 | 1));
    }

    template <typename C> int find_subtree(int a, const C& check, Monoid& M, bool type) {
        while (a < size) {
            propagate(a);
            Monoid nxt = type ? f(apply(1 << a | type), M) : f(M, apply(1 << a | type));
            if (check(nxt))
                a = 1 << a | type;
            else
                M = nxt, a = (a << 1 | 1) - type;
        }
        return a - size;
    }
};

/**
 * @brief Lazy Segment Tree
 * @docs docs/datastructure/LazySegmentTree.md
 */