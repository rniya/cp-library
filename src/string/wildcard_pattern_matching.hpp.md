---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/wildcard_pattern_matching.test.cpp
    title: test/yosupo/wildcard_pattern_matching.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ~~~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n    ~~~~~~~~~~~~~~^^^^^^\n  File\
    \ \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \    ~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ~~~~~~~~~~~~~^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.13.3/x64/lib/python3.13/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/convolution.hpp:\
    \ line -1: no such header\n"
  code: "#include <string>\n#include \"../atcoder/convolution\"\n\nstd::vector<bool>\
    \ wildcard_pattern_matching(const std::string& s, const std::string& t, char wild\
    \ = '?') {\n    int n = s.size(), m = t.size();\n    assert(n >= m and n > 0);\n\
    \    char mini = s[0];\n    for (const auto& c : s) {\n        if (c != wild)\
    \ {\n            mini = std::min(mini, c);\n        }\n    }\n    for (const auto&\
    \ c : t) {\n        if (c != wild) {\n            mini = std::min(mini, c);\n\
    \        }\n    }\n    std::vector<atcoder::modint998244353> f1(n), f2(n), f3(n),\
    \ g1(m), g2(m), g3(m);\n    for (int i = 0; i < n; i++) {\n        atcoder::modint998244353\
    \ x = (s[i] == wild ? 0 : s[i] - mini + 1), y = (s[i] == wild ? 0 : 1);\n    \
    \    f1[i] = y;\n        f2[i] = y * x;\n        f3[i] = y * x * x;\n    }\n \
    \   for (int i = 0; i < m; i++) {\n        atcoder::modint998244353 x = (t[i]\
    \ == wild ? 0 : t[i] - mini + 1), y = (t[i] == wild ? 0 : 1);\n        g1[m -\
    \ 1 - i] = y;\n        g2[m - 1 - i] = y * x;\n        g3[m - 1 - i] = y * x *\
    \ x;\n    }\n    auto h1 = atcoder::convolution(f1, g3);\n    auto h2 = atcoder::convolution(f2,\
    \ g2);\n    auto h3 = atcoder::convolution(f3, g1);\n    std::vector<bool> res(n\
    \ - m + 1);\n    for (int i = 0; i < n - m + 1; i++) {\n        res[i] = (h1[m\
    \ - 1 + i] - 2 * h2[m - 1 + i] + h3[m - 1 + i] == 0);\n    }\n    return res;\n\
    }\n"
  dependsOn: []
  isVerificationFile: false
  path: src/string/wildcard_pattern_matching.hpp
  requiredBy: []
  timestamp: '2024-05-26 15:33:49+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/wildcard_pattern_matching.test.cpp
documentation_of: src/string/wildcard_pattern_matching.hpp
layout: document
title: Wildcard Pattern Matching
---

## 入力
文字列 $S, T\ (\vert S \vert \geq \vert T \vert)$

## 出力

長さの等しい文字列 $S ^ \prime, T ^ \prime$ が各 $0 \leq i < \vert S ^ \prime \vert $ について

- $S ^ \prime _ i = T ^ \prime _ i$
- $S ^ \prime _ i$ が wildcard
- $T ^ \prime _ i$ が wildcard

のいずれかを満たすとき，$S ^ \prime$ と $T ^ \prime$ はマッチすると呼ぶことにする．

このときの

$$
v_i = 
\begin{cases}
1 & \text{($S \lbrack i, i + \vert T \vert)$ と $T$ がマッチしている)} \\
0 & \text{(otherwise)}
\end{cases}
\quad (0 \leq i \leq \vert S \vert - \vert T \vert)
$$

で定まる長さ $\vert S \vert - \vert T \vert + 1$ の配列 $v$

## 計算量

- 時間計算量 $\mathrm{O}((\vert S \vert + \vert T \vert) \log (\vert S \vert + \vert T \vert))$
- 空間計算量 $\mathrm{O}(\vert S \vert + \vert T \vert)$

## 概要

### 決定的解法

任意の文字 $s, t$ について

$$
\mathrm{cmp}(s, t) := (s - t)^2 \mathbf{1}(s \gt 0) \mathbf{1}(t \gt 0)
$$

と定めると，$\mathrm{cmp}(s, t)$ は $s = t$ もしくは $s, t$ の少なくとも一方が wildcard に一致するときにのみ $0$ となり，それ以外の場合は正の値を取る．
ただし，$\mathbf{1}(x)$ は命題 $x$ が真のとき $1$，偽のとき $0$ を返す関数とする．

従って，

$$
\begin{aligned}
    S \lbrack i,  i + \vert T \vert) = T
    && \iff & \sum _ {k = 0} ^ {\vert T \vert - 1} \mathrm{cmp}(S \lbrack i + k \rbrack, T \lbrack k \rbrack) = 0 \\
    && \iff & \sum _ {k = 0} ^ {\vert T \vert - 1} \left \lbrack  S \lbrack i + k \rbrack^2 \mathbf{1}(S \lbrack i + k \rbrack \gt 0) \mathbf{1}(T \lbrack k \rbrack \gt 0) \right. \\
    &&& - 2 S \lbrack i + k \rbrack T \lbrack k \rbrack \mathbf{1}(S \lbrack i + k \rbrack \gt 0) \mathbf{1}(T \lbrack k \rbrack \gt 0) \\
    &&& \left. + T \lbrack k \rbrack^2 \mathbf{1}(S \lbrack i + k \rbrack \gt 0) \mathbf{1}(T \lbrack k \rbrack \gt 0) \right \rbrack = 0
\end{aligned}
$$

が成立し，最後の式は畳み込みにより計算可能である．

また，現れる文字の種類数を $\sigma$ として，畳み込んだ結果現れる数値の最大値 $\sigma ^ 2 \vert T\vert$ が畳み込みで用いる $\text{mod}$ 未満ならば判定は決定的となる．

### 乱択解法

素数 $P \geq \sigma$ 及び $0$ 以上 $P$ 未満の一様乱数 $r _ k\ (k = 0, \dots , \vert T \vert - 1)$ を取る．
マッチの判定式を

$$
\sum _ {k = 0} ^ {\vert T \vert - 1} r _ k (S \lbrack i + k \rbrack - T \lbrack k \rbrack) \mathbf{1}(S \lbrack i + k \rbrack \gt 0) \mathbf{1}(T \lbrack k \rbrack \gt 0)
\equiv 0 \pmod{P}
$$

と改めると，Schwartz-Zippel の補題よりこの判定式によりマッチしていないのにマッチしていると誤って判定される確率は $1 / P$ 以下となる．
<!-- $\sigma$ や $\vert T \vert$ の値によらず，畳み込みの回数も決定的解法に比べて 1 回減り高速なため本実装ではこちらを採用している． -->

## 出題例
- [AtCoder Beginner Contest 307 Ex - Marquee](https://atcoder.jp/contests/abc307/tasks/abc307_h)
- [DEGwer さんの D 論応援コンテスト H - Incomplete Notes](https://atcoder.jp/contests/DEGwer2023/tasks/1202Contest_h)
- [Codeforces Round 947 (Div. 1 + Div. 2) G. Zimpha Fan Club](https://codeforces.com/contest/1975/problem/G)

## Links
- [ワイルドカードマッチングの高速化 - noshi91のメモ](https://noshi91.hatenablog.com/entry/2024/05/26/060854)