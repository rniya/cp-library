---
layout: default
---

<!-- mathjax config similar to math.stackexchange -->
<script type="text/javascript" async
  src="https://cdnjs.cloudflare.com/ajax/libs/mathjax/2.7.5/MathJax.js?config=TeX-MML-AM_CHTML">
</script>
<script type="text/x-mathjax-config">
  MathJax.Hub.Config({
    TeX: { equationNumbers: { autoNumber: "AMS" }},
    tex2jax: {
      inlineMath: [ ['$','$'] ],
      processEscapes: true
    },
    "HTML-CSS": { matchFontHeight: false },
    displayAlign: "left",
    displayIndent: "2em"
  });
</script>

<script type="text/javascript" src="https://cdnjs.cloudflare.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://cdn.jsdelivr.net/npm/jquery-balloon-js@1.1.2/jquery.balloon.min.js" integrity="sha256-ZEYs9VrgAeNuPvs15E39OsyOJaIkXEEt10fzxJ20+2I=" crossorigin="anonymous"></script>
<script type="text/javascript" src="../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../assets/css/copy-button.css" />


# :warning: Trie <small>(string/Trie.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/Trie.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 15:23:12+09:00




## 概要

## 計算量

## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Trie
 * @docs docs/string/Trie.md
 */

#pragma once

#include "../base.hpp"

template<int char_size>
struct Trie{
    struct TrieNode{
        char c; int dep;
        vector<int> nxt,idxs;
        TrieNode(char c,int dep):c(c),dep(dep),nxt(char_size,-1){}
    };
    vector<TrieNode> Nodes;
    function<int(char)> ctoi;
    Trie(function<int(char)> ctoi):ctoi(ctoi){
        Nodes.emplace_back('$',0);
    }
    inline int &next(int node,int c){
        return Nodes[node].nxt[c];
    }
    inline int &next(int node,char c){
        return next(node,ctoi(c));
    }
    void add(const string &s,int x=0){
        int node=0;
        for (int i=0;i<s.size();++i){
            int k=ctoi(s[i]);
            if (next(node,k)<0){
                next(node,k)=Nodes.size();
                Nodes.emplace_back(s[i],i+1);
            }
            node=next(node,k);
        }
        Nodes[node].idxs.emplace_back(x);
    }
    int find(const string &s){
        int node=0;
        for (int i=0;i<s.size();++i){
            int k=ctoi(s[i]);
            if (next(node,k)<0) return -1;
            node=next(node,k);
        }
        return node;
    }
    template<typename F>
    void query(const string &s,const F &f,int l){
        int node=0;
        for (int i=l;i<s.size();++i){
            node=next(node,s[i]);
            if (node<0) return;
            for (auto &idx:Nodes[node].idxs) f(idx);
        }
    }
    int size(){return Nodes.size();};
    vector<int> idxs(int node){return Nodes[node].idxs;}
};
```
{% endraw %}

<a id="bundled"></a>
{% raw %}
```cpp
Traceback (most recent call last):
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/docs.py", line 349, in write_contents
    bundled_code = language.bundle(self.file_class.file_path, basedir=pathlib.Path.cwd())
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus.py", line 185, in bundle
    bundler.update(path)
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 310, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/Trie.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

