#pragma once
#include <algorithm>
#include <cassert>
#include <utility>
#include <vector>
#include "atcoder/mincostflow"

template <class Cap, class Cost> struct min_cost_b_flow {
    min_cost_b_flow() {}
    explicit min_cost_b_flow(int n) : n(n), graph(n + 2), b(n), sum(Cost{}) {}

    int add_edge(int from, int to, Cap lower, Cap upper, Cost cost) {
        assert(0 <= from and from < n);
        assert(0 <= to and to < n);
        assert(lower <= upper);
        if (cost < 0) {
            std::swap(from, to);
            std::swap(lower, upper);
            lower *= -1;
            upper *= -1;
            cost *= -1;
        }
        b[from] -= lower;
        b[to] += lower;
        sum += cost * lower;
        return graph.add_edge(from, to, upper - lower, cost);
    }

    void add_supply(int v, Cap x) {
        assert(0 <= v and v < n);
        b[v] += x;
    }

    void add_demand(int v, Cap x) {
        assert(0 <= v and v < n);
        b[v] -= x;
    }

    std::pair<bool, Cost> flow() {
        int source = n, sink = source + 1;
        Cap positive{}, negative{};
        for (int v = 0; v < n; v++) {
            if (b[v] > 0) {
                graph.add_edge(source, v, b[v], 0);
                positive += b[v];
            } else if (b[v] < 0) {
                graph.add_edge(v, sink, -b[v], 0);
                negative += -b[v];
            }
        }
        if (positive != negative) return make_pair(false, Cost{});
        auto res = graph.flow(source, sink);
        Cap flow = res.first;
        Cost cost = res.second;
        if (flow < positive) return make_pair(false, Cost{});
        return make_pair(true, sum + cost);
    }

private:
    int n;
    atcoder::mcf_graph<Cap, Cost> graph;
    std::vector<Cap> b;
    Cost sum;
};
