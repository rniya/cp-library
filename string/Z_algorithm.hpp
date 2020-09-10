/**
 * @brief Z-Algorithm
 * @docs docs/string/Z_algorithm.hpp
 */

#pragma once

#include "../base.hpp"

vector<int> Zalgorithm(const string &s){
    int n=s.size();
    vector<int> z(n);
    z[0]=n;
    int i=1,j=0;
    while(i<n){
        while(i+j<n&&s[j]==s[i+j]) ++j;
        z[i]=j;
        if (j==0){++i; continue;}
        int k=1;
        while(i+k<n&&k+z[k]<j) z[i+k]=z[k],++k;
        i+=k,j-=k;
    }
    return z;
}

vector<int> LCP(const string &s,const string &t){
    vector<int> Z=Zalgorithm(t+s);
    for (int &i:Z) i=min(i,(int)t.size());
    return vector<int>(Z.begin()+t.size(),Z.end());
}

template<typename T>
vector<int> Zalgorithm(const T &s){
    int n=s.size();
    vector<int> z(n);
    z[0]=n;
    int i=1,j=0;
    while(i<n){
        while(i+j<n&&s[j]==s[i+j]) ++j;
        z[i]=j;
        if (j==0){++i; continue;}
        int k=1;
        while(i+k<n&&k+z[k]<j) z[i+k]=z[k],++k;
        i+=k,j-=k;
    }
    return z;
}

template<typename T>
vector<int> LCP(const T &s,const T &t){
    T u(s);
    u.insert(u.begin(),t.begin(),t.end());
    vector<int> Z=Zalgorithm(u);
    for (int &i:Z) i=min(i,(int)t.size());
    return vector<int>(Z.begin()+t.size(),Z.end());
}