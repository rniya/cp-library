---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/SegmentTreeBeats.hpp
    title: Segment Tree Beats
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/SegmentTreeBeats.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_G\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/SegmentTreeBeats.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n,q;\
    \ cin >> n >> q;\n\n    SegmentTreeBeats<long long> seg(n);\n    vector<long long>\
    \ v(n,0);\n    seg.build(v);\n\n    for (;q--;){\n        int c; cin >> c;\n \
    \       if (!c){\n            int s,t; long long x; cin >> s >> t >> x;\n    \
    \        seg.update_add(s-1,t,x);\n        } else {\n            int s,t; cin\
    \ >> s >> t;\n            cout << seg.query_sum(s-1,t) << '\\n';\n        }\n\
    \    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/SegmentTreeBeats.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_G.SegmentTreeBeats.test.cpp
  requiredBy: []
  timestamp: '2020-09-09 23:15:02+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/aoj/DSL_2_G.SegmentTreeBeats.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_G.SegmentTreeBeats.test.cpp
- /verify/test/aoj/DSL_2_G.SegmentTreeBeats.test.cpp.html
title: test/aoj/DSL_2_G.SegmentTreeBeats.test.cpp
---
