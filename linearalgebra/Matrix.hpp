/**
 * @brief Matrix
 * @docs docs/linearalgebra/Matrix.md
 */

#pragma once

#include "../base.hpp"

template<class K>
struct Matrix{
    vector<vector<K>> dat;
    Matrix(size_t r,size_t c):dat(r,vector<K>(c,K())){}
    Matrix(size_t n):dat(n,vector<K>(n,K())){}
    Matrix(vector<vector<K>> dat):dat(dat){}
    size_t size() const{return dat.size();}
    vector<K> &operator[](int i){return dat[i];}
    const vector<K> &operator[](int i) const{return dat[i];}
    static Matrix I(size_t n){
        Matrix res(n);
        for (int i=0;i<n;++i) res[i][i]=K(1);
        return res;
    }
    Matrix &operator+=(const Matrix &B){
        for (int i=0;i<dat.size();++i)
            for (int j=0;j<dat[0].size();++j)
                (*this)[i][j]+=B[i][j];
        return (*this);
    }
    Matrix operator+(const Matrix &B) const{
        return Matrix(*this)+=B;
    }
    Matrix &operator-=(const Matrix &B){
        for (int i=0;i<dat.size();++i)
            for (int j=0;j<dat[0].size();++j)
                (*this)[i][j]-=B[i][j];
        return (*this);
    }
    Matrix operator-(const Matrix &B) const{
        return Matrix(*this)-=B;
    }
    Matrix &operator*=(const Matrix &B){
        vector<vector<K>> res(dat.size(),vector<K>(B[0].size(),K()));
        for (int i=0;i<dat.size();++i)
            for (int j=0;j<B[0].size();++j)
                for (int k=0;k<B.size();++k)
                    res[i][j]+=(*this)[i][k]*B[k][j];
        dat.swap(res);
        return (*this);
    }
    Matrix operator*(const Matrix &B) const{
        return Matrix(*this)*=B;
    }
    Matrix &operator^=(long long k){
        Matrix res=Matrix::I(size());
        while(k){
            if (k&1LL) res*=*this;
            *this*=*this; k>>=1LL;
        }
        dat.swap(res.dat);
        return (*this);
    }
    Matrix operator^(long long k) const{
        return Matrix(*this)^=k;
    }
    static Matrix Gauss_Jordan(const Matrix &A,const Matrix &B){
        int n=A.size(),l=B[0].size();
        Matrix C(n,n+l);
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j)
                C[i][j]=A[i][j];
            for (int j=0;j<l;++j)
                C[i][j+n]=B[i][j];
        }
        for (int i=0;i<n;++i){
            int p=i;
            for (int j=i;j<n;++j){
                if (abs(C[p][i])<abs(C[j][i])) p=j;
            }
            swap(C[i],C[p]);
            if (abs(C[i][i])<1e-9) return Matrix(0,0);
            for (int j=i+1;j<n+l;++j) C[i][j]/=C[i][i];
            for (int j=0;j<n;++j){
                if (i!=j) for (int k=i+1;k<n+l;++k){
                    C[j][k]-=C[j][i]*C[i][k];
                }
            }
        }
        Matrix res(n,l);
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                res[i][j]=C[i][j+n];
        return res;
    }
    Matrix inv() const{
        Matrix res=I(size());
        return Gauss_Jordan(*this,res);
    }
    K determinant() const{
        Matrix A(dat);
        K res(1);
        int n=size();
        for (int i=0;i<n;++i){
            int p=i;
            for (int j=i;j<n;++j){
                if (abs(A[p][i])<abs(A[j][i])) p=j;
            }
            if (i!=p) swap(A[i],A[p]),res=-res;
            if (abs(A[i][i])<1e-9) return K(0);
            res*=A[i][i];
            for (int j=i+1;j<n;++j) A[i][j]/=A[i][i];
            for (int j=i+1;j<n;++j)
                for (int k=i+1;k<n;++k)
                    A[j][k]-=A[j][i]*A[i][k];
        }
        return res;
    }
    //sum_{k=0}^{n-1} x^k
    static K geometric_sum(K x,long long n){
        Matrix A(2);
        A[0][0]=x; A[0][1]=0;
        A[1][0]=1; A[1][1]=1;
        return (A^n)[1][0];
    }
    //sum_{k=0}^{n-1} A^k
    Matrix powsum(long long k) const{
        int n=size();
        Matrix B(n<<1),res(n);
        for (int i=0;i<n;++i){
            for (int j=0;j<n;++j)
                B[i][j]=dat[i][j];
            B[i+n][i]=B[i+n][i+n]=K(1);
        }
        B^=k;
        for (int i=0;i<n;++i)
            for (int j=0;j<n;++j)
                res[i][j]=B[i+n][j];
        return res;
    }
};