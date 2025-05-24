---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/optimization/hungarian.hpp
    title: Hungarian (Assignment Problem)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/assignment
    links:
    - https://judge.yosupo.jp/problem/assignment
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: optimization/hungarian.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include\
    \ <iostream>\n#include \"optimization/hungarian.hpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int N;\n    std::cin >> N;\n    std::vector a(N,\
    \ std::vector<long long>(N));\n    for (int i = 0; i < N; i++) {\n        for\
    \ (int j = 0; j < N; j++) {\n            std::cin >> a[i][j];\n        }\n   \
    \ }\n    auto [X, p] = hungarian(a);\n    std::cout << X << '\\n';\n    for (int\
    \ i = 0; i < N; i++) std::cout << p[i] << (i + 1 == N ? '\\n' : ' ');\n    return\
    \ 0;\n}"
  dependsOn:
  - src/optimization/hungarian.hpp
  isVerificationFile: true
  path: test/yosupo/assignment.test.cpp
  requiredBy: []
  timestamp: '2024-06-01 01:35:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/assignment.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/assignment.test.cpp
- /verify/test/yosupo/assignment.test.cpp.html
title: test/yosupo/assignment.test.cpp
---
