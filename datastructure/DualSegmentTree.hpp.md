---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':x:'
    path: test/aoj/DSL_2_D.DualSegmentTree.test.cpp
    title: test/aoj/DSL_2_D.DualSegmentTree.test.cpp
  - icon: ':x:'
    path: test/aoj/DSL_2_E.DualSegmentTree.test.cpp
    title: test/aoj/DSL_2_E.DualSegmentTree.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':x:'
  attributes:
    _deprecated_at_docs: docs/datastructure/DualSegmentTree.hpp
    document_title: Dual Segment Tree
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/DualSegmentTree.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "/**\n * @brief Dual Segment Tree\n * @docs docs/datastructure/DualSegmentTree.hpp\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename OperatorMonoid>\n\
    struct DualSegmentTree{\n    typedef function<OperatorMonoid(OperatorMonoid,OperatorMonoid)>\
    \ H;\n    int n,hi;\n    H h;\n    OperatorMonoid id1;\n    vector<OperatorMonoid>\
    \ laz;\n    DualSegmentTree(int n_,H h,OperatorMonoid id1):h(h),id1(id1){init(n_);}\n\
    \    void init(int n_){\n        n=1,hi=0;\n        while(n<n_) n<<=1,++hi;\n\
    \        laz.assign(n<<1,id1);\n    }\n    inline void propagate(int k){\n   \
    \     if (laz[k]==id1) return;\n        laz[k<<1|0]=h(laz[k<<1|0],laz[k]);\n \
    \       laz[k<<1|1]=h(laz[k<<1|1],laz[k]);\n        laz[k]=id1;\n    }\n    inline\
    \ void thrust(int k){\n        for (int i=hi;i;--i) propagate(k>>i);\n    }\n\
    \    void update(int a,int b,OperatorMonoid x){\n        if (a>=b) return;\n \
    \       thrust(a+=n); thrust(b+=n-1);\n        for (int l=a,r=b+1;l<r;l>>=1,r>>=1){\n\
    \            if (l&1) laz[l]=h(laz[l],x),++l;\n            if (r&1) --r,laz[r]=h(laz[r],x);\n\
    \        }\n    }\n    void set_val(int k,OperatorMonoid x){\n        thrust(k+=n);\n\
    \        laz[k]=x;\n    }\n    OperatorMonoid operator[](int k){\n        thrust(k+=n);\n\
    \        return laz[k];\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/DualSegmentTree.hpp
  requiredBy: []
  timestamp: '2021-01-19 00:11:31+09:00'
  verificationStatus: LIBRARY_ALL_WA
  verifiedWith:
  - test/aoj/DSL_2_E.DualSegmentTree.test.cpp
  - test/aoj/DSL_2_D.DualSegmentTree.test.cpp
documentation_of: datastructure/DualSegmentTree.hpp
layout: document
redirect_from:
- /library/datastructure/DualSegmentTree.hpp
- /library/datastructure/DualSegmentTree.hpp.html
title: Dual Segment Tree
---
