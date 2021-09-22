#pragma once
#include <cassert>
#include <climits>
#include <iterator>
#include <set>

struct Line {
    mutable long long k, m, p;
    bool operator<(const Line& o) const { return k < o.k; }
    bool operator<(long long x) const { return p < x; }
};

template <bool isMin = true> struct LineContainer : std::multiset<Line, std::less<>> {
    // (for doubles, use inf = 1/.0, div(a,b) = a/b)
    const long long inf = LLONG_MAX / 2;
    long long div(long long a, long long b) {  // floored divisoin
        return a / b - ((a ^ b) < 0 && a % b);
    }
    bool isect(iterator x, iterator y) {
        if (y == end()) {
            x->p = inf;
            return false;
        }
        if (x->k == y->k)
            x->p = x->m > y->m ? inf : -inf;
        else
            x->p = div(y->m - x->m, x->k - y->k);
        return x->p >= y->p;
    }
    void add(long long k, long long m) {
        if (isMin) k = -k, m = -m;
        auto z = insert({k, m, 0}), y = z++, x = y;
        while (isect(y, z)) z = erase(z);
        if (x != begin() && isect(--x, y)) isect(x, y = erase(y));
        while ((y = x) != begin() && (--x)->p >= y->p) isect(x, erase(y));
    }
    long long query(long long x) {
        assert(!empty());
        auto l = *lower_bound(x);
        long long s = 1;
        if (isMin) s = -1;
        return s * (l.k * x + l.m);
    }
};

/**
 * @brief Line Container (based on kactl)
 * @docs docs/datastructure/LineContainer.md
 * @see https://github.com/kth-competitive-programming/kactl/blob/main/content/data-structures/LineContainer.h#L1
 */