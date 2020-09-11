/**
 * @brief Rolling Hash
 * @docs docs/string/RollingHash.md
 */

#pragma once

#include "../base.hpp"

struct RollingHash{
    static const int B1=1007,B2=2009;
    static const int mod1=1000000007,mod2=1000000009;
    vector<long long> hash1,hash2,po1,po2;
    RollingHash(const vector<long long> &vs){init(vs);}
    RollingHash(const string &S){
        vector<long long> vs;
        for (char c:S) vs.emplace_back(c);
        init(vs);
    }
    void init(vector<long long> vs){
        int n=vs.size();
        hash1.assign(n+1,0);
        hash2.assign(n+1,0);
        po1.assign(n+1,1);
        po2.assign(n+1,1);
        for (int i=0;i<n;++i){
            hash1[i+1]=(hash1[i]*B1+vs[i])%mod1;
            hash2[i+1]=(hash2[i]*B2+vs[i])%mod2;
            po1[i+1]=po1[i]*B1%mod1;
            po2[i+1]=po2[i]*B2%mod2;
        }
    }
    inline pair<long long,long long> get(int l,int r) const {
        long long res1=hash1[r]+mod1-hash1[l]*po1[r-l]%mod1
                ,res2=hash2[r]+mod2-hash2[l]*po2[r-l]%mod2;
        return {res1>=mod1?res1-mod1:res1,res2>=mod2?res2-mod2:res2};
    }
    inline int lcp(int a,int b) const {
        int len=min((int)hash1.size()-a,(int)hash1.size()-b);
        int lb=0,ub=len;
        while(ub-lb>1){
            int mid=(lb+ub)>>1;
            (get(a,a+mid)==get(b,b+mid)?lb:ub)=mid;
        }
        return lb;
    }
};