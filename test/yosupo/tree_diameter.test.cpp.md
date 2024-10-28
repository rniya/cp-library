---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/tree/TreeDiameter.hpp
    title: Tree Diameter
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/tree_diameter
    links:
    - https://judge.yosupo.jp/problem/tree_diameter
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.7/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: tree/TreeDiameter.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/tree_diameter\"\n\n#include\
    \ <iostream>\n#include \"tree/TreeDiameter.hpp\"\n\nint main() {\n    std::cin.tie(0);\n\
    \    std::ios::sync_with_stdio(false);\n    int N;\n    std::cin >> N;\n\n   \
    \ TreeDiameter<long long> TD(N);\n    for (int i = 0; i < N - 1; i++) {\n    \
    \    int a, b;\n        long long c;\n        std::cin >> a >> b >> c;\n     \
    \   TD.add_edge(a, b, c);\n    }\n\n    auto res = TD.get_diameter_path();\n \
    \   long long X = res.first;\n    auto ans = res.second;\n    int Y = ans.size();\n\
    \    std::cout << X << ' ' << Y << '\\n';\n    for (int i = 0; i < Y; i++) std::cout\
    \ << ans[i] << (i + 1 == Y ? '\\n' : ' ');\n    return 0;\n}"
  dependsOn:
  - src/tree/TreeDiameter.hpp
  isVerificationFile: true
  path: test/yosupo/tree_diameter.test.cpp
  requiredBy: []
  timestamp: '2024-04-07 17:26:46+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/tree_diameter.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/tree_diameter.test.cpp
- /verify/test/yosupo/tree_diameter.test.cpp.html
title: test/yosupo/tree_diameter.test.cpp
---
