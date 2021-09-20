#pragma once
#include <algorithm>
#include <cassert>
#include <vector>

struct UnionFind {
    UnionFind(int n) : n(n), num(n), data(n, -1) {}
    int find(int x) {
        assert(0 <= x && x < n);
        return data[x] < 0 ? x : data[x] = find(data[x]);
    }
    bool merge(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        if ((x = find(x)) == (y = find(y))) return false;
        if (-data[x] < -data[y]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        num--;
        return true;
    }
    bool same(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        return find(x) == find(y);
    }
    int size(int x) {
        assert(0 <= x && x < n);
        return -data[find(x)];
    }
    int count() const { return num; }
    std::vector<std::vector<int>> groups() {
        std::vector<std::vector<int>> res(n);
        for (int i = 0; i < n; i++) res[find(i)].emplace_back(i);
        res.erase(std::remove_if(res.begin(), res.end(), [&](const std::vector<int>& v) { return v.empty(); }));
        return res;
    }
    int operator[](int x) { return find(x); }

private:
    int n, num;
    // root node : -1 * component size
    // otherwise : parent
    std::vector<int> data;
};

/**
 * @brief Union Find (Disjoint Set Union)
 * @docs docs/datastructure/UnionFind.md
 */