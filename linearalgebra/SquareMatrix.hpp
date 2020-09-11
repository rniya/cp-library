/**
 * @brief Square Matrix
 * @docs docs/linearalgebra/Squarematrix.md
 */

#pragma once

#include "../base.hpp"

template<class K,size_t N>
struct SquareMatrix{
    array<array<K,N>,N> dat;
    SquareMatrix(){
        for (size_t i=0;i<N;++i)
            for (size_t j=0;j<N;++j)
                dat[i][j]=K();
    }
    size_t size() const{return N;}
    array<K,N> &operator[](size_t i){return dat[i];}
    const array<K,N> &operator[](size_t i) const{return dat[i];}
    static SquareMatrix I(){
        SquareMatrix res;
        for (size_t i=0;i<N;++i) res[i][i]=K(1);
        return res;
    }
    SquareMatrix &operator+=(const SquareMatrix &B){
        for (size_t i=0;i<N;++i)
            for (size_t j=0;j<N;++j)
                (*this)[i][j]+=B[i][j];
        return (*this);
    }
    SquareMatrix operator+(const SquareMatrix &B) const{
        return SquareMatrix(*this)+=B;
    }
    SquareMatrix &operator-=(const SquareMatrix &B){
        for (size_t i=0;i<N;++i)
            for (size_t j=0;j<N;++j)
                (*this)[i][j]-=B[i][j];
        return (*this);
    }
    SquareMatrix operator-(const SquareMatrix &B) const{
        return SquareMatrix(*this)-=B;
    }
    SquareMatrix &operator*=(const SquareMatrix &B){
        SquareMatrix res;
        for (size_t i=0;i<N;++i)
            for (size_t j=0;j<N;++j)
                for (size_t k=0;k<N;++k)
                    res[i][j]+=(*this)[i][k]*B[k][j];
        dat.swap(res.dat);
        return (*this);
    }
    SquareMatrix operator*(const SquareMatrix &B) const{
        return SquareMatrix(*this)*=B;
    }
    SquareMatrix &operator^=(long long k){
        SquareMatrix res=I();
        while(k){
            if (k&1LL) res*=*this;
            *this*=*this; k>>=1LL;
        }
        dat.swap(res.dat);
        return (*this);
    }
    SquareMatrix operator^(long long k) const{
        return SquareMatrix(*this)^=k;
    }
};