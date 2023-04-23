#pragma once
#include <numeric>
#include <tuple>
#include "atcoder/dsu"

struct MergeTree : atcoder::dsu {
    MergeTree() {}

    MergeTree(int n) : atcoder::dsu(n), n(n), vid(n) {}

    std::vector<std::pair<int, int>> build(const std::vector<std::tuple<int, int, int>>& qs) {
        int q = qs.size();
        std::vector<int> root(n), idx(q, -1);
        std::iota(root.begin(), root.end(), 0);
        child.resize(q);
        range.resize(n + q);
        for (int i = 0; i < q; i++) {
            auto [type, a, b] = qs[i];
            if (type == 0) {
                if (same(a, b)) continue;
                child[i] = {root[leader(a)], root[leader(b)]};
                root[merge(a, b)] = n + i;
            } else
                idx[i] = root[leader(a)];
        }
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (leader(i) == i) {
                dfs(root[i], cur);
            }
        }
        std::vector<std::pair<int, int>> res(q);
        for (int i = 0; i < q; i++) {
            if (idx[i] != -1) {
                res[i] = range[idx[i]];
            }
        }
        return res;
    }

    int operator[](int v) const { return vid[v]; }

private:
    int n;
    std::vector<int> vid;
    std::vector<std::pair<int, int>> child, range;

    void dfs(int v, int& cur) {
        int l = cur;
        if (v < n)
            vid[v] = cur++;
        else {
            auto [a, b] = child[v - n];
            dfs(a, cur);
            dfs(b, cur);
        }
        int r = cur;
        range[v] = {l, r};
    }
};
