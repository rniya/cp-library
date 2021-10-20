## 概要
単一始点最短路問題を解くアルゴリズム. 同じく最短路問題を解く Dijkstra 法と比較すると, 計算量が悪化する代わりに Bellman-Ford 法は負辺があっても動作する.

負閉路が存在しない場合, 任意の 2 点間の最短路に含まれる辺の本数は高々 $n - 1$ 本であるから, 全有向辺を見て始点から終点への最短路を更新するという操作を $n - 1$ 回行えば良い. それ以降もなお最短経路が更新される場合は負の有向閉路が存在することになる.

始点と特定の頂点との間に負閉路が存在するかは, 負閉路から終点に到達できるかを見ることで判定が可能であり, このライブラリはその機能も搭載している. また, 全点の最短経路長を 0 で初期化すれば任意の負閉路を検出することも可能である.

| メンバ関数                 | 効果                                                                                              | 時間計算量 |
| -------------------------- | ------------------------------------------------------------------------------------------------- | ---------- |
| `BellmanFord(n)`           | 頂点数 $n$ の有向グラフとして初期化する.                                                          | $O(n)$     |
| `add_edge(from, to, cost)` | $from$ から $to$ へ伸びる重み $cost$ の有向辺を追加する.                                          | $O(1)$     |
| `find_negative_loop()`     | グラフ全体に負閉路が存在するか否かを返す.                                                         | $O(nm)$    |
| `solve(s)`                 | $s$ から各点までの最短経路を返す. $s$ から到達可能な範囲に負閉路が一つでも存在すれば空配列を返す. | $O(nm)$    |
| `shortest_path(s, t)`      | $s$ から $t$ への最短経路を返す. $s - t$ パス上に負閉路が存在すれば空配列を返す.                  | $O(nm)$    |

## 双対問題 (牛ゲー)
グラフ $G(V, E) において, $辺 $e \in E$ の重みを $w_e$ ,  $\delta^+(v) \subseteq E$ を $v$ から出る辺の集合,  $\delta^-(v) \subseteq v$ を $v$ に入る辺の集合とする. 簡単のためにグラフに負閉路が存在しない場合を考えると, 最短路において各辺は高々 1 回しか通らないため, 最短路内に各辺を起用するかどうかを表す変数 $x_e$ を用いて, $s - t$ 最短路問題は以下のような整数計画問題 (IP) に定式化できる.

$$
\begin{alignedat}{5}
    & \mathrm{Minimize}     & \quad & \sum_{e \in E} w_ex_e \\
    & \mathrm{subject\ to}  & \quad & \sum_{e \in \delta^-(v)} x_e - \sum_{e \in \delta^+(v)} x_e = -1  & \quad & v = s \\
    &                       & \quad & \sum_{e \in \delta^-(v)} x_e - \sum_{e \in \delta^+(v)} x_e = 0   & \quad & v \neq s,\ v \neq t \\
    &                       & \quad & \sum_{e \in \delta^-(v)} x_e - \sum_{e \in \delta^+(v)} x_e = 1   & \quad & v = t \\
    &                       & \quad & x_e \in \{0, 1\}                                                  & \quad & \forall e \in E
\end{alignedat}
$$

となる. これと $x_e$ の整数性を緩和した線形計画問題 (LP)

$$
\begin{alignedat}{5}
    & \mathrm{Minimize}     & \quad & \sum_{e \in E} w_ex_e \\
    & \mathrm{subject\ to}  & \quad & \sum_{e \in \delta^-(v)} x_e - \sum_{e \in \delta^+(v)} x_e = -1  & \quad & v = s \\
    &                       & \quad & \sum_{e \in \delta^-(v)} x_e - \sum_{e \in \delta^+(v)} x_e = 0   & \quad & v \neq s,\ v \neq t \\
    &                       & \quad & \sum_{e \in \delta^-(v)} x_e - \sum_{e \in \delta^+(v)} x_e = 1   & \quad & v = t \\
    &                       & \quad & x_e \geq 0                                                        & \quad & \forall e \in E
\end{alignedat}
$$

との関係性について考えたい. まず, (LP) はグラフの接続行列 $H$

$$
H_{ij} = \begin{cases}
    1   & e_j \text{ emanates from } v_i \\
    -1  & e_j \text{ terminates at } v_i \\
    0   & \text{otherwise} \\
\end{cases}
$$

及びベクトル $\boldsymbol{w}, \boldsymbol{a}$

$$
w_i = w_{e_i}
, \quad
a_v = \begin{cases}
    -1  & v = s \\
    1   & v = t \\
    0   & \text{otherwise}
\end{cases}
$$

を用いて

$$
\begin{alignedat}{5}
    & \mathrm{Minimize}     & \quad & \boldsymbol{w}^\top\boldsymbol{x} \\
    & \mathrm{subject\ to}  & \quad & -H\boldsymbol{x} = \boldsymbol{a} \\
    &                       & \quad & \boldsymbol{x} \in \{0, 1\}^n
\end{alignedat}
$$

と表せる. (LP) と (IP) の最適解について, $\text{(LP)} \leq \text{(IP)}$ であることは容易にわかるが, 実は $\text{(LP)} =\text{(IP)}$ が成立する.

### 定義 (完全単模行列 \ totally unimodular matrix)
任意の要素が整数であるような行列を整数行列という. 整数正方行列であって行列式が $+1$ もしくは $-1$ であるような行列を単模行列 (unimodular matrix) という. 任意の正方部分行列 $B$ が $\det B \in \{0, +1, -1\}$ を満たすような行列を完全単模行列 (totally unimodular matrix) という.

### 補題
任意のグラフの接続行列は完全単模である.

#### 証明
正方部分行列 $B$ のサイズに関する帰納法により証明する. 接続行列の成分は $0, +1, -1$ のいずれかであるからサイズが 1 の場合には明らかである. サイズが 2 以上のとき,

1. $B$ が全成分が $0$ であるような列を含むとき
   明らかに $\det B = 0$ である.
2. $B$ が非零成分をただ一つもつような列を含むとき
   その列についての Laplace 展開を考えれば, 帰納法の仮定より従う.
3. $B$ の各列に $+1, -1$ が一つずつ存在するとき
   $B$ の行ベクトルの総和は零ベクトルでありこれらは線形従属であるから, $\det B = 0$ である.

$\blacksquare$

その他にも 2 部グラフの無向接続行列も完全単模行列である.

(LP) を単体法で解く過程について考えると, 単模行列 $H$ の逆行列 $H^{-1}$ が整数行列であることが効いて (LP) が整数最適解 $\boldsymbol{x}^\ast \in \mathbb{Z}^n$ をもつことがわかる (流石に単体法について書いているとキリがないので省略) . グラフに負閉路がない場合は $x_e \in \{0, 1\}$ であり, 以上より, $\text{(LP)} = \text{(IP)}$ が成立する. 以降は (LP) について考えいく.

(LP) の各点での次数制約式に $d_v$ をかけて足し合わせて, $\sum_{e \in E} w_ex_e$ のできるだけ大きい下界を設けることを考える ($x_e$ の係数の総和が $w_e$ 以下でないといけないことに注意)と, 双対問題 (DP) は以下のように表せる.

$$
\begin{alignedat}{5}
    & \mathrm{Maximize}     & \quad & d_t - d_s \\
    & \mathrm{subject\ to}  & \quad & d_v - d_u \leq w_{uv} & \quad & \forall e = (u, v) \in E
\end{alignedat}
$$

これも $\text{(DP)} \leq \text{(LP)}$ だが、線形計画問題においては強双対性が成立して $\text{(DP)} = \text{(LP)}$ となる (証明略、これも単体法について考察する) . また, (DP) は目的・制約関数ともに 2 変数の差で表された単純な形をしている. これが俗に言う牛ゲーであり, $\text{(DP)} = \text{(LP)} = \text{(IP)}$ から, 逆に (IP) の最短路問題として考えることで解くことが可能である. 辺を張る際には各変数の符号の扱いや辺の向きに十分注意する必要がある.

(DP) を解く際に対応する (IP) において負閉路が存在する場合は, その経路に沿った制約式 $d_{v_{i + 1}} - d_{v_{i}} \leq c_i$ で $\sum_{i = 1}^n c_i < 0$ を満たす頂点列 $\{v_i\}_{i = 1}^n$ が存在する. このとき, 両辺の総和を取ると $0 \leq \sum_{i = 1}^n c_i< 0$ となることから明らかに矛盾し, 解は存在しない.

## 問題例
- [AtCoder Beginner Contest 137 E - Coins Respawn](https://atcoder.jp/contests/abc137/tasks/abc137_e)
  - `shortest_path` の verify 問題. なお, これを呼ぶ際には値型は無難に `long long` 等に取るのが良い.

## Links
- [双対性](https://www.slideshare.net/wata_orz/ss-91375739)
- [競プロとLP双対まわりの話で最近知ったこと - とこはるのまとめ](https://tokoharuland.hateblo.jp/entry/2016/12/06/223614)