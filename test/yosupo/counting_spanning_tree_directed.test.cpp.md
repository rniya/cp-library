---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/matrix/Matrix.hpp
    title: Matrix
  - icon: ':heavy_check_mark:'
    path: src/tree/counting_spanning_trees.hpp
    title: Counting Spanning Trees
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/counting_spanning_tree_directed
    links:
    - https://judge.yosupo.jp/problem/counting_spanning_tree_directed
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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/counting_spanning_tree_directed\"\
    \n\n#include <iostream>\n#include \"atcoder/modint\"\n#include \"tree/counting_spanning_trees.hpp\"\
    \n\nusing mint = atcoder::modint998244353;\n\nint main() {\n    std::ios::sync_with_stdio(false);\n\
    \    std::cin.tie(nullptr);\n    int N, M, r;\n    std::cin >> N >> M >> r;\n\
    \    std::vector G(N, std::vector<mint>(N, 0));\n    for (; M--;) {\n        int\
    \ u, v;\n        std::cin >> u >> v;\n        G[v][u]++;\n    }\n\n    auto ans\
    \ = counting_spanning_trees_directed(G, r);\n    std::cout << ans.val() << '\\\
    n';\n    return 0;\n}"
  dependsOn:
  - src/tree/counting_spanning_trees.hpp
  - src/matrix/Matrix.hpp
  isVerificationFile: true
  path: test/yosupo/counting_spanning_tree_directed.test.cpp
  requiredBy: []
  timestamp: '2024-06-04 01:23:18+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/counting_spanning_tree_directed.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/counting_spanning_tree_directed.test.cpp
- /verify/test/yosupo/counting_spanning_tree_directed.test.cpp.html
title: test/yosupo/counting_spanning_tree_directed.test.cpp
---
