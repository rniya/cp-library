---
title: Run Enumerate
documentation_of: ./run_enumerate.hpp
---

## 概要
文字列 $S$ 中の run を列挙する．
run とは文字列中の部分文字列の繰り返しであって長さが極大で周期が最小のものを指し，本アルゴリズムでは以下の条件を満たす $(t, l, r)$ を列挙する．
- $S$ の $l$ 文字目から $r - 1$ 文字目の最小周期は $t$ であり，$r - l \geq 2 t$ を満たす．
- 上の条件を満たすもののうち，$l, r$ は極大である．つまり $(t, l - 1, r), (t, l, r + 1)$ は上の条件を満たさない


計算量は $|S| = n$ として $O(n \log n)$．
また，アルゴリズムの存在からこのような $(t, l, r)$ の個数は $O(n \log n)$ 個であることがわかるが，実際は $O(n)$ で列挙するアルゴリズムも存在し，個数はさらに $O(n)$ で抑えることが可能である．

## Links
- [Runの列挙 (Main-Lorentz algorithm) - 迷いませんか？](https://pazzle1230.hatenablog.com/entry/2019/11/27/234632)

## 問題例
- [DMOPC '22 Contest 3 P6 - Compressibility](https://dmoj.ca/problem/dmopc22c3p6)