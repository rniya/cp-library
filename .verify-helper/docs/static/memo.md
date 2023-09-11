- [Burnside の補題 / Polya の定理](#burnside-の補題--polya-の定理)
    - [問題例](#問題例)
- [Lagrange の反転公式](#lagrange-の反転公式)
    - [問題例](#問題例-1)
- [凸包](#凸包)
    - [問題例](#問題例-2)
- [$C\_3, C\_4, K\_4$ counting in undirected graph](#c_3-c_4-k_4-counting-in-undirected-graph)
    - [問題例](#問題例-3)
- [ゲーム](#ゲーム)
    - [問題例](#問題例-4)
- [操作における不変量](#操作における不変量)
- [部分和問題](#部分和問題)
- [その他](#その他)
- [反省](#反省)
- [実装](#実装)


## Burnside の補題 / Polya の定理
$n$ 個の要素の組 $(x_1, \dots, x_n)$ からなる有限集合を $X$，その置換の集合を $G$ とする．
$G$ の置換で一致するものを同一視した際の $X$ の相異なる要素の個数は
$$
\frac{1}{|G|} \sum_{g \in G} |\{x \in X \mid gx = x\}|
$$
に等しい．
#### 問題例
- [AtCoder Beginner Contest 198 F - Cube](https://atcoder.jp/contests/abc198/tasks/abc198_f)
- [AtCoder Beginner Contest 284 Ex - Count Unlabeled Graphs](https://atcoder.jp/contests/abc284/tasks/abc284_h)

## Lagrange の反転公式
形式的冪級数 $F(x), G(x)$ は逆関数の関係にあるとする（すなわち $F(G(x)) = G(F(x)) = x$ が成り立つ）．
$[x^0]F(x) = [x^0]G(x) = 0$ かつ $[x^1]F(x) \neq 0,\ [x^1]G(x) \neq 0$ が成り立つとき，
$$
[x^n]G(x) = \frac{1}{n} [x^{n - 1}] \left(\frac{x}{F(x)}\right)^n.
$$

#### 問題例
- [AtCoder Beginner Contest 222 H - Beautiful Binary Tree](https://atcoder.jp/contests/abc222/tasks/abc222_h)
- [Educational Codeforces Round 142 (Rated for Div. 2) F2. Graph Coloring (hard version)](https://codeforces.com/contest/1792/problem/F2)
  - [参考](https://codeforces.com/blog/entry/111835?#comment-996577)

## 凸包
#### 問題例
- [The 1st Universal Cup. Stage 2: Hong Kong D. Shortest Path Query](https://qoj.ac/contest/1099/problem/5458?v=1)
  - 各頂点の状態としては凸包の頂点のみが重要となるが，$n \times n$ の格子点を頂点にもつ凸包の頂点数は $O(n^{2 / 3})$ で抑えられる（[参照](https://not522.hatenablog.com/entry/2016/09/24/154939)）．
- [The 1st Universal Cup. Stage 3: Poland B. Big Picture](https://qoj.ac/contest/1099/problem/5456?v=1)
  - 利益を考えると最終的な開店の仕方は凸包に一致する．

## $C_3, C_4, K_4$ counting in undirected graph
頂点数 $n$，辺数 $m$ のグラフの各種部分グラフを列挙及び数え上げる．
頂点を次数の昇順に並べ，各辺を右方向に向きづけることにする．
このとき，各頂点の出次数は $\sqrt{2 m}$ で抑えられ，各種列挙が効率的に行える．

#### 問題例
- [The 1st Universal Cup. Stage 13: Iberia K. 4](https://qoj.ac/problem/6354)
  - [ecnerwala のコメント](https://codeforces.com/blog/entry/97762?#comment-866645)

## ゲーム
#### 問題例
- [CodeTON Round 2 (Div. 1 + Div. 2, Rated, Prizes!) F. Colouring Game](https://codeforces.com/contest/1704/problem/F)
  - 周期 34 の Grundy 数．
- [yukicoder No.2285 Make A Unit Square](https://yukicoder.me/problems/no/2285)
  - 同上．
- [The 1st Universal Cup. Stage 8: Slovenia B. Combination Locks](https://qoj.ac/contest/1070/problem/5250?v=1)
  - [参考](https://37zigen.com/game-on-graph/)．まだ upsolve していない．
- [2023牛客暑期多校训练营2 F - Link with Chess Game](https://ac.nowcoder.com/acm/contest/57356/F)

## 操作における不変量
- [The 1st Universal Cup. Stage 14: Ranoa C. LaLa and Lamp](https://qoj.ac/contest/1214/problem/6376)
- [Hokkaido University Competitive Programming Camp 2023 Day 1 D: Beam Beam Beam](https://onlinejudge.u-aizu.ac.jp/beta/room.html#HUPC2023Day1/problems/D)
  - グリッド上の各マス目に数字が書かれていて，各行および各列に値を一律に加算する操作を行えるとき，数字を全て $0$ にすることができる必要十分条件は任意の連続する $2$ 行及び列からなる $2 \times 2$ 部分行列の行列式が $0$ であることである．[参考](https://potato167.hatenablog.com/entry/2023/05/05/012415)．

## 部分和問題
- [Codeforces Round 890 (Div. 2) supported by Constructor Institute E2. PermuTree (hard version)](https://codeforces.com/contest/1856/problem/E2)
  - 総和 $n$ の部分和問題は $\mathrm{O}\left(\frac{n \sqrt{n}}{w}\right)$ で解ける（[参考](https://twitter.com/noshi91/status/1404719619097567236?s=20)）．
    - 同じ重みのアイテムが $3$ つ存在する場合は $2$ つをまとめてもよく，この操作により各重みのアイテムは高々 $2$ 個で重みの種類数は $\mathrm{O}(\sqrt{n})$ で抑えられるからアイテムの個数も $\mathrm{O}(\sqrt{n})$ 個である．
  - 動的 bitset は template 引数を利用して書ける．


## その他
- [The 1st Universal Cup. Stage 16: Gomel H. Classical Maximization Problem](https://qoj.ac/contest/1223/problem/6414?v=1)
  - 端点を共有する辺同士のマッチングは dfs 木を取ってボトムアップに構築可能．また，連結成分内の辺の本数が偶数ならば必ず完全マッチングが存在する．

## 反省
- 木上の任意のパスを扱う際には重心分解による分割統治が有効であるのと同様に，数列上の任意の区間を扱う際にも分割統治が有効
  - [AtCoder Regular Contest 158 E - All Pair Shortest Paths](https://atcoder.jp/contests/arc158/tasks/arc158_e)
- 回数制限のない構築等では最小単位の扱いやすい操作を扱う操作を合成することを考える
  - [AtCoder Regular Contest 159 C - Permutation Addition](https://atcoder.jp/contests/arc159/tasks/arc159_c)
- 任意の順列をソートできる $\iff$ 任意の 01 列をソートできる
  - [AtCoder Regular Contest 160 F - Count Sorted Arrays](https://atcoder.jp/contests/arc160/tasks/arc160_f)
- 区間に対して操作した後，宝箱 $i$ が開いているならば報酬 $A_i$ を受け取ることができる→元から $A_i$ 所持しているとして $A_i$ 支払うことで宝箱 $i$ を開けることができるとして，宝箱を全て開ける問題に言い換える
  - [yukicoder No.2321 Continuous Flip](https://yukicoder.me/problems/no/2321)
  - [第四回 アルゴリズム実技検定 過去問 O - 宝箱](https://atcoder.jp/contests/past202010-open/tasks/past202010_o)
- 構築でジャッジができたら乱択を疑う
  - [AtCoder Regular Contest 161 E - Not Dyed by Majority (Cubic Graph)](https://atcoder.jp/contests/arc161/tasks/arc161_e)
- 自明な上界/下界から最適解の性質が得られることがある
  - [Codeforces Round 875 (Div. 1) D. Mex Tree](https://codeforces.com/contest/1830/problem/D)
  - [AtCoder Regular Contest 063 F - すぬけ君の塗り絵 2](https://atcoder.jp/contests/arc063/tasks/arc063_d)
- ゲームで 2 次元での勝敗を表すグリッドからエスパー
  - [AtCoder Regular Contest 163 E - Chmin XOR Game](https://atcoder.jp/contests/arc163/tasks/arc163_e)
- 2 値 dp の値の連続性に注目
  - [Codeforces Round 887 (Div. 1) D. Miriany and Matchstick](https://codeforces.com/contest/1852/problem/D)
- 区間長の 2 乗時間かかる dp を更新しながら区間 dp を行える．
  - [COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred) J. Jackets and Packets](https://codeforces.com/contest/1866/problem/J)
- top 2 の値は乱択でグループ分けしてそれらが別グループに入れば良い．
  - [COMPFEST 15 - Preliminary Online Mirror (Unrated, ICPC Rules, Teams Preferred) K. Keen Tree Calculation](https://codeforces.com/contest/1866/problem/K)
  - もしくは，2 番目の最大値は CHT の凸包の与えられた $x$ が属する直線の左右に隣接する直線の $x$ における値及び凸包の制作過程で棄却された直線群の最大値（再び凸方を構成する）から得られる．

## 実装
- $n$ 頂点の完全二分木の左部分木の頂点数は以下で求まる．
```c++
int k = std::__lg(n + 1);
long long l = ((1LL << (k - 1)) - 1) + std::min(1LL << (k - 1), n - (1LL << k) + 1);
```
