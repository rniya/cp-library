---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/assignment.test.cpp
    title: test/yosupo/assignment.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/optimization/hungarian.hpp\"\n#include <cassert>\n#include\
    \ <limits>\n#include <utility>\n#include <vector>\n\ntemplate <class Cost> std::pair<Cost,\
    \ std::vector<int>> hungarian(const std::vector<std::vector<Cost>>& a) {\n   \
    \ const Cost inf = std::numeric_limits<Cost>::max();\n    int n = a.size(), m\
    \ = a[0].size();\n    assert(n <= m);\n    std::vector<int> P(m + 1, -1);\n  \
    \  std::vector<Cost> yl(n, 0), yr(m + 1, 0);\n    for (int i = 0; i < n; i++)\
    \ {\n        std::vector<Cost> adjmin(m + 1, inf);\n        std::vector<bool>\
    \ inL(m + 1, false);\n        std::vector<int> pre(m + 1, -1);\n        int j_cur\
    \ = m;\n        P[j_cur] = i;\n        while (P[j_cur] != -1) {\n            inL[j_cur]\
    \ = true;\n            int i_cur = P[j_cur], j_nxt = 0;\n            Cost delta\
    \ = inf;\n            for (int j = 0; j < m; j++) {\n                if (inL[j])\
    \ continue;\n                Cost w = a[i_cur][j] - yl[i_cur] - yr[j];\n     \
    \           if (w < adjmin[j]) adjmin[j] = w, pre[j] = j_cur;\n              \
    \  if (adjmin[j] < delta) delta = adjmin[j], j_nxt = j;\n            }\n     \
    \       for (int j = 0; j <= m; j++) {\n                if (inL[j])\n        \
    \            yl[P[j]] += delta, yr[j] -= delta;\n                else\n      \
    \              adjmin[j] -= delta;\n            }\n            j_cur = j_nxt;\n\
    \        }\n        for (; j_cur != m; j_cur = pre[j_cur]) P[j_cur] = P[pre[j_cur]];\n\
    \    }\n    std::vector<int> res(n);\n    for (int i = 0; i < m; i++) {\n    \
    \    if (P[i] != -1) {\n            res[P[i]] = i;\n        }\n    }\n    return\
    \ {-yr[m], res};\n}\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <utility>\n\
    #include <vector>\n\ntemplate <class Cost> std::pair<Cost, std::vector<int>> hungarian(const\
    \ std::vector<std::vector<Cost>>& a) {\n    const Cost inf = std::numeric_limits<Cost>::max();\n\
    \    int n = a.size(), m = a[0].size();\n    assert(n <= m);\n    std::vector<int>\
    \ P(m + 1, -1);\n    std::vector<Cost> yl(n, 0), yr(m + 1, 0);\n    for (int i\
    \ = 0; i < n; i++) {\n        std::vector<Cost> adjmin(m + 1, inf);\n        std::vector<bool>\
    \ inL(m + 1, false);\n        std::vector<int> pre(m + 1, -1);\n        int j_cur\
    \ = m;\n        P[j_cur] = i;\n        while (P[j_cur] != -1) {\n            inL[j_cur]\
    \ = true;\n            int i_cur = P[j_cur], j_nxt = 0;\n            Cost delta\
    \ = inf;\n            for (int j = 0; j < m; j++) {\n                if (inL[j])\
    \ continue;\n                Cost w = a[i_cur][j] - yl[i_cur] - yr[j];\n     \
    \           if (w < adjmin[j]) adjmin[j] = w, pre[j] = j_cur;\n              \
    \  if (adjmin[j] < delta) delta = adjmin[j], j_nxt = j;\n            }\n     \
    \       for (int j = 0; j <= m; j++) {\n                if (inL[j])\n        \
    \            yl[P[j]] += delta, yr[j] -= delta;\n                else\n      \
    \              adjmin[j] -= delta;\n            }\n            j_cur = j_nxt;\n\
    \        }\n        for (; j_cur != m; j_cur = pre[j_cur]) P[j_cur] = P[pre[j_cur]];\n\
    \    }\n    std::vector<int> res(n);\n    for (int i = 0; i < m; i++) {\n    \
    \    if (P[i] != -1) {\n            res[P[i]] = i;\n        }\n    }\n    return\
    \ {-yr[m], res};\n}\n"
  dependsOn: []
  isVerificationFile: false
  path: src/optimization/hungarian.hpp
  requiredBy: []
  timestamp: '2024-06-01 01:35:37+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/assignment.test.cpp
documentation_of: src/optimization/hungarian.hpp
layout: document
title: Hungarian (Assignment Problem)
---

## 入力

$n \times m$ 行列 $a\ (n \le m)$．

## 出力

$\min _ {p \in \mathcal{S} _ n} \sum _ {i = 0} ^ {n - 1} a _ {i, p _ i}$ 及びそれを達成する順列 $p$．

## 計算量

時間計算量 $\mathrm{O}(n m \min(n, m))$．

## 概要

割当問題は左側頂点集合 $A$ 及び右側頂点集合 $B$ からなる二部グラフの最小重み完全マッチングを求める問題と等価である．

まず，簡単のために $\vert A \vert = \vert B \vert$ の場合について考えると，辺 $(i, j)\ (i \in A, j \in B)$ の重みを $c _ {i, j}$ として，

$$
\begin{alignedat}{5}
    & \mathrm{Minimize}     & \quad & \sum _ {i, j} c _ {i, j} x _ {i, j} \\
    & \mathrm{subject\ to}  & \quad & \sum _ j x _ {i, j} = 1 & \quad & (\forall i \in A) \\
    &                       & \quad & \sum_i x _ {i, j} = 1 & \quad & (\forall j \in B) \\
    &                       & \quad & x _ {i, j} \in \lbrace 0, 1 \rbrace
\end{alignedat}
$$

と定式化することができ，これを (IP) とする．
制約 $x _ {i, j} \in \lbrace 0, 1 \rbrace$ を $x _ {i, j} \ge 0$ に緩和した問題 (LP) の双対問題 (DLP) は，

$$
\begin{alignedat}{5}
    & \mathrm{Maximize}     & \quad & \sum _ i y _ i + \sum _ j y _ j \\
    & \mathrm{subject\ to}  & \quad & y _ i + y _ j \le c _ {i, j} & \quad & (\forall (i, j) \in A \times B)
\end{alignedat}
$$

と表せる．
これは任意の $i \in A,\ j \in B$ について $y _ i + y _ j \le c _ {i, j}$ を満たすようなノードポテンシャル $y \colon (A \cup B) \to \mathbb{R}$ を各頂点がもつと解釈することができる．
完全マッチングの重みがポテンシャルの総和 $\sum _ {v \in A \cup B} y _ v$ 以上であることはマッチングが全ての頂点をカバーすることから明らかである ($\mathrm{(IP)} \geq \mathrm{(DLP)}$)．
また，これらの値が等しいようなマッチング及びポテンシャルがあるとき，そのマッチングが任意のマッチングの中で最小の重みをもつこともわかる．
Hungarian 法とはこれらの値が等しくなるようなマッチング及びポテンシャルを同時に構成する主双対アルゴリズムである．

## アルゴリズムの詳細
補助二部グラフ $G _ y = (A, B, E _ y)$ を $E _ y = \lbrace (i, j) \mid y _ i + y _ j = c _ {i, j} \rbrace$ として構成する．
マッチング $M$ を空集合で，ポテンシャル $y$ を $y _ i = 0\ (\forall i \in A), y _ j =  \min _ i c _ {i, j}\ (j \in B)$  で初期化する．
この $y$ が (DLP) の実行可能解であることは明らかである．
これを順次更新し，その過程で $M$ が $G$ の完全マッチングとなれば，$M$ 及び $y$ が所望のものである．
そうでないとき，以下のようにして $M$ 及び $y$ を更新する．

$G _ y$ の辺集合 $E _ y$ を，最大マッチング $M$ に属するならば $B$ から $A$ に，そうでなければ $A$ から $B$ に向き付けた有向二部グラフを $\vec{G} _ y$ とする．
マッチングの端点集合を $\partial M$，$A ^ \ast = A \setminus \partial M, B ^ \ast = B \setminus \partial M$，$\vec{G} _ y$ 上で $A ^ \ast$ から到達可能な頂点集合を $L$ とする．
$L$ は BFS で $\mathrm{O}(n + m)$ 時間で計算可能である．
$L \cap B ^ \ast \neq \emptyset$ のとき，グラフには増加道が存在するからこれに従ってマッチング $M$ を更新する．
そうでないとき，$M$ は $G _ y$ の最大マッチングであり，ポテンシャル $y$ を更新することを考えたい．
ここで，$G _ y$ 上で $A \cap L$ と $B \setminus L$ の間には辺は存在しない．

<details>
<summary>証明</summary>
<div>

$e = (u, v) \in E _ y\ (u \in A \cap L, v \in B \setminus L)$ が存在するとする．
$e \in M$ のとき，$u \in L$ かつ $u \notin A ^ \ast$ より $v \in L$ が成立する必要があるが，これは $v \notin L$ に矛盾する．
$e \in E _ y \setminus M$ とすると，$u \in L$ より $L$ の定義から $v \in L$ で同様に矛盾が導ける．

$\blacksquare$

</div>
</details>

すなわち，任意の $i \in A \cap L, j \in B \setminus L$ について $y _ i + y _ j \lt c _ {i, j}$ が成立する．
このとき，

$$
\delta := \min _ {i \in A \cap L, j \in B \setminus L} (c _ {i, j} - y _ i - y _ j)
$$

とすると，$\delta \gt 0$ であり，これをもとにポテンシャル $y ^ \prime$ を次のように得る：

$$
y ^ \prime _ i = \begin{cases}
    y _ i             & (i \in A \setminus L) \\
    y _ i + \delta    & (i \in A \cap L)
\end{cases}, \quad
y ^ \prime _ j = \begin{cases}
    y _ j             & (j \in B \setminus L) \\
    y _ j - \delta    & (j \in B \cap L)
\end{cases}
$$

この $y ^ \prime$ も (DLP) の実行可能解である．


<details>
<summary>証明</summary>
<div>

$i \in A \cap L$ かつ $j \in B \setminus L$ のとき，

$$
\begin{aligned}
    y ^ \prime _ i + y ^ \prime _ j
    & = y _ i + y _ j + \delta \\
    & = y _ i + y _ j + \min _ {i \in A \cap L, j \in B \setminus L} (c _ {i, j} - y _ i - y _ j) \\
    & \leq y _ i + y _ j + (c _ {i, j} - y _ i - y _ j) \\
    & = c _ {i, j}.
\end{aligned}
$$

それ以外の場合は $\delta \gt 0$ より明らか．

$\blacksquare$

</div>
</details>

$y$ を $y ^ \prime$ で更新し，対応する各種グラフも更新する．
ここで，$G _ {y ^ \prime}$ において同様に $L ^ \prime$ を定める．
更新によって $i \in A \setminus L, j \in B \cap L$ については辺が消滅することがあるが，これは $L$ には影響しない．
また，$\delta$ の定義より $i \in A \cap L, j \in B \setminus L$ において少なくとも 1 辺が新たに加わり，これにより $B \cap L$ の大きさは少なくとも $1$ 増加し，これを高々 $\vert B \vert$ 回繰り返せば必ず増加道が発見できる．

以上より，$\mathrm{O}(n ^ 2)$ 回更新を行うことでアルゴリズムは停止し（増加道に沿ってマッチングを更新した際には $\vert B \vert$ は減少し得ることに注意），各更新では $\delta$ の計算がボトルネックとなって $\mathrm{O}(n ^ 2)$ 時間かかるので，全体として $\mathrm{O}(n ^ 4)$ 時間でアルゴリズムは動作する．
マッチングが更新されるまでの間に各辺は高々 1 回しか通らないのでこれをもとに各種計算を効率化して，左側頂点集合に点を加えていくとして考えることで $\mathrm{O}(n ^ 3)$ 時間を達成する．

## Links
- [Hungarian algorithm - Wikipedia](https://en.wikipedia.org/wiki/Hungarian_algorithm)
- [Lecture notes on bipartite matching](https://math.mit.edu/~goemans/18453S17/matching-notes.pdf)
- [Lecture 8: Assignment Algorithms](https://cyberlab.engr.uconn.edu/wp-content/uploads/sites/2576/2018/09/Lecture_8.pdf)
  - Jonker, Volgenant and Castanon (JVC) algorithm による高速化．