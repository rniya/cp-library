---
data:
  _extendedDependsOn:
  - icon: ':heavy_check_mark:'
    path: base.hpp
    title: base.hpp
  _extendedRequiredBy: []
  _extendedVerifiedWith:
  - icon: ':heavy_check_mark:'
    path: test/yosupo/set_xor_min.test.cpp
    title: test/yosupo/set_xor_min.test.cpp
  _pathExtension: hpp
  _verificationStatusIcon: ':heavy_check_mark:'
  attributes:
    _deprecated_at_docs: docs/datastructure/BinaryTrie.md
    document_title: Binary Trie
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir).decode()\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 191, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 310, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ datastructure/BinaryTrie.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Binary Trie\n * @docs docs/datastructure/BinaryTrie.md\n */\n\
    \n#pragma once\n\n#include \"../base.hpp\"\n\ntemplate<typename T,int MAX_LOG>\n\
    class BinaryTrie{\n    struct Node{\n        int cnt;\n        Node *ch[2];\n\
    \        Node():cnt(0),ch{nullptr,nullptr}{}\n    };\n    Node *root;\n    Node\
    \ *add(Node *node,T val,int b=MAX_LOG-1){\n        if (!node) node=new Node;\n\
    \        node->cnt+=1;\n        if (b<0) return node;\n        bool f=(val>>(T)b)&(T)1;\n\
    \        node->ch[f]=add(node->ch[f],val,b-1);\n        return node;\n    }\n\
    \    Node *sub(Node *node,T val,int b=MAX_LOG-1){\n        node->cnt-=1;\n   \
    \     if (node->cnt==0) return nullptr;\n        if (b<0) return node;\n     \
    \   bool f=(val>>(T)b)&(T)1;\n        node->ch[f]=sub(node->ch[f],val,b-1);\n\
    \        return node;\n    }\n    T get_min(Node *node,T val,int b=MAX_LOG-1)\
    \ const {\n        if (b<0) return 0;\n        bool f=(val>>(T)b)&(T)1; f^=!node->ch[f];\n\
    \        return get_min(node->ch[f],val,b-1)|(T)f<<(T)b;\n    }\n    T get(Node\
    \ *node,int k,int b=MAX_LOG-1) const {\n        if (b<0) return 0;\n        int\
    \ m=node->ch[0]?node->ch[0]->cnt:0;\n        return k<m?get(node->ch[0],k,b-1):get(node->ch[1],k-m,b-1)|(T)1<<(T)b;\n\
    \    }\n    int count_lower(Node *node,T val,int b=MAX_LOG-1){\n        if (!node||b<0)\
    \ return 0;\n        bool f=(val>>(T)b)&(T)1;\n        return (f&&node->ch[0]?node->ch[0]->cnt:0)+count_lower(node->ch[f],val,b-1);\n\
    \    }\npublic:\n    BinaryTrie():root(nullptr){}\n    int size() const {return\
    \ root?root->cnt:0;}\n    bool empty() const {return !root;}\n    void insert(T\
    \ val){root=add(root,val);}\n    void erase(T val){root=sub(root,val);}\n    T\
    \ max_element(T bias=0) const {return get_min(root,~bias);}\n    T min_element(T\
    \ bias=0) const {return get_min(root,bias);}\n    int lower_bound(T val){return\
    \ count_lower(root,val);}\n    int upper_bound(T val){return count_lower(root,val+1);}\n\
    \    T operator[](int k) const {return get(root,k);}\n    int count(T val) const\
    \ {\n        if (!root) return 0;\n        Node *node=root;\n        for (int\
    \ i=MAX_LOG-1;i>=0;--i){\n            node=node->ch[(val>>(T)i)&(T)1];\n     \
    \       if (!node) return 0;\n        }\n        return node->cnt;\n    }\n};"
  dependsOn:
  - base.hpp
  isVerificationFile: false
  path: datastructure/BinaryTrie.hpp
  requiredBy: []
  timestamp: '2020-09-09 23:15:02+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yosupo/set_xor_min.test.cpp
documentation_of: datastructure/BinaryTrie.hpp
layout: document
redirect_from:
- /library/datastructure/BinaryTrie.hpp
- /library/datastructure/BinaryTrie.hpp.html
title: Binary Trie
---
## 概要

## 計算量