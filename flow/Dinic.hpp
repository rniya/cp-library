#pragma once
#include <cassert>
#include <fstream>
#include <limits>
#include <queue>
#include <string>
#include <tuple>
#include <vector>

template <typename Cap, bool directed> struct Dinic {
    Dinic(int n) : n(n), G(n), level(n), iter(n) {}

    int add_edge(int from, int to, Cap cap) {
        assert(0 <= from && from < n);
        assert(0 <= to && to < n);
        assert(0 <= cap);
        assert(from != to);
        int m = pos.size(), from_id = G[from].size(), to_id = G[to].size();
        pos.emplace_back(from, G[from].size());
        G[from].emplace_back(to, cap, to_id);
        G[to].emplace_back(from, directed ? 0 : cap, from_id);
        return m;
    }

    int add_vertex() {
        G.emplace_back();
        level.emplace_back();
        iter.emplace_back();
        return n++;
    }

    std::tuple<int, int, Cap, Cap> get_edge(int i) {
        assert(0 <= i && i < (int)pos.size());
        auto e = G[pos[i].first][pos[i].second];
        auto re = G[e.to][e.rev];
        return {pos[i].first, e.to, e.cap + re.cap, re.cap};
    }

    std::vector<std::tuple<int, int, Cap, Cap>> edges() {
        std::vector<std::tuple<int, int, Cap, Cap>> res;
        for (size_t i = 0; i < pos.size(); i++) res.emplace_back(get_edge(i));
        return res;
    }

    void change_edge(int i, Cap new_cap, Cap new_flow) {
        assert(0 <= i && i < (int)pos.size());
        assert(0 <= new_flow && new_flow <= new_cap);
        auto& e = G[pos[i].first][pos[i].second];
        auto& re = G[e.to][e.rev];
        e.cap = new_cap - new_flow;
        re.cap = (directed ? new_flow : new_cap + new_flow);
    }

    Cap max_flow(int s, int t) { return max_flow(s, t, std::numeric_limits<Cap>::max()); }

    Cap max_flow(int s, int t, Cap flow_limit) {
        assert(0 <= s && s < n);
        assert(0 <= t && t < n);
        if (s == t) return 0;
        Cap flow = 0;
        while (flow < flow_limit) {
            bfs(s, t);
            if (level[t] < 0) break;
            std::fill(iter.begin(), iter.end(), 0);
            while (flow < flow_limit) {
                Cap f = dfs(s, t, flow_limit - flow);
                if (f == 0) break;
                flow += f;
            }
        }
        return flow;
    }

    std::vector<bool> min_cut(int s) {
        assert(0 <= s && s < n);
        std::vector<bool> visited(n);
        std::queue<int> que;
        visited[s] = true;
        que.emplace(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (const auto& e : G[v]) {
                if (e.cap && !visited[e.to]) {
                    visited[e.to] = true;
                    que.emplace(e.to);
                }
            }
        }
        return visited;
    }

    void dump_graphviz(std::string filename = "maxflow") {
        std::ofstream ofs(filename + ".dot");
        ofs << "digraph {\n";
        auto es = edges();
        for (const auto& e : es) {
            int from, to;
            Cap cap, flow;
            std::tie(from, to, cap, flow) = e;
            ofs << from << " -> " << to << " [label = \"" << flow << "/" << cap << "\", color = "
                << (flow == cap ? "red"
                    : flow > 0  ? "blue"
                                : "black")
                << "];\n";
        }
        ofs << "}\n";
        ofs.close();
        return;
    }

private:
    struct edge {
        int to;
        Cap cap;
        int rev;
        edge(int to, Cap cap, int rev) : to(to), cap(cap), rev(rev) {}
    };

    int n;
    std::vector<std::vector<edge>> G;
    std::vector<std::pair<int, int>> pos;
    std::vector<int> level, iter;

    void bfs(int s, int t) {
        std::fill(level.begin(), level.end(), -1);
        std::queue<int> que;
        level[s] = 0;
        que.emplace(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (const auto& e : G[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    if (e.to == t) return;
                    que.emplace(e.to);
                }
            }
        }
    }

    Cap dfs(int v, int t, Cap f) {
        if (v == t) return f;
        for (int& i = iter[v]; i < (int)G[v].size(); i++) {
            auto& e = G[v][i];
            if (e.cap <= 0 || level[v] >= level[e.to]) continue;
            Cap d = dfs(e.to, t, std::min(f, e.cap));
            if (d <= 0) continue;
            e.cap -= d;
            G[e.to][e.rev].cap += d;
            return d;
        }
        return 0;
    }
};

/**
 * @brief Dinic (Maximum flow)
 * @docs docs/flow/Dinic.md
 */
