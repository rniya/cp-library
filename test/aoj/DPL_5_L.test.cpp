#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/courses/library/7/DPL/5/DPL_5_L"

#include "../../base.hpp"
#include "../../modulo/modint.hpp"
#include "../../combinatorics/PartitionTable.hpp"

using mint=modint<1000000007>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;

    cout << (n-k>=0?partition_table<mint>(n-k,k)[n-k][k]:0) << '\n';
}