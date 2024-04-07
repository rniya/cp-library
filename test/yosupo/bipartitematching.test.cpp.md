---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/graph/BipartiteMatching.hpp
    title: Bipartite Matching
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/bipartitematching
    links:
    - https://judge.yosupo.jp/problem/bipartitematching
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/BipartiteMatching.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/bipartitematching\"\n\n\
    #include \"graph/BipartiteMatching.hpp\"\n#include <iostream>\n\nint main() {\n\
    \    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n    int L, R, M;\n\
    \    std::cin >> L >> R >> M;\n\n    BipartiteMatching BM(L, R);\n    for (; M--;)\
    \ {\n        int a, b;\n        std::cin >> a >> b;\n        BM.add_edge(a, b);\n\
    \    }\n\n    BM.solve();\n    auto ans = BM.max_matching();\n    std::cout <<\
    \ ans.size() << '\\n';\n    for (auto p : ans) std::cout << p.first << ' ' <<\
    \ p.second << '\\n';\n    return 0;\n}"
  dependsOn:
  - src/graph/BipartiteMatching.hpp
  isVerificationFile: true
  path: test/yosupo/bipartitematching.test.cpp
  requiredBy: []
  timestamp: '2024-04-07 17:26:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/bipartitematching.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/bipartitematching.test.cpp
- /verify/test/yosupo/bipartitematching.test.cpp.html
title: test/yosupo/bipartitematching.test.cpp
---
