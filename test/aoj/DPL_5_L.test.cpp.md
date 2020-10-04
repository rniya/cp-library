---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: combinatorics/PartitionTable.hpp
    title: "\u5206\u5272\u6570\u30C6\u30FC\u30D6\u30EB"
  - icon: ':heavy_check_mark:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ modulo/modint.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n#include\
    \ \"../../combinatorics/PartitionTable.hpp\"\n\nusing mint=modint<1000000007>;\n\
    \nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n,k;\
    \ cin >> n >> k;\n\n    cout << (n-k>=0?partition_table<mint>(n-k,k)[n-k][k]:0)\
    \ << '\\n';\n}"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - combinatorics/PartitionTable.hpp
  isVerificationFile: true
  path: test/aoj/DPL_5_L.test.cpp
  requiredBy: []
  timestamp: '2020-10-04 22:03:25+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DPL_5_L.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DPL_5_L.test.cpp
- /verify/test/aoj/DPL_5_L.test.cpp.html
title: test/aoj/DPL_5_L.test.cpp
---