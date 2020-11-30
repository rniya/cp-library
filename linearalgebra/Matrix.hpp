/**
 * @brief Matrix
 * @docs docs/linearalgebra/Matrix.md
 */

#pragma once

#include "../base.hpp"

template<class T>
struct Matrix{
    vector<vector<T>> A;
    Matrix(size_t n,size_t m):A(n,vector<T>(m,0)){}
    Matrix(size_t n):A(n,vector<T>(n,0)){}
    size_t height() const {return A.size();}
    size_t width() const {return A[0].size();}
    inline const vector<T> &operator[](int i) const {return A[i];}
    inline vector<T> &operator[](int i){return A[i];}
    static Matrix I(size_t n){
        Matrix res(n);
        for (int i=0;i<n;++i) res[i][i]=1;
        return res;
    }
    Matrix operator+(const Matrix &B) const {return Matrix(*this)+=B;}
    Matrix operator-(const Matrix &B) const {return Matrix(*this)-=B;}
    Matrix operator*(const Matrix &B) const {return Matrix(*this)*=B;}
    Matrix operator^(const long long k) const {return Matrix(*this)^=k;}
    Matrix &operator+=(const Matrix &B){
        size_t n=height(),m=width();
        assert(n==B.height()&&m==B.width());
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                (*this)[i][j]+=B[i][j];
            }
        }
        return *this;
    }
    Matrix &operator-=(const Matrix &B){
        size_t n=height(),m=width();
        assert(n==B.height()&&m==B.width());
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                (*this)[i][j]-=B[i][j];
            }
        }
        return *this;
    }
    Matrix &operator*=(const Matrix &B){
        size_t n=height(),m=B.width(),l=width();
        assert(l==B.height());
        vector<vector<T>> C(n,vector<T>(m,0));
        for (int i=0;i<n;++i){
            for (int j=0;j<m;++j){
                for (int k=0;k<l;++k){
                    C[i][j]+=(*this)[i][k]*B[k][j];
                }
            }
        }
        A.swap(C);
        return *this;
    }
    Matrix &operator^=(long long k){
        Matrix res=Matrix::I(height());
        while (k>0){
            if (k&1) res*=*this;
            *this*=*this; k>>=1LL;
        }
        A.swap(res.A);
        return *this;
    }
    T determinant(){
        Matrix B(*this);
        T res=1;
        for (int i=0;i<width();++i){
            int pivot=-1;
            for (int j=i;j<height();++j){
                if (B[j][i]!=0){
                    pivot=j;
                }
            }
            if (pivot<0) return 0;
            if (pivot!=i){
                res*=-1;
                swap(B[i],B[pivot]);
            }
            res*=B[i][i];
            T v=T(1)/B[i][i];
            for (int j=0;j<width();++j) B[i][j]*=v;
            for (int j=i+1;j<height();++j){
                T w=B[j][i];
                for (int k=0;k<width();++k){
                    B[j][k]-=B[i][k]*w;
                }
            }
        }
        return res;
    }
};