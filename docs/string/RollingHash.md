## 概要
$\bmod 2^{61}-1$で基数は$\left[2,2^{61}-1\right)$の乱数によるRolling Hash.

[Codeforces Round #542 [Alex Lopashev Thanks-Round] (Div. 1) C. Morse Code](https://codeforces.com/contest/1129/problem/C) $\bmod$の値が小さいとかなりの確率で衝突し, hash値を2つもとうとするとTLEにハマるので, このRolling Hashが有効.

## 計算量

## 参照
[安全で爆速なRollingHashの話](https://qiita.com/keymoon/items/11fac5627672a6d6a9f6)