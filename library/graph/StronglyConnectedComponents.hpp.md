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


# :heavy_check_mark: Strongly Connected Components <small>(graph/StronglyConnectedComponents.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/StronglyConnectedComponents.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 10:17:21+09:00




## 概要

## 計算量

## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Required by

* :heavy_check_mark: <a href="TwoSatisfiability.hpp.html">2-SAT <small>(graph/TwoSatisfiability.hpp)</small></a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_3_C.test.cpp.html">test/aoj/GRL_3_C.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/scc.test.cpp.html">test/yosupo/scc.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/yosupo/two_sat.test.cpp.html">test/yosupo/two_sat.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Strongly Connected Components
 * @docs docs/graph/StronglyConnectedComponents.md
 */

#pragma once

#include "../base.hpp"

struct StronglyConnectedComponents{
    vector<vector<int>> G,rG,C,T;
    vector<int> vs,cmp,used;
    StronglyConnectedComponents(int n):G(n),rG(n),cmp(n),used(n){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        rG[v].emplace_back(u);
    }
    void dfs(int v){
        used[v]=1;
        for (int u:G[v]) if(!used[u]) dfs(u);
        vs.emplace_back(v);
    }
    void rdfs(int v,int k){
        used[v]=1;
        cmp[v]=k;
        C[k].emplace_back(v);
        for (int u:rG[v]) if (!used[u]) rdfs(u,k);
    }
    int build(){
        int n=G.size();
        for (int i=0;i<n;++i) if (!used[i]) dfs(i);
        fill(used.begin(),used.end(),0);
        int k=0;
        for (int i=n-1;i>=0;--i){
            if (!used[vs[i]]){
                C.emplace_back(),T.emplace_back();
                rdfs(vs[i],k++);
            }
        }
        for (int v=0;v<n;++v){
            for (int u:G[v]){
                if (cmp[v]!=cmp[u]){
                    T[cmp[v]].emplace_back(cmp[u]);
                }
            }
        }
        for (int i=0;i<k;++i){
            sort(T[i].begin(),T[i].end());
            T[i].erase(unique(T[i].begin(),T[i].end()),T[i].end());
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/StronglyConnectedComponents.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

