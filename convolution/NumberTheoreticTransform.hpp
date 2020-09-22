/**
 * @brief Number Theoretic Transform
 * @docs docs/convolution/NumberTheoreticTransform.md
 */

#pragma once

#include "../base.hpp"
#include "../modulo/modint.hpp"

template<int mod>
struct NumberTheoreticTransform{
    using Mint=modint<mod>;
    vector<Mint> roots;
    vector<int> rev;
    int base,max_base;
    Mint root;
    NumberTheoreticTransform():base(1),rev{0,1},roots{Mint(0),Mint(1)}{
        int tmp=mod-1;
        for (max_base=0;tmp%2==0;++max_base) tmp>>=1;
        root=2;
        while (root.pow((mod-1)>>1)==1) ++root;
        root=root.pow((mod-1)>>max_base);
    }
    void ensure_base(int nbase){
        if (nbase<=base) return;
        rev.resize(1<<nbase);
        for (int i=0;i<(1<<nbase);++i){
            rev[i]=(rev[i>>1]>>1)|((i&1)<<(nbase-1));
        }
        roots.resize(1<<nbase);
        for (;base<nbase;++base){
            Mint z=root.pow(1<<(max_base-1-base));
            for (int i=1<<(base-1);i<(1<<base);++i){
                roots[i<<1]=roots[i];
                roots[i<<1|1]=roots[i]*z;
            }
        }
    }
    void ntt(vector<Mint> &a){
        const int n=a.size();
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
                    Mint z=a[i+j+k]*roots[j+k];
                    a[i+j+k]=a[i+j]-z;
                    a[i+j]=a[i+j]+z;
                }
            }
        }
    }
    vector<Mint> multiply(vector<Mint> a,vector<Mint> b){
        int need=a.size()+b.size()-1;
        int nbase=1;
        while ((1<<nbase)<need) ++nbase;
        ensure_base(nbase);
        int sz=1<<nbase;
        a.resize(sz,Mint(0)); b.resize(sz,Mint(0));
        ntt(a); ntt(b);
        Mint inv_sz=1/Mint(sz);
        for (int i=0;i<sz;++i) a[i]*=b[i]*inv_sz;
        reverse(a.begin()+1,a.end());
        ntt(a);
        a.resize(need);
        return a;
    }
    vector<int> multiply(vector<int> a,vector<int> b){
        vector<Mint> A(a.size()),B(b.size());
        for (int i=0;i<a.size();++i) A[i]=Mint(a[i]);
        for (int i=0;i<b.size();++i) B[i]=Mint(b[i]);
        vector<Mint> C=multiply(A,B);
        vector<int> res(C.size());
        for (int i=0;i<C.size();++i) res[i]=C[i].a;
        return res;
    }
};