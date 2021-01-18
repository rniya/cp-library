---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':x:'
    path: convolution/NumberTheoreticTransform.hpp
    title: Number Theoretic Transform
  - icon: ':x:'
    path: modulo/modint.hpp
    title: modint
  - icon: ':x:'
    path: polynomial/FormalPowerSeries.hpp
    title: Formal Power Series
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/pow_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/pow_of_formal_power_series
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ modulo/modint.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/pow_of_formal_power_series\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n#include\
    \ \"../../convolution/NumberTheoreticTransform.hpp\"\n#include \"../../polynomial/FormalPowerSeries.hpp\"\
    \n\nusing mint=modint<998244353>;\nusing FPS=FormalPowerSeries<mint>;\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(false);\n    NumberTheoreticTransform<998244353>\
    \ NTT;\n    auto mul=[&](const FPS::Poly &a,const FPS::Poly &b){\n        auto\
    \ res=NTT.multiply(a,b);\n        return FPS::Poly(res.begin(),res.end());\n \
    \   };\n    FPS::set_mul(mul);\n\n    int N,M; cin >> N >> M;\n    FPS a(N);\n\
    \    for (int i=0;i<N;++i) cin >> a[i];\n    FPS b=a.pow(M);\n    for (int i=0;i<N;++i)\
    \ cout << b[i] << (i+1==N?'\\n':' ');\n}"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - convolution/NumberTheoreticTransform.hpp
  - polynomial/FormalPowerSeries.hpp
  isVerificationFile: true
  path: test/yosupo/pow_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 00:11:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/pow_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/pow_of_formal_power_series.test.cpp
- /verify/test/yosupo/pow_of_formal_power_series.test.cpp.html
title: test/yosupo/pow_of_formal_power_series.test.cpp
---
