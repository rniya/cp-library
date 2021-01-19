#pragma once
#include "../base.hpp"

/**
 * @brief UnionFind (Undo可能)
 * @docs docs/datastructure/UnionFindUndo.md
 */
struct UnionFindUndo {
    vector<int> dat;
    stack<pair<int, int>> hist;
    UnionFindUndo(int n) : dat(n, -1) {}
    int root(int x) { return (dat[x] < 0 ? x : root(dat[x])); }
    bool merge(int x, int y) {
        x = root(x);
        y = root(y);
        hist.emplace(x, dat[x]);
        hist.emplace(y, dat[y]);
        if (x == y) return false;
        if (dat[x] > dat[y]) swap(x, y);
        dat[x] += dat[y];
        dat[y] = x;
        return true;
    }
    void undo() {
        dat[hist.top().first] = hist.top().second;
        hist.pop();
        dat[hist.top().first] = hist.top().second;
        hist.pop();
    }
    void snapshot() {
        while (!hist.empty()) hist.pop();
    }
    void rollback() {
        while (!hist.empty()) undo();
    }
    bool same(int x, int y) { return root(x) == root(y); }
    int size(int x) { return -dat[root(x)]; }
};