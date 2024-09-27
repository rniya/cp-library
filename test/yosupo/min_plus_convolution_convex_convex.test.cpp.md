---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/convolution/min_plus_convolution_convex_convex.hpp
    title: Min Plus Convolution (Convex and Convex)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex
    links:
    - https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convolution/min_plus_convolution_convex_convex.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_convex\"\
    \n\n#include \"convolution/min_plus_convolution_convex_convex.hpp\"\n#include\
    \ <iostream>\n\nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int N, M;\n    std::cin >> N >> M;\n    std::vector<int> a(N), b(M);\n  \
    \  for (int i = 0; i < N; i++) std::cin >> a[i];\n    for (int i = 0; i < M; i++)\
    \ std::cin >> b[i];\n    auto c = min_plus_convolution_convex_convex(a, b);\n\
    \    for (int i = 0; i < N + M - 1; i++) std::cout << c[i] << (i + 1 == N + M\
    \ - 1 ? '\\n' : ' ');\n    return 0;\n}"
  dependsOn:
  - src/convolution/min_plus_convolution_convex_convex.hpp
  isVerificationFile: true
  path: test/yosupo/min_plus_convolution_convex_convex.test.cpp
  requiredBy: []
  timestamp: '2024-06-01 02:28:17+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/min_plus_convolution_convex_convex.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/min_plus_convolution_convex_convex.test.cpp
- /verify/test/yosupo/min_plus_convolution_convex_convex.test.cpp.html
title: test/yosupo/min_plus_convolution_convex_convex.test.cpp
---
