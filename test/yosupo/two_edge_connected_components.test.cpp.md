---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/LowLink.hpp
    title: LowLink (with Two Edge Connected Components, Bi Connected Components)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/two_edge_connected_components
    links:
    - https://judge.yosupo.jp/problem/two_edge_connected_components
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/LowLink.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/two_edge_connected_components\"\
    \n\n#include <iostream>\n#include \"graph/LowLink.hpp\"\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    int N, M;\n    std::cin >> N >> M;\n\
    \    LowLink G(N);\n    for (; M--;) {\n        int a, b;\n        std::cin >>\
    \ a >> b;\n        G.add_edge(a, b);\n    }\n\n    G.build();\n    auto& tecc\
    \ = G.tecc;\n    int K = G.t;\n    std::vector<std::vector<int>> ans(K);\n   \
    \ for (int i = 0; i < N; i++) ans[tecc[i]].emplace_back(i);\n    std::cout <<\
    \ K << '\\n';\n    for (int i = 0; i < K; i++) {\n        std::cout << ans[i].size();\n\
    \        for (int& v : ans[i]) std::cout << ' ' << v;\n        std::cout << '\\\
    n';\n    }\n}"
  dependsOn:
  - src/graph/LowLink.hpp
  isVerificationFile: true
  path: test/yosupo/two_edge_connected_components.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/two_edge_connected_components.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/two_edge_connected_components.test.cpp
- /verify/test/yosupo/two_edge_connected_components.test.cpp.html
title: test/yosupo/two_edge_connected_components.test.cpp
---
