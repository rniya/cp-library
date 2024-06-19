---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/DirectedCycleDetection.hpp
    title: Directed Cycle Detection
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection
    links:
    - https://judge.yosupo.jp/problem/cycle_detection
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/DirectedCycleDetection.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection\"\n\n#include\
    \ <iostream>\n#include \"graph/DirectedCycleDetection.hpp\"\n\nint main() {\n\
    \    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n    int N,\
    \ M;\n    std::cin >> N >> M;\n    DirectedCycleDetection G(N);\n    for (; M--;)\
    \ {\n        int u, v;\n        std::cin >> u >> v;\n        G.add_edge(u, v);\n\
    \    }\n\n    auto [vs, es] = G.build();\n    if (es.empty()) {\n        std::cout\
    \ << -1 << '\\n';\n        return 0;\n    }\n    std::cout << es.size() << '\\\
    n';\n    for (auto& e : es) std::cout << e << '\\n';\n    return 0;\n}"
  dependsOn:
  - src/graph/DirectedCycleDetection.hpp
  isVerificationFile: true
  path: test/yosupo/cycle_detection.test.cpp
  requiredBy: []
  timestamp: '2023-09-11 12:23:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/cycle_detection.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/cycle_detection.test.cpp
- /verify/test/yosupo/cycle_detection.test.cpp.html
title: test/yosupo/cycle_detection.test.cpp
---
