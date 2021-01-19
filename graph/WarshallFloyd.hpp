#pragma once
#include "../base.hpp"

/**
 * @brief Warshall Floyd
 * @docs docs/graph/WarshallFloyd.md
 */
template <typename T> void Warshall_Floyd(vector<vector<T>>& d, T id) {
    int n = d.size();
    for (int k = 0; k < n; k++) {
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (d[i][k] == id || d[k][j] == id) continue;
                d[i][j] = min(d[i][j], d[i][k] + d[k][j]);
            }
        }
    }
}