---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':warning:'
    path: test/aoj/DSL_3_D.SlidingWindowAggregation.cpp
    title: test/aoj/DSL_3_D.SlidingWindowAggregation.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/queue_operate_all_composite.test.cpp
    title: test/yosupo/queue_operate_all_composite.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/SlidingWindowAggregation.md
    document_title: Sliding Window Aggregation (SWAG)
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/SlidingWindowAggregation.hpp: line 6: #pragma once found in a\
    \ non-first line\n"
  code: "/**\n * @brief Sliding Window Aggregation (SWAG)\n * @docs docs/datastructure/SlidingWindowAggregation.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename Monoid>\n\
    struct SlidingWindowAggregation{\n    typedef function<Monoid(Monoid,Monoid)>\
    \ F;\n    stack<pair<Monoid,Monoid>> front_stack,back_stack;\n    F f;\n    Monoid\
    \ id;\n    SlidingWindowAggregation(F f,Monoid id):\n        f(f),id(id),front_stack(),back_stack(){\n\
    \        front_stack.emplace(id,id);\n        back_stack.emplace(id,id);\n   \
    \ }\n    void push(const Monoid &x){\n        back_stack.emplace(x,f(back_stack.top().second,x));\n\
    \    }\n    void pop(){\n        if (front_stack.size()==1){\n            while(1<back_stack.size()){\n\
    \                Monoid t=back_stack.top().first;\n                Monoid calc=f(t,front_stack.top().second);\n\
    \                front_stack.emplace(t,calc);\n                back_stack.pop();\n\
    \            }\n        }\n        front_stack.pop();\n    }\n    Monoid fold(){\n\
    \        return f(front_stack.top().second,back_stack.top().second);\n    }\n\
    };"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/SlidingWindowAggregation.hpp
  requiredBy:
  - test/aoj/DSL_3_D.SlidingWindowAggregation.cpp
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/queue_operate_all_composite.test.cpp
documentation_of: datastructure/SlidingWindowAggregation.hpp
layout: document
redirect_from:
- /library/datastructure/SlidingWindowAggregation.hpp
- /library/datastructure/SlidingWindowAggregation.hpp.html
title: Sliding Window Aggregation (SWAG)
---
## 概要

## 計算量