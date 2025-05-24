#pragma once
#include <algorithm>
#include <cassert>
#include <queue>
#include <utility>
#include <vector>

struct StaticTopTree {
    struct Node {
        int l, r, p, head, tail;
        bool is_compress;
        Node() {}
        Node(int l, int r, int p, bool is_compress) : l(l), r(r), p(p), is_compress(is_compress) {}
    };
    int n;
    std::vector<std::vector<int>> G;
    std::vector<Node> nodes;

    StaticTopTree(int n) : n(n), G(n), nodes(n, {-1, -1, -1, false}) {}

    void add_edge(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    void build(int r = 0) {
        dfs_sz(r, -1);
        dfs_stt(r);
        assert(int(nodes.size()) == 2 * n - 1);
    }

  private:
    int make_node(int l, int r, bool is_compress) {
        int v = nodes.size();
        nodes.emplace_back(l, r, -1, is_compress);
        nodes[l].p = nodes[r].p = v;
        return v;
    }

    int dfs_sz(int v, int p) {
        for (int& u : G[v]) {
            if (u == p) {
                std::swap(u, G[v].back());
                G[v].pop_back();
                break;
            }
        }
        int sum = 1, best = 0;
        for (int& u : G[v]) {
            int ch = dfs_sz(u, v);
            sum += ch;
            if (best < ch) {
                best = ch;
                std::swap(u, G[v].front());
            }
        }
        return sum;
    }

    std::pair<int, int> dfs_stt(int v) {
        std::vector<std::pair<int, int>> st;
        st.emplace_back(0, v);
        auto merge_last = [&]() {
            auto [hr, ir] = st.back();
            st.pop_back();
            auto [hl, il] = st.back();
            st.pop_back();
            st.emplace_back(std::max(hl, hr) + 1, make_node(il, ir, true));
        };

        for (int cur = v; not G[cur].empty(); cur = G[cur].front()) {
            int nxt = G[cur].front(), marked = nxt;
            std::priority_queue<std::pair<int, int>, std::vector<std::pair<int, int>>,
                                std::greater<std::pair<int, int>>>
                pq;
            pq.emplace(0, marked);
            for (int i = 1; i < int(G[cur].size()); i++) {
                pq.emplace(dfs_stt(G[cur][i]));
            }
            while (pq.size() >= 2) {
                auto [hl, il] = pq.top();
                pq.pop();
                auto [hr, ir] = pq.top();
                pq.pop();
                if (ir == marked) {
                    std::swap(il, ir);
                }
                int i = make_node(il, ir, false);
                if (il == marked) {
                    marked = i;
                }
                pq.emplace(std::max(hl, hr) + 1, i);
            }
            st.emplace_back(pq.top());

            while (true) {
                int len = st.size();
                if (len >= 3 and (st[len - 3].first == st[len - 2].first or st[len - 3].first <= st[len - 1].first)) {
                    auto tmp = st.back();
                    st.pop_back();
                    merge_last();
                    st.emplace_back(tmp);
                } else if (len >= 2 and st[len - 2].first <= st[len - 1].first) {
                    merge_last();
                } else {
                    break;
                }
            }
        }

        while (st.size() >= 2) {
            merge_last();
        }
        return st.back();
    }
};

template <typename TREEDP> struct DynamicTreeDP {
    using T = typename TREEDP::T;

    template <typename F>
    DynamicTreeDP(int n, const StaticTopTree& stt, const F& vertex) : n(n), stt(stt), dp(2 * n - 1) {
        for (int i = 0; i < n; i++) {
            dp[i] = vertex(i);
        }
        for (int i = n; i < 2 * n - 1; i++) {
            update(i);
        }
    }

    void set(int v, T x) {
        assert(0 <= v and v < n);
        dp[v] = x;
        for (int i = stt.nodes[v].p; i != -1; i = stt.nodes[i].p) {
            update(i);
        }
    }

    T all_prod() const { return dp.back(); }

  private:
    int n;
    const StaticTopTree& stt;
    std::vector<T> dp;

    void update(int k) {
        const auto &L = dp[stt.nodes[k].l], &R = dp[stt.nodes[k].r];
        dp[k] = (stt.nodes[k].is_compress ? TREEDP::compress(L, R) : TREEDP::rake(L, R));
    }
};
