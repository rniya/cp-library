#pragma once
#include "../base.hpp"

/**
 * @brief Weighted UnionFind
 * @docs docs/datastructure/WeightedUnionFind.md
 */
template <typename Abel> struct WeightedUnionFind {
    int num;
    vector<int> par, rank;
    vector<Abel> diff_weight;
    WeightedUnionFind(int n, Abel id = 0) : num(n), par(n), rank(n, 1), diff_weight(n, Abel(0)) {
        iota(par.begin(), par.end(), 0);
    }
    int root(int x) {
        if (x == par[x]) return x;
        int t = root(par[x]);
        diff_weight[x] += diff_weight[par[x]];
        return par[x] = t;
    }
    bool merge(int x, int y, Abel w) {
        w += weight(x), w -= weight(y);
        x = root(x), y = root(y);
        if (x == y) return false;
        if (rank[x] < rank[y]) swap(x, y), w = -w;
        par[y] = x;
        rank[x] += rank[y];
        diff_weight[y] = w;
        num--;
        return true;
    }
    Abel weight(int x) {
        root(x);
        return diff_weight[x];
    }
    Abel diff(int x, int y) { return weight(y) - weight(x); }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return rank[root(x)]; }
    int count() { return num; }
};