/**
 * @brief ラグランジュ補間
 * @docs docs/polynomial/lagrange_interpolation.md
 */

#pragma once

#include "../base.hpp"

template<typename M>
M lagrange_interpolation(vector<M> x,vector<M> y,M T){
    int n=x.size()-1;
    M res=0;
    for (int i=0;i<=n;++i){
        M c=1;
        for (int j=0;j<=n;++j){
            if (i==j) continue;
            (c*=T-x[j])/=x[i]-x[j];
        }
        res+=c*y[i];
    }
    return res;
}

template<typename M>
M lagrange_interpolation_arithmetic(vector<M> &y,M T){
    int n=y.size()-1;
    if (T.v<=n) return y[T.v];
    vector<M> left(n+1,1),right(n+1,1),fac(n+1,1),finv(n+1,1);
    for (int i=0;i<n;++i) left[i+1]=left[i]*(T-i);
    for (int i=n-1;i>=0;--i) right[i]=right[i+1]*(T-(i+1));
    for (int i=1;i<=n;++i) fac[i]=fac[i-1]*i;
    finv[n]=(M)1/fac[n];
    for (int i=n;i>0;--i) finv[i-1]=finv[i]*i;
    M res=0;
    for (int i=0;i<=n;++i){
        M add=y[i]*left[i]*right[i]*finv[i]*finv[n-i];
        if ((n-i)&1) res-=add;
        else res+=add;
    }
    return res;
}