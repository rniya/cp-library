#define IGNORE

#define PROBLEM "https://atcoder.jp/contests/tdpc/tasks/tdpc_fibonacci"

#include "../../base.hpp"
#include "../../modulo/modint.hpp"
#include "../../polynomial/Kitamasa.hpp"

using mint=modint<1000000007>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int K,N; cin >> K >> N;

    vector<mint> A(K,1);
    Kitamasa<mint> Ki(A);

    cout << Ki.calc(A,--N) << endl;
}