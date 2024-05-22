#pragma once
#include <array>
#include <cassert>
#include <utility>

template <typename T, int N> struct SquareMatrix {
    std::array<std::array<T, N>, N> A;

    SquareMatrix() : A() {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                A[i][j] = T();
            }
        }
    }

    int size() const { return N; }

    inline const std::array<T, N>& operator[](int k) const { return A[k]; }

    inline std::array<T, N>& operator[](int k) { return A[k]; }

    static SquareMatrix identity() {
        SquareMatrix res;
        for (int i = 0; i < N; i++) res[i][i] = 1;
        return res;
    }

    SquareMatrix& operator+=(const SquareMatrix& B) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                (*this)[i][j] += B[i][j];
            }
        }
        return *this;
    }

    SquareMatrix& operator-=(const SquareMatrix& B) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return *this;
    }

    SquareMatrix& operator*=(const SquareMatrix& B) {
        std::array<std::array<T, N>, N> C;
        for (int i = 0; i < N; i++) {
            for (int k = 0; k < N; k++) {
                for (int j = 0; j < N; j++) {
                    C[i][j] += (*this)[i][k] * B[k][j];
                }
            }
        }
        std::swap(A, C);
        return *this;
    }

    SquareMatrix& operator*=(const T& v) {
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                (*this)[i][j] *= v;
            }
        }
        return *this;
    }

    SquareMatrix& operator/=(const T& v) {
        T inv = T(1) / v;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                (*this)[i][j] *= inv;
            }
        }
        return *this;
    }

    SquareMatrix operator-() const {
        SquareMatrix res;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res[i][j] = -(*this)[i][j];
            }
        }
        return res;
    }

    SquareMatrix operator+(const SquareMatrix& B) const { return SquareMatrix(*this) += B; }

    SquareMatrix operator-(const SquareMatrix& B) const { return SquareMatrix(*this) -= B; }

    SquareMatrix operator*(const SquareMatrix& B) const { return SquareMatrix(*this) *= B; }

    SquareMatrix operator*(const T& v) const { return SquareMatrix(*this) *= v; }

    SquareMatrix operator/(const T& v) const { return SquareMatrix(*this) /= v; }

    bool operator==(const SquareMatrix& B) const { return A == B.A; }

    bool operator!=(const SquareMatrix& B) const { return A != B.A; }

    SquareMatrix pow(long long n) const {
        assert(0 <= n);
        SquareMatrix x = *this, r = identity();
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }

    SquareMatrix transpose() const {
        SquareMatrix res;
        for (int i = 0; i < N; i++) {
            for (int j = 0; j < N; j++) {
                res[j][i] = (*this)[i][j];
            }
        }
        return res;
    }

    int rank() const { return Matrix(*this).gauss_jordan().first; }

    T det() const { return Matrix(*this).gauss_jordan().second; }

    SquareMatrix inv() const {
        SquareMatrix B(*this), C = identity();
        for (int j = 0; j < N; j++) {
            int pivot = -1;
            for (int i = j; i < N; i++) {
                if (B[i][j] != T(0)) {
                    pivot = i;
                    break;
                }
            }
            assert(pivot != -1);
            if (pivot != j) {
                std::swap(B[pivot], B[j]);
                std::swap(C[pivot], C[j]);
            }
            {
                T coef = T(1) / B[j][j];
                for (int k = 0; k < N; k++) {
                    B[j][k] *= coef;
                    C[j][k] *= coef;
                }
            }
            for (int i = 0; i < N; i++) {
                if (i == j) continue;
                T coef = B[i][j];
                if (coef == T(0)) continue;
                for (int k = 0; k < N; k++) {
                    B[i][k] -= B[j][k] * coef;
                    C[i][k] -= C[j][k] * coef;
                }
            }
        }
        return C;
    }

    friend std::ostream& operator<<(std::ostream& os, const SquareMatrix& p) {
        os << "[(" << N << " * " << N << " Matrix)";
        os << "\n[columun sums: ";
        for (int j = 0; j < N; j++) {
            T sum = 0;
            for (int i = 0; i < N; i++) sum += p[i][j];
            ;
            os << sum << (j + 1 < N ? "," : "");
        }
        os << "]";
        for (int i = 0; i < N; i++) {
            os << "\n[";
            for (int j = 0; j < N; j++) os << p[i][j] << (j + 1 < N ? "," : "");
            os << "]";
        }
        os << "]\n";
        return os;
    }

  private:
    std::pair<int, T> gauss_jordan() {
        int rank = 0;
        T det = 1;
        for (int j = 0; j < N; j++) {
            int pivot = -1;
            for (int i = rank; i < N; i++) {
                if ((*this)[i][j] != T(0)) {
                    pivot = i;
                    break;
                }
            }
            if (pivot == -1) {
                det = 0;
                continue;
            }
            if (pivot != rank) {
                det = -det;
                std::swap((*this)[pivot], (*this)[rank]);
            }
            det *= A[rank][j];
            if (A[rank][j] != T(1)) {
                T coef = T(1) / (*this)[rank][j];
                for (int k = j; k < N; k++) (*this)[rank][k] *= coef;
            }
            for (int i = 0; i < N; i++) {
                if (i == rank) continue;
                T coef = (*this)[i][j];
                if (coef == T(0)) continue;
                for (int k = j; k < N; k++) (*this)[i][k] -= (*this)[rank][k] * coef;
            }
            rank++;
        }
        return {rank, det};
    }
};