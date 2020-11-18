---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':question:'
    path: datastructure/SegmentTree.hpp
    title: Segment Tree
  - icon: ':question:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':x:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/point_set_range_composite
    links:
    - https://judge.yosupo.jp/problem/point_set_range_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ modulo/modint.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/point_set_range_composite\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n#include\
    \ \"../../datastructure/SegmentTree.hpp\"\n\nusing mint=modint<998244353>;\n\n\
    int main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    int N,Q; cin\
    \ >> N >> Q;\n    vector<mint> a(N),b(N);\n    for (int i=0;i<N;++i) cin >> a[i]\
    \ >> b[i];\n\n    struct node{\n        mint a,b;\n        node (mint a,mint b):a(a),b(b){}\n\
    \    };\n    auto f=[](node a,node b){return node(a.a*b.a,a.b*b.a+b.b);};\n  \
    \  SegmentTree<node> seg(N,f,node(1,0));\n    vector<node> v;\n    for (int i=0;i<N;++i)\
    \ v.emplace_back(a[i],b[i]);\n    seg.build(v);\n\n    for (;Q--;){\n        int\
    \ t; cin >> t;\n        if (!t){\n            int p; mint c,d; cin >> p >> c >>\
    \ d;\n            seg.update(p,node(c,d));\n        } else {\n            int\
    \ l,r; mint x; cin >> l >> r >> x;\n            node ans=seg.query(l,r);\n   \
    \         cout << x*ans.a+ans.b << '\\n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - datastructure/SegmentTree.hpp
  isVerificationFile: true
  path: test/yosupo/point_set_range_composite.test.cpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: TEST_WRONG_ANSWER
  verifiedWith: []
documentation_of: test/yosupo/point_set_range_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/point_set_range_composite.test.cpp
- /verify/test/yosupo/point_set_range_composite.test.cpp.html
title: test/yosupo/point_set_range_composite.test.cpp
---
