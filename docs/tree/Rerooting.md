---
title: Rerooting
documentation_of: //src/tree/Rerooting.hpp
---

## 概要
全方位木 dp を計算する．

使用する際には，以下の関数をもつ構造体 `TreeDP` が必要となる．

- `T e()`: 単位元を返す．
- `T op(const T& l, const T& r)`: 根が virtual な木 $l, r$ の合成を返す．
- `T add_vertex(const T& t, int v)`: 根が virtual な木 $t$ の根に $v$ を代入した木を返す．
- `T add_edge(const T& t, int e)`: 木 $t$ の根に枝 $e$ を接続してできる，根が virtual な木を返す．

```C++
struct TreeDP {
    struct T {};

    T e() {}

    T op(const T& l, const T& r) {}

    T add_vertex(const T& t, int v) {}

    T add_edge(const T& t, int e) {}
};
```

計算量は時間・空間計算量ともに $\mathrm{O}(n)$．

## Links
- [全方位木DP (ReRooting) の抽象化について - メモ帳](https://null-mn.hatenablog.com/entry/2020/04/14/124151)

## 出題例
- [AtCoder Regular Contest 179 D - Portable Gate](https://atcoder.jp/contests/arc179/tasks/arc179_d)