#pragma once
#include "../base.hpp"

template <typename T> struct RectangleSet {
    constexpr T inf = numeric_limits<T>::max() / 2;
    set<pair<T, T>> s;
    multiset<T> val;
    RectangleSet() {
        s.emplace(-1, inf);
        s.emplace(0, 0);
        val.emplace(0);
    }

    void add(T x, T y) {
        auto itr = s.lower_bound(make_pair(x, y));
        bool flag = false;
        T nx = inf, ny = inf;
        while (1) {
            itr = prev(itr);
            if (y < itr->second) break;
            flag = true;
            nx = min(nx, itr->first);
            ny = min(ny, itr->second);
            val.erase(val.find(itr->first + itr->second));
            itr = s.erase(itr);
        }
        if (flag) {
            s.emplace(nx, y);
            val.emplace(nx + y);
            s.emplace(x, ny);
            val.emplace(x + ny);
        }
    }
    T query() { return *val.begin(); }
};
