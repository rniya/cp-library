## 概要
2 次元平面上の一点更新及び長方形領域のクエリに答えるデータ構造. 事前に座標圧縮等を施す必要はないが, 一点更新が適用される点の候補を予め列挙しておく必要がある.

仕組みとしては, 1 次元 Segment Tree の各ノードに対応する区間を再びデータ構造を用いて管理している.

以下に記す時間計算量において, $n$ は一点更新が適用される候補点の数である. 空間計算量は $O(n \log n)$ となる.

| メンバ関数                                  | 効果                                                                                                                                                                                                                 | 時間計算量       |
| ------------------------------------------- | -------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------- | ---------------- |
| `RangeTree(st_new, st_set, st_prod, op, e)` | サイズが与えられた際にデータ構造を構築する関数 `st_new`, 各ノードのデータ構造を更新する関数 `st_set`, 各ノードのデータ構造の区間クエリを取得する関数 `st_prod`, 値を合成する関数 `op` 及び単位元 `e` の情報を与える. | $O(1)$           |
| `add_point(x, y)`                           | 候補点 $(x, y)$ を追加する.                                                                                                                                                                                          | $O(1)$           |
| `build()`                                   | 追加された候補点の情報をもとにデータ構造を構築する.                                                                                                                                                                  | $O(n \log n)$    |
| `set(x, y, val)`                            | 点 $(x, y)$ の値を $val$ をもとに更新する.                                                                                                                                                                           | $O(n(\log n)^2)$ |
| `query(xl, xr, yl, yr)`                     | 長方形領域 $[x_l, x_r) \times [y_l, y_r)$ のクエリに答える.                                                                                                                                                          | $O(n(\log n)^2)$ |

### 使用例
- [Aizu Competitive Programming Camp 2021 Day 2 H - RangeMinimumQuery](https://onlinejudge.u-aizu.ac.jp/services/room.html#ACPC2021Day2/problems/H)

```c++
struct node {
    int min, sum;
    node(int min, int sum) : min(min), sum(sum) {}
};
const node id = node(int(1e9), 0);
auto f = [](node a, node b) { return node(min(a.min, b.min), a.sum + b.sum); };
using SEG = SegmentTree<node, decltype(f)>;
auto st_new = [&](int n) { return new SEG(n, f, id); };
auto st_set = [](SEG& seg, int i, node x) { seg.update(i, x); };
auto st_prod = [](SEG& seg, int l, int r) { return seg.query(l, r); };
RangeTree<SEG, node, int> RT(st_new, st_set, st_prod, f, id);
for (int i = 0; i < M; i++) RT.add_point(X[i], Y[i]);
RT.build();
for (int i = 0; i < M; i++) RT.set(X[i], Y[i], node(A[i], 1));
```

引数の渡し方がかなり複雑なのでテストファイルも併せて参考にするのが良い.
