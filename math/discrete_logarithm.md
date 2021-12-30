---
title: Discrete Logarithm（離散対数問題）
documentation_of: ./discrete_logarithm.hpp
---

## 概要
離散対数問題を $O(\sqrt{m})$ で解く. 離散対数問題とは正整数 $m$ と $0 \leq x, y < m$ なる整数 $x, y$ が与えられた際に,

$$x^k \equiv y \pmod{m}$$

を満たす最小の非負整数 $k$ を求める問題である. 以下の実装は Baby-step Giant-step のアルゴリズムに基づいている.

### $x$ と $m$ が互いに素の場合
$x$ と $m$ が互いに素かつ $0 \leq x < m$ であるから, $x \cdot \bar{x} \equiv 1 \pmod{m}$ なる整数 $\bar{x} \in [0, m)$ がただ一つ存在する ($(\mathbb{Z}/m\mathbb{Z})^\times$ における $x$ の逆元に対応). これを $x^{-1}$ とする.

また, $n = \lceil \sqrt{m} \rceil$ として, $k = pn + q\ (0 \leq q < n)$ と表すことにすると, $p, q$ は一意に定まり, さらに $a^k \bmod{m}$ の周期性から $p$ としては $0 \leq p < n$ のみ考えれば良い.

以上を踏まえると,

$$\begin{aligned}
    x^k \equiv y \pmod{m}
    &\iff x^{pn + q} \equiv y \pmod{m} \\
    &\iff x^q \equiv y \cdot (x^{-1})^p \pmod{m}
\end{aligned}$$

となる. このとき, 左辺が取り得る値は $0 \leq q < n$ より $O(\sqrt{m})$ 通りに抑えられているので, 右辺を $p$ の昇順に確認していき (こうすることで $k$ の最小性が満たされる) , 両辺が一致するような $p, q$ を求めれば良い. $q$ を小刻みに動かす (Baby-step) 一方で $p$ を $n$ 回分まとめて動かしていき (Giant-step) 探索するというような平方分割に沿ったアルゴリズムであり, 離散対数問題以外にも応用が効くことがある.

### 一般の場合
$x$ と $m$ が互いに素とは限らない場合も工夫すれば互いに素な場合に帰着することができる.

天下りになってしまうが, $g = \gcd(x^d, m)$ として, $x$ と $m/g \in \mathbb{Z}$ が互いに素となるような整数 $d$ を取ることを考える. これは素因数ごとに考えた際に $x$ における指数が 0 もしくは $x^d$ における指数が $m$ における指数以上となればよく ($m/g$ における指数が 0 となる) , $m$ における指数は高々 $\lfloor \log_2 m \rfloor$ であることから $d \geq \log_2 m$ であれば十分であり, 以下でもこの値を取るとする.

このとき, まず $k \in [0, d)$ の範囲に解となりうる $k$ が存在しないか判定する. 存在する場合にはそこでアルゴリズムは停止する. 以下では存在しない場合について考える.

$$x^d \cdot x^k \equiv y \pmod{m}$$

を満たす最小の非負整数 $k$ を求めれば良い. まず, $g \| x^d,\ g \| m$ であるから $g \not\| y$ であれば明らかに解は存在しない. そうでない場合,

$$\tilde{x} = x^d/g,\ \tilde{y} = y/g,\ \tilde{m} = m/g$$

とすると, $x$ と $\tilde{m}$ は互いに素だから$\tilde{x}$ と $\tilde{m}$ も互いに素であり, $\tilde{x} \cdot \bar{\tilde{x}} \equiv 1 \pmod{\tilde{m}}$ を満たす整数 $\bar{\tilde{x}} \in [0, \tilde{m})$ が存在し, これを $\tilde{x}^{-1}$ とする. このとき,

$$\begin{aligned}
    x^d \cdot x^k \equiv y \pmod{m}
    &\iff \exists n \in \mathbb{Z},\ x^d \cdot x^k = y + nm \\
    &\iff \exists n \in \mathbb{Z},\ \tilde{x} \cdot x^k = \tilde{y} + n\tilde{m} \\
    &\iff \tilde{x} \cdot x^k \equiv \tilde{y} \pmod{\tilde{m}} \\
    &\iff x^k \equiv \tilde{y} \cdot \tilde{x}^{-1} \pmod{\tilde{m}}
\end{aligned}$$

となる. 再び$x$ と $\tilde{m}$ は互いに素だから, これで先の場合に帰着されたことになる.

以上が概略で世の実装はこれに従うものが多いが, 実装においては簡潔さのためにもう少々変形している.

まず, $d$ 及び $g = \gcd(x^d, m)$ の取り方は変わらない. この後, $d$ としては $g \| x^d$ でさえあれば良いのでこのような最小の $d$ に取り替えている (このときの $x^d$ を $t$ としている) .

また, $n = \lceil \sqrt{m} \rceil$ として, $k = (p + 1)n - q\ (1 \leq q \leq n)$ として表すことにする. このとき,

$$\begin{aligned}
    \tilde{x} \cdot x^k \equiv \tilde{y} \pmod{\tilde{m}}
    &\iff \tilde{x} \cdot x^{(p + 1)n - q} \equiv \tilde{y} \pmod{\tilde{m}} \\
    &\iff \tilde{x} \cdot x^{(p + 1)n} \equiv \tilde{y} \cdot x^q \pmod{\tilde{m}}
\end{aligned}$$

となり, $\tilde{x}$ の逆元を求める必要がなくなる.

時間計算量は平方分割のパートがボトルネックとなって $O(\sqrt{m})$ となる ( `std::unordered_map` の計算量についてはよくわかっていない) .

### Remark
時間計算量は $O(\sqrt{m})$ だが, $m > 10^9$ の際には内部演算で 64 bit に収まらないケースがあるので `__int128_t` を用いるべきである.
