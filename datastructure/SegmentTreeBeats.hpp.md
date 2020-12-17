---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_A.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_A.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_B.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_B.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_D.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_D.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_E.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_E.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_F.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_F.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_G.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_G.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/aoj/DSL_2_I.SegmentTreeBeats.test.cpp
    title: test/aoj/DSL_2_I.SegmentTreeBeats.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
    title: test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/LazySegmentTree.md
    document_title: Segment Tree Beats
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/SegmentTreeBeats.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Segment Tree Beats\n * @docs docs/datastructure/LazySegmentTree.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T>\nclass\
    \ SegmentTreeBeats{\n    int n;\n    static const T idm=numeric_limits<T>::min();\n\
    \    static const T idM=numeric_limits<T>::max(),idl=idM;\n    struct Node{\n\
    \        T Max,Max_second,Min,Min_second,sum,laz_add,laz_val;\n        int Max_count,Min_count,len;\n\
    \        Node():Max(idm),Max_second(idm),Min(idM),Min_second(idM)\n          \
    \  ,laz_add(0),laz_val(idl),len(1){}\n    };\n    vector<Node> Nodes;\n    inline\
    \ void calc(int k){\n        Node &p=Nodes[k];\n        Node l=Nodes[(k<<1)+1],r=Nodes[(k<<1)+2];\n\
    \        p.sum=l.sum+r.sum;\n        if (l.Max<r.Max){\n            p.Max=r.Max;\n\
    \            p.Max_count=r.Max_count;\n            p.Max_second=max(l.Max,r.Max_second);\n\
    \        } else if (r.Max<l.Max){\n            p.Max=l.Max;\n            p.Max_count=l.Max_count;\n\
    \            p.Max_second=max(l.Max_second,r.Max);\n        } else {\n       \
    \     p.Max=l.Max;\n            p.Max_count=l.Max_count+r.Max_count;\n       \
    \     p.Max_second=max(l.Max_second,r.Max_second);\n        }\n        if (l.Min<r.Min){\n\
    \            p.Min=l.Min;\n            p.Min_count=l.Min_count;\n            p.Min_second=min(l.Min_second,r.Min);\n\
    \        } else if (r.Min<l.Min){\n            p.Min=r.Min;\n            p.Min_count=r.Min_count;\n\
    \            p.Min_second=min(l.Min,r.Min_second);\n        } else {\n       \
    \     p.Min=l.Min;\n            p.Min_count=l.Min_count+r.Min_count;\n       \
    \     p.Min_second=min(l.Min_second,r.Min_second);\n        }\n    }\n    inline\
    \ void update_node_min(int k,T x){\n        Node &node=Nodes[k];\n        node.sum+=(x-node.Max)*node.Max_count;\n\
    \        if (node.Max==node.Min) node.Max=node.Min=x;\n        else if (node.Max==node.Min_second)\
    \ node.Max=node.Min_second=x;\n        else node.Max=x;\n        if (node.laz_val!=idl&&node.laz_val<x)\
    \ node.laz_val=x;\n    }\n    inline void update_node_max(int k,T x){\n      \
    \  Node &node=Nodes[k];\n        node.sum+=(x-node.Min)*node.Min_count;\n    \
    \    if (node.Min==node.Max) node.Min=node.Max=x;\n        else if (node.Min==node.Max_second)\
    \ node.Min=node.Max_second=x;\n        else node.Min=x;\n        if (node.laz_val!=idl&&x<node.laz_val)\
    \ node.laz_val=x;\n    }\n    inline void update_node_add(int k,T x){\n      \
    \  Node &node=Nodes[k];\n        node.Max+=x;\n        if (node.Max_second!=idm)\
    \ node.Max_second+=x;\n        node.Min+=x;\n        if (node.Min_second!=idM)\
    \ node.Min_second+=x;\n        node.sum+=x*node.len;\n        (node.laz_val!=idl?node.laz_val:node.laz_add)+=x;\n\
    \    }\n    inline void update_node_val(int k,T x){\n        Node &node=Nodes[k];\n\
    \        node.Max=x; node.Max_second=idm;\n        node.Min=x; node.Min_second=idM;\n\
    \        node.Max_count=node.Min_count=node.len;\n        node.sum=x*node.len;\n\
    \        node.laz_val=x; node.laz_add=0;\n    }\n    inline void propagate(int\
    \ k){\n        if (k>=n-1) return;\n        Node &node=Nodes[k];\n        if (node.laz_val!=idl){\n\
    \            update_node_val((k<<1)+1,node.laz_val);\n            update_node_val((k<<1)+2,node.laz_val);\n\
    \            node.laz_val=idl; return;\n        }\n        if (node.laz_add!=0){\n\
    \            update_node_add((k<<1)+1,node.laz_add);\n            update_node_add((k<<1)+2,node.laz_add);\n\
    \            node.laz_add=0;\n        }\n        if (node.Max<Nodes[(k<<1)+1].Max)\
    \ update_node_min((k<<1)+1,node.Max);\n        if (node.Max<Nodes[(k<<1)+2].Max)\
    \ update_node_min((k<<1)+2,node.Max);\n        if (Nodes[(k<<1)+1].Min<node.Min)\
    \ update_node_max((k<<1)+1,node.Min);\n        if (Nodes[(k<<1)+2].Min<node.Min)\
    \ update_node_max((k<<1)+2,node.Min);\n    }\n    inline void update_min(int a,int\
    \ b,T x,int k,int l,int r){\n        if (b<=l||r<=a||Nodes[k].Max<=x) return;\n\
    \        if (a<=l&&r<=b&&Nodes[k].Max_second<x){\n            update_node_min(k,x);\
    \ return;\n        }\n        propagate(k);\n        update_min(a,b,x,(k<<1)+1,l,(l+r)>>1);\n\
    \        update_min(a,b,x,(k<<1)+2,(l+r)>>1,r);\n        calc(k);\n    }\n   \
    \ inline void update_max(int a,int b,T x,int k,int l,int r){\n        if (b<=l||r<=a||x<=Nodes[k].Min)\
    \ return;\n        if (a<=l&&r<=b&&x<Nodes[k].Min_second){\n            update_node_max(k,x);\
    \ return;\n        }\n        propagate(k);\n        update_max(a,b,x,(k<<1)+1,l,(l+r)>>1);\n\
    \        update_max(a,b,x,(k<<1)+2,(l+r)>>1,r);\n        calc(k);\n    }\n   \
    \ inline void update_add(int a,int b,T x,int k,int l,int r){\n        if (b<=l||r<=a)\
    \ return;\n        if (a<=l&&r<=b){\n            update_node_add(k,x); return;\n\
    \        }\n        propagate(k);\n        update_add(a,b,x,(k<<1)+1,l,(l+r)>>1);\n\
    \        update_add(a,b,x,(k<<1)+2,(l+r)>>1,r);\n        calc(k);\n    }\n   \
    \ inline void update_val(int a,int b,T x,int k,int l,int r){\n        if (b<=l||r<=a)\
    \ return;\n        if (a<=l&&r<=b){\n            update_node_val(k,x); return;\n\
    \        }\n        propagate(k);\n        update_val(a,b,x,(k<<1)+1,l,(l+r)>>1);\n\
    \        update_val(a,b,x,(k<<1)+2,(l+r)>>1,r);\n        calc(k);\n    }\n   \
    \ inline T query_min(int a,int b,int k,int l,int r){\n        if (b<=l||r<=a)\
    \ return idM;\n        if (a<=l&&r<=b) return Nodes[k].Min;\n        propagate(k);\n\
    \        T vl=query_min(a,b,(k<<1)+1,l,(l+r)>>1);\n        T vr=query_min(a,b,(k<<1)+2,(l+r)>>1,r);\n\
    \        return min(vl,vr);\n    }\n    inline T query_max(int a,int b,int k,int\
    \ l,int r){\n        if (b<=l||r<=a) return idm;\n        if (a<=l&&r<=b) return\
    \ Nodes[k].Max;\n        propagate(k);\n        T vl=query_max(a,b,(k<<1)+1,l,(l+r)>>1);\n\
    \        T vr=query_max(a,b,(k<<1)+2,(l+r)>>1,r);\n        return max(vl,vr);\n\
    \    }\n    inline T query_sum(int a,int b,int k,int l,int r){\n        if (b<=l||r<=a)\
    \ return 0;\n        if (a<=l&&r<=b) return Nodes[k].sum;\n        propagate(k);\n\
    \        T vl=query_sum(a,b,(k<<1)+1,l,(l+r)>>1);\n        T vr=query_sum(a,b,(k<<1)+2,(l+r)>>1,r);\n\
    \        return vl+vr;\n    }\npublic:\n    SegmentTreeBeats(int n_){init(n_);}\n\
    \    void init(int n_){\n        n=1;\n        while(n<n_) n<<=1;\n        Nodes.resize(n<<1);\n\
    \    }\n    void build(const vector<T> &v){\n        for (int i=0;i<v.size();++i){\n\
    \            Nodes[i+n-1].Max=Nodes[i+n-1].Min=Nodes[i+n-1].sum=v[i];\n      \
    \      Nodes[i+n-1].Max_count=Nodes[i+n-1].Min_count=Nodes[i+n-1].len=1;\n   \
    \     }\n        for (int i=n-2;i>=0;--i){\n            calc(i);\n           \
    \ Nodes[i].len=Nodes[(i<<1)+1].len+Nodes[(i<<1)+2].len;\n        }\n    }\n  \
    \  void update_min(int a,int b,T x){update_min(a,b,x,0,0,n);}\n    void update_max(int\
    \ a,int b,T x){update_max(a,b,x,0,0,n);}\n    void update_add(int a,int b,T x){update_add(a,b,x,0,0,n);}\n\
    \    void update_val(int a,int b,T x){update_val(a,b,x,0,0,n);}\n    T query_min(int\
    \ a,int b){return query_min(a,b,0,0,n);}\n    T query_max(int a,int b){return\
    \ query_max(a,b,0,0,n);}\n    T query_sum(int a,int b){return query_sum(a,b,0,0,n);}\n\
    \    T operator[](int i){return query_sum(i,i+1);}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/SegmentTreeBeats.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/range_chmin_chmax_add_range_sum.test.cpp
  - test/aoj/DSL_2_A.SegmentTreeBeats.test.cpp
  - test/aoj/DSL_2_H.SegmentTreeBeats.test.cpp
  - test/aoj/DSL_2_B.SegmentTreeBeats.test.cpp
  - test/aoj/DSL_2_D.SegmentTreeBeats.test.cpp
  - test/aoj/DSL_2_I.SegmentTreeBeats.test.cpp
  - test/aoj/DSL_2_G.SegmentTreeBeats.test.cpp
  - test/aoj/DSL_2_F.SegmentTreeBeats.test.cpp
  - test/aoj/DSL_2_E.SegmentTreeBeats.test.cpp
documentation_of: datastructure/SegmentTreeBeats.hpp
layout: document
redirect_from:
- /library/datastructure/SegmentTreeBeats.hpp
- /library/datastructure/SegmentTreeBeats.hpp.html
title: Segment Tree Beats
---
## 概要

## 計算量