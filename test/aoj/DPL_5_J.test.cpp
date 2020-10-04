#define PROBLEM "https://onlinejudge.u-aizu.ac.jp/problems/DPL_5_J"

#include "../../base.hpp"
#include "../../modulo/modint.hpp"
#include "../../combinatorics/PartitionTable.hpp"

using mint=modint<1000000007>;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int n,k; cin >> n >> k;

    cout << partition_table<mint>(n,k)[n][k] << '\n';
}