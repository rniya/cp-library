#pragma once
#include "BinaryOptimization.hpp"

template <typename T, bool MINIMIZE = true> struct KaryOptimization {
    KaryOptimization() = default;

    KaryOptimization(const std::vector<int>& ks) : n(ks.size()), ks(ks), idx(ks.size()) {
        int cur = 0;
        for (int i = 0; i < n; i++) {
            assert(ks[i] > 0);
            idx[i].resize(ks[i]);
            idx[i][0] = -1;
            for (int d = 1; d < ks[i]; d++) idx[i][d] = cur++;
        }
        bopt = BinaryOptimization<T, MINIMIZE>(cur);
        for (int i = 0; i < n; i++) {
            for (int d = 1; d + 1 < ks[i]; d++) {
                bopt.add_10(idx[i][d], idx[i][d + 1], MINIMIZE ? inf : -inf);
            }
        }
    }

    void add(int i, const std::vector<T>& theta) {
        assert(0 <= i and i < n);
        assert(theta.size() == ks[i]);
        bopt.add(theta.back());
        for (int d = 1; d < ks[i]; d++) bopt.add(idx[i][d], {0, theta[d - 1] - theta[d]});
    }

    void add(int i, int j, std::vector<std::vector<T>> phi) {
        assert(0 <= i and i < n);
        assert(0 <= j and j < n);
        assert(phi.size() == ks[i]);
        std::vector<T> theta_i(ks[i]), theta_j(ks[j]);
        for (int d = 0; d < ks[i]; d++) {
            assert(phi[d].size() == ks[j]);
            theta_i[d] = phi[d][0];
            for (int e = 0; e < ks[j]; e++) phi[d][e] -= theta_i[d];
        }
        for (int e = 0; e < ks[j]; e++) {
            theta_j[e] = phi[0][e];
            for (int d = 0; d < ks[i]; d++) phi[d][e] -= theta_j[e];
        }
        add(i, theta_i);
        add(j, theta_j);
        for (int d = 1; d < ks[i]; d++) {
            for (int e = 1; e < ks[j]; e++) {
                T x = (phi[d][e] + phi[d - 1][e - 1]) - (phi[d][e - 1] + phi[d - 1][e]);
                assert(x <= 0);
                bopt.add(idx[i][d], idx[j][e], {x, 0, 0, 0});
            }
        }
    }

    std::pair<T, std::vector<int>> solve() {
        auto [ans, xs] = bopt.solve();
        std::vector<int> x(n, 0);
        for (int i = 0; i < n; i++) {
            for (int d = 1; d < ks[i]; d++) {
                x[i] += not xs[idx[i][d]];
            }
        }
        return {ans, x};
    }

  private:
    static constexpr T inf = std::numeric_limits<T>::max() / 2;
    int n;
    std::vector<int> ks;
    std::vector<std::vector<int>> idx;
    BinaryOptimization<T, MINIMIZE> bopt;
};
