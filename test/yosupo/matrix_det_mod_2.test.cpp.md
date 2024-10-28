---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/matrix/F2Matrix.hpp
    title: Matrix on $\mathbb{F}_2$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/matrix_det_mod_2
    links:
    - https://judge.yosupo.jp/problem/matrix_det_mod_2
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: matrix/F2Matrix.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det_mod_2\"\n\n\
    #include <iostream>\n#include \"matrix/F2Matrix.hpp\"\n\nconst int MAX = 1 <<\
    \ 12;\n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N;\n    std::cin >> N;\n    F2Matrix<MAX> A(N, N);\n    for (int i =\
    \ 0; i < N; i++) {\n        for (int j = 0; j < N; j++) {\n            char val;\n\
    \            std::cin >> val;\n            A[i][j] = val - '0';\n        }\n \
    \   }\n\n    int det = A.det();\n    std::cout << det << '\\n';\n    return 0;\n\
    }\n"
  dependsOn:
  - src/matrix/F2Matrix.hpp
  isVerificationFile: true
  path: test/yosupo/matrix_det_mod_2.test.cpp
  requiredBy: []
  timestamp: '2024-10-28 16:18:08+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/matrix_det_mod_2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_det_mod_2.test.cpp
- /verify/test/yosupo/matrix_det_mod_2.test.cpp.html
title: test/yosupo/matrix_det_mod_2.test.cpp
---
