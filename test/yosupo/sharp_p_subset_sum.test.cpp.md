---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/polynomial/FormalPowerSeries.hpp
    title: "Formal Power Series\uFF08\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\uFF09"
  - icon: ':heavy_check_mark:'
    path: src/polynomial/subset_sum.hpp
    title: $\#_p$ Subset Sum
  - icon: ':heavy_check_mark:'
    path: src/util/modint.hpp
    title: modint (input/output)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sharp_p_subset_sum
    links:
    - https://judge.yosupo.jp/problem/sharp_p_subset_sum
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: polynomial/subset_sum.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sharp_p_subset_sum\"\n\n\
    #include \"polynomial/subset_sum.hpp\"\n#include \"util/modint.hpp\"\n\nusing\
    \ mint = atcoder::modint998244353;\n\nint main() {\n    std::cin.tie(0);\n   \
    \ std::ios::sync_with_stdio(false);\n    int N, T;\n    std::cin >> N >> T;\n\
    \    std::vector<int> s(N);\n    for (int& x : s) std::cin >> x;\n\n    auto res\
    \ = subset_sum<mint>(s, T);\n    for (int i = 1; i <= T; i++) std::cout << res[i]\
    \ << (i == T ? '\\n' : ' ');\n}"
  dependsOn:
  - src/polynomial/subset_sum.hpp
  - src/polynomial/FormalPowerSeries.hpp
  - src/util/modint.hpp
  isVerificationFile: true
  path: test/yosupo/sharp_p_subset_sum.test.cpp
  requiredBy: []
  timestamp: '2023-09-18 22:25:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sharp_p_subset_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sharp_p_subset_sum.test.cpp
- /verify/test/yosupo/sharp_p_subset_sum.test.cpp.html
title: test/yosupo/sharp_p_subset_sum.test.cpp
---
