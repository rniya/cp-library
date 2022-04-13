---
title: Binary Trie
documentation_of: ./BinaryTrie.hpp
---

## 概要
整数の $2$ 進数表現を利用して Trie 木のように非負整数を管理する `std::multiset` をより汎用的にしたデータ構造．

以下ではこのデータ構造にその時点で格納されている非負整数の集合を $S$ としている．また整数の最大 bit 長を $w$ とする．各クエリにおいて返される整数は $xor\_val$ を適用する前のものであることに注意．

| メンバ関数                | 効果                                                                                                                     | 時間計算量    |
| ------------------------- | ------------------------------------------------------------------------------------------------------------------------ | ------------- |
| `insert(x)`               | $S$ に $x$ を追加する．                                                                                                  | $O(w)$        |
| `erase(x)`                | $S$ から $x$ を $1$ つ削除する．                                                                                         | $O(w)$        |
| `find(x)`                 | $S$ に $x$ が含めれていない場合は $-1$ を，含まれている場合はそれに対応するノード番号（非負）を返す．                    | クエリ $O(w)$ |
| `count(x)`                | $S$ に含まれる $x$ の個数を求める．                                                                                      | $O(w)$        |
| `min_element(xor_val)`    | $\argmin_{x \in S} x \oplus xor\_val$ を求める．                                                                         | $O(w)$        |
| `max_element(xor_val)`    | $\argmax_{x \in S} x \oplus xor\_val$ を求める．                                                                         | $O(w)$        |
| `kth_element(k, xor_val)` | $T = \{s \oplus xor\_val \mid s \in S\}$ として，$T$ の小さい方から $k$ 番目 (0-indexed) の元に対応する $S$ の元を返す． | $O(w)$        |
| `count_less(x, xor_val)`  | $T = \{s \oplus xor\_val \mid s \in S\}$ において $x$ 未満の元の個数を返す．                                             | $O(w)$        |
