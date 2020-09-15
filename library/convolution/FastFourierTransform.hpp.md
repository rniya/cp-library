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


# :heavy_check_mark: Fast Fourier Transform <small>(convolution/FastFourierTransform.hpp)</small>

<a href="../../index.html">Back to top page</a>

* category: <a href="../../index.html#a9595c1c24c33b16056d2ad07e71682d">convolution</a>
* <a href="{{ site.github.repository_url }}/blob/master/convolution/FastFourierTransform.hpp">View this file on GitHub</a>
    - Last commit date: 2020-09-10 10:17:21+09:00




## 概要

## 計算量

## Depends on

* :question: <a href="../base.hpp.html">base.hpp</a>


## Verified with

* :heavy_check_mark: <a href="../../verify/test/yukicoder/206.test.cpp.html">test/yukicoder/206.test.cpp</a>


## Code

<a id="unbundled"></a>
{% raw %}
```cpp
/**
 * @brief Fast Fourier Transform
 * @docs docs/convolution/FastFourierTransform.md
 */

#pragma once

#include "../base.hpp"

namespace FastFourierTransform{
    struct Complex{
        double x,y;
        Complex():x(0),y(0){}
        Complex(double x,double y):x(x),y(y){}
        inline Complex operator+(const Complex &c) const {
            return Complex(x+c.x,y+c.y);
        }
        inline Complex operator-(const Complex &c) const {
            return Complex(x-c.x,y-c.y);
        }
        inline Complex operator*(const Complex &c) const {
            return Complex(x*c.x-y*c.y,x*c.y+y*c.x);
        }
        inline Complex conj() const {return Complex(x,-y);}
    };
    const double PI=acosl(-1);
    vector<Complex> roots={{0,0},{1,0}};
    vector<int> rev={0,1};
    int base=1;
    void ensure_base(int nbase){
        if (nbase<=base) return;
        rev.resize(1<<nbase);
        for (int i=0;i<(1<<nbase);++i){
            rev[i]=(rev[i>>1]>>1)|((i&1)<<(nbase-1));
        }
        roots.resize(1<<nbase);
        for (;base<nbase;++base){
            double angle=PI*2.0/(1<<(base+1));
            for (int i=1<<(base-1);i<(1<<base);++i){
                roots[i<<1]=roots[i];
                double angle_i=angle*((i<<1|1)-(1<<base));
                roots[i<<1|1]=Complex(cos(angle_i),sin(angle_i));
            }
        }
    }
    void fft(vector<Complex> &a,int n){
        int zeros=__builtin_ctz(n);
        ensure_base(zeros);
        int shift=base-zeros;
        for (int i=0;i<n;++i){
            if (i<(rev[i]>>shift)){
                swap(a[i],a[rev[i]>>shift]);
            }
        }
        for (int k=1;k<n;k<<=1){
            for (int i=0;i<n;i+=(k<<1)){
                for (int j=0;j<k;++j){
                    Complex z=a[i+j+k]*roots[j+k];
                    a[i+j+k]=a[i+j]-z;
                    a[i+j]=a[i+j]+z;
                }
            }
        }
    }
    vector<long long> multiply(const vector<int> &a,const vector<int> &b){
        int need=a.size()+b.size()-1;
        int nbase=1;
        while((1<<nbase)<need) ++nbase;
        ensure_base(nbase);
        int sz=1<<nbase;
        vector<Complex> C(sz);
        for (int i=0;i<sz;++i){
            int x=(i<a.size()?a[i]:0);
            int y=(i<b.size()?b[i]:0);
            C[i]=Complex(x,y);
        }
        fft(C,sz);
        Complex r(0,-0.25/(sz>>1)),s(0,1),t(0.5,0);
        for (int i=0;i<=(sz>>1);++i){
            int j=(sz-i)&(sz-1);
            Complex z=(C[j]*C[j]-(C[i]*C[i]).conj())*r;
            C[j]=(C[i]*C[i]-(C[j]*C[j]).conj())*r;
            C[i]=z;
        }
        for (int i=0;i<(sz>>1);++i){
            Complex C0=(C[i]+C[i+(sz>>1)])*t;
            Complex C1=(C[i]-C[i+(sz>>1)])*t*roots[(sz>>1)+i];
            C[i]=C0+C1*s;
        }
        fft(C,sz>>1);
        vector<long long> res(need);
        for (int i=0;i<need;++i){
            res[i]=llround(i&1?C[i>>1].y:C[i>>1].x);
        }
        return res;
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
  File "/opt/hostedtoolcache/Python/3.8.5/x64/lib/python3.8/site-packages/onlinejudge_verify/languages/cplusplus_bundle.py", line 310, in update
    raise BundleErrorAt(path, i + 1, "#pragma once found in a non-first line")
onlinejudge_verify.languages.cplusplus_bundle.BundleErrorAt: convolution/FastFourierTransform.hpp: line 6: #pragma once found in a non-first line

```
{% endraw %}

<a href="../../index.html">Back to top page</a>

