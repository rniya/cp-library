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


# :heavy_check_mark: Low Link (橋/関節点) <small>(graph/LowLink.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/LowLink.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 10:46:07+09:00




## 概要

## 計算量

## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_3_A.test.cpp.html">test/aoj/GRL_3_A.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_3_B.test.cpp.html">test/aoj/GRL_3_B.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Low Link (橋/関節点)
 * @docs docs/graph/LowLink.md
 */

#pragma once

#include "../base.hpp"

struct LowLink{
    int n,time;
    vector<int> ord,low;
    vector<vector<int>> G;
    vector<int> articulation;
    vector<pair<int,int>> bridge;
    LowLink(int n):n(n),time(0),ord(n,-1),low(n),G(n){}
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
        bool is_articulation=false;
        int cnt=0;
        for (int u:G[v]){
            if (u==p) continue;
            if (~ord[u]){
                low[v]=min(low[v],ord[u]);
                continue;
            }
            ++cnt;
            dfs(u,v);
            low[v]=min(low[v],low[u]);
            is_articulation|=(~p&&ord[v]<=low[u]);
            if (is_bridge(v,u)) bridge.emplace_back(v,u);
        }
        is_articulation|=(p<0&&cnt>1);
        if (is_articulation) articulation.emplace_back(v);
    }
    void build(){
        for (int v=0;v<n;++v){
            if (ord[v]<0) dfs(v,-1);
        }
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/LowLink.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

