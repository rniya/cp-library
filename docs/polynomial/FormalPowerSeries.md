## 概要
形式的冪級数(Formal Power Series)に関する諸演算を扱う.
- `operator+`：$P(x)+Q(x)$
- `operator-`：$P(x)-Q(x)$
- `operator*`：$P(x)Q(x)$
- `operator/`：$P(x)/Q(x)$
- `operator%`：$P(x)\%Q(x)$
- `operator<<(deg)`：$P(x)*x^{\deg}$
- `operator>>(deg)`：$P(x)/x^{\deg}$
- `diff()`：$P'(x)$
- `integral()`：$\int P(x)\mathrm{d}{x}$
- `inv()`：$1/P(x)$
- `log()`：$\log(P(x))=\int \frac{P'(x)}{P(x)}\mathrm{d}x$
- `sqrt()`：$\sqrt{P(x)}$
- `exp()`：$\exp(P(x))$
- `pow(k)`：$(P(x))^k$
- `pow_mod(k,mod)`：$(P(x))^k\%Q(x)$
- `linear_mul(a, b)`：$P(x)(ax+b)$
- `linear_div(a, b)`：$P(x)/(ax+b)$
- `sparse_mul(c, d)`：$P(x)(1+cx^d)$
- `sparse_div(c, d)`：$P(x)/(1+cx^d)$
- `operator(x)`：$P(x)$に実際に$x$を代入した際の値を返す.

## 計算量
- $P(x)+Q(x),P(x)-Q(x),P(x)*x^{\deg},P(x)/x^{\deg}$：$O(n)$
- $P(x)Q(x),P(x)/Q(x),P(x)\%Q(x)$：$O(n\log n)$
- $P'(x),\int P(x)\mathrm{d}{x}$：$O(n)$
- $1/P(x)$：$O(n\log n)$
- $\log(P(x))$：$O(n\log n)$
- $\sqrt{P(x)}$：$O(n\log n)$
- $\exp(P(x))$：$O(n\log n)$
- $(P(x))^k$：$O(n\log n)$
- $P(x)(ax+b),P(x)/(ax+b)$：$O(n)$
- $P(x)(1+cx^d),P(x)/(1+cx^d)$：$O(n+d)$

## 問題例
[Codeforces Round #250 (Div. 1) E. The Child and Binary Tree](https://codeforces.com/contest/438/problem/E)

## 参照
[Operations on Formal Power Series - Codeforces](https://codeforces.com/blog/entry/56422)