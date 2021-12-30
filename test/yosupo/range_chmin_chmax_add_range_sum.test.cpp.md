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
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_chmin_chmax_add_range_sum\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/SegmentTreeBeats.hpp\"\
    \n\nint main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,\
    \ Q;\n    cin >> N >> Q;\n    vector<long long> a(N);\n    for (int i = 0; i <\
    \ N; i++) cin >> a[i];\n\n    SegmentTreeBeats<long long> seg(N);\n    seg.build(a);\n\
    \n    for (; Q--;) {\n        int t, l, r;\n        long long b;\n        cin\
    \ >> t >> l >> r;\n        if (t == 0) {\n            cin >> b;\n            seg.update_min(l,\
    \ r, b);\n        } else if (t == 1) {\n            cin >> b;\n            seg.update_max(l,\
    \ r, b);\n        } else if (t == 2) {\n            cin >> b;\n            seg.update_add(l,\
    \ r, b);\n        } else\n            cout << seg.query_sum(l, r) << '\\n';\n\
    \    }\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
- /verify/test/yosupo/range_chmin_chmax_add_range_sum.test.cpp.html
title: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
---
