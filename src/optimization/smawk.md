---
title: SMAWK Algotirhm
documentation_of: ./smawk.hpp
---

## 入力

## 出力

## 計算量

## 概要

### 定義

$N \times M$ 行列 $A$ が任意の $i < i ^ \prime$ について $\underset{j}{\operatorname{argmin}}\ A _ {i, j} \leq \underset{j}{\operatorname{argmin}}\ A _ {i ^ \prime, j}$ を満たすとき，$A$ は monotone であるという．

また，$A$ の任意の部分行列が monotone であるとき，$A$ は totally monotone であるという．

#### 補題

$A$ が totally monotone であることは $A$ の任意の $2$ 次正方部分行列が monotone であることと同値である．

<details>
<summary>証明</summary>
<div>

部分行列において行を削除することは totally monotone の条件を緩和するから考えなくて良い．

$\implies$ は明らかであるから $\impliedby$ を示す．
$A$ が totally monotone でない，すなわち $A$ が monotone でない部分行列 $B$ を有するとする．
$B$ の行及び列の添字はもとの行列 $A$ に準拠するとして，$\underset{j}{\operatorname{argmin}}\ B_{i, j} \gt \underset{j}{\operatorname{argmin}}\ B _ {i ^ \prime, j}$ を満たす $i \lt i^\prime$ が存在し，$k = \underset{j}{\operatorname{argmin}}\ B _ {i, j}, k ^ \prime = \underset{j}{\operatorname{argmin}}\ B _ {i ^ \prime, j}$ とする．
ここで，$A$ から行 $i, i ^ \prime$ 及び列 $k, k ^ \prime$ のみを抽出した $2$ 次正方部分行列は monotone ではない．
よって，$A$ の任意の $2$ 次正方部分行列が monotone であるならば $A$ は totally monotone である．

$\blacksquare$

</div>
</details>


### アルゴリズム

SMAWK algorithm は totally monotone な $N \times M$ 行列 $A$ を入力として，各 $i$ について $\underset{j}{\operatorname{argmin}}\ A_{i, j}$ を $\mathrm{O}(N + M)$ 時間で求める．
実装中の関数 `select(i, j, k)` は $j < k$ が保証されているもとで，$A _ {i, j}$ よりも $A _ {i, k}$ が好ましいとされる場合に `true` を，そうでないときは `false` を返す関数である．
以下，$A _ {i, j} = f(i, j)$ と表記する．

#### Step 1. Reduce

$A$ の行最小値を達成する列を高々 $N$ 個に絞る．

具体的には，列候補を格納するスタックを $S$ として以下の処理を $1 \le i \le M$ について行う．
1. $S$ が空でなく，$j$ を $S$ の最上位の要素として，$f(\vert S \vert, j) > f(\vert S \vert, i)$ である間 $j$ を $S$ から取り出す．
2. $\vert S \vert \lt N$ ならば $i$ を $S$ に追加する．

$S$ に $i$ を追加するとき，その時点での $\vert S \vert = k$ として $f(k, j) \le f(k, i)$ が成立しており，先の補題より $r \le k$ なる行 $r$ では列 $i$ は行最小値を達成しないことがわかる（等号の際にはより左のものを小さいとするようにタイブレークを処理することに注意）．
また，後に $i$ が $S$ から取り出される際には比較要素を $i ^ \prime$ として $f(k + 1, i) \gt f(k + 1, i ^ \prime)$ が成立し，再び補題より $r \ge k + 1$ なる行 $r$ では列 $i$ は行最小値を達成しないことがわかるから列 $i$ は全体として行最小値を取ることはない．

以上の操作により列候補を絞った後，$A$ の偶数行目のみを抽出した部分行列 $A ^ \prime$ について再帰的に各行の答えを計算する．

#### Step 2. Interpolate

$A$ の奇数行目の答えはその前後の行の答えの間にあり，それらは既に再帰的に求まっているので，その間を全探索すれば良い．

## Links
- [SMAWK algorithm as an alternative for D&C optimization - Codeforces](https://codeforces.com/blog/entry/110844)
- [Monge の手引書 (tatyam)](https://speakerdeck.com/tatyam_prime/monge-noshou-yin-shu)

## 出題例
- [JAG 3 日目 G]
  - 凸多角形のある 1 点から他の点までの距離は monge で，各端点からの最遠端点が求まる．