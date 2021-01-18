---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':x:'
    path: datastructure/BinaryIndexedTree.hpp
    title: Binary Indexed Tree
  - icon: ':x:'
    path: tree/EulerTourforEdge.hpp
    title: "Euler Tour (\u30D1\u30B9\u306B\u5BFE\u3059\u308B\u64CD\u4F5C)"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/BinaryIndexedTree.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/5/GRL_5_D\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/BinaryIndexedTree.hpp\"\
    \n#include \"../../tree/EulerTourforEdge.hpp\"\n\nint main(){\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    int n; cin >> n;\n\n    EulerTourforEdge\
    \ ET(n);\n    for (int i=0;i<n;++i){\n        int k; cin >> k;\n        for (;k--;){\n\
    \            int c; cin >> c;\n            ET.add_edge(i,c);\n        }\n    }\n\
    \n    ET.build();\n    BinaryIndexedTree<int> BIT(2*n);\n    auto f=[&](int l,int\
    \ r){return BIT.query(l,r);};\n    auto g=[&](int k,int w){BIT.add(k,w);};\n\n\
    \    int q; cin >> q;\n    for (;q--;){\n        int t; cin >> t;\n        if\
    \ (!t){\n            int v,w; cin >> v >> w;\n            ET.update(v,w,g);\n\
    \        } else {\n            int u; cin >> u;\n            cout << ET.query<int>(u,f)\
    \ << '\\n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/BinaryIndexedTree.hpp
  - tree/EulerTourforEdge.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_D.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 00:11:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/GRL_5_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_D.test.cpp
- /verify/test/aoj/GRL_5_D.test.cpp.html
title: test/aoj/GRL_5_D.test.cpp
---
