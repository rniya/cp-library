---
title: Monge グラフ上の $d$-辺最短路長
documentation_of: ./monge_d_edge_shortest_path.hpp
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