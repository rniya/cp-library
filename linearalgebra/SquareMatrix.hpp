#pragma once
#include <array>
#include <cassert>
#include <iostream>

template <typename T, size_t N> struct SquareMatrix {
    std::array<std::array<T, N>, N> A;

    SquareMatrix() : A{{}} {}

    size_t size() const { return N; }

    inline const std::array<T, N>& operator[](int k) const { return A[k]; }

    inline std::array<T, N>& operator[](int k) { return A[k]; }

    static SquareMatrix I() {
        SquareMatrix res;
        for (size_t i = 0; i < N; i++) res[i][i] = 1;
        return res;
    }

    SquareMatrix& operator+=(const SquareMatrix& B) {
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                (*this)[i][j] += B[i][j];
            }
        }
        return *this;
    }

    SquareMatrix& operator-=(const SquareMatrix& B) {
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return *this;
    }

    SquareMatrix& operator*=(const SquareMatrix& B) {
        std::array<std::array<T, N>, N> C;
        for (size_t i = 0; i < N; i++) {
            for (size_t k = 0; k < N; k++) {
                for (size_t j = 0; j < N; j++) {
                    C[i][j] += (*this)[i][k] * B[k][j];
                }
            }
        }
        A.swap(C);
        return *this;
    }

    SquareMatrix& operator*=(const T& v) {
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                (*this)[i][j] *= v;
            }
        }
        return *this;
    }

    SquareMatrix& operator/=(const T& v) {
        T inv = T(1) / v;
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                (*this)[i][j] *= inv;
            }
        }
        return *this;
    }

    SquareMatrix& operator^=(long long k) {
        assert(0 <= k);
        SquareMatrix B = SquareMatrix::I();
        while (k > 0) {
            if (k & 1) B *= *this;
            *this *= *this;
            k >>= 1;
        }
        A.swap(B.A);
        return *this;
    }

    SquareMatrix operator-() const {
        SquareMatrix res;
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
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

    SquareMatrix operator^(const long long k) const { return SquareMatrix(*this) ^= k; }

    bool operator==(const SquareMatrix& B) const { return A == B.A; }

    bool operator!=(const SquareMatrix& B) const { return A != B.A; }

    SquareMatrix transpose() const {
        SquareMatrix res;
        for (size_t i = 0; i < N; i++) {
            for (size_t j = 0; j < N; j++) {
                res[j][i] = (*this)[i][j];
            }
        }
        return res;
    }

    T determinant(size_t n = N) const {
        SquareMatrix B(*this);
        T res = 1;
        for (size_t i = 0; i < n; i++) {
            int pivot = -1;
            for (size_t j = i; j < n; j++) {
                if (B[j][i] != 0) {
                    pivot = j;
                    break;
                }
            }
            if (pivot == -1) return 0;
            if (pivot != (int)i) {
                res *= -1;
                std::swap(B[i], B[pivot]);
            }
            res *= B[i][i];
            T inv = T(1) / B[i][i];
            for (size_t j = 0; j < n; j++) B[i][j] *= inv;
            for (size_t j = i + 1; j < n; j++) {
                T a = B[j][i];
                for (size_t k = 0; k < n; k++) {
                    B[j][k] -= B[i][k] * a;
                }
            }
        }
    }

    friend std::ostream& operator<<(std::ostream& os, const SquareMatrix& p) {
        os << "[(" << N << " * " << N << " Matrix)";
        os << "\n[columun sums: ";
        for (size_t j = 0; j < N; j++) {
            T sum = 0;
            for (size_t i = 0; i < N; i++) sum += p[i][j];
            ;
            os << sum << (j + 1 < N ? "," : "");
        }
        os << "]";
        for (size_t i = 0; i < N; i++) {
            os << "\n[";
            for (size_t j = 0; j < N; j++) os << p[i][j] << (j + 1 < N ? "," : "");
            os << "]";
        }
        os << "]\n";
        return os;
    }
};

/**
 * @brief 正方行列ライブラリ
 * @docs docs/linearalgebra/SquareMatrix.md
 */
