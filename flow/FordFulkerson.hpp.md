---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/GRL_6_A.test.cpp
    title: test/aoj/GRL_6_A.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/FordFulkerson.hpp
    document_title: Ford Fulkerson
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/FordFulkerson.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Ford Fulkerson\n * @docs docs/flow/FordFulkerson.hpp\n */\n\
    \n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T,bool directed>\n\
    struct FordFulkerson{\n    struct edge{\n        int to,rev; T cap;\n        edge(int\
    \ to,T cap,int rev):to(to),cap(cap),rev(rev){}\n    };\n    vector<vector<edge>>\
    \ G;\n    vector<pair<int,int>> pos;\n    vector<int> used;\n    FordFulkerson(int\
    \ n):G(n),used(n){}\n    int add_edge(int from,int to,T cap){\n        pos.emplace_back(from,G[from].size());\n\
    \        G[from].emplace_back(to,cap,G[to].size());\n        G[to].emplace_back(from,directed?0:cap,G[from].size()-1);\n\
    \        return pos.size()-1;\n    }\n    tuple<int,int,int,int> get_edge(int\
    \ i){\n        auto e=G[pos[i].first][pos[i].second];\n        auto re=G[e.to][e.rev];\n\
    \        return {pos[i].first,e.to,e.cap+re.cap,re.cap};\n    }\n    vector<tuple<int,int,int,int>>\
    \ edges(){\n        vector<tuple<int,int,int,int>> res;\n        for (int i=0;i<pos.size();++i){\n\
    \            res.emplace_back(get_edge(i));\n        }\n        return res;\n\
    \    }\n    T dfs(int v,int t,T f){\n        if (v==t) return f;\n        used[v]=true;\n\
    \        for (auto &e:G[v]){\n            if (!used[e.to]&&e.cap>0){\n       \
    \         T d=dfs(e.to,t,min(f,e.cap));\n                if (d<=0) continue;\n\
    \                e.cap-=d;\n                G[e.to][e.rev].cap+=d;\n         \
    \       return d;\n            }\n        }\n        return 0;\n    }\n    T max_flow(int\
    \ s,int t,T lim){\n        T flow=0;\n        while(lim>0){\n            fill(used.begin(),used.end(),0);\n\
    \            T f=dfs(s,t,lim);\n            if (f==0) break;\n            flow+=f;\
    \ lim-=f;\n        }\n        return flow;\n    }\n    T max_flow(int s,int t){\n\
    \        return max_flow(s,t,numeric_limits<T>::max());\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: flow/FordFulkerson.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/GRL_6_A.test.cpp
documentation_of: flow/FordFulkerson.hpp
layout: document
redirect_from:
- /library/flow/FordFulkerson.hpp
- /library/flow/FordFulkerson.hpp.html
title: Ford Fulkerson
---
