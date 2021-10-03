---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/flow/BipartiteMathcing.md
    document_title: Bipartite Matching
    links: []
  bundledCode: "#line 2 \"flow/BipartiteMatching.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <queue>\n#include <utility>\n#include <vector>\n\nstruct\
    \ BipartiteMatching {\n    BipartiteMatching(int U, int V) : U(U), V(V), t(0),\
    \ solved(false), G(U), L(U, -1), R(V, -1), visited(U, -1) {}\n\n    void add_edge(int\
    \ u, int v) {\n        assert(0 <= u && u < U && 0 <= v && v < V);\n        G[u].emplace_back(v);\n\
    \    }\n\n    int solve() {\n        for (bool updated = true; std::exchange(updated,\
    \ false); t++) {\n            for (int i = 0; i < U; i++) {\n                if\
    \ (L[i] == -1) {\n                    updated |= dfs(i);\n                }\n\
    \            }\n        }\n        solved = true;\n        return U - std::count(L.begin(),\
    \ L.end(), -1);\n    }\n\n    std::vector<std::pair<int, int>> max_matching()\
    \ const {\n        assert(solved);\n        std::vector<std::pair<int, int>> res;\n\
    \        for (int i = 0; i < U; i++) {\n            if (~L[i]) {\n           \
    \     res.emplace_back(i, L[i]);\n            }\n        }\n        return res;\n\
    \    }\n\nprivate:\n    int U, V, t;\n    bool solved;\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<int> L, R, visited;\n\n    bool dfs(int u) {\n        if\
    \ (std::exchange(visited[u], t) == t) return false;\n        for (int& v : G[u])\
    \ {\n            if (R[v] == -1) {\n                L[u] = v, R[v] = u;\n    \
    \            return true;\n            }\n        }\n        for (int& v : G[u])\
    \ {\n            if (dfs(R[v])) {\n                L[u] = v, R[v] = u;\n     \
    \           return true;\n            }\n        }\n        return false;\n  \
    \  }\n};\n\n/**\n * @brief Bipartite Matching\n * @docs docs/flow/BipartiteMathcing.md\n\
    \ */\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <queue>\n\
    #include <utility>\n#include <vector>\n\nstruct BipartiteMatching {\n    BipartiteMatching(int\
    \ U, int V) : U(U), V(V), t(0), solved(false), G(U), L(U, -1), R(V, -1), visited(U,\
    \ -1) {}\n\n    void add_edge(int u, int v) {\n        assert(0 <= u && u < U\
    \ && 0 <= v && v < V);\n        G[u].emplace_back(v);\n    }\n\n    int solve()\
    \ {\n        for (bool updated = true; std::exchange(updated, false); t++) {\n\
    \            for (int i = 0; i < U; i++) {\n                if (L[i] == -1) {\n\
    \                    updated |= dfs(i);\n                }\n            }\n  \
    \      }\n        solved = true;\n        return U - std::count(L.begin(), L.end(),\
    \ -1);\n    }\n\n    std::vector<std::pair<int, int>> max_matching() const {\n\
    \        assert(solved);\n        std::vector<std::pair<int, int>> res;\n    \
    \    for (int i = 0; i < U; i++) {\n            if (~L[i]) {\n               \
    \ res.emplace_back(i, L[i]);\n            }\n        }\n        return res;\n\
    \    }\n\nprivate:\n    int U, V, t;\n    bool solved;\n    std::vector<std::vector<int>>\
    \ G;\n    std::vector<int> L, R, visited;\n\n    bool dfs(int u) {\n        if\
    \ (std::exchange(visited[u], t) == t) return false;\n        for (int& v : G[u])\
    \ {\n            if (R[v] == -1) {\n                L[u] = v, R[v] = u;\n    \
    \            return true;\n            }\n        }\n        for (int& v : G[u])\
    \ {\n            if (dfs(R[v])) {\n                L[u] = v, R[v] = u;\n     \
    \           return true;\n            }\n        }\n        return false;\n  \
    \  }\n};\n\n/**\n * @brief Bipartite Matching\n * @docs docs/flow/BipartiteMathcing.md\n\
    \ */\n"
  dependsOn: []
  isVerificationFile: false
  path: flow/BipartiteMatching.hpp
  requiredBy: []
  timestamp: '2021-10-03 18:22:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: flow/BipartiteMatching.hpp
layout: document
redirect_from:
- /library/flow/BipartiteMatching.hpp
- /library/flow/BipartiteMatching.hpp.html
title: Bipartite Matching
---
