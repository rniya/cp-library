#include <algorithm>
#include <cassert>
#include <vector>

template <bool directed> struct EulerianTrail {
    std::vector<std::vector<std::pair<int, int>>> G;

    EulerianTrail(int n) : G(n), n(n), m(0), deg(n, 0), used_vertex(n, false) {}

    void add_edge(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        edges.emplace_back(u, v);
        used_edge.emplace_back(false);
        G[u].emplace_back(v, m);
        deg[u]++;
        if (directed)
            deg[v]--;
        else {
            G[v].emplace_back(u, m);
            deg[v]++;
        }
        m++;
    }

    std::vector<std::vector<int>> solve() {
        if (directed) {
            if (std::count_if(deg.begin(), deg.end(), [](int x) { return x != 0; })) return {};
        } else {
            if (std::count_if(deg.begin(), deg.end(), [](int x) { return (x & 1) != 0; })) return {};
        }
        std::vector<std::vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (G[i].empty() or used_vertex[i]) continue;
            res.emplace_back(go(i));
        }
        return res;
    }

    std::vector<std::vector<int>> solve_semi() {
        checked_vertex.assign(n, false);
        std::vector<std::vector<int>> res;
        for (int i = 0; i < n; i++) {
            if (checked_vertex[i]) continue;
            int s = -1, t = -1;
            if (!dfs(i, s, t)) return {};
            res.emplace_back(go(s >= 0 ? s : i));
            if (res.back().empty()) res.pop_back();
        }
        return res;
    }

    std::pair<int, int> operator[](int k) const { return edges[k]; }

private:
    int n, m;
    std::vector<int> deg;
    std::vector<std::pair<int, int>> edges;
    std::vector<bool> used_vertex, used_edge, checked_vertex;

    bool dfs(int v, int& s, int& t) {
        if (directed) {
            if (deg[v] < -1 or 1 < deg[v]) return false;
            if (deg[v] == 1) {
                if (s >= 0) return false;
                s = v;
            }
        } else {
            if (deg[v] & 1) {
                if (s == -1)
                    s = v;
                else if (t == -1)
                    t = v;
                else
                    return false;
            }
        }
        for (const auto& e : G[v]) {
            int u = e.first;
            if (checked_vertex[u]) continue;
            if (!dfs(u, s, t)) return false;
        }
        return true;
    }

    std::vector<int> go(int s) {
        std::vector<std::pair<int, int>> st;
        std::vector<int> order;
        st.emplace_back(s, -1);
        while (!st.empty()) {
            int v = st.back().first;
            used_vertex[v] = true;
            if (G[v].empty()) {
                order.emplace_back(st.back().second);
                st.pop_back();
            } else {
                auto e = G[v].back();
                G[v].pop_back();
                if (used_edge[e.second]) continue;
                used_edge[e.second] = true;
                st.emplace_back(e);
            }
        }
        order.pop_back();
        reverse(order.begin(), order.end());
        return order;
    }
};

/**
 * @brief Eulerian Trail
 * @docs docs/graph/EulerianTrail.md
 */
