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


# :heavy_check_mark: Two Edge Connected Components <small>(graph/TwoEdgeConnectedComponents.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/TwoEdgeConnectedComponents.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 10:17:21+09:00




## 概要

## 計算量

## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yosupo/two_edge_connected_components.test.cpp.html">test/yosupo/two_edge_connected_components.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Two Edge Connected Components
 * @docs docs/graph/StronglyConnectedComponents.md
 */

#pragma once

#include "../base.hpp"

struct TwoEdgeConnectedComponents{
    int time,k;
    vector<int> ord,low,cmp;
    vector<vector<int>> G,C,T;
    vector<pair<int,int>> bridge;
    TwoEdgeConnectedComponents(int n):
        time(0),k(0),ord(n,-1),low(n),cmp(n,-1),G(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    bool is_bridge(int u,int v){
        if (ord[u]>ord[v]) swap(u,v);
        return ord[u]<low[v];
    }
    void dfs(int v,int p){
        ord[v]=low[v]=time++;
        int bic=0;
        for (int u:G[v]){
            if (u==p&&!bic){bic=1; continue;}
            if (~ord[u]){
                low[v]=min(low[v],ord[u]);
                continue;
            }
            dfs(u,v);
            low[v]=min(low[v],low[u]);
            if (is_bridge(v,u)) bridge.emplace_back(v,u);
        }
    }
    void fill_component(int v){
        C[cmp[v]].emplace_back(v);
        for (int u:G[v]){
            if (~cmp[u]||is_bridge(u,v)) continue;
            cmp[u]=cmp[v];
            fill_component(u);
        }
    }
    void add_component(int v){
        if (~cmp[v]) return;
        cmp[v]=k++;
        C.emplace_back();
        fill_component(v);
    }
    int build(){
        int n=G.size();
        for (int v=0;v<n;++v){
            if (ord[v]<0) dfs(v,-1);
        }
        for (int v=0;v<n;++v) add_component(v);
        T.resize(k);
        for (auto e:bridge){
            int u=cmp[e.first],v=cmp[e.second];
            T[u].emplace_back(v);
            T[v].emplace_back(u);
        }
        return k;
    }
    int operator[](int i) const{return cmp[i];}
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/TwoEdgeConnectedComponents.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

