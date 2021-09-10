## 概要
添字XORでの畳み込みを行う. すなわち,
$$c_k=\sum_{i\oplus j=k}a_ib_j$$
を計算する.

列$a,b$に対して離散Hadamard変換を施した後に掛け合わせて, 逆Hadamard変換することで求めたい列$c$が得られる. この際, 列$a,b$の長さは$2$の冪乗である必要がある. また$\mathbb{F}_p$上での逆Hadamard変換では$2$で割る操作がネックになることもあるので, 定数倍改善が必要な場合は適宜$2$の逆元を掛けるように書き換える必要がある.

## 計算量
$|a|=2^n$として, $O(n2^n)$

## 問題例
[Codeforces Round #259 (Div. 1) D. Little Pony and Elements of Harmony](https://codeforces.com/contest/453/problem/D)

## 参照
[色々な畳み込み - kazuma8128’s blog](https://kazuma8128.hatenablog.com/entry/2018/05/31/144519)