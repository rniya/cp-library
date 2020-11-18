---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: convolution/NumberTheoreticTransform.hpp
    title: Number Theoretic Transform
  - icon: ':question:'
    path: modulo/modint.hpp
    title: modint
  - icon: ':question:'
    path: polynomial/FormalPowerSeries.hpp
    title: Formal Power Series
  - icon: ':x:'
    path: polynomial/StirlingSecond.hpp
    title: "\u7B2C2\u7A2E\u30B9\u30BF\u30FC\u30EA\u30F3\u30B0\u6570"
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
    links:
    - https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ modulo/modint.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n#include\
    \ \"../../convolution/NumberTheoreticTransform.hpp\"\n#include \"../../polynomial/StirlingSecond.hpp\"\
    \n\nusing mint=modint<998244353>;\nusing FPS=FormalPowerSeries<mint>;\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(false);\n    NumberTheoreticTransform<998244353>\
    \ NTT;\n    auto mul=[&](const FPS::Poly &a,const FPS::Poly &b){\n        auto\
    \ res=NTT.multiply(a,b);\n        return FPS::Poly(res.begin(),res.end());\n \
    \   };\n    FPS::set_mul(mul);\n\n    int N; cin >> N;\n    FPS ans=StirlingSecond<mint>(N);\n\
    \    for (int i=0;i<=N;++i) cout << ans[i] << (i==N?'\\n':' ');\n}"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - convolution/NumberTheoreticTransform.hpp
  - polynomial/StirlingSecond.hpp
  - polynomial/FormalPowerSeries.hpp
  isVerificationFile: true
  path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/stirling_number_of_the_second_kind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/stirling_number_of_the_second_kind.test.cpp
- /verify/test/yosupo/stirling_number_of_the_second_kind.test.cpp.html
title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
---
