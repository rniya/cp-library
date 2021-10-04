#pragma once
#include <cassert>
#include <limits>
#include <vector>

struct PartiallyPersistentUnionFind {
    PartiallyPersistentUnionFind(int n)
        : n(n), time(0), data(n, -1), last(n, std::numeric_limits<int>::max()), history(n) {
        for (auto& v : history) v.emplace_back(-1, -1);
    }

    int find(int t, int x) const {
        assert(0 <= x && x < n);
        return t < last[x] ? x : find(t, data[x]);
    }

    bool merge(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        time++;
        if ((x = find(time, x)) == (y = find(time, y))) return false;
        if (-data[x] < -data[y]) std::swap(x, y);
        data[x] += data[y];
        history[x].emplace_back(time, data[x]);
        data[y] = x;
        last[y] = time;
        return true;
    }

    bool same(int t, int x, int y) const {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        return find(t, x) == find(t, y);
    }

    int size(int t, int x) const {
        assert(0 <= x && x < n);
        x = find(t, x);
        return -prev(lower_bound(history[x].begin(), history[x].end(), std::make_pair(t, 0)))->second;
    }

private:
    int n, time;
    std::vector<int> data, last;
    std::vector<std::vector<std::pair<int, int>>> history;
};

/**
 * @brief Partially Persistent Union Find
 * @docs docs/datastructure/PartiallyPersistentUnionFind.md
 */
