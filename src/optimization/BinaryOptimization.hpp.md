---
data:
  _extendedDependsOn: []
  _extendedRequiredBy:
  - icon: ':warning:'
    path: src/optimization/KaryOptimization.hpp
    title: $K$-ary Optimization
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
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/maxflow.hpp:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <array>\n#include <tuple>\n#include \"../atcoder/maxflow\"\
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
  path: src/optimization/BinaryOptimization.hpp
  requiredBy:
  - src/optimization/KaryOptimization.hpp
  timestamp: '2024-06-01 01:35:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/1984.test.cpp
  - test/aoj/2903.test.cpp
documentation_of: src/optimization/BinaryOptimization.hpp
layout: document
title: Binary Optimization (Project Selection Problem)
---

**`add(i, j, k, x), add_all_0(is, x), add_all_1(is, x)` は未 verify につき注意**

## 概要

Project Selection Problem，いわゆる燃やす埋める問題を解く際の補助ライブラリ．
具体的には $n$ 個の $01$ 変数 $x _ 1, \dots , x _ n$ に対して各種損失条件が与えられる際に損失を最小化する割当を求める．
すなわち，$\alpha \in \mathbb{Z}, \theta _ i \colon \lbrace 0, 1 \rbrace \to \mathbb{Z}, \phi _ {i, j} \colon \lbrace 0, 1 \rbrace ^ 2 \to \mathbb{Z}, \psi _ {i, j, k} \colon \lbrace 0, 1 \rbrace ^ 3 \to \mathbb{Z}$ について，

$$
\begin{alignedat}{3}
    & \mathrm{Minimize}     & \quad & \alpha + \sum _ i \theta _ i(x _ i) + \sum _ {i \lt j} \phi _ {i, j}(x _ i, x _ j) + \sum _ {i \lt j \lt k} \psi _ {i, j, k}(x _ i, x _ j, x _ k) \\
    & \mathrm{subject\ to}  & \quad & x \in \lbrace 0, 1 \rbrace ^ n
\end{alignedat}
$$

を解く．
また，$x _ {i _ 1} = x _ {i _ 2} = \dots x _ {i _ m}$ のときにのみ $c$ を減らすような関数も考慮可能である．

頂点 $i$ から $j$ への容量 $c$ の辺は $x _ i = 0$ かつ $x _ j = 1$ のときにのみコスト $c$ を発生させるものと考えると良い．
最大化したい場合は template 引数の `MINIMIZE` を `false` にする．

| メンバ関数              | 効果                                                 | 時間計算量                            |
| ----------------------- | ---------------------------------------------------- | ------------------------------------- |
| `BinaryOptimization(n)` | 頂点数 $n$ のグラフとして初期化する．                | $\mathrm{O}(n)$                       |
| `add(x)`                | $\alpha$ に $x$ を加える．                           | $\mathrm{O}(1)$                       |
| `add(i, x)`             | $\theta _ i$ を設定する．                            | $\mathrm{O}(1)$                       |
| `add(i, j, x)`          | $\phi _ {i, j}$ を設定する．                         | $\mathrm{O}(1)$                       |
| `add(i, j, k, x)`       | $\psi _ {i, j, k}$ を設定する．                      | $\mathrm{O}(1)$                       |
| `add_all_0(is, x)`      | $\textit{is}$ の要素が全て $0$ のときに $x$ を得る． | $\mathrm{O}(\vert \textit{is} \vert)$ |
| `add_all_1(is, x)`      | $\textit{is}$ の要素が全て $1$ のときに $x$ を得る． | $\mathrm{O}(\vert \textit{is} \vert)$ |
| `solve()`               | 損失の最小値及びそれを達成する割当を返す．           | $\mathrm{O}(n^2m)$                    |

`solve()` の計算量に現れる $n, m$ はそれぞれできあがったネットワークの頂点の個数，辺の本数である．
一般にこれ以外の条件に対応する際には 2 部グラフなどの制約が必要になる．

## 出題例
- [Codeforces Round #668 (Div. 1) E. Bricks](https://codeforces.com/contest/1404/problem/E)
- [AtCoder Regular Contest 085 E - MUL](https://atcoder.jp/contests/arc085/tasks/arc085_c)
- [AtCoder Grand Contest 038 F - Two Permutations](https://atcoder.jp/contests/agc038/tasks/agc038_f)
- [AtCoder Regular Contest 107 F - Sum of Abs](https://atcoder.jp/contests/arc107/tasks/arc107_f)
- [2023牛客暑期多校训练营2 B Link with Railway Company](https://ac.nowcoder.com/acm/contest/57356/F)
- [AtCoder Regular Contest 176 E - Max Vector](https://atcoder.jp/contests/arc176/tasks/arc176_e)

## Links
- [最小カットを使って「燃やす埋める問題」を解く](https://www.slideshare.net/shindannin/project-selection-problem)
- [最小カットについて - よすぽの日記](https://yosupo.hatenablog.com/entry/2015/03/31/134336)
- [Project Selection (燃やす埋める) 周りの話についてもう少し考えた - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/12/25/000003)
- [続：『燃やす埋める』と『ProjectSelectionProblem』 - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/11/13/220607)
- [燃やす埋める問題と劣モジュラ関数のグラフ表現可能性 その① - 私と理論](https://theory-and-me.hatenablog.com/entry/2020/03/13/180935)
