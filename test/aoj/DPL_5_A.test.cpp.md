---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ modulo/modint.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_A\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n\nusing\
    \ mint=modint<1000000007>;\n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n\
    \    int n,k; cin >> n >> k;\n\n    cout << mint(k).pow(n) << '\\n';\n}"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  isVerificationFile: true
  path: test/aoj/DPL_5_A.test.cpp
  requiredBy: []
  timestamp: '2020-10-04 23:28:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_A.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_A.test.cpp
- /verify/test/aoj/DPL_5_A.test.cpp.html
title: test/aoj/DPL_5_A.test.cpp
---
