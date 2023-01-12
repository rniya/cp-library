---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/polynomial/FormalPowerSeries.hpp
    title: "Formal Power Series\uFF08\u5F62\u5F0F\u7684\u51AA\u7D1A\u6570\uFF09"
  - icon: ':question:'
    path: src/util/modint.hpp
    title: src/util/modint.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/product_of_polynomial_sequence
    links:
    - https://judge.yosupo.jp/problem/product_of_polynomial_sequence
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.1/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: polynomial/FormalPowerSeries.hpp:\
    \ line -1: no such header\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/product_of_polynomial_sequence\"\
    \n\n#include \"polynomial/FormalPowerSeries.hpp\"\n#include \"util/modint.hpp\"\
    \n\nusing mint = atcoder::modint998244353;\nusing FPS = FormalPowerSeries<mint>;\n\
    \nint main() {\n    std::cin.tie(0);\n    std::ios::sync_with_stdio(false);\n\
    \    int N;\n    std::cin >> N;\n    std::vector<FPS> fs;\n    for (; N--;) {\n\
    \        int d;\n        std::cin >> d;\n        FPS a(d + 1);\n        for (int\
    \ i = 0; i <= d; i++) std::cin >> a[i];\n        fs.emplace_back(a);\n    }\n\n\
    \    auto res = FPS::product_of_polynomial_sequence(fs);\n    for (size_t i =\
    \ 0; i < res.size(); i++) std::cout << res[i] << (i + 1 == res.size() ? '\\n'\
    \ : ' ');\n    return 0;\n}"
  dependsOn:
  - src/polynomial/FormalPowerSeries.hpp
  - src/util/modint.hpp
  isVerificationFile: true
  path: test/yosupo/product_of_polynomial_sequence.test.cpp
  requiredBy: []
  timestamp: '2023-01-12 23:01:53+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/product_of_polynomial_sequence.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/product_of_polynomial_sequence.test.cpp
- /verify/test/yosupo/product_of_polynomial_sequence.test.cpp.html
title: test/yosupo/product_of_polynomial_sequence.test.cpp
---
