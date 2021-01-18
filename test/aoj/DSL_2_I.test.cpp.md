---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: datastructure/LazySegmentTree.hpp
    title: Lazy Segment Tree
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
    links:
    - https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 401, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/LazySegmentTree.hpp: line 6: #pragma once found in a non-first\
    \ line\n"
  code: "#define PROBLEM \"https://onlinejudge.u-aizu.ac.jp/courses/library/3/DSL/2/DSL_2_I\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../datastructure/LazySegmentTree.hpp\"\
    \n\nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    const\
    \ int inf=1<<30;\n    int n,q; cin >> n >> q;\n\n    struct node{\n        long\
    \ long a; int b;\n        node(long long a,int b):a(a),b(b){}\n    };\n    auto\
    \ f=[](node a,node b){return node(a.a+b.a,a.b+b.b);};\n    auto g=[](node a,long\
    \ long x){return node(x!=inf?x*a.b:a.a,a.b);};\n    auto h=[](long long a,long\
    \ long b){return b;};\n    LazySegmentTree<node,long long> seg(n,f,g,h,node(0,0),inf);\n\
    \    vector<node> v(n,node(0,1));\n    seg.build(v);\n\n    for (;q--;){\n   \
    \     int c,s,t,x; cin >> c >> s >> t;\n        if (!c){\n            cin >> x;\n\
    \            seg.update(s,t+1,x);\n        } else cout << seg.query(s,t+1).a <<\
    \ '\\n';\n    }\n}"
  dependsOn:
  - base.hpp
  - datastructure/LazySegmentTree.hpp
  isVerificationFile: true
  path: test/aoj/DSL_2_I.test.cpp
  requiredBy: []
  timestamp: '2021-01-19 00:11:31+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/aoj/DSL_2_I.test.cpp
layout: document
redirect_from:
- /verify/test/aoj/DSL_2_I.test.cpp
- /verify/test/aoj/DSL_2_I.test.cpp.html
title: test/aoj/DSL_2_I.test.cpp
---
