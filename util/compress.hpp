/**
 * @brief compress
 */

#pragma once

#include "../base.hpp"

template<typename T> vector<T> compress(vector<T> v){
    sort(v.begin(),v.end());
    v.erase(unique(v.begin(),v.end()),v.end());
    return v;
}

template<typename T> map<T,int> dict(vector<T> v){
    map<T,int> res;
    for (int i=0;i<v.size();++i) res[v[i]]=i;
    return res;
}

template<typename T> vector<int> dict(vector<T> v){
    vector<T> cv=compress(v);
    int n=v.size();
    vector<int> res(n);
    for (int i=0;i<n;++i)
        res[i]=lower_bound(cv.begin(),cv.end(),v[i])-cv.begin();
    return res;
}