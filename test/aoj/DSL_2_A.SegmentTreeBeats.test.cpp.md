---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.1/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../datastructure/SegmentTreeBeats.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_A\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/SegmentTreeBeats.hpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int n,\
    \ q;\n    cin >> n >> q;\n\n    SegmentTreeBeats<int> seg(n);\n    vector<int>\
    \ v(n, INT_MAX);\n    seg.build(v);\n\n    for (; q--;) {\n        int c, x, y;\n\
    \        cin >> c >> x >> y;\n        if (!c)\n            seg.update_val(x, x\
    \ + 1, y);\n        else\n            cout << seg.query_min(x, y + 1) << '\\n';\n\
    \    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/aoj/DSL_2_A.SegmentTreeBeats.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_A.SegmentTreeBeats.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_A.SegmentTreeBeats.test.cpp
- /verify/test/aoj/DSL_2_A.SegmentTreeBeats.test.cpp.html
title: test/aoj/DSL_2_A.SegmentTreeBeats.test.cpp
---
