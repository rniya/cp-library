/**
 * @brief Dual Segment Tree
 * @docs docs/datastructure/DualSegmentTree.hpp
 */

#pragma once

#include "../base.hpp"

template<typename OperatorMonoid>
struct DualSegmentTree{
    typedef function<OperatorMonoid(OperatorMonoid,OperatorMonoid)> H;
    int n,hi;
    H h;
    OperatorMonoid id1;
    vector<OperatorMonoid> laz;
    DualSegmentTree(int n_,H h,OperatorMonoid id1):h(h),id1(id1){init(n_);}
    void init(int n_){
        n=1,hi=0;
        while(n<n_) n<<=1,++hi;
        laz.assign(n<<1,id1);
    }
    inline void propagate(int k){
        if (laz[k]==id1) return;
        laz[k<<1|0]=h(laz[k<<1|0],laz[k]);
        laz[k<<1|1]=h(laz[k<<1|1],laz[k]);
        laz[k]=id1;
    }
    inline void thrust(int k){
        for (int i=hi;i;--i) propagate(k>>i);
    }
    void update(int a,int b,OperatorMonoid x){
        if (a>=b) return;
        thrust(a+=n); thrust(b+=n-1);
        for (int l=a,r=b+1;l<r;l>>=1,r>>=1){
            if (l&1) laz[l]=h(laz[l],x),++l;
            if (r&1) --r,laz[r]=h(laz[r],x);
        }
    }
    void set_val(int k,OperatorMonoid x){
        thrust(k+=n);
        laz[k]=x;
    }
    OperatorMonoid operator[](int k){
        thrust(k+=n);
        return laz[k];
    }
};