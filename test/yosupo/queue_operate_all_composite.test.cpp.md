---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: datastructure/SlidingWindowAggregation.hpp
    title: Sliding Window Aggregation (SWAG)
  - icon: ':heavy_check_mark:'
    path: modulo/modint.hpp
    title: modint
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: cpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    '*NOT_SPECIAL_COMMENTS*': ''
    PROBLEM: https://judge.yosupo.jp/problem/queue_operate_all_composite
    links:
    - https://judge.yosupo.jp/problem/queue_operate_all_composite
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ modulo/modint.hpp: line 6: #pragma once found in a non-first line\n"
  code: "#define PROBLEM \"https://judge.yosupo.jp/problem/queue_operate_all_composite\"\
    \n\n#include \"../../base.hpp\"\n#include \"../../modulo/modint.hpp\"\n#include\
    \ \"../../datastructure/SlidingWindowAggregation.hpp\"\n\nusing mint=modint<998244353>;\n\
    \nint main(){\n    cin.tie(0);\n    ios::sync_with_stdio(false);\n    struct node{\n\
    \        mint a,b;\n        node(mint a,mint b):a(a),b(b){}\n    };\n    auto\
    \ f=[](node a,node b){return node(a.a*b.a,a.b*b.a+b.b);};\n    SlidingWindowAggregation<node>\
    \ SWAG(f,node(1,0));\n\n    int Q; cin >> Q;\n    for (;Q--;){\n        int t;\
    \ cin >> t;\n        if (t==0){\n            int a,b; cin >> a >> b;\n       \
    \     SWAG.push(node(a,b));\n        } else if (t==1){\n            SWAG.pop();\n\
    \        } else {\n            int x; cin >> x;\n            node ans=SWAG.fold();\n\
    \            cout << ans.a*x+ans.b << '\\n';\n        }\n    }\n}"
  dependsOn:
  - base.hpp
  - modulo/modint.hpp
  - datastructure/SlidingWindowAggregation.hpp
  isVerificationFile: true
  path: test/yosupo/queue_operate_all_composite.test.cpp
  requiredBy: []
  timestamp: '2020-10-04 23:28:24+09:00'
  verificationStatus: TEST_ACCEPTED
  verifiedWith: []
documentation_of: test/yosupo/queue_operate_all_composite.test.cpp
layout: document
redirect_from:
- /verify/test/yosupo/queue_operate_all_composite.test.cpp
- /verify/test/yosupo/queue_operate_all_composite.test.cpp.html
title: test/yosupo/queue_operate_all_composite.test.cpp
---
