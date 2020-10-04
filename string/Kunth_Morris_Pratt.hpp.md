---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith: []
  _pathExtension: hpp
  _verificationStatusIcon: ':warning:'
  attributes:
    _deprecated_at_docs: docs/string/Knuth_Morris_Pratt.md
    document_title: "Knuth Moriss Pratt (KMP\u6CD5)"
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/Kunth_Morris_Pratt.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Knuth Moriss Pratt (KMP\u6CD5)\n * @docs docs/string/Knuth_Morris_Pratt.md\n\
    \ */\n\n#pragma once\n\n#include \"../base.hpp\"\n\nstruct Knuth_Morris_Pratt{\n\
    \    string s;\n    int n;\n    vector<int> kmp;\n    Knuth_Morris_Pratt(const\
    \ string &s):s(s){build();}\n    void build(){\n        n=s.size();\n        kmp.assign(n+1,-1);\n\
    \        for (int i=0,j=-1;i<n;kmp[++i]=++j){\n            while(j>=0&&s[i]!=s[j])\
    \ j=kmp[j];\n        }\n    }\n    vector<int> KMP(){return kmp;}\n    vector<int>\
    \ next_period(){\n        vector<int> np=kmp;\n        for (int i=1;i<kmp.size();++i)\
    \ np[i]=i-np[i];\n        return np;\n    }\n    vector<int> pattern_match(const\
    \ string &t){\n        int m=t.size();\n        vector<int> res;\n        int\
    \ i=0,j=0;\n        while(i+j<m){\n            if (s[j]==t[i+j]){\n          \
    \      if (++j!=n) continue;\n                res.emplace_back(i);\n         \
    \   }\n            i+=j-kmp[j];\n            j=max(kmp[j],0);\n        }\n   \
    \     return res;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/Kunth_Morris_Pratt.hpp
  requiredBy: []
  timestamp: '2020-09-10 15:23:12+09:00'
  verificationStatus: LIBRARY_NO_TESTS
  verifiedWith: []
documentation_of: string/Kunth_Morris_Pratt.hpp
layout: document
redirect_from:
- /library/string/Kunth_Morris_Pratt.hpp
- /library/string/Kunth_Morris_Pratt.hpp.html
title: "Knuth Moriss Pratt (KMP\u6CD5)"
---
## 概要

## 計算量