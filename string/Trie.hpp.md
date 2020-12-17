---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy:
  - icon: ':heavy_check_mark:'
    path: string/AhoCorasick.hpp
    title: Aho Corasick
  - icon: ':warning:'
    path: test/atcoder/tenka1_2016_final_c.cpp
    title: test/atcoder/tenka1_2016_final_c.cpp
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/1269.test.cpp
    title: test/yukicoder/1269.test.cpp
  - icon: ':heavy_check_mark:'
    path: test/yukicoder/430.AhoCorasick.test.cpp
    title: test/yukicoder/430.AhoCorasick.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/string/Trie.md
    document_title: Trie
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/Trie.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Trie\n * @docs docs/string/Trie.md\n */\n\n#pragma once\n\n\
    #include \"../base.hpp\"\n\ntemplate<int char_size>\nstruct Trie{\n    struct\
    \ TrieNode{\n        char c; int dep;\n        vector<int> nxt,idxs;\n       \
    \ TrieNode(char c,int dep):c(c),dep(dep),nxt(char_size,-1){}\n    };\n    vector<TrieNode>\
    \ Nodes;\n    function<int(char)> ctoi;\n    Trie(function<int(char)> ctoi):ctoi(ctoi){\n\
    \        Nodes.emplace_back('$',0);\n    }\n    inline int &next(int node,int\
    \ c){\n        return Nodes[node].nxt[c];\n    }\n    inline int &next(int node,char\
    \ c){\n        return next(node,ctoi(c));\n    }\n    void add(const string &s,int\
    \ x=0){\n        int node=0;\n        for (int i=0;i<s.size();++i){\n        \
    \    int k=ctoi(s[i]);\n            if (next(node,k)<0){\n                next(node,k)=Nodes.size();\n\
    \                Nodes.emplace_back(s[i],i+1);\n            }\n            node=next(node,k);\n\
    \        }\n        Nodes[node].idxs.emplace_back(x);\n    }\n    int find(const\
    \ string &s){\n        int node=0;\n        for (int i=0;i<s.size();++i){\n  \
    \          int k=ctoi(s[i]);\n            if (next(node,k)<0) return -1;\n   \
    \         node=next(node,k);\n        }\n        return node;\n    }\n    template<typename\
    \ F>\n    void query(const string &s,const F &f,int l){\n        int node=0;\n\
    \        for (int i=l;i<s.size();++i){\n            node=next(node,s[i]);\n  \
    \          if (node<0) return;\n            for (auto &idx:Nodes[node].idxs) f(idx);\n\
    \        }\n    }\n    int size(){return Nodes.size();};\n    vector<int> idxs(int\
    \ node){return Nodes[node].idxs;}\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: string/Trie.hpp
  requiredBy:
  - string/AhoCorasick.hpp
  - test/atcoder/tenka1_2016_final_c.cpp
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/430.AhoCorasick.test.cpp
  - test/yukicoder/1269.test.cpp
documentation_of: string/Trie.hpp
layout: document
redirect_from:
- /library/string/Trie.hpp
- /library/string/Trie.hpp.html
title: Trie
---
## 概要

## 計算量