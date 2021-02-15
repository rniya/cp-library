---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: flow/Dinic.hpp
    title: Dinic
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/arc085_c.cpp
    title: test/atcoder/arc085_c.cpp
  - icon: ':warning:'
    path: test/codeforces/1404_E.cpp
    title: test/codeforces/1404_E.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2903.test.cpp
    title: test/aoj/2903.test.cpp
  _isVerificationFailed: false
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/ProjectSelectionProblem.md
    document_title: Project Selection Problem
    links: []
  bundledCode: "#line 2 \"base.hpp\"\n#include <bits/stdc++.h>\nusing namespace std;\n\
    typedef long long ll;\ntypedef __int128_t i128;\ntypedef unsigned int uint;\n\
    typedef unsigned long long ull;\n#define ALL(x) (x).begin(), (x).end()\n\ntemplate\
    \ <typename T> istream& operator>>(istream& is, vector<T>& v) {\n    for (T& x\
    \ : v) is >> x;\n    return is;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const vector<T>& v) {\n    for (int i = 0; i < (int)v.size(); i++) {\n \
    \       os << v[i] << (i + 1 == (int)v.size() ? \"\" : \" \");\n    }\n    return\
    \ os;\n}\ntemplate <typename T, typename U> ostream& operator<<(ostream& os, const\
    \ pair<T, U>& p) {\n    os << '(' << p.first << ',' << p.second << ')';\n    return\
    \ os;\n}\ntemplate <typename T, typename U, typename V> ostream& operator<<(ostream&\
    \ os, const tuple<T, U, V>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t)\
    \ << ',' << get<2>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U, typename V, typename W> ostream& operator<<(ostream& os, const tuple<T, U,\
    \ V, W>& t) {\n    os << '(' << get<0>(t) << ',' << get<1>(t) << ',' << get<2>(t)\
    \ << ',' << get<3>(t) << ')';\n    return os;\n}\ntemplate <typename T, typename\
    \ U> ostream& operator<<(ostream& os, const map<T, U>& m) {\n    os << '{';\n\
    \    for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T, typename U> ostream&\
    \ operator<<(ostream& os, const unordered_map<T, U>& m) {\n    os << '{';\n  \
    \  for (auto itr = m.begin(); itr != m.end();) {\n        os << '(' << itr->first\
    \ << ',' << itr->second << ')';\n        if (++itr != m.end()) os << ',';\n  \
    \  }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const set<T>& s) {\n    os << '{';\n    for (auto itr = s.begin(); itr !=\
    \ s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os << ',';\n\
    \    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream& operator<<(ostream&\
    \ os, const multiset<T>& s) {\n    os << '{';\n    for (auto itr = s.begin();\
    \ itr != s.end();) {\n        os << *itr;\n        if (++itr != s.end()) os <<\
    \ ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename T> ostream&\
    \ operator<<(ostream& os, const unordered_set<T>& s) {\n    os << '{';\n    for\
    \ (auto itr = s.begin(); itr != s.end();) {\n        os << *itr;\n        if (++itr\
    \ != s.end()) os << ',';\n    }\n    os << '}';\n    return os;\n}\ntemplate <typename\
    \ T> ostream& operator<<(ostream& os, const deque<T>& v) {\n    for (int i = 0;\
    \ i < (int)v.size(); i++) {\n        os << v[i] << (i + 1 == (int)v.size() ? \"\
    \" : \" \");\n    }\n    return os;\n}\n\nvoid debug_out() { cerr << '\\n'; }\n\
    template <class Head, class... Tail> void debug_out(Head&& head, Tail&&... tail)\
    \ {\n    cerr << head;\n    if (sizeof...(Tail) > 0) cerr << \", \";\n    debug_out(move(tail)...);\n\
    }\n#ifdef LOCAL\n#define debug(...)                                          \
    \                         \\\n    cerr << \" \";                             \
    \                                        \\\n    cerr << #__VA_ARGS__ << \" :[\"\
    \ << __LINE__ << \":\" << __FUNCTION__ << \"]\" << '\\n'; \\\n    cerr << \" \"\
    ;                                                                     \\\n   \
    \ debug_out(__VA_ARGS__)\n#else\n#define debug(...) 42\n#endif\n\ntemplate <typename\
    \ T> T gcd(T x, T y) { return y != 0 ? gcd(y, x % y) : x; }\ntemplate <typename\
    \ T> T lcm(T x, T y) { return x / gcd(x, y) * y; }\n\ntemplate <class T1, class\
    \ T2> inline bool chmin(T1& a, T2 b) {\n    if (a > b) {\n        a = b;\n   \
    \     return true;\n    }\n    return false;\n}\ntemplate <class T1, class T2>\
    \ inline bool chmax(T1& a, T2 b) {\n    if (a < b) {\n        a = b;\n       \
    \ return true;\n    }\n    return false;\n}\n#line 3 \"flow/Dinic.hpp\"\n\n/**\n\
    \ * @brief Dinic\n * @docs docs/flow/Dinic.md\n */\ntemplate <typename T, bool\
    \ directed> struct Dinic {\n    struct edge {\n        int to, rev;\n        T\
    \ cap;\n        edge(int to, T cap, int rev) : to(to), cap(cap), rev(rev) {}\n\
    \    };\n    vector<vector<edge>> G;\n    vector<pair<int, int>> pos;\n    vector<int>\
    \ level, iter;\n    Dinic(int n) : G(n), level(n), iter(n) {}\n    int add_edge(int\
    \ from, int to, T cap) {\n        pos.emplace_back(from, G[from].size());\n  \
    \      G[from].emplace_back(to, cap, G[to].size());\n        G[to].emplace_back(from,\
    \ directed ? 0 : cap, G[from].size() - 1);\n        return pos.size() - 1;\n \
    \   }\n    int add_vertex() {\n        G.emplace_back();\n        level.emplace_back();\n\
    \        iter.emplace_back();\n        return G.size() - 1;\n    }\n    tuple<int,\
    \ int, int, int> get_edge(int i) {\n        auto e = G[pos[i].first][pos[i].second];\n\
    \        auto re = G[e.to][e.rev];\n        return {pos[i].first, e.to, e.cap\
    \ + re.cap, re.cap};\n    }\n    vector<tuple<int, int, int, int>> edges() {\n\
    \        vector<tuple<int, int, int, int>> res;\n        for (int i = 0; i < (int)pos.size();\
    \ i++) {\n            res.emplace_back(get_edge(i));\n        }\n        return\
    \ res;\n    }\n    void change_edge(int i, T new_cap, T new_flow) {\n        auto&\
    \ e = G[pos[i].first][pos[i].second];\n        auto& re = G[e.to][e.rev];\n  \
    \      e.cap = new_cap - new_flow;\n        re.cap = (directed ? new_flow : new_cap\
    \ + new_flow);\n    }\n    void bfs(int s) {\n        fill(level.begin(), level.end(),\
    \ -1);\n        queue<int> que;\n        level[s] = 0;\n        que.emplace(s);\n\
    \        while (!que.empty()) {\n            int v = que.front();\n          \
    \  que.pop();\n            for (auto& e : G[v]) {\n                if (e.cap >\
    \ 0 && level[e.to] < 0) {\n                    level[e.to] = level[v] + 1;\n \
    \                   que.emplace(e.to);\n                }\n            }\n   \
    \     }\n    }\n    T dfs(int v, int t, T f) {\n        if (v == t) return f;\n\
    \        for (int& i = iter[v]; i < (int)G[v].size(); i++) {\n            auto&\
    \ e = G[v][i];\n            if (e.cap > 0 && level[v] < level[e.to]) {\n     \
    \           T d = dfs(e.to, t, min(f, e.cap));\n                if (d <= 0) continue;\n\
    \                e.cap -= d;\n                G[e.to][e.rev].cap += d;\n     \
    \           return d;\n            }\n        }\n        return 0;\n    }\n  \
    \  T max_flow(int s, int t, T lim) {\n        T flow = 0;\n        while (lim\
    \ > 0) {\n            bfs(s);\n            if (level[t] < 0) break;\n        \
    \    fill(iter.begin(), iter.end(), 0);\n            while (lim > 0) {\n     \
    \           T f = dfs(s, t, lim);\n                if (f == 0) break;\n      \
    \          flow += f;\n                lim -= f;\n            }\n        }\n \
    \       return flow;\n    }\n    T max_flow(int s, int t) { return max_flow(s,\
    \ t, numeric_limits<T>::max()); }\n    vector<bool> min_cut(int s) {\n       \
    \ vector<bool> res(G.size());\n        queue<int> que;\n        res[s] = true;\n\
    \        que.emplace(s);\n        while (!que.empty()) {\n            int v =\
    \ que.front();\n            que.pop();\n            for (auto e : G[v]) {\n  \
    \              if (e.cap > 0 && !res[e.to]) {\n                    res[e.to] =\
    \ true;\n                    que.emplace(e.to);\n                }\n         \
    \   }\n        }\n        return res;\n    }\n};\n#line 4 \"flow/ProjectSelectionProblem.hpp\"\
    \n\n/**\n * @brief Project Selection Problem\n * @docs docs/flow/ProjectSelectionProblem.md\n\
    \ */\ntemplate <typename T> struct ProjectSelectionProblem {\n    int s, t;\n\
    \    T sum = 0;\n    const T inf = numeric_limits<T>::max() / 2;\n    Dinic<T,\
    \ true> D;\n    ProjectSelectionProblem(int n) : s(n), t(n + 1), D(n + 2) {}\n\
    \    void x_false_loss(int x, T z) { D.add_edge(x, t, z); }\n    void x_false_profit(int\
    \ x, T z) {\n        sum += z;\n        x_true_loss(x, z);\n    }\n    void x_true_loss(int\
    \ x, T z) { D.add_edge(s, x, z); }\n    void x_true_profit(int x, T z) {\n   \
    \     sum += z;\n        x_false_loss(x, z);\n    }\n    void x_false_y_true_loss(int\
    \ x, int y, T z) { D.add_edge(x, y, z); }\n    void x_true_y_false_loss(int x,\
    \ int y, T z) { D.add_edge(y, x, z); }\n    void x_true_y_true_profit(int x, int\
    \ y, T z) {\n        sum += z;\n        int w = D.add_vertex();\n        x_false_loss(w,\
    \ z);\n        x_true_y_false_loss(w, x, inf);\n        x_true_y_false_loss(w,\
    \ y, inf);\n    }\n    void x_false_y_false_profit(int x, int y, T z) {\n    \
    \    sum += z;\n        int w = D.add_vertex();\n        x_true_loss(w, z);\n\
    \        x_false_y_true_loss(w, x, inf);\n        x_false_y_true_loss(w, y, inf);\n\
    \    }\n    T build() { return D.max_flow(s, t) - sum; }\n};\n"
  code: "#pragma once\n#include \"../base.hpp\"\n#include \"Dinic.hpp\"\n\n/**\n *\
    \ @brief Project Selection Problem\n * @docs docs/flow/ProjectSelectionProblem.md\n\
    \ */\ntemplate <typename T> struct ProjectSelectionProblem {\n    int s, t;\n\
    \    T sum = 0;\n    const T inf = numeric_limits<T>::max() / 2;\n    Dinic<T,\
    \ true> D;\n    ProjectSelectionProblem(int n) : s(n), t(n + 1), D(n + 2) {}\n\
    \    void x_false_loss(int x, T z) { D.add_edge(x, t, z); }\n    void x_false_profit(int\
    \ x, T z) {\n        sum += z;\n        x_true_loss(x, z);\n    }\n    void x_true_loss(int\
    \ x, T z) { D.add_edge(s, x, z); }\n    void x_true_profit(int x, T z) {\n   \
    \     sum += z;\n        x_false_loss(x, z);\n    }\n    void x_false_y_true_loss(int\
    \ x, int y, T z) { D.add_edge(x, y, z); }\n    void x_true_y_false_loss(int x,\
    \ int y, T z) { D.add_edge(y, x, z); }\n    void x_true_y_true_profit(int x, int\
    \ y, T z) {\n        sum += z;\n        int w = D.add_vertex();\n        x_false_loss(w,\
    \ z);\n        x_true_y_false_loss(w, x, inf);\n        x_true_y_false_loss(w,\
    \ y, inf);\n    }\n    void x_false_y_false_profit(int x, int y, T z) {\n    \
    \    sum += z;\n        int w = D.add_vertex();\n        x_true_loss(w, z);\n\
    \        x_false_y_true_loss(w, x, inf);\n        x_false_y_true_loss(w, y, inf);\n\
    \    }\n    T build() { return D.max_flow(s, t) - sum; }\n};"
  dependsOn:
  - base.hpp
  - flow/Dinic.hpp
  isVerificationFile: false
  path: flow/ProjectSelectionProblem.hpp
  requiredBy:
  - test/atcoder/arc085_c.cpp
  - test/codeforces/1404_E.cpp
  timestamp: '2021-01-20 20:25:59+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/2903.test.cpp
documentation_of: flow/ProjectSelectionProblem.hpp
layout: document
redirect_from:
- /library/flow/ProjectSelectionProblem.hpp
- /library/flow/ProjectSelectionProblem.hpp.html
title: Project Selection Problem
---
## 概要
Project Selection Problem, いわゆる燃やす埋める問題を解く際の補助ライブラリ.
- `x_false_loss(x, z)`：$x$が$0$のときに$z$失う
- `x_false_profit(x, z)`：$x$が$0$のときに$z$得る
- `x_true_loss(x, z)`：$x$が$1$のときに$z$失う
- `x_true_profit(x, z)`：$x$が$1$のときに$z$得る
- `x_false_y_true_loss(x, y, z)`：$x$が$0$かつ$y$が$1$のときに$z$失う
- `x_true_y_false_loss(x, y, z)`：$x$が$1$かつ$y$が$0$のときに$z$失う
- `x_true_y_true_profit(x, y, z)`：$x$が$1$かつ$y$が$1$のときに$z$得る
- `x_false_y_false_profit(x, y, z)`：$x$が$0$かつ$y$が$0$のときに$z$得る

といった条件に対応している. 一般にこれ以外の条件に対応する際には$2$部グラフなどの制約が必要になる.

## 計算量
$O(EV^2)$だが, 概ねこれより高速に動作する.

## 問題例
[ARC107 F Sum of Abs](https://atcoder.jp/contests/arc107/tasks/arc107_f)
絶対値については, 各頂点に対して$0$(削除), $+1$(連結成分内での$B_i$の合計が正), $-1$(連結成分内での$B_i$の合計が正負)として, 各連結成分内に$+1$と$-1$が割り当てられた頂点が混在することがないようにすれば問題ない. これは$3$つのうちどれかに割り当てる問題になるが, 各頂点に対して$+1$か$+1$以外, $-1$以外か$-1$という2つの選択肢の直積として表現することで解くことができる. ([参照](http://tokoharuland.hateblo.jp/entry/2017/11/13/220607))

## 参照
- [最小カットを使って「燃やす埋める問題」を解く](https://www.slideshare.net/shindannin/project-selection-problem)
- [最小カットについて - よすぽの日記](https://yosupo.hatenablog.com/entry/2015/03/31/134336)
- [Project Selection (燃やす埋める) 周りの話についてもう少し考えた - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/12/25/000003)
- [続：『燃やす埋める』と『ProjectSelectionProblem』 - とこはるのまとめ](http://tokoharuland.hateblo.jp/entry/2017/11/13/220607)