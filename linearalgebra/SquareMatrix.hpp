/**
 * @brief Square Matrix
 * @docs docs/linearalgebra/Squarematrix.md
 */

#pragma once

#include "../base.hpp"

template<class T,size_t N>
struct SquareMatrix{
    array<array<T,N>,N> A;
    SquareMatrix()=default;
    size_t size() {return N;}
    inline const array<T,N> &operator[](int i) const {return A[i];}
    inline array<T,N> &operator[](int i){return A[i];}
    static SquareMatrix add_identity(){
        return SquareMatrix();
    }
    static SquareMatrix mul_identity(){
        SquareMatrix res;
        for (size_t i=0;i<N;++i) res[i][i]=1;
        return res;
    }
    SquareMatrix operator+(const SquareMatrix &B) const {return SquareMatrix(*this)+=B;}
    SquareMatrix operator-(const SquareMatrix &B) const {return SquareMatrix(*this)-=B;}
    SquareMatrix operator*(const SquareMatrix &B) const {return SquareMatrix(*this)*=B;}
    SquareMatrix operator^(const long long &k) const {return SquareMatrix(*this)^=k;}
    SquareMatrix &operator+=(const SquareMatrix &B){
        for (size_t i=0;i<N;++i){
            for (size_t j=0;j<N;++j){
                (*this)[i][j]+=B[i][j];
            }
        }
        return *this;
    }
    SquareMatrix &operator-=(const SquareMatrix &B){
        for (size_t i=0;i<N;++i){
            for (size_t j=0;j<N;++j){
                (*this)[i][j]-=B[i][j];
            }
        }
        return *this;
    }
    SquareMatrix &operator*=(const SquareMatrix &B){
        array<array<T,N>,N> C;
        for (size_t i=0;i<N;++i){
            for (size_t j=0;j<N;++j){
                for (size_t k=0;k<N;++k){
                    C[i][j]+=(*this)[i][k]*B[k][j];
                }
            }
        }
        A.swap(C);
        return *this;
    }
    SquareMatrix &operator^=(long long k){
        SquareMatrix res=SquareMatrix::mul_identity();
        while (k>0){
            if (k&1) res*=*this;
            *this*=*this; k>>=1LL;
        }
        A.swap(res.A);
        return *this;
    }
};