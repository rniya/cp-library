---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
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
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/flow/ProjectSelectionProblem.md
    document_title: Project Selection Problem
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ flow/ProjectSelectionProblem.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Project Selection Problem\n * @docs docs/flow/ProjectSelectionProblem.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n#include \"../flow/Dinic.hpp\"\
    \n\ntemplate<typename T>\nstruct ProjectSelectionProblem{\n    int s,t;\n    T\
    \ sum=0;\n    const T inf=numeric_limits<T>::max()/2;\n    Dinic<T,true> D;\n\
    \    ProjectSelectionProblem(int n):s(n),t(n+1),D(n+2){}\n    void x_false_loss(int\
    \ x,T z){\n        D.add_edge(x,t,z);\n    }\n    void x_false_profit(int x,T\
    \ z){\n        sum+=z;\n        x_true_loss(x,z);\n    }\n    void x_true_loss(int\
    \ x,T z){\n        D.add_edge(s,x,z);\n    }\n    void x_true_profit(int x,T z){\n\
    \        sum+=z;\n        x_false_loss(x,z);\n    }\n    void x_false_y_true_loss(int\
    \ x,int y,T z){\n        D.add_edge(x,y,z);\n    }\n    void x_true_y_false_loss(int\
    \ x,int y,T z){\n        D.add_edge(y,x,z);\n    }\n    void x_true_y_true_profit(int\
    \ x,int y,T z){\n        sum+=z;\n        int w=D.add_vertex();\n        x_false_loss(w,z);\n\
    \        x_true_y_false_loss(w,x,inf);\n        x_true_y_false_loss(w,y,inf);\n\
    \    }\n    void x_false_y_false_profit(int x,int y,T z){\n        sum+=z;\n \
    \       int w=D.add_vertex();\n        x_true_loss(w,z);\n        x_false_y_true_loss(w,x,inf);\n\
    \        x_false_y_true_loss(w,y,inf);\n    }\n    T build(){\n        return\
    \ D.max_flow(s,t)-sum;\n    }\n};"
  dependsOn:
  - base.hpp
  - flow/Dinic.hpp
  isVerificationFile: false
  path: flow/ProjectSelectionProblem.hpp
  requiredBy:
  - test/codeforces/1404_E.cpp
  - test/atcoder/arc085_c.cpp
  timestamp: '2021-01-19 00:11:31+09:00'
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
- `x_false_loss(x,z)`：$x$が$0$のときに$z$失う
- `x_false_profit(x,z)`：$x$が$0$のときに$z$得る
- `x_true_loss(x,z)`：$x$が$1$のときに$z$失う
- `x_true_profit(x,z)`：$x$が$1$のときに$z$得る
- `x_false_y_true_loss(x,y,z)`：$x$が$0$かつ$y$が$1$のときに$z$失う
- `x_true_y_false_loss(x,y,z)`：$x$が$1$かつ$y$が$0$のときに$z$失う
- `x_true_y_true_profit(x,y,z)`：$x$が$1$かつ$y$が$1$のときに$z$得る
- `x_false_y_false_profit(x,y,z)`：$x$が$0$かつ$y$が$0$のときに$z$得る

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