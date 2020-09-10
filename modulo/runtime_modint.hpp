/**
 * @brief 実行時 modint
 */

#pragma once

#include "../base.hpp"

class runtime_modint{
    using u64=uint_fast64_t;
    static u64 &mod(){
        static u64 mod_=0;
        return mod_;
    }
    public:
    u64 a;
    static void set_mod(const u64 x){mod()=x;}
    static u64 get_mod(){return mod();}
    runtime_modint(const u64 x=0):a(x%get_mod()){}
    u64 &balue() noexcept{return a;}
    const u64 &value() const noexcept{return a;}
    runtime_modint &operator+=(const runtime_modint &rhs){
        a+=rhs.a;
        if (a>=get_mod()) a-=get_mod();
        return *this;
    }
    runtime_modint operator+(const runtime_modint &rhs) const{
        return runtime_modint(*this)+=rhs;
    }
    runtime_modint &operator-=(const runtime_modint &rhs){
        if (a<rhs.a) a+=get_mod();
        a-=rhs.a;
        return *this;
    }
    runtime_modint operator-(const runtime_modint &rhs) const{
        return runtime_modint(*this)-=rhs;
    }
    runtime_modint &operator*=(const runtime_modint &rhs){
        a=a*rhs.a%get_mod();
        return *this;
    }
    runtime_modint operator*(const runtime_modint &rhs) const{
        return runtime_modint(*this)*=rhs;
    }
    runtime_modint &operator/=(runtime_modint rhs){
        u64 exp=get_mod()-2;
        while(exp){
            if (exp&1) *this*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return *this;
    }
    runtime_modint operator/(const runtime_modint &rhs) const{
        return runtime_modint(*this)/=rhs;
    }
    friend runtime_modint pow(runtime_modint rhs,long long exp) noexcept{
        runtime_modint res{1};
        while(exp){
            if (exp&1) res*=rhs;
            rhs*=rhs; exp>>=1;
        }
        return res;
    }
    friend ostream &operator<<(ostream &s,const runtime_modint &rhs){
        return s << rhs.a;
    }
    friend istream &operator>>(istream &s,runtime_modint &rhs){
        u64 a; rhs=runtime_modint{(s >> a,a)}; return s;
    }
};