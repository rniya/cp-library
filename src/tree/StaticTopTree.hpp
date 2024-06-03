#pragma once
#include <cassert>
#include <queue>
#include <utility>
#include <vector>

struct StaticTopTree {
    enum Type { Vertex, Compress, Add_Vertex, Rake, Add_Edge };
    struct Node {
        Type type;
        int l, r, p;
        Node() {}
        Node(Type type, int l = -1, int r = -1, int p = -1) : type(type), l(l), r(r), p(p) {}
    };
    int n, stt_root;
    std::vector<std::vector<int>> G;
    std::vector<Node> nodes;

    StaticTopTree(int n) : n(n), stt_root(-1), G(n), nodes(n) {}

    void add_edge(int u, int v) {
        assert(0 <= u and u < n);
        assert(0 <= v and v < n);
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }

    void build(int r = 0) {
        assert(0 <= r and r < n);
        dfs(r, -1);
        auto [i, s] = _compress(r);
        assert(s == n);
        stt_root = i;
    }

    int size() const { return nodes.size(); }

  private:
    int dfs(int v, int p) {
        for (int& u : G[v]) {
            if (u == p) {
                std::swap(u, G[v].back());
                G[v].pop_back();
                break;
            }
        }
        int sum = 1, best = 0;
        for (int& u : G[v]) {
            int ch = dfs(u, v);
            sum += ch;
            if (best < ch) {
                best = ch;
                std::swap(u, G[v].front());
            }
        }
        return sum;
    }

    int add(int l, int r, Type t) {
        int v = nodes.size();
        nodes.emplace_back(t, l, r);
        if (l != -1) {
            assert(l < v);
            nodes[l].p = v;
        }
        if (r != -1) {
            assert(r < v);
            nodes[r].p = v;
        }
        return v;
    }

    int Add(int v, int l, int r, Type t) {
        assert(v < n);
        nodes[v].type = t, nodes[v].l = l, nodes[v].r = r, nodes[v].p = -1;
        if (l != -1) {
            assert(l < int(nodes.size()));
            nodes[l].p = v;
        }
        if (r != -1) {
            assert(r < int(nodes.size()));
            nodes[r].p = v;
        }
        return v;
    }

    std::pair<int, int> merge(const std::vector<std::pair<int, int>>& a, Type t) {
        if (a.size() == 1) return a[0];
        int sum = 0;
        for (const auto& [_, s] : a) sum += s;
        std::vector<std::pair<int, int>> b, c;
        for (const auto& [i, s] : a) {
            (sum > s ? b : c).emplace_back(i, s);
            sum -= s * 2;
        }
        auto [l, sl] = merge(b, t);
        auto [r, sr] = merge(c, t);
        return {add(l, r, t), sl + sr};
    }

    std::pair<int, int> _compress(int v) {
        std::vector<std::pair<int, int>> chs{_add_vertex(v)};
        while (not G[v].empty()) chs.emplace_back(_add_vertex(v = G[v][0]));
        return merge(chs, Type::Compress);
    }

    std::pair<int, int> _add_vertex(int v) {
        auto [i, s] = _rake(v);
        return {Add(v, i, -1, i == -1 ? Type::Vertex : Type::Add_Vertex), s + 1};
    }

    std::pair<int, int> _rake(int v) {
        std::vector<std::pair<int, int>> chs;
        for (int i = 1; i < int(G[v].size()); i++) chs.emplace_back(_add_edge(G[v][i]));
        return chs.empty() ? std::make_pair(-1, 0) : merge(chs, Type::Rake);
    }

    std::pair<int, int> _add_edge(int v) {
        auto [i, s] = _compress(v);
        return {add(i, -1, Type::Add_Edge), s};
    }
};

template <class TreeDP> struct DynamicDPonStaticTopTree {
    using Path = typename TreeDP::Path;
    using Point = typename TreeDP::Point;
    const StaticTopTree& stt;
    TreeDP& treedp;
    std::vector<Path> paths;
    std::vector<Point> points;
    DynamicDPonStaticTopTree(const StaticTopTree& stt, TreeDP& treedp)
        : stt(stt), treedp(treedp), paths(stt.size()), points(stt.size()) {
        init(stt.stt_root);
    }

    void set(int k) {
        for (; k != -1; k = stt.nodes[k].p) {
            update(k);
        }
    }

    Path all_prod() const { return paths[stt.stt_root]; }

  private:
    void init(int k) {
        const auto& node = stt.nodes[k];
        if (node.l != -1) init(node.l);
        if (node.r != -1) init(node.r);
        update(k);
    }

    void update(int k) {
        const auto& node = stt.nodes[k];
        if (node.type == StaticTopTree::Type::Vertex) {
            paths[k] = treedp.vertex(k);
        } else if (node.type == StaticTopTree::Type::Compress) {
            paths[k] = treedp.compress(paths[node.l], paths[node.r]);
        } else if (node.type == StaticTopTree::Type::Add_Vertex) {
            paths[k] = treedp.add_vertex(points[node.l], k);
        } else if (node.type == StaticTopTree::Type::Rake) {
            points[k] = treedp.rake(points[node.l], points[node.r]);
        } else if (node.type == StaticTopTree::Type::Add_Edge) {
            points[k] = treedp.add_edge(paths[node.l]);
        } else {
            assert(false);
        }
    }
};
