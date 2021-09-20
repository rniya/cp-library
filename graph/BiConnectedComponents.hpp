#pragma once
#include "LowLink.hpp"

struct BiConnectedComponents : LowLink {
    using LowLink::G;
    using LowLink::low;
    using LowLink::LowLink;
    using LowLink::ord;

    vector<vector<pair<int, int>>> bc;
    vector<pair<int, int>> tmp;
    vector<bool> used;

    vector<vector<pair<int, int>>> build() {
        LowLink::build();
        used.assign(G.size(), false);
        for (size_t i = 0; i < used.size(); i++) {
            if (used[i]) continue;
            dfs(i, -1);
        }
        return bc;
    }

    void dfs(int v, int p) {
        used[v] = true;
        bool flag = false;
        for (int& u : G[v]) {
            if (u == p && !exchange(flag, true)) continue;
            if (!used[u] || ord[u] < ord[v]) tmp.emplace_back(minmax(u, v));
            if (!used[u]) {
                dfs(u, v);
                if (low[u] >= ord[v]) {
                    bc.emplace_back();
                    for (;;) {
                        auto e = tmp.back();
                        bc.back().emplace_back(e);
                        tmp.pop_back();
                        if (e.first == min(u, v) && e.second == max(u, v)) break;
                    }
                }
            }
        }
    }
};
