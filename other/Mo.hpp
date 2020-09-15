/**
 * @brief Mo's Algorithm
 * @docs docs/other/Mo.md
 */

#pragma once

#include "../base.hpp"

struct Mo{
    int sz;
    vector<int> left,right;
    Mo(int n):sz((int)sqrt(n)){}
    void insert(int l,int r){
        left.emplace_back(l);
        right.emplace_back(r);
    }
    template<typename ADDL,typename ADDR,typename DELL,typename DELR,typename REM>
    void build(const ADDL &add_left,const ADDR &add_right,const DELL &del_left,const DELR &del_right,const REM &rem){
        int q=left.size();
        vector<int> ord(q);
        iota(ord.begin(),ord.end(),0);
        sort(ord.begin(),ord.end(),[&](int a,int b){
            return (left[a]/sz!=left[b]/sz?left[a]<left[b]:right[a]<right[b]);
        });
        int l=0,r=0;
        for (int idx:ord){
            while(l>left[idx]) add_left(--l);
            while(r<right[idx]) add_right(r++);
            while(l<left[idx]) del_left(l++);
            while(r>right[idx]) del_right(--r);
            rem(idx);
        }
    }
    template<typename ADD,typename DEL,typename REM>
    void build(const ADD &add,const DEL &del,const REM &rem){
        build(add,add,del,del,rem);
    }
};