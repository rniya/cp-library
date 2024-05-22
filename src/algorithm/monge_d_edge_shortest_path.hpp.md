---
data:
  _extendedDependsOn:
  - icon: ':warning:'
    path: src/algorithm/golden_section_search.hpp
    title: Golden Section Search
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    links: []
  bundledCode: "#line 1 \"src/algorithm/monge_d_edge_shortest_path.hpp\"\n#include\
    \ <cassert>\n#include <functional>\n#include <limits>\n#include <vector>\n#line\
    \ 3 \"src/algorithm/golden_section_search.hpp\"\n#include <utility>\n\ntemplate\
    \ <typename T, bool get_min = true>\nstd::pair<long long, T> golden_section_search(const\
    \ std::function<T(long long)>& f, long long mini, long long maxi) {\n    assert(mini\
    \ <= maxi);\n    long long a = mini - 1, x, b;\n    {\n        long long s = 1,\
    \ t = 2;\n        while (t < maxi - mini + 2) std::swap(s += t, t);\n        x\
    \ = a + t - s, b = a + t;\n    }\n    T fx = f(x), fy;\n    while (a + b != 2\
    \ * x) {\n        long long y = a + b - x;\n        fy = f(y);\n        if (maxi\
    \ < y or (get_min ? fx < fy : fx > fy)) {\n            b = a;\n            a =\
    \ y;\n        } else {\n            a = x;\n            x = y;\n            fx\
    \ = fy;\n        }\n    }\n    return {x, fx};\n}\n#line 6 \"src/algorithm/monge_d_edge_shortest_path.hpp\"\
    \n\ntemplate <typename T> std::vector<T> monge_shortest_path(int N, const std::function<T(int,\
    \ int)>& f) {\n    std::vector<T> dp(N + 1, std::numeric_limits<T>::max() / 2);\n\
    \    std::vector<int> x(N + 1);\n    dp[0] = x[0] = 0, x[N] = N;\n    auto check\
    \ = [&](int from, int to) {\n        if (from >= to) return;\n        T cost =\
    \ f(from, to);\n        if (dp[from] + cost < dp[to]) {\n            dp[to] =\
    \ dp[from] + cost;\n            x[to] = from;\n        }\n    };\n    auto solve\
    \ = [&](auto&& self, int l, int r) -> void {\n        if (l >= r) return;\n  \
    \      int m = (l + r) >> 1;\n        x[m] = x[l];\n        for (int i = x[l];\
    \ i <= x[r]; i++) check(i, m);\n        if (r - l > 1) self(self, l, m);\n   \
    \     for (int i = l; i <= m; i++) check(i, r);\n        if (r - l > 1) self(self,\
    \ m, r);\n    };\n    solve(solve, 0, N);\n    return dp;\n}\n\nlong long monge_d_edge_shortest_path(int\
    \ N, int D, long long upper, const std::function<long long(int, int)>& f) {\n\
    \    assert(0 <= upper);\n    auto dp = [&](long long x) -> long long {\n    \
    \    auto g = [&](int from, int to) -> long long { return f(from, to) + x; };\n\
    \        long long cost = monge_shortest_path<long long>(N, g)[N];\n        return\
    \ cost - 1LL * D * x;\n    };\n    auto [tmp, res] = golden_section_search<long\
    \ long, false>(dp, -upper, upper);\n    return res;\n}\n"
  code: "#include <cassert>\n#include <functional>\n#include <limits>\n#include <vector>\n\
    #include \"golden_section_search.hpp\"\n\ntemplate <typename T> std::vector<T>\
    \ monge_shortest_path(int N, const std::function<T(int, int)>& f) {\n    std::vector<T>\
    \ dp(N + 1, std::numeric_limits<T>::max() / 2);\n    std::vector<int> x(N + 1);\n\
    \    dp[0] = x[0] = 0, x[N] = N;\n    auto check = [&](int from, int to) {\n \
    \       if (from >= to) return;\n        T cost = f(from, to);\n        if (dp[from]\
    \ + cost < dp[to]) {\n            dp[to] = dp[from] + cost;\n            x[to]\
    \ = from;\n        }\n    };\n    auto solve = [&](auto&& self, int l, int r)\
    \ -> void {\n        if (l >= r) return;\n        int m = (l + r) >> 1;\n    \
    \    x[m] = x[l];\n        for (int i = x[l]; i <= x[r]; i++) check(i, m);\n \
    \       if (r - l > 1) self(self, l, m);\n        for (int i = l; i <= m; i++)\
    \ check(i, r);\n        if (r - l > 1) self(self, m, r);\n    };\n    solve(solve,\
    \ 0, N);\n    return dp;\n}\n\nlong long monge_d_edge_shortest_path(int N, int\
    \ D, long long upper, const std::function<long long(int, int)>& f) {\n    assert(0\
    \ <= upper);\n    auto dp = [&](long long x) -> long long {\n        auto g =\
    \ [&](int from, int to) -> long long { return f(from, to) + x; };\n        long\
    \ long cost = monge_shortest_path<long long>(N, g)[N];\n        return cost -\
    \ 1LL * D * x;\n    };\n    auto [tmp, res] = golden_section_search<long long,\
    \ false>(dp, -upper, upper);\n    return res;\n}"
  dependsOn:
  - src/algorithm/golden_section_search.hpp
  isVerificationFile: false
  path: src/algorithm/monge_d_edge_shortest_path.hpp
  requiredBy: []
  timestamp: '2024-05-22 00:21:24+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: src/algorithm/monge_d_edge_shortest_path.hpp
layout: document
title: $d$-edge Shortest Path on Monge Graph
---

## 概要

完全 DAG $G(V, E)\ (\|V\| = N + 1)$ について，その辺重み $c : E \to \mathbb{Z}$ が monge 性を満たす際に頂点 $0$ から各点までの最短路長を $\mathrm{O}(N \log N)$ で，辺を丁度 $D$ 本使う $0$ から $N - 1$ への最短路長を $\mathrm{O}(N \log N \log \max_{e \in E} \|c(e)\|)$ で求める．

LARSCH algorithm を用いることでそれぞれ $\log N$ を落とすことが可能．

## Links
- [Monge グラフ上の $d$-辺最短路長を計算するアルゴリズム \| Kyopro Encyclopedia of Algorithms](https://noshi91.github.io/algorithm-encyclopedia/d-edge-shortest-path-monge)
- [Aliens DP で辺の本数が区間で指定される場合 - noshi91のメモ](https://noshi91.hatenablog.com/entry/2022/01/13/001217)
- [Incredibly beautiful DP optimization from $N^3$ to $N \log^2 N$ - Codeforces](https://codeforces.com/blog/entry/49691)
- [Monge の手引書 (tatyam)](https://speakerdeck.com/tatyam_prime/monge-noshou-yin-shu)
- https://twitter.com/noshi91/status/1625587844000649217

## 問題例
- [AtCoder Beginner Contest 218 H - Red and Blue Lamps](https://atcoder.jp/contests/abc218/tasks/abc218_h)
- [The 1st Universal Cup. Stage 3: Poland I. Investors](https://qoj.ac/contest/1103/problem/5507?v=1)
- [東北大学プログラミングコンテスト 2022 K - Lebesgue Integral](https://atcoder.jp/contests/tupc2022/tasks/tupc2022_k)
- [AtCoder Beginner Contest 305 Ex - Shojin](https://atcoder.jp/contests/abc305/tasks/abc305_h)