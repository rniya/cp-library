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


# :heavy_check_mark: Bellman Ford <small>(graph/BellmanFord.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/BellmanFord.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 16:00:32+09:00




## 概要

## 計算量

## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_B.test.cpp.html">test/aoj/GRL_1_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Bellman Ford
 * @docs docs/graph/BellmanFord.md
 */

#pragma once

#include "../base.hpp"

template<typename T>
struct BellmanFord{
    const T inf=numeric_limits<T>::max();
    struct edge{
        int u,v; T w;
        edge(int u,int v,T w):u(u),v(v),w(w){}
    };
    int n;
    vector<vector<int>> G;
    vector<int> check,reach;
    vector<edge> es;
    BellmanFord(int n):n(n),G(n),check(n),reach(n,1){}
    void add_edge(int u,int v,T w){
        es.emplace_back(u,v,w);
        G[u].emplace_back(v);
    }
    vector<T> build(int s,int &neg_loop){
        vector<T> d(n,inf);
        d[s]=0;
        for (int i=0;i<n;++i){
            bool update=false;
            for (auto e:es){
                if (!reach[e.u]||!reach[e.v]||d[e.u]==inf) continue;
                if (d[e.u]+e.w<d[e.v]){
                    d[e.v]=d[e.u]+e.w;
                    update=true;
                }
            }
            if (!update) break;
            if (i==n-1){neg_loop=1; return d;}
        }
        neg_loop=0; return d;
    }
    void dfs(int v){
        if (check[v]) return;
        check[v]=1;
        for (int u:G[v]) dfs(u);
    }
    T shortest_path(int s,int t,int &neg_loop){
        for (int i=0;i<n;++i){
            fill(check.begin(),check.end(),0);
            dfs(i);
            reach[i]=check[t];
        }
        return build(s,neg_loop)[t];
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/BellmanFord.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

