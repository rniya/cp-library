---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/colopl2018_final_c.cpp
    title: test/atcoder/colopl2018_final_c.cpp
  - icon: ':warning:'
    path: test/atcoder/dp_z.cpp
    title: test/atcoder/dp_z.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/952.test.cpp
    title: test/yukicoder/952.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/ConvexHullTrick.md
    document_title: Convex Hull Trick
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/ConvexHullTrick.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Convex Hull Trick\n * @docs docs/datastructure/ConvexHullTrick.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T,bool isMin=true>\n\
    struct ConvexHullTrick{\n    struct Line{\n        T a,b;\n        Line(T a,T\
    \ b):a(a),b(b){}\n    };\n    deque<Line> Lines;\n    bool empty() const {return\
    \ Lines.empty();}\n    inline int sgn(T a){return a==0?0:(a<0?-1:1);}\n    inline\
    \ bool check(const Line &a,const Line &b,const Line &c){\n        if (b.b==a.b||c.b==b.b)\
    \ return sgn(b.a-a.a)*sgn(c.b-b.b)>=sgn(c.a-b.a)*sgn(b.b-a.b);\n        return\
    \ (long double)(b.a-a.a)*sgn(c.b-b.b)/(long double)abs(b.b-a.b)>=(long double)(c.a-b.a)*sgn(b.b-a.b)/(long\
    \ double)abs(c.b-b.b);\n    }\n    void add(T a,T b){\n        if (!isMin) a*=-1,b*=-1;\n\
    \        Line l(a,b);\n        if (empty()){\n            Lines.emplace_back(l);\n\
    \            return;\n        }\n        if (Lines.front().a<=a){\n          \
    \  if (Lines.front().a==a){\n                if (Lines.front().b<=b) return;\n\
    \                Lines.pop_front();\n            }\n            while(Lines.size()>=2&&check(l,Lines.front(),Lines[1]))\
    \ Lines.pop_front();\n            Lines.emplace_front(l);\n        } else {\n\
    \            if (Lines.back().a==a){\n                if (Lines.back().b<=b) return;\n\
    \                Lines.pop_back();\n            }\n            while(Lines.size()>=2&&check(Lines[Lines.size()-2],Lines.back(),l))\
    \ Lines.pop_back();\n            Lines.emplace_back(l);\n        }\n    }\n  \
    \  inline T f(const Line &l,const T &x){\n        return l.a*x+l.b;\n    }\n \
    \   T query(T x){\n        int lb=-1,ub=Lines.size()-1;\n        while(ub-lb>1){\n\
    \            int mid=(ub+lb)>>1;\n            (f(Lines[mid],x)>=f(Lines[mid+1],x)?lb:ub)=mid;\n\
    \        }\n        return (isMin?f(Lines[ub],x):-f(Lines[ub],x));\n    }\n  \
    \  T query_monotone_inc(T x){\n        while(Lines.size()>=2&&f(Lines.front(),x)>=f(Lines[1],x))\
    \ Lines.pop_front();\n        return (isMin?f(Lines.front(),x):-f(Lines.front(),x));\n\
    \    }\n    T query_monotone_dec(T x){\n        while(Lines.size()>=2&&f(Lines.back(),x)>=f(Lines[Lines.size()-2],x))\
    \ Lines.pop_back();\n        return (isMin?f(Lines.back(),x):-f(Lines.back(),x));\n\
    \    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/ConvexHullTrick.hpp
  requiredBy:
  - test/atcoder/colopl2018_final_c.cpp
  - test/atcoder/dp_z.cpp
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/952.test.cpp
documentation_of: datastructure/ConvexHullTrick.hpp
layout: document
redirect_from:
- /library/datastructure/ConvexHullTrick.hpp
- /library/datastructure/ConvexHullTrick.hpp.html
title: Convex Hull Trick
---
## 概要

## 計算量