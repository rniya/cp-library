---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/codeforces/1179_C.cpp
    title: test/codeforces/1179_C.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/2667.test.cpp
    title: test/aoj/2667.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/2871.test.cpp
    title: test/aoj/2871.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.test.cpp
    title: test/aoj/DSL_2_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.test.cpp
    title: test/aoj/DSL_2_E.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.test.cpp
    title: test/aoj/DSL_2_F.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.test.cpp
    title: test/aoj/DSL_2_G.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.test.cpp
    title: test/aoj/DSL_2_H.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.test.cpp
    title: test/aoj/DSL_2_I.test.cpp
  - icon: ':x:'
    path: test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
    title: test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
  - icon: ':x:'
    path: test/yosupo/range_affine_range_sum.test.cpp
    title: test/yosupo/range_affine_range_sum.test.cpp
  - icon: ':x:'
    path: test/yukicoder/1270.test.cpp
    title: test/yukicoder/1270.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':question:'
  attributes:
    _deprecated_at_docs: docs/datastructure/LazySegmentTree.md
    document_title: Lazy Segment Tree
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/LazySegmentTree.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Lazy Segment Tree\n * @docs docs/datastructure/LazySegmentTree.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename Monoid,typename\
    \ OperatorMonoid>\nstruct LazySegmentTree{\n    typedef function<Monoid(Monoid,Monoid)>\
    \ F;\n    typedef function<Monoid(Monoid,OperatorMonoid)> G;\n    typedef function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>\
    \ H;\n    int n,hi;\n    F f;\n    G g;\n    H h;\n    Monoid id0;\n    OperatorMonoid\
    \ id1;\n    vector<Monoid> dat;\n    vector<OperatorMonoid> laz;\n    LazySegmentTree(int\
    \ n_,F f,G g,H h,Monoid id0,OperatorMonoid id1):\n                    f(f),g(g),h(h),id0(id0),id1(id1){init(n_);}\n\
    \    void init(int n_){\n        n=1,hi=0;\n        while(n<n_) n<<=1,++hi;\n\
    \        dat.assign(n<<1,id0);\n        laz.assign(n<<1,id1);\n    }\n    void\
    \ build(const vector<Monoid> &v){\n        for (int i=0;i<v.size();++i) dat[i+n]=v[i];\n\
    \        for (int i=n-1;i;--i) dat[i]=f(dat[i<<1|0],dat[i<<1|1]);\n    }\n   \
    \ inline Monoid reflect(int k){\n        return laz[k]==id1?dat[k]:g(dat[k],laz[k]);\n\
    \    }\n    inline void propagate(int k){\n        if (laz[k]==id1) return;\n\
    \        laz[k<<1|0]=h(laz[k<<1|0],laz[k]);\n        laz[k<<1|1]=h(laz[k<<1|1],laz[k]);\n\
    \        dat[k]=reflect(k);\n        laz[k]=id1;\n    }\n    inline void thrust(int\
    \ k){\n        for (int i=hi;i;--i) propagate(k>>i);\n    }\n    inline void recalc(int\
    \ k){\n        while(k>>=1) dat[k]=f(reflect(k<<1|0),reflect(k<<1|1));\n    }\n\
    \    void update(int a,int b,OperatorMonoid x){\n        if (a>=b) return;\n \
    \       thrust(a+=n); thrust(b+=n-1);\n        for (int l=a,r=b+1;l<r;l>>=1,r>>=1){\n\
    \            if (l&1) laz[l]=h(laz[l],x),++l;\n            if (r&1) --r,laz[r]=h(laz[r],x);\n\
    \        }\n        recalc(a); recalc(b);\n    }\n    void set_val(int k,Monoid\
    \ x){\n        thrust(k+=n);\n        dat[k]=x,laz[k]=id1;\n        recalc(k);\n\
    \    }\n    Monoid query(int a,int b){\n        if (a>=b) return id0;\n      \
    \  thrust(a+=n); thrust(b+=n-1);\n        Monoid vl=id0,vr=id0;\n        for (int\
    \ l=a,r=b+1;l<r;l>>=1,r>>=1){\n            if (l&1) vl=f(vl,reflect(l++));\n \
    \           if (r&1) vr=f(reflect(--r),vr);\n        }\n        return f(vl,vr);\n\
    \    }\n    template<typename C>\n    int find_subtree(int k,const C &check,Monoid\
    \ &M,bool type){\n        while(k<n){\n            propagate(k);\n           \
    \ Monoid nxt=type?f(reflect(k<<1|type),M):f(M,reflect(k<<1|type));\n         \
    \   if (check(nxt)) k=k<<1|type;\n            else M=nxt,k=k<<1|(type^1);\n  \
    \      }\n        return k-n;\n    }\n    // min i s.t. f(seg[a],seg[a+1],...,seg[i])\
    \ satisfy \"check\"\n    template<typename C>\n    int find_first(int a,const\
    \ C &check){\n        Monoid L=id0;\n        if (a<=0){\n            if (check(f(L,reflect(1))))\
    \ return find_subtree(1,check,L,false);\n            return -1;\n        }\n \
    \       thrust(a+n);\n        int b=n;\n        for (int l=a+n,r=b+n;l<r;l>>=1,r>>=1){\n\
    \            if (l&1){\n                Monoid nxt=f(L,reflect(l));\n        \
    \        if (check(nxt)) return find_subtree(l,check,L,false);\n             \
    \   L=nxt; ++l;\n            }\n        }\n        return -1;\n    }\n    // max\
    \ i s.t. f(seg[i],...,seg[b-2],seg[b-1]) satisfy \"check\"\n    template<typename\
    \ C>\n    int find_last(int b,const C &check){\n        Monoid R=id0;\n      \
    \  if (b>=n){\n            if (check(f(reflect(1),R))) return find_subtree(1,check,R,true);\n\
    \            return -1;\n        }\n        thrust(b+n-1);\n        int a=n;\n\
    \        for (int l=a,r=b+n;l<r;l>>=1,r>>=1){\n            if (r&1){\n       \
    \         Monoid nxt=f(reflect(--r),R);\n                if (check(nxt)) return\
    \ find_subtree(r,check,R,true);\n                R=nxt;\n            }\n     \
    \   }\n        return -1;\n    }\n    Monoid operator[](int i){return query(i,i+1);}\n\
    };"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/LazySegmentTree.hpp
  requiredBy:
  - test/codeforces/1179_C.cpp
  timestamp: '2021-01-19 13:16:33+09:00'
  verificationStatus: LIBRARY_SOME_WA
  verifiedWith:
  - test/yosupo/range_affine_range_sum.test.cpp
  - test/aoj/DSL_2_G.test.cpp
  - test/aoj/DSL_2_H.test.cpp
  - test/aoj/2871.test.cpp
  - test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp
  - test/aoj/DSL_2_D.test.cpp
  - test/aoj/DSL_2_E.test.cpp
  - test/aoj/2667.test.cpp
  - test/aoj/DSL_2_I.test.cpp
  - test/aoj/DSL_2_F.test.cpp
  - test/yukicoder/1270.test.cpp
documentation_of: datastructure/LazySegmentTree.hpp
layout: document
redirect_from:
- /library/datastructure/LazySegmentTree.hpp
- /library/datastructure/LazySegmentTree.hpp.html
title: Lazy Segment Tree
---
## 概要

## 計算量