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
  bundledCode: "#line 2 \"src/datastructure/SlopeTrick.hpp\"\n#include <cassert>\n\
    #include <limits>\n#include <queue>\n\ntemplate <typename T> struct SlopeTrick\
    \ {\n    // initialize as f(x) = 0\n    SlopeTrick() : min_f(0), add_l(0), add_r(0)\
    \ {}\n\n    // argmin f(x), min f(x)\n    std::tuple<T, T, T> query() const {\
    \ return {top_L(), top_R(), min_f}; }\n\n    // f(x) += b\n    void add_const(const\
    \ T& b) { min_f += b; }\n\n    // f(x) += max(a - x, 0) \\_\n    void add_a_minus_x(const\
    \ T& a) {\n        min_f += std::max(T(0), a - top_R());\n        push_R(a);\n\
    \        push_L(pop_R());\n    }\n\n    // f(x) += max(x - a, 0) _/\n    void\
    \ add_x_minus_a(const T& a) {\n        min_f += std::max(T(0), top_L() - a);\n\
    \        push_L(a);\n        push_R(pop_L());\n    }\n\n    // f(x) += |x - a|\
    \ \\/\n    void add_abs(const T& a) {\n        add_a_minus_x(a);\n        add_x_minus_a(a);\n\
    \    }\n\n    // f(x) <- min_{y <= x} f(y) \\/ -> \\_\n    void chmin_right()\
    \ {\n        while (!R.empty()) R.pop();\n    }\n\n    // f(x) <- min_{x <= y}\
    \ f(y)\n    void chmin_left() {\n        while (!L.empty()) L.pop();\n    }\n\n\
    \    // f(x) <- min_{x - b <= y <= x - a} f(y)\n    void shift(const T& a, const\
    \ T& b) {\n        assert(a <= b);\n        add_l += a;\n        add_r += b;\n\
    \    }\n\n    // f(x) <- f(x - a)\n    void shift(const T& a) { shift(a, a); }\n\
    \n    // return f(x), f destructive\n    T get_destructive(const T& x) {\n   \
    \     T res = min_f;\n        while (!L.empty()) res += std::max(T(0), pop_L()\
    \ - x);\n        while (!R.empty()) res += std::max(T(0), x - pop_R());\n    \
    \    return res;\n    }\n\n    // f(x) += g(x), g destructive\n    void merge_destructive(SlopeTrick&\
    \ g) {\n        if (g.size() < size()) {\n            std::swap(min_f, g.min_f);\n\
    \            std::swap(L, g.L);\n            std::swap(R, g.R);\n            std::swap(min_f,\
    \ g.add_l);\n            std::swap(min_f, g.add_r);\n        }\n        min_f\
    \ += g.min_f;\n        while (!g.L.empty()) add_a_minus_x(g.pop_L());\n      \
    \  while (!g.R.empty()) add_x_minus_a(g.pop_R());\n    }\n\nprivate:\n    const\
    \ T inf = std::numeric_limits<T>::max() / 2;\n    T min_f;\n    std::priority_queue<T,\
    \ std::vector<T>, std::less<>> L;\n    std::priority_queue<T, std::vector<T>,\
    \ std::greater<>> R;\n    T add_l, add_r;\n\n    void push_L(const T& a) { L.emplace(a\
    \ - add_l); }\n\n    T top_L() const { return L.empty() ? -inf : L.top() + add_l;\
    \ }\n\n    T pop_L() {\n        T res = top_L();\n        if (!L.empty()) L.pop();\n\
    \        return res;\n    }\n\n    void push_R(const T& a) { R.emplace(a - add_r);\
    \ }\n\n    T top_R() const { return R.empty() ? inf : R.top() + add_r; }\n\n \
    \   T pop_R() {\n        T res = top_R();\n        if (!R.empty()) R.pop();\n\
    \        return res;\n    }\n\n    size_t size() const { return L.size() + R.size();\
    \ }\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <limits>\n#include <queue>\n\n\
    template <typename T> struct SlopeTrick {\n    // initialize as f(x) = 0\n   \
    \ SlopeTrick() : min_f(0), add_l(0), add_r(0) {}\n\n    // argmin f(x), min f(x)\n\
    \    std::tuple<T, T, T> query() const { return {top_L(), top_R(), min_f}; }\n\
    \n    // f(x) += b\n    void add_const(const T& b) { min_f += b; }\n\n    // f(x)\
    \ += max(a - x, 0) \\_\n    void add_a_minus_x(const T& a) {\n        min_f +=\
    \ std::max(T(0), a - top_R());\n        push_R(a);\n        push_L(pop_R());\n\
    \    }\n\n    // f(x) += max(x - a, 0) _/\n    void add_x_minus_a(const T& a)\
    \ {\n        min_f += std::max(T(0), top_L() - a);\n        push_L(a);\n     \
    \   push_R(pop_L());\n    }\n\n    // f(x) += |x - a| \\/\n    void add_abs(const\
    \ T& a) {\n        add_a_minus_x(a);\n        add_x_minus_a(a);\n    }\n\n   \
    \ // f(x) <- min_{y <= x} f(y) \\/ -> \\_\n    void chmin_right() {\n        while\
    \ (!R.empty()) R.pop();\n    }\n\n    // f(x) <- min_{x <= y} f(y)\n    void chmin_left()\
    \ {\n        while (!L.empty()) L.pop();\n    }\n\n    // f(x) <- min_{x - b <=\
    \ y <= x - a} f(y)\n    void shift(const T& a, const T& b) {\n        assert(a\
    \ <= b);\n        add_l += a;\n        add_r += b;\n    }\n\n    // f(x) <- f(x\
    \ - a)\n    void shift(const T& a) { shift(a, a); }\n\n    // return f(x), f destructive\n\
    \    T get_destructive(const T& x) {\n        T res = min_f;\n        while (!L.empty())\
    \ res += std::max(T(0), pop_L() - x);\n        while (!R.empty()) res += std::max(T(0),\
    \ x - pop_R());\n        return res;\n    }\n\n    // f(x) += g(x), g destructive\n\
    \    void merge_destructive(SlopeTrick& g) {\n        if (g.size() < size()) {\n\
    \            std::swap(min_f, g.min_f);\n            std::swap(L, g.L);\n    \
    \        std::swap(R, g.R);\n            std::swap(min_f, g.add_l);\n        \
    \    std::swap(min_f, g.add_r);\n        }\n        min_f += g.min_f;\n      \
    \  while (!g.L.empty()) add_a_minus_x(g.pop_L());\n        while (!g.R.empty())\
    \ add_x_minus_a(g.pop_R());\n    }\n\nprivate:\n    const T inf = std::numeric_limits<T>::max()\
    \ / 2;\n    T min_f;\n    std::priority_queue<T, std::vector<T>, std::less<>>\
    \ L;\n    std::priority_queue<T, std::vector<T>, std::greater<>> R;\n    T add_l,\
    \ add_r;\n\n    void push_L(const T& a) { L.emplace(a - add_l); }\n\n    T top_L()\
    \ const { return L.empty() ? -inf : L.top() + add_l; }\n\n    T pop_L() {\n  \
    \      T res = top_L();\n        if (!L.empty()) L.pop();\n        return res;\n\
    \    }\n\n    void push_R(const T& a) { R.emplace(a - add_r); }\n\n    T top_R()\
    \ const { return R.empty() ? inf : R.top() + add_r; }\n\n    T pop_R() {\n   \
    \     T res = top_R();\n        if (!R.empty()) R.pop();\n        return res;\n\
    \    }\n\n    size_t size() const { return L.size() + R.size(); }\n};\n"
  dependsOn: []
  isVerificationFile: false
  path: src/datastructure/SlopeTrick.hpp
  requiredBy: []
  timestamp: '2023-01-12 22:28:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/datastructure/SlopeTrick.hpp
layout: document
title: Slope Trick
---

## 概要
区分線形凸関数 $f(x)$ を傾きの変化点の集合を管理することで，諸操作を効率的に行えるようにしたデータ構造．

| メンバ関数             | 効果                                                                                            | 時間計算量                                                              |
| ---------------------- | ----------------------------------------------------------------------------------------------- | ----------------------------------------------------------------------- |
| `query()`              | $f(x)$ が最小値を取るような $x$ の最小値，最大値，そのときの $f(x)$ の値を `tuple` にして返す． | $O(1)$                                                                  |
| `add_const()`          | $f(x)$ に均一に $a$ を加算する．                                                                | $O(1)$                                                                  |
| `add_a_minus_x(a)`     | $f(x)$ に $\max(x - a, 0)$ を加算する．                                                         | $O(\log N)$                                                             |
| `add_x_minus_a(a)`     | $f(x)$ に $\max(a - x, 0)$ を加算する．                                                         | $O(\log N)$                                                             |
| `add_abs(a)`           | $f(x)$ に $\|x - a\|$ を加算する．                                                              | $O(\log N)$                                                             |
| `chmin_right()`        | $f(x) \leftarrow \min_{y \leq x} f(y)$ とする．                                                 | $O(N)$                                                                  |
| `chmin_left()`         | $f(x) \leftarrow \min_{x \leq y} f(y)$ とする．                                                 | $O(N)$                                                                  |
| `shift(a, b)`          | $f(x) \leftarrow \min_{y \in [x - b, x - a]} f(y)$ とする．$[x - b, x - a]$ であることに注意．  | $O(1)$                                                                  |
| `shift(a)`             | $f(x) \leftarrow f(x - a)$ とする．                                                             | $O(1)$                                                                  |
| `get_destructive(x)`   | $f$ を破壊する代わりに $f(x)$ を返す．                                                          | $O(N)$                                                                  |
| `merge_destructive(g)` | $g$ を破壊する代わりに $f(x)$ に $g(x)$ を加算する．                                            | $f, g$ の大きさをそれぞれ $N, M$ として $O(\min(N, M) \log \max(N, M))$ |

## 問題例
- [AtCoder Beginner Contest 217 H- Snuketoon](https://atcoder.jp/contests/abc217/tasks/abc217_h)
- [Codeforces LATOKEN Round 1 (Div. 1 + Div. 2) G. A New Beginning](https://codeforces.com/contest/1534/problem/G)
- [Codeforces Round #219 (Div. 1) C. Watching Fireworks is Fun](https://codeforces.com/contest/372/problem/C)
  - 想定解はスライド最小値．
- [“范式杯”2023牛客暑期多校训练营1 E Heap](https://ac.nowcoder.com/acm/contest/57355/E)
  - 微分すると折れ線管理に帰着される．

## 参照
- [[Tutorial] Slope Trick - Codeforces](https://codeforces.com/blog/entry/47821)
- [Slope trick explained - Codeforces](https://codeforces.com/blog/entry/77298)
- [slope trick (1) 解説編 \| maspyのHP](https://maspypy.com/slope-trick-1-%E8%A7%A3%E8%AA%AC%E7%B7%A8)
- [Slope-Trick \| Luzhiled’s Library](https://ei1333.github.io/library/structure/others/slope-trick.cpp)
