---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/UndirectedCycleDetection.hpp
    title: Cycle Detection (Undirected)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/cycle_detection_undirected
    links:
    - https://judge.yosupo.jp/problem/cycle_detection_undirected
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.6/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/UndirectedCycleDetection.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/cycle_detection_undirected\"\
    \n\n#include <iostream>\n#include \"graph/UndirectedCycleDetection.hpp\"\n\nint\
    \ main() {\n    std::ios::sync_with_stdio(false);\n    std::cin.tie(nullptr);\n\
    \    int N, M;\n    std::cin >> N >> M;\n    UndirectedCycleDetection G(N);\n\
    \    for (; M--;) {\n        int u, v;\n        std::cin >> u >> v;\n        G.add_edge(u,\
    \ v);\n    }\n\n    auto [vs, es] = G.build();\n    if (vs.empty()) {\n      \
    \  std::cout << -1 << '\\n';\n        return 0;\n    }\n    int L = vs.size();\n\
    \    assert(int(es.size()) == L);\n    std::cout << L << \"\\n\";\n    for (int\
    \ i = 0; i < L; i++) std::cout << vs[i] << (i + 1 == L ? \"\\n\" : \" \");\n \
    \   for (int i = 0; i < L; i++) std::cout << es[i] << (i + 1 == L ? \"\\n\" :\
    \ \" \");\n    return 0;\n}"
  dependsOn:
  - src/graph/UndirectedCycleDetection.hpp
  isVerificationFile: true
  path: test/yosupo/cycle_detection_undirected.test.cpp
  requiredBy: []
  timestamp: '2024-08-25 02:56:03+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/cycle_detection_undirected.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/cycle_detection_undirected.test.cpp
- /verify/test/yosupo/cycle_detection_undirected.test.cpp.html
title: test/yosupo/cycle_detection_undirected.test.cpp
---
