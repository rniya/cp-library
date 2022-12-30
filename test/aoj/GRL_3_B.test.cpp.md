---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: graph/LowLink.hpp
    title: LowLink (with Two Edge Connected Components, Bi Connected Components)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B
  bundledCode: "#line 1 \"test/aoj/GRL_3_B.test.cpp\"\n#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B\"\
    \n\n#include <algorithm>\n#include <iostream>\n#line 2 \"graph/LowLink.hpp\"\n\
    #include <cassert>\n#include <utility>\n#include <vector>\n\nstruct LowLink {\n\
    \    int n, m = 0, t = 0, b = 0;\n    std::vector<std::vector<int>> G;\n    std::vector<std::pair<int,\
    \ int>> es;\n    std::vector<int> ord, low, tecc, bcc, tmp;\n    std::vector<bool>\
    \ is_articulation, is_bridge;\n\n    LowLink(int n) : n(n), G(n), ord(n, -1),\
    \ low(n), tecc(n, -1), is_articulation(n, false) {}\n\n    void add_edge(int u,\
    \ int v) {\n        assert(0 <= u and u < n);\n        assert(0 <= v and v < n);\n\
    \        G[u].emplace_back(m);\n        G[v].emplace_back(m);\n        es.emplace_back(u,\
    \ v);\n        is_bridge.emplace_back(false);\n        bcc.emplace_back();\n \
    \       m++;\n    }\n\n    void build() {\n        for (int i = 0; i < n; i++)\
    \ {\n            if (ord[i] != -1) continue;\n            dfs1(i, 0, -1);\n  \
    \          dfs2(i, -1);\n        }\n    }\n\n    std::pair<int, int> operator[](int\
    \ k) const { return es[k]; }\n\nprivate:\n    void dfs1(int v, int k, int pre)\
    \ {\n        ord[v] = k++, low[v] = ord[v];\n        int cnt = 0;\n        for\
    \ (int& e : G[v]) {\n            if (e == pre) continue;\n            int u =\
    \ es[e].first ^ es[e].second ^ v;\n            if (ord[u] == -1) {\n         \
    \       cnt++;\n                dfs1(u, k, e);\n                low[v] = std::min(low[v],\
    \ low[u]);\n                if (pre != -1 and ord[v] <= low[u]) is_articulation[v]\
    \ = true;\n                if (ord[v] < low[u]) is_bridge[e] = true;\n       \
    \     } else\n                low[v] = std::min(low[v], ord[u]);\n        }\n\
    \        if (pre == -1 and cnt > 1) is_articulation[v] = true;\n    }\n\n    void\
    \ dfs2(int v, int pre) {\n        if (pre == -1) tecc[v] = t++;\n        for (int&\
    \ e : G[v]) {\n            if (e == pre) continue;\n            int u = es[e].first\
    \ ^ es[e].second ^ v;\n            if (tecc[u] == -1 or ord[u] < ord[v]) tmp.emplace_back(e);\n\
    \            if (tecc[u] >= 0) continue;\n            if (ord[v] >= low[u])\n\
    \                tecc[u] = tecc[v];\n            else\n                tecc[u]\
    \ = t++;\n            dfs2(u, e);\n            if (ord[v] <= low[u]) {\n     \
    \           while (true) {\n                    int ne = tmp.back();\n       \
    \             tmp.pop_back();\n                    bcc[ne] = b;\n            \
    \        if (ne == e) break;\n                }\n                b++;\n      \
    \      }\n        }\n    }\n};\n#line 6 \"test/aoj/GRL_3_B.test.cpp\"\n\nint main()\
    \ {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    int V, E;\n\
    \    std::cin >> V >> E;\n    LowLink G(V);\n    for (; E--;) {\n        int s,\
    \ t;\n        std::cin >> s >> t;\n        if (s > t) std::swap(s, t);\n     \
    \   G.add_edge(s, t);\n    }\n\n    G.build();\n    std::vector<std::pair<int,\
    \ int>> ans;\n    for (int i = 0; i < E; i++) {\n        if (G.is_bridge[i]) {\n\
    \            ans.emplace_back(G[i]);\n        }\n    }\n    std::sort(ans.begin(),\
    \ ans.end());\n    for (auto& e : ans) std::cout << e.first << ' ' << e.second\
    \ << '\\n';\n    return 0;\n}\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/3/GRL_3_B\"\
    \n\n#include <algorithm>\n#include <iostream>\n#include \"graph/LowLink.hpp\"\n\
    \nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int V, E;\n    std::cin >> V >> E;\n    LowLink G(V);\n    for (; E--;) {\n\
    \        int s, t;\n        std::cin >> s >> t;\n        if (s > t) std::swap(s,\
    \ t);\n        G.add_edge(s, t);\n    }\n\n    G.build();\n    std::vector<std::pair<int,\
    \ int>> ans;\n    for (int i = 0; i < E; i++) {\n        if (G.is_bridge[i]) {\n\
    \            ans.emplace_back(G[i]);\n        }\n    }\n    std::sort(ans.begin(),\
    \ ans.end());\n    for (auto& e : ans) std::cout << e.first << ' ' << e.second\
    \ << '\\n';\n    return 0;\n}"
  dependsOn:
  - graph/LowLink.hpp
  isVerificationFile: true
  path: test/aoj/GRL_3_B.test.cpp
  requiredBy: []
  timestamp: '2022-12-30 22:31:33+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_3_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_3_B.test.cpp
- /verify/test/aoj/GRL_3_B.test.cpp.html
title: test/aoj/GRL_3_B.test.cpp
---
