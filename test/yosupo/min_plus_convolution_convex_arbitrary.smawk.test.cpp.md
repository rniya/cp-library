---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/optimization/smawk.hpp
    title: SMAWK Algotirhm
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: optimization/smawk.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/min_plus_convolution_convex_arbitrary\"\
    \n\n#include <cassert>\n#include <iostream>\n#include \"optimization/smawk.hpp\"\
    \n\ntemplate <typename T>\nstd::vector<T> min_plus_convolution_convex_arbitrary(const\
    \ std::vector<T>& a, const std::vector<T>& b) {\n    int n = a.size(), m = b.size();\n\
    \    assert(n and m);\n    for (int i = 0; i + 2 < n; i++) assert(a[i + 1] - a[i]\
    \ <= a[i + 2] - a[i + 1]);\n    auto f = [&](int i, int j) { return a[i - j] +\
    \ b[j]; };\n    auto select = [&](int i, int j, int k) {\n        if (i < k) return\
    \ false;\n        if (n <= i - j) return true;\n        return f(i, j) >= f(i,\
    \ k);\n    };\n    auto argmin = smawk(n + m - 1, m, select);\n    std::vector<T>\
    \ c(n + m - 1);\n    for (int i = 0; i < n + m - 1; i++) c[i] = f(i, argmin[i]);\n\
    \    return c;\n}\n\nint main() {\n    std::ios::sync_with_stdio(false);\n   \
    \ std::cin.tie(nullptr);\n    int N, M;\n    std::cin >> N >> M;\n    std::vector<int>\
    \ a(N), b(M);\n    for (int i = 0; i < N; i++) std::cin >> a[i];\n    for (int\
    \ i = 0; i < M; i++) std::cin >> b[i];\n    auto c = min_plus_convolution_convex_arbitrary(a,\
    \ b);\n    for (int i = 0; i < N + M - 1; i++) std::cout << c[i] << (i + 1 ==\
    \ N + M - 1 ? '\\n' : ' ');\n    return 0;\n}"
  dependsOn:
  - src/optimization/smawk.hpp
  isVerificationFile: true
  path: test/yosupo/min_plus_convolution_convex_arbitrary.smawk.test.cpp
  requiredBy: []
  timestamp: '2024-06-01 01:35:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/min_plus_convolution_convex_arbitrary.smawk.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/min_plus_convolution_convex_arbitrary.smawk.test.cpp
- /verify/test/yosupo/min_plus_convolution_convex_arbitrary.smawk.test.cpp.html
title: test/yosupo/min_plus_convolution_convex_arbitrary.smawk.test.cpp
---
