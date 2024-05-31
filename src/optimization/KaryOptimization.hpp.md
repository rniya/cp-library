---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: src/optimization/BinaryOptimization.hpp
    title: Binary Optimization (Project Selection Problem)
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
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
    \  File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.3/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/maxflow.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include \"BinaryOptimization.hpp\"\n\ntemplate <typename T,\
    \ bool MINIMIZE = true> struct KaryOptimization {\n    KaryOptimization() = default;\n\
    \n    KaryOptimization(const std::vector<int>& ks) : n(ks.size()), ks(ks), idx(ks.size())\
    \ {\n        int cur = 0;\n        for (int i = 0; i < n; i++) {\n           \
    \ assert(ks[i] > 0);\n            idx[i].resize(ks[i]);\n            idx[i][0]\
    \ = -1;\n            for (int d = 1; d < ks[i]; d++) idx[i][d] = cur++;\n    \
    \    }\n        bopt = BinaryOptimization<T, MINIMIZE>(cur);\n        for (int\
    \ i = 0; i < n; i++) {\n            for (int d = 1; d + 1 < ks[i]; d++) {\n  \
    \              bopt.add_10(idx[i][d], idx[i][d + 1], MINIMIZE ? inf : -inf);\n\
    \            }\n        }\n    }\n\n    void add(int i, const std::vector<T>&\
    \ theta) {\n        assert(0 <= i and i < n);\n        assert(theta.size() ==\
    \ ks[i]);\n        bopt.add(theta.back());\n        for (int d = 1; d < ks[i];\
    \ d++) bopt.add(idx[i][d], {0, theta[d - 1] - theta[d]});\n    }\n\n    void add(int\
    \ i, int j, std::vector<std::vector<T>> phi) {\n        assert(0 <= i and i <\
    \ n);\n        assert(0 <= j and j < n);\n        assert(phi.size() == ks[i]);\n\
    \        std::vector<T> theta_i(ks[i]), theta_j(ks[j]);\n        for (int d =\
    \ 0; d < ks[i]; d++) {\n            assert(phi[d].size() == ks[j]);\n        \
    \    theta_i[d] = phi[d][0];\n            for (int e = 0; e < ks[j]; e++) phi[d][e]\
    \ -= theta_i[d];\n        }\n        for (int e = 0; e < ks[j]; e++) {\n     \
    \       theta_j[e] = phi[0][e];\n            for (int d = 0; d < ks[i]; d++) phi[d][e]\
    \ -= theta_j[e];\n        }\n        add(i, theta_i);\n        add(j, theta_j);\n\
    \        for (int d = 1; d < ks[i]; d++) {\n            for (int e = 1; e < ks[j];\
    \ e++) {\n                T x = (phi[d][e] + phi[d - 1][e - 1]) - (phi[d][e -\
    \ 1] + phi[d - 1][e]);\n                assert(x <= 0);\n                bopt.add(idx[i][d],\
    \ idx[j][e], {x, 0, 0, 0});\n            }\n        }\n    }\n\n    std::pair<T,\
    \ std::vector<int>> solve() {\n        auto [ans, xs] = bopt.solve();\n      \
    \  std::vector<int> x(n, 0);\n        for (int i = 0; i < n; i++) {\n        \
    \    for (int d = 1; d < ks[i]; d++) {\n                x[i] += not xs[idx[i][d]];\n\
    \            }\n        }\n        return {ans, x};\n    }\n\n  private:\n   \
    \ static constexpr T inf = std::numeric_limits<T>::max() / 2;\n    int n;\n  \
    \  std::vector<int> ks;\n    std::vector<std::vector<int>> idx;\n    BinaryOptimization<T,\
    \ MINIMIZE> bopt;\n};\n"
  dependsOn:
  - src/optimization/BinaryOptimization.hpp
  isVerificationFile: false
  path: src/optimization/KaryOptimization.hpp
  requiredBy: []
  timestamp: '2024-06-01 01:35:37+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/optimization/KaryOptimization.hpp
layout: document
title: $K$-ary Optimization
---

**`MINIMIZE = false` は未 verify につき注意**

## 概要
$[k] \coloneqq \{0, 1, \dots , k - 1\}$ とする．
$\alpha \in \mathbb{Z},\ \theta_i \colon [k] \to \mathbb{Z}$ 及び Monge な関数 $\phi_{i, j} \colon [k]^2 \to \mathbb{Z}$ について
$$
\begin{alignedat}{3}
    & \mathrm{Minimize}     & \quad & \alpha + \sum_i \theta_i(x_i) + \sum_{i < j} \phi_{i, j}(x_i, x_j) \\
    & \mathrm{subject\ to}  & \quad & x \in [k]^n
\end{alignedat}
$$
を解く．
ここで，$0 \leq i_1 < i_2 < k$ 及び $0 \leq j_1 < j_2 < k$ を満たす任意の整数の組 $(i_1, i_2, j_1, j_2)$ について，$\phi(i_1, j_1) + \phi(i_2, j_2) \leq \phi(i_1, j_2) + \phi(i_2, j_1)$ が成立するとき，$\phi$ は Monge であるという．
また，これは $0 \leq i < k - 1$ 及び $0 \leq j < k - 1$ を満たす任意の整数の組 
$(i, j)$ について，$\phi(i, j) + \phi(i + 1, j + 1) \leq \phi(i, j + 1) + \phi(i + 1, j)$ が成立することと同値である．

## 問題例
- [AtCoder Regular Contest 129 E - Yet Another Minimization](https://atcoder.jp/contests/arc129/tasks/arc129_e?lang=ja)
- [AtCoder Beginner Contest 347 G - Grid Coloring 2](https://atcoder.jp/contests/abc347/tasks/abc347_g)

## Links
- [最小カット問題の $k$ 値への一般化 - noshi91のメモ](https://noshi91.hatenablog.com/entry/2021/06/29/044225)