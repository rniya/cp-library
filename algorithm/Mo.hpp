#pragma once
#include <algorithm>
#include <cassert>
#include <cmath>
#include <numeric>
#include <vector>

struct Mo {
    Mo(int n) : n(n) {}

    void add(int l, int r) {
        assert(l <= r);
        left.emplace_back(l);
        right.emplace_back(r);
    }

    template <typename AL, typename AR, typename DL, typename DR, typename REM>
    void run(const AL& add_left, const AR& add_right, const DL& del_left, const DR del_right, const REM& rem) {
        int q = left.size(), width = n / std::min(std::max<int>(sqrt(q * 2 / 3), 1), n);
        std::vector<int> order(q);
        std::iota(order.begin(), order.end(), 0);
        std::sort(order.begin(), order.end(), [&](int a, int b) {
            int ablock = left[a] / width, bblock = left[b] / width;
            if (ablock != bblock) return ablock < bblock;
            return (ablock & 1) ? (right[a] > right[b]) : (right[a] < right[b]);
        });

        int l = 0, r = 0;
        for (auto idx : order) {
            while (l > left[idx]) add_left(--l);
            while (r < right[idx]) add_right(r++);
            while (l < left[idx]) del_left(l++);
            while (r > right[idx]) del_right(--r);
            rem(idx);
        }
    }

    template <typename A, typename D, typename REM> void run(const A& add, const D& del, const REM& rem) {
        run(add, add, del, del, rem);
    }

private:
    int n;
    std::vector<int> left, right;
};

/**
 * @brief Mo's algorithm
 * @docs docs/other/Mo.md
 */
