---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/1181.test.cpp
    title: test/aoj/1181.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/util/Dice.md
    document_title: "\u30B5\u30A4\u30B3\u30ED"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ util/Dice.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief \u30B5\u30A4\u30B3\u30ED\n * @docs docs/util/Dice.md\n */\n\
    \n#pragma once\n\n#include \"../base.hpp\"\n\nstruct Dice{\n    int surface[6];\n\
    \    int top()   {return surface[0];}\n    int south() {return surface[1];}\n\
    \    int east()  {return surface[2];}\n    int west()  {return surface[3];}\n\
    \    int north() {return surface[4];}\n    int bottom(){return surface[5];}\n\
    \    int operator[](int i) const {return surface[i];}\n    const int dice[6][6]=\
    \   {{0,3,5,2,4,0}\n                            ,{4,0,1,6,0,3}\n             \
    \               ,{2,6,0,0,1,5}\n                            ,{5,1,0,0,6,2}\n \
    \                           ,{3,0,6,1,0,4}\n                            ,{0,4,2,5,3,0}};\n\
    \    const int code[6][4]=   {{0,3,5,2}\n                            ,{0,2,5,3}\n\
    \                            ,{0,1,5,4}\n                            ,{0,4,5,1}\n\
    \                            ,{1,2,4,3}\n                            ,{1,3,4,2}};\n\
    \    const string direction=\"EWNSRL\";\n    Dice(int TOP,int FRONT){\n      \
    \  surface[0]=TOP; surface[1]=FRONT; surface[2]=dice[TOP-1][FRONT-1];\n      \
    \  surface[3]=7-surface[2]; surface[4]=7-surface[1]; surface[5]=7-surface[0];\n\
    \    }\n    void roll(char c){\n        for (int i=0;i<6;++i){\n            if\
    \ (direction[i]!=c) continue;\n            int tmp=surface[code[i][0]];\n    \
    \        surface[code[i][0]]=surface[code[i][1]];\n            surface[code[i][1]]=surface[code[i][2]];\n\
    \            surface[code[i][2]]=surface[code[i][3]];\n            surface[code[i][3]]=tmp;\n\
    \        }\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: util/Dice.hpp
  requiredBy: []
  timestamp: '2021-01-19 00:11:31+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/1181.test.cpp
documentation_of: util/Dice.hpp
layout: document
redirect_from:
- /library/util/Dice.hpp
- /library/util/Dice.hpp.html
title: "\u30B5\u30A4\u30B3\u30ED"
---
## 概要
サイコロを転がす.

- `Dice(TOP,FRONT)`：上面と前面の数字を引数に全ての面の数字を復元するコンストラクタ.
- `roll(c)`：サイコロを転がしたり回転させたりする. 引数`c`としてはそのオプションとなる以下の文字をとる.
    - `E`：サイコロを東の方向に転がす. $(x,y)\rightarrow (x+1,y)$
    - `W`：サイコロを西の方向に転がす. $(x,y)\rightarrow (x-1,y)$
    - `N`：サイコロを北の方向に転がす. $(x,y)\rightarrow (x,y+1)$
    - `S`：サイコロを南の方向に転がす. $(x,y)\rightarrow (x,y-1)$
    - `R`：サイコロをその場で時計回りに回転させる.
    - `L`：サイコロをその場で反時計回りに回転させる.

## 計算量
$O(1)$