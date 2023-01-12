---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/enumerate_cliques.hpp
    title: "\u30AF\u30EA\u30FC\u30AF\u5168\u5217\u6319"
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
    PROBLEM: https://judge.yosupo.jp/problem/enumerate_cliques
    links:
    - https://judge.yosupo.jp/problem/enumerate_cliques
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/enumerate_cliques.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/enumerate_cliques\"\n\n\
    #include \"graph/enumerate_cliques.hpp\"\n#include \"util/modint.hpp\"\n\nusing\
    \ mint = atcoder::modint998244353;\n\nint main() {\n    std::cin.tie(0);\n   \
    \ std::ios::sync_with_stdio(false);\n    int N, M;\n    std::cin >> N >> M;\n\
    \    std::vector<int> x(N);\n    for (int i = 0; i < N; i++) std::cin >> x[i];\n\
    \    std::vector<std::vector<bool>> G(N, std::vector<bool>(N, false));\n    for\
    \ (; M--;) {\n        int u, v;\n        std::cin >> u >> v;\n        G[u][v]\
    \ = G[v][u] = true;\n    }\n\n    auto calc = [&](std::vector<int> clique) {\n\
    \        mint res = 1;\n        for (int& v : clique) res *= x[v];\n        return\
    \ res;\n    };\n    mint ans = 0;\n    for (const auto& clique : enumerate_cliques(G))\
    \ ans += calc(clique);\n    std::cout << ans << '\\n';\n    return 0;\n}"
  dependsOn:
  - src/graph/enumerate_cliques.hpp
  - src/util/modint.hpp
  isVerificationFile: true
  path: test/yosupo/enumerate_cliques.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 23:01:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/enumerate_cliques.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/enumerate_cliques.test.cpp
- /verify/test/yosupo/enumerate_cliques.test.cpp.html
title: test/yosupo/enumerate_cliques.test.cpp
---
