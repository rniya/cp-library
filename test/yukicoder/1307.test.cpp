#define PROBLEM "https://yukicoder.me/problems/no/1307"

#include "../../base.hpp"
#include "../../convolution/FastFourierTransform.hpp"

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,Q; cin >> N >> Q;
    vector<int> a(N);
    for (int i=0;i<N;++i) cin >> a[i];
    vector<int> b(N+1,0);
    for (;Q--;){
        int r; cin >> r;
        ++b[N-r];
    }

    vector<long long> c=FastFourierTransform::multiply(a,b);
    vector<int> ans(N,0);
    for (int i=0;i<c.size();++i) ans[i%N]+=c[i];

    for (int i=0;i<N;++i) cout << ans[i] << (i==N-1?'\n':' ');
}