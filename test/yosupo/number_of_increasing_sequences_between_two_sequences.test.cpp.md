---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/binomial.hpp
    title: Binomial Coefficients
  - icon: ':heavy_check_mark:'
    path: src/math/number_of_increasing_sequences_between_two_sequences.hpp
    title: Number of Increasing Sequences Between Two Sequences
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/number_of_increasing_sequences_between_two_sequences
    links:
    - https://judge.yosupo.jp/problem/number_of_increasing_sequences_between_two_sequences
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/number_of_increasing_sequences_between_two_sequences.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/number_of_increasing_sequences_between_two_sequences\"\
    \n\n#include \"math/number_of_increasing_sequences_between_two_sequences.hpp\"\
    \n#include <iostream>\n#include \"atcoder/modint\"\n\nusing mint = atcoder::modint998244353;\n\
    \nint main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int N, M;\n    std::cin >> N >> M;\n    std::vector<int> A(N), B(N);\n  \
    \  for (int i = 0; i < N; i++) std::cin >> A[i];\n    for (int i = 0; i < N; i++)\
    \ std::cin >> B[i];\n\n    auto ans = number_of_increasing_sequences_between_two_sequences<mint>(A,\
    \ B);\n    std::cout << ans.val() << \"\\n\";\n    return 0;\n}"
  dependsOn:
  - src/math/number_of_increasing_sequences_between_two_sequences.hpp
  - src/math/binomial.hpp
  isVerificationFile: true
  path: test/yosupo/number_of_increasing_sequences_between_two_sequences.test.cpp
  requiredBy: []
  timestamp: '2024-10-28 15:43:27+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/number_of_increasing_sequences_between_two_sequences.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/number_of_increasing_sequences_between_two_sequences.test.cpp
- /verify/test/yosupo/number_of_increasing_sequences_between_two_sequences.test.cpp.html
title: test/yosupo/number_of_increasing_sequences_between_two_sequences.test.cpp
---
