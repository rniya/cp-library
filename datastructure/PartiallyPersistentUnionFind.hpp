#pragma once
#include "../base.hpp"

/**
 * @brief Partially Persistent UnionFind
 * @docs docs/datastructure/PartiallyPersistentUnionFind.md
 */
struct PartiallyPersistentUnionFind {
    const int inf = numeric_limits<int>::max() / 2;
    int now, num;
    vector<int> par, time;
    vector<vector<pair<int, int>>> Size;
    PartiallyPersistentUnionFind(int n) : now(0), num(n), par(n, -1), Size(n), time(n, inf) {
        for (int i = 0; i < n; i++) Size[i].emplace_back(0, -1);
    }
    int root(int t, int x) {
        if (t < time[x]) return x;
        return root(t, par[x]);
    }
    int merge(int x, int y) {
        now++;
        x = root(now, x), y = root(now, y);
        if (x == y) return 0;
        if (par[x] > par[y]) swap(x, y);
        par[x] += par[y];
        par[y] = x;
        time[y] = now;
        Size[x].emplace_back(now, par[x]);
        num--;
        return now;
    }
    bool same(int t, int x, int y) { return root(t, x) == root(t, y); }
    int size(int t, int x) {
        x = root(t, x);
        return -prev(lower_bound(Size[x].begin(), Size[x].end(), make_pair(t, 0)))->second;
    }
    int count() { return num; }
};