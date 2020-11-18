## 概要
$\bmod 2^{61}-1$で基数は$\left[2,2^{61}-1\right)$の乱数によるRolling Hash.

[Codeforces Round #542 [Alex Lopashev Thanks-Round] (Div. 1) C. Morse Code](https://codeforces.com/contest/1129/problem/C) $\bmod$の値が小さいとかなりの確率で衝突し, hash値を2つもとうとするとTLEにハマるので, このRolling Hashが有効.

- `generate_base()`：基数を生成する. 2つ以上の文字列に対しては同じ基数を用いねばならないので注意.
- `query(l,r)`：$[l,r)$のhash値を返す.
- `lcp(a,b)`：$a$文字目を$b$文字目を始点としたLongest Common Prefixの長さを返す.
- `get(t)`：文字列$t$のhash値を返す.

## 計算量
- `generate_base()`：$O(1)$
- `query(l,r)`：$O(1)$
- `lcp(a,b)`；$O(\log n)$
- `get(t)`：$O(|t|)$

## 参照
[安全で爆速なRollingHashの話](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)