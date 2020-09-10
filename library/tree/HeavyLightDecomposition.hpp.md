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


# :heavy_check_mark: Heavy Light Decomposition <small>(tree/HeavyLightDecomposition.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/HeavyLightDecomposition.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 23:15:02+09:00




## 概要

## 計算量

## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2667.test.cpp.html">test/aoj/2667.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp.html">test/aoj/GRL_5_C.HeavyLiightDecomposition.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp.html">test/aoj/GRL_5_E.HeavyLightDecomposition.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Heavy Light Decomposition
 * @docsdocs/tree/HeavyLightDecomposition.md
 */

#pragma once

#include "../base.hpp"

class HeavyLightDecomposition{
    void dfs_sz(int v){
        if (G[v].size()&&G[v][0]==par[v]) swap(G[v][0],G[v].back());
        for (int &u:G[v]){
            if (u==par[v]) continue;
            par[u]=v; dep[u]=dep[v]+1;
            dfs_sz(u);
            sub[v]+=sub[u];
            if (sub[u]>sub[G[v][0]]) swap(u,G[v][0]);
        }
    }
    void dfs_hld(int v,int c,int &times){
        vid[v]=times++; type[v]=c;
        for (int u:G[v]){
            if (u==par[v]) continue;
            head[u]=(u==G[v][0]?head[v]:u);
            dfs_hld(u,c,times);
        }
    }
public:
    vector<vector<int>> G;
    vector<int> vid,head,sub,par,dep,type;
    HeavyLightDecomposition(int n):
        G(n),vid(n,-1),head(n),sub(n,1),par(n,-1),dep(n,0),type(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void build(vector<int> rs={0}){
        int c=0,times=0;
        for (int r:rs){
            dfs_sz(r);
            head[r]=r;
            dfs_hld(r,c++,times);
        }
    }
    int lca(int u,int v){
        for (;;v=par[head[v]]){
            if (vid[u]>vid[v]) swap(u,v);
            if (head[u]==head[v]) return u;
        }
    }
    int distance(int u,int v){
        return dep[u]+dep[v]-2*dep[lca(u,v)];
    }
    template<typename F>
    void update_path(int u,int v,const F &f,bool edge=false){
        for (;;v=par[head[v]]){
            if (vid[u]>vid[v]) swap(u,v);
            if (head[u]==head[v]) break;
            f(vid[head[v]],vid[v]+1);
        }
        f(vid[u]+edge,vid[v]+1);
    }
    template<typename F>
    void update_sub(int u,const F &f,bool edge=false){
        f(vid[u]+edge,vid[u]+sub[u]);
    }
    template<typename T,typename Q,typename F>
    T query(int u,int v,const T &id,const Q &q,const F &f,bool edge=false){
        T l=id,r=id;
        for (;;v=par[head[v]]){
            if (vid[u]>vid[v]) swap(u,v),swap(l,r);
            if (head[u]==head[v]) break;
            l=f(l,q(vid[head[v]],vid[v]+1));
        }
        return f(r,f(l,q(vid[u]+edge,vid[v]+1)));
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: tree/HeavyLightDecomposition.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

