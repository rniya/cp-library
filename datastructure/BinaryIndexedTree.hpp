/**
 * @brief Binary Indexed Tree
 * @docs docs/datastructure/BinaryIndexedTree.md
 */

#pragma once

#include "../base.hpp"

template<typename T>
struct BinaryIndexedTree{
    int n;
    vector<T> dat;
    BinaryIndexedTree(int n):n(n),dat(n+1,0){}
    void add(int i,T x){
        if (i==0) return;
        for (;i<=dat.size();i+=(i&-i)) dat[i]+=x;
    }
    T sum(int i){ //[1,i]
        T res=0;
        for (;i>0;i-=(i&-i)) res+=dat[i];
        return res;
    }
    T query(int l,int r){ //[l,r)
        return sum(r-1)-sum(l-1);
    }
    int lower_bound(T x){
        if (x<=0) return 0;
        int lb=0,r=1;
        while(r<n) r<<=1;
        for (;r>0;r>>=1){
            if (lb+r<=n&&dat[lb+r]<x){
                x-=dat[lb+r]; lb+=r;
            }
        }
        return lb+1;
    }
    void add0(int i,T x){add(i+1,x);}
    T sum0(int i){return sum(i+1);}
    T query0(int l,int r){return sum(r)-sum(l);}
};