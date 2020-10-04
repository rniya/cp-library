---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/SegmentTree.hpp
    title: Segment Tree
  - icon: ':heavy_check_mark:'
    path: tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_path_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_path_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/SegmentTree.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_path_sum\"\n\
    \n#include \"../../base.hpp\"\n#include \"../../datastructure/SegmentTree.hpp\"\
    \n#include \"../../tree/HeavyLightDecomposition.hpp\"\n\nint main(){\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int N,Q; cin >> N >> Q;\n    vector<long\
    \ long> a(N);\n    for (int i=0;i<N;++i) cin >> a[i];\n\n    HeavyLightDecomposition\
    \ HLD(N);\n    for (int i=0;i<N-1;++i){\n        int u,v; cin >> u >> v;\n   \
    \     HLD.add_edge(u,v);\n    }\n    HLD.build();\n\n    auto f=[](long long a,long\
    \ long b){return a+b;};\n    SegmentTree<long long> seg(N,f,0);\n    for (int\
    \ i=0;i<N;++i) HLD.update_path(i,i,[&](int l,int r){seg.update(l,a[i]);});\n\n\
    \    for (;Q--;){\n        int t; cin >> t;\n        if (!t){\n            int\
    \ p; long long x; cin >> p >> x;\n            HLD.update_path(p,p,[&](int l,int\
    \ r){seg.update(l,seg[l]+x);});\n        } else {\n            int u,v; cin >>\
    \ u >> v;\n            cout << HLD.query(u,v,0LL,[&](int l,int r){return seg.query(l,r);},f)\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/SegmentTree.hpp
  - tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_path_sum.test.cpp
  requiredBy: []
  timestamp: '2020-09-12 20:51:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_path_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_path_sum.test.cpp
- /verify/test/yosupo/vertex_add_path_sum.test.cpp.html
title: test/yosupo/vertex_add_path_sum.test.cpp
---
