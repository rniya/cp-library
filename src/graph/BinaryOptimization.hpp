#pragma once
#include <array>
#include <tuple>
#include "atcoder/maxflow"

template <typename T, bool MINIMIZE = true> struct BinaryOptimization {
    BinaryOptimization() = default;

    explicit BinaryOptimization(int n) : n(n) {}

    void add(T x) {
        if (not MINIMIZE) x = -x;
        _add(x);
    }

    void add(int i, std::array<T, 2> x) {
        assert(0 <= i and i < n);
        if (not MINIMIZE) {
            for (int i = 0; i < 2; i++) {
                x[i] = -x[i];
            }
        }
        _add(i, x);
    }

    void add_01(int i, int j, T x) {
        assert(0 <= i and i < n);
        assert(0 <= j and j < n);
        if (not MINIMIZE) x = -x;
        assert(x >= 0);
        add_edge(i, j, x);
    }

    void add_10(int i, int j, T x) { add_01(j, i, x); }

    void add(int i, int j, std::array<std::array<T, 2>, 2> x) {
        assert(0 <= i and i < n);
        assert(0 <= j and j < n);
        if (not MINIMIZE) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    x[i][j] = -x[i][j];
                }
            }
        }
        assert(x[0][1] + x[1][0] >= x[0][0] + x[1][1]);
        _add(i, j, x);
    }

    void add(int i, int j, int k, std::array<std::array<std::array<T, 2>, 2>, 2> x) {
        assert(0 <= i and i < n);
        assert(0 <= j and j < n);
        assert(0 <= k and k < n);
        if (not MINIMIZE) {
            for (int i = 0; i < 2; i++) {
                for (int j = 0; j < 2; j++) {
                    for (int k = 0; k < 2; k++) {
                        x[i][j][k] = -x[i][j][k];
                    }
                }
            }
        }
        _add(i, j, k, x);
    }

    void add_all_0(const std::vector<int>& is, T x) {
        if (not MINIMIZE) x = -x;
        assert(x <= 0);
        if (is.size() == 0)
            _add(x);
        else if (is.size() == 1)
            _add(is[0], {x, 0});
        else if (is.size() == 2)
            _add(is[0], is[1], {x, 0, 0, 0});
        else {
            _add(x);
            int nxt = n + aux++;
            add_edge(source, nxt, -x);
            for (const int& i : is) {
                assert(0 <= i and i < n);
                add_edge(nxt, i, -x);
            }
        }
    }

    void add_all_1(const std::vector<int>& is, T x) {
        if (not MINIMIZE) x = -x;
        assert(x <= 0);
        if (is.size() == 0)
            _add(x);
        else if (is.size() == 1)
            _add(is[0], {0, x});
        else if (is.size() == 2)
            _add(is[0], is[1], {0, 0, 0, x});
        else {
            _add(x);
            int nxt = n + aux++;
            add_edge(nxt, sink, -x);
            for (const int& i : is) {
                assert(0 <= i and i < n);
                add_edge(i, nxt, -x);
            }
        }
    }

    std::pair<T, std::vector<bool>> solve() {
        atcoder::mf_graph<T> g(n + aux + 2);
        int s = n + aux, t = s + 1;
        for (auto [u, v, w] : es) {
            u = (u == source ? s : u == sink ? t : u);
            v = (v == source ? s : v == sink ? t : v);
            g.add_edge(u, v, w);
        }
        T sum = base + g.flow(s, t);
        auto cut = g.min_cut(s);
        cut.resize(n);
        for (int i = 0; i < n; i++) cut[i] = not cut[i];
        if (not MINIMIZE) sum = -sum;
        return {sum, cut};
    }

  private:
    int n, aux = 0, source = -1, sink = -2;
    T base = 0;
    std::vector<std::tuple<int, int, T>> es;

    void add_edge(int i, int j, T x) {
        assert(i == source or i == sink or (0 <= i and i < n + aux));
        assert(j == source or j == sink or (0 <= j and j < n + aux));
        if (x == 0) return;
        assert(x > 0);
        es.emplace_back(i, j, x);
    }

    void _add(T x) { base += x; }

    void _add(int i, const std::array<T, 2>& x) {
        if (x[0] <= x[1]) {
            _add(x[0]);
            add_edge(source, i, x[1] - x[0]);
        } else {
            _add(x[1]);
            add_edge(i, sink, x[0] - x[1]);
        }
    }

    void _add(int i, int j, const std::array<std::array<T, 2>, 2>& x) {
        _add(i, {x[0][0], x[1][0]});
        _add(j, {0, x[1][1] - x[1][0]});
        add_edge(i, j, (x[0][1] + x[1][0]) - (x[0][0] + x[1][1]));
    }

    void _add(int i, int j, int k, const std::array<std::array<std::array<T, 2>, 2>, 2>& x) {
        T P = x[0][0][0] - (x[1][0][0] + x[0][1][0] + x[0][0][1]) + (x[1][1][0] + x[0][1][1] + x[1][0][1]) - x[1][1][1];
        if (P >= 0) {
            _add(x[0][0][0]);
            _add(i, {0, x[1][0][0] - x[0][0][0]});
            _add(j, {0, x[0][1][0] - x[0][0][0]});
            _add(k, {0, x[0][0][1] - x[0][0][0]});
            _add(i, j, {0, 0, 0, (x[0][0][0] + x[1][1][0]) - (x[1][0][0] + x[0][1][0])});
            _add(j, k, {0, 0, 0, (x[0][0][0] + x[0][1][1]) - (x[0][1][0] + x[0][0][1])});
            _add(k, i, {0, 0, 0, (x[0][0][0] + x[1][0][1]) - (x[0][0][1] + x[1][0][0])});
            _add(-P);
            int nxt = n + aux++;
            add_edge(i, nxt, P);
            add_edge(j, nxt, P);
            add_edge(k, nxt, P);
            add_edge(nxt, sink, P);
        } else {
            _add(x[1][1][1]);
            _add(i, {x[0][1][1] - x[1][1][1], 0});
            _add(j, {x[1][0][1] - x[1][1][1], 0});
            _add(k, {x[1][1][0] - x[1][1][1], 0});
            _add(i, j, {(x[1][1][1] + x[0][0][1]) - (x[0][1][1] + x[1][0][1]), 0, 0, 0});
            _add(j, k, {(x[1][1][1] + x[1][0][0]) - (x[1][0][1] + x[1][1][0]), 0, 0, 0});
            _add(k, i, {(x[1][1][1] + x[0][1][0]) - (x[1][1][0] + x[0][1][1]), 0, 0, 0});
            P = -P;
            _add(-P);
            int nxt = n + aux++;
            add_edge(nxt, i, P);
            add_edge(nxt, j, P);
            add_edge(nxt, k, P);
            add_edge(source, nxt, P);
        }
    }
};