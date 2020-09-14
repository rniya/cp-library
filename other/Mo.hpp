/**
 * @brief Mo's Algorithm
 * @docs docs/other/Mo.md
 */

#pragma once

#include "../base.hpp"

struct Mo{
    int sz;
    vector<int> left,right,order;
    vector<bool> check;
    Mo(int n,int q):sz((int)sqrt(n)),order(q),check(n){}
    void insert(int l,int r){
        left.emplace_back(l);
        right.emplace_back(r);
    }
    template<typename ADD,typename DEL,typename REM>
    void build(const ADD &add,const DEL &del,const REM &rem){
        iota(order.begin(),order.end(),0);
        sort(order.begin(),order.end(),[&](int a,int b){
            return (left[a]/sz!=left[b]/sz?left[a]<left[b]:right[a]<right[b]);
        });
        int l=0,r=0;
        auto push=[&](int idx){
            check[idx].flip();
            if (check[idx]) add(idx);
            else del(idx);
        };
        for (int idx:order){
            while(l>left[idx]) push(--l);
            while(r<right[idx]) push(r++);
            while(l<left[idx]) push(l++);
            while(r>right[idx]) push(--r);
            rem(idx);
        }
    }
};