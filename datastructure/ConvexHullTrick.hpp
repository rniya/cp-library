#pragma once
#include <cassert>
#include <queue>

template <typename T, bool isMin = true> struct ConvexHullTrick {
    bool empty() const { return lines.empty(); }

    void add(T a, T b) {
        if (!isMin) a *= -1, b *= -1;
        std::pair<T, T> l(a, b);
        if (empty()) {
            lines.emplace_back(a, b);
            return;
        }
        if (lines.front().first <= a) {
            if (lines.front().first == a) {
                if (lines.front().second <= b) return;
                lines.pop_back();
            }
            while (lines.size() >= 2 && check(l, lines.front(), lines[1])) lines.pop_front();
            lines.emplace_front(l);
        } else if (a <= lines.back().first) {
            if (lines.back().first == a) {
                if (lines.back().second <= b) return;
                lines.pop_back();
            }
            while (lines.size() >= 2 && check(lines[lines.size() - 2], lines.back(), l)) lines.pop_back();
            lines.emplace_back(l);
        } else
            assert(false);
    }

    T query(T x) {
        assert(!called_query_monotonic_inc && !called_query_monotonic_dec);
        assert(!empty());
        called_query = true;
        int lb = -1, ub = lines.size() - 1;
        while (ub - lb > 1) {
            int mid = (ub + lb) >> 1;
            (f(lines[mid], x) >= f(lines[mid + 1], x) ? lb : ub) = mid;
        }
        T res = f(lines[ub], x);
        return isMin ? res : -res;
    }

    T query_monotone_inc(T x) {
        assert(!called_query && !called_query_monotonic_dec);
        assert(!empty());
        if (!called_query_monotonic_inc)
            called_query_monotonic_inc = true;
        else
            assert(prev_query <= x);
        prev_query = x;
        while (lines.size() >= 2 && f(lines.front(), x) >= f(lines[1], x)) lines.pop_front();
        T res = f(lines.front(), x);
        return isMin ? res : -res;
    }

    T query_monotone_dec(T x) {
        assert(!called_query && !called_query_monotonic_inc);
        assert(!empty());
        if (!called_query_monotonic_dec)
            called_query_monotonic_dec = true;
        else
            assert(x <= prev_query);
        prev_query = x;
        while (lines.size() >= 2 && f(lines.back(), x) >= f(lines[lines.size() - 2], x)) lines.pop_back();
        T res = f(lines.back(), x);
        return isMin ? res : -res;
    }

private:
    std::deque<std::pair<T, T>> lines;  // slope decreases as index increases
    bool called_query = false, called_query_monotonic_inc = false, called_query_monotonic_dec = false;
    T prev_query;

    using D = long double;

    // check if b is unnecessary
    inline bool check(const std::pair<T, T>& a, const std::pair<T, T>& b, const std::pair<T, T>& c) {
        // return (b.first - a.first) * (c.second - b.second) >= (c.first - b.first) * (b.second - a.second);
        // note that slopes are distinct and decrease
        return D(c.second - b.second) / (c.first - b.first) >= D(b.second - a.second) / (b.first - a.first);
    }

    inline T f(const std::pair<T, T>& l, T x) { return l.first * x + l.second; }
};

/**
 * @brief Convex Hull Trick (Add-Monotonic Slope Optimization)
 * @docs docs/datastructure/ConvexHullTrick.md
 */