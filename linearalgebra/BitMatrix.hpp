#pragma once
#include <bitset>
#include <cassert>
#include <vector>

template <size_t MAX_COL> struct BitMatrix {
    size_t n, m;
    std::vector<std::bitset<MAX_COL>> A;

    BitMatrix(size_t n, size_t m) : n(n), m(m), A(n) { assert(m <= MAX_COL); }

    size_t size() const { return n; };

    size_t height() const { return n; }

    size_t width() const { return m; }

    inline const std::bitset<MAX_COL>& operator[](int k) const { return A[k]; }

    inline std::bitset<MAX_COL>& operator[](int k) { return A[k]; }

    static BitMatrix I(size_t n) {
        BitMatrix res(n, n);
        for (size_t i = 0; i < n; i++) res[i][i] = true;
        return res;
    }

    BitMatrix& operator*=(const BitMatrix& B) {
        assert(m == B.height());
        BitMatrix C(n, B.width());
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                if (A[i][j]) {
                    C[i] |= B[j];
                }
            }
        }
        std::swap(A, C.A);
        return *this;
    }

    BitMatrix& operator^=(long long k) {
        assert(0 <= k);
        BitMatrix B = BitMatrix::I(n);
        while (k > 0) {
            if (k & 1) B *= *this;
            *this *= *this;
            k >>= 1;
        }
        std::swap(A, B.A);
        return *this;
    }

    BitMatrix operator*(const BitMatrix& B) const { return BitMatrix(*this) *= B; }

    BitMatrix operator^(const long long k) const { return BitMatrix(*this) ^= k; }

    size_t gauss_jordan() {
        size_t rank = 0;
        for (size_t j = 0; j < m; j++) {
            int pivot = -1;
            for (size_t i = rank; i < n; i++) {
                if (A[i][j]) {
                    pivot = i;
                    break;
                }
            }
            if (pivot == -1) continue;
            std::swap(A[pivot], A[rank]);
            for (size_t i = 0; i < n; i++) {
                if (i != rank and A[i][j]) {
                    A[i] ^= A[rank];
                }
            }
            rank++;
        }
        return rank;
    }

    std::pair<int, std::bitset<MAX_COL>> system_of_linear_equations(const std::vector<bool>& b) {
        assert(m + 1 <= MAX_COL);
        BitMatrix B(*this);
        for (size_t i = 0; i < n; i++) B[i][m] = b[i];
        size_t rank = B.gauss_jordan();
        for (size_t i = rank; i < n; i++) {
            if (B[i][m]) {
                return {-1, std::bitset<MAX_COL>()};
            }
        }
        std::bitset<MAX_COL> res;
        for (size_t i = 0; i < rank; i++) res[i] = A[i][m];
        return {rank, res};
    }
};

/**
 * @brief Bit Matrix
 * @docs docs/linearalgebra/BitMatrix.md
 */
