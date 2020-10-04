/**
 * @brief Rolling Hash
 * @docs docs/string/RollingHash.md
 */

#pragma once

#include "../base.hpp"

class RollingHash{
    using u64=uint64_t;
    using u128=__uint128_t;
    static const uint64_t mod=(1ULL<<61)-1;
    const u64 base;
    vector<u64> hash,power;
    static inline u64 add(u64 a,u64 b){
        if ((a+=b)>=mod) a-=mod;
        return a;
    }
    static inline u64 mul(u64 a,u64 b){
        u128 c=(u128)a*b;
        return add(c>>61,c&mod);
    }
public:
    static inline u64 generate_base(){
        mt19937_64 mt(chrono::steady_clock::now().time_since_epoch().count());
        uniform_int_distribution<u64> rand(2,RollingHash::mod-1);
        return rand(mt);
    }
    template<typename T>
    RollingHash(const T &s,u64 base):base(base){
        int n=s.size();
        hash.assign(n+1,0);
        power.assign(n+1,0);
        power[0]=1;
        for (int i=0;i<n;++i){
            hash[i+1]=add(mul(hash[i],base),s[i]);
            power[i+1]=mul(power[i],base);
        }
    }
    u64 query(int l,int r) const {
        return add(hash[r],mod-mul(hash[l],power[r-l]));
    }
    int lcp(int a,int b) const {
        int len=min(hash.size()-a,hash.size()-b);
        int lb=0,ub=len;
        while (ub-lb>1){
            int mid=(lb+ub)>>1;
            (query(a,a+mid)==query(b,b+mid)?lb:ub)=mid;
        }
        return lb;
    }
};