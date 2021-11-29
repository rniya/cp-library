---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: true
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes: {}
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.10.0/x64/lib/python3.10/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/stirling_number_of_the_second_kind\"\
    \n#define IGNORE\n\n#include \"../../base.hpp\"\n#include \"../../convolution/NumberTheoreticTransform.hpp\"\
    \n#include \"../../modulo/modint.hpp\"\n#include \"../../polynomial/StirlingSecond.hpp\"\
    \n\nusing mint = modint<998244353>;\nusing FPS = FormalPowerSeries<mint>;\n\n\
    int main() {\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    NumberTheoreticTransform<998244353>\
    \ NTT;\n    auto mul = [&](const FPS::Poly& a, const FPS::Poly& b) {\n       \
    \ auto res = NTT.multiply(a, b);\n        return FPS::Poly(res.begin(), res.end());\n\
    \    };\n    FPS::set_mul(mul);\n\n    int N;\n    cin >> N;\n    FPS ans = StirlingSecond<mint>(N);\n\
    \    for (int i = 0; i <= N; i++) cout << ans[i] << (i == N ? '\\n' : ' ');\n}"
  dependsOn: []
  isVerificationFile: true
  path: test/yosupo/stirling_number_of_the_second_kind.test.cpp
  requiredBy: []
  timestamp: '1970-01-01 00:00:00+00:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/stirling_number_of_the_second_kind.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/stirling_number_of_the_second_kind.test.cpp
- /verify/test/yosupo/stirling_number_of_the_second_kind.test.cpp.html
title: test/yosupo/stirling_number_of_the_second_kind.test.cpp
---
