/**
 * @brief 繰り返し自乗法
 */

#pragma once

#include "../base.hpp"

long long modpow(long long x,long long n,long long mod){
    long long res=1;
    while (n>0){
        if (n&1LL) res=res*x%mod;
        x=x*x%mod; n>>=1LL;
    }
    return res;
}
long long modinv(long long x,long long p){
    return modpow(x,p-2,p);
}