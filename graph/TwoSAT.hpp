#pragma once
#include <cassert>
#include <vector>
#include "StronglyConnectedComponents.hpp"

struct TwoSAT {
    TwoSAT(int n) : n(n), called_satisfiable(false), ans(n), scc(2 * n) {}

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

    // i <=> !i -> i
    void set_true(int i) {
        assert(0 <= i and i < n);
        scc.add_edge(i << 1 | 1, i << 1 | 0);
    }

    // !i <=> i -> !i
    void set_false(int i) {
        assert(0 <= i and i < n);
        scc.add_edge(i << 1 | 0, i << 1 | 1);
    }

    bool satisfiable() {
        called_satisfiable = true;
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
