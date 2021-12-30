---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/point_add_rectangle_sum.test.cpp
    title: test/yosupo/point_add_rectangle_sum.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"datastructure/RangeTree.hpp\"\n#include <algorithm>\n#include\
    \ <cassert>\n#include <functional>\n#include <vector>\n\ntemplate <typename structure_t,\
    \ typename value_t, typename coordinate_t> struct RangeTree {\nprivate:\n    using\
    \ structure_new = std::function<structure_t*(int)>;\n    using structure_set =\
    \ std::function<void(structure_t&, int, value_t)>;\n    using structure_prod =\
    \ std::function<value_t(structure_t&, int, int)>;\n    using value_merge = std::function<value_t(value_t,\
    \ value_t)>;\n    using Pt = std::pair<coordinate_t, coordinate_t>;\n\npublic:\n\
    \    RangeTree(const structure_new& st_new,\n              const structure_set&\
    \ st_set,\n              const structure_prod& st_prod,\n              const value_merge&\
    \ op,\n              const value_t& e)\n        : st_new(st_new), st_set(st_set),\
    \ st_prod(st_prod), op(op), e(e) {}\n\n    void add_point(coordinate_t x, coordinate_t\
    \ y) { points.emplace_back(x, y); }\n\n    void build() {\n        std::sort(points.begin(),\
    \ points.end());\n        points.erase(std::unique(points.begin(), points.end()),\
    \ points.end());\n        n = points.size();\n        yxs.resize(n << 1);\n  \
    \      segs.resize(n << 1, nullptr);\n        for (int i = 0; i < n; i++) yxs[n\
    \ + i] = {{points[i].second, points[i].first}};\n        for (int i = n - 1; i\
    \ >= 0; i--) {\n            auto& lch = yxs[i << 1 | 0];\n            auto& rch\
    \ = yxs[i << 1 | 1];\n            std::merge(lch.begin(), lch.end(), rch.begin(),\
    \ rch.end(), std::back_inserter(yxs[i]));\n            yxs[i].erase(std::unique(yxs[i].begin(),\
    \ yxs[i].end()), yxs[i].end());\n        }\n        for (int i = 0; i < (n <<\
    \ 1); i++) segs[i] = st_new(yxs[i].size());\n    }\n\n    void set(coordinate_t\
    \ x, coordinate_t y, value_t val) {\n        int i = std::distance(points.begin(),\
    \ std::lower_bound(points.begin(), points.end(), std::make_pair(x, y)));\n   \
    \     assert(i < n && points[i] == std::make_pair(x, y));\n        for (i += n;\
    \ i; i >>= 1) st_set(*segs[i], zip(i, x, y), val);\n    }\n\n    value_t prod(coordinate_t\
    \ xl, coordinate_t xr, coordinate_t yl, coordinate_t yr) {\n        assert(xl\
    \ <= xr && yl <= yr);\n        value_t L = e, R = e;\n        int l = zip(xl),\
    \ r = zip(xr);\n        for (l += n, r += n; l < r; l >>= 1, r >>= 1) {\n    \
    \        if (l & 1) L = op(L, st_prod(*segs[l], zip(l, yl), zip(l, yr))), l++;\n\
    \            if (r & 1) --r, R = op(st_prod(*segs[r], zip(r, yl), zip(r, yr)),\
    \ R);\n        }\n        return op(L, R);\n    }\n\nprivate:\n    int n;\n  \
    \  const structure_new st_new;\n    const structure_set st_set;\n    const structure_prod\
    \ st_prod;\n    const value_merge op;\n    const value_t e;\n    std::vector<Pt>\
    \ points;\n    std::vector<std::vector<Pt>> yxs;\n    std::vector<structure_t*>\
    \ segs;\n\n    int zip(coordinate_t x) {\n        auto compare = [](const Pt&\
    \ l, const Pt& r) { return l.first < r.first; };\n        return std::distance(\n\
    \            points.begin(), std::lower_bound(points.begin(), points.end(), std::make_pair(x,\
    \ coordinate_t()), compare));\n    }\n\n    int zip(int i, coordinate_t y) {\n\
    \        auto compare = [](const Pt& l, const Pt& r) { return l.first < r.first;\
    \ };\n        return std::distance(\n            yxs[i].begin(), std::lower_bound(yxs[i].begin(),\
    \ yxs[i].end(), std::make_pair(y, coordinate_t()), compare));\n    }\n\n    int\
    \ zip(int i, coordinate_t x, coordinate_t y) {\n        return std::distance(yxs[i].begin(),\
    \ std::lower_bound(yxs[i].begin(), yxs[i].end(), std::make_pair(y, x)));\n   \
    \ }\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <functional>\n\
    #include <vector>\n\ntemplate <typename structure_t, typename value_t, typename\
    \ coordinate_t> struct RangeTree {\nprivate:\n    using structure_new = std::function<structure_t*(int)>;\n\
    \    using structure_set = std::function<void(structure_t&, int, value_t)>;\n\
    \    using structure_prod = std::function<value_t(structure_t&, int, int)>;\n\
    \    using value_merge = std::function<value_t(value_t, value_t)>;\n    using\
    \ Pt = std::pair<coordinate_t, coordinate_t>;\n\npublic:\n    RangeTree(const\
    \ structure_new& st_new,\n              const structure_set& st_set,\n       \
    \       const structure_prod& st_prod,\n              const value_merge& op,\n\
    \              const value_t& e)\n        : st_new(st_new), st_set(st_set), st_prod(st_prod),\
    \ op(op), e(e) {}\n\n    void add_point(coordinate_t x, coordinate_t y) { points.emplace_back(x,\
    \ y); }\n\n    void build() {\n        std::sort(points.begin(), points.end());\n\
    \        points.erase(std::unique(points.begin(), points.end()), points.end());\n\
    \        n = points.size();\n        yxs.resize(n << 1);\n        segs.resize(n\
    \ << 1, nullptr);\n        for (int i = 0; i < n; i++) yxs[n + i] = {{points[i].second,\
    \ points[i].first}};\n        for (int i = n - 1; i >= 0; i--) {\n           \
    \ auto& lch = yxs[i << 1 | 0];\n            auto& rch = yxs[i << 1 | 1];\n   \
    \         std::merge(lch.begin(), lch.end(), rch.begin(), rch.end(), std::back_inserter(yxs[i]));\n\
    \            yxs[i].erase(std::unique(yxs[i].begin(), yxs[i].end()), yxs[i].end());\n\
    \        }\n        for (int i = 0; i < (n << 1); i++) segs[i] = st_new(yxs[i].size());\n\
    \    }\n\n    void set(coordinate_t x, coordinate_t y, value_t val) {\n      \
    \  int i = std::distance(points.begin(), std::lower_bound(points.begin(), points.end(),\
    \ std::make_pair(x, y)));\n        assert(i < n && points[i] == std::make_pair(x,\
    \ y));\n        for (i += n; i; i >>= 1) st_set(*segs[i], zip(i, x, y), val);\n\
    \    }\n\n    value_t prod(coordinate_t xl, coordinate_t xr, coordinate_t yl,\
    \ coordinate_t yr) {\n        assert(xl <= xr && yl <= yr);\n        value_t L\
    \ = e, R = e;\n        int l = zip(xl), r = zip(xr);\n        for (l += n, r +=\
    \ n; l < r; l >>= 1, r >>= 1) {\n            if (l & 1) L = op(L, st_prod(*segs[l],\
    \ zip(l, yl), zip(l, yr))), l++;\n            if (r & 1) --r, R = op(st_prod(*segs[r],\
    \ zip(r, yl), zip(r, yr)), R);\n        }\n        return op(L, R);\n    }\n\n\
    private:\n    int n;\n    const structure_new st_new;\n    const structure_set\
    \ st_set;\n    const structure_prod st_prod;\n    const value_merge op;\n    const\
    \ value_t e;\n    std::vector<Pt> points;\n    std::vector<std::vector<Pt>> yxs;\n\
    \    std::vector<structure_t*> segs;\n\n    int zip(coordinate_t x) {\n      \
    \  auto compare = [](const Pt& l, const Pt& r) { return l.first < r.first; };\n\
    \        return std::distance(\n            points.begin(), std::lower_bound(points.begin(),\
    \ points.end(), std::make_pair(x, coordinate_t()), compare));\n    }\n\n    int\
    \ zip(int i, coordinate_t y) {\n        auto compare = [](const Pt& l, const Pt&\
    \ r) { return l.first < r.first; };\n        return std::distance(\n         \
    \   yxs[i].begin(), std::lower_bound(yxs[i].begin(), yxs[i].end(), std::make_pair(y,\
    \ coordinate_t()), compare));\n    }\n\n    int zip(int i, coordinate_t x, coordinate_t\
    \ y) {\n        return std::distance(yxs[i].begin(), std::lower_bound(yxs[i].begin(),\
    \ yxs[i].end(), std::make_pair(y, x)));\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: datastructure/RangeTree.hpp
  requiredBy: []
  timestamp: '2021-12-30 22:50:08+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/point_add_rectangle_sum.test.cpp
documentation_of: datastructure/RangeTree.hpp
layout: document
title: Range Tree
---

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

引数の渡し方がかなり複雑なのでテストファイルも併せて参考にするのが良い.
