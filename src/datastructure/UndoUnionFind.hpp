#pragma once
#include <cassert>
#include <stack>
#include <vector>

struct UndoUnionFind {
    UndoUnionFind() {}

    UndoUnionFind(int n) : n(n), data(n, -1) {}

    int find(int x) const {
        assert(0 <= x && x < n);
        return data[x] < 0 ? x : find(data[x]);
    }

    bool merge(int x, int y) {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        x = find(x), y = find(y);
        history.emplace(x, data[x]);
        history.emplace(y, data[y]);
        if (x == y) return false;
        if (-data[x] < -data[y]) std::swap(x, y);
        data[x] += data[y];
        data[y] = x;
        return true;
    }

    bool same(int x, int y) const {
        assert(0 <= x && x < n);
        assert(0 <= y && y < n);
        return find(x) == find(y);
    }

    int size(int x) const {
        assert(0 <= x && x < n);
        return -data[find(x)];
    }

    void undo() {
        assert(!history.empty());
        data[history.top().first] = history.top().second;
        history.pop();
        data[history.top().first] = history.top().second;
        history.pop();
    }

    void snapshot() {
        while (!history.empty()) history.pop();
    }

    void rollback() {
        while (!history.empty()) undo();
    }

    int operator[](int x) const { return find(x); }

  private:
    int n;
    std::vector<int> data;
    std::stack<std::pair<int, int>> history;
};
