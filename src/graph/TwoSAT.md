---
title: 2-SAT
documentation_of: ./TwoSAT.hpp
---

## 概要
$(a \vee b \vee \cdots) \wedge (c \vee d \vee \cdots) \wedge \cdots$ のような形をした論理式，すなわち $x_{i,j}$ をリテラルとして $\bigwedge_i \bigvee_j x_{i,j}$ のように表される論理式を CNF 形式（乗法標準形，連言標準形とも）という．
内側の各 $\bigvee_j x_{i,j}$ をクロージャ (clause) という．

論理式が与えられた際に，各リテラルに適切に真偽値を割り振ることで全体の真偽値を真にできるかを判定する問題を充足可能性問題 (SAT) という．
特に，論理式を CNF 形式で表現した際に各クロージャ内のリテラルの数が高々 2 つであるような論理式に対する充足可能性問題を 2-SAT と呼ぶ．
SAT は一般には NP 完全だが，2-SAT については多項式時間で解くことが可能であり，全体を真にすることが可能であれば実際にそのようなリテラルの真偽値の割当を構成するアルゴリズムである．

各クロージャは $(a \vee b) \iff (\neg a \Rightarrow b \vee \neg b \Rightarrow a)$ と換言でき，論理式全体は $(a \Rightarrow b)$ という形の論理式が $\wedge$ で繋がれた形となる．
ここで，$n$ 個のリテラル $x_i$ が存在する際に，$\Rightarrow$ に対応した有向辺を取り $x_i，\neg x_i$ に対応する頂点をそれぞれ用意した $2 n$ 頂点の有向グラフを考える．
もし $x_i$ と $\neg x_i$ が同じ強連結成分にあるようなリテラル $x_i$ が存在するならば，$x \Rightarrow \neg x \wedge \neg x \Rightarrow x$ となり明らかに矛盾し論理式全体を真にすることは不可能である．
逆にそのようなリテラルが存在しない場合には $x_i$ を含む強連結成分のトポロジカル順序が $\neg x_i$ を含む強連結成分のトポロジカル順序よりも後ろであるかを $x_i$ の真偽値とすれば論理式全体を充足させることが可能である．
以上よりグラフを強連結成分分解することでリテラルの数を $n$，クロージャの数を $m$ として $O(n + m)$ で解くことができる．

| メンバ関数               | 効果                                                               | 時間計算量 |
| ------------------------ | ------------------------------------------------------------------ | ---------- |
| `TwoSAT(n)`              | リテラル数 $n$ として初期化する．                                  | $O(n)$     |
| `add_clause(i，f，j，g)` | $(x_i = f) \vee (x_j = g)$ のようなクロージャを足す．              | $O(1)$     |
| `add_if(i，f，j，g)`     | $(x_i = f) \Rightarrow (x_j = g)$ のようなクロージャを足す．       | $O(1)$     |
| `set_true(i)`            | $x_i$ を真とする．                                                 | $O(1)$     |
| `set_false(i)`           | $x_i$ を偽とする．すなわち，$\neg x_i$ を真とする．                | $O(1)$     |
| `at_most_one(v)`         | $v$ 内の $L$ 個のリテラルのうち高々 1 つが真とする（問題例参照）． | $O(L)$     |
| `satisfiable()`          | 充足可能かどうか判定する．                                         | $O(n + m)$ |
| `answer()`               | 充足可能として全体の真偽値を真にする各リテラルの真偽値を返す．     | $O(1)$     |

### 構成方法の正当性の証明
## 問題例
- [AtCoder Beginner Contest 210 F - Coprime Solitaire](https://atcoder.jp/contests/abc210/tasks/abc210_f)
  - `at_most_one(v)` の使用例．各カードについて表にある数は $A_i$ もしくは $B_i$ で，各素数についてそれを素因数に含むような数は高々 1 つしか表にない．
  すると $x_1，x_2，\cdots，x_n$ のうち高々 1 つが真であるというような論理式が複数ある論理式を考えることになる．
  これはリテラルの累積 OR を考えることで $O(n)$ 個の 2 変数のクロージャで言い換えることができる．
  $$ y_i = \begin{cases}
    x_i                     & (i = 1) \\
    y_{i - 1} \vee x_i      & (i > 1)
  \end{cases} $$
  をイメージして新たに $n$ 個のリテラル $y_i$ を考えると，$x_i$ のうち真であるリテラルが高々 1 つ $\iff$ $(x_i \Rightarrow y_i) \wedge (y_{i - 1} \Rightarrow y_i) \wedge (x_i \Rightarrow \neg y_{i - 1}) \wedge (y_{i - 1} \Rightarrow \neg x_i)$ と換言できる．

- [CodeChef March Cook-Off 2022 - Oh I Dont Care](https://www.codechef.com/COOK139A/problems/OH1DCARE)

- [JOI 2020/2021 二次予選 過去問 E - スパイ 2 (Spy 2)](https://atcoder.jp/contests/joi2021yo2/tasks/joi2021_yo2_e)
  - A がスパイでないときは A の証言の内容は気にしなくてもよく，A がスパイの場合は B はスパイでないかもしくは C はスパイである．
  よって各人はスパイであるか否かを真偽値とするリテラルを考えると各クロージャは $(\neg a \vee \neg b \vee c)$ のようになる．
  このように各クロージャ内の否定されているリテラルの数が高々 1 つであるような論理式の充足可能性問題を Horn-SAT といい，これも次のようにして 2-SAT 同様に多項式時間で解くことができる．
  真のリテラルを確定させていくことを考える．
  このとき，各クロージャの否定は $(a \wedge b \wedge \neg c)$ だから $(a \wedge b) \Rightarrow c$ であり，次々に確定させていくことが可能である．
  もう確定させることが可能なリテラルが存在しなくなったならば残りのリテラルは全て偽としまっても問題ない（これで矛盾するのはクロージャの末尾のリテラルに偽が割り当てられて他のリテラルが全て真のときだが，これは他のリテラルが全て真で確定した際に真を割り当てられなければならないので起こり得ない）．
  よって，リテラルに真を割り当てていき，そのリテラルが存在する各クロージャについて新たに真で確定するリテラルがないかチェックしていけばよい．
  適切に実装すればリテラル数とクロージャ内のリテラル数の合計に対して線形時間で解くことができる．

- [AtCoder Beginner Contest 277 Ex - Constrained Sums](https://atcoder.jp/contests/abc277/tasks/abc277_h)

- [AtCoder Regular Contest 069 F - Flags](https://atcoder.jp/contests/arc069/tasks/arc069_d)