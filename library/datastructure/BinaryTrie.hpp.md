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


# :warning: Binary Trie <small>(datastructure/BinaryTrie.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/BinaryTrie.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 23:15:02+09:00




## 概要

## 計算量

## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Binary Trie
 * @docs docs/datastructure/BinaryTrie.md
 */

#pragma once

#include "../base.hpp"

template<typename T,int MAX_LOG>
class BinaryTrie{
    struct Node{
        int cnt;
        Node *ch[2];
        Node():cnt(0),ch{nullptr,nullptr}{}
    };
    Node *root;
    Node *add(Node *node,T val,int b=MAX_LOG-1){
        if (!node) node=new Node;
        node->cnt+=1;
        if (b<0) return node;
        bool f=(val>>(T)b)&(T)1;
        node->ch[f]=add(node->ch[f],val,b-1);
        return node;
    }
    Node *sub(Node *node,T val,int b=MAX_LOG-1){
        node->cnt-=1;
        if (node->cnt==0) return nullptr;
        if (b<0) return node;
        bool f=(val>>(T)b)&(T)1;
        node->ch[f]=sub(node->ch[f],val,b-1);
        return node;
    }
    T get_min(Node *node,T val,int b=MAX_LOG-1) const {
        if (b<0) return 0;
        bool f=(val>>(T)b)&(T)1; f^=!node->ch[f];
        return get_min(node->ch[f],val,b-1)|(T)f<<(T)b;
    }
    T get(Node *node,int k,int b=MAX_LOG-1) const {
        if (b<0) return 0;
        int m=node->ch[0]?node->ch[0]->cnt:0;
        return k<m?get(node->ch[0],k,b-1):get(node->ch[1],k-m,b-1)|(T)1<<(T)b;
    }
    int count_lower(Node *node,T val,int b=MAX_LOG-1){
        if (!node||b<0) return 0;
        bool f=(val>>(T)b)&(T)1;
        return (f&&node->ch[0]?node->ch[0]->cnt:0)+count_lower(node->ch[f],val,b-1);
    }
public:
    BinaryTrie():root(nullptr){}
    int size() const {return root?root->cnt:0;}
    bool empty() const {return !root;}
    void insert(T val){root=add(root,val);}
    void erase(T val){root=sub(root,val);}
    T max_element(T bias=0) const {return get_min(root,~bias);}
    T min_element(T bias=0) const {return get_min(root,bias);}
    int lower_bound(T val){return count_lower(root,val);}
    int upper_bound(T val){return count_lower(root,val+1);}
    T operator[](int k) const {return get(root,k);}
    int count(T val) const {
        if (!root) return 0;
        Node *node=root;
        for (int i=MAX_LOG-1;i>=0;--i){
            node=node->ch[(val>>(T)i)&(T)1];
            if (!node) return 0;
        }
        return node->cnt;
    }
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: datastructure/BinaryTrie.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

