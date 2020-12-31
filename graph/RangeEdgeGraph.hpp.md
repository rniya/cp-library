---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/nikkei2019_2_qual_d.cpp
    title: test/atcoder/nikkei2019_2_qual_d.cpp
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/graph/RangeEdgeGraph.md
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/RangeEdgeGraph.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief\n * @docs docs/graph/RangeEdgeGraph.md\n */\n\n#pragma once\n\
    \n#include \"../base.hpp\"\n\ntemplate<typename T>\nclass RangeEdgeGraph{\n  \
    \  struct edge{\n        int to; T cost;\n        edge(int to,T cost):to(to),cost(cost){}\n\
    \        bool operator<(const edge &rhs) const {return cost>rhs.cost;}\n    };\n\
    \    int n;\n    vector<vector<edge>> G;\n    void add_edge(int u,int v,T cost){G[(3*n<=u?u-2*n:u)].emplace_back(v,cost);}\n\
    \npublic:\n    RangeEdgeGraph(int n):n(n),G(3*n){\n        for (int i=1;i<n;++i){\n\
    \            int l=i<<1|0,r=i<<1|1;\n            add_edge(i,l,0);\n          \
    \  add_edge(i,r,0);\n            add_edge(l+2*n,i+2*n,0);\n            add_edge(r+2*n,i+2*n,0);\n\
    \        }\n    }\n    void add_edge(int l1,int r1,int l2,int r2,T cost){\n  \
    \      int add=G.size();\n        G.emplace_back();\n        for (l1+=n,r1+=n;l1<r1;l1>>=1,r1>>=1){\n\
    \            if (l1&1) add_edge((l1++)+2*n,add,0);\n            if (r1&1) add_edge((--r1)+2*n,add,0);\n\
    \        }\n        for (l2+=n,r2+=n;l2<r2;l2>>=1,r2>>=1){\n            if (l2&1)\
    \ G[add].emplace_back(l2++,cost);\n            if (r2&1) G[add].emplace_back(--r2,cost);\n\
    \        }\n    }\n    vector<T> build(int s){\n        vector<T> dp(G.size(),numeric_limits<T>::max());\n\
    \        s+=n; dp[s]=0;\n        priority_queue<edge> pq;\n        pq.emplace(s,dp[s]);\n\
    \        while (!pq.empty()){\n            auto p=pq.top(); pq.pop();\n      \
    \      int v=p.to;\n            if (dp[v]<p.cost) continue;\n            for (const\
    \ auto &e:G[v]){\n                int u=e.to;\n                if (dp[v]+e.cost<dp[u]){\n\
    \                    dp[u]=dp[v]+e.cost;\n                    pq.emplace(u,dp[u]);\n\
    \                }\n            }\n        }\n        vector<T> res(dp.begin()+n,dp.begin()+2*n);\n\
    \        return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: graph/RangeEdgeGraph.hpp
  requiredBy:
  - test/atcoder/nikkei2019_2_qual_d.cpp
  timestamp: '2020-12-31 12:31:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: graph/RangeEdgeGraph.hpp
layout: document
redirect_from:
- /library/graph/RangeEdgeGraph.hpp
- /library/graph/RangeEdgeGraph.hpp.html
title: graph/RangeEdgeGraph.hpp
---
## 概要
区間から区間に辺が伸びるようなグラフ上での最短路を計算する. Segment Treeの構造を利用して頂点数$3n+q$, 辺数$4n+q\log n$のグラフを構成している.

- 'add_edge(l1,r1,l2,r2,cost)'：$[l1,r1)$から$[l2,r2)$に対して伸びる重み$cost$の辺を追加する.
- 'build(s)'：$s$を始点にしたときの各点までの最短距離を計算する.

## 計算量
- 'add_edge(l1,r1,l2,r2,cost)'：$O(\log n)$
- 'build(s)'：$O(n+q\log n)\log(n+q)$

## 参照
[区間に辺を張るテクの実装例（Dijkstra法セット）と使用例 - Lorent’s diary](https://atcoder.jp/contests/nikkei2019-2-qual/tasks/nikkei2019_2_qual_d)