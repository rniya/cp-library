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

    bool empty() const { return A.empty(); }

    int size() const { return A.size(); }

    int height() const { return A.size(); }

    int width() const {
        assert(not A.empty());
        return A[0].size();
    }

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

    int rank() const { return Matrix(*this).gauss_jordan().first; }

    T det() const { return Matrix(*this).gauss_jordan().second; }

    Matrix inv() const {
        assert(height() == width());
        int n = height();
        Matrix B(*this);
        for (int i = 0; i < n; i++) {
            B[i].resize(2 * n, T(0));
            B[i][n + i] = T(1);
        }
        int rank = B.gauss_jordan(n).first;
        if (rank != n) return {};
        for (int i = 0; i < n; i++) {
            B[i].erase(B[i].begin(), B[i].begin() + n);
        }
        return B;
    }

    std::vector<std::vector<T>> system_of_linear_equations(const std::vector<T>& b) const {
        assert(height() == int(b.size()));
        int n = height(), m = width();
        Matrix B(*this);
        for (int i = 0; i < n; i++) B[i].emplace_back(b[i]);
        int rank = B.gauss_jordan(m).first;
        for (int i = rank; i < n; i++) {
            if (B[i][m] != T(0)) {
                return {};
            }
        }
        std::vector<std::vector<T>> res(1, std::vector<T>(m, 0));
        std::vector<int> pivot(m, -1);
        for (int i = 0, j = 0; i < rank; i++) {
            while (B[i][j] == T(0)) j++;
            res[0][j] = B[i][m];
            pivot[j] = i;
        }
        for (int j = 0; j < m; j++) {
            if (pivot[j] != -1) continue;
            std::vector<T> x(m);
            x[j] = 1;
            for (int k = 0; k < j; k++) {
                if (pivot[k] != -1) {
                    x[k] = -B[pivot[k]][j];
                }
            }
            res.emplace_back(x);
        }
        return res;
    }

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

  private:
    std::pair<int, T> gauss_jordan(int pivot_end = -1) {
        if (empty()) return {0, T(1)};
        if (pivot_end == -1) pivot_end = width();
        int rank = 0;
        T det = 1;
        for (int j = 0; j < pivot_end; j++) {
            int pivot = -1;
            for (int i = rank; i < height(); i++) {
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
                for (int k = j; k < width(); k++) (*this)[rank][k] *= coef;
            }
            for (int i = 0; i < height(); i++) {
                if (i == rank) continue;
                T coef = (*this)[i][j];
                if (coef == T(0)) continue;
                for (int k = j; k < width(); k++) (*this)[i][k] -= (*this)[rank][k] * coef;
            }
            rank++;
        }
        return {rank, det};
    }
};
