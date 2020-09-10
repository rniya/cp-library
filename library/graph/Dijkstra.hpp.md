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


# :heavy_check_mark: Dijkstra <small>(graph/Dijkstra.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#f8b0b924ebd7046dbfa85a856e4682c8">graph</a>
* <a href="{{ site.github.repository_url }}/blob/master/graph/Dijkstra.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 10:17:21+09:00




## 概要

## 計算量

## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_1_A.test.cpp.html">test/aoj/GRL_1_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Dijkstra
 * @docs docs/graph/Dijkstra.md
 */

#pragma once

#include "../base.hpp"

template<typename T>
struct Dijkstra{
    struct edge{
        int to; T cost;
        edge(int to,T cost):to(to),cost(cost){}
        bool operator<(const edge &e) const {
            return cost>e.cost;
        }
    };
    vector<vector<edge>> G;
    vector<T> dp;
    vector<int> pre;
    Dijkstra(int n):G(n),dp(n),pre(n){}
    void add_edge(int u,int v,T c){
        G[u].emplace_back(v,c);
    }
    void build(int s){
        int n=G.size();
        fill(dp.begin(),dp.end(),numeric_limits<T>::max());
        fill(pre.begin(),pre.end(),-1);
        priority_queue<edge> pq;
        dp[s]=0;
        pq.emplace(s,dp[s]);
        while(!pq.empty()){
            auto p=pq.top(); pq.pop();
            int v=p.to;
            if (dp[v]<p.cost) continue;
            for (auto e:G[v]){
                if (dp[v]+e.cost<dp[e.to]){
                    dp[e.to]=dp[v]+e.cost;
                    pre[e.to]=v;
                    pq.emplace(e.to,dp[e.to]);
                }
            }
        }
    }
    vector<int> restore(int t){
        vector<int> res;
        if (pre[t]<0) return res;
        while(~t){
            res.emplace_back(t);
            t=pre[t];
        }
        reverse(res.begin(),res.end());
        return res;
    }
    T operator[](int to){return dp[to];}
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/Dijkstra.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

