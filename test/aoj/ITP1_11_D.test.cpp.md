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
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_D
    links:
    - https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_D
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: base.hpp: line\
    \ -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/problems/ITP1_11_D\"\n\
    \n#include \"base.hpp\"\n#include \"util/Dice.hpp\"\n\nint main() {\n    cin.tie(0);\n\
    \    ios::sync_with_stdio(false);\n    size_t n;\n    cin >> n;\n    set<Dice>\
    \ s;\n    vector<int> v(6);\n    for (size_t i = 0; i < n; i++) {\n        for\
    \ (int j = 0; j < 6; j++) cin >> v[j];\n        Dice d(v);\n        s.emplace(d.identifier());\n\
    \    }\n    cout << (s.size() == n ? \"Yes\" : \"No\") << '\\n';\n    return 0;\n\
    }"
  dependsOn:
  - src/base.hpp
  - src/util/Dice.hpp
  isVerificationFile: true
  path: test/aoj/ITP1_11_D.test.cpp
  requiredBy: []
  timestamp: '2023-01-13 11:27:34+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/ITP1_11_D.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/ITP1_11_D.test.cpp
- /verify/test/aoj/ITP1_11_D.test.cpp.html
title: test/aoj/ITP1_11_D.test.cpp
---
