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


# :heavy_check_mark: 2部グラフの最大マッチング <small>(flow/BipartiteMatching.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#cff5497121104c2b8e0cb41ed2083a9b">flow</a>
* <a href="{{ site.github.repository_url }}/blob/master/flow/BipartiteMatching.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-11 18:26:48+09:00




## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/GRL_7_A.test.cpp.html">test/aoj/GRL_7_A.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief 2部グラフの最大マッチング
 * @docs docs/flow/BipartiteMatchgin.md
 */

#pragma once

#include "../base.hpp"

struct BipartiteMatching{
    vector<vector<int>> G;
    vector<int> match,alive,used;
    int time=0;
    BipartiteMatching(int n):G(n),match(n,-1),alive(n,1),used(n,0){}
    void add_edge(int u,int v){
        G[u].emplace_back(v);
        G[v].emplace_back(u);
    }
    bool dfs(int v){
        used[v]=time;
        for (int u:G[v]){
            int w=match[u];
            if (!alive[u]) continue;
            if (w<0||(used[w]!=time&&dfs(w))){
                match[v]=u; match[u]=v;
                return true;
            }
        }
        return false;
    }
    int build(){
        int res=0;
        for (int i=0;i<G.size();++i){
            if (!alive[i]) continue;
            if (~match[i]) continue;
            ++time; res+=dfs(i);
        }
        return res;
    }
    int enable(int v){
        alive[v]=1;
        ++time;
        return dfs(v);
    }
    int disable(int v){
        alive[v]=0;
        if (match[v]<0) return 0;
        match[v]=-1; match[match[v]]=-1;
        ++time;
        int res=dfs(match[v]);
        return res-1;
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: flow/BipartiteMatching.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

