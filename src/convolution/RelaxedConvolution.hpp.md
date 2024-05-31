---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/convolution_mod.relaxedconvolution.test.cpp
    title: test/yosupo/convolution_mod.relaxedconvolution.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"../atcoder/convolution\"\n\ntemplate <class T> class\
    \ RelaxedConvolution {\n    int n;\n    std::vector<T> f, g, h;\n\n  public:\n\
    \    RelaxedConvolution() : n(0) {}\n\n    T query(T a, T b) {\n        f.emplace_back(a);\n\
    \        g.emplace_back(b);\n        h.emplace_back(0);\n        if (n > 0) h.emplace_back(0);\n\
    \        int p = __builtin_ctz(n + 2);\n        for (int k = 0; k <= p; k++) {\n\
    \            {\n                std::vector<T> f1(f.begin() + (1 << k) - 1, f.begin()\
    \ + (1 << (k + 1)) - 1);\n                std::vector<T> g1(g.end() - (1 << k),\
    \ g.end());\n                auto c1 = atcoder::convolution(f1, g1);\n       \
    \         for (int i = 0; i < (1 << (k + 1)) - 1; i++) h[n + i] += c1[i];\n  \
    \          }\n            if ((1 << p) == n + 2 and k == p - 1) break;\n     \
    \       {\n                std::vector<T> f2(f.end() - (1 << k), f.end());\n \
    \               std::vector<T> g2(g.begin() + (1 << k) - 1, g.begin() + (1 <<\
    \ (k + 1)) - 1);\n                auto c2 = atcoder::convolution(f2, g2);\n  \
    \              for (int i = 0; i < (1 << (k + 1)) - 1; i++) h[n + i] += c2[i];\n\
    \            }\n        }\n        return h[n++];\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/convolution/RelaxedConvolution.hpp
  requiredBy: []
  timestamp: '2024-06-01 02:28:17+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/convolution_mod.relaxedconvolution.test.cpp
documentation_of: src/convolution/RelaxedConvolution.hpp
layout: document
title: Relaxed Convolution
---

## 概要
未知の $n$ 次多項式 $f, g$ があり，$h(x) = f(x) g(x)$ であるとき，$i = 0, 1, \dots , n$ の順に以下のクエリを計 $\mathrm{O}(n (\log n)^2)$ 時間で処理する．
- $[x^i] f(x), [x^i] g(x)$ が与えられるので，$[x^i] h(x)$ を返す．

## Links
- [オンライン畳み込み - Qiita](https://qiita.com/Kiri8128/items/1738d5403764a0e26b4c)

## 出題例
- [AtCoder Beginner Contest 230 H - Bullion](https://atcoder.jp/contests/abc230/tasks/abc230_h)
- [AtCoder Beginner Contest 315 Ex - Typical Convolution Problem](https://atcoder.jp/contests/abc315/tasks/abc315_h)
