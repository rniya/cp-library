---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/StronglyConnectedComponents.hpp
    title: Strongly Connected Components
  - icon: ':heavy_check_mark:'
    path: src/graph/TwoSAT.hpp
    title: 2-SAT
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_sat
    links:
    - https://judge.yosupo.jp/problem/two_sat
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/TwoSAT.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_sat\"\n\n#include <iostream>\n\
    #include <string>\n#include \"graph/TwoSAT.hpp\"\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    std::string p, cnf;\n    int N, M;\n\
    \    std::cin >> p >> cnf >> N >> M;\n\n    TwoSAT TS(N + 1);\n    for (int i\
    \ = 0; i < M; i++) {\n        int a, b, c;\n        std::cin >> a >> b >> c;\n\
    \        TS.add_clause(abs(a), (a > 0), abs(b), (b > 0));\n    }\n\n    if (!TS.satisfiable())\
    \ {\n        std::cout << \"s UNSATISFIABLE\" << '\\n';\n        return 0;\n \
    \   }\n    std::cout << \"s SATISFIABLE\" << '\\n';\n    std::cout << \"v \";\n\
    \    auto ans = TS.answer();\n    for (int i = 1; i <= N; i++) std::cout << (ans[i]\
    \ ? i : -i) << ' ';\n    std::cout << \"0\\n\";\n    return 0;\n}"
  dependsOn:
  - src/graph/TwoSAT.hpp
  - src/graph/StronglyConnectedComponents.hpp
  isVerificationFile: true
  path: test/yosupo/two_sat.test.cpp
  requiredBy: []
  timestamp: '2024-04-07 17:26:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_sat.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_sat.test.cpp
- /verify/test/yosupo/two_sat.test.cpp.html
title: test/yosupo/two_sat.test.cpp
---
