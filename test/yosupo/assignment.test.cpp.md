---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/hungarian.hpp
    title: "Hungarian\uFF08\u5272\u5F53\u554F\u984C\uFF0C\u4E8C\u90E8\u30B0\u30E9\u30D5\
      \u306E\u6700\u5C0F\u91CD\u307F\u5B8C\u5168\u30DE\u30C3\u30C1\u30F3\u30B0\uFF09"
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/hungarian.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/assignment\"\n\n#include\
    \ <iostream>\n#include \"graph/hungarian.hpp\"\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int N;\n    std::cin >> N;\n    std::vector a(N,\
    \ std::vector<long long>(N));\n    for (int i = 0; i < N; i++) {\n        for\
    \ (int j = 0; j < N; j++) {\n            std::cin >> a[i][j];\n        }\n   \
    \ }\n    auto [X, p] = hungarian(a);\n    std::cout << X << '\\n';\n    for (int\
    \ i = 0; i < N; i++) std::cout << p[i] << (i + 1 == N ? '\\n' : ' ');\n    return\
    \ 0;\n}"
  dependsOn:
  - src/graph/hungarian.hpp
  isVerificationFile: true
  path: test/yosupo/assignment.test.cpp
  requiredBy: []
  timestamp: '2023-10-01 16:26:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/assignment.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/assignment.test.cpp
- /verify/test/yosupo/assignment.test.cpp.html
title: test/yosupo/assignment.test.cpp
---
