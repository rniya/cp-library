---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: graph/StronglyConnectedComponents.hpp
    title: Strongly Connected Components
  - icon: ':heavy_check_mark:'
    path: graph/TwoSatisfiability.hpp
    title: 2-SAT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ graph/StronglyConnectedComponents.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include \"\
    ../../base.hpp\"\n#include \"../../graph/StronglyConnectedComponents.hpp\"\n#include\
    \ \"../../graph/TwoSatisfiability.hpp\"\n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    string p,cnf; cin >> p >> cnf;\n    int N,M; cin >> N >> M;\n\n    TwoSatisfiability\
    \ TS(N+1);\n    for (int i=0;i<M;++i){\n        int a,b,c; cin >> a >> b >> c;\n\
    \        TS.add_or((a<0?TS.neg(-a):a),(b<0?TS.neg(-b):b));\n    }\n\n    vector<int>\
    \ ans=TS.build();\n    if (ans.empty()){cout << \"s UNSATISFIABLE\" << '\\n';\
    \ return 0;}\n    cout << \"s SATISFIABLE\" << '\\n';\n    cout << \"v \";\n \
    \   for (int i=1;i<=N;++i) cout << (ans[i]?i:-i) << ' ';\n    cout << \"0\\n\"\
    ;\n}"
  dependsOn:
  - base.hpp
  - graph/StronglyConnectedComponents.hpp
  - graph/TwoSatisfiability.hpp
  isVerificationFile: true
  path: test/yosupo/two_sat.test.cpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_sat.test.cpp
- /verify/test/yosupo/two_sat.test.cpp.html
title: test/yosupo/two_sat.test.cpp
---
