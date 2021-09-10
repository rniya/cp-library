#pragma once
#include "../base.hpp"

/**
 * @brief Dinic
 * @docs docs/flow/Dinic.md
 */
template <typename T, bool directed> struct Dinic {
    struct edge {
        int to, rev;
        T cap;
        edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}
    };
    vector<vector<edge>> G;
    vector<pair<int, int>> pos;
    vector<int> level, iter;
    Dinic(int n) : G(n), level(n), iter(n) {}
    int add_edge(int from, int to, T cap) {
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
    tuple<int, int, T, T> get_edge(int i) {
        auto e = G[pos[i].first][pos[i].second];
        auto re = G[e.to][e.rev];
        return {pos[i].first, e.to, e.cap + re.cap, re.cap};
    }
    vector<tuple<int, int, T, T>> edges() {
        vector<tuple<int, int, T, T>> res;
        for (int i = 0; i < (int)pos.size(); i++) {
            res.emplace_back(get_edge(i));
        }
        return res;
    }
    void change_edge(int i, T new_cap, T new_flow) {
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
    T dfs(int v, int t, T f) {
        if (v == t) return f;
        for (int& i = iter[v]; i < (int)G[v].size(); i++) {
            auto& e = G[v][i];
            if (e.cap > 0 && level[v] < level[e.to]) {
                T d = dfs(e.to, t, min(f, e.cap));
                if (d <= 0) continue;
                e.cap -= d;
                G[e.to][e.rev].cap += d;
                return d;
            }
        }
        return 0;
    }
    T max_flow(int s, int t, T lim) {
        T flow = 0;
        while (lim > 0) {
            bfs(s);
            if (level[t] < 0) break;
            fill(iter.begin(), iter.end(), 0);
            while (lim > 0) {
                T f = dfs(s, t, lim);
                if (f == 0) break;
                flow += f;
                lim -= f;
            }
        }
        return flow;
    }
    T max_flow(int s, int t) { return max_flow(s, t, numeric_limits<T>::max()); }
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