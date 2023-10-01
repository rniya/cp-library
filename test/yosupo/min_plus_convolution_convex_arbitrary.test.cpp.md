---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/algorithm/min_plus_convolution_convex_arbitrary.hpp
    title: Min Plus Convolution (Convex and Arbitary)
  - icon: ':heavy_check_mark:'
    path: src/algorithm/monotone_minima.hpp
    title: monotone minima
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
    links:
    - https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: algorithm/min_plus_convolution_convex_arbitrary.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n\n#include \"algorithm/min_plus_convolution_convex_arbitrary.hpp\"\n#include\
    \ <iostream>\n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int N, M;\n    std::cin >> N >> M;\n    std::vector<int> a(N), b(M);\n  \
    \  for (int i = 0; i < N; i++) std::cin >> a[i];\n    for (int i = 0; i < M; i++)\
    \ std::cin >> b[i];\n    auto c = min_plus_convolution_convex_arbitrary(a, b);\n\
    \    for (int i = 0; i < N + M - 1; i++) std::cout << c[i] << (i + 1 == N + M\
    \ - 1 ? '\\n' : ' ');\n    return 0;\n}"
  dependsOn:
  - src/algorithm/min_plus_convolution_convex_arbitrary.hpp
  - src/algorithm/monotone_minima.hpp
  isVerificationFile: true
  path: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
  requiredBy: []
  timestamp: '2023-10-01 16:26:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
- /verify/test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp.html
title: test/yosupo/min_plus_convolution_convex_arbitrary.test.cpp
---
