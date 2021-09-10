#pragma once
#include "../base.hpp"

/**
 * @brief Dinic
 * @docs docs/flow/Dinic.md
 */
template <typename Cap, bool directed> struct Dinic {
    struct edge {
        int to;
        Cap cap;
        int rev;
        edge(int to, Cap cap, int rev) : to(to), cap(cap), rev(rev) {}
    };
    vector<vector<edge>> G;
    vector<pair<int, int>> pos;
    vector<int> level, iter;
    Dinic(int n) : G(n), level(n), iter(n) {}
    int add_edge(int from, int to, Cap cap) {
        pos.emplace_back(from, G[from].size());
        G[from].emplace_back(to, cap, G[to].size());
        G[to].emplace_back(from, directed ? 0 : cap, G[from].size() - 1);
        return pos.size() - 1;
    }
    int add_vertex() {
        G.emplace_back();
        level.emplace_back();
        iter.emplace_back();
        return G.size() - 1;
    }
    tuple<int, int, Cap, Cap> get_edge(int i) {
        auto e = G[pos[i].first][pos[i].second];
        auto re = G[e.to][e.rev];
        return {pos[i].first, e.to, e.cap + re.cap, re.cap};
    }
    vector<tuple<int, int, Cap, Cap>> edges() {
        vector<tuple<int, int, Cap, Cap>> res;
        for (size_t i = 0; i < pos.size(); i++) res.emplace_back(get_edge(i));
        return res;
    }
    void change_edge(int i, Cap new_cap, Cap new_flow) {
        auto& e = G[pos[i].first][pos[i].second];
        auto& re = G[e.to][e.rev];
        e.cap = new_cap - new_flow;
        re.cap = (directed ? new_flow : new_cap + new_flow);
    }
    void bfs(int s) {
        fill(level.begin(), level.end(), -1);
        queue<int> que;
        level[s] = 0;
        que.emplace(s);

        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto& e : G[v]) {
                if (e.cap > 0 && level[e.to] < 0) {
                    level[e.to] = level[v] + 1;
                    que.emplace(e.to);
                }
            }
        }
    }
    Cap dfs(int v, int t, Cap f) {
        if (v == t) return f;
        for (int& i = iter[v]; i < (int)G[v].size(); i++) {
            auto& e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                Cap d = dfs(e.to, t, min(f, e.cap));
                if (d <= 0) continue;
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }
    Cap max_flow(int s, int t, Cap lim) {
        Cap flow = 0;
        while (lim > 0) {
            bfs(s);
            if (level[t] < 0) break;
            fill(iter.begin(), iter.end(), 0);
            while (lim > 0) {
                Cap f = dfs(s, t, lim);
                if (f == 0) break;
                flow += f;
                lim -= f;
            }
        }
        return flow;
    }
    Cap max_flow(int s, int t) { return max_flow(s, t, numeric_limits<Cap>::max()); }
    vector<bool> min_cut(int s) {
        vector<bool> res(G.size());
        queue<int> que;
        res[s] = true;
        que.emplace(s);
        while (!que.empty()) {
            int v = que.front();
            que.pop();
            for (auto e : G[v]) {
                if (e.cap > 0 && !res[e.to]) {
                    res[e.to] = true;
                    que.emplace(e.to);
                }
            }
        }
        return res;
    }
};