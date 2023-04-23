---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/base.hpp
    title: src/base.hpp
  - icon: ':heavy_check_mark:'
    path: src/util/Dice.hpp
    title: "\u30B5\u30A4\u30B3\u30ED"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_B
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_B
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.3/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: base.hpp: line\
    \ -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_B\"\n\
    \n#include \"base.hpp\"\n#include \"util/Dice.hpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    vector<int> v(6);\n    for (int i = 0;\
    \ i < 6; i++) cin >> v[i];\n\n    Dice d(v);\n    auto ds = d.make_all();\n  \
    \  map<pair<int, int>, int> mp;\n    for (auto& x : ds) mp[{x.top(), x.front()}]\
    \ = x.right();\n\n    int q;\n    cin >> q;\n    for (; q--;) {\n        int t,\
    \ f;\n        cin >> t >> f;\n        cout << mp[{t, f}] << '\\n';\n    }\n  \
    \  return 0;\n}"
  dependsOn:
  - src/base.hpp
  - src/util/Dice.hpp
  isVerificationFile: true
  path: test/aoj/ITP1_11_B.test.cpp
  requiredBy: []
  timestamp: '2023-04-22 02:23:28+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ITP1_11_B.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP1_11_B.test.cpp
- /verify/test/aoj/ITP1_11_B.test.cpp.html
title: test/aoj/ITP1_11_B.test.cpp
---