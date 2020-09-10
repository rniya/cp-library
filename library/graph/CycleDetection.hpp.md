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


# :heavy_check_mark: Cycle Detection <small>(graph/CycleDetection.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/CycleDetection.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 14:24:53+09:00




## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/2891.test.cpp.html">test/aoj/2891.test.cpp</a>
* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_4_A.test.cpp.html">test/aoj/GRL_4_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Cycle Detection
 * @docs docs/graph/CycleDetection.hpp
 */

#pragma once

#include "../base.hpp"

template<bool directed>
struct CycleDetection{
    vector<vector<int>> G;
    vector<int> seen,finished;
    stack<int> hist;
    int pos;
    CycleDetection(int n):G(n),seen(n,0),finished(n,0),pos(-1){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
    }
    void dfs(int v,int p){
        seen[v]=1; hist.emplace(v);
        for (int u:G[v]){
            if (!directed&&u==p) continue;
            if (finished[u]) continue;
            if (seen[u]&&!finished[u]){pos=u; return;}
            dfs(u,v);
            if (~pos) return;
        }
        finished[v]=1; hist.pop();
    }
    vector<int> build(){
        for (int v=0;v<G.size();++v){
            if (!seen[v]) dfs(v,-1);
            if (~pos) break;
        }
        vector<int> res;
        while(!hist.empty()){
            int t=hist.top(); hist.pop();
            res.emplace_back(t);
            if (t==pos) break;
        }
        return res;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/CycleDetection.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

