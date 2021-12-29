---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/static_range_inversions_query.test.cpp
    title: test/yosupo/static_range_inversions_query.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"algorithm/Mo.hpp\"\n#include <algorithm>\n#include <cassert>\n\
    #include <cmath>\n#include <numeric>\n#include <vector>\n\nstruct Mo {\n    Mo(int\
    \ n) : n(n) {}\n\n    void add(int l, int r) {\n        assert(l <= r);\n    \
    \    left.emplace_back(l);\n        right.emplace_back(r);\n    }\n\n    template\
    \ <typename AL, typename AR, typename DL, typename DR, typename REM>\n    void\
    \ run(const AL& add_left, const AR& add_right, const DL& del_left, const DR del_right,\
    \ const REM& rem) {\n        int q = left.size(), width = n / std::min(std::max<int>(sqrt(q\
    \ * 2 / 3), 1), n);\n        std::vector<int> order(q);\n        std::iota(order.begin(),\
    \ order.end(), 0);\n        std::sort(order.begin(), order.end(), [&](int a, int\
    \ b) {\n            int ablock = left[a] / width, bblock = left[b] / width;\n\
    \            if (ablock != bblock) return ablock < bblock;\n            return\
    \ (ablock & 1) ? (right[a] > right[b]) : (right[a] < right[b]);\n        });\n\
    \n        int l = 0, r = 0;\n        for (auto idx : order) {\n            while\
    \ (l > left[idx]) add_left(--l);\n            while (r < right[idx]) add_right(r++);\n\
    \            while (l < left[idx]) del_left(l++);\n            while (r > right[idx])\
    \ del_right(--r);\n            rem(idx);\n        }\n    }\n\n    template <typename\
    \ A, typename D, typename REM> void run(const A& add, const D& del, const REM&\
    \ rem) {\n        run(add, add, del, del, rem);\n    }\n\nprivate:\n    int n;\n\
    \    std::vector<int> left, right;\n};\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <cmath>\n\
    #include <numeric>\n#include <vector>\n\nstruct Mo {\n    Mo(int n) : n(n) {}\n\
    \n    void add(int l, int r) {\n        assert(l <= r);\n        left.emplace_back(l);\n\
    \        right.emplace_back(r);\n    }\n\n    template <typename AL, typename\
    \ AR, typename DL, typename DR, typename REM>\n    void run(const AL& add_left,\
    \ const AR& add_right, const DL& del_left, const DR del_right, const REM& rem)\
    \ {\n        int q = left.size(), width = n / std::min(std::max<int>(sqrt(q *\
    \ 2 / 3), 1), n);\n        std::vector<int> order(q);\n        std::iota(order.begin(),\
    \ order.end(), 0);\n        std::sort(order.begin(), order.end(), [&](int a, int\
    \ b) {\n            int ablock = left[a] / width, bblock = left[b] / width;\n\
    \            if (ablock != bblock) return ablock < bblock;\n            return\
    \ (ablock & 1) ? (right[a] > right[b]) : (right[a] < right[b]);\n        });\n\
    \n        int l = 0, r = 0;\n        for (auto idx : order) {\n            while\
    \ (l > left[idx]) add_left(--l);\n            while (r < right[idx]) add_right(r++);\n\
    \            while (l < left[idx]) del_left(l++);\n            while (r > right[idx])\
    \ del_right(--r);\n            rem(idx);\n        }\n    }\n\n    template <typename\
    \ A, typename D, typename REM> void run(const A& add, const D& del, const REM&\
    \ rem) {\n        run(add, add, del, del, rem);\n    }\n\nprivate:\n    int n;\n\
    \    std::vector<int> left, right;\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: algorithm/Mo.hpp
  requiredBy: []
  timestamp: '2021-12-29 23:24:50+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/static_range_inversions_query.test.cpp
documentation_of: algorithm/Mo.hpp
layout: document
title: Mo's Algorithm
---

## 概要
区間の伸縮による更新が容易にできるときに, 事前にクエリの区間を適切に並び替えることで効率的に処理するアルゴリズム.

以下に記す時間計算量においては伸縮 1 回あたりの計算量を $O(1)$ としている.

| メンバ関数                                           | 効果                                                                    | 時間計算量         |
| ---------------------------------------------------- | ----------------------------------------------------------------------- | ------------------ |
| `Mo(n)`                                              | 要素数 $n$ の列に関するクエリを処理するとして初期化する.                | $O(1)$             |
| `add(l, r)`                                          | $[l, r)$ についてのクエリを追加する. この追加順はクエリの解答順に則る.  | $O(1)$             |
| `run(add_left, add_right, del_left, del_right, rem)` | 伸縮操作の関数及び解答の関数を引数にしてクエリを処理する.               | $O(N\sqrt{Q} + Q)$ |
| `run(add, del, rem)`                                 | 伸縮操作の関数 (左右で等価) 及び解答の関数を引数にしてクエリを処理する. | $O(N\sqrt{Q} + Q)$ |

## 問題例
- [Codeforces Round #221 (Div. 1) D. Tree and Queries](https://codeforces.com/contest/375/problem/D)
  - 部分木クエリはオイラーツアー順に並べることにより区間クエリになる. 種類数や転倒数に関連するクエリは Mo's algorithm で扱いやすい.

## Links
- [Mo's algorithm とその上位互換の話 - あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2016/07/01/000000)
- [Mo's algorithm - ei1333の日記](https://ei1333.hateblo.jp/entry/2017/09/11/211011)
