---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1181.test.cpp
    title: test/aoj/1181.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_A.test.cpp
    title: test/aoj/ITP1_11_A.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_B.test.cpp
    title: test/aoj/ITP1_11_B.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_C.test.cpp
    title: test/aoj/ITP1_11_C.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/ITP1_11_D.test.cpp
    title: test/aoj/ITP1_11_D.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/util/Dice.hpp\"\n#include <algorithm>\n#include <array>\n\
    #include <cassert>\n#include <string>\n#include <vector>\n\nstruct Dice {\n  \
    \  std::array<int, 6> surface;\n\n    Dice(int TOP = 1, int FRONT = 2) {\n   \
    \     assert(1 <= TOP and TOP <= 6);\n        assert(1 <= FRONT and FRONT <= 6);\n\
    \        assert(TOP + FRONT != 7);\n        surface[0] = TOP;\n        surface[1]\
    \ = FRONT;\n        surface[2] = dice[TOP - 1][FRONT - 1];\n        surface[3]\
    \ = 7 - surface[2];\n        surface[4] = 7 - surface[1];\n        surface[5]\
    \ = 7 - surface[0];\n    }\n\n    Dice(const std::vector<int>& v) {\n        assert(v.size()\
    \ == 6);\n        for (size_t i = 0; i < 6; i++) surface[i] = v[i];\n    }\n\n\
    \    const int& top() const { return surface[0]; }\n    const int& front() const\
    \ { return surface[1]; }\n    const int& right() const { return surface[2]; }\n\
    \    const int& left() const { return surface[3]; }\n    const int& back() const\
    \ { return surface[4]; }\n    const int& bottom() const { return surface[5]; }\n\
    \    const int& operator[](int k) const { return surface[k]; }\n\n    int& top()\
    \ { return surface[0]; }\n    int& front() { return surface[1]; }\n    int& right()\
    \ { return surface[2]; }\n    int& left() { return surface[3]; }\n    int& back()\
    \ { return surface[4]; }\n    int& bottom() { return surface[5]; }\n    int& operator[](int\
    \ k) { return surface[k]; }\n\n    bool operator==(const Dice& d) const { return\
    \ surface == d.surface; }\n    bool operator!=(const Dice& d) const { return surface\
    \ != d.surface; }\n    bool operator<(const Dice& d) const { return surface <\
    \ d.surface; }\n\n    int roll(int k) {  // x++, x--, y++, y--, turn right, turn\
    \ left\n        assert(0 <= k and k < 6);\n        int tmp = surface[code[k][0]];\n\
    \        for (int i = 0; i < 3; i++) surface[code[k][i]] = surface[code[k][i +\
    \ 1]];\n        surface[code[k][3]] = tmp;\n        return surface[0];\n    }\n\
    \n    int rollc(char c) {\n        for (int k = 0; k < 6; k++) {\n           \
    \ if (direction[k] != c) continue;\n            return roll(k);\n        }\n \
    \       assert(false);\n    }\n\n    int hash() const {\n        int res = 0;\n\
    \        for (size_t i = 0; i < 6; i++) {\n            assert(1 <= surface[i]\
    \ and surface[i] <= 6);\n            (res *= 6) += surface[i] - 1;\n        }\n\
    \        return res;\n    }\n\n    std::vector<Dice> make_all() {\n        std::vector<Dice>\
    \ res;\n        for (int i = 0; i < 6; i++) {\n            Dice d(*this);\n  \
    \          if (i == 1) d.roll(2);\n            if (i == 2) d.roll(3);\n      \
    \      if (i == 3) d.roll(3), d.roll(3);\n            if (i == 4) d.roll(5);\n\
    \            if (i == 5) d.roll(4);\n            for (int j = 0; j < 4; j++) {\n\
    \                res.emplace_back(d);\n                d.roll(0);\n          \
    \  }\n        }\n        return res;\n    }\n\n    Dice identifier() {\n     \
    \   auto dices = make_all();\n        return *std::min_element(dices.begin(),\
    \ dices.end());\n    }\n\nprivate:\n    const int dice[6][6] = {{0, 3, 5, 2, 4,\
    \ 0}, {4, 0, 1, 6, 0, 3}, {2, 6, 0, 0, 1, 5},\n                            {5,\
    \ 1, 0, 0, 6, 2}, {3, 0, 6, 1, 0, 4}, {0, 4, 2, 5, 3, 0}};\n    const int code[6][4]\
    \ = {{0, 3, 5, 2}, {0, 2, 5, 3}, {0, 1, 5, 4}, {0, 4, 5, 1}, {1, 2, 4, 3}, {1,\
    \ 3, 4, 2}};\n    const char direction[6] = {'E', 'W', 'N', 'S', 'R', 'L'};\n\
    };\n"
  code: "#pragma once\n#include <algorithm>\n#include <array>\n#include <cassert>\n\
    #include <string>\n#include <vector>\n\nstruct Dice {\n    std::array<int, 6>\
    \ surface;\n\n    Dice(int TOP = 1, int FRONT = 2) {\n        assert(1 <= TOP\
    \ and TOP <= 6);\n        assert(1 <= FRONT and FRONT <= 6);\n        assert(TOP\
    \ + FRONT != 7);\n        surface[0] = TOP;\n        surface[1] = FRONT;\n   \
    \     surface[2] = dice[TOP - 1][FRONT - 1];\n        surface[3] = 7 - surface[2];\n\
    \        surface[4] = 7 - surface[1];\n        surface[5] = 7 - surface[0];\n\
    \    }\n\n    Dice(const std::vector<int>& v) {\n        assert(v.size() == 6);\n\
    \        for (size_t i = 0; i < 6; i++) surface[i] = v[i];\n    }\n\n    const\
    \ int& top() const { return surface[0]; }\n    const int& front() const { return\
    \ surface[1]; }\n    const int& right() const { return surface[2]; }\n    const\
    \ int& left() const { return surface[3]; }\n    const int& back() const { return\
    \ surface[4]; }\n    const int& bottom() const { return surface[5]; }\n    const\
    \ int& operator[](int k) const { return surface[k]; }\n\n    int& top() { return\
    \ surface[0]; }\n    int& front() { return surface[1]; }\n    int& right() { return\
    \ surface[2]; }\n    int& left() { return surface[3]; }\n    int& back() { return\
    \ surface[4]; }\n    int& bottom() { return surface[5]; }\n    int& operator[](int\
    \ k) { return surface[k]; }\n\n    bool operator==(const Dice& d) const { return\
    \ surface == d.surface; }\n    bool operator!=(const Dice& d) const { return surface\
    \ != d.surface; }\n    bool operator<(const Dice& d) const { return surface <\
    \ d.surface; }\n\n    int roll(int k) {  // x++, x--, y++, y--, turn right, turn\
    \ left\n        assert(0 <= k and k < 6);\n        int tmp = surface[code[k][0]];\n\
    \        for (int i = 0; i < 3; i++) surface[code[k][i]] = surface[code[k][i +\
    \ 1]];\n        surface[code[k][3]] = tmp;\n        return surface[0];\n    }\n\
    \n    int rollc(char c) {\n        for (int k = 0; k < 6; k++) {\n           \
    \ if (direction[k] != c) continue;\n            return roll(k);\n        }\n \
    \       assert(false);\n    }\n\n    int hash() const {\n        int res = 0;\n\
    \        for (size_t i = 0; i < 6; i++) {\n            assert(1 <= surface[i]\
    \ and surface[i] <= 6);\n            (res *= 6) += surface[i] - 1;\n        }\n\
    \        return res;\n    }\n\n    std::vector<Dice> make_all() {\n        std::vector<Dice>\
    \ res;\n        for (int i = 0; i < 6; i++) {\n            Dice d(*this);\n  \
    \          if (i == 1) d.roll(2);\n            if (i == 2) d.roll(3);\n      \
    \      if (i == 3) d.roll(3), d.roll(3);\n            if (i == 4) d.roll(5);\n\
    \            if (i == 5) d.roll(4);\n            for (int j = 0; j < 4; j++) {\n\
    \                res.emplace_back(d);\n                d.roll(0);\n          \
    \  }\n        }\n        return res;\n    }\n\n    Dice identifier() {\n     \
    \   auto dices = make_all();\n        return *std::min_element(dices.begin(),\
    \ dices.end());\n    }\n\nprivate:\n    const int dice[6][6] = {{0, 3, 5, 2, 4,\
    \ 0}, {4, 0, 1, 6, 0, 3}, {2, 6, 0, 0, 1, 5},\n                            {5,\
    \ 1, 0, 0, 6, 2}, {3, 0, 6, 1, 0, 4}, {0, 4, 2, 5, 3, 0}};\n    const int code[6][4]\
    \ = {{0, 3, 5, 2}, {0, 2, 5, 3}, {0, 1, 5, 4}, {0, 4, 5, 1}, {1, 2, 4, 3}, {1,\
    \ 3, 4, 2}};\n    const char direction[6] = {'E', 'W', 'N', 'S', 'R', 'L'};\n\
    };\n"
  dependsOn: []
  isVerificationFile: false
  path: src/util/Dice.hpp
  requiredBy: []
  timestamp: '2023-01-12 23:01:53+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ITP1_11_D.test.cpp
  - test/aoj/ITP1_11_A.test.cpp
  - test/aoj/1181.test.cpp
  - test/aoj/ITP1_11_B.test.cpp
  - test/aoj/ITP1_11_C.test.cpp
documentation_of: src/util/Dice.hpp
layout: document
title: "\u30B5\u30A4\u30B3\u30ED"
---

## 概要
サイコロを扱うライブラリ. 主に ICPC 国内予選用.

サイコロは隣接する 2 面の情報が与えられれば各面の数字の情報は一意に定まる.

実装においては面に 0 から 5 の番号をつけ, それぞれ上面, 前面, 右面, 左面, 背面, 底面に対応させている. また, `roll` や `rollc` での回転方向については,

- `0` or `E` : サイコロを右に倒す. すなわち $(x, y) \to (x + 1, y)$ のようにサイコロを移動させる.
- `1` or `W` : サイコロを左に倒す. すなわち $(x, y) \to (x - 1, y)$ のようにサイコロを移動させる.
- `2` or `N` : サイコロを奥に倒す. すなわち $(x, y) \to (x , y + 1)$ のようにサイコロを移動させる.
- `3` or `S` : サイコロを手前に倒す. すなわち $(x, y) \to (x , y - 1)$ のようにサイコロを移動させる.
- `4` or `R` : サイコロをその場で右に (上から見て反時計回りに) 回転させる.
- `5` or `L` : サイコロをその場で左に (上から見て時計回りに) 回転させる.

となっている.

| メンバ関数         | 効果                                                                                                                                        | 時間計算量 |
| ------------------ | ------------------------------------------------------------------------------------------------------------------------------------------- | ---------- |
| `Dice(TOP, FRONT)` | 上面の数字 `TOP` と 前面の数字 `FRONT` から適切なサイコロを構築する.                                                                        | $O(1)$     |
| `Dice(v)`          | 上面, 前面, 右面, 左面, 背面, 底面の順に数が詰まった配列 `v` からサイコロを構築する.                                                        | $O(1)$     |
| `top()`            | 上面に書かれた数字を返す.                                                                                                                   | $O(1)$     |
| `front()`          | 前面に書かれた数字を返す.                                                                                                                   | $O(1)$     |
| `right()`          | 右面に書かれた数字を返す.                                                                                                                   | $O(1)$     |
| `left()`           | 左面に書かれた数字を返す.                                                                                                                   | $O(1)$     |
| `back()`           | 背面に書かれた数字を返す.                                                                                                                   | $O(1)$     |
| `bottom()`         | 底面に書かれた数字を返す.                                                                                                                   | $O(1)$     |
| `operator[k]`      | 対応する番号の面に書かれた数字を返す.                                                                                                       | $O(1)$     |
| `roll(k)`          | 対応する番号の方向にサイコロを移動させる.                                                                                                   | $O(1)$     |
| `rollc(c)`         | 移動方向を文字で指定して実行する.                                                                                                           | $O(1)$     |
| `hash()`           | サイコロの hash 値を計算して返す.                                                                                                           | $O(1)$     |
| `make_all()`       | サイコロを自由に転がすことで有り得る全状態を返す. これは合計で 24 個存在する.                                                               | $O(1)$     |
| `identifier()`     | サイコロを自由に転がすことでできる面に書かれた数字についての辞書順最小のサイコロを返す. 2 つのサイコロが同型かどうかの判定の際などに用いる. | $O(1)$     |
