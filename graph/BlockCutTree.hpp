#pragma once
#include <cassert>
#include <queue>
#include <utility>
#include <vector>

struct BlockCutTree {
    std::vector<std::vector<std::pair<int, int>>> G;
    std::vector<std::vector<int>> tecc_tree,    // tree that consists of two-edge-connected-component
        bct;                                    // tree that consists of bi-connected-component and articulation
    std::vector<bool> is_articulation,          // whether vertex i is articulation or not
        is_bridge;                              // whether edge i is bridge or not
    std::vector<int> tecc_id;                   // id of two-edge-connected-component vertex i belongs to
    std::vector<std::vector<int>> tecc_groups;  // vertices belongs to i-th two-edge-connected-component
    std::vector<int> bcc_id;                    // id of bi-connected-component edge i belongs to
    std::vector<std::vector<std::pair<int, int>>> bcc_groups;  // edges belongs to i-th bi-connected-component
    std::vector<int> bct_id;  // id of component on block-cut-tree vertex i belongs to (order : bcc -> articulation)
    std::vector<std::vector<int>> bct_groups;  // vertices belongs to i-th component on block-cut-tree

    BlockCutTree(int n)
        : G(n), is_articulation(n, false), n(n), m(0), time(0), bcc_num(0), order(n, -1), lowlink(n, -1) {}

    void add_edge(int u, int v) {
        assert(0 <= u && u < n);
        assert(0 <= v && v < n);
        G[u].emplace_back(v, m);
        G[v].emplace_back(u, m);
        if (u > v) std::swap(u, v);
        edges.emplace_back(u, v);
        is_bridge.emplace_back(false);
        is_dfstree_edge.emplace_back(false);
        bcc_id.emplace_back(-1);
        m++;
    }

    void build() {
        called_build = true;
        for (int i = 0; i < n; i++) {
            if (order[i] == -1) {
                dfs_lowlink(i);
            }
        }
        for (int i = 0; i < m; i++) {
            int u = edges[i].first, v = edges[i].second;
            if (order[u] > order[v]) std::swap(u, v);
            if (order[u] < lowlink[v]) is_bridge[i] = true;
        }
    }

    std::vector<std::vector<int>> two_edge_connected_components() {
        assert(called_build);
        called_two_connected_components = true;
        tecc_num = 0;
        tecc_id.assign(n, -1);
        for (int i = 0; i < n; i++) {
            if (tecc_id[i] >= 0) continue;
            tecc_id[i] = tecc_num;
            std::queue<int> que;
            que.emplace(i);
            while (!que.empty()) {
                int v = que.front();
                que.pop();
                for (const auto& e : G[v]) {
                    int u = e.first;
                    if (tecc_id[u] >= 0 || is_bridge[e.second]) continue;
                    tecc_id[u] = tecc_num;
                    que.emplace(u);
                }
            }
            tecc_num++;
        }
        tecc_groups.resize(tecc_num);
        for (int i = 0; i < n; i++) tecc_groups[tecc_id[i]].emplace_back(i);
        return tecc_groups;
    }

    std::vector<std::vector<int>> tecc_make_tree() {
        assert(called_two_connected_components);
        tecc_tree.resize(tecc_num);
        for (int i = 0; i < m; i++) {
            if (!is_bridge[i]) continue;
            int u = tecc_id[edges[i].first], v = tecc_id[edges[i].second];
            tecc_tree[u].emplace_back(v);
            tecc_tree[v].emplace_back(u);
        }
        return tecc_tree;
    }

    std::vector<std::vector<std::pair<int, int>>> bi_connected_components() {
        assert(called_build);
        called_bi_connected_components = true;
        bcc_groups.resize(bcc_num);
        for (int i = 0; i < m; i++) bcc_groups[bcc_id[i]].emplace_back(edges[i]);
        return bcc_groups;
    }

    std::vector<std::vector<int>> block_cut_tree() {
        assert(called_bi_connected_components);
        int bct_num = bcc_num;
        for (int i = 0; i < n; i++) {
            if (is_articulation[i]) {
                bct_id[i] = bct_num++;
            }
        }
        bct.resize(bct_num);
        std::vector<int> last_adjacent(bct_num, -1);
        for (int i = 0; i < bcc_num; i++) {
            for (auto& e : bcc_groups[i]) {
                for (auto& v : {e.first, e.second}) {
                    if (is_articulation[v]) {
                        if (std::exchange(last_adjacent[bct_id[v]], i) != i) {
                            bct[i].emplace_back(bct_id[v]);
                            bct[bct_id[v]].emplace_back(i);
                        }
                    } else
                        bct_id[v] = i;
                }
            }
        }
        return bct;
    }

private:
    int n, m, time, tecc_num, bcc_num;
    bool called_build, called_two_connected_components, called_bi_connected_components;
    std::vector<std::pair<int, int>> edges;
    std::vector<int> order;             // visiting order of dfs-tree
    std::vector<int> lowlink;           // min of order of u which can be visited from v by using dfs-tree edge any
                                        // times and back edge at most once
    std::vector<bool> is_dfstree_edge;  // whether edge is used in dfs-tree or not

    std::vector<int> edge_stack;

    void dfs_lowlink(int v, int pre_eid = -1) {
        order[v] = lowlink[v] = time++;
        for (const auto& e : G[v]) {
            int u = e.first;
            if (e.second != pre_eid) {
                if (order[u] < order[v]) edge_stack.emplace_back(e.second);
                if (order[u] >= 0)
                    lowlink[v] = std::min(lowlink[v], order[u]);
                else {
                    is_dfstree_edge[e.second] = true;
                    dfs_lowlink(u, e.second);
                    lowlink[v] = std::min(lowlink[v], lowlink[u]);
                    if (pre_eid == -1 && order[u] != order[v] + 1) is_articulation[v] = true;
                    if (pre_eid != -1 && order[v] <= lowlink[u]) is_articulation[v] = true;
                    if (order[v] <= lowlink[u]) {
                        while (true) {
                            int cur = edge_stack.back();
                            edge_stack.pop_back();
                            bcc_id[cur] = bcc_num;
                            if (edges[cur] == edges[e.second]) break;
                        }
                        bcc_num++;
                    }
                }
            }
        }
    }
};
