---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/datastructure/UndoUnionFind.hpp\"\n#include <cassert>\n\
    #include <stack>\n#include <vector>\n\nstruct UndoUnionFind {\n    UndoUnionFind(int\
    \ n) : n(n), data(n, -1) {}\n\n    int find(int x) const {\n        assert(0 <=\
    \ x && x < n);\n        return data[x] < 0 ? x : find(data[x]);\n    }\n\n   \
    \ bool merge(int x, int y) {\n        assert(0 <= x && x < n);\n        assert(0\
    \ <= y && y < n);\n        x = find(x), y = find(y);\n        history.emplace(x,\
    \ data[x]);\n        history.emplace(y, data[y]);\n        if (x == y) return\
    \ false;\n        if (-data[x] < -data[y]) std::swap(x, y);\n        data[x] +=\
    \ data[y];\n        data[y] = x;\n        return true;\n    }\n\n    bool same(int\
    \ x, int y) const {\n        assert(0 <= x && x < n);\n        assert(0 <= y &&\
    \ y < n);\n        return find(x) == find(y);\n    }\n\n    int size(int x) const\
    \ {\n        assert(0 <= x && x < n);\n        return -data[find(x)];\n    }\n\
    \n    void undo() {\n        assert(!history.empty());\n        data[history.top().first]\
    \ = history.top().second;\n        history.pop();\n        data[history.top().first]\
    \ = history.top().second;\n        history.pop();\n    }\n\n    void snapshot()\
    \ {\n        while (!history.empty()) history.pop();\n    }\n\n    void rollback()\
    \ {\n        while (!history.empty()) undo();\n    }\n\n    int operator[](int\
    \ x) const { return find(x); }\n\nprivate:\n    int n;\n    std::vector<int> data;\n\
    \    std::stack<std::pair<int, int>> history;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <stack>\n#include <vector>\n\n\
    struct UndoUnionFind {\n    UndoUnionFind(int n) : n(n), data(n, -1) {}\n\n  \
    \  int find(int x) const {\n        assert(0 <= x && x < n);\n        return data[x]\
    \ < 0 ? x : find(data[x]);\n    }\n\n    bool merge(int x, int y) {\n        assert(0\
    \ <= x && x < n);\n        assert(0 <= y && y < n);\n        x = find(x), y =\
    \ find(y);\n        history.emplace(x, data[x]);\n        history.emplace(y, data[y]);\n\
    \        if (x == y) return false;\n        if (-data[x] < -data[y]) std::swap(x,\
    \ y);\n        data[x] += data[y];\n        data[y] = x;\n        return true;\n\
    \    }\n\n    bool same(int x, int y) const {\n        assert(0 <= x && x < n);\n\
    \        assert(0 <= y && y < n);\n        return find(x) == find(y);\n    }\n\
    \n    int size(int x) const {\n        assert(0 <= x && x < n);\n        return\
    \ -data[find(x)];\n    }\n\n    void undo() {\n        assert(!history.empty());\n\
    \        data[history.top().first] = history.top().second;\n        history.pop();\n\
    \        data[history.top().first] = history.top().second;\n        history.pop();\n\
    \    }\n\n    void snapshot() {\n        while (!history.empty()) history.pop();\n\
    \    }\n\n    void rollback() {\n        while (!history.empty()) undo();\n  \
    \  }\n\n    int operator[](int x) const { return find(x); }\n\nprivate:\n    int\
    \ n;\n    std::vector<int> data;\n    std::stack<std::pair<int, int>> history;\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/UndoUnionFind.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/UndoUnionFind.hpp
layout: document
title: Union Find with Undo Operation
---

## 概要
経路圧縮せずにマージテクにより集合を管理する際，1 回の `merge(x, y)` 操作で値が変更されるのは `x = find(x), y = find(y)` とした後の `data[x], data[y]` の 2 箇所のみであるから，操作前の値を記憶しておくことで $O(1)$ で操作を巻き戻すことが可能である．
これを踏まえて `snapshot` や `rollback` といった機能も搭載したデータ構造．

| メンバ関数         | 効果                                                                                                              | 時間計算量                                                                      |
| ------------------ | ----------------------------------------------------------------------------------------------------------------- | ------------------------------------------------------------------------------- |
| `UndoUnionFind(n)` | 要素数 $n$ で初期化する．                                                                                         | $O(n)$                                                                          |
| `find(x)`          | 頂点 $x$ の属する集合の代表元を返す．                                                                             | $O(\log n)$                                                                     |
| `merge(x, y)`      | 頂点 $x, y$ が属する集合を併合する．                                                                              | $O(\log n)$                                                                     |
| `same(x, y)`       | 頂点 $x, y$ が同一の集合に属するか判定する．                                                                      | $O(\log n)$                                                                     |
| `size(x)`          | 頂点 $x$ が属する集合の要素数を返す．                                                                             | $O(\log n)$                                                                     |
| `undo()`           | `merge` 1 回分の処理を巻き戻す．                                                                                  | $O(1)$                                                                          |
| `snapshot()`       | 現在の集合の状態を保存する．                                                                                      | 前回 `snapshot` が呼び出されて以降に `merge` が行われた回数を $m$ として $O(m)$ |
| `rollback()`       | 前回 `snapshot` が呼び出されたときの状態まで巻き戻す．`snapshot` が一度も呼ばれていない場合には初期状態まで戻る． | $O(m)$                                                                          |
| `operator[x]`      | 頂点 $x$ の属する集合の代表元を返す．                                                                             | $O(\log n)$                                                                     |

## 問題例
- [Codeforces Round #680 (Div. 1, based on Moscow Team Olympiad) C. Team-Building](https://codeforces.com/contest/1444/problem/C)

## 参照
- [Mo's algorithm とその上位互換の話 - あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2016/07/01/000000)
