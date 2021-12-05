#pragma once
#include <algorithm>
#include <cassert>
#include <limits>
#include <queue>
#include <vector>

#include "atcoder/internal_queue"

namespace ProjectSelectionProblem_Impl {

template <class Cap> struct mf_graph {
public:
    mf_graph() : _n(0) {}
    explicit mf_graph(int n) : _n(n), g(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < _n);
        assert(0 <= to && to < _n);
        assert(0 <= cap);
        int m = int(pos.size());
        pos.push_back({from, int(g[from].size())});
        int from_id = int(g[from].size());
        int to_id = int(g[to].size());
        if (from == to) to_id++;
        g[from].push_back(_edge{to, to_id, cap});
        g[to].push_back(_edge{from, from_id, 0});
        return m;
    }
    int add_vertex() {
        g.resize(_n + 1);
        return _n++;
    }

    struct edge {
        int from, to;
        Cap cap, flow;
    };

    edge get_edge(int i) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        auto _e = g[pos[i].first][pos[i].second];
        auto _re = g[_e.to][_e.rev];
        return edge{pos[i].first, _e.to, _e.cap + _re.cap, _re.cap};
    }
    std::vector<edge> edges() {
        int m = int(pos.size());
        std::vector<edge> result;
        for (int i = 0; i < m; i++) {
            result.push_back(get_edge(i));
        }
        return result;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        int m = int(pos.size());
        assert(0 <= i && i < m);
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& _e = g[pos[i].first][pos[i].second];
        auto& _re = g[_e.to][_e.rev];
        _e.cap = new_cap - new_flow;
        _re.cap = new_flow;
    }

    Cap flow(int s, int t) { return flow(s, t, std::numeric_limits<Cap>::max()); }
    Cap flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < _n);
        assert(0 <= t && t < _n);
        assert(s != t);

        std::vector<int> level(_n), iter(_n);
        atcoder::internal::simple_queue<int> que;

        auto bfs = [&]() {
            std::fill(level.begin(), level.end(), -1);
            level[s] = 0;
            que.clear();
            que.push(s);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (auto e : g[v]) {
                    if (e.cap == 0 || level[e.to] >= 0) continue;
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.push(e.to);
                }
            }
        };
        auto dfs = [&](auto self, int v, Cap up) {
            if (v == s) return up;
            Cap res = 0;
            int level_v = level[v];
            for (int& i = iter[v]; i < int(g[v].size()); i++) {
                _edge& e = g[v][i];
                if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;
                Cap d = self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));
                if (d <= 0) continue;
                g[v][i].cap += d;
                g[e.to][e.rev].cap -= d;
                res += d;
                if (res == up) return res;
            }
            level[v] = _n;
            return res;
        };

        Cap flow = 0;
        while (flow < flow_limit) {
            bfs();
            if (level[t] == -1) break;
            std::fill(iter.begin(), iter.end(), 0);
            Cap f = dfs(dfs, t, flow_limit - flow);
            if (!f) break;
            flow += f;
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        std::vector<bool> visited(_n);
        atcoder::internal::simple_queue<int> que;
        que.push(s);
        while (!que.empty()) {
            int p = que.front();
            que.pop();
            visited[p] = true;
            for (auto e : g[p]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.push(e.to);
                }
            }
        }
        return visited;
    }

private:
    int _n;
    struct _edge {
        int to, rev;
        Cap cap;
    };
    std::vector<std::pair<int, int>> pos;
    std::vector<std::vector<_edge>> g;
};

template <typename T> struct ProjectSelectionProblem {
    ProjectSelectionProblem(int n) : n(n + 2), s(n), t(n + 1), sum(T(0)), graph(n + 2) {}

    void x_false_loss(int x, T z) {
        assert(0 <= x and x < n);
        graph.add_edge(x, t, z);
    }

    void x_false_profit(int x, T z) {
        assert(0 <= x and x < n);
        sum += z;
        x_true_loss(x, z);
    }

    void x_true_loss(int x, T z) {
        assert(0 <= x and x < n);
        graph.add_edge(s, x, z);
    }

    void x_true_profit(int x, T z) {
        assert(0 <= x and x < n);
        sum += z;
        x_false_loss(x, z);
    }

    void x_false_y_true_loss(int x, int y, T z) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        graph.add_edge(x, y, z);
    }

    void x_true_y_false_loss(int x, int y, T z) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        graph.add_edge(y, x, z);
    }

    void x_false_y_false_profit(int x, int y, T z) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        sum += z;
        int w = graph.add_vertex();
        n++;
        x_true_loss(w, z);
        x_false_y_true_loss(w, x, inf);
        x_false_y_true_loss(w, y, inf);
    }

    void x_true_y_true_profit(int x, int y, T z) {
        assert(0 <= x and x < n);
        assert(0 <= y and y < n);
        sum += z;
        int w = graph.add_vertex();
        n++;
        x_false_loss(w, z);
        x_true_y_false_loss(w, x, inf);
        x_true_y_false_loss(w, y, inf);
    }

    T min_loss() { return graph.flow(s, t) - sum; }

    T max_profit() { return -min_loss(); }

private:
    int n, s, t;
    T sum;
    const T inf = std::numeric_limits<T>::max() / 2;
    mf_graph<T> graph;
};

}  // namespace ProjectSelectionProblem_Impl

using ProjectSelectionProblem_Impl::ProjectSelectionProblem;

/**
 * @brief Project Selection Problem (based on ac-library)
 * @docs docs/flow/ProjectSelectionProblem.md
 */
