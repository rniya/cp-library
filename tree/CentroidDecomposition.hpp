#pragma once
#include <cassert>
#include <vector>

struct CentroidDecomposition {
    std::vector<std::vector<int>> G;

    CentroidDecomposition(int n) : G(n), n(n), sub(n), is_centroid(n) {}

    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    std::vector<int> build(int x = 0) {
        centroids.clear();
        fill(is_centroid.begin(), is_centroid.end(), false);
        centroid_decomposition(x);
        return centroids;
    }

private:
    int n;
    std::vector<int> sub, centroids;
    std::vector<bool> is_centroid;

    int dfs_sz(int v, int p) {
        sub[v] = 1;
        for (int& u : G[v]) {
            if (u == p || is_centroid[u]) continue;
            sub[v] += dfs_sz(u, v);
        }
        return sub[v];
    }

    int dfs_search_centroid(int v, int p, int mid) {
        for (int& u : G[v]) {
            if (u == p || is_centroid[u]) continue;
            if (sub[u] > mid) return dfs_search_centroid(u, v, mid);
        }
        return v;
    }

    void centroid_decomposition(int r) {
        int centroid = dfs_search_centroid(r, -1, dfs_sz(r, -1) / 2);
        centroids.emplace_back(centroid);
        is_centroid[centroid] = true;
        for (int& ch : G[centroid]) {
            if (is_centroid[ch]) continue;
            centroid_decomposition(ch);
        }
    }
};
