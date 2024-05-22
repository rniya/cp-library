#pragma once
#include <cassert>
#include <iostream>
#include <utility>
#include <vector>

template <typename T> struct Matrix {
    std::vector<std::vector<T>> A;

    Matrix() = default;

    Matrix(int n, int m) : A(n, std::vector<T>(m, 0)) {}

    Matrix(int n) : A(n, std::vector<T>(n, 0)) {}

    int size() const { return A.size(); }

    int height() const { return A.size(); }

    int width() const { return A[0].size(); }

    inline const std::vector<T>& operator[](int k) const { return A[k]; }
    inline std::vector<T>& operator[](int k) { return A[k]; }

    static Matrix identity(int n) {
        Matrix res(n);
        for (int i = 0; i < n; i++) res[i][i] = 1;
        return res;
    }

    Matrix& operator+=(const Matrix& B) {
        int n = height(), m = width();
        assert(n == B.height() and m == B.width());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                (*this)[i][j] += B[i][j];
            }
        }
        return *this;
    }

    Matrix& operator-=(const Matrix& B) {
        int n = height(), m = width();
        assert(n == B.height() and m == B.width());
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                (*this)[i][j] -= B[i][j];
            }
        }
        return *this;
    }

    Matrix& operator*=(const Matrix& B) {
        int n = height(), m = B.width(), p = width();
        assert(p == B.height());
        std::vector<std::vector<T>> C(n, std::vector<T>(m, 0));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < p; k++) {
                for (int j = 0; j < m; j++) {
                    C[i][j] += (*this)[i][k] * B[k][j];
                }
            }
        }
        std::swap(A, C);
        return *this;
    }

    Matrix& operator*=(const T& v) {
        for (int i = 0; i < height(); i++) {
            for (int j = 0; j < width(); j++) {
                (*this)[i][j] *= v;
            }
        }
        return *this;
    }

    Matrix& operator/=(const T& v) {
        T inv = T(1) / v;
        for (int i = 0; i < height(); i++) {
            for (int j = 0; j < width(); j++) {
                (*this)[i][j] *= inv;
            }
        }
        return *this;
    }

    Matrix operator-() const {
        Matrix res(height(), width());
        for (int i = 0; i < height(); i++) {
            for (int j = 0; j < width(); j++) {
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

    bool operator==(const Matrix& B) const {
        assert(height() == B.height() && width() == B.width());
        return A == B.A;
    }

    bool operator!=(const Matrix& B) const {
        assert(height() == B.height() && width() == B.width());
        return A != B.A;
    }

    Matrix pow(long long n) const {
        assert(0 <= n);
        Matrix x = *this, r = identity(size());
        while (n) {
            if (n & 1) r *= x;
            x *= x;
            n >>= 1;
        }
        return r;
    }

    Matrix transpose() const {
        Matrix res(width(), height());
        for (int i = 0; i < height(); i++) {
            for (int j = 0; j < width(); j++) {
                res[j][i] = (*this)[i][j];
            }
        }
        return res;
    }

    T determinant() const {
        assert(height() == width());
        Matrix B(*this);
        T res = 1;
        for (int i = 0; i < height(); i++) {
            int pivot = -1;
            for (int j = i; j < height(); j++) {
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
            for (int j = 0; j < width(); j++) B[i][j] *= inv;
            for (int j = i + 1; j < height(); j++) {
                T a = B[j][i];
                for (int k = 0; k < width(); k++) {
                    B[j][k] -= B[i][k] * a;
                }
            }
        }
        return res;
    }

    std::pair<int, T> gauss_jordan() {}

    int rank() const {}

    T det() const {}

    Matrix inv() const {}

    std::vector<std::vector<T>> system_of_linear_equations(const std::vector<T>& b) const {}

    friend std::ostream& operator<<(std::ostream& os, const Matrix& p) {
        int n = p.height(), m = p.width();
        os << "[(" << n << " * " << m << " Matrix)";
        os << "\n[columun sums: ";
        for (int j = 0; j < m; j++) {
            T sum = 0;
            for (int i = 0; i < n; i++) sum += p[i][j];
            os << sum << (j + 1 < m ? "," : "");
        }
        os << "]";
        for (int i = 0; i < n; i++) {
            os << "\n[";
            for (int j = 0; j < m; j++) os << p[i][j] << (j + 1 < m ? "," : "");
            os << "]";
        }
        os << "]\n";
        return os;
    }
};
