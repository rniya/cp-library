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
    PROBLEM: https://judge.yosupo.jp/problem/jump_on_tree
    links:
    - https://judge.yosupo.jp/problem/jump_on_tree
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/jump_on_tree\"\n\n#include\
    \ <iostream>\n#include \"tree/HeavyLightDecomposition.hpp\"\n\nint main() {\n\
    \    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    int N, Q;\n\
    \    std::cin >> N >> Q;\n    HeavyLightDecomposition HLD(N);\n    for (int i\
    \ = 0; i < N - 1; i++) {\n        int a, b;\n        std::cin >> a >> b;\n   \
    \     HLD.add_edge(a, b);\n    }\n\n    HLD.build();\n    for (; Q--;) {\n   \
    \     int s, t, i;\n        std::cin >> s >> t >> i;\n        std::cout << HLD.jump(s,\
    \ t, i) << '\\n';\n    }\n    return 0;\n}"
  dependsOn:
  - src/tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/yosupo/jump_on_tree.test.cpp
  requiredBy: []
  timestamp: '2024-08-27 15:05:21+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/jump_on_tree.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/jump_on_tree.test.cpp
- /verify/test/yosupo/jump_on_tree.test.cpp.html
title: test/yosupo/jump_on_tree.test.cpp
---
