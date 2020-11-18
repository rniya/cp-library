---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/atcoder/ukuku09_d.cpp
    title: test/atcoder/ukuku09_d.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.test.cpp
    title: test/aoj/DSL_2_A.test.cpp
  - icon: ':x:'
    path: test/yosupo/point_add_range_sum.test.cpp
    title: test/yosupo/point_add_range_sum.test.cpp
  - icon: ':x:'
    path: test/yosupo/point_set_range_composite.test.cpp
    title: test/yosupo/point_set_range_composite.test.cpp
  - icon: ':x:'
    path: test/yosupo/vertex_add_path_sum.test.cpp
    title: test/yosupo/vertex_add_path_sum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/datastructure/SegmentTree.md
    document_title: Segment Tree
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/SegmentTree.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Segment Tree\n * @docs docs/datastructure/SegmentTree.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename Monoid>\n\
    struct SegmentTree{\n    typedef function<Monoid(Monoid,Monoid)> F;\n    int n;\n\
    \    F f;\n    Monoid id;\n    vector<Monoid> dat;\n    SegmentTree(int n_,F f,Monoid\
    \ id):f(f),id(id){init(n_);}\n    void init(int n_){\n        n=1;\n        while(n<n_)\
    \ n<<=1;\n        dat.assign(n<<1,id);\n    }\n    void build(const vector<Monoid>\
    \ &v){\n        for (int i=0;i<v.size();++i) dat[i+n]=v[i];\n        for (int\
    \ i=n-1;i;--i) dat[i]=f(dat[i<<1|0],dat[i<<1|1]);\n    }\n    void update(int\
    \ k,Monoid x){\n        dat[k+=n]=x;\n        while(k>>=1) dat[k]=f(dat[k<<1|0],dat[k<<1|1]);\n\
    \    }\n    Monoid query(int a,int b){\n        if (a>=b) return id;\n       \
    \ Monoid vl=id,vr=id;\n        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){\n      \
    \      if (l&1) vl=f(vl,dat[l++]);\n            if (r&1) vr=f(dat[--r],vr);\n\
    \        }\n        return f(vl,vr);\n    }\n    template<typename C>\n    int\
    \ find_subtree(int k,const C &check,Monoid &M,bool type){\n        while(k<n){\n\
    \            Monoid nxt=type?f(dat[k<<1|type],M):f(M,dat[k<<1|type]);\n      \
    \      if (check(nxt)) k=k<<1|type;\n            else M=nxt,k=k<<1|(type^1);\n\
    \        }\n        return k-n;\n    }\n    // min i s.t. f(seg[a],seg[a+1],...,seg[i])\
    \ satisfy \"check\"\n    template<typename C>\n    int find_first(int a,const\
    \ C &check){\n        Monoid L=id;\n        if (a<=0){\n            if (check(f(L,dat[1])))\
    \ return find_subtree(1,check,L,false);\n            return -1;\n        }\n \
    \       int b=n;\n        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){\n           \
    \ if (l&1){\n                Monoid nxt=f(L,dat[l]);\n                if (check(nxt))\
    \ return find_subtree(l,check,L,false);\n                L=nxt; ++l;\n       \
    \     }\n        }\n        return -1;\n    }\n    // max i s.t. f(seg[i],...,seg[b-2],seg[b-1])\
    \ satisfy \"check\"\n    template<typename C>\n    int find_last(int b,const C\
    \ &check){\n        Monoid R=id;\n        if (b>=n){\n            if (check(f(dat[1],R)))\
    \ return find_subtree(1,check,R,true);\n            return -1;\n        }\n  \
    \      int a=n;\n        for (int l=a,r=b+n;l<r;l>>=1,r>>=1){\n            if\
    \ (r&1){\n                Monoid nxt=f(dat[--r],R);\n                if (check(nxt))\
    \ return find_subtree(r,check,R,true);\n                R=nxt;\n            }\n\
    \        }\n        return -1;\n    }\n    Monoid operator[](int i){return dat[i+n];}\n\
    };"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/SegmentTree.hpp
  requiredBy:
  - test/atcoder/ukuku09_d.cpp
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/aoj/DSL_2_A.test.cpp
  - test/yosupo/point_set_range_composite.test.cpp
  - test/yosupo/point_add_range_sum.test.cpp
  - test/yosupo/vertex_add_path_sum.test.cpp
documentation_of: datastructure/SegmentTree.hpp
layout: document
redirect_from:
- /library/datastructure/SegmentTree.hpp
- /library/datastructure/SegmentTree.hpp.html
title: Segment Tree
---
## 概要

## 計算量