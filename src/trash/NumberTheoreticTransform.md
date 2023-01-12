## 概要
剰余環$\mathbb{Z}/p\mathbb{Z}$上でFFTを行う. このとき, $p$としてはNTT-friendlyな素数($998244353,1012924417,924844033$など)である必要がある.

## 問題例
[AGC047 C Product Modulo](https://atcoder.jp/contests/agc047/tasks/agc047_c)
一般に素数$P$について, 添字の剰余環$\mathbb{Z}/P\mathbb{Z}$における積での畳み込み, すなわち,
$$c_k=\sum_{i\times j\bmod P=k}a_ib_j$$
が計算できる. 具体的には, $P$の原子根$r$が取れて, $\mathbb{Z}/P\mathbb{Z}$の乗法群と$\mathbb{Z}/(P-1)\mathbb{Z}$が同型であることから, 各添字を$r$を底とした離散対数に変換して, その上でNTTを施した後に解を復元すれば良い. [これ](https://yukicoder.me/problems/no/931)が類題.
[AtCoder Beginner Contest 213 H - Stroll](https://atcoder.jp/contests/abc213/tasks/abc213_h)

## 計算量
$O(n\log n)$