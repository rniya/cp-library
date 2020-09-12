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


# :heavy_check_mark: Suffix Array <small>(string/SuffixArray.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#b45cffe084dd3d20d928bee85e7b0f21">string</a>
* <a href="{{ site.github.repository_url }}/blob/master/string/SuffixArray.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-12 12:22:43+09:00




## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/aoj/ALDS1_14_D.test.cpp.html">test/aoj/ALDS1_14_D.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Suffix Array
 * @docs docs/string/SuffixArray.hpp
 */

#pragma once

#include "../base.hpp"

struct SuffixArray{
    string s;
    vector<int> SA;
    SuffixArray(const string &S):s(S){
        int n=s.size();
        SA.resize(n);
        iota(SA.begin(),SA.end(),0);
        sort(SA.begin(),SA.end(),[&](int a,int b){
            return s[a]==s[b]?a>b:s[a]<s[b];
        });
        vector<int> nxt(n),c(s.begin(),s.end()),cnt(n);
        for (int j=1;j<n;j<<=1){
            for (int i=0;i<n;++i){
                if (i&&c[SA[i-1]]==c[SA[i]]&&SA[i-1]+j<n&&c[SA[i-1]+j/2]==c[SA[i]+j/2]) nxt[SA[i]]=nxt[SA[i-1]];
                else nxt[SA[i]]=i;
            }
            iota(cnt.begin(),cnt.end(),0);
            copy(SA.begin(),SA.end(),c.begin());
            for (int i=0;i<n;++i){
                int sl=c[i]-j;
                if (sl>=0) SA[cnt[nxt[sl]]++]=sl;
            }
            nxt.swap(c);
        }
    }
    bool lt_substr(const string &t,int si=0,int ti=0){
        int sn=s.size(),tn=t.size();
        for (;si<sn&&ti<tn;++si,++ti){
            if (s[si]<t[ti]) return true;
            if (s[si]>t[ti]) return false;
        }
        return si>=sn&&ti<tn;
    }
    int lower_bound(const string &t){
        int lb=-1,ub=SA.size();
        while(ub-lb>1){
            int mid=(ub+lb)>>1;
            (lt_substr(t,SA[mid])?lb:ub)=mid;
        }
        return ub;
    }
    pair<int,int> lower_upper_bound(string &t){
        int idx=lower_bound(t);
        int lb=idx-1,ub=SA.size();
        ++t.back();
        while(ub-lb>1){
            int mid=(ub+lb)>>1;
            (lt_substr(t,SA[mid])?lb:ub)=mid;
        }
        --t.back();
        return {idx,ub};
    }
    int operator[](int i) const {return SA[i];}
    int size() const {return s.size();}
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
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: string/SuffixArray.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

