#include "atcoder/maxflow"

template <typename T> struct ProjectSelectionProblem {
    ProjectSelectionProblem() = default;

    explicit ProjectSelectionProblem(int n) : n(n), costs(n, std::vector<T>(2, 0)) {}

    void add_cost_0(int x, T cost) {
        assert(0 <= x and x < n);
        assert(cost >= 0);
        add_cost(x, {cost, 0});
    }

    void add_cost_1(int x, T cost) {
        assert(0 <= x and x < n);
        assert(cost >= 0);
        add_cost(x, {0, cost});
    }

    void add_profit_0(int x, T profit) {
        assert(0 <= x and x < n);
        assert(profit >= 0);
        add_cost(x, {-profit, 0});
    }

    void add_profit_1(int x, T profit) {
        assert(0 <= x and x < n);
        assert(profit >= 0);
        add_cost(x, {0, -profit});
    }

    void add_cost_01(int x, int y, T cost) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        assert(cost >= 0);
        add_edge(x, y, cost);
    }

    void add_cost_10(int x, int y, T cost) { add_cost_01(y, x, cost); }

    void add_profit_00(int x, int y, T profit) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        assert(profit >= 0);
        add_cost(x, y, {-profit, 0, 0, 0});
    }

    void add_profit_11(int x, int y, T profit) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        assert(profit >= 0);
        add_cost(x, y, {0, 0, 0, -profit});
    }

    // void add_cost_for_3(int x, int y, int z, std::array<std::array<std::array<T, 2>, 2>, 2> cost) {
    //     add_cost(x, y, z, cost);
    // }

    void add_profit_all_0(const std::vector<int>& v, T profit) {
        assert(profit >= 0);
        if (v.size() == 0)
            base_cost -= profit;
        else if (v.size() == 1)
            add_profit_0(v[0], profit);
        else if (v.size() == 2)
            add_profit_00(v[0], v[1], profit);
        else {
            base_cost -= profit;
            int nxt = n + aux++;
            add_edge(source, nxt, profit);
            for (const int& x : v) add_edge(nxt, x, profit);
        }
    }

    void add_profit_all_1(const std::vector<int>& v, T profit) {
        assert(profit >= 0);
        if (v.size() == 0)
            base_cost -= profit;
        else if (v.size() == 1)
            add_profit_1(v[0], profit);
        else if (v.size() == 2)
            add_profit_11(v[0], v[1], profit);
        else {
            base_cost -= profit;
            int nxt = n + aux++;
            add_edge(nxt, sink, profit);
            for (const int& x : v) add_edge(x, nxt, profit);
        }
    }

    std::pair<T, std::vector<bool>> min_cost() {
        for (int i = 0; i < n; i++) {
            auto& tmp = costs[i];
            if (tmp[0] <= tmp[1]) {
                base_cost += tmp[0];
                add_edge(source, i, tmp[1] - tmp[0]);
            } else {
                base_cost += tmp[1];
                add_edge(i, sink, tmp[0] - tmp[1]);
            }
        }
        atcoder::mf_graph<T> g(n + aux + 2);
        int s = n + aux, t = s + 1;
        for (auto [u, v, w] : es) {
            u = (u == source ? s : u == sink ? t : u);
            v = (v == source ? s : v == sink ? t : v);
            g.add_edge(u, v, w);
        }
        auto sum = base_cost + g.flow(s, t);
        auto x = g.min_cut(s);
        x.resize(n);
        for (int i = 0; i < n; i++) x[i] = not x[i];
        return {sum, x};
    }

    std::pair<T, std::vector<bool>> max_profit() {
        auto res = min_cost();
        res.first *= -1;
        return res;
    }

  private:
    int n, aux = 0, source = -1, sink = -2;
    T base_cost;
    std::vector<std::vector<T>> costs;
    std::vector<std::tuple<int, int, T>> es;

    void add_edge(int x, int y, T cost) {
        assert(x == source or x == sink or (0 <= x and x < n + aux));
        assert(y == source or y == sink or (0 <= y and y < n + aux));
        if (cost == 0) return;
        es.emplace_back(x, y, cost);
    }

    void add_cost(int x, std::array<T, 2> cost) {
        for (int i = 0; i < 2; i++) costs[x][i] += cost[i];
    }

    void add_cost(int x, int y, std::array<std::array<T, 2>, 2> cost) {
        assert(cost[0][1] + cost[1][0] >= cost[0][0] + cost[1][1]);
        base_cost += cost[0][0];
        add_cost(x, {0, cost[1][0] - cost[0][0]});
        add_cost(y, {0, cost[1][1] - cost[1][0]});
        add_cost_01(x, y, (cost[0][1] - cost[0][0]) - (cost[1][1] - cost[1][0]));
    }

    // void add_cost(int x, int y, std::array<std::array<std::array<T, 2>, 2>, 2> cost) {}
};
