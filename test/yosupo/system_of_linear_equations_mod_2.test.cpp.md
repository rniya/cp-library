---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: src/matrix/F2Matrix.hpp
    title: Matrix on $\mathbb{F}_2$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2
    links:
    - https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/system_of_linear_equations_mod_2\"\
    \n\n#include <iostream>\n#include \"matrix/F2Matrix.hpp\"\n\nconst int MAX_M =\
    \ (1 << 12) + 1;\n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N, M;\n    std::cin >> N >> M;\n    F2Matrix<MAX_M> A(N, M);\n    for\
    \ (int i = 0; i < N; i++) {\n        for (int j = 0; j < M; j++) {\n         \
    \   char val;\n            std::cin >> val;\n            A[i][j] = val - '0';\n\
    \        }\n    }\n    std::vector<bool> b(N);\n    for (int i = 0; i < N; i++)\
    \ {\n        char val;\n        std::cin >> val;\n        b[i] = val - '0';\n\
    \    }\n\n    auto ans = A.system_of_linear_equations(b);\n    int R = int(ans.size())\
    \ - 1;\n    std::cout << R << '\\n';\n    for (auto& x : ans) {\n        for (int\
    \ i = 0; i < M; i++) {\n            std::cout << x[i] << (i + 1 == M ? \"\\n\"\
    \ : \"\");\n        }\n    }\n    return 0;\n}\n"
  dependsOn:
  - src/matrix/F2Matrix.hpp
  isVerificationFile: true
  path: test/yosupo/system_of_linear_equations_mod_2.test.cpp
  requiredBy: []
  timestamp: '2024-10-28 15:48:27+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/system_of_linear_equations_mod_2.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/system_of_linear_equations_mod_2.test.cpp
- /verify/test/yosupo/system_of_linear_equations_mod_2.test.cpp.html
title: test/yosupo/system_of_linear_equations_mod_2.test.cpp
---
