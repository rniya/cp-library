---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
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
    PROBLEM: https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.6/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/SegmentTreeBeats.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/SegmentTreeBeats.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,Q;\
    \ cin >> N >> Q;\n    vector<long long> a(N);\n    for (int i=0;i<N;++i) cin >>\
    \ a[i];\n\n    SegmentTreeBeats<long long> seg(N);\n    seg.build(a);\n\n    for\
    \ (;Q--;){\n        int t,l,r; long long b; cin >> t >> l >> r;\n        if (t==0){\n\
    \            cin >> b;\n            seg.update_min(l,r,b);\n        } else if\
    \ (t==1){\n            cin >> b;\n            seg.update_max(l,r,b);\n       \
    \ } else if (t==2){\n            cin >> b;\n            seg.update_add(l,r,b);\n\
    \        } else cout << seg.query_sum(l,r) << '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/SegmentTreeBeats.hpp
  isVerificationFile: true
  path: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-09-12 20:51:23+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp.html
title: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
---
