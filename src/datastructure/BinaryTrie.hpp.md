---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/set_xor_min.test.cpp
    title: test/yosupo/set_xor_min.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"src/datastructure/BinaryTrie.hpp\"\n#include <array>\n#include\
    \ <cassert>\n#include <vector>\n\ntemplate <typename T, int MAX_LOG> struct BinaryTrie\
    \ {\n    struct Node {\n        std::array<int, 2> nxt;\n        int count;\n\
    \        Node() : nxt{-1, -1}, count(0) {}\n    };\n\n    std::vector<Node> nodes;\n\
    \n    inline int& next(int i, int j) { return nodes[i].nxt[j]; }\n\n    BinaryTrie()\
    \ { nodes.emplace_back(); }\n\n    void insert(const T& x) {\n        int cur\
    \ = 0;\n        for (int i = MAX_LOG - 1; i >= 0; i--) {\n            int f =\
    \ x >> i & 1;\n            int nxt = next(cur, f);\n            if (nxt == -1)\
    \ {\n                nxt = nodes.size();\n                next(cur, f) = nxt;\n\
    \                nodes.emplace_back();\n            }\n            nodes[cur].count++;\n\
    \            cur = nxt;\n        }\n        nodes[cur].count++;\n    }\n\n   \
    \ void erase(const T& x) {\n        assert(count(x));\n        int cur = 0;\n\
    \        for (int i = MAX_LOG - 1; i >= 0; i--) {\n            int f = x >> i\
    \ & 1;\n            nodes[cur].count--;\n            cur = next(cur, f);\n   \
    \     }\n        nodes[cur].count--;\n    }\n\n    int find(const T& x) {\n  \
    \      int cur = 0;\n        for (int i = MAX_LOG - 1; i >= 0; i--) {\n      \
    \      int f = x >> i & 1;\n            cur = next(cur, f);\n            if (cur\
    \ == -1) return -1;\n        }\n        return cur;\n    }\n\n    int count(const\
    \ T& x) {\n        int idx = find(x);\n        return idx == -1 ? 0 : nodes[idx].count;\n\
    \    }\n\n    T min_element(const T& xor_val = 0) {\n        int cur = 0;\n  \
    \      T res = 0;\n        for (int i = MAX_LOG - 1; i >= 0; i--) {\n        \
    \    int f = xor_val >> i & 1;\n            int l = next(cur, f), r = next(cur,\
    \ f ^ 1);\n            if (l == -1 or nodes[l].count == 0) {\n               \
    \ cur = r;\n                res |= T(f ^ 1) << i;\n            } else {\n    \
    \            cur = l;\n                res |= T(f) << i;\n            }\n    \
    \    }\n        return res;\n    }\n\n    T max_element(const T& xor_val = 0)\
    \ { return min_element(~xor_val); }\n\n    T kth_element(int k, const T& xor_val\
    \ = 0) const {\n        int cur = 0;\n        T res = 0;\n        for (int i =\
    \ MAX_LOG - 1; i >= 0; i--) {\n            int f = xor_val >> i & 1;\n       \
    \     int l = next(cur, f), r = next(cur, f ^ 1);\n            if (l == -1 or\
    \ nodes[l].count <= k) {\n                cur = r;\n                k -= (l ==\
    \ -1 ? 0 : nodes[l].count);\n                res |= T(f ^ 1) << i;\n         \
    \   } else {\n                cur = l;\n                res |= T(f) << i;\n  \
    \          }\n        }\n        return res;\n    }\n\n    int count_less(const\
    \ T& x, const T& xor_val = 0) {\n        int cur = 0;\n        int res = 0;\n\
    \        for (int i = MAX_LOG - 1; i >= 0; i--) {\n            int f = xor_val\
    \ >> i & 1, g = x >> i & 1;\n            int l = next(cur, f), r = next(cur, f\
    \ ^ 1);\n            if (f != g and l != -1) res += nodes[l].count;\n        \
    \    cur = next(cur, g);\n            if (cur == -1) break;\n        }\n     \
    \   return res;\n    }\n};\n"
  code: "#pragma once\n#include <array>\n#include <cassert>\n#include <vector>\n\n\
    template <typename T, int MAX_LOG> struct BinaryTrie {\n    struct Node {\n  \
    \      std::array<int, 2> nxt;\n        int count;\n        Node() : nxt{-1, -1},\
    \ count(0) {}\n    };\n\n    std::vector<Node> nodes;\n\n    inline int& next(int\
    \ i, int j) { return nodes[i].nxt[j]; }\n\n    BinaryTrie() { nodes.emplace_back();\
    \ }\n\n    void insert(const T& x) {\n        int cur = 0;\n        for (int i\
    \ = MAX_LOG - 1; i >= 0; i--) {\n            int f = x >> i & 1;\n           \
    \ int nxt = next(cur, f);\n            if (nxt == -1) {\n                nxt =\
    \ nodes.size();\n                next(cur, f) = nxt;\n                nodes.emplace_back();\n\
    \            }\n            nodes[cur].count++;\n            cur = nxt;\n    \
    \    }\n        nodes[cur].count++;\n    }\n\n    void erase(const T& x) {\n \
    \       assert(count(x));\n        int cur = 0;\n        for (int i = MAX_LOG\
    \ - 1; i >= 0; i--) {\n            int f = x >> i & 1;\n            nodes[cur].count--;\n\
    \            cur = next(cur, f);\n        }\n        nodes[cur].count--;\n   \
    \ }\n\n    int find(const T& x) {\n        int cur = 0;\n        for (int i =\
    \ MAX_LOG - 1; i >= 0; i--) {\n            int f = x >> i & 1;\n            cur\
    \ = next(cur, f);\n            if (cur == -1) return -1;\n        }\n        return\
    \ cur;\n    }\n\n    int count(const T& x) {\n        int idx = find(x);\n   \
    \     return idx == -1 ? 0 : nodes[idx].count;\n    }\n\n    T min_element(const\
    \ T& xor_val = 0) {\n        int cur = 0;\n        T res = 0;\n        for (int\
    \ i = MAX_LOG - 1; i >= 0; i--) {\n            int f = xor_val >> i & 1;\n   \
    \         int l = next(cur, f), r = next(cur, f ^ 1);\n            if (l == -1\
    \ or nodes[l].count == 0) {\n                cur = r;\n                res |=\
    \ T(f ^ 1) << i;\n            } else {\n                cur = l;\n           \
    \     res |= T(f) << i;\n            }\n        }\n        return res;\n    }\n\
    \n    T max_element(const T& xor_val = 0) { return min_element(~xor_val); }\n\n\
    \    T kth_element(int k, const T& xor_val = 0) const {\n        int cur = 0;\n\
    \        T res = 0;\n        for (int i = MAX_LOG - 1; i >= 0; i--) {\n      \
    \      int f = xor_val >> i & 1;\n            int l = next(cur, f), r = next(cur,\
    \ f ^ 1);\n            if (l == -1 or nodes[l].count <= k) {\n               \
    \ cur = r;\n                k -= (l == -1 ? 0 : nodes[l].count);\n           \
    \     res |= T(f ^ 1) << i;\n            } else {\n                cur = l;\n\
    \                res |= T(f) << i;\n            }\n        }\n        return res;\n\
    \    }\n\n    int count_less(const T& x, const T& xor_val = 0) {\n        int\
    \ cur = 0;\n        int res = 0;\n        for (int i = MAX_LOG - 1; i >= 0; i--)\
    \ {\n            int f = xor_val >> i & 1, g = x >> i & 1;\n            int l\
    \ = next(cur, f), r = next(cur, f ^ 1);\n            if (f != g and l != -1) res\
    \ += nodes[l].count;\n            cur = next(cur, g);\n            if (cur ==\
    \ -1) break;\n        }\n        return res;\n    }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2023-06-08 18:42:58+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/set_xor_min.test.cpp
documentation_of: src/datastructure/BinaryTrie.hpp
layout: document
title: Binary Trie
---

## 概要
整数の $2$ 進数表現を利用して Trie 木のように非負整数を管理する `std::multiset` をより汎用的にしたデータ構造．

以下ではこのデータ構造にその時点で格納されている非負整数の集合を $S$ としている．
また整数の最大 bit 長を $w$ とする．
__各クエリにおいて返される整数は $xor\\_val$ を適用する前のものであることに注意．

| メンバ関数                | 効果                                                                                                                      | 時間計算量    |
| ------------------------- | ------------------------------------------------------------------------------------------------------------------------- | ------------- |
| `insert(x)`               | $S$ に $x$ を追加する．                                                                                                   | $O(w)$        |
| `erase(x)`                | $S$ から $x$ を $1$ つ削除する．                                                                                          | $O(w)$        |
| `find(x)`                 | $S$ に $x$ が含めれていない場合は $-1$ を，含まれている場合はそれに対応するノード番号（非負）を返す．                     | クエリ $O(w)$ |
| `count(x)`                | $S$ に含まれる $x$ の個数を求める．                                                                                       | $O(w)$        |
| `min_element(xor_val)`    | $\argmin_{x \in S} x \oplus xor\\_val$ を求める．                                                                         | $O(w)$        |
| `max_element(xor_val)`    | $\argmax_{x \in S} x \oplus xor\\_val$ を求める．                                                                         | $O(w)$        |
| `kth_element(k, xor_val)` | $T = \{s \oplus xor\\_val \mid s \in S\}$ として，$T$ の小さい方から $k$ 番目 (0-indexed) の元に対応する $S$ の元を返す． | $O(w)$        |
| `count_less(x, xor_val)`  | $T = \{s \oplus xor\\_val \mid s \in S\}$ において $x$ 未満の元の個数を返す．                                             | $O(w)$        |
