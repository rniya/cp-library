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
  bundledCode: "#line 1 \"src/graph/hungarian.hpp\"\n#include <cassert>\n#include\
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
  code: "#include <cassert>\n#include <limits>\n#include <utility>\n#include <vector>\n\
    \ntemplate <class Cost> std::pair<Cost, std::vector<int>> hungarian(const std::vector<std::vector<Cost>>&\
    \ a) {\n    const Cost inf = std::numeric_limits<Cost>::max();\n    int n = a.size(),\
    \ m = a[0].size();\n    assert(n <= m);\n    std::vector<int> P(m + 1, -1);\n\
    \    std::vector<Cost> yl(n, 0), yr(m + 1, 0);\n    for (int i = 0; i < n; i++)\
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
  dependsOn: []
  isVerificationFile: false
  path: src/graph/hungarian.hpp
  requiredBy: []
  timestamp: '2023-09-11 22:32:46+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/assignment.test.cpp
documentation_of: src/graph/hungarian.hpp
layout: document
title: "Hungarian\uFF08\u5272\u5F53\u554F\u984C\uFF0C\u4E8C\u90E8\u30B0\u30E9\u30D5\
  \u306E\u6700\u5C0F\u91CD\u307F\u5B8C\u5168\u30DE\u30C3\u30C1\u30F3\u30B0\uFF09"
---

## 概要
割当問題を $\mathrm{O}(n m \min(n, m))$ 時間で解くアルゴリズム．

割当問題は左側頂点集合 $A$ 及び右側頂点集合 $B$ からなる二部グラフの最小重み完全マッチングを求める問題と等価である．

まず，簡単のために $|A| = |B|$ の場合について考えると，辺 $(i, j)\ (i \in A,\ j \in B)$ の重みを $c_{i, j}$ として，

$$
\begin{alignedat}{5}
    & \mathrm{Minimize}     & \quad & \sum_{i, j} c_{i, j} x_{i, j} \\
    & \mathrm{subject\ to}  & \quad & \sum_j x_{i, j} = 1 & \quad & (\forall i \in A) \\
    &                       & \quad & \sum_i x_{i, j} = 1 & \quad & (\forall j \in B) \\
    &                       & \quad & x_{i, j} \in \{0, 1\}
\end{alignedat}
$$

と定式化することができ，これを (IP) とする．
制約 $x_{i, j} \in \{0, 1\}$ を $x_{i, j} \geq 0$ に緩和した問題 (LP) の双対問題 (DLP) は，

$$
\begin{alignedat}{5}
    & \mathrm{Maximize}     & \quad & \sum_i y_i + \sum_j y_j \\
    & \mathrm{subject\ to}  & \quad & y_i + y_j \leq c_{i, j} & \quad & (\forall (i, j) \in A \times B)
\end{alignedat}
$$

と表せる．
これは任意の $i \in A,\ j \in B$ について $y_i + y_j \leq c_{i, j}$ を満たすようなノードポテンシャル $y \colon (A \cup B) \to \R$ を各頂点がもつと解釈することができる．
完全マッチングの重みがポテンシャルの総和 $\sum_{v \in A \cup B} y_v$ 以上であることはマッチングが全ての頂点をカバーすることから明らかである ($\mathrm{(IP)} \geq \mathrm{(DLP)}$)．
また，これらの値が等しいようなマッチング及びポテンシャルがあるとき，そのマッチングが任意のマッチングの中で最小の重みをもつこともわかる．
Hungarian 法とはこれらの値が等しくなるようなマッチング及びポテンシャルを同時に構成する主双対アルゴリズムである．

## アルゴリズムの詳細
補助二部グラフ $G_y = (A, B, E_y)$ を $E_y = \{(i, j) \mid y_i + y_j = c_{i, j}\}$ として構成する．
マッチング $M$ を空集合で，ポテンシャル $y$ を $y_i = 0\ (\forall i \in A),\ y_j =  \min_i c_{i, j}\ (j \in B)$  で初期化する．
この $y$ が (DLP) の実行可能解であることは明らかである．
これを順次更新し，その過程で $M$ が $G$ の完全マッチングとなれば，$M$ 及び $y$ が所望のものである．
そうでないとき，以下のようにして $M$ 及び $y$ を更新する．

$G_y$ の辺集合 $E_y$ を，最大マッチング $M$ に属するならば $B$ から $A$ に，そうでなければ $A$ から $B$ に向き付けた有向二部グラフを $\vec{G}_y$ とする．
マッチングの端点集合を $\partial M$，$A^\ast = A \setminus \partial M,\ B^\ast = B \setminus \partial M$，$\vec{G}_y$ 上で $A^\ast$ から到達可能な頂点集合を $L$ とする．
$L$ は BFS で $\mathrm{O}(n + m)$ 時間で計算可能である．
$L \cap B^\ast \neq \emptyset$ のとき，グラフには増加道が存在するからこれに従ってマッチング $M$ を更新する．
そうでないとき，$M$ は $G_y$ の最大マッチングであり，ポテンシャル $y$ を更新することを考えたい．
ここで，$G_y$ 上で $A \cap L$ と $B \setminus L$ の間には辺は存在しない．

<details>
<summary>証明</summary>
<div>

$e = (u, v) \in E_y\ (u \in A \cap L,\ v \in B \setminus L)$ が存在するとする．
$e \in M$ のとき，$u \in L$ かつ $u \notin A^\ast$ より $v \in L$ が成立する必要があるが，これは $v \notin L$ に矛盾する．
$e \in E_y \setminus M$ とすると，$u \in L$ より $L$ の定義から $v \in L$ で同様に矛盾が導ける．

$\blacksquare$

</div>
</details>

すなわち，任意の $i \in A \cap L,\ j \in B \setminus L$ について $y_i + y_j < c_{i, j}$ が成立する．
このとき，
$$
\delta \coloneqq \min_{i \in A \cap L,\ j \in B \setminus L} (c_{i, j} - y_i - y_j)
$$
とすると，$\delta > 0$ であり，これをもとにポテンシャル $y^\prime$ を次のように得る：

$$
y^\prime_i = \begin{cases}
    y_i             & (i \in A \setminus L) \\
    y_i + \delta    & (i \in A \cap L)
\end{cases}, \quad
y^\prime_j = \begin{cases}
    y_j             & (j \in B \setminus L) \\
    y_j - \delta    & (j \in B \cap L)
\end{cases}
$$

この $y^\prime$ も (DLP) の実行可能解である．


<details>
<summary>証明</summary>
<div>

$i \in A \cap L$ かつ $j \in B \setminus L$ のとき，

$$
\begin{aligned}
    y^\prime_i + y^\prime_j
    & = y_i + y_j + \delta \\
    & = y_i + y_j + \min_{i \in A \cap L,\ j \in B \setminus L} (c_{i, j} - y_i - y_j) \\
    & \leq y_i + y_j + (c_{i, j} - y_i - y_j) \\
    & = c_{i, j}.
\end{aligned}
$$

それ以外の場合は $\delta > 0$ より明らか．

$\blacksquare$

</div>
</details>

$y$ を $y^\prime$ で更新し，対応する各種グラフも更新する．
ここで，$G_{y^\prime}$ において同様に $L^\prime$ を定める．
更新によって $i \in A \setminus L,\ j \in B \cap L$ については辺が消滅することがあるが，これは $L$ には影響しない．
また，$\delta$ の定義より $i \in A \cap L,\ j \in B \setminus L$ において少なくとも 1 辺が新たに加わり，これにより $B \cap L$ の大きさは少なくとも $1$ 増加し，これを高々 $|B|$ 回繰り返せば必ず増加道が発見できる．

以上より，$\mathrm{O}(n^2)$ 回更新を行うことでアルゴリズムは停止し（増加道に沿ってマッチングを更新した際には $|B|$ は減少し得ることに注意），各更新では $\delta$ の計算がボトルネックとなって $\mathrm{O}(n^2)$ 時間かかるので，全体として $\mathrm{O}(n^4)$ 時間でアルゴリズムは動作する．
マッチングが更新されるまでの間に各辺は高々 1 回しか通らないのでこれをもとに各種計算を効率化して，左側頂点集合に点を加えていくとして考えることで $\mathrm{O}(n^3)$ 時間を達成する．

## Links
- [Hungarian algorithm - Wikipedia](https://en.wikipedia.org/wiki/Hungarian_algorithm)
- [Lecture notes on bipartite matching](https://math.mit.edu/~goemans/18453S17/matching-notes.pdf)
- [Lecture 8: Assignment Algorithms](https://cyberlab.engr.uconn.edu/wp-content/uploads/sites/2576/2018/09/Lecture_8.pdf)
  - Jonker, Volgenant and Castanon (JVC) algorithm による高速化