#pragma once
#include <cassert>
#include <vector>
#include "StronglyConnectedComponents.hpp"

struct TwoSAT {
    TwoSAT(int n) : n(n), called_satisfiable(false), scc(2 * n) {}

    int add_vertex() {
        scc.add_vertex();
        scc.add_vertex();
        return n++;
    }

    // (i = f or j = g)
    void add_clause(int i, bool f, int j, bool g) {
        assert(0 <= i and i < n);
        assert(0 <= j and j < n);
        scc.add_edge(i << 1 | (f ? 0 : 1), j << 1 | (g ? 1 : 0));
        scc.add_edge(j << 1 | (g ? 0 : 1), i << 1 | (f ? 1 : 0));
    }

    // (i = f) -> (j = g) <=> (i = !f) or (j = g)
    void add_if(int i, bool f, int j, bool g) {
        assert(0 <= i and i < n);
        assert(0 <= j and j < n);
        add_clause(i, f ^ 1, j, g);
    }

    // i
    void set_true(int i) {
        assert(0 <= i and i < n);
        add_clause(i, true, i, true);
    }

    // !i
    void set_false(int i) {
        assert(0 <= i and i < n);
        add_clause(i, false, i, false);
    }

    // <= 1 of literals in v are true
    void at_most_one(const std::vector<std::pair<int, int>>& v) {
        if (v.size() <= 1) return;
        for (size_t i = 0; i < v.size(); i++) {
            int nxt = add_vertex(), cur = nxt - 1, x = v[i].first, f = v[i].second;
            add_if(x, f, nxt, 1);
            if (i > 0) {
                add_if(cur, 1, nxt, 1);
                add_clause(cur, 0, x, f ^ 1);
            }
        }
    }

    bool satisfiable() {
        called_satisfiable = true;
        ans.resize(n);
        scc.build();
        for (int i = 0; i < n; i++) {
            if (scc[i << 1] == scc[i << 1 | 1]) return false;
            ans[i] = (scc[i << 1] < scc[i << 1 | 1]);
        }
        return true;
    }

    std::vector<bool> answer() const {
        assert(called_satisfiable);
        return ans;
    }

private:
    int n;
    bool called_satisfiable;
    std::vector<bool> ans;
    StronglyConnectedComponents scc;
};
