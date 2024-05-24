---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/math/RelaxedConvolution.hpp
    title: Relaxed Convolution
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/convolution_mod
    links:
    - https://judge.yosupo.jp/problem/convolution_mod
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/convolution_mod\"\n\n#include\
    \ <iostream>\n#include \"atcoder/modint\"\n#include \"math/RelaxedConvolution.hpp\"\
    \n\nusing mint = atcoder::modint998244353;\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    int N, M;\n    std::cin >> N >> M;\n\
    \    std::vector<int> a(N), b(M);\n    for (int i = 0; i < N; i++) std::cin >>\
    \ a[i];\n    for (int i = 0; i < M; i++) std::cin >> b[i];\n\n    RelaxedConvolution<mint>\
    \ rc;\n    for (int i = 0; i <= N + M - 2; i++) {\n        mint ans = rc.query(i\
    \ < N ? a[i] : 0, i < M ? b[i] : 0);\n        std::cout << ans.val() << (i ==\
    \ N + M - 2 ? '\\n' : ' ');\n    }\n    return 0;\n}"
  dependsOn:
  - src/math/RelaxedConvolution.hpp
  isVerificationFile: true
  path: test/yosupo/convolution_mod.relaxedconvolution.test.cpp
  requiredBy: []
  timestamp: '2024-05-25 00:17:07+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/convolution_mod.relaxedconvolution.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/convolution_mod.relaxedconvolution.test.cpp
- /verify/test/yosupo/convolution_mod.relaxedconvolution.test.cpp.html
title: test/yosupo/convolution_mod.relaxedconvolution.test.cpp
---
