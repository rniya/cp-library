---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/count_graphs.hpp
    title: Enuemrate $C_3$, Count $C_4, K_4$
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_triangles
    links:
    - https://judge.yosupo.jp/problem/enumerate_triangles
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/modint:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_triangles\"\n\
    \n#include <iostream>\n#include \"atcoder/modint\"\n#include \"graph/count_graphs.hpp\"\
    \n\nusing mint = atcoder::modint998244353;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int N, M;\n    std::cin >> N >> M;\n    std::vector<int>\
    \ x(N);\n    for (int i = 0; i < N; i++) std::cin >> x[i];\n    std::vector<std::vector<int>>\
    \ G(N);\n    for (; M--;) {\n        int u, v;\n        std::cin >> u >> v;\n\
    \        G[u].emplace_back(v);\n        G[v].emplace_back(u);\n    }\n\n    mint\
    \ ans = 0;\n    for (auto [a, b, c] : count_graphs::enumerate_C4(G)) ans += mint(1)\
    \ * x[a] * x[b] * x[c];\n    std::cout << ans.val() << '\\n';\n    return 0;\n\
    }"
  dependsOn:
  - src/graph/count_graphs.hpp
  isVerificationFile: true
  path: test/yosupo/enumerate_triangles.test.cpp
  requiredBy: []
  timestamp: '2023-10-01 16:26:05+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/enumerate_triangles.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate_triangles.test.cpp
- /verify/test/yosupo/enumerate_triangles.test.cpp.html
title: test/yosupo/enumerate_triangles.test.cpp
---
