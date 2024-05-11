---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/polynomial/BostanMori.hpp
    title: Bostan-Mori Algorithm
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
    PROBLEM: https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
    links:
    - https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: polynomial/BostanMori.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/kth_term_of_linearly_recurrent_sequence\"\
    \n\n#include \"polynomial/BostanMori.hpp\"\n#include \"util/modint.hpp\"\n\nusing\
    \ mint = atcoder::modint998244353;\n\nint main() {\n    std::cin.tie(0);\n   \
    \ std::ios::sync_with_stdio(false);\n    int d;\n    long long k;\n    std::cin\
    \ >> d >> k;\n    std::vector<mint> a(d), c(d);\n    for (auto& x : a) std::cin\
    \ >> x;\n    for (auto& x : c) std::cin >> x;\n\n    auto ans = LinearRecurrence(a,\
    \ c, k);\n    std::cout << ans << '\\n';\n    return 0;\n}"
  dependsOn:
  - src/polynomial/BostanMori.hpp
  - src/util/modint.hpp
  isVerificationFile: true
  path: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
  requiredBy: []
  timestamp: '2023-09-18 22:25:37+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
- /verify/test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp.html
title: test/yosupo/kth_term_of_linearly_recurrent_sequence.test.cpp
---
