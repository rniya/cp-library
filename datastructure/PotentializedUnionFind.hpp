#pragma once
#include <cassert>
#include <vector>

template <typename T> struct PotentializedUnionFind {
    PotentializedUnionFind(int n) : n(n), data(n, -1), dist(n, T()) {}

    int find(int x) {
        assert(0 <= x && x < n);
        if (data[x] < 0) return x;
        int r = find(data[x]);
        dist[x] += dist[data[x]];
        return data[x] = r;
    }

    bool merge(int x, int y, T p) {
        p += potential(x) - potential(y);
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        if ((x = find(x)) == (y = find(y))) return false;
        if (-data[x] < -data[y]) {
            std::swap(x, y);
            p = -p;
        }
        data[x] += data[y];
        data[y] = x;
        dist[y] = p;
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

    T potential(int x) {
        assert(0 <= x && x < n);
        find(x);
        return dist[x];
    }

    T diff(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        return potential(y) - potential(x);
    }

    int operator[](int x) { return find(x); }

private:
    int n;
    std::vector<int> data;
    std::vector<T> dist;
};

/**
 * @brief Potentialized Union Find
 * @docs docs/datastructure/PotentializedUnionFind.md
 */
