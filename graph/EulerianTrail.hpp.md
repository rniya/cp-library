---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/codeforces/1361_C.cpp
    title: test/codeforces/1361_C.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/583.test.cpp
    title: test/yukicoder/583.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/graph/EulerianTrail.md
    document_title: "\u30AA\u30A4\u30E9\u30FC\u30B0\u30E9\u30D5\u30FB\u6E96\u30AA\u30A4\
      \u30E9\u30FC\u30B0\u30E9\u30D5\u306E\u69CB\u7BC9"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/EulerianTrail.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u30AA\u30A4\u30E9\u30FC\u30B0\u30E9\u30D5\u30FB\u6E96\u30AA\
    \u30A4\u30E9\u30FC\u30B0\u30E9\u30D5\u306E\u69CB\u7BC9\n * @docs docs/graph/EulerianTrail.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<bool directed>\n\
    struct EulerianTrail{\n    vector<vector<pair<int,int>>> G;\n    vector<vector<int>>\
    \ BG;\n    vector<pair<int,int>> es;\n    vector<int> used,visited,deg;\n    EulerianTrail(int\
    \ n):G(n),BG(n),visited(n,0),deg(n,0){}\n    void add_edge(int u,int v){\n   \
    \     int m=es.size();\n        es.emplace_back(u,v);\n        used.emplace_back(0);\n\
    \        BG[u].emplace_back(v);\n        BG[v].emplace_back(u);\n        G[u].emplace_back(v,m);\n\
    \        ++deg[u];\n        if (directed) --deg[v];\n        else G[v].emplace_back(u,m),++deg[v];\n\
    \    }\n    void dfs(int v,int &s,int &t,int &check){\n        visited[v]=1;\n\
    \        if (directed){\n            if (abs(deg[v])>1) check=0;\n           \
    \ else if (deg[v]==1){\n                if (~s) check=0;\n                else\
    \ s=v;\n            }\n        } else {\n            if (deg[v]&1){\n        \
    \        if (s<0) s=v;\n                else if (t<0) t=v;\n                else\
    \ check=0;\n            }\n        }\n        for (int u:BG[v]){\n           \
    \ if (visited[u]) continue;\n            dfs(u,s,t,check);\n        }\n    }\n\
    \    vector<int> go(int s){\n        stack<pair<int,int>> st;\n        vector<int>\
    \ ord;\n        st.emplace(s,-1);\n        while(!st.empty()){\n            int\
    \ v=st.top().first;\n            visited[v]=1;\n            if (G[v].empty()){\n\
    \                ord.emplace_back(st.top().second);\n                st.pop();\n\
    \            } else {\n                auto e=G[v].back(); G[v].pop_back();\n\
    \                if (used[e.second]) continue;\n                used[e.second]=1;\n\
    \                st.emplace(e);\n            }\n        }\n        ord.pop_back();\n\
    \        reverse(ord.begin(),ord.end());\n        return ord;\n    }\n    vector<vector<int>>\
    \ build(){\n        for (int i=0;i<G.size();++i){\n            if (directed&&deg[i]!=0)\
    \ return {};\n            if (!directed&&(deg[i]&1)) return {};\n        }\n \
    \       vector<vector<int>> res;\n        for (int i=0;i<G.size();++i){\n    \
    \        if (G[i].empty()||visited[i]) continue;\n            res.emplace_back(go(i));\n\
    \        }\n        return res;\n    }\n    vector<vector<int>> build_semi(){\n\
    \        vector<vector<int>> res;\n        for (int i=0;i<G.size();++i){\n   \
    \         if (visited[i]) continue;\n            int s=-1,t=-1,check=1;\n    \
    \        dfs(i,s,t,check);\n            if (!check) return {};\n            res.emplace_back(go(~s?s:i));\n\
    \            if (res.back().empty()) res.pop_back();\n        }\n        return\
    \ res;\n    }\n    pair<int,int> operator[](int i){return es[i];}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/EulerianTrail.hpp
  requiredBy:
  - test/codeforces/1361_C.cpp
  timestamp: '2020-09-11 16:00:32+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/583.test.cpp
documentation_of: graph/EulerianTrail.hpp
layout: document
redirect_from:
- /library/graph/EulerianTrail.hpp
- /library/graph/EulerianTrail.hpp.html
title: "\u30AA\u30A4\u30E9\u30FC\u30B0\u30E9\u30D5\u30FB\u6E96\u30AA\u30A4\u30E9\u30FC\
  \u30B0\u30E9\u30D5\u306E\u69CB\u7BC9"
---
## 概要

## 計算量