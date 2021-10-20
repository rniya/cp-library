## 概要
ベル数$B\left(n,k\right)$は$n$個の区別できる玉を$k$個の区別できない箱に入れる組合せ数, すなわち整数$1$から$n$を$k$個以下のグループに分割する場合の数である. これは, スターリング数$S\left(n,k\right)$をもとに,
$$ \begin{aligned}
    B\left(n,k\right)&=\sum_{j=0}^k S\left(n,k\right)\\
    &=\sum_{j=0}^k \frac{1}{j!} \sum_{i=0}^j \left(-1\right)^{j-i}\binom{j}{i}i^n\\
    &=\sum_{j=0}^k \sum_{i=0}^j \frac{\left(-1\right)^{j-i}}{i!\left(j-i\right)!}i^n\\
    &=\sum_{i=0}^k \sum_{j=i}^k \frac{\left(-1\right)^{j-i}}{i!\left(j-i\right)!}i^n\\
    &=\sum_{i=0}^k \sum_{j=0}^{k-i} \frac{\left(-1\right)^j}{i!j!}i^n\\
    &=\sum_{i=0}^k \frac{i^n}{i!} \sum_{j=0}^{k-1} \frac{\left(-1\right)^j}{j!}
\end{aligned} $$
と計算できる. $\sum_{j=0}^{k-1} \frac{\left(-1\right)^j}{j!}$は累積和のように前計算できる.

## 計算量
$O\left(\min\left(n,k\right)\log{n}\right)$

## 参照
[「写像12相」を総整理！ 〜 数え上げ問題の学びの宝庫 〜 - Qiita](https://qiita.com/drken/items/f2ea4b58b0d21621bd51)