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
<script type="text/javascript" src="../../../assets/js/copy-button.js"></script>
<link rel="stylesheet" href="../../../assets/css/copy-button.css" />


# :heavy_check_mark: test/aoj/GRL_1_C.test.cpp

<a href="../../../index.html">Back to top page</a>

* category: <a href="../../../index.html#0d0c91c0cca30af9c1c9faef0cf04aa9">test/aoj</a>
* <a href="{{ site.github.repository_url }}/blob/master/test/aoj/GRL_1_C.test.cpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 11:16:56+09:00


* see: <a href="https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C">https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C</a>


## Depends on

* :heavy_check_mark: <a href="../../../library/base.hpp.html">base.hpp</a>
* :heavy_check_mark: <a href="../../../library/graph/WarshallFloyd.hpp.html">Warshall Floyd <small>(graph/WarshallFloyd.hpp)</small></a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/5/GRL/1/GRL_1_C"

#include "../../base.hpp"
#include "../../graph/WarshallFloyd.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    const long long inf=1e18;
    int V,E; cin >> V >> E;
    vector<vector<long long>> ans(V,vector<long long>(V,inf));
    for (int i=0;i<V;++i) ans[i][i]=0;
    for (int i=0;i<E;++i){
        int s,t,d; cin >> s >> t >> d;
        ans[s][t]=d;
    }

    Warshall_Floyd(ans,inf);
    for (int i=0;i<V;++i){
        if (ans[i][i]<0){
            cout << "NEGATIVE CYCLE" << '\n';
            return 0;
        }
    }
    for (int i=0;i<V;++i){
        for (int j=0;j<V;++j){
            if (ans[i][j]==inf) cout << "INF";
            else cout << ans[i][j];
            cout << (j+1==V?'\n':' ');
        }
    }
}
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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 399, in update
    self.update(self._resolve(pathlib.Path(included), included_from=path))
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 310, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: graph/WarshallFloyd.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../../index.html">Back to top page</a>
