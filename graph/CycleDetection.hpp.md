---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2891.test.cpp
    title: test/aoj/2891.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_4_A.test.cpp
    title: test/aoj/GRL_4_A.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/CycleDetection.hpp
    document_title: Cycle Detection
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/CycleDetection.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Cycle Detection\n * @docs docs/graph/CycleDetection.hpp\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<bool directed>\n\
    struct CycleDetection{\n    vector<vector<int>> G;\n    vector<int> seen,finished;\n\
    \    stack<int> hist;\n    int pos;\n    CycleDetection(int n):G(n),seen(n,0),finished(n,0),pos(-1){}\n\
    \    void add_edge(int u,int v){\n        G[u].emplace_back(v);\n    }\n    void\
    \ dfs(int v,int p){\n        seen[v]=1; hist.emplace(v);\n        for (int u:G[v]){\n\
    \            if (!directed&&u==p) continue;\n            if (finished[u]) continue;\n\
    \            if (seen[u]&&!finished[u]){pos=u; return;}\n            dfs(u,v);\n\
    \            if (~pos) return;\n        }\n        finished[v]=1; hist.pop();\n\
    \    }\n    vector<int> build(){\n        for (int v=0;v<G.size();++v){\n    \
    \        if (!seen[v]) dfs(v,-1);\n            if (~pos) break;\n        }\n \
    \       vector<int> res;\n        while(!hist.empty()){\n            int t=hist.top();\
    \ hist.pop();\n            res.emplace_back(t);\n            if (t==pos) break;\n\
    \        }\n        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/CycleDetection.hpp
  requiredBy: []
  timestamp: '2020-09-10 14:24:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_4_A.test.cpp
  - test/aoj/2891.test.cpp
documentation_of: graph/CycleDetection.hpp
layout: document
redirect_from:
- /library/graph/CycleDetection.hpp
- /library/graph/CycleDetection.hpp.html
title: Cycle Detection
---
