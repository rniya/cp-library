---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/sum_of_multiplicative_function.hpp
    title: Sum of Multiplicative Function
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/sum_of_multiplicative_function
    links:
    - https://judge.yosupo.jp/problem/sum_of_multiplicative_function
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: math/sum_of_multiplicative_function.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/sum_of_multiplicative_function\"\
    \n\n#include \"math/sum_of_multiplicative_function.hpp\"\n#include <iostream>\n\
    #include \"atcoder/modint\"\n\nusing mint = atcoder::static_modint<469762049>;\n\
    \nlong long a, b;\n\nmint f(long long p, long long e) { return mint(a) * e + mint(b)\
    \ * p; }\n\nvoid solve() {\n    long long N;\n    std::cin >> N >> a >> b;\n\n\
    \    sum_of_multiplicative_function<mint, f> smf(N);\n    auto S0 = smf.counting_primes();\n\
    \    auto S1 = smf.summing_primes();\n    for (int i = 0; i < int(S1.size());\
    \ i++) S1[i] = S1[i] * b + S0[i] * a;\n    auto ans = smf.solve(S1);\n\n    std::cout\
    \ << ans.val() << \"\\n\";\n}\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n\n    int T;\n    std::cin >> T;\n    for (; T--;)\
    \ solve();\n    return 0;\n}"
  dependsOn:
  - src/math/sum_of_multiplicative_function.hpp
  isVerificationFile: true
  path: test/yosupo/sum_of_multiplicative_function.test.cpp
  requiredBy: []
  timestamp: '2024-09-28 01:48:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/sum_of_multiplicative_function.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/sum_of_multiplicative_function.test.cpp
- /verify/test/yosupo/sum_of_multiplicative_function.test.cpp.html
title: test/yosupo/sum_of_multiplicative_function.test.cpp
---
