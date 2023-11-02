---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/polynomial/shift_of_sampling_points_of_polynomial.hpp
    title: Shift of Sampling Points of Polynomial
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial
    links:
    - https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: polynomial/shift_of_sampling_points_of_polynomial.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/shift_of_sampling_points_of_polynomial\"\
    \n\n#include \"polynomial/shift_of_sampling_points_of_polynomial.hpp\"\n#include\
    \ <iostream>\n\nusing mint = atcoder::modint998244353;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int N, M, c;\n    std::cin >> N >> M >> c;\n\
    \    std::vector<mint> f(N);\n    for (int i = 0; i < N; i++) {\n        int x;\n\
    \        std::cin >> x;\n        f[i] = x;\n    }\n\n    auto res = shift_of_sampling_points_of_polynomial<mint>(f,\
    \ c, M);\n    for (int i = 0; i < M; i++) std::cout << res[i].val() << (i + 1\
    \ == M ? '\\n' : ' ');\n    return 0;\n}"
  dependsOn:
  - src/polynomial/shift_of_sampling_points_of_polynomial.hpp
  isVerificationFile: true
  path: test/yosupo/shift_of_sampling_points_of_polynomial.test.cpp
  requiredBy: []
  timestamp: '2023-05-24 23:58:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/shift_of_sampling_points_of_polynomial.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/shift_of_sampling_points_of_polynomial.test.cpp
- /verify/test/yosupo/shift_of_sampling_points_of_polynomial.test.cpp.html
title: test/yosupo/shift_of_sampling_points_of_polynomial.test.cpp
---
