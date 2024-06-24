---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/polynomial/FormalPowerSeries.hpp
    title: Formal Power Series
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.4/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#include <vector>\n#include \"FormalPowerSeries.hpp\"\n\nnamespace internal\
    \ {\n\ntemplate <typename T>\nstd::vector<FormalPowerSeries<T>> convolution2d(const\
    \ std::vector<FormalPowerSeries<T>>& f,\n                                    \
    \            const std::vector<FormalPowerSeries<T>>& g) {\n    int h1 = f.size(),\
    \ w1 = h1 == 0 ? 0 : f[0].size();\n    int h2 = g.size(), w2 = h2 == 0 ? 0 : g[0].size();\n\
    \    int h = h1 + h2 - 1, w = w1 + w2 - 1;\n    std::vector<T> ff(h1 * w, 0),\
    \ gg(h2 * w, 0);\n    for (int x = 0; x < h1; x++) {\n        assert(f[x].size()\
    \ == w1);\n        for (int y = 0; y < w1; y++) {\n            ff[x * w + y] =\
    \ f[x][y];\n        }\n    }\n    for (int x = 0; x < h2; x++) {\n        assert(g[x].size()\
    \ == w2);\n        for (int y = 0; y < w2; y++) {\n            gg[x * w + y] =\
    \ g[x][y];\n        }\n    }\n    auto hh = atcoder::convolution(ff, gg);\n  \
    \  std::vector res(h, FormalPowerSeries<T>(w));\n    for (int x = 0; x < h; x++)\
    \ {\n        for (int y = 0; y < w; y++) {\n            res[x][y] = hh[x * w +\
    \ y];\n        }\n    }\n    return res;\n}\n\n}  // namespace internal\n\ntemplate\
    \ <typename T> std::vector<T> coefficient_of_powers(std::vector<T> f, std::vector<T>\
    \ g, int n, int deg) {\n    assert(f[0] == 0);\n    f.resize(deg + 1);\n    g.resize(deg\
    \ + 1);\n    std::vector P(deg + 1, FormalPowerSeries<T>(2, T(0))), Q(deg + 1,\
    \ FormalPowerSeries<T>(2, T(0)));\n    for (int i = 0; i <= deg; i++) {\n    \
    \    P[i][0] = g[i];\n        Q[i][1] = -f[i];\n    }\n    Q[0][0] = 1;\n    for\
    \ (; deg; deg >>= 1) {\n        auto Q_neg = Q;\n        for (int i = 1; i < int(Q_neg.size());\
    \ i += 2) {\n            for (auto& val : Q_neg[i]) {\n                val = -val;\n\
    \            }\n        }\n        auto nP = internal::convolution2d(P, Q_neg);\n\
    \        auto nQ = internal::convolution2d(Q, Q_neg);\n        P.resize(deg /\
    \ 2 + 1);\n        Q.resize(deg / 2 + 1);\n        for (int i = 0; i <= deg /\
    \ 2; i++) P[i] = nP[i << 1 | (deg & 1)];\n        for (int i = 0; i <= deg / 2;\
    \ i++) Q[i] = nQ[i << 1];\n        for (int i = 0; i < int(P.size()); i++) {\n\
    \            if (int(P[i].size()) > n)\n                P[i].resize(n);\n    \
    \        else\n                break;\n        }\n        for (int i = 0; i <\
    \ int(Q.size()); i++) {\n            if (int(Q[i].size()) > n)\n             \
    \   Q[i].resize(n);\n            else\n                break;\n        }\n   \
    \ }\n    P[0].resize(n);\n    Q[0].resize(n);\n    return P[0] * Q[0].inv();\n\
    }"
  dependsOn:
  - src/polynomial/FormalPowerSeries.hpp
  isVerificationFile: false
  path: src/polynomial/coefficient_of_powers.hpp
  requiredBy: []
  timestamp: '2024-05-22 00:21:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/polynomial/coefficient_of_powers.hpp
layout: document
title: Power Projection
---

## 出題例
- [AtCoder Beginner Contest 345 G - Sugoroku 5](https://atcoder.jp/contests/abc345/tasks/abc345_g)

## Links
- [FPS の合成と逆関数、冪乗の係数列挙 $\Theta(n (\log(n)) ^ 2)$ - noshi91のメモ](https://noshi91.hatenablog.com/entry/2024/03/16/224034)
