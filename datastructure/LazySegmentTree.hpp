#pragma once
#include "../base.hpp"

/**
 * @brief Lazy Segment Tree
 * @docs docs/datastructure/LazySegmentTree.md
 */
template <typename Monoid, typename OperatorMonoid> struct LazySegmentTree {
    typedef function<Monoid(Monoid, Monoid)> F;
    typedef function<Monoid(Monoid, OperatorMonoid)> G;
    typedef function<OperatorMonoid(OperatorMonoid, OperatorMonoid)> H;
    int n, hi;
    F f;
    G g;
    H h;
    Monoid id0;
    OperatorMonoid id1;
    vector<Monoid> dat;
    vector<OperatorMonoid> laz;
    LazySegmentTree(int n_, F f, G g, H h, Monoid id0, OperatorMonoid id1) : f(f), g(g), h(h), id0(id0), id1(id1) {
        init(n_);
    }
    void init(int n_) {
        n = 1, hi = 0;
        while (n < n_) n <<= 1, hi++;
        dat.assign(n << 1, id0);
        laz.assign(n << 1, id1);
    }
    void build(const vector<Monoid>& v) {
        for (int i = 0; i < v.size(); i++) dat[i + n] = v[i];
        for (int i = n - 1; i; --i) dat[i] = f(dat[i << 1 | 0], dat[i << 1 | 1]);
    }
    inline Monoid reflect(int k) { return laz[k] == id1 ? dat[k] : g(dat[k], laz[k]); }
    inline void propagate(int k) {
        if (laz[k] == id1) return;
        laz[k << 1 | 0] = h(laz[k << 1 | 0], laz[k]);
        laz[k << 1 | 1] = h(laz[k << 1 | 1], laz[k]);
        dat[k] = reflect(k);
        laz[k] = id1;
    }
    inline void thrust(int k) {
        for (int i = hi; i; i--) propagate(k >> i);
    }
    inline void recalc(int k) {
        while (k >>= 1) dat[k] = f(reflect(k << 1 | 0), reflect(k << 1 | 1));
    }
    void update(int a, int b, OperatorMonoid x) {
        if (a >= b) return;
        thrust(a += n);
        thrust(b += n - 1);
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) laz[l] = h(laz[l], x), ++l;
            if (r & 1) --r, laz[r] = h(laz[r], x);
        }
        recalc(a);
        recalc(b);
    }
    void set_val(int k, Monoid x) {
        thrust(k += n);
        dat[k] = x, laz[k] = id1;
        recalc(k);
    }
    Monoid query(int a, int b) {
        if (a >= b) return id0;
        thrust(a += n);
        thrust(b += n - 1);
        Monoid vl = id0, vr = id0;
        for (int l = a, r = b + 1; l < r; l >>= 1, r >>= 1) {
            if (l & 1) vl = f(vl, reflect(l++));
            if (r & 1) vr = f(reflect(--r), vr);
        }
        return f(vl, vr);
    }
    template <typename C> int find_subtree(int k, const C& check, Monoid& M, bool type) {
        while (k < n) {
            propagate(k);
            Monoid nxt = type ? f(reflect(k << 1 | type), M) : f(M, reflect(k << 1 | type));
            if (check(nxt))
                k = k << 1 | type;
            else
                M = nxt, k = k << 1 | (type ^ 1);
        }
        return k - n;
    }
    // min i s.t. f(seg[a],seg[a+1],...,seg[i]) satisfy "check"
    template <typename C> int find_first(int a, const C& check) {
        Monoid L = id0;
        if (a <= 0) {
            if (check(f(L, reflect(1)))) return find_subtree(1, check, L, false);
            return -1;
        }
        thrust(a + n);
        int b = n;
        for (int l = a + n, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (l & 1) {
                Monoid nxt = f(L, reflect(l));
                if (check(nxt)) return find_subtree(l, check, L, false);
                L = nxt;
                l++;
            }
        }
        return -1;
    }
    // max i s.t. f(seg[i],...,seg[b-2],seg[b-1]) satisfy "check"
    template <typename C> int find_last(int b, const C& check) {
        Monoid R = id0;
        if (b >= n) {
            if (check(f(reflect(1), R))) return find_subtree(1, check, R, true);
            return -1;
        }
        thrust(b + n - 1);
        int a = n;
        for (int l = a, r = b + n; l < r; l >>= 1, r >>= 1) {
            if (r & 1) {
                Monoid nxt = f(reflect(--r), R);
                if (check(nxt)) return find_subtree(r, check, R, true);
                R = nxt;
            }
        }
        return -1;
    }
    Monoid operator[](int i) { return query(i, i + 1); }
};