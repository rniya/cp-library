#include <iostream>
#include "RandomNumberGenerator.hpp"

template <typename T> struct Edge {
    int u, v;
    T w;
    Edge(int u, int v, T w = 1) : u(u), v(v), w(w) {}
};

template <typename T> struct Graph {
    int n, m;
    std::vector<Edge<T>> es;
    bool weighted;

    Graph(int n, bool weighted = false) : n(n), m(0), weighted(weighted) {}

    void print_as_tree(std::ostream& os, bool origin_zero = false) const {
        os << n << "\n";
        print_edges(os, origin_zero);
    }

    void print(std::ostream& os, bool origin_zero = false) const {
        os << n << " " << m << "\n";
        print_edges(os, origin_zero);
    }

    friend std::ostream& operator<<(std::ostream& os, const Graph& g) {
        g.print_as_tree(os);
        return os;
    }

    void add_edge(int u, int v, T w = 1) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        es.emplace_back(u, v, w);
        m++;
    }

  private:
    void print_edges(std::ostream& os, bool origin_zero = false) const {
        for (const auto& e : es) {
            os << e.u + (origin_zero ? 0 : 1) << " " << e.v + (origin_zero ? 0 : 1);
            if (weighted) {
                os << " " << e.w;
            }
            os << "\n";
        }
    }
};

template <typename T> struct RandomUndirectedGraphGenerator {
    Graph<T> tree(int n, bool weighted = false, T _w_min = 1, T _w_max = 1) {
        set_weight(weighted, _w_min, _w_max);
        Graph<T> G(n, weighted);
        if (n == 2) {
            add_edge(G, 0, 1);
        }
        if (n <= 2) {
            return G;
        }
        std::vector<int> prufer(n - 2), deg(n, 1);
        for (auto& y : prufer) {
            y = rng(n);
            deg[y]++;
        }
        std::set<int> leaves;
        for (int i = 0; i < n; i++) {
            if (deg[i] == 1) {
                leaves.emplace(i);
            }
        }
        for (auto& y : prufer) {
            int x = *leaves.begin();
            add_edge(G, x, y);
            leaves.erase(leaves.begin());
            if (--deg[y] == 1) {
                leaves.emplace(y);
            }
        }
        int u = *leaves.begin(), v = *next(leaves.begin());
        add_edge(G, u, v);
        return G;
    }

    Graph<T> path(int n, bool weighted = false, T _w_min = 1, T _w_max = 1) {
        set_weight(weighted, _w_min, _w_max);
        Graph<T> G(n, weighted);
        std::vector<int> ord(n);
        std::iota(ord.begin(), ord.end(), 0);
        rng.shuffle(ord);
        for (int i = 0; i < n - 1; i++) {
            add_edge(G, ord[i], ord[i + 1]);
        }
        return G;
    }

    Graph<T> star(int n, bool weighted = false, T _w_min = 1, T _w_max = 1) {
        set_weight(weighted, _w_min, _w_max);
        Graph<T> G(n, weighted);
        int center = rng(n);
        for (int i = 0; i < n; i++) {
            if (i != center) {
                add_edge(G, center, i);
            }
        }
        return G;
    }

    Graph<T> perfect(int n, bool weighted = false, T _w_min = 1, T _w_max = 1) {
        set_weight(weighted, _w_min, _w_max);
        Graph<T> G(n, weighted);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                add_edge(G, i, j);
            }
        }
        return G;
    }

    Graph<T> simple(int n, bool weighted = false, T _w_min = 1, T _w_max = 1) {
        set_weight(weighted, _w_min, _w_max);
        Graph<T> G(n, weighted);
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (rng(2)) {
                    add_edge(G, i, j);
                }
            }
        }
        return G;
    }

  private:
    T w_min, w_max;
    RandomNumberGenerator64 rng;

    void set_weight(bool weighted, T _w_min, T _w_max) {
        assert(0 <= _w_min and _w_min <= _w_max);
        if (weighted) {
            w_min = _w_min;
            w_max = _w_max;
        } else {
            w_min = w_max = 1;
        }
    }

    void add_edge(Graph<T>& G, int u, int v) {
        T w = (w_min == w_max ? w_min : rng(w_min, w_max + 1));
        G.add_edge(u, v, w);
    }
};