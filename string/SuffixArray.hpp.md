---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/LongestCommonPrefixArray.hpp
    title: Longest Common Prefix Array
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/aoj/ALDS1_14_D.test.cpp
    title: test/aoj/ALDS1_14_D.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/number_of_substrings.test.cpp
    title: test/yosupo/number_of_substrings.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yosupo/suffixarray.test.cpp
    title: test/yosupo/suffixarray.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/SuffixArray.hpp
    document_title: Suffix Array
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.0/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/SuffixArray.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Suffix Array\n * @docs docs/string/SuffixArray.hpp\n */\n\n\
    #pragma once\n\n#include \"../base.hpp\"\n\nstruct SuffixArray{\n    string s;\n\
    \    vector<int> SA;\n    SuffixArray(const string &S):s(S){\n        int n=s.size();\n\
    \        s.push_back('$');\n        SA.resize(n+1);\n        iota(SA.begin(),SA.end(),0);\n\
    \        sort(SA.begin(),SA.end(),[&](int a,int b){\n            return s[a]==s[b]?a>b:s[a]<s[b];\n\
    \        });\n        vector<int> c(s.begin(),s.end()),cnt(n+1),nxt(n+1);\n  \
    \      for (int j=1;j<=n;j<<=1){\n            for (int i=0;i<=n;++i){\n      \
    \          nxt[SA[i]]=((i&&c[SA[i-1]]==c[SA[i]]&&SA[i-1]+j<n&&c[SA[i-1]+j/2]==c[SA[i]+j/2])?nxt[SA[i-1]]:i);\n\
    \            }\n            iota(cnt.begin(),cnt.end(),0);\n            copy(SA.begin(),SA.end(),c.begin());\n\
    \            for (int i=0;i<=n;++i){\n                if (c[i]-j>=0){\n      \
    \              SA[cnt[nxt[c[i]-j]]++]=c[i]-j;\n                }\n           \
    \ }\n            nxt.swap(c);\n        }\n    }\n    bool comp(const string &t,int\
    \ si=0,int ti=0){\n        int sn=s.size(),tn=t.size();\n        for (;si<sn&&ti<tn;++si,++ti){\n\
    \            if (s[si]<t[ti]) return true;\n            if (s[si]>t[ti]) return\
    \ false;\n        }\n        return si>=sn&&ti<tn;\n    }\n    int lower_bound(const\
    \ string &t){\n        int lb=-1,ub=SA.size();\n        while(ub-lb>1){\n    \
    \        int mid=(ub+lb)>>1;\n            (comp(t,SA[mid])?lb:ub)=mid;\n     \
    \   }\n        return ub;\n    }\n    pair<int,int> lower_upper_bound(string &t){\n\
    \        int l=lower_bound(t);\n        int lb=l-1,ub=SA.size();\n        ++t.back();\n\
    \        while(ub-lb>1){\n            int mid=(ub+lb)>>1;\n            (comp(t,SA[mid])?lb:ub)=mid;\n\
    \        }\n        --t.back();\n        return {l,ub};\n    }\n    int count(string\
    \ &t){\n        pair<int,int> p=lower_upper_bound(t);\n        return p.second-p.first;\n\
    \    }\n    int operator[](int i) const {return SA[i];}\n    int size() const\
    \ {return s.size();}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/SuffixArray.hpp
  requiredBy:
  - string/LongestCommonPrefixArray.hpp
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/aoj/ALDS1_14_D.test.cpp
  - test/yosupo/number_of_substrings.test.cpp
  - test/yosupo/suffixarray.test.cpp
documentation_of: string/SuffixArray.hpp
layout: document
redirect_from:
- /library/string/SuffixArray.hpp
- /library/string/SuffixArray.hpp.html
title: Suffix Array
---
