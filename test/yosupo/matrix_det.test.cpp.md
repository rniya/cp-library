---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/linearalgebra/Matrix.hpp
    title: "\u884C\u5217\u30E9\u30A4\u30D6\u30E9\u30EA"
  - icon: ':question:'
    path: src/util/modint.hpp
    title: src/util/modint.hpp
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
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.2/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: linearalgebra/Matrix.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/matrix_det\"\n\n#include\
    \ \"linearalgebra/Matrix.hpp\"\n#include \"util/modint.hpp\"\n\nusing mint = atcoder::modint998244353;\n\
    \nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N;\n    std::cin >> N;\n    Matrix<mint> a(N);\n    for (int i = 0; i\
    \ < N; i++) {\n        for (int j = 0; j < N; j++) {\n            std::cin >>\
    \ a[i][j];\n        }\n    }\n\n    std::cout << a.determinant() << '\\n';\n}"
  dependsOn:
  - src/linearalgebra/Matrix.hpp
  - src/util/modint.hpp
  isVerificationFile: true
  path: test/yosupo/matrix_det.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 23:01:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/matrix_det.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/matrix_det.test.cpp
- /verify/test/yosupo/matrix_det.test.cpp.html
title: test/yosupo/matrix_det.test.cpp
---
