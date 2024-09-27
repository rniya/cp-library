---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: tree/HeavyLightDecomposition.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/GRL_5_C\"\n\n\
    #include <iostream>\n#include \"tree/HeavyLightDecomposition.hpp\"\n\nint main()\
    \ {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    int n;\n\
    \    std::cin >> n;\n    HeavyLightDecomposition HLD(n);\n    for (int i = 0;\
    \ i < n; i++) {\n        int k;\n        std::cin >> k;\n        for (; k--;)\
    \ {\n            int c;\n            std::cin >> c;\n            HLD.add_edge(i,\
    \ c);\n        }\n    }\n    HLD.build();\n\n    int q;\n    std::cin >> q;\n\
    \    for (; q--;) {\n        int u, v;\n        std::cin >> u >> v;\n        std::cout\
    \ << HLD.lca(u, v) << '\\n';\n    }\n}"
  dependsOn:
  - src/tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/aoj/GRL_5_C.test.cpp
  requiredBy: []
  timestamp: '2024-08-27 15:05:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/GRL_5_C.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/GRL_5_C.test.cpp
- /verify/test/aoj/GRL_5_C.test.cpp.html
title: test/aoj/GRL_5_C.test.cpp
---
