## 概要
基本的な数学関数の集合.

| 関数                          | 効果                                                                                                                   | 時間計算量           |
| ----------------------------- | ---------------------------------------------------------------------------------------------------------------------- | -------------------- |
| `divisor(n)`                  | $n$ の約数を列挙する.                                                                                                  | $O(\sqrt{n})$        |
| `prime_factor(n)`             | $n$ の素因数を列挙する.                                                                                                | $O(\sqrt{n})$        |
| `osa_k(n)`                    | $n$ 以下の各数 $i$ について, その最小素因数を記録した配列を返す.                                                       | $O(n \log \log n)$   |
| `prime_factor(min_factor, n)` | `osa_k` で構築された最小素因数の配列 `min_factor` をもとに $n$ の素因数を列挙する.                                     | $O(\log n)$          |
| `modpow(x, n, mod)`           | $x^n \pmod{mod}$ を計算する.                                                                                           | $O(\log n)$          |
| `extgcd(a, b, x, y)`          | $x, y$ を参照渡しすることで $ax + by = d$ を満たす $x, y$ に変更し, $a$ と $b$ の最大公約数 $d$ を返す.                | $O(\log \max(a,b))$  |
| `inv_mod(a, mod)`             | $\mathbb{Z}/mod\mathbb{Z}$ における $a$ の逆元を返す. $a$ と $mod$ が互いに素でなく逆元が存在しない場合は `-1` を返す. | $O(\log mod)$        |
| `euler_phi(n)`                | Euler's totient function $\varphi(n)$ を返す. こで, $\varphi(n)$ は $n$ 以下の $n$ と互いに素な自然数の個数である.     | $O(\sqrt{n})$        |
| `euler_phi_table(n)`          | $n$ 以下の各数 $i$ について, $\varphi(i)$ を記録した配列を返す.                                                        | $O(n \log \log n)$   |
| `order(x, m)`                 | $x^i \equiv 1 \pmod{m}$ を満たす最小の正整数 $i$ を返す. 存在しない場合は `-1` を返す.                                 | $O(\sqrt{m}\log{m})$ |
