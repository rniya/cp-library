---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/StronglyConnectedComponents.hpp
    title: Strongly Connected Components
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/StronglyConnectedComponents.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include \"../../base.hpp\"\
    \n#include \"../../graph/StronglyConnectedComponents.hpp\"\n\nint main(){\n  \
    \  cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,M; cin >> N >> M;\n\
    \n    StronglyConnectedComponents SCC(N);\n    for (int i=0;i<M;++i){\n      \
    \  int a,b; cin >> a >> b;\n        SCC.add_edge(a,b);\n    }\n\n    int K=SCC.build();\n\
    \    cout << K << '\\n';\n    for (int i=0;i<K;++i){\n        cout << SCC.C[i].size();\n\
    \        for (int v:SCC.C[i]) cout << ' ' << v;\n        cout << '\\n';\n    }\n\
    }"
  dependsOn:
  - base.hpp
  - graph/StronglyConnectedComponents.hpp
  isVerificationFile: true
  path: test/yosupo/scc.test.cpp
  requiredBy: []
  timestamp: '2020-09-12 20:51:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/scc.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/scc.test.cpp
- /verify/test/yosupo/scc.test.cpp.html
title: test/yosupo/scc.test.cpp
---
