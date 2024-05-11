---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/datastructure/RangeTree.hpp
    title: Range Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_add_rectangle_sum
    links:
    - https://judge.yosupo.jp/problem/point_add_rectangle_sum
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/fenwicktree:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_add_rectangle_sum\"\
    \n\n#include <iostream>\n#include \"atcoder/fenwicktree\"\n#include \"datastructure/RangeTree.hpp\"\
    \n\nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    auto f = [](long long a, long long b) { return a + b; };\n    using FT =\
    \ atcoder::fenwick_tree<long long>;\n    auto st_new = [](int n) { return new\
    \ FT(n); };\n    auto st_set = [](FT& FT, int i, long long x) { FT.add(i, x);\
    \ };\n    auto st_prod = [](FT& FT, int l, int r) { return FT.sum(l, r); };\n\
    \    RangeTree<FT, long long, int> RT(st_new, st_set, st_prod, f, 0LL);\n\n  \
    \  int N, Q;\n    std::cin >> N >> Q;\n    std::vector<int> x(N), y(N), w(N),\
    \ c(Q), s(Q), t(Q), u(Q), v(Q);\n    for (int i = 0; i < N; i++) {\n        std::cin\
    \ >> x[i] >> y[i] >> w[i];\n        RT.add_point(x[i], y[i]);\n    }\n    for\
    \ (int i = 0; i < Q; i++) {\n        std::cin >> c[i] >> s[i] >> t[i] >> u[i];\n\
    \        if (c[i] == 0)\n            RT.add_point(s[i], t[i]);\n        else\n\
    \            std::cin >> v[i];\n    }\n\n    RT.build();\n    for (int i = 0;\
    \ i < N; i++) RT.set(x[i], y[i], w[i]);\n    for (int i = 0; i < Q; i++) {\n \
    \       if (c[i] == 0)\n            RT.set(s[i], t[i], u[i]);\n        else\n\
    \            std::cout << RT.prod(s[i], u[i], t[i], v[i]) << '\\n';\n    }\n \
    \   return 0;\n}"
  dependsOn:
  - src/datastructure/RangeTree.hpp
  isVerificationFile: true
  path: test/yosupo/point_add_rectangle_sum.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/point_add_rectangle_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_add_rectangle_sum.test.cpp
- /verify/test/yosupo/point_add_rectangle_sum.test.cpp.html
title: test/yosupo/point_add_rectangle_sum.test.cpp
---
