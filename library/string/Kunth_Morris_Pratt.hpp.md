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


# :warning: Knuth Moriss Pratt (KMP法) <small>(string/Kunth_Morris_Pratt.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/Kunth_Morris_Pratt.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 15:23:12+09:00




## 概要

## 計算量

## Depends on

* :heavy_check_mark: <a href="../base.hpp.html">base.hpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Knuth Moriss Pratt (KMP法)
 * @docs docs/string/Knuth_Morris_Pratt.md
 */

#pragma once

#include "../base.hpp"

struct Knuth_Morris_Pratt{
    string s;
    int n;
    vector<int> kmp;
    Knuth_Morris_Pratt(const string &s):s(s){build();}
    void build(){
        n=s.size();
        kmp.assign(n+1,-1);
        for (int i=0,j=-1;i<n;kmp[++i]=++j){
            while(j>=0&&s[i]!=s[j]) j=kmp[j];
        }
    }
    vector<int> KMP(){return kmp;}
    vector<int> next_period(){
        vector<int> np=kmp;
        for (int i=1;i<kmp.size();++i) np[i]=i-np[i];
        return np;
    }
    vector<int> pattern_match(const string &t){
        int m=t.size();
        vector<int> res;
        int i=0,j=0;
        while(i+j<m){
            if (s[j]==t[i+j]){
                if (++j!=n) continue;
                res.emplace_back(i);
            }
            i+=j-kmp[j];
            j=max(kmp[j],0);
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/Kunth_Morris_Pratt.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

