#define PROBLEM "https://yukicoder.me/problems/no/1050"

#include "../../base.hpp"
#include "../../linearalgebra/SquareMatrix.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int M,K; cin >> M >> K;

    SquareMatrix<mint,55> SM;
    for (int i=0;i<M;++i){
        for (int j=0;j<M;++j){
            ++SM[i][(i+j)%M];
            ++SM[i][i*j%M];
        }
    }

    SM^=K;
    cout << SM[0][0] << '\n';
}