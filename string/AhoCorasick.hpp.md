---
data:
  _extendedDependsOn:
  - icon: ':question:'
    path: base.hpp
    title: base.hpp
  - icon: ':heavy_check_mark:'
    path: string/Trie.hpp
    title: Trie
  _extendedRequiredBy: []
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
    _deprecated_at_docs: docs/string/AhoCorasick.md
    document_title: Aho Corasick
    links: []
  bundledCode: "Traceback (most recent call last):\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/documentation/build.py\"\
    , line 71, in _render_source_code_stat\n    bundled_code = language.bundle(stat.path,\
    \ basedir=basedir, options={'include_paths': [basedir]}).decode()\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus.py\"\
    , line 193, in bundle\n    bundler.update(path)\n  File \"/opt/hostedtoolcache/Python/3.9.1/x64/lib/python3.9/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py\"\
    , line 312, in update\n    raise BundleErrorAt(path, i + 1, \"#pragma once found\
    \ in a non-first line\")\nonlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt:\
    \ string/AhoCorasick.hpp: line 6: #pragma once found in a non-first line\n"
  code: "/**\n * @brief Aho Corasick\n * @docs docs/string/AhoCorasick.md\n */\n\n\
    #pragma once\n\n#include \"../base.hpp\"\n#include \"../string/Trie.hpp\"\n\n\
    template<int char_size>\nstruct AhoCorasick:Trie<char_size+1>{\n    using Trie<char_size+1>::Trie;\n\
    \    using Trie<char_size+1>::next;\n    using Trie<char_size+1>::ctoi;\n    const\
    \ int FAIL=char_size;\n    vector<int> cnt;\n    void build(bool heavy=true){\n\
    \        auto &Nodes=this->Nodes;\n        cnt.resize(Nodes.size());\n       \
    \ for (int i=0;i<Nodes.size();++i){\n            cnt[i]=Nodes[i].idxs.size();\n\
    \        }\n        queue<int> que;\n        for (int i=0;i<=char_size;++i){\n\
    \            if (~next(0,i)){\n                next(next(0,i),FAIL)=0;\n     \
    \           que.emplace(next(0,i));\n            } else next(0,i)=0;\n       \
    \ }\n        while (!que.empty()){\n            auto &node=Nodes[que.front()];\n\
    \            int fail=node.nxt[FAIL];\n            cnt[que.front()]+=cnt[fail];\n\
    \            que.pop();\n            for (int i=0;i<char_size;++i){\n        \
    \        if (~node.nxt[i]){\n                    next(node.nxt[i],FAIL)=next(fail,i);\n\
    \                    if (heavy){\n                        auto &u=Nodes[node.nxt[i]].idxs;\n\
    \                        auto &v=Nodes[next(fail,i)].idxs;\n                 \
    \       vector<int> w;\n                        set_union(u.begin(),u.end(),v.begin(),v.end(),back_inserter(w));\n\
    \                        u=w;\n                    }\n                    que.emplace(node.nxt[i]);\n\
    \                } else node.nxt[i]=Nodes[fail].nxt[i];\n            }\n     \
    \   }\n    }\n    map<int,int> match(const string &s,int now=0){\n        auto\
    \ &Nodes=this->Nodes;\n        map<int,int> res;\n        for (auto c:s){\n  \
    \          now=next(now,ctoi(c));\n            for (auto &id:Nodes[now].idxs)\
    \ ++res[id];\n        }\n        return res;\n    }\n    int move(const char &c,int\
    \ now){\n        while (next(now,ctoi(c))<0) now=next(now,FAIL);\n        return\
    \ next(now,ctoi(c));\n    }\n    pair<long long,int> move(const string &s,int\
    \ now=0){\n        long long res=0;\n        for (auto &c:s){\n            int\
    \ nxt=move(c,now);\n            res+=cnt[nxt]; now=nxt;\n        }\n        return\
    \ {res,now};\n    }\n    int count(int node){return cnt[node];}\n};"
  dependsOn:
  - base.hpp
  - string/Trie.hpp
  isVerificationFile: false
  path: string/AhoCorasick.hpp
  requiredBy: []
  timestamp: '2020-11-18 12:14:00+09:00'
  verificationStatus: LIBRARY_ALL_AC
  verifiedWith:
  - test/yukicoder/430.AhoCorasick.test.cpp
  - test/yukicoder/1269.test.cpp
documentation_of: string/AhoCorasick.hpp
layout: document
redirect_from:
- /library/string/AhoCorasick.hpp
- /library/string/AhoCorasick.hpp.html
title: Aho Corasick
---
## 概要

## 計算量