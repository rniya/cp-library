---
title: Static Top Tree
documentation_of: //src/tree/StaticTopTree.hpp
---

## 概要
以下の関数をもつ構造体 `TreeDP` が必要となる．
ここで，`compress(l, r)` においては `l` の方が根寄りの cluster である．
詳細は verify code や問題例での提出を参照．

```C++
struct TreeDP {
    struct Path {};

    struct Point {};

    Path vertex(int v) {}

    Path compress(const Path& l, const Path& r) {}

    Path add_vertex(const Point& p, int v) {}

    Point rake(const Point& l, const Point& r) {}

    Point add_edge(const Path& p) {}
};
```

## 出題例
- [AtCoder Beginner Contest 351 G - Hash on Tree](https://atcoder.jp/contests/abc351/tasks/abc351_g)