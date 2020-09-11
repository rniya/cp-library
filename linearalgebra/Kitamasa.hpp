/**
 * @brief Kitamasa
 * @docs docs/linearalgebra/Kitamasa.md
 */

#pragma once

#include "../base.hpp"

template<typename K>
struct Kitamasa{
    int k;
    vector<K> cs;
    vector<vector<K>> pcs;
    Kitamasa(const vector<K> &C):cs(C),pcs(1),k(C.size()){
        pcs[0].assign(2*k+1,K(0));
        pcs[0][1]=K(1);
    }
    vector<K> merge(const vector<K> &xs,const vector<K> &ys){
        vector<K> zs(2*k+1,K(0));
        for (int i=1;i<=k;++i)
            for (int j=1;j<=k;++j)
                zs[i+j]+=xs[i]*ys[j];
        for (int i=2*k;i>k;zs[i--]=K(0))
            for (int j=1;j<=k;++j)
                zs[i-j]+=cs[k-j]*zs[i];
        return zs;
    }
    //Be careful n is 0-indexed
    K calc(const vector<K> &A,long long n){
        vector<K> res(pcs[0]);
        for (int i=0;n;++i,n>>=1){
            if ((int)pcs.size()<=i)
                pcs.emplace_back(merge(pcs[i-1],pcs[i-1]));
            if (~n&1) continue;
            res=merge(res,pcs[i]);
        }
        K ans=K(0);
        for (int i=1;i<=k;++i) ans+=res[i]*A[i-1];
        return ans;
    }
};