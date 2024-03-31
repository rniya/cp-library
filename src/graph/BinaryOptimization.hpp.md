---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/graph/KaryOptimization.hpp
    title: K-ary Optimization
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2903.test.cpp
    title: test/aoj/2903.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1984.test.cpp
    title: test/yukicoder/1984.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.2/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/maxflow:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <array>\n#include <tuple>\n#include \"atcoder/maxflow\"\
    \n\ntemplate <typename T, bool MINIMIZE = true> struct BinaryOptimization {\n\
    \    BinaryOptimization() = default;\n\n    explicit BinaryOptimization(int n)\
    \ : n(n) {}\n\n    void add(T x) {\n        if (not MINIMIZE) x = -x;\n      \
    \  _add(x);\n    }\n\n    void add(int i, std::array<T, 2> x) {\n        assert(0\
    \ <= i and i < n);\n        if (not MINIMIZE) {\n            for (int i = 0; i\
    \ < 2; i++) {\n                x[i] = -x[i];\n            }\n        }\n     \
    \   _add(i, x);\n    }\n\n    void add_01(int i, int j, T x) {\n        assert(0\
    \ <= i and i < n);\n        assert(0 <= j and j < n);\n        if (not MINIMIZE)\
    \ x = -x;\n        assert(x >= 0);\n        add_edge(i, j, x);\n    }\n\n    void\
    \ add_10(int i, int j, T x) { add_01(j, i, x); }\n\n    void add(int i, int j,\
    \ std::array<std::array<T, 2>, 2> x) {\n        assert(0 <= i and i < n);\n  \
    \      assert(0 <= j and j < n);\n        if (not MINIMIZE) {\n            for\
    \ (int i = 0; i < 2; i++) {\n                for (int j = 0; j < 2; j++) {\n \
    \                   x[i][j] = -x[i][j];\n                }\n            }\n  \
    \      }\n        assert(x[0][1] + x[1][0] >= x[0][0] + x[1][1]);\n        _add(i,\
    \ j, x);\n    }\n\n    void add(int i, int j, int k, std::array<std::array<std::array<T,\
    \ 2>, 2>, 2> x) {\n        assert(0 <= i and i < n);\n        assert(0 <= j and\
    \ j < n);\n        assert(0 <= k and k < n);\n        if (not MINIMIZE) {\n  \
    \          for (int i = 0; i < 2; i++) {\n                for (int j = 0; j <\
    \ 2; j++) {\n                    for (int k = 0; k < 2; k++) {\n             \
    \           x[i][j][k] = -x[i][j][k];\n                    }\n               \
    \ }\n            }\n        }\n        _add(i, j, k, x);\n    }\n\n    void add_all_0(const\
    \ std::vector<int>& is, T x) {\n        if (not MINIMIZE) x = -x;\n        assert(x\
    \ <= 0);\n        if (is.size() == 0)\n            _add(x);\n        else if (is.size()\
    \ == 1)\n            _add(is[0], {x, 0});\n        else if (is.size() == 2)\n\
    \            _add(is[0], is[1], {x, 0, 0, 0});\n        else {\n            _add(x);\n\
    \            int nxt = n + aux++;\n            add_edge(source, nxt, -x);\n  \
    \          for (const int& i : is) {\n                assert(0 <= i and i < n);\n\
    \                add_edge(nxt, i, -x);\n            }\n        }\n    }\n\n  \
    \  void add_all_1(const std::vector<int>& is, T x) {\n        if (not MINIMIZE)\
    \ x = -x;\n        assert(x <= 0);\n        if (is.size() == 0)\n            _add(x);\n\
    \        else if (is.size() == 1)\n            _add(is[0], {0, x});\n        else\
    \ if (is.size() == 2)\n            _add(is[0], is[1], {0, 0, 0, x});\n       \
    \ else {\n            _add(x);\n            int nxt = n + aux++;\n           \
    \ add_edge(nxt, sink, -x);\n            for (const int& i : is) {\n          \
    \      assert(0 <= i and i < n);\n                add_edge(i, nxt, -x);\n    \
    \        }\n        }\n    }\n\n    std::pair<T, std::vector<bool>> solve() {\n\
    \        atcoder::mf_graph<T> g(n + aux + 2);\n        int s = n + aux, t = s\
    \ + 1;\n        for (auto [u, v, w] : es) {\n            u = (u == source ? s\
    \ : u == sink ? t : u);\n            v = (v == source ? s : v == sink ? t : v);\n\
    \            g.add_edge(u, v, w);\n        }\n        T sum = base + g.flow(s,\
    \ t);\n        auto cut = g.min_cut(s);\n        cut.resize(n);\n        for (int\
    \ i = 0; i < n; i++) cut[i] = not cut[i];\n        if (not MINIMIZE) sum = -sum;\n\
    \        return {sum, cut};\n    }\n\n  private:\n    int n, aux = 0, source =\
    \ -1, sink = -2;\n    T base = 0;\n    std::vector<std::tuple<int, int, T>> es;\n\
    \n    void add_edge(int i, int j, T x) {\n        assert(i == source or i == sink\
    \ or (0 <= i and i < n + aux));\n        assert(j == source or j == sink or (0\
    \ <= j and j < n + aux));\n        if (x == 0) return;\n        assert(x > 0);\n\
    \        es.emplace_back(i, j, x);\n    }\n\n    void _add(T x) { base += x; }\n\
    \n    void _add(int i, const std::array<T, 2>& x) {\n        if (x[0] <= x[1])\
    \ {\n            _add(x[0]);\n            add_edge(source, i, x[1] - x[0]);\n\
    \        } else {\n            _add(x[1]);\n            add_edge(i, sink, x[0]\
    \ - x[1]);\n        }\n    }\n\n    void _add(int i, int j, const std::array<std::array<T,\
    \ 2>, 2>& x) {\n        _add(i, {x[0][0], x[1][0]});\n        _add(j, {0, x[1][1]\
    \ - x[1][0]});\n        add_edge(i, j, (x[0][1] + x[1][0]) - (x[0][0] + x[1][1]));\n\
    \    }\n\n    void _add(int i, int j, int k, const std::array<std::array<std::array<T,\
    \ 2>, 2>, 2>& x) {\n        T P = x[0][0][0] - (x[1][0][0] + x[0][1][0] + x[0][0][1])\
    \ + (x[1][1][0] + x[0][1][1] + x[1][0][1]) - x[1][1][1];\n        if (P >= 0)\
    \ {\n            _add(x[0][0][0]);\n            _add(i, {0, x[1][0][0] - x[0][0][0]});\n\
    \            _add(j, {0, x[0][1][0] - x[0][0][0]});\n            _add(k, {0, x[0][0][1]\
    \ - x[0][0][0]});\n            _add(i, j, {0, 0, 0, (x[0][0][0] + x[1][1][0])\
    \ - (x[1][0][0] + x[0][1][0])});\n            _add(j, k, {0, 0, 0, (x[0][0][0]\
    \ + x[0][1][1]) - (x[0][1][0] + x[0][0][1])});\n            _add(k, i, {0, 0,\
    \ 0, (x[0][0][0] + x[1][0][1]) - (x[0][0][1] + x[1][0][0])});\n            _add(-P);\n\
    \            int nxt = n + aux++;\n            add_edge(i, nxt, P);\n        \
    \    add_edge(j, nxt, P);\n            add_edge(k, nxt, P);\n            add_edge(nxt,\
    \ sink, P);\n        } else {\n            _add(x[1][1][1]);\n            _add(i,\
    \ {x[0][1][1] - x[1][1][1], 0});\n            _add(j, {x[1][0][1] - x[1][1][1],\
    \ 0});\n            _add(k, {x[1][1][0] - x[1][1][1], 0});\n            _add(i,\
    \ j, {(x[1][1][1] + x[0][0][1]) - (x[0][1][1] + x[1][0][1]), 0, 0, 0});\n    \
    \        _add(j, k, {(x[1][1][1] + x[1][0][0]) - (x[1][0][1] + x[1][1][0]), 0,\
    \ 0, 0});\n            _add(k, i, {(x[1][1][1] + x[0][1][0]) - (x[1][1][0] + x[0][1][1]),\
    \ 0, 0, 0});\n            P = -P;\n            _add(-P);\n            int nxt\
    \ = n + aux++;\n            add_edge(nxt, i, P);\n            add_edge(nxt, j,\
    \ P);\n            add_edge(nxt, k, P);\n            add_edge(source, nxt, P);\n\
    \        }\n    }\n};"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/BinaryOptimization.hpp
  requiredBy:
  - src/graph/KaryOptimization.hpp
  timestamp: '2024-04-01 01:36:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2903.test.cpp
  - test/yukicoder/1984.test.cpp
documentation_of: src/graph/BinaryOptimization.hpp
layout: document
title: Binary Optimization (Project Selection Problem)
---

**`add(i, j, k, x), add_all_0(is, x), add_all_1(is, x)` は未 verify につき注意**

## 概要
Project Selection Problem，いわゆる燃やす埋める問題を解く際の補助ライブラリ．
具体的には $n$ 個の $01$ 変数 $x_1, \dots , x_n$ に対して各種損失条件が与えられる際に損失を最小化する割当を求める．
すなわち，$\alpha \in \mathbb{Z},\ \theta_i \colon \{0, 1\} \to \mathbb{Z},\ \phi_{i, j} \colon \{0, 1\}^2 \to \mathbb{Z},\ \psi_{i, j, k} \colon \{0, 1\}^3 \to \mathbb{Z}$ について
$$
\begin{alignedat}{3}
    & \mathrm{Minimize}     & \quad & \alpha + \sum_i \theta_i(x_i) + \sum_{i < j} \phi_{i, j}(x_i, x_j) + \sum_{i < j < k} \psi_{i, j, k}(x_i, x_j, x_k) \\
    & \mathrm{subject\ to}  & \quad & x \in \{0, 1\}^n
\end{alignedat}
$$
を解く．
また，$x_{i_1} = x_{i_2} = \dots x_{i_m}$ のときにのみ $c$ を減らすような関数も考慮可能である．

頂点 $i$ から $j$ への容量 $c$ の辺は $x_i = 0$ かつ $x_j = 1$ のときにのみコスト $c$ を発生させるものと考えると良い．
最大化したい場合は template 引数の `MINIMIZE` を `false` にする．

| メンバ関数              | 効果                                                 | 時間計算量           |
| ----------------------- | ---------------------------------------------------- | -------------------- |
| `BinaryOptimization(n)` | 頂点数 $n$ のグラフとして初期化する．                | $O(n)$               |
| `add(x)`                | $\alpha$ に $x$ を加える．                           | $O(1)$               |
| `add(i, x)`             | $\theta_i$ を設定する．                              | $O(1)$               |
| `add(i, j, x)`          | $\phi_{i, j}$ を設定する．                           | $O(1)$               |
| `add(i, j, k, x)`       | $\psi_{i, j, k}$ を設定する．                        | $O(1)$               |
| `add_all_0(is, x)`      | $\textit{is}$ の要素が全て $0$ のときに $x$ を得る． | $O(\|\textit{is}\|)$ |
| `add_all_1(is, x)`      | $\textit{is}$ の要素が全て $1$ のときに $x$ を得る． | $O(\|\textit{is}\|)$ |
| `solve()`               | 損失の最小値及びそれを達成する割当を返す．           | $O(n^2m)$            |

一般にこれ以外の条件に対応する際には 2 部グラフなどの制約が必要になる．

## 問題例
- [Codeforces Round #668 (Div. 1) E. Bricks](https://codeforces.com/contest/1404/problem/E)
- [AtCoder Regular Contest 085 E - MUL](https://atcoder.jp/contests/arc085/tasks/arc085_c)
- [AtCoder Regular Contest 107 F - Sum of Abs](https://atcoder.jp/contests/arc107/tasks/arc107_f)
- [AtCoder Regular Contest 129 E - Yet Another Minimization](https://atcoder.jp/contests/arc129/tasks/arc129_e)
  - 2 択だけでなく選択肢が $k$ 個あるような場合の問題．[このブログ](https://maspypy.com/atcoder-%e5%8f%82%e5%8a%a0%e6%84%9f%e6%83%b3-2020-10-31arc107)の F の解説にある辺の張り方が参考になる．ライブラリにしていいかもしれない．
- [2023牛客暑期多校训练营2 B Link with Railway Company](https://ac.nowcoder.com/acm/contest/57356/F)

## Links
- [最小カットを使って「燃やす埋める問題」を解く](https://www.slideshare.net/shindannin/project-selection-problem)
- [最小カットについて - よすぽの日記](https://yosupo.hatenablog.com/entry/2015/03/31/134336)
- [Project Selection (燃やす埋める) 周りの話についてもう少し考えた - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/12/25/000003)
- [続：『燃やす埋める』と『ProjectSelectionProblem』 - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/11/13/220607)
- [燃やす埋める問題と劣モジュラ関数のグラフ表現可能性 その① - 私と理論](https://theory-and-me.hatenablog.com/entry/2020/03/13/180935)