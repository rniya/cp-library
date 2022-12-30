---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/LowLink.hpp
    title: LowLink (with Two Edge Connected Components, Bi Connected Components)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "#line 1 \"test/yosupo/two_edge_connected_components.test.cpp\"\n#define\
    \ PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\n\n\
    #include <iostream>\n#line 2 \"graph/LowLink.hpp\"\n#include <cassert>\n#include\
    \ <utility>\n#include <vector>\n\nstruct LowLink {\n    int n, m = 0, t = 0, b\
    \ = 0;\n    std::vector<std::vector<int>> G;\n    std::vector<std::pair<int, int>>\
    \ es;\n    std::vector<int> ord, low, tecc, bcc, tmp;\n    std::vector<bool> is_articulation,\
    \ is_bridge;\n\n    LowLink(int n) : n(n), G(n), ord(n, -1), low(n), tecc(n, -1),\
    \ is_articulation(n, false) {}\n\n    void add_edge(int u, int v) {\n        assert(0\
    \ <= u and u < n);\n        assert(0 <= v and v < n);\n        G[u].emplace_back(m);\n\
    \        G[v].emplace_back(m);\n        es.emplace_back(u, v);\n        is_bridge.emplace_back(false);\n\
    \        bcc.emplace_back();\n        m++;\n    }\n\n    void build() {\n    \
    \    for (int i = 0; i < n; i++) {\n            if (ord[i] != -1) continue;\n\
    \            dfs1(i, 0, -1);\n            dfs2(i, -1);\n        }\n    }\n\n \
    \   std::pair<int, int> operator[](int k) const { return es[k]; }\n\nprivate:\n\
    \    void dfs1(int v, int k, int pre) {\n        ord[v] = k++, low[v] = ord[v];\n\
    \        int cnt = 0;\n        for (int& e : G[v]) {\n            if (e == pre)\
    \ continue;\n            int u = es[e].first ^ es[e].second ^ v;\n           \
    \ if (ord[u] == -1) {\n                cnt++;\n                dfs1(u, k, e);\n\
    \                low[v] = std::min(low[v], low[u]);\n                if (pre !=\
    \ -1 and ord[v] <= low[u]) is_articulation[v] = true;\n                if (ord[v]\
    \ < low[u]) is_bridge[e] = true;\n            } else\n                low[v] =\
    \ std::min(low[v], ord[u]);\n        }\n        if (pre == -1 and cnt > 1) is_articulation[v]\
    \ = true;\n    }\n\n    void dfs2(int v, int pre) {\n        if (pre == -1) tecc[v]\
    \ = t++;\n        for (int& e : G[v]) {\n            if (e == pre) continue;\n\
    \            int u = es[e].first ^ es[e].second ^ v;\n            if (tecc[u]\
    \ == -1 or ord[u] < ord[v]) tmp.emplace_back(e);\n            if (tecc[u] >= 0)\
    \ continue;\n            if (ord[v] >= low[u])\n                tecc[u] = tecc[v];\n\
    \            else\n                tecc[u] = t++;\n            dfs2(u, e);\n \
    \           if (ord[v] <= low[u]) {\n                while (true) {\n        \
    \            int ne = tmp.back();\n                    tmp.pop_back();\n     \
    \               bcc[ne] = b;\n                    if (ne == e) break;\n      \
    \          }\n                b++;\n            }\n        }\n    }\n};\n#line\
    \ 5 \"test/yosupo/two_edge_connected_components.test.cpp\"\n\nint main() {\n \
    \   std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    int N, M;\n \
    \   std::cin >> N >> M;\n    LowLink G(N);\n    for (; M--;) {\n        int a,\
    \ b;\n        std::cin >> a >> b;\n        G.add_edge(a, b);\n    }\n\n    G.build();\n\
    \    auto& tecc = G.tecc;\n    int K = G.t;\n    std::vector<std::vector<int>>\
    \ ans(K);\n    for (int i = 0; i < N; i++) ans[tecc[i]].emplace_back(i);\n   \
    \ std::cout << K << '\\n';\n    for (int i = 0; i < K; i++) {\n        std::cout\
    \ << ans[i].size();\n        for (int& v : ans[i]) std::cout << ' ' << v;\n  \
    \      std::cout << '\\n';\n    }\n}\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include <iostream>\n#include \"graph/LowLink.hpp\"\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    int N, M;\n    std::cin >> N >> M;\n\
    \    LowLink G(N);\n    for (; M--;) {\n        int a, b;\n        std::cin >>\
    \ a >> b;\n        G.add_edge(a, b);\n    }\n\n    G.build();\n    auto& tecc\
    \ = G.tecc;\n    int K = G.t;\n    std::vector<std::vector<int>> ans(K);\n   \
    \ for (int i = 0; i < N; i++) ans[tecc[i]].emplace_back(i);\n    std::cout <<\
    \ K << '\\n';\n    for (int i = 0; i < K; i++) {\n        std::cout << ans[i].size();\n\
    \        for (int& v : ans[i]) std::cout << ' ' << v;\n        std::cout << '\\\
    n';\n    }\n}"
  dependsOn:
  - graph/LowLink.hpp
  isVerificationFile: true
  path: test/yosupo/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2022-12-30 22:22:43+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_edge_connected_components.test.cpp
- /verify/test/yosupo/two_edge_connected_components.test.cpp.html
title: test/yosupo/two_edge_connected_components.test.cpp
---
