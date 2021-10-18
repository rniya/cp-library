#pragma once
#include <limits>
#include "Dinic.hpp"

template <typename T> struct ProjectSelectionProblem {
    ProjectSelectionProblem(int n) : n(n), s(n), t(n + 1), dinic(n + 2) {}

    void x_false_loss(int x, T z) {
        assert(0 <= x and x < n);
        dinic.add_edge(x, t, z);
    }

    void x_false_profit(int x, T z) {
        assert(0 <= x and x < n);
        sum += z;
        x_true_loss(x, z);
    }

    void x_true_loss(int x, T z) {
        assert(0 <= x and x < n);
        dinic.add_edge(s, x, z);
    }

    void x_true_profit(int x, T z) {
        assert(0 <= x and x < n);
        sum += z;
        x_false_loss(x, z);
    }

    void x_false_y_true_loss(int x, int y, T z) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        dinic.add_edge(x, y, z);
    }

    void x_true_y_false_loss(int x, int y, T z) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        dinic.add_edge(y, x, z);
        int w = dinic.add_vertex();
        x_false_loss(w, z);
        x_true_y_false_loss(w, x, inf);
        x_true_y_false_loss(w, y, inf);
    }

    void x_false_y_false_profit(int x, int y, T z) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        sum += z;
        int w = dinic.add_vertex();
        x_true_loss(w, z);
        x_false_y_true_loss(w, x, inf);
        x_false_y_true_loss(w, y, inf);
    }

    void x_true_y_true_profit(int x, int y, T z) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
    }

    T solve() {}

private:
    int n, s, t;
    T sum;
    const T inf = std::numeric_limits<T>::max() / 2;
    Dinic<T, true> dinic;
};

/**
 * @brief Project Selection Problem
 * @docs docs/flow/ProjectSelectionPorblem.md
 */
