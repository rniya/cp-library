#pragma once
#include <algorithm>
#include <map>
#include <tuple>
#include <utility>
#include "UndoUnionFind.hpp"

struct OfflineDynamicConnectivity {
    OfflineDynamicConnectivity(int n) : n(n) {}

    void add(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        time.emplace(std::minmax(u, v), qs.size());
    }

    void del(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        auto it = time.find(std::minmax(u, v));
        assert(it != time.end());
        es.emplace_back(u, v, it->second, qs.size());
        time.erase(it);
    }

    void query(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        qs.emplace_back(u, v);
    }

    std::vector<bool> solve() {
        int q = qs.size();
        if (q == 0) return {};
        for (auto it = time.begin(); it != time.end(); it = time.erase(it)) {
            const auto& [u, v] = it->first;
            es.emplace_back(u, v, it->second, q);
        }
        std::vector<std::vector<std::pair<int, int>>> seg(2 * q);
        for (auto [u, v, l, r] : es) {
            for (l += q, r += q; l < r; l >>= 1, r >>= 1) {
                if (l & 1) seg[l++].emplace_back(u, v);
                if (r & 1) seg[--r].emplace_back(u, v);
            }
        }
        UndoUnionFind uf(n);
        std::vector<bool> res(q);
        auto dfs = [&](auto self, int k) -> void {
            for (const auto& [u, v] : seg[k]) uf.merge(u, v);
            if (k >= q) {
                const auto& [u, v] = qs[k - q];
                res[k - q] = uf.same(u, v);
            } else {
                self(self, k << 1);
                self(self, k << 1 | 1);
            }
            for (int i = 0; i < int(seg[k].size()); i++) uf.undo();
        };
        dfs(dfs, 1);
        return res;
    }

  private:
    int n;
    std::multimap<std::pair<int, int>, int> time;
    std::vector<std::pair<int, int>> qs;
    std::vector<std::tuple<int, int, int, int>> es;
};
