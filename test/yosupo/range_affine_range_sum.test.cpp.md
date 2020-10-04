---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/LazySegmentTree.hpp
    title: Lazy Segment Tree
  - icon: ':heavy_check_mark:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/range_affine_range_sum
    links:
    - https://judge.yosupo.jp/problem/range_affine_range_sum
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ modulo/modint.hpp: line 5: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/range_affine_range_sum\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n#include\
    \ \"../../datastructure/LazySegmentTree.hpp\"\n\nusing mint=modint<998244353>;\n\
    \nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,Q;\
    \ cin >> N >> Q;\n    vector<mint> a(N);\n    for (int i=0;i<N;++i) cin >> a[i];\n\
    \n    struct node{\n        mint sum; int a;\n        node(mint sum,int a):sum(sum),a(a){}\n\
    \    };\n    struct add{\n        mint b,c;\n        add(mint b,mint c):b(b),c(c){}\n\
    \        const bool operator==(const add &rhs){\n            return b==rhs.b&&c==rhs.c;\n\
    \        }\n    };\n    auto f=[](node a,node b){return node(a.sum+b.sum,a.a+b.a);};\n\
    \    auto g=[](node a,add x){return node(a.sum*x.b+x.c*a.a,a.a);};\n    auto h=[](add\
    \ a,add b){return add(a.b*b.b,a.c*b.b+b.c);};\n    LazySegmentTree<node,add> seg(N,f,g,h,node(0,0),add(1,0));\n\
    \    vector<node> v;\n    for (int i=0;i<N;++i) v.emplace_back(a[i],1);\n    seg.build(v);\n\
    \n    for (;Q--;){\n        int t,l,r; cin >> t >> l >> r;\n        if (!t){\n\
    \            mint b,c; cin >> b >> c;\n            seg.update(l,r,add(b,c));\n\
    \        } else cout << seg.query(l,r).sum << '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - datastructure/LazySegmentTree.hpp
  isVerificationFile: true
  path: test/yosupo/range_affine_range_sum.test.cpp
  requiredBy: []
  timestamp: '2020-09-22 13:03:14+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/range_affine_range_sum.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/range_affine_range_sum.test.cpp
- /verify/test/yosupo/range_affine_range_sum.test.cpp.html
title: test/yosupo/range_affine_range_sum.test.cpp
---
