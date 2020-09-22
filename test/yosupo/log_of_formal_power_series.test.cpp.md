---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: modulo/modint.hpp
    title: modint
  - icon: ':heavy_check_mark:'
    path: convolution/NumberTheoreticTransform.hpp
    title: Number Theoretic Transform
  - icon: ':heavy_check_mark:'
    path: polynomial/FormalPowerSeries.hpp
    title: Formal Power Series
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/log_of_formal_power_series
    links:
    - https://judge.yosupo.jp/problem/log_of_formal_power_series
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 70, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ modulo/modint.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/log_of_formal_power_series\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n#include\
    \ \"../../convolution/NumberTheoreticTransform.hpp\"\n#include \"../../polynomial/FormalPowerSeries.hpp\"\
    \n\nusing mint=modint<998244353>;\nusing FPS=FormalPowerSeries<mint>;\n\nint main(){\n\
    \    cin.tie(0);\n    ios::sync_with_stdio(false);\n    NumberTheoreticTransform<998244353>\
    \ NTT;\n    auto mul=[&](const FPS::Poly &a,const FPS::Poly &b){\n        auto\
    \ res=NTT.multiply(a,b);\n        return FPS::Poly(res.begin(),res.end());\n \
    \   };\n    FPS::set_mul(mul);\n\n    int N; cin >> N;\n    FPS a(N);\n    for\
    \ (int i=0;i<N;++i) cin >> a[i];\n    FPS b=a.log();\n    for (int i=0;i<N;++i)\
    \ cout << b[i] << (i+1==N?'\\n':' ');\n}"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - convolution/NumberTheoreticTransform.hpp
  - polynomial/FormalPowerSeries.hpp
  isVerificationFile: true
  path: test/yosupo/log_of_formal_power_series.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 12:07:47+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/log_of_formal_power_series.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/log_of_formal_power_series.test.cpp
- /verify/test/yosupo/log_of_formal_power_series.test.cpp.html
title: test/yosupo/log_of_formal_power_series.test.cpp
---
