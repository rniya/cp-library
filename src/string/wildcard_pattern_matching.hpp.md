---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.11.5/x64/lib/python3.11/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution:\
    \ line -1: no such header\n"
  code: "#include <string>\n#include \"atcoder/convolution\"\n\nstd::vector<bool>\
    \ wildcard_pattern_matching(const std::string& s, const std::string& t, char wild\
    \ = '?') {\n    int n = s.size(), m = t.size();\n    assert(n >= m);\n    char\
    \ mini = s[0];\n    for (const auto& c : s) {\n        if (c != wild) {\n    \
    \        mini = std::min(mini, c);\n        }\n    }\n    for (const auto& c :\
    \ s) {\n        if (c != wild) {\n            mini = std::min(mini, c);\n    \
    \    }\n    }\n    std::vector<atcoder::modint998244353> f1(n), f2(n), f3(n),\
    \ g1(m), g2(m), g3(m);\n    for (int i = 0; i < n; i++) {\n        f1[i] = (s[i]\
    \ == wild ? 0 : s[i] - mini + 1);\n        f2[i] = f1[i] * f1[i];\n        f3[i]\
    \ = f2[i] * f1[i];\n    }\n    for (int i = 0; i < m; i++) {\n        g1[m - 1\
    \ - i] = (t[i] == wild ? 0 : t[i] - mini + 1);\n        g2[m - 1 - i] = g1[m -\
    \ 1 - i] * g1[m - 1 - i];\n        g3[m - 1 - i] = g2[m - 1 - i] * g1[m - 1 -\
    \ i];\n    }\n    auto h1 = atcoder::convolution(f1, g3);\n    auto h2 = atcoder::convolution(f2,\
    \ g2);\n    auto h3 = atcoder::convolution(f3, g1);\n    std::vector<bool> res(n\
    \ - m + 1);\n    for (int i = 0; i < n - m + 1; i++) res[i] = (h1[m - 1 + i] -\
    \ 2 * h2[m - 1 + i] + h3[m - 1 + i] == 0);\n    return res;\n}"
  dependsOn: []
  isVerificationFile: false
  path: src/string/wildcard_pattern_matching.hpp
  requiredBy: []
  timestamp: '2023-10-07 00:10:49+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/string/wildcard_pattern_matching.hpp
layout: document
title: Wildcard Pattern Matching
---

## 概要
長さ $n$ の文字列 $S$ と長さ $m$ の文字列 $T$ を入力とし，$i = 0, \dots , n - m$ について，$S[i, i + m)$ と $T$ が一致するか判定する．
ただし，2 つの文字列は任意の一文字を指し示すワイルドカードを含むことがある．

$$
\mathrm{cmp}(s, t) = s t (s - t)^2
$$
を定めると，$\mathrm{cmp}(s, t)$ は $s = t$ もしくは $s, t$ の少なくとも一方がワイルドカードに一致するときにのみ $0$ となり，それ以外の場合は正の値を取る．
従って，
$$
\begin{aligned}
    S[i,  i + m) = T
    &\iff \sum_{k = 0}^{m - 1} \mathrm{cmp}(S[i + k], T[k]) = 0 \\
    &\iff \sum_{k = 0}^{m - 1} S[i + k]^3 T[k] - 2 S[i + k]^2 T[k]^2 + S[i + k] T[k]^3 = 0
\end{aligned}
$$
が成立し，最後の式を畳み込みにより計算することで $\mathrm{O}((n + m) \log (n + m))$ 時間で計算可能である．

## 問題例
- [AtCoder Beginner Contest 307 Ex - Marquee](https://atcoder.jp/contests/abc307/tasks/abc307_h)