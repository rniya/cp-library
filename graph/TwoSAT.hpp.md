---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: graph/StronglyConnectedComponents.hpp
    title: "Strongly Connected Components\uFF08\u5F37\u9023\u7D50\u6210\u5206\u5206\
      \u89E3\uFF09"
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/two_sat.test.cpp
    title: test/yosupo/two_sat.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    links: []
  bundledCode: "#line 2 \"graph/TwoSAT.hpp\"\n#include <cassert>\n#include <vector>\n\
    #line 2 \"graph/StronglyConnectedComponents.hpp\"\n#include <algorithm>\n#line\
    \ 5 \"graph/StronglyConnectedComponents.hpp\"\n\nstruct StronglyConnectedComponents\
    \ {\n    std::vector<std::vector<int>> G;\n    std::vector<int> comp;  // component\
    \ id vertex v belongs to\n\n    StronglyConnectedComponents(int n) : G(n), comp(n,\
    \ -1), n(n), time(0), group_num(0), ord(n, -1), low(n) {}\n\n    void add_edge(int\
    \ u, int v) {\n        assert(0 <= u && u < n);\n        assert(0 <= v && v <\
    \ n);\n        G[u].emplace_back(v);\n    }\n\n    int add_vertex() {\n      \
    \  G.emplace_back();\n        comp.emplace_back(-1);\n        ord.emplace_back(-1);\n\
    \        low.emplace_back();\n        return n++;\n    }\n\n    std::vector<std::vector<int>>\
    \ build() {\n        for (int i = 0; i < n; i++) {\n            if (ord[i] < 0)\
    \ {\n                dfs(i);\n            }\n        }\n        for (int& x :\
    \ comp) x = group_num - 1 - x;\n        std::vector<std::vector<int>> groups(group_num);\n\
    \        for (int i = 0; i < n; i++) groups[comp[i]].emplace_back(i);\n      \
    \  return groups;\n    }\n\n    std::vector<std::vector<int>> make_graph() {\n\
    \        std::vector<std::vector<int>> dag(group_num);\n        for (int v = 0;\
    \ v < n; v++) {\n            for (int& u : G[v]) {\n                if (comp[v]\
    \ != comp[u]) {\n                    dag[comp[v]].emplace_back(comp[u]);\n   \
    \             }\n            }\n        }\n        for (auto& to : dag) {\n  \
    \          std::sort(to.begin(), to.end());\n            to.erase(unique(to.begin(),\
    \ to.end()), to.end());\n        }\n        return dag;\n    }\n\n    int operator[](int\
    \ v) const { return comp[v]; }\n\nprivate:\n    int n, time, group_num;\n    std::vector<int>\
    \ ord, low, visited;\n\n    void dfs(int v) {\n        ord[v] = low[v] = time++;\n\
    \        visited.emplace_back(v);\n        for (int& u : G[v]) {\n           \
    \ if (ord[u] == -1) {\n                dfs(u);\n                low[v] = std::min(low[v],\
    \ low[u]);\n            } else if (comp[u] < 0) {\n                low[v] = std::min(low[v],\
    \ ord[u]);\n            }\n        }\n        if (ord[v] == low[v]) {\n      \
    \      while (true) {\n                int u = visited.back();\n             \
    \   visited.pop_back();\n                comp[u] = group_num;\n              \
    \  if (u == v) break;\n            }\n            group_num++;\n        }\n  \
    \  }\n};\n#line 5 \"graph/TwoSAT.hpp\"\n\nstruct TwoSAT {\n    TwoSAT(int n) :\
    \ n(n), called_satisfiable(false), scc(2 * n) {}\n\n    int add_vertex() {\n \
    \       scc.add_vertex();\n        scc.add_vertex();\n        return n++;\n  \
    \  }\n\n    // (i = f or j = g)\n    void add_clause(int i, bool f, int j, bool\
    \ g) {\n        assert(0 <= i and i < n);\n        assert(0 <= j and j < n);\n\
    \        scc.add_edge(i << 1 | (f ? 0 : 1), j << 1 | (g ? 1 : 0));\n        scc.add_edge(j\
    \ << 1 | (g ? 0 : 1), i << 1 | (f ? 1 : 0));\n    }\n\n    // (i = f) -> (j =\
    \ g) <=> (i = !f) or (j = g)\n    void add_if(int i, bool f, int j, bool g) {\n\
    \        assert(0 <= i and i < n);\n        assert(0 <= j and j < n);\n      \
    \  add_clause(i, f ^ 1, j, g);\n    }\n\n    // i\n    void set_true(int i) {\n\
    \        assert(0 <= i and i < n);\n        add_clause(i, true, i, true);\n  \
    \  }\n\n    // !i\n    void set_false(int i) {\n        assert(0 <= i and i <\
    \ n);\n        add_clause(i, false, i, false);\n    }\n\n    // <= 1 of literals\
    \ in v are true\n    void at_most_one(const std::vector<std::pair<int, int>>&\
    \ v) {\n        if (v.size() <= 1) return;\n        for (size_t i = 0; i < v.size();\
    \ i++) {\n            int nxt = add_vertex(), cur = nxt - 1, x = v[i].first, f\
    \ = v[i].second;\n            add_if(x, f, nxt, 1);\n            if (i > 0) {\n\
    \                add_if(cur, 1, nxt, 1);\n                add_clause(cur, 0, x,\
    \ f ^ 1);\n            }\n        }\n    }\n\n    bool satisfiable() {\n     \
    \   called_satisfiable = true;\n        ans.resize(n);\n        scc.build();\n\
    \        for (int i = 0; i < n; i++) {\n            if (scc[i << 1] == scc[i <<\
    \ 1 | 1]) return false;\n            ans[i] = (scc[i << 1] < scc[i << 1 | 1]);\n\
    \        }\n        return true;\n    }\n\n    std::vector<bool> answer() const\
    \ {\n        assert(called_satisfiable);\n        return ans;\n    }\n\nprivate:\n\
    \    int n;\n    bool called_satisfiable;\n    std::vector<bool> ans;\n    StronglyConnectedComponents\
    \ scc;\n};\n"
  code: "#pragma once\n#include <cassert>\n#include <vector>\n#include \"StronglyConnectedComponents.hpp\"\
    \n\nstruct TwoSAT {\n    TwoSAT(int n) : n(n), called_satisfiable(false), scc(2\
    \ * n) {}\n\n    int add_vertex() {\n        scc.add_vertex();\n        scc.add_vertex();\n\
    \        return n++;\n    }\n\n    // (i = f or j = g)\n    void add_clause(int\
    \ i, bool f, int j, bool g) {\n        assert(0 <= i and i < n);\n        assert(0\
    \ <= j and j < n);\n        scc.add_edge(i << 1 | (f ? 0 : 1), j << 1 | (g ? 1\
    \ : 0));\n        scc.add_edge(j << 1 | (g ? 0 : 1), i << 1 | (f ? 1 : 0));\n\
    \    }\n\n    // (i = f) -> (j = g) <=> (i = !f) or (j = g)\n    void add_if(int\
    \ i, bool f, int j, bool g) {\n        assert(0 <= i and i < n);\n        assert(0\
    \ <= j and j < n);\n        add_clause(i, f ^ 1, j, g);\n    }\n\n    // i\n \
    \   void set_true(int i) {\n        assert(0 <= i and i < n);\n        add_clause(i,\
    \ true, i, true);\n    }\n\n    // !i\n    void set_false(int i) {\n        assert(0\
    \ <= i and i < n);\n        add_clause(i, false, i, false);\n    }\n\n    // <=\
    \ 1 of literals in v are true\n    void at_most_one(const std::vector<std::pair<int,\
    \ int>>& v) {\n        if (v.size() <= 1) return;\n        for (size_t i = 0;\
    \ i < v.size(); i++) {\n            int nxt = add_vertex(), cur = nxt - 1, x =\
    \ v[i].first, f = v[i].second;\n            add_if(x, f, nxt, 1);\n          \
    \  if (i > 0) {\n                add_if(cur, 1, nxt, 1);\n                add_clause(cur,\
    \ 0, x, f ^ 1);\n            }\n        }\n    }\n\n    bool satisfiable() {\n\
    \        called_satisfiable = true;\n        ans.resize(n);\n        scc.build();\n\
    \        for (int i = 0; i < n; i++) {\n            if (scc[i << 1] == scc[i <<\
    \ 1 | 1]) return false;\n            ans[i] = (scc[i << 1] < scc[i << 1 | 1]);\n\
    \        }\n        return true;\n    }\n\n    std::vector<bool> answer() const\
    \ {\n        assert(called_satisfiable);\n        return ans;\n    }\n\nprivate:\n\
    \    int n;\n    bool called_satisfiable;\n    std::vector<bool> ans;\n    StronglyConnectedComponents\
    \ scc;\n};\n"
  dependsOn:
  - graph/StronglyConnectedComponents.hpp
  isVerificationFile: false
  path: graph/TwoSAT.hpp
  requiredBy: []
  timestamp: '2022-11-13 11:22:27+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/two_sat.test.cpp
documentation_of: graph/TwoSAT.hpp
layout: document
title: 2-SAT
---

## 概要
$(a \vee b \vee \cdots) \wedge (c \vee d \vee \cdots) \wedge \cdots$ のような形をした論理式，すなわち $x_{i,j}$ をリテラルとして $\bigwedge_i \bigvee_j x_{i,j}$ のように表される論理式を CNF 形式（乗法標準形，連言標準形とも）という．
内側の各 $\bigvee_j x_{i,j}$ をクロージャ (clause) という．

論理式が与えられた際に，各リテラルに適切に真偽値を割り振ることで全体の真偽値を真にできるかを判定する問題を充足可能性問題 (SAT) という．
特に，論理式を CNF 形式で表現した際に各クロージャ内のリテラルの数が高々 2 つであるような論理式に対する充足可能性問題を 2-SAT と呼ぶ．
SAT は一般には NP 完全だが，2-SAT については多項式時間で解くことが可能であり，全体を真にすることが可能であれば実際にそのようなリテラルの真偽値の割当を構成するアルゴリズムである．

各クロージャは $(a \vee b) \iff (\neg a \Rightarrow b \vee \neg b \Rightarrow a)$ と換言でき，論理式全体は $(a \Rightarrow b)$ という形の論理式が $\wedge$ で繋がれた形となる．
ここで，$n$ 個のリテラル $x_i$ が存在する際に，$\Rightarrow$ に対応した有向辺を取り $x_i，\neg x_i$ に対応する頂点をそれぞれ用意した $2 n$ 頂点の有向グラフを考える．
もし $x_i$ と $\neg x_i$ が同じ強連結成分にあるようなリテラル $x_i$ が存在するならば，$x \Rightarrow \neg x \wedge \neg x \Rightarrow x$ となり明らかに矛盾し論理式全体を真にすることは不可能である．
逆にそのようなリテラルが存在しない場合には $x_i$ を含む強連結成分のトポロジカル順序が $\neg x_i$ を含む強連結成分のトポロジカル順序よりも後ろであるかを $x_i$ の真偽値とすれば論理式全体を充足させることが可能である．
以上よりグラフを強連結成分分解することでリテラルの数を $n$，クロージャの数を $m$ として $O(n + m)$ で解くことができる．

| メンバ関数               | 効果                                                               | 時間計算量 |
| ------------------------ | ------------------------------------------------------------------ | ---------- |
| `TwoSAT(n)`              | リテラル数 $n$ として初期化する．                                  | $O(n)$     |
| `add_clause(i，f，j，g)` | $(x_i = f) \vee (x_j = g)$ のようなクロージャを足す．              | $O(1)$     |
| `add_if(i，f，j，g)`     | $(x_i = f) \Rightarrow (x_j = g)$ のようなクロージャを足す．       | $O(1)$     |
| `set_true(i)`            | $x_i$ を真とする．                                                 | $O(1)$     |
| `set_false(i)`           | $x_i$ を偽とする．すなわち，$\neg x_i$ を真とする．                | $O(1)$     |
| `at_most_one(v)`         | $v$ 内の $L$ 個のリテラルのうち高々 1 つが真とする（問題例参照）． | $O(L)$     |
| `satisfiable()`          | 充足可能かどうか判定する．                                         | $O(n + m)$ |
| `answer()`               | 充足可能として全体の真偽値を真にする各リテラルの真偽値を返す．     | $O(1)$     |

### 構成方法の正当性の証明
## 問題例
- [AtCoder Beginner Contest 210 F - Coprime Solitaire](https://atcoder.jp/contests/abc210/tasks/abc210_f)
  - `at_most_one(v)` の使用例．各カードについて表にある数は $A_i$ もしくは $B_i$ で，各素数についてそれを素因数に含むような数は高々 1 つしか表にない．
  すると $x_1，x_2，\cdots，x_n$ のうち高々 1 つが真であるというような論理式が複数ある論理式を考えることになる．
  これはリテラルの累積 OR を考えることで $O(n)$ 個の 2 変数のクロージャで言い換えることができる．
  $$ y_i = \begin{cases}
    x_i                     & (i = 1) \\
    y_{i - 1} \vee x_i      & (i > 1)
  \end{cases} $$
  をイメージして新たに $n$ 個のリテラル $y_i$ を考えると，$x_i$ のうち真であるリテラルが高々 1 つ $\iff$ $(x_i \Rightarrow y_i) \wedge (y_{i - 1} \Rightarrow y_i) \wedge (x_i \Rightarrow \neg y_{i - 1}) \wedge (y_{i - 1} \Rightarrow \neg x_i)$ と換言できる．

- [CodeChef March Cook-Off 2022 - Oh I Dont Care](https://www.codechef.com/COOK139A/problems/OH1DCARE)

- [JOI 2020/2021 二次予選 過去問 E - スパイ 2 (Spy 2)](https://atcoder.jp/contests/joi2021yo2/tasks/joi2021_yo2_e)
  - A がスパイでないときは A の証言の内容は気にしなくてもよく，A がスパイの場合は B はスパイでないかもしくは C はスパイである．
  よって各人はスパイであるか否かを真偽値とするリテラルを考えると各クロージャは $(\neg a \vee \neg b \vee c)$ のようになる．
  このように各クロージャ内の否定されているリテラルの数が高々 1 つであるような論理式の充足可能性問題を Horn-SAT といい，これも次のようにして 2-SAT 同様に多項式時間で解くことができる．
  真のリテラルを確定させていくことを考える．
  このとき，各クロージャの否定は $(a \wedge b \wedge \neg c)$ だから $(a \wedge b) \Rightarrow c$ であり，次々に確定させていくことが可能である．
  もう確定させることが可能なリテラルが存在しなくなったならば残りのリテラルは全て偽としまっても問題ない（これで矛盾するのはクロージャの末尾のリテラルに偽が割り当てられて他のリテラルが全て真のときだが，これは他のリテラルが全て真で確定した際に真を割り当てられなければならないので起こり得ない）．
  よって，リテラルに真を割り当てていき，そのリテラルが存在する各クロージャについて新たに真で確定するリテラルがないかチェックしていけばよい．
  適切に実装すればリテラル数とクロージャ内のリテラル数の合計に対して線形時間で解くことができる．

- [AtCoder Beginner Contest 277 Ex - Constrained Sums](https://atcoder.jp/contests/abc277/tasks/abc277_h)