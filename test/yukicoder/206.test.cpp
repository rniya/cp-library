#define PROBLEM "https://yukicoder.me/problems/no/206"

#include "../../base.hpp"
#include "../../convolution/FastFourierTransform.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int L,M,N; cin >> L >> M >> N;
    vector<int> A(N+1,0),B(N+1,0);
    for (int i=0;i<L;++i){
        int a; cin >> a;
        A[a]=1;
    }
    for (int i=0;i<M;++i){
        int b; cin >> b;
        B[N-b]=1;
    }

    vector<long long> C=FastFourierTransform::multiply(A,B);
    int Q; cin >> Q;
    for (int i=0;i<Q;++i) cout << C[N+i] << '\n';
}