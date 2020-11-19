## 概要
経路圧縮せずにマージテクにより集合を管理する過程を保持することでrollbackを可能にしたUnionFind.
- `root(x)`：$x$の集合の根を返す.
- `merge(x,y)`：$x$と$y$の属する集合をマージする.
- `undo()`：直前のマージを巻き戻す.
- `snapshot()`：それまでのマージ過程を保存する.
- `rollback()`：直前に`snapshot()`された時間まで状態をrollbackする.
- `same(x,y)`：現時点で$x$と$y$が同じ集合にいるかどうか判定する.
- `size(x)`：$x$の属する集合の大きさを返す.

## 計算量
クエリあたり$O(\log n)$

## 参照
[Mo's algorithm とその上位互換の話 - あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2016/07/01/000000)