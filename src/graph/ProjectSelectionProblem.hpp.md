---
data:
  _extendedDependsOn: []
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2903.test.cpp
    title: test/aoj/2903.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n          \
    \         ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n\
    \  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 187, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \                ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^\n \
    \ File \"/opt/hostedtoolcache/Python/3.12.0/x64/lib/python3.12/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 260, in _resolve\n    raise BundleErrorAt(path, -1, \"no such header\"\
    )\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: atcoder/internal_queue:\
    \ line -1: no such header\n"
  code: "#pragma once\n#include <algorithm>\n#include <cassert>\n#include <limits>\n\
    #include <queue>\n#include <vector>\n\n#include \"atcoder/internal_queue\"\n\n\
    namespace ProjectSelectionProblem_Impl {\n\ntemplate <class Cap> struct mf_graph\
    \ {\npublic:\n    mf_graph() : _n(0) {}\n    explicit mf_graph(int n) : _n(n),\
    \ g(n) {}\n\n    int add_edge(int from, int to, Cap cap) {\n        assert(0 <=\
    \ from && from < _n);\n        assert(0 <= to && to < _n);\n        assert(0 <=\
    \ cap);\n        int m = int(pos.size());\n        pos.push_back({from, int(g[from].size())});\n\
    \        int from_id = int(g[from].size());\n        int to_id = int(g[to].size());\n\
    \        if (from == to) to_id++;\n        g[from].push_back(_edge{to, to_id,\
    \ cap});\n        g[to].push_back(_edge{from, from_id, 0});\n        return m;\n\
    \    }\n    int add_vertex() {\n        g.resize(_n + 1);\n        return _n++;\n\
    \    }\n\n    struct edge {\n        int from, to;\n        Cap cap, flow;\n \
    \   };\n\n    edge get_edge(int i) {\n        int m = int(pos.size());\n     \
    \   assert(0 <= i && i < m);\n        auto _e = g[pos[i].first][pos[i].second];\n\
    \        auto _re = g[_e.to][_e.rev];\n        return edge{pos[i].first, _e.to,\
    \ _e.cap + _re.cap, _re.cap};\n    }\n    std::vector<edge> edges() {\n      \
    \  int m = int(pos.size());\n        std::vector<edge> result;\n        for (int\
    \ i = 0; i < m; i++) {\n            result.push_back(get_edge(i));\n        }\n\
    \        return result;\n    }\n    void change_edge(int i, Cap new_cap, Cap new_flow)\
    \ {\n        int m = int(pos.size());\n        assert(0 <= i && i < m);\n    \
    \    assert(0 <= new_flow && new_flow <= new_cap);\n        auto& _e = g[pos[i].first][pos[i].second];\n\
    \        auto& _re = g[_e.to][_e.rev];\n        _e.cap = new_cap - new_flow;\n\
    \        _re.cap = new_flow;\n    }\n\n    Cap flow(int s, int t) { return flow(s,\
    \ t, std::numeric_limits<Cap>::max()); }\n    Cap flow(int s, int t, Cap flow_limit)\
    \ {\n        assert(0 <= s && s < _n);\n        assert(0 <= t && t < _n);\n  \
    \      assert(s != t);\n\n        std::vector<int> level(_n), iter(_n);\n    \
    \    atcoder::internal::simple_queue<int> que;\n\n        auto bfs = [&]() {\n\
    \            std::fill(level.begin(), level.end(), -1);\n            level[s]\
    \ = 0;\n            que.clear();\n            que.push(s);\n            while\
    \ (!que.empty()) {\n                int v = que.front();\n                que.pop();\n\
    \                for (auto e : g[v]) {\n                    if (e.cap == 0 ||\
    \ level[e.to] >= 0) continue;\n                    level[e.to] = level[v] + 1;\n\
    \                    if (e.to == t) return;\n                    que.push(e.to);\n\
    \                }\n            }\n        };\n        auto dfs = [&](auto self,\
    \ int v, Cap up) {\n            if (v == s) return up;\n            Cap res =\
    \ 0;\n            int level_v = level[v];\n            for (int& i = iter[v];\
    \ i < int(g[v].size()); i++) {\n                _edge& e = g[v][i];\n        \
    \        if (level_v <= level[e.to] || g[e.to][e.rev].cap == 0) continue;\n  \
    \              Cap d = self(self, e.to, std::min(up - res, g[e.to][e.rev].cap));\n\
    \                if (d <= 0) continue;\n                g[v][i].cap += d;\n  \
    \              g[e.to][e.rev].cap -= d;\n                res += d;\n         \
    \       if (res == up) return res;\n            }\n            level[v] = _n;\n\
    \            return res;\n        };\n\n        Cap flow = 0;\n        while (flow\
    \ < flow_limit) {\n            bfs();\n            if (level[t] == -1) break;\n\
    \            std::fill(iter.begin(), iter.end(), 0);\n            Cap f = dfs(dfs,\
    \ t, flow_limit - flow);\n            if (!f) break;\n            flow += f;\n\
    \        }\n        return flow;\n    }\n\n    std::vector<bool> min_cut(int s)\
    \ {\n        std::vector<bool> visited(_n);\n        atcoder::internal::simple_queue<int>\
    \ que;\n        que.push(s);\n        while (!que.empty()) {\n            int\
    \ p = que.front();\n            que.pop();\n            visited[p] = true;\n \
    \           for (auto e : g[p]) {\n                if (e.cap && !visited[e.to])\
    \ {\n                    visited[e.to] = true;\n                    que.push(e.to);\n\
    \                }\n            }\n        }\n        return visited;\n    }\n\
    \nprivate:\n    int _n;\n    struct _edge {\n        int to, rev;\n        Cap\
    \ cap;\n    };\n    std::vector<std::pair<int, int>> pos;\n    std::vector<std::vector<_edge>>\
    \ g;\n};\n\ntemplate <typename T> struct ProjectSelectionProblem {\n    ProjectSelectionProblem(int\
    \ n) : n(n + 2), s(n), t(n + 1), sum(T(0)), graph(n + 2) {}\n\n    void x_false_loss(int\
    \ x, T z) {\n        assert(0 <= x and x < n);\n        graph.add_edge(x, t, z);\n\
    \    }\n\n    void x_false_profit(int x, T z) {\n        assert(0 <= x and x <\
    \ n);\n        sum += z;\n        x_true_loss(x, z);\n    }\n\n    void x_true_loss(int\
    \ x, T z) {\n        assert(0 <= x and x < n);\n        graph.add_edge(s, x, z);\n\
    \    }\n\n    void x_true_profit(int x, T z) {\n        assert(0 <= x and x <\
    \ n);\n        sum += z;\n        x_false_loss(x, z);\n    }\n\n    void x_false_y_true_loss(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        graph.add_edge(x, y, z);\n    }\n\n    void x_true_y_false_loss(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        graph.add_edge(y, x, z);\n    }\n\n    void x_false_y_false_profit(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        sum += z;\n        int w = graph.add_vertex();\n        n++;\n\
    \        x_true_loss(w, z);\n        x_false_y_true_loss(w, x, inf);\n       \
    \ x_false_y_true_loss(w, y, inf);\n    }\n\n    void x_true_y_true_profit(int\
    \ x, int y, T z) {\n        assert(0 <= x and x < n);\n        assert(0 <= y and\
    \ y < n);\n        sum += z;\n        int w = graph.add_vertex();\n        n++;\n\
    \        x_false_loss(w, z);\n        x_true_y_false_loss(w, x, inf);\n      \
    \  x_true_y_false_loss(w, y, inf);\n    }\n\n    T min_loss() { return graph.flow(s,\
    \ t) - sum; }\n\n    T max_profit() { return -min_loss(); }\n\nprivate:\n    int\
    \ n, s, t;\n    T sum;\n    const T inf = std::numeric_limits<T>::max() / 2;\n\
    \    mf_graph<T> graph;\n};\n\n}  // namespace ProjectSelectionProblem_Impl\n\n\
    using ProjectSelectionProblem_Impl::ProjectSelectionProblem;\n"
  dependsOn: []
  isVerificationFile: false
  path: src/graph/ProjectSelectionProblem.hpp
  requiredBy: []
  timestamp: '2023-04-23 18:55:45+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2903.test.cpp
documentation_of: src/graph/ProjectSelectionProblem.hpp
layout: document
title: Project Selection Problem (based on ac-library)
---

## 概要
Project Selection Problem，いわゆる燃やす埋める問題を解く際の補助ライブラリ．

| メンバ関数                        | 効果                                           | 時間計算量 |
| --------------------------------- | ---------------------------------------------- | ---------- |
| `ProjectSelectionProblem(n)`      | 頂点数 $n$ のグラフとして初期化する．          | $O(n)$     |
| `x_false_loss(x, z)`              | $x$ が $0$ のときに $z$ 失う．                 | $O(1)$     |
| `x_false_profit(x, z)`            | $x$ が $0$ のときに $z$ 得る．                 | $O(1)$     |
| `x_true_loss(x, z)`               | $x$ が $1$ のときに $z$ 失う．                 | $O(1)$     |
| `x_true_profit(x, z)`             | $x$ が $1$ のときに $z$ 得る．                 | $O(1)$     |
| `x_false_y_true_loss(x, y, z)`    | $x$ が $0$ かつ $y$ が $1$ のときに $z$ 失う． | $O(1)$     |
| `x_true_y_false_loss(x, y, z)`    | $x$ が $1$ かつ $y$ が $0$ のときに $z$ 失う． | $O(1)$     |
| `x_false_y_false_profit(x, y, z)` | $x$ が $0$ かつ $y$ が $0$ のときに $z$ 得る． | $O(1)$     |
| `x_true_y_true_profit(x, y, z)`   | $x$ が $1$ かつ $y$ が $1$ のときに $z$ 得る． | $O(1)$     |
| `min_loss()`                      | 損失の最小値を返す．                           | $O(n^2m)$  |
| `max_profit()`                    | 利得の最大値を返す．                           | $O(n^2m)$  |

一般にこれ以外の条件に対応する際には 2 部グラフなどの制約が必要になる．

## 問題例
- [Codeforces Round #668 (Div. 1) E. Bricks](https://codeforces.com/contest/1404/problem/E)
- [AtCoder Regular Contest 085 E - MUL](https://atcoder.jp/contests/arc085/tasks/arc085_c)
- [AtCoder Regular Contest 107 F - Sum of Abs](https://atcoder.jp/contests/arc107/tasks/arc107_f)
- [AtCoder Regular Contest 129 E - Yet Another Minimization](https://atcoder.jp/contests/arc129/tasks/arc129_e)
  - 2 択だけでなく選択肢が $k$ 個あるような場合の問題．[このブログ](https://maspypy.com/atcoder-%e5%8f%82%e5%8a%a0%e6%84%9f%e6%83%b3-2020-10-31arc107)の F の解説にある辺の張り方が参考になる．ライブラリにしていいかもしれない．
- [yukicoder No.1984 [Cherry 4th Tune*] Dilemma](https://yukicoder.me/problems/no/1984)
  - 復元の際には `atcoder::mf_graph::min_cut(s)` を利用する．
- [2023牛客暑期多校训练营2 B Link with Railway Company](https://ac.nowcoder.com/acm/contest/57356/F)

## 参照
- [最小カットを使って「燃やす埋める問題」を解く](https://www.slideshare.net/shindannin/project-selection-problem)
- [最小カットについて - よすぽの日記](https://yosupo.hatenablog.com/entry/2015/03/31/134336)
- [Project Selection (燃やす埋める) 周りの話についてもう少し考えた - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/12/25/000003)
- [続：『燃やす埋める』と『ProjectSelectionProblem』 - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/11/13/220607)
