#pragma once
#include "../matrix/Matrix.hpp"

template <typename T> T counting_spanning_trees_directed(std::vector<std::vector<T>> G, int r) {
    int n = G.size();
    assert(0 <= r and r < n);
    if (n <= 1) return T(1);
    for (int i = 0; i < n; i++) {
        G[i][i] = 0;
        for (int j = 0; j < n; j++) {
            if (j != i) {
                G[i][i] += G[i][j];
                G[i][j] = -G[i][j];
            }
        }
    }
    Matrix<T> L(n - 1);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (i != r and j != r) {
                L[i - (i > r)][j - (j > r)] = G[i][j];
            }
        }
    }
    return L.det();
}

template <typename T> T counting_spanning_trees_undirected(std::vector<std::vector<T>> G) {
    return count_spanning_trees_directed(G, 0);
}