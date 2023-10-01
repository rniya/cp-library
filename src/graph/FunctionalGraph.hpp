#pragma once
#include <cassert>
#include <vector>

struct FunctionalGraph {
    int n, L;
    std::vector<int> visit;
    std::vector<std::vector<int>> loops, G;

    FunctionalGraph(int n) : n(n), L(1), visit(n), G(n), nxt(n, -1) {}

    void add_edge(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        nxt[u] = v;
    }

    void build() {
        for (int i = 0; i < n; i++) {
            if (visit[i] != 0) continue;
            std::vector<int> loop;
            dfs(i, loop);
            if (not loop.empty()) loops.emplace_back(loop);
        }
        for (int i = 0; i < n; i++) {
            if (visit[i] < 0) {
                G[nxt[i]].emplace_back(i);
            }
        }
    }

  private:
    std::vector<int> nxt;

    void make_loop(int s, std::vector<int>& loop) {
        loop.emplace_back(s);
        visit[s] = L;
        for (int cur = nxt[s]; cur != s; cur = nxt[cur]) {
            loop.emplace_back(cur);
            visit[cur] = L;
        }
    }

    int dfs(int v, std::vector<int>& loop) {
        visit[v] = -L;
        int u = nxt[v];
        if (visit[u] == -L) {
            make_loop(v, loop);
            L++;
            return 0;
        } else if (visit[u] == 0) {
            int res = dfs(u, loop);
            if (res == 0) return 0;
            return visit[v] = res;
        }
        return visit[v] = (visit[u] > 0 ? -visit[u] : visit[u]);
    }
};
