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


# :warning: Z-Algorithm <small>(string/Z_algorithm.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/Z_algorithm.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 15:23:12+09:00




## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Z-Algorithm
 * @docs docs/string/Z_algorithm.hpp
 */

#pragma once

#include "../base.hpp"

vector<int> Zalgorithm(const string &s){
    int n=s.size();
    vector<int> z(n);
    z[0]=n;
    int i=1,j=0;
    while(i<n){
        while(i+j<n&&s[j]==s[i+j]) ++j;
        z[i]=j;
        if (j==0){++i; continue;}
        int k=1;
        while(i+k<n&&k+z[k]<j) z[i+k]=z[k],++k;
        i+=k,j-=k;
    }
    return z;
}

vector<int> LCP(const string &s,const string &t){
    vector<int> Z=Zalgorithm(t+s);
    for (int &i:Z) i=min(i,(int)t.size());
    return vector<int>(Z.begin()+t.size(),Z.end());
}

template<typename T>
vector<int> Zalgorithm(const T &s){
    int n=s.size();
    vector<int> z(n);
    z[0]=n;
    int i=1,j=0;
    while(i<n){
        while(i+j<n&&s[j]==s[i+j]) ++j;
        z[i]=j;
        if (j==0){++i; continue;}
        int k=1;
        while(i+k<n&&k+z[k]<j) z[i+k]=z[k],++k;
        i+=k,j-=k;
    }
    return z;
}

template<typename T>
vector<int> LCP(const T &s,const T &t){
    T u(s);
    u.insert(u.begin(),t.begin(),t.end());
    vector<int> Z=Zalgorithm(u);
    for (int &i:Z) i=min(i,(int)t.size());
    return vector<int>(Z.begin()+t.size(),Z.end());
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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 310, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/Z_algorithm.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

