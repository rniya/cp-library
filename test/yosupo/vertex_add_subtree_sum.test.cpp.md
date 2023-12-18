---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/tree/HeavyLightDecomposition.hpp
    title: Heavy Light Decomposition
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/vertex_add_subtree_sum
    links:
    - https://judge.yosupo.jp/problem/vertex_add_subtree_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.1/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/fenwicktree:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/vertex_add_subtree_sum\"\
    \n\n#include <iostream>\n#include \"atcoder/fenwicktree\"\n#include \"tree/HeavyLightDecomposition.hpp\"\
    \n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int> a(N);\n    for (int\
    \ i = 0; i < N; i++) std::cin >> a[i];\n    HeavyLightDecomposition HLD(N);\n\
    \    for (int i = 1; i < N; i++) {\n        int p;\n        std::cin >> p;\n \
    \       HLD.add_edge(p, i);\n    }\n    HLD.build();\n\n    atcoder::fenwick_tree<long\
    \ long> FT(N);\n    for (int i = 0; i < N; i++) FT.add(HLD.idx(i), a[i]);\n\n\
    \    for (; Q--;) {\n        int t, u;\n        std::cin >> t >> u;\n        if\
    \ (!t) {\n            int x;\n            std::cin >> x;\n            FT.add(HLD.idx(u),\
    \ x);\n        } else {\n            long long ans = 0;\n            auto q =\
    \ [&](int l, int r) { ans += FT.sum(l, r); };\n            HLD.query_subtree(u,\
    \ q, true);\n            std::cout << ans << '\\n';\n        }\n    }\n    return\
    \ 0;\n}"
  dependsOn:
  - src/tree/HeavyLightDecomposition.hpp
  isVerificationFile: true
  path: test/yosupo/vertex_add_subtree_sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/vertex_add_subtree_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/vertex_add_subtree_sum.test.cpp
- /verify/test/yosupo/vertex_add_subtree_sum.test.cpp.html
title: test/yosupo/vertex_add_subtree_sum.test.cpp
---
