/**
 * @brief
 * @docs docs/string/Manacher.md
 */

#pragma once

#include "../base.hpp"

vector<int> Manacher(const string &s){
    int n=s.size();
    vector<int> res(n);
    for (int i=0,j=0;i<n;){
        while(i-j>=0&&i+j<n&&s[i-j]==s[i+j]) ++j;
        res[i]=j;
        int k=1;
        while(i-k>=0&&i+k<n&&k+res[i-k]<j) res[i+k]=res[i-k],++k;
        i+=k,j-=k;
    }
    return res;
}