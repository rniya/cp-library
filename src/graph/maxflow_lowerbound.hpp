#include "atcoder/maxflow"

template <class Cap> struct maxflow_lowerbound {
    maxflow_lowerbound() {}
    maxflow_lowerbound(int n) : n(n), graph(n + 2), in(n, 0) {}

    int add_edge(int from, int to, Cap lower, Cap upper) {
        assert(0 <= from and from < n);
        assert(0 <= to and to < n);
        assert(0 <= lower and lower <= upper);
        in[from] -= lower;
        in[to] += lower;
        lows.emplace_back(lower);
        return graph.add_edge(from, to, upper - lower);
    }

    Cap flow(int s, int t) {
        assert(0 <= s and s < n);
        assert(0 <= t and t < n);
        assert(s != t);
        Cap sum = 0;
        for (int i = 0; i < n; i++) {
            if (in[i] > 0) graph.add_edge(n, i, in[i]), sum += in[i];
            if (in[i] < 0) graph.add_edge(i, n + 1, -in[i]);
        }
        graph.add_edge(t, s, std::numeric_limits<Cap>::max());
        if (graph.flow(n, n + 1) < sum) return -1;
        return graph.flow(s, t);
    }

    typename atcoder::mf_graph<Cap>::edge get_edge(int i) {
        auto res = graph.get_edge(i);
        res.cap += lows[i];
        res.flow += lows[i];
        return res;
    }

    std::vector<typename atcoder::mf_graph<Cap>::edge> edges() {
        std::vector<typename atcoder::mf_graph<Cap>::edge> res;
        for (int i = 0; i < int(lows.size()); i++) res.emplace_back(get_edge(i));
        return res;
    }

  private:
    int n;
    atcoder::mf_graph<Cap> graph;
    std::vector<Cap> in, lows;
};