---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/matrix/SquareMatrix.hpp
    title: Square Matrix
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det
    links:
    - https://judge.yosupo.jp/problem/matrix_det
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include\
    \ <iostream>\n#include \"atcoder/modint\"\n#include \"matrix/SquareMatrix.hpp\"\
    \n\nusing mint = atcoder::modint998244353;\nconstexpr int MAX = 1 << 9;\n\nint\
    \ main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    int\
    \ N;\n    std::cin >> N;\n    SquareMatrix<mint, MAX> A;\n    for (int i = 0;\
    \ i < MAX; i++) A[i][i] = 1;\n    for (int i = 0; i < N; i++) {\n        for (int\
    \ j = 0; j < N; j++) {\n            int val;\n            std::cin >> val;\n \
    \           A[i][j] = val;\n        }\n    }\n\n    auto det = A.det();\n    std::cout\
    \ << det.val() << '\\n';\n    return 0;\n}\n"
  dependsOn:
  - src/matrix/SquareMatrix.hpp
  isVerificationFile: true
  path: test/yosupo/matrix_det.squarematrix.test.cpp
  requiredBy: []
  timestamp: '2024-05-24 00:56:59+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/matrix_det.squarematrix.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_det.squarematrix.test.cpp
- /verify/test/yosupo/matrix_det.squarematrix.test.cpp.html
title: test/yosupo/matrix_det.squarematrix.test.cpp
---
