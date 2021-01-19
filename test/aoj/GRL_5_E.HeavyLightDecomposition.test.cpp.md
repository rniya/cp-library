---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: datastructure/LazySegmentTree.hpp
    title: Lazy Segment Tree
  - icon: ':question:'
    path: tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ tree/HeavyLightDecomposition.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_E\"\n\n\
    #include \"../../base.hpp\"\n#include \"../../datastructure/LazySegmentTree.hpp\"\
    \n#include \"../../tree/HeavyLightDecomposition.hpp\"\n\nint main(){\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int n; cin >> n;\n\n    HeavyLightDecomposition\
    \ HLD(n);\n    for (int i=0;i<n;++i){\n        int k; cin >> k;\n        for (;k--;){\n\
    \            int c; cin >> c;\n            HLD.add_edge(i,c);\n        }\n   \
    \ }\n    HLD.build();\n\n    struct node{\n        long long a; int b;\n     \
    \   node(long long a,int b):a(a),b(b){}\n    };\n    auto f=[](node a,node b){return\
    \ node(a.a+b.a,a.b+b.b);};\n    auto g=[](node a,long long x){return node(a.a+x*a.b,a.b);};\n\
    \    auto h=[](long long a,long long b){return a+b;};\n    LazySegmentTree<node,long\
    \ long> seg(n,f,g,h,node(0,0),0);\n    vector<node> v(n,node(0,1));\n    seg.build(v);\n\
    \n    int q; cin >> q;\n    for (;q--;){\n        int t; cin >> t;\n        if\
    \ (!t){\n            int v; long long w; cin >> v >> w;\n            HLD.update_path(0,v,[&](int\
    \ l,int r){seg.update(l,r,w);},true);\n        } else {\n            int u; cin\
    \ >> u;\n            cout << HLD.query_path(0,u,0LL,[&](int l,int r){return seg.query(l,r).a;},h)\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/LazySegmentTree.hpp
  - tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 14:04:24+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
- /verify/test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp.html
title: test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
---
