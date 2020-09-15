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


# :heavy_check_mark: Euler Tour (パスに対する操作) <small>(tree/EulerTourforEdge.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#c0af77cf8294ff93a5cdb2963ca9f038">tree</a>
* <a href="{{ site.github.repository_url }}/blob/master/tree/EulerTourforEdge.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 12:32:51+09:00




## 概要

## 計算量

## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_5_D.test.cpp.html">test/aoj/GRL_5_D.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Euler Tour (パスに対する操作)
 * @docs docs/tree/EulerTourforEdge.md
 */

#pragma once

#include "../base.hpp"

class EulerTourforEdge{
    vector<int> ds,us,dep,btm;
    void dfs(int v,int p,int d){
        dep[v]=d;
        for (int u:G[v]){
            if (u==p) continue;
            ds[u]=btm.size();
            btm.emplace_back(u);
            dfs(u,v,d+1);
            us[u]=btm.size();
            btm.emplace_back(u);
        }
    }
public:
    vector<vector<int>> G;
    EulerTourforEdge(int n):
        ds(n),us(n),dep(n),G(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    void build(int r=0){
        btm.clear();
        ds[r]=btm.size(); btm.emplace_back(r);
        dfs(r,-1,0);
        us[r]=btm.size(); btm.emplace_back(r);
    }
    int child(int u,int v){
        return dep[u]<dep[v]?v:u;
    }
    int bottom(int e){
        return btm[e];
    }
    template<typename T,typename F>
    T query(int v,F f){
        return f(0,us[v]);
    }
    // u or v must be lca(u,v)
    template<typename T,typename F>
    T query(int u,int v,F f){
        if (dep[u]<dep[v]) swap(u,v);
        return query<T>(u,f)-query<T>(v,f);
    }
    // v is child of the edge
    template<typename T,typename G>
    void update(int v,T x,G g){
        g(ds[v],x);
        g(us[v],-x);
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: tree/EulerTourforEdge.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

