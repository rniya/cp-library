---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 258, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: ../../string/Z_Algorithm.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/zalgorithm\"\n\n#include\
    \ \"../../base.hpp\"\n#include \"../../string/Z_Algorithm.hpp\"\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(false);\n    string S; cin >> S;\n\
    \    vector<int> ans=Z_Algorithm(S);\n\n    for (int i=0;i<ans.size();++i) cout\
    \ << ans[i] << (i+1==ans.size()?'\\n':' ');\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/zalgorithm.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/zalgorithm.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/zalgorithm.test.cpp
- /verify/test/yosupo/zalgorithm.test.cpp.html
title: test/yosupo/zalgorithm.test.cpp
---
