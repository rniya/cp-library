---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/StronglyConnectedComponents.hpp
    title: Strongly Connected Components
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/scc
    links:
    - https://judge.yosupo.jp/problem/scc
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/StronglyConnectedComponents.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/scc\"\n\n#include <iostream>\n\
    #include \"graph/StronglyConnectedComponents.hpp\"\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    int N, M;\n    std::cin >> N >> M;\n\
    \n    StronglyConnectedComponents SCC(N);\n    for (int i = 0; i < M; i++) {\n\
    \        int a, b;\n        std::cin >> a >> b;\n        SCC.add_edge(a, b);\n\
    \    }\n\n    auto res = SCC.build();\n    std::cout << res.size() << '\\n';\n\
    \    for (auto& group : res) {\n        std::cout << group.size();\n        for\
    \ (int& v : group) std::cout << ' ' << v;\n        std::cout << '\\n';\n    }\n\
    }"
  dependsOn:
  - src/graph/StronglyConnectedComponents.hpp
  isVerificationFile: true
  path: test/yosupo/scc.test.cpp
  requiredBy: []
  timestamp: '2024-04-07 17:26:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/scc.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/scc.test.cpp
- /verify/test/yosupo/scc.test.cpp.html
title: test/yosupo/scc.test.cpp
---
