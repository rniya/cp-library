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


# :heavy_check_mark: Lowest Common Ancestor <small>(tree/LowestCommonAncestor.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/LowestCommonAncestor.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-09 23:15:02+09:00




## 概要

## 計算量

## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_C.test.cpp.html">test/aoj/GRL_5_C.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Lowest Common Ancestor
 * @docs docs/tree/LowestCommonAncestor.md
 */

#pragma once

#include "../base.hpp"

struct LowestCommonAncestor{
    int n,h;
    vector<vector<int>> G,par;
    vector<int> dep;
    LowestCommonAncestor(int n):n(n),G(n),dep(n){
        h=1;
        while((1<<h)<=n) ++h;
        par.assign(h,vector<int>(n,-1));
    }
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void dfs(int v,int p,int d){
        par[0][v]=p;
        dep[v]=d;
        for (int u:G[v]){
            if (u!=p) dfs(u,v,d+1);
        }
    }
    void build(int r=0){
        dfs(r,-1,0);
        for (int k=0;k<h-1;++k){
            for (int v=0;v<n;++v){
                if (par[k][v]>=0){
                    par[k+1][v]=par[k][par[k][v]];
                }
            }
        }
    }
    int lca(int u,int v){
        if (dep[u]>dep[v]) swap(u,v);
        for (int k=0;k<h;++k){
            if ((dep[v]-dep[u])&1<<k){
                v=par[k][v];
            }
        }
        if (u==v) return u;
        for (int k=h-1;k>=0;--k){
            if (par[k][u]!=par[k][v]){
                u=par[k][u]; v=par[k][v];
            }
        }
        return par[0][u];
    }
    int distance(int u,int v){
        return dep[u]+dep[v]-dep[lca(u,v)]*2;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: tree/LowestCommonAncestor.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

