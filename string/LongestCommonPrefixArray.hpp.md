---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: string/SuffixArray.hpp
    title: Suffix Array
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_of_substrings.test.cpp
    title: test/yosupo/number_of_substrings.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/LongestCommonPrefixArray.md
    document_title: Longest Common Prefix Array
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 399, in update\n    self.update(self._resolve(pathlib.Path(included), included_from=path))\n\
    \  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/SuffixArray.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Longest Common Prefix Array\n * @docs docs/string/LongestCommonPrefixArray.md\n\
    \ */\n\n#include \"../base.hpp\"\n#include \"../string/SuffixArray.hpp\"\n\nstruct\
    \ LongestCommonPrefixArray{\n    SuffixArray SA;\n    vector<int> LCP,rank,lookup;\n\
    \    vector<vector<int>> dat;\n    LongestCommonPrefixArray(const string &s):SA(s){\n\
    \        int n=s.size();\n        LCP.resize(n); rank.resize(n+1);\n        for\
    \ (int i=0;i<=n;++i) rank[SA[i]]=i;\n        LCP[0]=0;\n        for (int i=0,t=0;i<n;++i){\n\
    \            if (t) --t;\n            for (int j=SA[rank[i]-1];max(i,j)+t<n&&s[i+t]==s[j+t];++t);\n\
    \            LCP[rank[i]-1]=t;\n        }\n        int h=1;\n        while((1<<h)<=n)\
    \ ++h;\n        dat.assign(h,vector<int>(n));\n        lookup.assign(n+1,0);\n\
    \        for (int i=2;i<=n;++i) lookup[i]=lookup[i>>1]+1;\n        for (int j=0;j<n;++j)\
    \ dat[0][j]=LCP[j];\n        for (int i=1,mask=1;i<h;++i,mask<<=1){\n        \
    \    for (int j=0;j<n;++j){\n                dat[i][j]=min(dat[i-1][j],dat[i-1][min(j+mask,n-1)]);\n\
    \            }\n        }\n    }\n    int query(int a,int b){\n        if (a>b)\
    \ swap(a,b);\n        int d=lookup[b-a];\n        return min(dat[d][a],dat[d][b-(1<<d)]);\n\
    \    }\n    // longest common prefix of s[a...] and s[b...]\n    int lcp(int a,int\
    \ b){\n        return query(rank[a],rank[b]);\n    }\n    int operator[](int i)\
    \ const {return LCP[i];}\n    int size() const {return LCP.size();}\n};"
  dependsOn:
  - base.hpp
  - string/SuffixArray.hpp
  isVerificationFile: false
  path: string/LongestCommonPrefixArray.hpp
  requiredBy: []
  timestamp: '2020-09-13 14:01:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/number_of_substrings.test.cpp
documentation_of: string/LongestCommonPrefixArray.hpp
layout: document
redirect_from:
- /library/string/LongestCommonPrefixArray.hpp
- /library/string/LongestCommonPrefixArray.hpp.html
title: Longest Common Prefix Array
---
