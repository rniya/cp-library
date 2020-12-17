---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/TwoEdgeConnectedComponents.hpp
    title: Two Edge Connected Components
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/TwoEdgeConnectedComponents.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../graph/TwoEdgeConnectedComponents.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,M;\
    \ cin >> N >> M;\n\n    TwoEdgeConnectedComponents TECC(N);\n    for (int i=0;i<M;++i){\n\
    \        int a,b; cin >> a >> b;\n        TECC.add_edge(a,b);\n    }\n\n    int\
    \ K=TECC.build();\n    cout << K << '\\n';\n    for (int i=0;i<K;++i){\n     \
    \   cout << TECC.C[i].size();\n        for (int v:TECC.C[i]) cout << ' ' << v;\n\
    \        cout << '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - graph/TwoEdgeConnectedComponents.hpp
  isVerificationFile: true
  path: test/yosupo/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_edge_connected_components.test.cpp
- /verify/test/yosupo/two_edge_connected_components.test.cpp.html
title: test/yosupo/two_edge_connected_components.test.cpp
---
