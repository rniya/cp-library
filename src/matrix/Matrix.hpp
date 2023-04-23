#pragma once
#include <cassert>
#include <iostream>
#include <vector>

template <typename T> struct Matrix {
    std::vector<std::vector<T>> A;

    Matrix(size_t n, size_t m) : A(n, std::vector<T>(m, 0)) {}

    Matrix(size_t n) : A(n, std::vector<T>(n, 0)) {}

    size_t size() const { return A.size(); }

    size_t height() const { return A.size(); }

    size_t width() const { return A[0].size(); }

    inline const std::vector<T>& operator[](int k) const { return A[k]; }

    inline std::vector<T>& operator[](int k) { return A[k]; }

    static Matrix I(size_t n) {
        Matrix res(n);
        for (size_t i = 0; i < n; i++) res[i][i] = 1;
        return res;
    }

    Matrix& operator+=(const Matrix& B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                (*this)[i][j] += B[i][j];
            }
        }
        return *this;
    }

    Matrix& operator-=(const Matrix& B) {
        size_t n = height(), m = width();
        assert(n == B.height() && m == B.width());
        for (size_t i = 0; i < n; i++) {
            for (size_t j = 0; j < m; j++) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return *this;
    }

    Matrix& operator*=(const Matrix& B) {
        size_t n = height(), m = B.width(), p = width();
        assert(p == B.height());
        std::vector<std::vector<T>> C(n, std::vector<T>(m, 0));
        for (size_t i = 0; i < n; i++) {
            for (size_t k = 0; k < p; k++) {
                for (size_t j = 0; j < m; j++) {
                    C[i][j] += (*this)[i][k] * B[k][j];
                }
            }
        }
        A.swap(C);
        return *this;
    }

    Matrix& operator*=(const T& v) {
        for (size_t i = 0; i < height(); i++) {
            for (size_t j = 0; j < width(); j++) {
                (*this)[i][j] *= v;
            }
        }
        return *this;
    }

    Matrix& operator/=(const T& v) {
        T inv = T(1) / v;
        for (size_t i = 0; i < height(); i++) {
            for (size_t j = 0; j < width(); j++) {
                (*this)[i][j] *= inv;
            }
        }
        return *this;
    }

    Matrix& operator^=(long long k) {
        assert(0 <= k);
        Matrix B = Matrix::I(size());
        while (k > 0) {
            if (k & 1) B *= *this;
            *this *= *this;
            k >>= 1;
        }
        A.swap(B.A);
        return *this;
    }

    Matrix operator-() const {
        Matrix res(height(), width());
        for (size_t i = 0; i < height(); i++) {
            for (size_t j = 0; j < width(); j++) {
                res[i][j] = -(*this)[i][j];
            }
        }
        return res;
    }

    Matrix operator+(const Matrix& B) const { return Matrix(*this) += B; }

    Matrix operator-(const Matrix& B) const { return Matrix(*this) -= B; }

    Matrix operator*(const Matrix& B) const { return Matrix(*this) *= B; }

    Matrix operator*(const T& v) const { return Matrix(*this) *= v; }

    Matrix operator/(const T& v) const { return Matrix(*this) /= v; }

    Matrix operator^(const long long k) const { return Matrix(*this) ^= k; }

    bool operator==(const Matrix& B) const {
        assert(height() == B.height() && width() == B.width());
        return A == B.A;
    }

    bool operator!=(const Matrix& B) const {
        assert(height() == B.height() && width() == B.width());
        return A != B.A;
    }

    Matrix transpose() const {
        Matrix res(width(), height());
        for (size_t i = 0; i < height(); i++) {
            for (size_t j = 0; j < width(); j++) {
                res[j][i] = (*this)[i][j];
            }
        }
        return res;
    }

    T determinant() const {
        assert(height() == width());
        Matrix B(*this);
        T res = 1;
        for (size_t i = 0; i < height(); i++) {
            int pivot = -1;
            for (size_t j = i; j < height(); j++) {
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
            for (size_t j = 0; j < width(); j++) B[i][j] *= inv;
            for (size_t j = i + 1; j < height(); j++) {
                T a = B[j][i];
                for (size_t k = 0; k < width(); k++) {
                    B[j][k] -= B[i][k] * a;
                }
            }
        }
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& p) {
        size_t n = p.height(), m = p.width();
        os << "[(" << n << " * " << m << " Matrix)";
        os << "\n[columun sums: ";
        for (size_t j = 0; j < m; j++) {
            T sum = 0;
            for (size_t i = 0; i < n; i++) sum += p[i][j];
            os << sum << (j + 1 < m ? "," : "");
        }
        os << "]";
        for (size_t i = 0; i < n; i++) {
            os << "\n[";
            for (size_t j = 0; j < m; j++) os << p[i][j] << (j + 1 < m ? "," : "");
            os << "]";
        }
        os << "]\n";
        return os;
    }
};
