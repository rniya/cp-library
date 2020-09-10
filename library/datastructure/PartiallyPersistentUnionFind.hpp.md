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


# :warning: Partially Persistent UnionFind <small>(datastructure/PartiallyPersistentUnionFind.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#8dc87745f885a4cc532acd7b15b8b5fe">datastructure</a>
* <a href="{{ site.github.repository_url }}/blob/master/datastructure/PartiallyPersistentUnionFind.hpp">View this file on GitHub</a>
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
 * @brief Partially Persistent UnionFind
 * @docs docs/datastructure/PartiallyPersistentUnionFind.md
 */

#pragma once

#include "../base.hpp"

struct PartiallyPersistentUnionFind{
    const int inf=numeric_limits<int>::max()/2;
    int now,num;
    vector<int> par,time;
    vector<vector<pair<int,int>>> Size;
    PartiallyPersistentUnionFind(int n):
        now(0),num(n),par(n,-1),Size(n),time(n,inf){
        for (int i=0;i<n;++i) Size[i].emplace_back(0,-1);
    }
    int root(int t,int x){
        if (t<time[x]) return x;
        return root(t,par[x]);
    }
    int merge(int x,int y){
        ++now;
        x=root(now,x),y=root(now,y);
        if (x==y) return 0;
        if (par[x]>par[y]) swap(x,y);
        par[x]+=par[y];
        par[y]=x;
        time[y]=now;
        Size[x].emplace_back(now,par[x]);
        --num;
        return now;
    }
    bool same(int t,int x,int y){return root(t,x)==root(t,y);}
    int size(int t,int x){
        x=root(t,x);
        return -prev(lower_bound(Size[x].begin(),Size[x].end(),make_pair(t,0)))->second;
    }
    int count(){return num;}
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: datastructure/PartiallyPersistentUnionFind.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

