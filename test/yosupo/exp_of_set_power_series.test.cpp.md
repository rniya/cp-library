---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/exp_of_set_power_series.hpp
    title: Exp of Set Power Series
  - icon: ':heavy_check_mark:'
    path: src/math/subset_convolution.hpp
    title: Subset Convolution
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/exp_of_set_power_series
    links:
    - https://judge.yosupo.jp/problem/exp_of_set_power_series
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/exp_of_set_power_series.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/exp_of_set_power_series\"\
    \n\n#include \"math/exp_of_set_power_series.hpp\"\n#include <iostream>\n#include\
    \ \"atcoder/modint\"\n\nusing mint = atcoder::modint998244353;\n\nint main() {\n\
    \    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    int N;\n\
    \    std::cin >> N;\n    std::vector<mint> b(1 << N);\n    for (int i = 0; i <\
    \ 1 << N; i++) {\n        int x;\n        std::cin >> x;\n        b[i] = mint::raw(x);\n\
    \    }\n\n    auto c = exp_of_set_power_series(b);\n    for (int i = 0; i < 1\
    \ << N; i++) std::cout << c[i].val() << (i + 1 == (1 << N) ? '\\n' : ' ');\n}"
  dependsOn:
  - src/math/exp_of_set_power_series.hpp
  - src/math/subset_convolution.hpp
  isVerificationFile: true
  path: test/yosupo/exp_of_set_power_series.test.cpp
  requiredBy: []
  timestamp: '2023-10-09 19:11:51+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/exp_of_set_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/exp_of_set_power_series.test.cpp
- /verify/test/yosupo/exp_of_set_power_series.test.cpp.html
title: test/yosupo/exp_of_set_power_series.test.cpp
---
