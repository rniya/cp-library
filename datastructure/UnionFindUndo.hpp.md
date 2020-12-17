---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/codeforces/1444_C.cpp
    title: test/codeforces/1444_C.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
    title: test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/UnionFindUndo.md
    document_title: "UnionFind (Undo\u53EF\u80FD)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/UnionFindUndo.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief UnionFind (Undo\u53EF\u80FD)\n * @docs docs/datastructure/UnionFindUndo.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\nstruct UnionFindUndo{\n  \
    \  vector<int> dat;\n    stack<pair<int,int>> hist;\n    UnionFindUndo(int n):dat(n,-1){}\n\
    \    int root(int x){\n        return (dat[x]<0?x:root(dat[x]));\n    }\n    bool\
    \ merge(int x,int y){\n        x=root(x); y=root(y);\n        hist.emplace(x,dat[x]);\n\
    \        hist.emplace(y,dat[y]);\n        if (x==y) return false;\n        if\
    \ (dat[x]>dat[y]) swap(x,y);\n        dat[x]+=dat[y]; dat[y]=x;\n        return\
    \ true;\n    }\n    void undo(){\n        dat[hist.top().first]=hist.top().second;\
    \ hist.pop();\n        dat[hist.top().first]=hist.top().second; hist.pop();\n\
    \    }\n    void snapshot(){\n        while(!hist.empty()) hist.pop();\n    }\n\
    \    void rollback(){\n        while(!hist.empty()) undo();\n    }\n    bool same(int\
    \ x,int y){return root(x)==root(y);}\n    int size(int x){return -dat[root(x)];}\n\
    };"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/UnionFindUndo.hpp
  requiredBy:
  - test/codeforces/1444_C.cpp
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/persistent_unionfind.UnionFindUndo.test.cpp
documentation_of: datastructure/UnionFindUndo.hpp
layout: document
redirect_from:
- /library/datastructure/UnionFindUndo.hpp
- /library/datastructure/UnionFindUndo.hpp.html
title: "UnionFind (Undo\u53EF\u80FD)"
---
## 概要
経路圧縮せずにマージテクにより集合を管理する過程を保持することでrollbackを可能にしたUnionFind.
- `root(x)`：$x$の集合の根を返す.
- `merge(x,y)`：$x$と$y$の属する集合をマージする.
- `undo()`：直前のマージを巻き戻す.
- `snapshot()`：それまでのマージ過程を保存する.
- `rollback()`：直前に`snapshot()`された時間まで状態をrollbackする.
- `same(x,y)`：現時点で$x$と$y$が同じ集合にいるかどうか判定する.
- `size(x)`：$x$の属する集合の大きさを返す.

## 計算量
クエリあたり$O(\log n)$

## 参照
[Mo's algorithm とその上位互換の話 - あなたは嘘つきですかと聞かれたら「YES」と答えるブログ](https://snuke.hatenablog.com/entry/2016/07/01/000000)