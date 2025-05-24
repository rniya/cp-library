---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/enumerative_combinatorics/bell_number.hpp
    title: Bell Number
  - icon: ':heavy_check_mark:'
    path: src/math/binomial.hpp
    title: Binomial Coefficients
  - icon: ':heavy_check_mark:'
    path: src/polynomial/FormalPowerSeries.hpp
    title: Formal Power Series
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bell_number
    links:
    - https://judge.yosupo.jp/problem/bell_number
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: enumerative_combinatorics/bell_number.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bell_number\"\n\n#include\
    \ \"enumerative_combinatorics/bell_number.hpp\"\n#include <iostream>\n#include\
    \ \"atcoder/modint\"\n\nusing mint = atcoder::modint998244353;\n\nvoid solve()\
    \ {\n    int N;\n    std::cin >> N;\n    auto res = bell_number<mint>(N);\n  \
    \  for (int i = 0; i <= N; i++) {\n        std::cout << res[i].val() << \" \\\
    n\"[i == N];\n    }\n}\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    solve();\n    return 0;\n}"
  dependsOn:
  - src/enumerative_combinatorics/bell_number.hpp
  - src/math/binomial.hpp
  - src/polynomial/FormalPowerSeries.hpp
  isVerificationFile: true
  path: test/yosupo/bell_number.test.cpp
  requiredBy: []
  timestamp: '2025-05-24 15:05:16+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bell_number.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bell_number.test.cpp
- /verify/test/yosupo/bell_number.test.cpp.html
title: test/yosupo/bell_number.test.cpp
---
