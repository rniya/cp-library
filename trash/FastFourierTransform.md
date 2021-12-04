## 概要
2つの数列$a,b$の畳み込み, すなわち,
$$c_k=\sum_{i=0}^k a_ib_{k-i}$$
を計算する. バタフライ演算を利用した非再帰のものを実装している. 誤差に注意が必要だが, NTTよりもこちらの方が速いので, TLが厳しい場合であればこちらを使う方が無難.
## 計算量
$O(n\log n)$

## 問題例
[Codeforces Round #296 (Div. 1) D. Fuzzy Search](https://codeforces.com/contest/528/problem/D)
2つの文字列$S,T$について, 特に特定の1種類の文字に着目して2つの文字列をbit列に変換すると, それらを畳み込むことで一致しているかどうかを判定することができる.

## 参照
- [高速フーリエ変換](https://www.slideshare.net/chokudai/fft-49066791)
- [高速フーリエ変換 (FFT) - ゆるふわブログ](http://ysmr-ry.hatenablog.com/entry/2017/11/09/102008)
- [競プロのための高速フーリエ変換](https://www.creativ.xyz/fast-fourier-transform/)
- [Cooley-Tukeyのアルゴリズム - Mister雑記](https://misteer.hatenablog.com/entry/cooley-tukey)