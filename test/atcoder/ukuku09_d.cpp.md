---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/SegmentTree.hpp
    title: Segment Tree
  - icon: ':warning:'
    path: string/Manacher.hpp
    title: Manacher
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links:
    - https://atcoder.jp/contests/ukuku09/tasks/ukuku09_d
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/Manacher.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define IGNORE\n\n#define PROBLEM \"https://atcoder.jp/contests/ukuku09/tasks/ukuku09_d\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../string/Manacher.hpp\"\n#include\
    \ \"../../datastructure/SegmentTree.hpp\"\n\nint main(){\n    cin.tie(0);\n  \
    \  ios::sync_with_stdio(false);\n    int N,Q; string S; cin >> N >> Q >> S;\n\n\
    \    vector<int> v=Manacher(S);\n    SegmentTree<int> seg(N,[](int a,int b){return\
    \ max(a,b);},0);\n    seg.build(v);\n\n    for (;Q--;){\n        int l,r; cin\
    \ >> l >> r; --l;\n        int lb=0,ub=(r-l+1)/2+1;\n        while(ub-lb>1){\n\
    \            int mid=(lb+ub)>>1;\n            int x=seg.query(l+mid-1,r-mid+1);\n\
    \            (mid<=x?lb:ub)=mid;\n        }\n        cout << lb*2-1 << '\\n';\n\
    \    }\n}"
  dependsOn:
  - base.hpp
  - string/Manacher.hpp
  - datastructure/SegmentTree.hpp
  isVerificationFile: false
  path: test/atcoder/ukuku09_d.cpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: test/atcoder/ukuku09_d.cpp
layout: document
redirect_from:
- /library/test/atcoder/ukuku09_d.cpp
- /library/test/atcoder/ukuku09_d.cpp.html
title: test/atcoder/ukuku09_d.cpp
---
