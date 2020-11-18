---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: flow/Dinic.hpp
    title: Dinic
  - icon: ':heavy_check_mark:'
    path: flow/ProjectSelectionProblem.hpp
    title: Project Selection Problem
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/arc085/tasks/arc085_c
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/ProjectSelectionProblem.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define IGNORE\n\n#define PROBLEM \"https://atcoder.jp/contests/arc085/tasks/arc085_c\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../flow/ProjectSelectionProblem.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    const\
    \ long long inf=1e18;\n    int N; cin >> N;\n\n    ProjectSelectionProblem<long\
    \ long> PSP(N);\n    for (int i=1;i<=N;++i){\n        int a; cin >> a;\n     \
    \   if (a>0) PSP.x_false_profit(i-1,a);\n        else PSP.x_false_loss(i-1,-a);\n\
    \        for (int j=2*i;j<=N;j+=i){\n            PSP.x_true_y_false_loss(i-1,j-1,inf);\n\
    \        }\n    }\n\n    cout << -PSP.build() << '\\n';\n}"
  dependsOn:
  - base.hpp
  - flow/ProjectSelectionProblem.hpp
  - flow/Dinic.hpp
  isVerificationFile: false
  path: test/atcoder/arc085_c.cpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/arc085_c.cpp
layout: document
redirect_from:
- /library/test/atcoder/arc085_c.cpp
- /library/test/atcoder/arc085_c.cpp.html
title: test/atcoder/arc085_c.cpp
---
