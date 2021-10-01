#pragma once
#include "../base.hpp"

/**
 * @brief BitMatrix
 * @docs docs/datastructure/BitMatrix.md
 */
template <size_t MAX_COL> struct BitMatrix {
    int n, m;
    vector<bitset<MAX_COL>> A;
    BitMatrix(int n) : n(n), m(MAX_COL), A(n) {}
    const bitset<MAX_COL>& operator[](int k) const { return A[k]; }
    bitset<MAX_COL>& operator[](int k) { return A[k]; }
    int gauss_jordan(int extended = 0) {
        int rank = 0;
        for (int j = 0; j < m - extended; j++) {
            int pivot = -1;
            for (int i = rank; i < n; i++) {
                if (A[i][j]) {
                    pivot = i;
                    break;
                }
            }
            if (pivot == -1) continue;
            swap(A[pivot], A[rank]);
            for (int i = 0; i < n; i++) {
                if (i != rank && A[i][j]) {
                    A[i] ^= A[rank];
                }
            }
            rank++;
        }
        return rank;
    }
    pair<int, vector<int>> linear_equation(const vector<int>& b) {
        assert(n == (int)b.size());
        for (int i = 0; i < n; i++) A[i][m - 1] = b[i];
        int rank = gauss_jordan(1);
        for (int i = rank; i < n; i++) {
            if (A[i][m - 1]) {
                return {-1, vector<int>{}};
            }
        }
        vector<int> res(m, 0);
        for (int i = 0; i < rank; i++) res[i] = A[i][m - 1];
        return {rank, res};
    }
};
