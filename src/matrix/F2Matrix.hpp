#pragma once
#include <bitset>
#include <cassert>
#include <utility>
#include <vector>

template <int MAX_W> struct F2Matrix {
    int H, W;

    std::vector<std::bitset<MAX_W>> A;

    F2Matrix(int H, int W) : H(H), W(W), A(H) {
        assert(W <= MAX_W);
        for (int i = 0; i < H; i++) A[i].reset();
    }

    bool empty() const { return A.empty(); }

    int size() const { return H; }

    int height() const { return H; }

    int width() const { return W; }

    inline const std::bitset<MAX_W>& operator[](int i) const { return A[i]; }

    inline std::bitset<MAX_W>& operator[](int i) { return A[i]; }

    static F2Matrix identity(int n) {
        F2Matrix res(n, n);
        for (int i = 0; i < n; i++) res[i][i] = 1;
        return res;
    }

    F2Matrix& operator+=(const F2Matrix& B) {
        assert(H == B.height() and W == B.width());
        for (int i = 0; i < H; i++) (*this)[i] ^= B[i];
        return *this;
    }

    F2Matrix& operator-=(const F2Matrix& B) { return *this += B; }

    F2Matrix& operator*=(const F2Matrix& B) {
        assert(W == B.height());
        F2Matrix C(H, B.width());
        for (int i = 0; i < H; i++) {
            for (int j = 0; j < W; j++) {
                if (A[i][j]) {
                    C[i] ^= B[j];
                }
            }
        }
        std::swap(A, C.A);
        return *this;
    }

    F2Matrix operator+(const F2Matrix& B) const { return F2Matrix(*this) += B; }

    F2Matrix operator-(const F2Matrix& B) const { return F2Matrix(*this) -= B; }

    F2Matrix operator*(const F2Matrix& B) const { return F2Matrix(*this) *= B; }

    F2Matrix pow(long long n) const {
        assert(H == W);
        assert(0 <= n);
        F2Matrix x = *this, r = identity(H);
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }

    int rank() const { return F2Matrix(*this).gauss_jordan(); }

    int det() const {
        assert(H == W);
        return rank() == H ? 1 : 0;
    }

    std::vector<std::bitset<MAX_W>> system_of_linear_equations(const std::vector<bool>& b) {
        assert(W + 1 <= MAX_W);
        assert(int(b.size()) == H);
        F2Matrix B(*this);
        for (int i = 0; i < H; i++) B[i][W] = b[i];
        int rank = B.gauss_jordan(W);
        for (int i = rank; i < H; i++) {
            if (B[i][W]) {
                return {};
            }
        }
        std::vector<std::bitset<MAX_W>> res(1);
        std::vector<int> pivot(W, -1);
        for (int i = 0, j = 0; i < rank; i++) {
            while (not B[i][j]) j++;
            res[0][j] = B[i][W];
            pivot[j] = i;
        }
        for (int j = 0; j < W; j++) {
            if (pivot[j] != -1) continue;
            std::bitset<MAX_W> x(W);
            x[j] = 1;
            for (int k = 0; k < j; k++) {
                if (pivot[k] != -1) {
                    x[k] = B[pivot[k]][j];
                }
            }
            res.emplace_back(x);
        }
        return res;
    }

  private:
    int gauss_jordan(int pivot_end = -1) {
        if (empty()) return 0;
        if (pivot_end == -1) pivot_end = W;
        assert(pivot_end <= MAX_W);
        int rank = 0;
        for (int j = 0; j < pivot_end; j++) {
            int pivot = -1;
            for (int i = rank; i < H; i++) {
                if ((*this)[i][j]) {
                    pivot = i;
                    break;
                }
            }
            if (pivot == -1) continue;
            if (pivot != rank) std::swap((*this)[pivot], (*this)[rank]);
            for (int i = 0; i < H; i++) {
                if (i != rank and (*this)[i][j]) {
                    (*this)[i] ^= (*this)[rank];
                }
            }
            rank++;
        }
        return rank;
    }
};
