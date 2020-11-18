---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/Dijkstra.hpp
    title: Dijkstra
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shortest_path
    links:
    - https://judge.yosupo.jp/problem/shortest_path
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/Dijkstra.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shortest_path\"\n\n#include\
    \ \"../../base.hpp\"\n#include \"../../graph/Dijkstra.hpp\"\n\nint main(){\n \
    \   cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,M,s,t; cin >> N >>\
    \ M >> s >> t;\n\n    Dijkstra<long long> D(N);\n    for (int i=0;i<M;++i){\n\
    \        int a,b,c; cin >> a >> b >> c;\n        D.add_edge(a,b,c);\n    }\n\n\
    \    D.build(s);\n    vector<int> ans=D.restore(t);\n    if (ans.empty()){cout\
    \ << -1 << '\\n'; return 0;}\n    cout << D[t] << ' ' << ans.size()-1 << '\\n';\n\
    \    for (int i=0;i+1<ans.size();++i){\n        cout << ans[i] << ' ' << ans[i+1]\
    \ << '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - graph/Dijkstra.hpp
  isVerificationFile: true
  path: test/yosupo/shortest_path.test.cpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/shortest_path.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/shortest_path.test.cpp
- /verify/test/yosupo/shortest_path.test.cpp.html
title: test/yosupo/shortest_path.test.cpp
---
